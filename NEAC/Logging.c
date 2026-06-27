__int64 __fastcall Reading_Writing_From_To_LogFile(__int64 a1)
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  KeEnterCriticalRegion();
  v2 = (a1 + 56);
  ExAcquireResourceExclusiveLite((a1 + 56), 1u);
  memset(&LockHandle, 0, sizeof(LockHandle));
  KeAcquireInStackQueuedSpinLock((a1 + 48), &LockHandle);
  Buffer = *a1;
  v4 = *(a1 + 16);
  if ( *a1 == v4 )
    v4 = *(a1 + 24);
  *a1 = v4;
  *v4 = 0;
  *(a1 + 8) = *a1;
  KeReleaseInStackQueuedSpinLock(&LockHandle);
  IoStatusBlock = 0;
  v5 = *Buffer;
  if ( *Buffer )
  {
    Resource = (a1 + 56);
    v10 = Buffer;
    do
    {
      *Buffer = v5 & 0x7F;
      Length = strlen(Buffer);
      v7 = ZwWriteFile(*(a1 + 40), 0, 0, 0, &IoStatusBlock, Buffer, Length, 0, 0);
      if ( v5 >= 0 )
      {
        *&Buffer[strlen(Buffer) - 2] = 10;
        DbgPrintEx(0x65u, 0, "%s", Buffer);
      }
      v5 = Buffer[Length + 1];
      Buffer += Length + 1;
    }
    while ( v5 );
    v2 = Resource;
    Buffer = v10;
  }
  else
  {
    v7 = 0;
  }
  *Buffer = 0;
  ExReleaseResourceLite(v2);
  KeLeaveCriticalRegion();
  if ( (&v9 ^ v14) != _security_cookie )
    JUMPOUT(0x1400025D8LL);
  return v7;
}

