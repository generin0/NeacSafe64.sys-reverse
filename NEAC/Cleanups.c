// probably cleanups

void __fastcall SomeCleanup(volatile signed __int32 **a1)
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  v2 = a1[1];
  if ( v2 )
    MmFreeContiguousMemory(v2);
  v3 = a1[3];
  if ( v3 )
    ExFreePoolWithTag(v3, 0x466B5458u);
  v4 = a1[2];
  if ( v4 )
    ExFreePoolWithTag(v4, 0x466B5458u);
  if ( a1[5] )
    FreeWrapper2();
  v5 = *(a1 + 66);
  if ( v5 )
    MmFreeContiguousMemory(v5);
  v6 = a1[4];
  if ( v6 )
    sub_140001D80(v6);
  v7 = a1[523];
  if ( v7 )
  {
    if ( *(a1 + 1048) )
    {
      v8 = 0;
      v9 = a1[523];
      do
      {
        *sub_140003150(v9) = 0;
        __invlpg(v9);                           // TLB cleanup
        ++v8;
        v9 += 1024;
      }
      while ( v8 < *(a1 + 1048) );
    }
    MmFreeMappingAddress(v7, 0x466B5458u);
  }
  if ( *a1 && !_InterlockedDecrement(*a1) )
  {
    v10 = *a1;
    if ( *(*a1 + 2) )
    {
      ExFreePoolWithTag(*(*a1 + 2), 0x466B5458u);
      v10 = *a1;
    }
    if ( *(v10 + 1) )
    {
      ExFreePoolWithTag(*(v10 + 1), 0x466B5458u);
      v10 = *a1;
    }
    if ( *(v10 + 4) )
    {
      sub_14006DD20(*(v10 + 4));
      v10 = *a1;
    }
    ExFreePoolWithTag(v10, 0x466B5458u);
  }
  ExFreePoolWithTag(a1, 0x466B5458u);
}

void CleanUp()
{
  if ( byte_14115DF58 )
  {
    MainLogFunction(128, &unk_14016FCE0, "timeout3");
    sub_140066FC0();
  }
  sub_14003FD20();
  FltCloseClientPort(Filter, &ClientPort);
  ClientPort = 0;
}

__int64 CleanupFunc()
{
  ULONG v0; // esi
  __int64 v2; // [rsp+0h] [rbp-88h] BYREF
  unsigned __int64 v3; // [rsp+30h] [rbp-58h] BYREF
  unsigned __int64 v4; // [rsp+38h] [rbp-50h] BYREF
  HANDLE Object[9]; // [rsp+40h] [rbp-48h] BYREF

  if ( byte_14115DF58 )
  {
    MainLogFunction(128, &unk_14016FCE0, "timeout4");
    sub_140066FC0();
  }
  sub_141163360(1000);
  if ( !byte_14115DF59 )
    CheckForSuspendedProc(0, &v4, &v3);
  v0 = 0;
  KeSetEvent(&Event, 0, 0);
  sub_140004EB0();
  if ( qword_14115A7D0 )
  {
    Object[0] = qword_14115A7D0;
    v0 = 1;
  }
  if ( qword_14115A7B8 )
    Object[v0++] = qword_14115A7B8;
  if ( qword_14115A7D8 )
    Object[v0++] = qword_14115A7D8;
  if ( qword_14115A7C8 )
    Object[v0++] = qword_14115A7C8;
  if ( qword_14115A7B0 )
    Object[v0++] = qword_14115A7B0;
  if ( qword_14115A7C0 )
  {
    Object[v0++] = qword_14115A7C0;
  }
  else if ( !v0 )
  {
    goto LABEL_30;
  }
  ZwWaitForMultipleObjects(v0, Object, WaitAll, 0, 0);
  if ( qword_14115A7D0 )
    ZwClose(qword_14115A7D0);
  if ( qword_14115A7B8 )
    ZwClose(qword_14115A7B8);
  if ( qword_14115A7D8 )
    ZwClose(qword_14115A7D8);
  if ( qword_14115A7C8 )
    ZwClose(qword_14115A7C8);
  if ( qword_14115A7B0 )
    ZwClose(qword_14115A7B0);
  if ( qword_14115A7C0 )
    ZwClose(qword_14115A7C0);
LABEL_30:
  if ( ServerPort )
  {
    FltCloseCommunicationPort(ServerPort);
    ServerPort = 0;
  }
  if ( ClientPort )
  {
    FltCloseClientPort(Filter, &ClientPort);
    ClientPort = 0;
  }
  FltUnregisterFilter(Filter);
  Filter = 0;
  if ( (&v2 ^ Object[7]) != _security_cookie )
    __debugbreak();
  return 0;
}

__int64 StopLogger()
{
  __int64 result; // rax
  __int64 v1; // [rsp+0h] [rbp-48h] BYREF
  union _LARGE_INTEGER Interval; // [rsp+28h] [rbp-20h] BYREF
  __int64 v3; // [rsp+30h] [rbp-18h]

  MainLogFunction(16, &unk_14016FCE0, "Flushing... (Max log usage = %08x bytes)", qword_141135CB0);
  MainLogFunction(32, &unk_14016FCE0, "Bye!");
  LoggingFlag_ = 0;
  for ( result = *qword_141135C90; result; result = *qword_141135C90 )
  {
    Interval.QuadPart = -500000;
    KeDelayExecutionThread(0, 0, &Interval);
  }
  if ( (&v1 ^ v3) != _security_cookie )
    __debugbreak();
  return result;
}

__int64 OnExit()
{
  MainLogFunction(16, &unk_14016FCE0, "Finalizing... (Max log usage = %08x bytes)", qword_141135CB0);
  MainLogFunction(32, &unk_14016FCE0, "Bye!");
  LoggingFlag_ = 0;
  return clear();
}