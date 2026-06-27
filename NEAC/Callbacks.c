__int64 __fastcall RegisterRegistryCallback(__int64 a1)
{
  PVOID SystemRoutineAddress; // rax
  __int64 (__fastcall *v3)(EX_CALLBACK_FUNCTION *, int *, __int64, _QWORD, union _LARGE_INTEGER *, _QWORD); // rdi
  char v4; // bp
  NTSTATUS v5; // eax
  unsigned int v6; // esi
  __int64 (__fastcall *v7)(PVOID); // rcx
  __int64 v9; // [rsp+0h] [rbp-C8h] BYREF
  int v10; // [rsp+38h] [rbp-90h] BYREF
  _OWORD *v11; // [rsp+40h] [rbp-88h]
  struct _UNICODE_STRING DestinationString; // [rsp+48h] [rbp-80h] BYREF
  _BYTE v13[4]; // [rsp+5Ch] [rbp-6Ch] BYREF
  _OWORD v14[2]; // [rsp+60h] [rbp-68h] BYREF
  __int64 v15; // [rsp+80h] [rbp-48h]

  RtlInitUnicodeString(&DestinationString, L"CmRegisterCallbackEx");
  SystemRoutineAddress = MmGetSystemRoutineAddress(&DestinationString);
  if ( SystemRoutineAddress )
  {
    v3 = SystemRoutineAddress;
    memset(v14, 0, sizeof(v14));
    v10 = 0x200000;
    v11 = v14;
    v4 = -24;
    do
    {
      if ( (v10 & 1) == 0 && !(BYTE2(v10) & 1 | (v10 > HIWORD(v10))) )
        sub_140019DE0(&v10, HIWORD(v10), v10, "%", v13, v4);
      v5 = v3(RegistryCallbackFunction, &v10, a1, 0, &Cookie, 0);
      ++v4;
    }
    while ( v5 == -1071906799 );
  }
  else
  {
    v5 = CmRegisterCallback(RegistryCallbackFunction, 0, &Cookie);
  }
  v6 = v5;
  RtlInitUnicodeString(&DestinationString, L"CmCallbackGetKeyObjectID");
  qword_141136190 = MmGetSystemRoutineAddress(&DestinationString);
  v7 = &sub_140019400;
  if ( !qword_141136190 )
    v7 = sub_1400194D0;
  qword_141136188 = v7;
  if ( (&v9 ^ v15) != _security_cookie )
    JUMPOUT(0x1411C92A1LL);
  return v6;
}

__int64 __fastcall RegistryCallbackFunction(PVOID CallbackContext, PVOID Argument1, _QWORD *Argument2)
{
  unsigned int v3; // esi
  __int64 v5; // [rsp+0h] [rbp-258h] BYREF
  struct _UNICODE_STRING Destination; // [rsp+20h] [rbp-238h] BYREF
  UNICODE_STRING String2; // [rsp+30h] [rbp-228h] BYREF
  char v8; // [rsp+40h] [rbp-218h] BYREF
  __int64 v9; // [rsp+248h] [rbp-10h]

  if ( Argument1 == 1 || (v3 = 0, Argument1 == 8) )
  {
    v3 = 0;
    if ( *Argument2 )
    {
      if ( qword_141136188(*Argument2, 0, &String2) >= 0 )
      {
        *&Destination.Length = 0x2000000;
        Destination.Buffer = &v8;
        if ( sub_1400195D0(&String2, &Destination) < 0 )
        {
          v3 = 0;
        }
        else
        {
          v3 = -1073741790;
          if ( !sub_1400376C0(qword_14115A748) )
            v3 = 0;
        }
        ExFreePoolWithTag(String2.Buffer, 0);
      }
    }
  }
  if ( (&v5 ^ v9) != _security_cookie )
    JUMPOUT(0x140019DD9LL);
  return v3;
}

