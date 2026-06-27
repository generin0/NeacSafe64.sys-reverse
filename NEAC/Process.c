NTSTATUS ProcMonitor()
{
  __int64 v0; // rcx
  __int64 v1; // r12
  __int64 *v2; // rax
  _QWORD *v3; // rdx
  __int64 *v4; // r9
  __int64 *v5; // r8
  _QWORD *v6; // r9
  __int64 v7; // r9
  NTSTATUS result; // eax
  __int64 v9; // [rsp+0h] [rbp-A8h] BYREF
  union _LARGE_INTEGER Timeout; // [rsp+28h] [rbp-80h] BYREF
  unsigned __int64 v11; // [rsp+30h] [rbp-78h] BYREF
  unsigned __int64 v12; // [rsp+38h] [rbp-70h] BYREF
  __m128 v13; // [rsp+40h] [rbp-68h] BYREF
  __m128 v14; // [rsp+50h] [rbp-58h]
  __int64 v15; // [rsp+60h] [rbp-48h]

  for ( Timeout.QuadPart = -100000000;
        KeWaitForSingleObject(&Event, Executive, 0, 0, &Timeout) && ClientPort;
        Timeout.QuadPart = -100000000 )
  {
    sub_140066200(qword_14115D9F0);
    sub_140037BA0(qword_14115A750);
    Aquire_Release_FastMutex(qword_14115D9A0);
    Aquire_Release_FastMutex(qword_14115D9A8);
    v1 = CountMsFromSysStart(v0);
    ExAcquireFastMutex(qword_14115D9B0);
    v2 = *&qword_14115D9B0[1].Count;
    v3 = *v2;
    if ( *v2 == v2 )
    {
LABEL_4:
      ExReleaseFastMutex(qword_14115D9B0);
      if ( byte_14115DF59 )
        continue;
    }
    else
    {
      while ( v1 - v3[6] <= *(v3 + 11) )
      {
        v4 = v3[2];
        if ( *(v4 + 25) )
        {
          do
          {
            v5 = v3[1];
            if ( *(v5 + 25) )
              break;
            v6 = v3;
            v3 = v3[1];
          }
          while ( v6 == v5[2] );
        }
        else
        {
          do
          {
            v5 = v4;
            v4 = *v4;
          }
          while ( !*(v4 + 25) );
        }
        v3 = v5;
        if ( v5 == v2 )
          goto LABEL_4;
      }
      v7 = *(v3 + 10);
      v13.m128_u64[0] = 0xB3739F5ED4D7E2DCuLL;
      v13.m128_u64[1] = 0x7AD85FB6B73ED673LL;
      v14.m128_u64[0] = 0xDC16F237A0F786F9uLL;
      v14.m128_u64[1] = 0x7AD85FB6B73EA206LL;
      v13 = _mm_xor_ps(v13, v14);               // "Process memory corruption detected. Terminating thread."
      MainLogFunction(128, &unk_14016FCE0, &v13, v7);
      ExReleaseFastMutex(qword_14115D9B0);
      v13.m128_u64[0] = 0xFD628758C59AEF8DuLL;
      v13.m128_u64[1] = 0x7AD85FB6B73EA206LL;
      v14.m128_u64[0] = 0xDC16F237A0F786F9uLL;
      v14.m128_u64[1] = 0x7AD85FB6B73EA206LL;
      v13 = _mm_xor_ps(v13, v14);               // "Process memory corruption detected. Terminating thread."
      MainLogFunction(128, &unk_14016FCE0, &v13);
      Aquire_Release_FastMutex(qword_14115D9B0);
      if ( byte_14115DF59 )
        continue;
    }
    CheckForSuspendedProc(3000, &v12, &v11);
  }
  result = PsTerminateSystemThread(0);
  if ( (&v9 ^ v15) != _security_cookie )
    JUMPOUT(0x140040AA7LL);
  return result;
}

void __fastcall CheckForSuspendedProc(unsigned int a1, unsigned __int64 *a2, unsigned __int64 *a3)
{
  LONGLONG msFromSysStart; // rbx
  _QWORD *v5; // r14
  char v6; // r13
  char v7; // al
  __int64 v8; // rcx
  struct _FAST_MUTEX *v9; // rcx
  PFAST_MUTEX v10; // r12
  __int64 v11; // [rsp+0h] [rbp-98h] BYREF
  ULONG_PTR BugCheckParameter2; // [rsp+30h] [rbp-68h]
  PULONG_PTR LowLimit; // [rsp+38h] [rbp-60h]
  PULONG_PTR HighLimit; // [rsp+40h] [rbp-58h]
  PEPROCESS Process[10]; // [rsp+48h] [rbp-50h] BYREF
  _UNKNOWN *retaddr; // [rsp+98h] [rbp+0h] BYREF

  HighLimit = a3;
  LowLimit = a2;
  msFromSysStart = CountMsFromSysStart();
  ExAcquireFastMutex(qword_14115D988);
  v5 = *&qword_14115D988[1].Count;
  BugCheckParameter2 = 0;
  v6 = 0;
  while ( 1 )
  {
    v9 = qword_14115D988;
    if ( v5 == qword_14115D988[1].Owner )
      break;
    if ( msFromSysStart - v5[2] <= a1 )
    {
      v7 = 0;
    }
    else
    {
      Process[0] = 0;
      if ( PsLookupProcessByProcessId(*v5, Process) >= 0 )
      {
        if ( Process[0] == v5[1] && PsGetProcessExitStatus(Process[0]) == 259 )// STILL_ACTIVE
        {
          BugCheckParameter2 = *v5;
          v6 = 1;
        }
        ObfDereferenceObject(Process[0]);
      }
      if ( (v6 & 1) == 0 )
      {
        v10 = qword_14115D988;
        memove(v5, (v5 + 3), qword_14115D988[1].Owner - (v5 + 3));
        v10[1].Owner = v10[1].Owner - 24;
      }
      v7 = v6 ^ 1;
    }
    v8 = 24;
    if ( (v6 & 1) != 0 )
      v8 = 0;
    if ( (v7 & 1) != 0 )
      v8 = 0;
    v5 = (v5 + v8);
    if ( (v6 & 1) != 0 )
    {
      v9 = qword_14115D988;
      break;
    }
  }
  ExReleaseFastMutex(v9);
  if ( (v6 & 1) != 0 )
  {
    __writedr(7u, 0);
    IoGetStackLimits(LowLimit, HighLimit);
    memset(&retaddr, 0, *HighLimit - &retaddr - 48);
    KeBugCheckEx(0x114514u, 1u, BugCheckParameter2, 0, 0);
  }
  if ( (&v11 ^ Process[1]) != _security_cookie )
    __debugbreak();
}

