NTSTATUS __fastcall IoProcessMemoryManipulations(Ctx *a1, unsigned int a2)
{
  int FalseCopyOf_PML4_InsideSusProc; // esi
  Ctx *v3; // rdi
  unsigned __int64 v4; // rdi
  int v5; // r14d
  BYTE Param; // bl
  NTSTATUS result; // eax
  struct _FAST_MUTEX *v8; // rcx
  PEPROCESS Process; // [rsp+28h] [rbp-8h] BYREF
                                                // Handling IOCTL like commands probably, im not sure
  FalseCopyOf_PML4_InsideSusProc = STATUS_INVALID_PARAMETER;
  if ( a2 < 0xA )
    return FalseCopyOf_PML4_InsideSusProc;
  if ( a1 + a2 < MmUserProbeAddress )
  {
    v3 = a1;
    ProbeForRead(a1, 0xAu, 1u);
    a1 = v3;
  }
  v4 = *(&a1->Magic + 1);
  if ( v4 < 5 )
    return FalseCopyOf_PML4_InsideSusProc;
  v5 = *(&a1->ProcessId + 1);
  Param = a1->Param;
  result = PsLookupProcessByProcessId(*(&a1->Magic + 1), &Process);
  if ( result >= 0 )
  {
    if ( IsProcessActive_Aquire(Process) )
    {
      switch ( v5 )
      {
        case 1:
          v8 = qword_14115D970;
          goto LABEL_19;
        case 2:
          FalseCopyOf_PML4_InsideSusProc = sub_141166840(Process, Param);
          goto LABEL_25;
        case 3:
          if ( Param )
          {
            if ( SomeByteWrapper() )
            {
              FalseCopyOf_PML4_InsideSusProc = 0x40000000;
              if ( !qword_14115DF60 )
                FalseCopyOf_PML4_InsideSusProc = CreateFalseCopyOf_PML4_InsideSusProc(Process, &qword_14115DF60);
            }
            else
            {
              FalseCopyOf_PML4_InsideSusProc = STATUS_NOT_SUPPORTED;
            }
            goto LABEL_25;
          }
          FalseCopyOf_PML4_InsideSusProc = STATUS_OBJECT_NAME_NOT_FOUND;
          if ( qword_14115DF60 != Process )
            goto LABEL_25;
          sub_14006BBA0(&qword_14115DF60);
          goto LABEL_24;
        case 4:
          v8 = qword_14115D978;
LABEL_19:
          if ( Param )
            goto LABEL_20;
          goto LABEL_23;
        case 5:
          if ( !Param )
          {
            v8 = qword_14115D970;
LABEL_23:
            sub_1400642D0(v8, v4);
            goto LABEL_24;
          }
          if ( sub_14005F870() )
          {
            v8 = qword_14115D970;
LABEL_20:
            WeirdFastMutexFunction_0(v8, v4);
LABEL_24:
            FalseCopyOf_PML4_InsideSusProc = 0;
            goto LABEL_25;
          }
          FalseCopyOf_PML4_InsideSusProc = STATUS_UNSUCCESSFUL;
LABEL_25:
          IsProcessActive_Release(Process);
          break;
        default:
          goto LABEL_25;
      }
    }
    else
    {
      FalseCopyOf_PML4_InsideSusProc = STATUS_PROCESS_IS_TERMINATING;
    }
    ObfDereferenceObject(Process);
    return FalseCopyOf_PML4_InsideSusProc;
  }
  return result;
}