__int64 CreateAndRegisterCallback()
{
  NTSTATUS v0; // esi
  _BYTE v2[32]; // [rsp+0h] [rbp-78h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+20h] [rbp-58h] BYREF
  __int128 v4; // [rsp+50h] [rbp-28h] BYREF
  __int64 v5; // [rsp+68h] [rbp-10h]

  v4 = *L"(*";
  ObjectAttributes.Length = '0';
  ObjectAttributes.RootDirectory = 0;
  ObjectAttributes.ObjectName = &v4;
  ObjectAttributes.Attributes = '@';
  *&ObjectAttributes.SecurityDescriptor = 0;
  v0 = ExCreateCallback(&Object, &ObjectAttributes, 0, 1u);
  if ( v0 >= 0 )
  {
    CallbackRegistration = ExRegisterCallback(Object, CallbackFunction, 0);
    if ( !CallbackRegistration )
    {
      ObfDereferenceObject(Object);
      Object = 0;
      v0 = -1073741823;
      if ( (v2 ^ v5) == _security_cookie )
        return v0;
LABEL_6:
      __debugbreak();
    }
  }
  if ( (v2 ^ v5) != _security_cookie )
    goto LABEL_6;
  return v0;
}

void __fastcall CallbackFunction(PVOID CallbackContext, PVOID Argument1, PVOID Argument2)
{
  if ( Argument1 == 3 )
  {
    if ( KdDebuggerNotPresent )
    {
      if ( Argument2 )
        goto LABEL_5;
    }
    else
    {
      __debugbreak();
      if ( Argument2 )
      {
LABEL_5:
        MainLogFunction(32, &unk_14016FCE0, "Resuming the system...");
        if ( SafeStartHV() < 0 )
          MainLogFunction(128, &unk_14016FCE0, "Failed to re-virtualize processors. Please unload the driver.");
        return;
      }
    }
    MainLogFunction(32, &unk_14016FCE0, "Suspending the system...");
    CheckForHVAndForSelfHV();
  }
}

char *__fastcall LocateRegistryCallbackList(__int64 a1)
{
  char *result; // rax
  _BYTE v2[40]; // [rsp+0h] [rbp-A8h] BYREF
  int v3; // [rsp+28h] [rbp-80h] BYREF
  __int64 v4; // [rsp+30h] [rbp-78h]
  int v5; // [rsp+38h] [rbp-70h]
  __m128 v6; // [rsp+40h] [rbp-68h] BYREF
  __m128 v7; // [rsp+50h] [rbp-58h]
  __m128 v8; // [rsp+60h] [rbp-48h]
  __m128 v9; // [rsp+70h] [rbp-38h]
  __int64 v10; // [rsp+80h] [rbp-28h]

  v6.m128_u64[0] = 0xB5719765CEA2EBBAuLL;
  v6.m128_u64[1] = 0x16B43EF5C55BD675LL;
  v7.m128_u64[0] = 0x36A8CB299942D579LL;
  v7.m128_u64[1] = 0x1F8EE6A0E092C958LL;
  v8.m128_u64[0] = 0xDC16F237A0F786F9uLL;
  v8.m128_u64[1] = 0x7AD85FB6B73EA206LL;
  v9.m128_u64[0] = 0x36A8CB29F221B41BLL;
  v9.m128_u64[1] = 0x1F8EE6A0E092C958LL;
  v6 = _mm_xor_ps(v6, v8);
  v7 = _mm_xor_ps(v7, v9);                      // CmUnregisterCallback
  result = sub_141166B20(a1, &v6);
  if ( !result
    || BuildNumber < 1536
    || (v3 = 0, v4 = 0, v5 = 0, result = sub_14001A760(result, 256, sub_1411C5AE0, &v3), qword_14115DCE8) )
  {
    if ( (v2 ^ v10) == _security_cookie )
      return result;
LABEL_7:
    __debugbreak();
  }
  v6.m128_u64[0] = 0xBD749E5BC1B4EBBAuLL;
  v6.m128_u64[1] = 0x1F902BC5DE72C965LL;
  v7.m128_u64[0] = 0x5088BF469C01D07ALL;
  v7.m128_u64[1] = 0x1F8EE6A084FCBC37LL;
  v8.m128_u64[0] = 0xDC16F237A0F786F9uLL;
  v8.m128_u64[1] = 0x7AD85FB6B73EA206LL;
  v9.m128_u64[0] = 0x36A8CB29F221B41BLL;
  v9.m128_u64[1] = 0x1F8EE6A0E092C958LL;
  v6 = _mm_xor_ps(v6, v8);
  v7 = _mm_xor_ps(v7, v9);                      // CmCallbackListHead not found
  result = MainLogFunction(128, &unk_14016FCE0, &v6);
  if ( (v2 ^ v10) != _security_cookie )
    goto LABEL_7;
  return result;
}

