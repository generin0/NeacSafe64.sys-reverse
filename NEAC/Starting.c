// checking for new logs every 50ms
void __fastcall StartRoutine(_BYTE *StartContext)
{
  HANDLE CurrentThreadId; // rax
  NTSTATUS v3; // edi
  __int64 v4; // [rsp+0h] [rbp-58h] BYREF
  union _LARGE_INTEGER Interval; // [rsp+28h] [rbp-30h] BYREF
  __int64 v6; // [rsp+30h] [rbp-28h]

  StartContext[162] = 1;
  CurrentThreadId = PsGetCurrentThreadId();
  MainLogFunction(16, &unk_14016FCE0, "Log thread started (TID= %p).", CurrentThreadId);
  v3 = 0;
  if ( (StartContext[161] & 1) != 0 )
  {
    v3 = 0;
    do
    {
      if ( **StartContext )
        v3 = Reading_Writing_From_To_LogFile(StartContext);
      Interval.QuadPart = -500000;
      KeDelayExecutionThread(0, 0, &Interval);
    }
    while ( (StartContext[161] & 1) != 0 );     // flag, if settled into 0, monitoring will be stopped
  }
  PsTerminateSystemThread(v3);
  if ( (&v4 ^ v6) != _security_cookie )
    JUMPOUT(0x141162EBCLL);
}

NTSTATUS __fastcall Setup(PVOID StartContext, PHANDLE FileHandle, NTSTATUS *a3)
{
  NTSTATUS result; // eax
  NTSTATUS v7; // ebp
  NTSTATUS v8; // ebp
  __int64 v9; // [rsp+0h] [rbp-F8h] BYREF
  union _LARGE_INTEGER Interval; // [rsp+58h] [rbp-A0h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+60h] [rbp-98h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+70h] [rbp-88h] BYREF
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+A0h] [rbp-58h] BYREF
  __int64 v14; // [rsp+B8h] [rbp-40h]

  DestinationString = 0;
  RtlInitUnicodeString(&DestinationString, StartContext + 88);
  *&ObjectAttributes.Length = 0;
  memset(&ObjectAttributes.Attributes + 1, 0, 20);
  ObjectAttributes.Length = 48;
  ObjectAttributes.Attributes = 576;
  ObjectAttributes.ObjectName = &DestinationString;
  IoStatusBlock = 0;
  result = ZwCreateFile(FileHandle, 0x100004u, &ObjectAttributes, &IoStatusBlock, 0, 0x80u, 1u, 3u, 0x60u, 0, 0);// creating fpsneac.log
  if ( result >= 0 )
  {
    *(StartContext + 161) = 1;
    result = PsCreateSystemThread(StartContext + 21, 0x10000000u, 0, 0, 0, StartRoutine, StartContext);
    if ( result < 0 )
    {
      v8 = result;
      ZwClose(*FileHandle);
      result = v8;
      *FileHandle = 0;
      *(StartContext + 161) = 0;
    }
    else if ( (*(StartContext + 162) & 1) == 0 )
    {
      v7 = result;
      do
      {
        Interval.QuadPart = -1000000;
        KeDelayExecutionThread(0, 0, &Interval);
      }
      while ( (*(StartContext + 162) & 1) == 0 );
      result = v7;
    }
  }
  *a3 = result;
  if ( (&v9 ^ v14) != _security_cookie )
    JUMPOUT(0x1400028AELL);
  return result;
}