// local variable allocation has failed, the output may be wrong!
__int64 MainLogFunction(int a1, const char *a2, __int64 a3, ...)
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  va_start(va, a3);
  if ( (a1 & LoggingFlag_) == 0 )
  {
    result = 0;
    goto LABEL_22;
  }
  v4 = a1;
  va_copy(v35, va);
  v5 = sub_1400716B0(v37, 411);
  if ( v5 > 0x19B )
  {
    v38 = 0;
    result = 2147483653LL;
    goto LABEL_22;
  }
  if ( v5 == 411 )
    v38 = 0;
  if ( !v37[0] )
  {
    result = 3221225485LL;
    goto LABEL_22;
  }
  v7 = (v4 & 0xF0) - 16;
  result = 3221225485LL;
  if ( v7 > 0x7F )
    goto LABEL_22;
  v8 = v7 >> 4;
  v9 = 139;
  if ( !_bittest(&v9, v8) )
    goto LABEL_22;
  v10 = off_14016FFF0[v8];
  v45 = 0;
  v46 = 0;
  v11 = LoggingFlag_;
  if ( (LoggingFlag_ & 0x100) == 0 )
  {
    SystemTime[0].QuadPart = MEMORY[0xFFFFF78000000014];
    ExSystemTimeToLocalTime(SystemTime, &LocalTime);
    RtlTimeToTimeFields(&LocalTime, &TimeFields);
    result = sub_1400025E0(
               &v45,
               20,
               "%02u:%02u:%02u.%03u\t",
               TimeFields.Hour,
               TimeFields.Minute,
               TimeFields.Second,
               TimeFields.Milliseconds);
    if ( result < 0 )
      goto LABEL_22;
    v11 = LoggingFlag_;
  }
  v43 = 0;
  v42 = 0;
  *&SystemTime[0].LowPart = 0;
  v44 = 0;
  if ( (v11 & 0x200) == 0 )
  {
    if ( a2 )
    {
      if ( *a2 )
      {
        v12 = a2 + 2;
        do
        {
          v13 = *(v12 - 1);
          if ( v13 == 58 )
            a2 = v12;
          ++v12;
        }
        while ( v13 );
      }
    }
    else
    {
      a2 = 0;
    }
    result = sub_1400025E0(SystemTime, 50, "%-40s\t", a2);
    if ( result < 0 )
      goto LABEL_22;
    v11 = LoggingFlag_;
  }
  v40 = 0;
  LocalTime.QuadPart = 0;
  if ( (v11 & 0x400) == 0 )
  {
    v14 = KeGetCurrentProcessorNumberWrapper();
    result = sub_1400025E0(&LocalTime, 10, "#%lu\t", v14);
    if ( result < 0 )
      goto LABEL_22;
  }
  CurrentProcess = IoGetCurrentProcess();
  ProcessImageFileName = PsGetProcessImageFileName(CurrentProcess);
  CurrentThreadId = PsGetCurrentThreadId();
  v18 = IoGetCurrentProcess();
  ProcessId = PsGetProcessId(v18);
  result = sub_1400025E0(
             &TimeFields,
             512,
             "%s%s%s%5Iu\t%5Iu\t%-15s\t%s%s\r\n",
             &v45,
             v10,
             &LocalTime,
             ProcessId,
             CurrentThreadId,
             ProcessImageFileName,
             SystemTime,
             v37);
  if ( result < 0 )
    goto LABEL_22;
  if ( (v4 & 1) != 0 )
  {
    v21 = 0;
    result = 0;
    if ( !xmmword_141135CA0 )
      goto LABEL_22;
LABEL_42:
    *&SystemTime[0].LowPart = 0;
    *&v42 = 0;
    CurrentIrql = KeGetCurrentIrql();
    if ( (CurrentIrql & 0xFE) != 0 )
      KeAcquireInStackQueuedSpinLockAtDpcLevel(&SpinLock, SystemTime);
    else
      KeAcquireInStackQueuedSpinLock(&SpinLock, SystemTime);
    v23 = qword_141135C98;
    v24 = qword_141135C98 - qword_141135C90;
    if ( (qword_141135C98 - qword_141135C90 + 2147418112) > 0x7FFFFFFE )
    {
      v29 = -1073741811;
      v30 = 0x10000;
      if ( v24 != 0xFFFF )
      {
LABEL_53:
        *v23 = 0;
        v30 = 0x10000;
        v23 = qword_141135C98;
      }
    }
    else
    {
      v25 = -2147483645;
      do
      {
        v26 = *(&STACK[0x8000005D] + v25);
        if ( !v26 )
        {
          v23 += v25 + 2147483645;
          goto LABEL_55;
        }
        v23[v25 + 2147483645] = v26;
        v27 = v25 + 1;
        if ( v24 + v25 == -2147418111 )
          break;
      }
      while ( v25++ != 0 );
      v23 = (v27 + ((__PAIR128__(v23, v24 + v27 + 2147418110) - 1) >> 64) + 2147483645);
      if ( v24 + v27 == -2147418110 )
      {
        v29 = -2147483643;
        goto LABEL_53;
      }
LABEL_55:
      *v23 = 0;
      v31 = strlen(&TimeFields);
      v23 = (qword_141135C98 + v31 + 1);
      qword_141135C98 = v23;
      v30 = v31 + v24 + 1;
      v29 = 0;
      if ( v30 <= qword_141135CB0 )
      {
LABEL_57:
        v32 = v29;
        *v23 = 0;
        if ( (CurrentIrql & 0xFE) != 0 )
          KeReleaseInStackQueuedSpinLockFromDpcLevel(SystemTime);
        else
          KeReleaseInStackQueuedSpinLock(SystemTime);
        LOBYTE(TimeFields.Year) &= ~0x80u;
        result = v32;
        if ( v21 )
          goto LABEL_61;
        goto LABEL_22;
      }
    }
    qword_141135CB0 = v30;
    goto LABEL_57;
  }
  v20 = KeGetCurrentIrql();
  if ( !xmmword_141135CA0 )
    goto LABEL_35;
  if ( KeGetCurrentIrql() || (byte_141135D31 & 1) == 0 )
  {
    if ( v20 > 0xCu )
    {
      v21 = 0;
    }
    else
    {
      LOBYTE(TimeFields.Year) |= 0x80u;
      v21 = 1;
    }
    goto LABEL_42;
  }
  if ( sub_1400036B0() )
  {
LABEL_35:
    result = 0;
    if ( v20 > 0xCu )
      goto LABEL_22;
    goto LABEL_61;
  }
  Reading_Writing_From_To_LogFile(&qword_141135C90);
  result = WriteFile_Wrapper(&TimeFields);
  if ( v20 < 0xDu )
  {
LABEL_61:
    v33 = result;
    *(&v35 + strlen(&TimeFields) + 6) = 10;
    DbgPrintEx(0x65u, 0, "%s", &TimeFields);
    result = v33;
  }
LABEL_22:
  if ( (&v34 ^ v47) != _security_cookie )
    __debugbreak();
  return result;
}

__int64 MainLogFunction_Wrapper()
{
  return MainLogFunction(
           32,
           &unk_14016FCE0,
           "%-45s,%-20s,%-20s",
           "FunctionName(Line)",
           "Execution Count",
           "Elapsed Time");
}

__int64 __fastcall MainLogFunction_Wrapper2(const char *a1, __int64 a2, __int64 a3)
{
  return MainLogFunction(32, &unk_14016FCE0, "%-45s,%20I64u,%20I64u,", a1, a2, a3);
}

__int64 WeirdShit()
{
  unsigned int v0; // esi
  char *PoolWithTag; // rax
  void *v2; // rdi

  v0 = 0;
  PoolWithTag = ExAllocatePoolWithTag(NonPagedPool, 0x12F8u, 0x466B5458u);
  if ( PoolWithTag )
  {
    *PoolWithTag = MainLogFunction_Wrapper;
    *(PoolWithTag + 1) = nullsub_1;
    *(PoolWithTag + 2) = MainLogFunction_Wrapper_0;
    *(PoolWithTag + 3) = nullsub_1;
    *(PoolWithTag + 4) = nullsub_1;
    v2 = PoolWithTag;
    (memset)((PoolWithTag + 40), 0, 0x12D0u);
    qword_141135ED0 = v2;
  }
  else
  {
    return STATUS_MEMORY_NOT_ALLOCATED;
  }
  return v0;
}