void __fastcall LoadImageNotifyCallback(PCUNICODE_STRING SourceString, HANDLE ProcessId, int *a3)
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  RtlInitUnicodeString(&DestinationString, L"\\System32\\ntdll.dll");
  RtlInitUnicodeString(&v33, L"\\SysWOW64\\ntdll.dll");
  if ( !qword_14115DD38 )
  {
    qword_14115DD38 = retaddr;
    v6 = RtlLookupFunctionEntry(retaddr, ImageBase, 0);
    if ( v6 )
      qword_14115DD30 = ImageBase[0] + v6->BeginAddress;
  }
  if ( WeirdFastMutexFunction(qword_14115D958, ProcessId) || (*(a3 + 1) & 1) != 0 || byte_14115DF59 )
  {
    if ( sub_1400361B0(qword_14115A718, 4) )
    {
      Process = 0;
      if ( ProcessId < 5
        || (*a3 & 0x100) != 0
        || PsLookupProcessByProcessId(ProcessId, &Process) < 0
        || (ProcessSectionBaseAddress = PsGetProcessSectionBaseAddress(Process),
            v8 = *(a3 + 1),
            ObfDereferenceObject(Process),
            ProcessSectionBaseAddress != v8) )
      {
        v9 = sub_1400361D0(qword_14115A718);
        if ( v9 )
        {
          v10 = v9;
          v11 = *(a3 + 1);
          v12 = *(a3 + 3);
          PoolWithTag = ExAllocatePoolWithTag(PagedPool, 0x529u, 0x53425458u);
          if ( PoolWithTag )
          {
            v14 = PoolWithTag;
            memset((PoolWithTag + 5), 0, 0x524u);
            *v14 = 4;
            *(v14 + 1) = 1321;
            *(v14 + 5) = CountMsFromSysStart(v15);
            *(v14 + 13) = v10;
            *(v14 + 21) = ProcessId;
            *(v14 + 25) = PsGetCurrentThreadId();
            *(v14 + 29) = v11;
            *(v14 + 37) = v12;
            v16 = *a3;
            if ( (*a3 & 0x100) != 0 )
            {
              *(v14 + 21) = 4;
              v16 = *a3;
            }
            *&SourceStringa.Length = 66977792;
            SourceStringa.Buffer = (v14 + 41);
            if ( (v16 & 0x400) != 0 )
            {
              v20 = *(a3 + 5);
              if ( !v20 || sub_140044000(v20, &SourceStringa) )
              {
LABEL_39:
                v23 = sub_14006C090(0x20u, ImageBase);
                if ( !v23 )
                  goto LABEL_52;
                v24 = v23;
                if ( v23 >= 8 && (v14 - ImageBase + 1065) >= 0x20 )
                {
                  v25 = v23 & 0xFFFFFFFC;
                  v28 = 0;
                  do
                  {
                    v29 = *&v36[v28 / 8];
                    *(v14 + v28 + 1065) = *&ImageBase[v28 / 8];
                    *(v14 + v28 + 1081) = v29;
                    v28 += 32LL;
                  }
                  while ( ((8 * v24) & 0xFFFFFFFFFFFFFFE0uLL) != v28 );
                  if ( v25 == v24 )
                    goto LABEL_52;
                }
                else
                {
                  v25 = 0;
                }
                v26 = v25;
                v27 = v24 & 3;
                if ( (v24 & 3) != 0 )
                {
                  v26 = v25;
                  do
                  {
                    *(v14 + 8 * v26 + 1065) = ImageBase[v26];
                    ++v26;
                    --v27;
                  }
                  while ( v27 );
                }
                if ( (v25 - v24) <= 0xFFFFFFFFFFFFFFFCuLL )
                {
                  do
                  {
                    *(v14 + 8 * v26 + 1065) = ImageBase[v26];
                    *(v14 + 8 * v26 + 1073) = ImageBase[v26 + 1];
                    *(v14 + 8 * v26 + 1081) = v36[v26];
                    *(v14 + 8 * v26 + 1089) = v36[v26 + 1];
                    v26 += 4;
                  }
                  while ( v24 != v26 );
                }
LABEL_52:
                ExAcquireFastMutex(qword_14115A718);
                sub_140036210(qword_14115A718, v14);
                ExReleaseFastMutex(qword_14115A718);
                sub_140036280(qword_14115A718);
                ExAcquireFastMutex(qword_14115D960);
                if ( !SourceString )
                  goto LABEL_53;
                goto LABEL_26;
              }
              v21 = qword_14115A750;
              p_Buffer = *(a3 + 5);
            }
            else
            {
              if ( !SourceString )
                goto LABEL_39;
              if ( (v16 & 0x100) != 0
                || !MmIsAddressValid(&SourceString[-6].Buffer)
                || LOWORD(SourceString[-6].Buffer) != 5
                || (WORD1(SourceString[-6].Buffer) - 176) > 0x28u )
              {
LABEL_22:
                RtlCopyUnicodeString(&SourceStringa, SourceString);
                goto LABEL_39;
              }
              v17 = sub_140044000(&SourceString[-6].Buffer, &SourceStringa);
              if ( v17 )
              {
                if ( v17 >= 0 )
                  goto LABEL_39;
                goto LABEL_22;
              }
              v21 = qword_14115A750;
              p_Buffer = &SourceString[-6].Buffer;
            }
            sub_1400378E0(v21, p_Buffer, &SourceStringa);
            goto LABEL_39;
          }
        }
      }
    }
  }
  ExAcquireFastMutex(qword_14115D960);
  if ( !SourceString )
    goto LABEL_53;
