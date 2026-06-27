__int64 __fastcall sub_14005D220(__int64 a1, _BYTE *a2, unsigned int a3, __int64 a4)
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  v8 = qword_1411301E8;
  if ( ExAcquireRundownProtection(&RunRef) )
  {
    v9 = SomeFlagWrapper() != 0;
    v10 = v8;
    if ( !v9 || dword_14115DE24 == 0 || (v20 = __readgsdword(dword_14115DE24), a3 != 1) || _bittest(&v20, 1u) )
    {
      if ( ((a1 >> 4) & (a2 > MmSystemRangeStart)) == 1 )
      {
        v11 = sub_140065080(qword_14115D990);
        v10 = v8;
        if ( v11 )
        {
          if ( qword_14115DE60 )
            qword_14115DE60(a2, 4096, 64);
          sub_1400650F0(qword_14115D990, a2);
          if ( *a2 == '\x111H.' )
          {
            *a2 = -61;
            MainLogFunction(128, &unk_14016FCE0, "fuck %p", a2);
          }
          goto LABEL_19;
        }
      }
      v12 = __readcr3();
      v13 = (qword_14115DF78 >> 12) & 0xFFFFFFFFFFLL;
      if ( v13 == ((v12 >> 12) & 0xFFFFFFFFFFLL) )
      {
        if ( v13 != ((qword_14115DF70 >> 12) & 0xFFFFFFFFFFLL) )
          __writecr3(qword_14115DF70);
        if ( a4 )
        {
          v14 = a4 & 0xFFFFFFFFFFFFFFFEuLL;
          if ( v14 )
          {
            CurrentProcessId = PsGetCurrentProcessId();
            CurrentThreadId = PsGetCurrentThreadId();
            if ( MmSystemRangeStart < *(v14 + 360) && a2 < MmSystemRangeStart && a2 >= 0x10000 )
              sub_140060680(CurrentProcessId, CurrentThreadId, a2, v14);
          }
        }
LABEL_19:
        ExReleaseRundownProtection(&RunRef);
        v17 = 0;
        if ( (v19 ^ v21) == _security_cookie )
          return v17;
LABEL_23:
        JUMPOUT(0x14005D450LL);
      }
    }
    v17 = v10(a1, a2, a3, a4);
    ExReleaseRundownProtection(&RunRef);
    if ( (v19 ^ v21) == _security_cookie )
      return v17;
    goto LABEL_23;
  }
  return (v8)(a1, a2, a3, a4);
}

__int64 AntiThreadHijacking()
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  if ( GlobalContext )
  {
    ReturnLength = 0;
    LODWORD(result) = 0;
    do
    {
      SizeOfBuffer = result;
      result = ExAllocatePool(NonPagedPool, result);
      if ( !result )
        break;
      Buffer = result;
      memset(result, 0, SizeOfBuffer);
      v3 = ZwQuerySystemInformation(SystemProcessInformation, Buffer, SizeOfBuffer, &ReturnLength);
      if ( v3 >= 0 )
      {
        NextEntryOffset = &Buffer->NextEntryOffset;
        if ( Buffer->UniqueProcessId == 4 )
        {
LABEL_9:
          if ( NextEntryOffset[1] )
          {
            SystemThreadInfo = (NextEntryOffset + 'L');
            index = 0;
            do
            {
              if ( PsGetCurrentThreadId() != SystemThreadInfo->KernelTime.QuadPart
                && qword_14115DE40 == *&SystemThreadInfo[-1].ContextSwitches
                && !PsLookupThreadByThreadId(SystemThreadInfo->KernelTime.QuadPart, &Thread) )
              {
                APCHackDetach(&Thread);
              }
              ++index;
              ++SystemThreadInfo;
            }
            while ( index < NextEntryOffset[1] );
          }
        }
        else
        {
          while ( 1 )
          {
            v5 = *NextEntryOffset;
            if ( !*NextEntryOffset )
              break;
            v6 = *(NextEntryOffset + v5 + 80) == 4;
            NextEntryOffset = (NextEntryOffset + v5);
            if ( v6 )
              goto LABEL_9;
          }
        }
      }
      ExFreePoolWithTag(Buffer, 0);
      result = ReturnLength;
    }
    while ( v3 == STATUS_INFO_LENGTH_MISMATCH );
  }
  else
  {
    v11.m128_u64[0] = 0x77CC3A37D0D81E1LL;
    v11.m128_u64[1] = 0x3C81913F706B0B96LL;
    v12.m128_u64[0] = 0x39F82AC616EEB01BLL;
    v12.m128_u64[1] = 0x919655DB2FEDB05AuLL;
    Thread.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
    Thread.m128_u64[1] = 0x54D5E54D151D6EC4LL;
    v14.m128_u64[0] = 0x5CAB4592728FD569LL;
    v14.m128_u64[1] = 0x919655DB2FEDD636uLL;
    v11 = _mm_xor_ps(v11, Thread);
    v12 = _mm_xor_ps(v12, v14);                 // no m_AsmRevertThreadToSelf
    result = MainLogFunction(128, &unk_14016FCE0, &v11);
  }
  if ( (&v9 ^ v15) != _security_cookie )
    JUMPOUT(0x14006318BLL);
  return result;
}

void __fastcall AntiManualMapping_kinda(
        unsigned __int8 (__fastcall *a1)(unsigned __int64, _QWORD, __int64, __int64),
        __int64 a2)
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  v4 = 0x40000;
  do
  {
    PoolWithTag = ExAllocatePoolWithTag(PagedPool, v4, 0x53425458u);
    if ( !PoolWithTag )
      break;
    v6 = PoolWithTag;
    SystemInformation = ZwQuerySystemInformation(SystemBigPoolInformation, PoolWithTag, v4, 0);
    if ( SystemInformation >= 0 )
    {
      if ( *v6 )
      {
        v9 = v6 + 4;
        v10 = 0;
        do
        {
          v11 = *(v9 - 1);
          LOBYTE(v11) = v11 & 1;
          if ( a1(*(v9 - 1) & 0xFFFFFFFFFFFFFFFEuLL, *v9, v11, a2) )
            break;
          ++v10;
          v9 += 3;
        }
        while ( v10 < *v6 );
      }
      ExFreePoolWithTag(v6, 0x53425458u);
      return;
    }
    v8 = SystemInformation;
    ExFreePoolWithTag(v6, 0x53425458u);
    v4 += 0x40000;
  }
  while ( v8 == -1073741820 );
}