LABEL_26:
  if ( sub_1400640D0(qword_14115D960, ProcessId) )
  {
    MainLogFunction(32, &unk_14016FCE0, "xxxxxxxxxxxxxxx");
    LOBYTE(v18) = 1;
    if ( sub_14006E830(&DestinationString, SourceString, v18) )
    {
      MainLogFunction(32, &unk_14016FCE0, "yyyyyyyyyyy");
      if ( !word_14115D830 || HookOnDllMain(ProcessId, *(a3 + 1), &word_14115D830) )
        goto LABEL_53;
    }
    else
    {
      LOBYTE(v19) = 1;
      if ( !sub_14006E830(&v33, SourceString, v19)
        || !word_14115D820
        || SetUpUmHooks(ProcessId, *(a3 + 1), &word_14115D820) )
      {
        goto LABEL_53;
      }
    }
    sub_140064330(qword_14115D960, ProcessId);
  }
LABEL_53:
  ExReleaseFastMutex(qword_14115D960);
  if ( (&v30 ^ v37) != _security_cookie )
    __debugbreak();
}

// ParentID, PID, Create -> create or terminate
void __fastcall NotifyRoutine(HANDLE ParentId, HANDLE ProcessId, int Create)
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  // saving some addr (most likely this function addr or smthng) to prevent some kind of patching or inline hooks in the future i think
  if ( !someAddr )
  {
    someAddr = retaddr;
    v6 = RtlLookupFunctionEntry(ControlPc, &ImageBase, 0);
    if ( v6 )
      ControlPc = ImageBase + v6->BeginAddress;
  }
  if ( Create )
  {
    if ( WeirdFastMutexFunction(qword_14115D968) )
      WeirdFastMutexFunction_0(qword_14115D968);
    if ( !byte_14115DF59 )
    {
      MemoryPoolWithTag = ExAllocatePoolWithTag(NonPagedPool, 0x800u, 0x53425458u);
      if ( MemoryPoolWithTag )
      {
        StartAddrOfAllocatedPool = MemoryPoolWithTag;
        ImageBase = 0x8000000;
        v21 = MemoryPoolWithTag;
        if ( QueryProcessImagePath(ProcessId, &ImageBase) >= 0 )
          CashingProcessOnCreate_Tree(qword_14115D9F0, ProcessId, &ImageBase);
        ExFreePoolWithTag(StartAddrOfAllocatedPool, 0x53425458u);
      }
      goto LABEL_31;
    }
    v7 = ExAllocatePoolWithTag(NonPagedPool, 0x800u, 0x53425458u);
    v8 = ExAllocatePoolWithTag(NonPagedPool, 0x800u, 0x53425458u);
    if ( v7 != 0 && v8 != 0 )
    {
      ImageBase = 0x8000000;
      v21 = v7;
      v19[0] = 0x8000000;
      v19[1] = v8;
      if ( QueryProcessImagePath(ProcessId, &ImageBase) >= 0 )
      {
        if ( QueryProcessImagePath(ParentId, v19) < 0 )
        {
          if ( !FoundItemInsideTree_Tree(qword_14115D9E0) )
            goto LABEL_13;
        }
        else if ( !FoundItemInsideTree_Tree(qword_14115D9E0) )
        {
LABEL_13:
          v9 = FoundItemInsideTree_Tree(qword_14115D9E8);
          CashingProcessOnCreate_Tree(qword_14115D9F0, ProcessId, &ImageBase);
          goto LABEL_42;
        }
        WeirdFastMutexFunction_0(qword_14115D960);
        goto LABEL_13;
      }
      v9 = 0;
    }
    else
    {
      v9 = 0;
      if ( !v7 )
      {
        if ( !v8 )
        {
LABEL_23:
          if ( ((qword_14115DF60 == 0) & v9) == 1 )// if (gameActive && ProcInBlackList)
          {
            Process = 0;
            if ( !PsLookupProcessByProcessId(ProcessId, &Process) )
            {
              if ( IsProcessActive_Aquire(Process) )
              {
                if ( byte_141130270 && !qword_14115DF60 )
                  CreateFalseCopyOf_PML4_InsideSusProc(Process);// Crashing suspect process without TerminateProcess
                IsProcessActive_Release(Process);
              }
              ObfDereferenceObject(Process);
            }
          }
LABEL_31:
          v10 = 0;
          goto LABEL_36;
        }
LABEL_22:
        ExFreePoolWithTag(v8, 0x53425458u);
        goto LABEL_23;
      }
    }
LABEL_42:
    ExFreePoolWithTag(v7, 0x53425458u);
    if ( !v8 )
      goto LABEL_23;
    goto LABEL_22;
  }
  ExAcquireFastMutex(qword_14115D958);
  if ( sub_1400640D0(qword_14115D958, ProcessId) )
  {
    sub_140064330(qword_14115D958, ProcessId);
    v10 = 1;
  }
  else
  {
    v10 = 0;
  }
  ExReleaseFastMutex(qword_14115D958);
  sub_1400642D0(qword_14115D968);
  sub_1400642D0(qword_14115D960);
  sub_1400642D0(qword_14115D970);
  sub_140064760(qword_14115D980, ProcessId);
  sub_1400642D0(qword_14115D978);
  if ( qword_14115DF68 == ProcessId )
    sub_14006BBA0(&qword_14115DF60);
  sub_140066170(qword_14115D9F0);
LABEL_36:
  if ( sub_1400361B0(qword_14115A718, 2) )
  {
    v13 = sub_1400361D0(qword_14115A718);
    v14 = ExAllocatePoolWithTag(PagedPool, 0x930u, 0x53425458u);
    if ( v14 )
    {
      ProcessIda = ProcessId;
      v15 = v14;
      GetProcessInformation(v14, v13, Create, v10, ProcessIda, ParentId);
      ExAcquireFastMutex(qword_14115A718);
      sub_140036210(qword_14115A718, v15);
      ExReleaseFastMutex(qword_14115A718);
      sub_140036280(qword_14115A718);
    }
  }
  if ( (&v16 ^ v22) != _security_cookie )
    __debugbreak();
}

void __fastcall CreateThreadNotifyRoutine(HANDLE ProcessId, HANDLE ThreadId, BOOLEAN Create)
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  v5 = ProcessId;
  if ( !qword_14115DD58 )
  {
    qword_14115DD58 = retaddr;
    v6 = RtlLookupFunctionEntry(qword_14115DD50, &ImageBase[0].Length, 0);
    if ( v6 )
      qword_14115DD50 = *&ImageBase[0].Length + v6->BeginAddress;
  }
  if ( sub_1400361B0(qword_14115A718, 3) )
  {
    v7 = sub_1400361D0(qword_14115A718);
    if ( v7 )
    {
      v8 = v7;
      PoolWithTag = ExAllocatePoolWithTag(PagedPool, 0x132u, 0x53425458u);
      if ( PoolWithTag )
      {
        v10 = PoolWithTag;
        memset(PoolWithTag + 5, 0, 0x12Du);
        *v10 = 3;
        *(v10 + 1) = 306;
        *(v10 + 5) = CountMsFromSysStart();
        *(v10 + 13) = v8;
        *(v10 + 21) = Create;
        *(v10 + 22) = v5;
        *(v10 + 26) = ThreadId;
        *(v10 + 30) = PsGetCurrentProcessId();
        *(v10 + 34) = PsGetCurrentThreadId();
        Thread = 0;
        if ( Create && PsLookupThreadByThreadId(ThreadId, &Thread) >= 0 )
        {
          ClientId.UniqueProcess = 0;
          ClientId.UniqueThread = ThreadId;
          ImageBase[0].Length = 48;
          *&ImageBase[0].RootDirectory = 0;
          ImageBase[0].Attributes = 512;
          *&ImageBase[0].SecurityDescriptor = 0;
          ThreadHandle = 0;
          if ( ZwOpenThread(&ThreadHandle, 0x400u, ImageBase, &ClientId) >= 0 )
          {
            if ( ZwQueryInformationThread(ThreadHandle, ThreadQuerySetWin32StartAddress, &ThreadInformation, 8u, 0) >= 0 )
              *(v10 + 38) = ThreadInformation;
            if ( ZwQueryInformationThread(ThreadHandle, ThreadBreakOnTermination, &v19, 4u, 0) >= 0 )
              *(v10 + 46) = (*(v10 + 46) & 0xFFFFFFFD) + 2 * (v19 != 0);
            ZwClose(ThreadHandle);
          }
          *(v10 + 46) = PsIsSystemThread(Thread) & 1 | *(v10 + 46) & 0xFFFFFFFE;
          ObfDereferenceObject(Thread);
        }
        v11 = sub_14006C090(0x20u, ImageBase);
        if ( !v11 )
          goto LABEL_29;
        v12 = v11;
        if ( v11 >= 8 && (v10 - ImageBase + 50) >= 0x20 )
        {
          v13 = v11 & 0xFFFFFFFC;
          v16 = 0;
          do
          {
            v17 = *&(&ImageBase[0].ObjectName)[v16 / 8];
            *(v10 + v16 + 50) = *(&ImageBase[0].Length + v16);
            *(v10 + v16 + 66) = v17;
            v16 += 32LL;
          }
          while ( ((8 * v12) & 0xFFFFFFFFFFFFFFE0uLL) != v16 );
          if ( v13 == v12 )
          {
LABEL_29:
            ExAcquireFastMutex(qword_14115A718);
            sub_140036210(qword_14115A718, v10);
            ExReleaseFastMutex(qword_14115A718);
            sub_140036280(qword_14115A718);
            goto LABEL_30;
          }
        }
        else
        {
          v13 = 0;
        }
        v14 = v13;
        v15 = v12 & 3;
        if ( (v12 & 3) != 0 )
        {
          v14 = v13;
          do
          {
            *(v10 + 8 * v14 + 50) = *(&ImageBase[0].Length + v14);
            ++v14;
            --v15;
          }
          while ( v15 );
        }
        if ( (v13 - v12) <= 0xFFFFFFFFFFFFFFFCuLL )
        {
          do
          {
            *(v10 + 8 * v14 + 50) = *(&ImageBase[0].Length + v14);
            *(v10 + 8 * v14 + 58) = *(&ImageBase[0].RootDirectory + v14);
            *(v10 + 8 * v14 + 66) = *(&ImageBase[0].ObjectName + v14);
            *(v10 + 8 * v14 + 74) = *(&ImageBase[0].Attributes + v14);
            v14 += 4;
          }
          while ( v12 != v14 );
        }
        goto LABEL_29;
      }
    }
  }
LABEL_30:
  if ( (&v18 ^ v25) != _security_cookie )
    JUMPOUT(0x14005E264LL);
}

void __fastcall AlternativeNotifyRoutine(__int64 a1, __int64 a2, __int64 a3)
{
  void *v4; // rdi
  char v5; // bl
  __int64 v6; // [rsp+0h] [rbp-48h] BYREF
  PEPROCESS Process[5]; // [rsp+20h] [rbp-28h] BYREF

  if ( a3 )                                     // only on proc create
  {
    if ( byte_141130270 )
    {
      v4 = *(a3 + 16);
      if ( (ProtectOtherGames)() )              // Protecting couple of other games, idk why
                                                // CROSSFIRE.EXE, DNF.EXE, GAMELOADER.EXE (loader)
      {
        Process[0] = 0;
        if ( !PsLookupProcessByProcessId(v4, Process) )
        {
          v5 = ProtectOtherGames(Process[0]);
          ObfDereferenceObject(Process[0]);
          if ( v5 )
            *(a3 + 64) = -1073741790;
        }
      }
    }
  }
  if ( (&v6 ^ Process[1]) != _security_cookie )
    __debugbreak();
}

__int64 PrepareCoreCallback()
{
  unsigned int v0; // eax
  __int64 result; // rax
  unsigned __int64 v2; // rax
  __int64 v3; // [rsp+0h] [rbp-88h] BYREF
  __m128 v4; // [rsp+20h] [rbp-68h] BYREF
  __m128 v5; // [rsp+30h] [rbp-58h]
  __m128 v6; // [rsp+40h] [rbp-48h]
  __m128 v7; // [rsp+50h] [rbp-38h]
  __m128 v8; // [rsp+60h] [rbp-28h]
  __m128 v9; // [rsp+70h] [rbp-18h]
  __int64 v10; // [rsp+80h] [rbp-8h]

  v0 = KeGetCurrentProcessorNumberWrapper();
  v4.m128_u64[0] = 0x50B896C844FFC9B1LL;
  v4.m128_u64[1] = 0x1B0128BE4A8D834FLL;
  v5.m128_u64[0] = 0x3BD71D8394DB3161LL;
  v5.m128_u64[1] = 0x53015AA3F5E23B98LL;
  v6.m128_u64[0] = 0x29E6AC336283089BLL;
  v6.m128_u64[1] = 0x95EB7F74492D43FAuLL;
  v7.m128_u64[0] = 0x24D9F8A1298DACE5LL;
  v7.m128_u64[1] = 0x3B5965E86AEAED26LL;
  v8.m128_u64[0] = 0x1BB275F7B4A95E07LL;
  v8.m128_u64[1] = 0x3C7229C6968D49E8LL;
  v9.m128_u64[0] = 0x29E6AC1D06A628E9LL;
  v9.m128_u64[1] = 0x95EB7F74492D43FAuLL;
  v4 = _mm_xor_ps(v4, v7);
  v5 = _mm_xor_ps(v5, v8);
  v6 = _mm_xor_ps(v6, v9);                      // VMM_Prepare_Core: %u
  MainLogFunction(32, &unk_14016FCE0, &v4, v0);
  v7.m128_u64[0] = 0;
  result = EnterHV();
  if ( result >= 0 )
  {
    v2 = __readcr4();
    __writecr4(v2 & 0xFFFFFFFFFFFFDFFFuLL);
    result = 0;
    if ( v7.m128_u64[0] )
    {
      SomeCleanup(v7.m128_u64[0]);
      result = 0;
    }
  }
  if ( (&v3 ^ v10) != _security_cookie )
    __debugbreak();
  return result;
}

bool __fastcall CallbackForEachDriverWrapper(__int64 a1, __int64 a2)
{
  int v4; // eax

  v4 = CallbackForEachDriverWrapper();
  if ( !v4 )
  {
    *(a2 + 8) = *(a1 + 16);
    *(a2 + 16) = *(a1 + 24);
  }
  return v4 == 0;
}

__int64 __fastcall CallbackForEachDriver(unsigned __int8 *a1, unsigned __int8 *a2)
{
  int v4; // r8d
  int v5; // edx
  int v6; // r9d
  int v7; // eax

  do
  {
    v4 = *a1++;
    v5 = *a2;
    v6 = v4 + 32;
    if ( (v4 - 65) > 0x19 )
      v6 = v4;
    v7 = v5 + 32;
    ++a2;
    if ( (v5 - 65) > 0x19 )
      v7 = v5;
  }
  while ( v6 && v6 == v7 );
  return (v6 - v7);
}