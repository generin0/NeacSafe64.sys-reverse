// this file will include everything about kernel features that were used inside NEAC modules, exclude hooks

__int64 __fastcall ReadKernelFromDisk(void (__fastcall *a1)(PVOID, ULONG_PTR, __int64), __int64 a2)
{
  unsigned int v4; // esi
  NTSTATUS v5; // eax
  NTSTATUS v6; // eax
  unsigned __int64 v7; // rdx
  __m128 *v8; // rcx
  _BYTE v10[32]; // [rsp+0h] [rbp-198h] BYREF
  ULONG_PTR ViewSize; // [rsp+50h] [rbp-148h] BYREF
  PVOID BaseAddress; // [rsp+58h] [rbp-140h] BYREF
  void *SectionHandle; // [rsp+60h] [rbp-138h] BYREF
  void *FileHandle; // [rsp+68h] [rbp-130h] BYREF
  struct _IO_STATUS_BLOCK IoStatusBlock; // [rsp+70h] [rbp-128h] BYREF
  struct _OBJECT_ATTRIBUTES ObjectAttributes; // [rsp+80h] [rbp-118h] BYREF
  __m128 v17; // [rsp+B0h] [rbp-E8h] BYREF
  __m128 v18; // [rsp+C0h] [rbp-D8h]
  __m128 v19; // [rsp+D0h] [rbp-C8h]
  char v20; // [rsp+E0h] [rbp-B8h] BYREF
  char v21; // [rsp+110h] [rbp-88h] BYREF
  char v22; // [rsp+140h] [rbp-58h] BYREF
  __int64 v23; // [rsp+178h] [rbp-20h]

  FileHandle = 0;
  SectionHandle = 0;
  BaseAddress = 0;
  ViewSize = 0;
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = 0;
  ObjectAttributes.Attributes = 576;
  ObjectAttributes.ObjectName = &KernelFilePath;
  *&ObjectAttributes.SecurityDescriptor = 0;
  v4 = ZwOpenFile(&FileHandle, 0x120089u, &ObjectAttributes, &IoStatusBlock, 3u, 0x20u);
  if ( v4 == -1073741757 )
    v4 = ZwOpenFile(&FileHandle, 0x120089u, &ObjectAttributes, &IoStatusBlock, 1u, 0x20u);
  if ( (v4 & 0x80000000) != 0 )
  {
    v17.m128_u64[0] = 0x186AE9DC7E489EE0LL;
    v17.m128_u64[1] = 0x31B98C2B35710BAALL;
    v18.m128_u64[0] = 0x7CCF20FE1BEEB349LL;
    v18.m128_u64[1] = 0xA9A670FB4799BF41uLL;
    v7 = 0x7B4E72C06E15352BLL;                  // Failed to open kernel file: %08X\n
    v8 = &v22;
  }
  else
  {
    ObjectAttributes.ObjectName = 0;
    v5 = ZwCreateSection(&SectionHandle, 0xF001Fu, &ObjectAttributes, 0, 2u, 0x1000000u, FileHandle);
    if ( v5 < 0 )
    {
      v4 = v5;
      v17.m128_u64[0] = 0x186AE9DC7E489EE0LL;
      v17.m128_u64[1] = 0x20B6803E35710BAALL;
      v18.m128_u64[0] = 0x30C224F452E1BA00LL;
      v18.m128_u64[1] = 0xB1FE21B258CDB253uLL;
      v7 = 0x7B4E72EE362D2B56LL;                // Failed to create section: %08X\n
      v8 = &v21;
    }
    else
    {
      v4 = 0;
      v6 = ZwMapViewOfSection(
             SectionHandle,
             0xFFFFFFFFFFFFFFFFLL,
             &BaseAddress,
             0,
             0,
             0,
             &ViewSize,
             ViewShare,
             0x100000u,
             2u);
      if ( v6 >= 0 )
      {
        a1(BaseAddress, ViewSize, a2);
        ZwUnmapViewOfSection(0xFFFFFFFFFFFFFFFFLL, BaseAddress);
        ZwClose(SectionHandle);
        ZwClose(FileHandle);
        if ( (v10 ^ v23) != _security_cookie )
          goto LABEL_7;
        return v4;
      }
      v17.m128_u64[0] = 0x47DE797305D8FE2LL;
      v17.m128_u64[1] = 0x3DA18628663D02A1LL;
      v18.m128_u64[0] = 0x39C72CF314AFBB06LL;
      v18.m128_u64[1] = 0xB4B63DAF469AF652uLL;
      v7 = 0x7B4E72C0404D2343LL;                // Failed to map view: %08X\n
      v8 = &v20;
      v4 = v6;
    }
  }
  v19.m128_u64[0] = v7;
  v19.m128_u64[1] = 0xAB2A09817ACB3C58uLL;
  v8->m128_u64[0] = 0x6A0F82FC102DEE8FLL;
  v8->m128_u64[1] = 0x54D5E54D151D6EC4LL;
  v8[1].m128_u64[0] = 0x5CAB4592728FD569LL;
  v8[1].m128_u64[1] = 0x919655DB2FEDD636uLL;
  v8[2].m128_u64[0] = 0x7B4E72C06E151B73LL;
  v8[2].m128_u64[1] = 0xAB2A09817ACB3C58uLL;
  v17 = _mm_xor_ps(v17, *v8);
  v18 = _mm_xor_ps(v18, v8[1]);
  v19 = _mm_xor_ps(v19, v8[2]);
  MainLogFunction(128, &unk_14016FCE0, &v17, v4);
  if ( (v10 ^ v23) != _security_cookie )
LABEL_7:
    __debugbreak();
  return v4;
}

__int64 __fastcall LookingForKernelInMem(__int64 a1, unsigned __int64 a2)
{
  unsigned __int64 v2; // rax
  unsigned __int64 v3; // rax
  PIMAGE_NT_HEADERS NtHeaders; // rax
  __int64 v7; // [rsp+0h] [rbp-58h] BYREF
  UNICODE_STRING SourceString; // [rsp+20h] [rbp-38h] BYREF
  struct _STRING DestinationString; // [rsp+30h] [rbp-28h] BYREF
  __int64 v10; // [rsp+40h] [rbp-18h]

  // This function looking for kernel in memory and collecting some information about it - where it starts and where it 

  // ends, then formatting complete way to the ntoskrnl.exe and putting everything in global variables
  if ( qword_14115DE78 || (v3 = *(a1 + 16), *(a1 + 32)) && (a2 < v3 || a2 >= v3 + *(a1 + 24)) )
  {
    if ( !qword_14115DE90 )
    {
      v2 = *(a1 + 16);
      if ( v2 <= LookingForKernelInMem && v2 + *(a1 + 24) > LookingForKernelInMem )
      {
        qword_14115DE90 = *(a1 + 16);
        qword_14115DE98 = *(a1 + 16) + *(a1 + 24);
      }
    }
  }
  else
  {
    qword_14115DE78 = *(a1 + 16);
    qword_14115DE80 = *(a1 + 16) + *(a1 + 24);
    NtHeaders = RtlImageNtHeader(*(a1 + 16));
    if ( NtHeaders )
      CheckSum = NtHeaders->OptionalHeader.CheckSum;
    DestinationString = 0;
    SourceString = 0;
    RtlInitAnsiString(&DestinationString, (a1 + *(a1 + 38) + 40));
    KernelFilePath.Buffer = ExAllocatePoolWithTag(PagedPool, 0x208u, 0x53425458u);
    if ( KernelFilePath.Buffer )
    {
      *&KernelFilePath.Length = 34078720;
      RtlInitUnicodeString(&SourceString, L"\\SystemRoot\\System32\\");
      RtlCopyUnicodeString(&KernelFilePath, &SourceString);
      SourceString.Buffer = (KernelFilePath.Buffer + KernelFilePath.Length);
      SourceString.Length = 0;
      SourceString.MaximumLength = KernelFilePath.MaximumLength - KernelFilePath.Length;
      RtlAnsiStringToUnicodeString(&SourceString, &DestinationString, 0);
      KernelFilePath.Length += SourceString.Length;
    }
  }
  if ( (&v7 ^ v10) != _security_cookie )
    __debugbreak();
  return 0;
}

__int64 __fastcall LoadCustomKernelAndCmpWithCurrent(struct _UNICODE_STRING *a1)
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  FileHandle = 0;
  ByteOffset.QuadPart = 0;
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = 0;
  ObjectAttributes.Attributes = 64;
  ObjectAttributes.ObjectName = a1;
  *&ObjectAttributes.SecurityDescriptor = 0;
  if ( ZwCreateFile(&FileHandle, 1u, &ObjectAttributes, &IoStatusBlock, 0, 0x80u, 1u, 1u, 0x60u, 0, 0) < 0 )
  {
LABEL_9:
    v5 = 0;
    v3 = 0;
    v6 = FileHandle;
    if ( !FileHandle )
      goto LABEL_11;
    goto LABEL_10;
  }
  v1 = ZwQueryInformationFile(FileHandle, &IoStatusBlock, FileInformation, 0x18u, FileStandardInformation);
  if ( v1 < 0 )
  {
    v15.m128_u64[0] = 0xB8779D5BC5A5E3B2uLL;
    v15.m128_u64[1] = 0x3CA12DD7C55CCB4ALL;
    v16.m128_u64[0] = 0x16CDA740B44CDB69LL;
    v16.m128_u64[1] = 0x6BAE82C58CFBA83ELL;
    v17.m128_u64[0] = 0xCD2C939EC6E044C2uLL;
    v17.m128_u64[1] = 0xBE4AED8376C620ACuLL;
    v18.m128_u64[0] = 0x2B54A0A540A820C1LL;
    v18.m128_u64[1] = 0x66DC2C40D04027CLL;
    v19.m128_u64[0] = 0xDC16F237A0F786F9uLL;
    v19.m128_u64[1] = 0x7AD85FB6B73EA206LL;
    v20.m128_u64[0] = 0x36A8CB29F221B41BLL;
    v20.m128_u64[1] = 0x1F8EE6A0E092C958LL;
    v21.m128_u64[0] = 0xED55E1FBB39164ADuLL;
    v21.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
    v22.m128_u64[0] = 0x2B7AF89D708D00EFLL;
    v22.m128_u64[1] = 0x66DC2C40D04027CLL;
    v15 = _mm_xor_ps(v15, v19);
    v16 = _mm_xor_ps(v16, v20);
    v17 = _mm_xor_ps(v17, v21);
    v18 = _mm_xor_ps(v18, v22);                 // Failed to query file info: %08X\n
    MainLogFunction(128, &unk_14016FCE0, &v15, v1);
    goto LABEL_9;
  }
  Pool = ExAllocatePool(PagedPool, NumberOfBytes);
  if ( !Pool )
  {
    v15.m128_u64[0] = 0xB8779D5BC5A5E3B2uLL;
    v15.m128_u64[1] = 0x3CA12DD7C55CCB4ALL;
    v16.m128_u64[0] = 0x16CDA740B44CDB69LL;
    v16.m128_u64[1] = 0x6BAE82C58CFBA83ELL;
    v17.m128_u64[0] = 0x8C368E97DFF044C2uLL;
    v17.m128_u64[1] = 0xA84EA392368A2CBEuLL;
    v18.m128_u64[0] = 0x2B7AF89D5EFE659BLL;
    v18.m128_u64[1] = 0x66DC2C40D04027CLL;
    v19.m128_u64[0] = 0xDC16F237A0F786F9uLL;
    v19.m128_u64[1] = 0x7AD85FB6B73EA206LL;
    v20.m128_u64[0] = 0x36A8CB29F221B41BLL;
    v20.m128_u64[1] = 0x1F8EE6A0E092C958LL;
    v21.m128_u64[0] = 0xED55E1FBB39164ADuLL;
    v21.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
    v22.m128_u64[0] = 0x2B7AF89D708D00EFLL;
    v22.m128_u64[1] = 0x66DC2C40D04027CLL;
    v15 = _mm_xor_ps(v15, v19);
    v16 = _mm_xor_ps(v16, v20);
    v17 = _mm_xor_ps(v17, v21);
    v18 = _mm_xor_ps(v18, v22);                 // Failed to allocate memory for file buffer: %llX\n
    MainLogFunction(128, &unk_14016FCE0, &v15, NumberOfBytes);
    goto LABEL_9;
  }
  v3 = Pool;
  v4 = ZwReadFile(FileHandle, 0, 0, 0, &IoStatusBlock, Pool, NumberOfBytes, &ByteOffset, 0);
  if ( v4 >= 0 )
  {
    v5 = ManualMappingModule(v3);
    v6 = FileHandle;
    if ( !FileHandle )
      goto LABEL_11;
LABEL_10:
    ZwClose(v6);
    goto LABEL_11;
  }
  v15.m128_u64[0] = 0xB8779D5BC5A5E3B2uLL;
  v15.m128_u64[1] = 0x3CA12DD7C55CCB4ALL;
  v16.m128_u64[0] = 0x16CDA740B44CDB69LL;
  v16.m128_u64[1] = 0x6BAE82C58CFBA83ELL;
  v17.m128_u64[0] = 0x8B75859AD6E344C2uLL;
  v17.m128_u64[1] = 0xE91CA6CA3DCF25A3uLL;
  v18.m128_u64[0] = 0x2B7AF89D708D2EB7LL;
  v18.m128_u64[1] = 0x66DC2C40D04027CLL;
  v19.m128_u64[0] = 0xDC16F237A0F786F9uLL;
  v19.m128_u64[1] = 0x7AD85FB6B73EA206LL;
  v20.m128_u64[0] = 0x36A8CB29F221B41BLL;
  v20.m128_u64[1] = 0x1F8EE6A0E092C958LL;
  v21.m128_u64[0] = 0xED55E1FBB39164ADuLL;
  v21.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
  v22.m128_u64[0] = 0x2B7AF89D708D00EFLL;
  v22.m128_u64[1] = 0x66DC2C40D04027CLL;
  v15 = _mm_xor_ps(v15, v19);
  v16 = _mm_xor_ps(v16, v20);
  v17 = _mm_xor_ps(v17, v21);
  v18 = _mm_xor_ps(v18, v22);                   // Failed to read file: %08X\n
  MainLogFunction(128, &unk_14016FCE0, &v15, v4);
  v5 = 0;
  v6 = FileHandle;
  if ( FileHandle )
    goto LABEL_10;
LABEL_11:
  if ( v3 )
    ExFreePoolWithTag(v3, 0);
  if ( (&v8 ^ v23) != _security_cookie )
    __debugbreak();
  return v5;
}

char *__fastcall ManualMappingModule(void *a1)
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  v2 = RtlImageNtHeader(a1);
  if ( !v2 )
  {
    v11.m128_u64[0] = 0xB15F9656CFBBE3B2uLL;
    v11.m128_u64[1] = 0x3CB530C4F15BC567LL;
    v12.m128_u64[0] = 0x5AC1AA4FD244D872LL;
    v12.m128_u64[1] = 0x7AF8C6CF94B2AD3DLL;
    v13.m128_u64[0] = 0x8C3888DBCAF70DDFuLL;
    v13.m128_u64[1] = 0xB448E28F7B8A2CADuLL;
    v14.m128_u64[0] = 0x2B7AF89D708D2E9DLL;
    v14.m128_u64[1] = 0x66DC2C40D04027CLL;
    v17.m128_u64[0] = 0xDC16F237A0F786F9uLL;
    v17.m128_u64[1] = 0x7AD85FB6B73EA206LL;
    v18.m128_u64[0] = 0x36A8CB29F221B41BLL;
    v18.m128_u64[1] = 0x1F8EE6A0E092C958LL;
    v19.m128_u64[0] = 0xED55E1FBB39164ADuLL;
    v19.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
    v20.m128_u64[0] = 0x2B7AF89D708D00EFLL;
    v20.m128_u64[1] = 0x66DC2C40D04027CLL;
    v11 = _mm_xor_ps(v11, v17);
    v12 = _mm_xor_ps(v12, v18);
    v13 = _mm_xor_ps(v13, v19);
    v14 = _mm_xor_ps(v14, v20);                 // Failed to parse NT headers for internal module\n
LABEL_11:
    MainLogFunction(128, &unk_14016FCE0, &v11);
    goto LABEL_12;
  }
  NtHeaders = v2;
  if ( v2->OptionalHeader.CheckSum != dword_14115DEDC )
  {
    v11.m128_u64[0] = 0xB15F9656CFBBE3B2uLL;
    v11.m128_u64[1] = 0x3CB530C4F15BC567LL;
    v12.m128_u64[0] = 0x5FC9AD099444D872LL;
    v12.m128_u64[1] = 0x69AE89D4C0F6AC34LL;
    v13.m128_u64[0] = 0x993BC182D5F816C8uLL;
    v13.m128_u64[1] = 0xBA4FE682708A3AA5uLL;
    v14.m128_u64[0] = 0x521B95BD5CE0759CLL;
    v14.m128_u64[1] = 0x6E19E2AA6C24671ELL;
    v15.m128_u64[0] = 0xDCD69E084C719B64uLL;
    v15.m128_u64[1] = 0x9671CCE115C9DEFLL;
    v16.m128_u64[0] = 0x8BA857F1FCEFF606uLL;
    v16.m128_u64[1] = 0xE9475A68D1B91B80uLL;
    v17.m128_u64[0] = 0xDC16F237A0F786F9uLL;
    v17.m128_u64[1] = 0x7AD85FB6B73EA206LL;
    v18.m128_u64[0] = 0x36A8CB29F221B41BLL;
    v18.m128_u64[1] = 0x1F8EE6A0E092C958LL;
    v19.m128_u64[0] = 0xED55E1FBB39164ADuLL;
    v19.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
    v20.m128_u64[0] = 0x2B7AF89D708D00EFLL;
    v20.m128_u64[1] = 0x66DC2C40D04027CLL;
    v21.m128_u64[0] = 0xFCA5FF7F6C14E901uLL;
    v21.m128_u64[1] = 0x7D0678BE647CF38ELL;
    v22.m128_u64[0] = 0x8BA857F1FCEFD863uLL;
    v22.m128_u64[1] = 0xE9475A68D1B91B80uLL;
    v11 = _mm_xor_ps(v11, v17);
    v12 = _mm_xor_ps(v12, v18);
    v13 = _mm_xor_ps(v13, v19);
    v14 = _mm_xor_ps(v14, v20);
    v15 = _mm_xor_ps(v15, v21);
    v16 = _mm_xor_ps(v16, v22);                 // Module checksum mismatch! Expected: %08X, Found: %08X\n
    goto LABEL_11;
  }
  v4 = v2->OptionalHeader.SectionAlignment
     + v2->OptionalHeader.SizeOfImage
     - 1
     - (v2->OptionalHeader.SectionAlignment + v2->OptionalHeader.SizeOfImage - 1) % v2->OptionalHeader.SectionAlignment;
  Pool = ExAllocatePool(NonPagedPool, v4);
  if ( !Pool )
  {
    v11.m128_u64[0] = 0xB15F9656CFBBE3B2uLL;
    v11.m128_u64[1] = 0x3CB530C4F15BC567LL;
    v12.m128_u64[0] = 0x5FC9AD099444D872LL;
    v12.m128_u64[1] = 0x7EAE89D4C0F6AC34LL;
    v13.m128_u64[0] = 0xCD30959AD0FE08C1uLL;
    v13.m128_u64[1] = 0xA249F793718A31EFuLL;
    v14.m128_u64[0] = 0x2B7AF89D708D00C1LL;
    v14.m128_u64[1] = 0x66DC2C40D04027CLL;
    v17.m128_u64[0] = 0xDC16F237A0F786F9uLL;
    v17.m128_u64[1] = 0x7AD85FB6B73EA206LL;
    v18.m128_u64[0] = 0x36A8CB29F221B41BLL;
    v18.m128_u64[1] = 0x1F8EE6A0E092C958LL;
    v19.m128_u64[0] = 0xED55E1FBB39164ADuLL;
    v19.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
    v20.m128_u64[0] = 0x2B7AF89D708D00EFLL;
    v20.m128_u64[1] = 0x66DC2C40D04027CLL;
    v11 = _mm_xor_ps(v11, v17);
    v12 = _mm_xor_ps(v12, v18);
    v13 = _mm_xor_ps(v13, v19);
    v14 = _mm_xor_ps(v14, v20);                 // Failed to allocate pool for module mapping (%llX bytes)\n
    MainLogFunction(128, &unk_14016FCE0, &v11, v4);
LABEL_12:
    v6 = 0;
    if ( (v10 ^ v23) != _security_cookie )
      goto LABEL_8;
    return v6;
  }
  v6 = Pool;
  memset(Pool, 0, v4);
  memove(v6, a1, NtHeaders->OptionalHeader.SizeOfHeaders);
  if ( NtHeaders->FileHeader.NumberOfSections )
  {
    v7 = (&NtHeaders->OptionalHeader.BaseOfCode + NtHeaders->FileHeader.SizeOfOptionalHeader);
    index = 0;
    do
    {
      memove(&v6[*(v7 - 2)], a1 + *v7, *(v7 - 3));
      ++index;
      v7 += 10;
    }
    while ( index < NtHeaders->FileHeader.NumberOfSections );
  }
  RelocsFix(v6);
  if ( (v10 ^ v23) != _security_cookie )
LABEL_8:
    __debugbreak();
  return v6;
}

void KernelMemoryDump()
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  ContextRecord.ContextFlags = 1048587;
  RtlCaptureContext(&ContextRecord);
  PoolWithTag = ExAllocatePoolWithTag(NonPagedPool, 0x40000u, 0x53425458u);
  if ( PoolWithTag )
  {
    v1 = PoolWithTag;
    if ( KeCapturePersistentThreadState(&ContextRecord, 0, 0, 0, 0, 0, 0, PoolWithTag) >= 0x23E0 )
    {
      qword_14115DD60 = v1[1051];
      qword_14115DD68 = v1[1049];
      v2 = v1[1064];
      if ( v2 )
        qword_14115DE58 = *v2;
      v3 = v1[1074];
      if ( v3 )
        qword_14115DD80 = *v3;
      v4 = v1[1075];
      if ( v4 )
        qword_14115DD88 = *v4;
      v5 = v1[1076];
      if ( v5 )
        qword_14115DD90 = *v5;
      v6 = v1[1077];
      if ( v6 )
        qword_14115DD98 = *v6;
      if ( BuildNumber >= 1299 )
      {
        qword_14115DDA0 = v1[1114];
        qword_14115DD70 = v1[1108];
        qword_14115DD78 = v1[1109];
      }
    }
    ExFreePoolWithTag(v1, 0x53425458u);
  }
  if ( qword_14115DD60 )
  {
    if ( (v7 ^ v13) == _security_cookie )
      return;
LABEL_20:
    JUMPOUT(0x1411C911DLL);
  }
  v8.m128_u64[0] = 0xBD42965EE387F5A9uLL;
  v8.m128_u64[1] = 0x5AAC30D8975BCE64LL;
  v9.m128_u64[0] = 0x36A8E54D9C54DB7DLL;
  v9.m128_u64[1] = 0x1F8EE6A0E092C958LL;
  v11.m128_u64[0] = 0xDC16F237A0F786F9uLL;
  v11.m128_u64[1] = 0x7AD85FB6B73EA206LL;
  v12.m128_u64[0] = 0x36A8CB29F221B41BLL;
  v12.m128_u64[1] = 0x1F8EE6A0E092C958LL;
  v8 = _mm_xor_ps(v8, v11);
  v9 = _mm_xor_ps(v9, v12);                     // PsOCidTable not found.
  MainLogFunction(128, &unk_14016FCE0, &v8);
  if ( (v7 ^ v13) != _security_cookie )
    goto LABEL_20;
}

LONG __fastcall sub_1400627D0(__int64 a1)
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  v1 = *(a1 + 56);
  LowLimit = 0;
  HighLimit = 0;
  Pool = ExAllocatePool(NonPagedPool, 0x200u);
  if ( Pool )
  {
    v3 = Pool;
    v4 = sub_14006FA20(Pool, 32, 0);
    if ( v4 )
    {
      v5 = v4;
      IoGetStackLimits(&LowLimit, &HighLimit);
      InitialStack = IoGetInitialStack();
      v7 = 16LL * (v5 - 1);
      v8 = *&v3[v7];
      if ( v8 )
      {
        v9 = InitialStack;
        if ( !sub_140002FC0(v8) )
        {
          v10 = &v3[v7];
          v11 = *&v3[v7 + 8];
          if ( v11 < v9 )
          {
            v12 = *v10;
            while ( *v11 != v12 )
            {
              if ( ++v11 >= v9 )
                goto LABEL_12;
            }
            if ( sub_1400629C0(v12, &v20, &v19) )
            {
              PoolWithTag = ExAllocatePoolWithTag(NonPagedPool, NumberOfBytes, 0x53425458u);
              memove(PoolWithTag, GlobalContext, NumberOfBytes);
              v14 = v19;
              v15 = v20;
              v16 = *v10;
              v23.m128_u64[0] = 0x4F2FF68E755B8BFDLL;
              v23.m128_u64[1] = 0x54ADC06D65384EB4LL;
              v24.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
              v24.m128_u64[1] = 0x54D5E54D151D6EC4LL;
              v23 = _mm_xor_ps(v23, v24);       // bypass_hook_check: %p
              MainLogFunction(32, &unk_14016FCE0, &v23, v16, v20, v19);
              *PoolWithTag = *v10;
              *(PoolWithTag + 1) = v15;
              *(PoolWithTag + 2) = v14;
              *v11 = PoolWithTag + 120;
            }
          }
        }
      }
    }
LABEL_12:
    ExFreePoolWithTag(v3, 0);
  }
  result = KeSetEvent((v1 + 8), 0, 0);
  if ( (&v18 ^ v25) != _security_cookie )
    JUMPOUT(0x1400629BELL);
  return result;
}

__int64 __fastcall GetCriticalKernelFuncAddrAndSave(__int64 a1, unsigned __int64 a2)
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  v3 = *(a1 + 60);
  result = *(a1 + v3 + 6);
  if ( !*(a1 + v3 + 6) )
    goto LABEL_151;
  v70.m128_u64[0] = a2;
  v5 = a1 + v3;
  v6 = *(a1 + v3 + 20);
  v70.m128_u64[1] = v5;
  v7 = v5 + v6 + 24;
  v8 = 0;
  v9 = 2019914798;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v72 = 0;
  v71 = 0;
  do
  {
    switch ( *v7 )
    {
      case 0x45474150LL:
        v10 = *(v7 + 8);
        v8 = a1 + *(v7 + 12);
        v16 = *(v7 + 16);
        if ( v16 > v10 )
          v10 = v16;
        break;
      case 0x747865742ELL:
        v12 = *(v7 + 8);
        v11 = a1 + *(v7 + 12);
        v19 = *(v7 + 16);
        if ( v19 > v12 )
          v12 = v19;
        break;
      case 0x45444F435341564BLL:
        v15 = a1 + *(v7 + 12);
        break;
      case 0x54494E49LL:
        v14 = *(v7 + 8);
        v13 = a1 + *(v7 + 12);
        v20 = *(v7 + 16);
        if ( v20 > v14 )
          v14 = v20;
        break;
      case 0x5946525645474150LL:
        v17 = *(v7 + 8);
        v72 = a1 + *(v7 + 12);
        v18 = *(v7 + 16);
        if ( v18 > v17 )
          v17 = v18;
        v71 = v17;
        break;
    }
    v7 += 40;
    --result;
  }
  while ( result );
  if ( v13 )
  {
    LOBYTE(v7) = 14;
    result = sub_1400444A0(v7);
    if ( !result )
    {
      v78[0] = 0;
      if ( v15 )
      {
        *&v79[41] = *(&xmmword_1401E18C0 + 9);
        *&v79[32] = xmmword_1401E18C0;
        *&v79[16] = xmmword_1401E18B0;
        *v79 = xmmword_1401E18A0;
        LOBYTE(v9) = 42;
        if ( sub_14006EE30(v79, v9, 56, v13, v14, v78) < 0 )
          goto LABEL_31;
        v21 = *(v78[0] + 296);
        v22 = v78[0] - 48;
      }
      else
      {
        *&v79[25] = *(&xmmword_1401E1880 + 9);
        *&v79[16] = xmmword_1401E1880;
        *v79 = xmmword_1401E1870;
        LOBYTE(v9) = 42;
        if ( sub_14006EE30(v79, v9, 40, v13, v14, v78) < 0 )
          goto LABEL_31;
        v21 = *(v78[0] + 200);
        v22 = v78[0] - 32;
      }
      v23 = v21 - *(v70.m128_u64[1] + 48);
      if ( v22 )
      {
        if ( v23 <= v70.m128_u64[0] )
        {
          *v79 = a1;
          *&v79[8] = a1 + v70.m128_u64[0];
          *&v79[16] = 0;
          v47 = (a1 + v23);
          RegisterInterruptHook(0xEu, v47, v79, SomeConstantWrapper);
          result = ParseKiPageFault(v47, v79);
          if ( !v11 )
            goto LABEL_128;
          goto LABEL_34;
        }
        v83[0] = 0xBD469B7C8093E79BuLL;
        v83[1] = 0x25AC33C3D678C761LL;
        v84.m128_u64[0] = 0x36A8CB29F240C269LL;
        v84.m128_u64[1] = 0x1F8EE6A0E092C958LL;
        *v79 = 0xDC16F237A0F786F9uLL;
        *&v79[8] = 0x7AD85FB6B73EA206LL;
        *&v79[16] = 0x36A8CB29F221B41BLL;
        *&v79[24] = 0x1F8EE6A0E092C958LL;
        goto LABEL_32;
      }
LABEL_31:
      v83[0] = 0xAE649743CEBEEFB2uLL;
      v83[1] = 0x2EAC36D8FE4AD273LL;
      v84.m128_u64[0] = 0x42C7A509974DD67ALL;
      v84.m128_u64[1] = 0x1F8E82CE95FDAF78LL;
      *v79 = 0xDC16F237A0F786F9uLL;
      *&v79[8] = 0x7AD85FB6B73EA206LL;
      *&v79[16] = 0x36A8CB29F221B41BLL;
      *&v79[24] = 0x1F8EE6A0E092C958LL;
LABEL_32:
      *v83 = _mm_xor_ps(*v83, *v79);
      v84 = _mm_xor_ps(v84, *&v79[16]);
      result = MainLogFunction(128, &unk_14016FCE0, v83);
    }
  }
  if ( !v11 )
    goto LABEL_128;
LABEL_34:
  if ( v15 )
  {
    v83[0] = 0;
    *v79 = 0xF8010F2A2A2A2AE9uLL;
    *&v79[7] = 13584632;
    LOBYTE(v9) = 42;
    if ( sub_14006EE30(v79, v9, 10, v11, v12, v83) >= 0 )
      qword_14115DD00 = KernelStart + v83[0] - a1 + *(v83[0] + 1) + 5;
  }
  if ( dword_14115DA50 >= 0x47BA )
  {
    v83[0] = 0;
    *v79 = xmmword_1401E18F0;
    *&v79[15] = 10794;
    LOBYTE(v9) = 42;
    if ( sub_14006EE30(v79, v9, 18, v11, v12, v83) >= 0 )
      dword_14115DE20 = *(v83[0] + 2);
  }
  v24 = BuildNumber;
  if ( BuildNumber < 1536 )
  {
LABEL_85:
    result = (v24 - 1536);
    if ( result <= 0x11 )
    {
      v83[0] = 0xAE7F8746C3B6E3B2uLL;
      v83[1] = 0x29BC3AC3D24BF363LL;
      v84.m128_u64[0] = 0x36C3A846BE4FDD6BLL;
      v84.m128_u64[1] = 0x1F8EE6A0E092C958LL;
      v71 = a1;
      *v79 = 0xDC16F237A0F786F9uLL;
      *&v79[8] = 0x7AD85FB6B73EA206LL;
      *&v79[16] = 0x36A8CB29F221B41BLL;
      *&v79[24] = 0x1F8EE6A0E092C958LL;
      *v83 = _mm_xor_ps(*v83, *v79);
      v84 = _mm_xor_ps(v84, *&v79[16]);
      v72 = GetProcAddrCustom(KernelStart, v83);
      v83[0] = 0xAE7F8746C3B6E3B2uLL;
      v83[1] = 0x11BB3EC2E450EB63LL;
      v84.m128_u64[0] = 0x46FBAF4C8744C14ALL;
      v84.m128_u64[1] = 0x1F8E8DC38FDEA731LL;
      v70.m128_u64[1] = 0xDC16F237A0F786F9uLL;
      *v79 = 0xDC16F237A0F786F9uLL;
      v74 = 0x7AD85FB6B73EA206LL;
      *&v79[8] = 0x7AD85FB6B73EA206LL;
      v73 = 0x36A8CB29F221B41BLL;
      *&v79[16] = 0x36A8CB29F221B41BLL;
      v70.m128_u64[0] = 0x1F8EE6A0E092C958LL;
      *&v79[24] = 0x1F8EE6A0E092C958LL;
      *v83 = _mm_xor_ps(*v83, *v79);
      v84 = _mm_xor_ps(v84, *&v79[16]);
      v44 = GetProcAddrCustom(KernelStart, v83);
      *(v78 + 5) = 0xD8D482A2A2A2ALL;
      result = 0x2A2A2AE815EFC148LL;
      v78[0] = 0x2A2A2AE815EFC148LL;
      if ( v12 )
      {
        for ( i = 0; i < v12; i = (((*v79 - a1) << 32) + 0x1000000000LL) >> 32 )
        {
          *v79 = 0;
          LOBYTE(v43) = 42;
          result = sub_14006EE30(v78, v43, 12, v11 + i, v12 - i, v79);
          if ( result < 0 )
            break;
          v43 = *v79 - a1;
          v46 = KernelStart + v43 + *(KernelStart + v43 + 5) + 9;
          if ( v46 == v72 || v46 == v44 )
          {
            result = KernelStart + v43 + *(KernelStart + v43 + 12) + 16;
            qword_14115DDC0 = result;
            if ( result )
              goto LABEL_128;
            goto LABEL_93;
          }
          result = 0x1000000000LL;
        }
      }
      if ( !qword_14115DDC0 )
      {
LABEL_93:
        v83[0] = 0xBB77A259CFB9EFB4uLL;
        v83[1] = 0x139A33D9D86EC663LL;
        v84.m128_u64[0] = 0x42C7A5098240F96FLL;
        v84.m128_u64[1] = 0x1F8E82CE95FDAF78LL;
        *v79 = v70.m128_u64[1];
        *&v79[8] = v74;
        *&v79[16] = v73;
        *&v79[24] = v70.m128_u64[0];
        *v83 = _mm_xor_ps(*v83, *v79);
        v84 = _mm_xor_ps(v84, *&v79[16]);
        result = MainLogFunction(128, &unk_14016FCE0, v83);
      }
    }
    goto LABEL_128;
  }
  v81 = 0;
  *(v78 + 7) = 0xE82A8B482A2A2ALL;
  v78[0] = 0x2A2A850F00000FFFLL;
  LOBYTE(v9) = 42;
  if ( sub_14006EE30(v78, v9, 14, v11, v12, &v81) < 0 )
  {
LABEL_44:
    if ( qword_14115DE08 )
      goto LABEL_54;
    goto LABEL_47;
  }
  while ( GetInstructionLength((v81 + 10)) != 3 )
  {
    LOBYTE(v26) = 42;
    if ( sub_14006EE30(v78, v26, 14, v81 + 14, v12 + v11 - v81 - 14, &v81) < 0 )
      goto LABEL_44;
  }
  qword_14115DE08 = KernelStart + v81 + *(v81 + 14) - a1 + 18;
  KernelHook2(KernelStart + v81 - a1, 256, sub_1411C6660, 0);
  if ( !qword_14115DE08 )
  {
LABEL_47:
    v83[0] = 0x8B482A7500000FFFuLL;
    *(v83 + 7) = 15256459;
    ImageBase = 0;
    LOBYTE(v25) = 42;
    if ( sub_14006EE30(v83, v25, 10, v72, v71, &ImageBase) >= 0 && GetInstructionLength((ImageBase + 6)) == 3 )
    {
      qword_14115DE08 = KernelStart + ImageBase + *(ImageBase + 10) - a1 + 14;
      v76 = 0;
      *v79 = xmmword_1401E1920;
      *&v79[16] = 228;
      LOBYTE(v25) = 42;
      if ( sub_14006EE30(v79, v25, 17, v11, v12, &v76) >= 0 && *(v76 + 32) == 40543 )
        KernelHook2(KernelStart + v76 - a1, 256, sub_1411C6660, 0);
    }
    if ( !qword_14115DE08 )
    {
      v83[0] = 0xB1649743C5B3EBB4uLL;
      v83[1] = 0x2EB430D9E75BCC6FLL;
      v84.m128_u64[0] = 0x16DCA447D244C462LL;
      v84.m128_u64[1] = 0x1F8EE6C48EE7A63ELL;
      *v79 = 0xDC16F237A0F786F9uLL;
      *&v79[8] = 0x7AD85FB6B73EA206LL;
      *&v79[16] = 0x36A8CB29F221B41BLL;
      *&v79[24] = 0x1F8EE6A0E092C958LL;
      *v83 = _mm_xor_ps(*v83, *v79);
      v84 = _mm_xor_ps(v84, *&v79[16]);
      MainLogFunction(128, &unk_14016FCE0, v83);
    }
  }
LABEL_54:
  v24 = BuildNumber;
  if ( BuildNumber < 1536 )
    goto LABEL_85;
  v81 = 0;
  *(v78 + 5) = 0x18B482A2A2A2ALL;
  v78[0] = 0x2A2A2A850F07C2F6LL;
  LOBYTE(v25) = 42;
  if ( sub_14006EE30(v78, v25, 12, v11, v12, &v81) < 0 )
  {
    *v79 = 0x18B482A7507C2F6LL;
    v79[8] = 0;
    LOBYTE(v27) = 42;
    if ( sub_14006EE30(v79, v27, 8, v11, v12, &v81) < 0 )
    {
      v83[0] = 0xAE50817ED09BF2ABuLL;
      v83[1] = 0xFB71DD8FE5BCF67LL;
      v84.m128_u64[0] = 0x57D8EB51B752D075LL;
      v84.m128_u64[1] = 0x70E0C6CE92F7BD2CLL;
      v85.m128_u64[0] = 0xED318F8EDCF744D9uLL;
      v85.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
      *v79 = 0xDC16F237A0F786F9uLL;
      *&v79[8] = 0x7AD85FB6B73EA206LL;
      *&v79[16] = 0x36A8CB29F221B41BLL;
      *&v79[24] = 0x1F8EE6A0E092C958LL;
      *&v79[32] = 0xED55E1FBB39164ADuLL;
      *&v79[40] = 0xD12C83EA13AA49CAuLL;
      *v83 = _mm_xor_ps(*v83, *v79);
      v84 = _mm_xor_ps(v84, *&v79[16]);
      v85 = _mm_xor_ps(v85, *&v79[32]);
      MainLogFunction(128, &unk_14016FCE0, v83);
    }
  }
  if ( v81 )
  {
    v28 = RtlLookupFunctionEntry(KernelStart + (v81 - a1), &ImageBase, 0);
    if ( v28 )
    {
      qword_14115DC68 = ImageBase + v28->BeginAddress;
      if ( qword_14115DC68 )
        goto LABEL_62;
      goto LABEL_61;
    }
    if ( !qword_14115DC68 )
    {
LABEL_61:
      v83[0] = 0xAE50817ED09BF2ABuLL;
      v83[1] = 0xFB71DD8FE5BCF67LL;
      v84.m128_u64[0] = 0x59C6EB51B752D075LL;
      v84.m128_u64[1] = 0x1FEA88D58FF4E92CLL;
      *v79 = 0xDC16F237A0F786F9uLL;
      *&v79[8] = 0x7AD85FB6B73EA206LL;
      *&v79[16] = 0x36A8CB29F221B41BLL;
      *&v79[24] = 0x1F8EE6A0E092C958LL;
      *v83 = _mm_xor_ps(*v83, *v79);
      v84 = _mm_xor_ps(v84, *&v79[16]);
      MainLogFunction(128, &unk_14016FCE0, v83);
    }
  }
LABEL_62:
  v24 = BuildNumber;
  if ( BuildNumber < 1568 )
    goto LABEL_85;
  ImageBase = 0;
  v81 = 0x3B482A2AF82A3B48LL;
  v82 = 0;
  LOBYTE(v27) = 42;
  if ( sub_14006EE30(&v81, v27, 8, v11, v12, &ImageBase) < 0 )
  {
    *(v78 + 7) = 0xCE0C148FFFFF6LL;
    v78[0] = 0xF6FB40000000B948uLL;
    ImageBase = 0;
    LOBYTE(v29) = 42;
    result = sub_14006EE30(v78, v29, 14, v11, v12, &ImageBase);
    if ( result < 0 )
      goto LABEL_126;
    result = RtlLookupFunctionEntry(KernelStart + (ImageBase - a1), &v76, 0);
    if ( result )
    {
      v48 = v76 + *result;
      if ( v48 )
      {
        *&v79[48] = 0;
        v49 = AllocateMemoryWrapper(40);
        *v49 = v49;
        v49[1] = v49;
        v49[2] = v49;
        *(v49 + 12) = 257;
        *&v79[40] = v49;
        *&v79[56] = 0;
        v80 = 0;
        *&v79[24] = &KernelStart;
        v50 = AllocateMemoryWrapper(16);
        v50[1] = 0;
        v51 = AllocateMemoryWrapper(40);
        *v51 = v51;
        v51[1] = v51;
        v51[2] = v51;
        *(v51 + 12) = 257;
        *v50 = v51;
        *&v79[32] = v50;
        *&v79[8] = 200;
        *&v79[16] = 32;
        *v79 = v48;
        LODWORD(v83[0]) = 0;
        v75 = 256;
        std::vector(&v79[56], 0, v79, &v75, v83);
        v52 = *&v79[64];
        for ( j = *&v79[56]; *&v79[64] != *&v79[56]; j = *&v79[56] )
        {
          v54 = *(v52 - 24);
          v55 = *(v52 - 16);
          v56 = *(v52 - 8);
          *&v79[64] = v52 - 24;
          KernelHook(v54, v55, sub_140018590, v79, v56);
          v52 = *&v79[64];
        }
        v57 = *&v79[32];
        if ( *&v79[32] )
        {
          v58 = **&v79[32];
          if ( !*(*(**&v79[32] + 8LL) + 25LL) )
          {
            sub_1400193B0(*(**&v79[32] + 8LL), *&v79[32], *&v79[32]);
            v58 = *v57;
          }
          FreeWrapper(v58, 40);
          FreeWrapper(v57, 16);
          j = *&v79[56];
        }
        if ( j )
        {
          v59 = v80 - j;
          if ( (v80 - j) >= 0x1000 )
          {
            if ( (j - 8 - *(j - 8)) >= 0x20 )
              goto LABEL_153;
            v59 += 39;
            j = *(j - 8);
          }
          FreeWrapper(j, v59);
          *&v79[56] = 0;
          v80 = 0;
        }
        v60 = *&v79[40];
        if ( !*(*(*&v79[40] + 8LL) + 25LL) )
        {
          sub_1400193B0(*(*&v79[40] + 8LL), &v79[40], &v79[40]);
          v60 = *&v79[40];
        }
        result = FreeWrapper(v60, 40);
      }
    }
    if ( !qword_14115DDD0 )
    {
      v83[0] = 0xBB77A259CFB9EFB4uLL;
      v83[1] = 0x1B9A33D9D86EC663LL;
      v84.m128_u64[0] = 0x5088BF469C01D168LL;
      v84.m128_u64[1] = 0x1F8EE6A084FCBC37LL;
      *v79 = 0xDC16F237A0F786F9uLL;
      *&v79[8] = 0x7AD85FB6B73EA206LL;
      *&v79[16] = 0x36A8CB29F221B41BLL;
      *&v79[24] = 0x1F8EE6A0E092C958LL;
      *v83 = _mm_xor_ps(*v83, *v79);
      v84 = _mm_xor_ps(v84, *&v79[16]);
      result = MainLogFunction(128, &unk_14016FCE0, v83);
    }
    if ( qword_14115DDD8 )
      goto LABEL_126;
    v83[0] = 0xBB77A259CFB9EFB4uLL;
    v83[1] = 0x1B9533D9D86EC663LL;
    v84.m128_u64[0] = 0x5888B34C964FFD63LL;
    v84.m128_u64[1] = 0x7BE093CF86B2BD37LL;
    v85.m128_u64[0] = 0xED55E1FBB39164ADuLL;
    v85.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
    *v79 = 0xDC16F237A0F786F9uLL;
    *&v79[8] = 0x7AD85FB6B73EA206LL;
    *&v79[16] = 0x36A8CB29F221B41BLL;
    *&v79[24] = 0x1F8EE6A0E092C958LL;
    *&v79[32] = 0xED55E1FBB39164ADuLL;
    *&v79[40] = 0xD12C83EA13AA49CAuLL;
    *v83 = _mm_xor_ps(*v83, *v79);
    v84 = _mm_xor_ps(v84, *&v79[16]);
    v85 = _mm_xor_ps(v85, *&v79[32]);
    goto LABEL_125;
  }
  result = RtlLookupFunctionEntry(KernelStart + (ImageBase - a1), v78, 0);
  if ( !result )
    goto LABEL_80;
  v30 = v78[0] + *result;
  if ( !v30 )
    goto LABEL_80;
  *&v79[48] = 0;
  v31 = AllocateMemoryWrapper(40);
  *v31 = v31;
  v31[1] = v31;
  v31[2] = v31;
  *(v31 + 12) = 257;
  *&v79[40] = v31;
  *&v79[56] = 0;
  v80 = 0;
  *&v79[24] = &KernelStart;
  v32 = AllocateMemoryWrapper(16);
  v32[1] = 0;
  v33 = AllocateMemoryWrapper(40);
  *v33 = v33;
  v33[1] = v33;
  v33[2] = v33;
  *(v33 + 12) = 257;
  *v32 = v33;
  *&v79[32] = v32;
  *&v79[8] = 200;
  *&v79[16] = 32;
  *v79 = v30;
  LODWORD(v83[0]) = 0;
  LODWORD(v76) = 256;
  std::vector(&v79[56], 0, v79, &v76, v83);
  v34 = *&v79[64];
  for ( k = *&v79[56]; *&v79[64] != *&v79[56]; k = *&v79[56] )
  {
    v36 = *(v34 - 24);
    v37 = *(v34 - 16);
    v38 = *(v34 - 8);
    *&v79[64] = v34 - 24;
    KernelHook(v36, v37, sub_140018230, v79, v38);
    v34 = *&v79[64];
  }
  v39 = *&v79[32];
  if ( *&v79[32] )
  {
    v40 = **&v79[32];
    if ( !*(*(**&v79[32] + 8LL) + 25LL) )
    {
      sub_1400193B0(*(**&v79[32] + 8LL), *&v79[32], *&v79[32]);
      v40 = *v39;
    }
    FreeWrapper(v40, 40);
    FreeWrapper(v39, 16);
    k = *&v79[56];
  }
  if ( k )
  {
    v41 = v80 - k;
    if ( (v80 - k) < 0x1000 )
    {
LABEL_76:
      FreeWrapper(k, v41);
      *&v79[56] = 0;
      v80 = 0;
      goto LABEL_77;
    }
    if ( (k - 8 - *(k - 8)) < 0x20 )
    {
      v41 += 39;
      k = *(k - 8);
      goto LABEL_76;
    }
LABEL_153:
    KeBugCheckWrapper();
  }
LABEL_77:
  v42 = *&v79[40];
  if ( !*(*(*&v79[40] + 8LL) + 25LL) )
  {
    sub_1400193B0(*(*&v79[40] + 8LL), &v79[40], &v79[40]);
    v42 = *&v79[40];
  }
  result = FreeWrapper(v42, 40);
LABEL_80:
  if ( qword_14115DDB0 )
  {
    if ( dword_14115DDB8 )
      goto LABEL_82;
  }
  else
  {
    v83[0] = 0xB25F9753CFB9EFB4uLL;
    v83[1] = 0x15B12BD7DA4CCD60LL;
    v84.m128_u64[0] = 0x59CEEB5D9D4F9475LL;
    v84.m128_u64[1] = 0x1F8EE6A0E0F6A72DLL;
    *v79 = 0xDC16F237A0F786F9uLL;
    *&v79[8] = 0x7AD85FB6B73EA206LL;
    *&v79[16] = 0x36A8CB29F221B41BLL;
    *&v79[24] = 0x1F8EE6A0E092C958LL;
    *v83 = _mm_xor_ps(*v83, *v79);
    v84 = _mm_xor_ps(v84, *&v79[16]);
    result = MainLogFunction(128, &unk_14016FCE0, v83);
    if ( dword_14115DDB8 )
    {
LABEL_82:
      if ( dword_14115DDBC )
        goto LABEL_83;
LABEL_123:
      v83[0] = 0xB25F9753CFB9EFB4uLL;
      v83[1] = 0x15B12BD7DA4CCD60LL;
      v84.m128_u64[0] = 0x69DCB840BE72EB75LL;
      v84.m128_u64[1] = 0x6BE1888085E8A02BLL;
      v85.m128_u64[0] = 0xED558595C6FE028DuLL;
      v85.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
      *v79 = 0xDC16F237A0F786F9uLL;
      *&v79[8] = 0x7AD85FB6B73EA206LL;
      *&v79[16] = 0x36A8CB29F221B41BLL;
      *&v79[24] = 0x1F8EE6A0E092C958LL;
      *&v79[32] = 0xED55E1FBB39164ADuLL;
      *&v79[40] = 0xD12C83EA13AA49CAuLL;
      *v83 = _mm_xor_ps(*v83, *v79);
      v84 = _mm_xor_ps(v84, *&v79[16]);
      v85 = _mm_xor_ps(v85, *&v79[32]);
      result = MainLogFunction(128, &unk_14016FCE0, v83);
      if ( qword_14115DDA8 )
        goto LABEL_126;
      goto LABEL_124;
    }
  }
  v83[0] = 0xB25F9753CFB9EFB4uLL;
  v83[1] = 0x15B12BD7DA4CCD60LL;
  v84.m128_u64[0] = 0x69DCB840BE72EB75LL;
  v84.m128_u64[1] = 0x71AE92C593F4AF37LL;
  v85.m128_u64[0] = 0x893B9494D5B110C2uLL;
  v85.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
  *v79 = 0xDC16F237A0F786F9uLL;
  *&v79[8] = 0x7AD85FB6B73EA206LL;
  *&v79[16] = 0x36A8CB29F221B41BLL;
  *&v79[24] = 0x1F8EE6A0E092C958LL;
  *&v79[32] = 0xED55E1FBB39164ADuLL;
  *&v79[40] = 0xD12C83EA13AA49CAuLL;
  *v83 = _mm_xor_ps(*v83, *v79);
  v84 = _mm_xor_ps(v84, *&v79[16]);
  v85 = _mm_xor_ps(v85, *&v79[32]);
  result = MainLogFunction(128, &unk_14016FCE0, v83);
  if ( !dword_14115DDBC )
    goto LABEL_123;
LABEL_83:
  if ( qword_14115DDA8 )
    goto LABEL_126;
LABEL_124:
  v83[0] = 0xAE73905AD5B9E3B2uLL;
  v83[1] = 0x15B67FC5D25ACD48LL;
  v84.m128_u64[0] = 0x36CCA55C9D47946FLL;
  v84.m128_u64[1] = 0x1F8EE6A0E092C958LL;
  *v79 = 0xDC16F237A0F786F9uLL;
  *&v79[8] = 0x7AD85FB6B73EA206LL;
  *&v79[16] = 0x36A8CB29F221B41BLL;
  *&v79[24] = 0x1F8EE6A0E092C958LL;
  *v83 = _mm_xor_ps(*v83, *v79);
  v84 = _mm_xor_ps(v84, *&v79[16]);
LABEL_125:
  result = MainLogFunction(128, &unk_14016FCE0, v83);
LABEL_126:
  if ( !qword_14115DDA8 )
  {
    v83[0] = 0xAE468052D3A2EBB4uLL;
    v83[1] = 0x1FAA3BD2F65BC069LL;
    v84.m128_u64[0] = 0x36A8CB29F221C768LL;
    v84.m128_u64[1] = 0x1F8EE6A0E092C958LL;
    *v79 = 0xDC16F237A0F786F9uLL;
    *&v79[8] = 0x7AD85FB6B73EA206LL;
    *&v79[16] = 0x36A8CB29F221B41BLL;
    *&v79[24] = 0x1F8EE6A0E092C958LL;
    *v83 = _mm_xor_ps(*v83, *v79);
    v84 = _mm_xor_ps(v84, *&v79[16]);
    result = GetProcAddrCustom(KernelStart, v83) + 8;
    qword_14115DDA8 = result;
  }
LABEL_128:
  if ( v8 )
  {
    v81 = 0;
    if ( BuildNumber >= 1536 )
    {
      v83[0] = 0xB273B544E99BF2ABuLL;
      v83[1] = 0x16BA3EE2D457D063LL;
      v84.m128_u64[0] = 0x40E9B25D824CF17ELL;
      v84.m128_u64[1] = 0x1F8EE6A0E092C934LL;
      v72 = 0xDC16F237A0F786F9uLL;
      *v79 = 0xDC16F237A0F786F9uLL;
      v71 = 0x7AD85FB6B73EA206LL;
      *&v79[8] = 0x7AD85FB6B73EA206LL;
      v70.m128_u64[0] = 0x36A8CB29F221B41BLL;
      *&v79[16] = 0x36A8CB29F221B41BLL;
      v70.m128_u64[1] = 0x1F8EE6A0E092C958LL;
      *&v79[24] = 0x1F8EE6A0E092C958LL;
      *v83 = _mm_xor_ps(*v83, *v79);
      v84 = _mm_xor_ps(v84, *&v79[16]);
      v62 = GetProcAddrCustom(KernelStart, v83);
      result = 0xC0842A2A2A2AE8LL;
      v78[0] = 0xC0842A2A2A2AE8LL;
      if ( v10 )
      {
        for ( m = 0; m < v10; m = v64 - v8 + 7 )
        {
          LOBYTE(v61) = 42;
          result = sub_14006EE30(v78, v61, 7, v8 + m, v10 - m, &v81);
          if ( result < 0 )
            break;
          v64 = v81;
          v61 = KernelStart;
          v65 = KernelStart + v81 - a1;
          result = &v65[*(v65 + 1) + 5];
          if ( result == v62 )
          {
            result = RtlLookupFunctionEntry(v65, v83, 0);
            if ( result )
            {
              v66 = (v83[0] + *result);
              if ( v66 )
              {
                v79[0] = 0;
                *&v79[8] = 0;
                KernelHook2(v66, 256, sub_140018880, v79);
                result = *&v79[8];
                if ( (v79[0] & (*&v79[8] != 0)) == 1 )
                  Table = *&v79[8];
              }
            }
            if ( Table )
              goto LABEL_142;
          }
        }
      }
      if ( !Table )
      {
        v83[0] = 0xBF77B175E4B3EFA9uLL;
        v83[1] = 0x5ABD33D4D66AC76ELL;
        v84.m128_u64[0] = 0x58DDA44FD255DB75LL;
        v84.m128_u64[1] = 0x1F8EE6A0E092C93CLL;
        *v79 = v72;
        *&v79[8] = v71;
        *&v79[16] = v70;
        *v83 = _mm_xor_ps(*v83, *v79);
        v84 = _mm_xor_ps(v84, v70);
        result = MainLogFunction(128, &unk_14016FCE0, v83);
      }
LABEL_142:
      if ( BuildNumber >= 1536 )
      {
        *v78 = xmmword_1401E1970;
        *(&v78[1] + 7) = 0xE810C18348402ALL;
        LOBYTE(v61) = 42;
        if ( sub_14006EE30(v78, v61, 22, v8, v10, &v81) < 0 )
        {
          v83[0] = 0xB9609D5AC5A5E3B2uLL;
          v83[1] = 0x19A81ED3C25BD757LL;
          v84.m128_u64[0] = 0x58DAAE5D8640C43BLL;
          v84.m128_u64[1] = 0x6AE1808094FDA778LL;
          v85.m128_u64[0] = 0xED55E1FBB39100C3uLL;
          v85.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
          *v79 = v72;
          *&v79[8] = v71;
          *&v79[16] = v70;
          *&v79[32] = 0xED55E1FBB39164ADuLL;
          *&v79[40] = 0xD12C83EA13AA49CAuLL;
          *v83 = _mm_xor_ps(*v83, *v79);
          v84 = _mm_xor_ps(v84, v70);
          v85 = _mm_xor_ps(v85, *&v79[32]);
          MainLogFunction(128, &unk_14016FCE0, v83);
        }
        result = v81;
        if ( v81 )
        {
          result = v81 - a1;
          if ( *(KernelStart + v81 - a1 - 5) == -24 )
          {
            v67 = KernelStart + result + *(KernelStart + result - 4);
            v83[0] = 0xB960B743C5A4E3B2uLL;
            v83[1] = 0x7AD85FB6B73ED668LL;
            *v79 = v72;
            *&v79[8] = v71;
            *v83 = _mm_xor_ps(*v83, *v79);
            if ( v67 == GetProcAddrCustom(KernelStart, v83) )
            {
              v68 = KernelStart + v81 - a1 + *(KernelStart + v81 - a1 + 22) + 26;
              result = sub_14001A470(v68, &KernelStart);
              if ( result )
                qword_14115DCF0 = v68;
            }
            else
            {
              v83[0] = 0xFC2BD317CC9BE79AuLL;
              v83[1] = 0x1FAE1AC2D26DC74DLL;
              v84.m128_u64[0] = 0x36A8CB29F221C075LL;
              v84.m128_u64[1] = v70.m128_u64[1];
              *v79 = v72;
              *&v79[8] = v71;
              *&v79[16] = v70;
              *v83 = _mm_xor_ps(*v83, *v79);
              v84 = _mm_xor_ps(v84, v70);
              result = MainLogFunction(128, &unk_14016FCE0, v83);
            }
          }
        }
      }
    }
  }
LABEL_151:
  if ( (&v69 ^ v86) != _security_cookie )
    __debugbreak();
  return result;
}

__int64 VerifyShadowTable()
{
  __int64 result; // rax
  _BYTE v1[32]; // [rsp+0h] [rbp-68h] BYREF
  __m128 v2; // [rsp+20h] [rbp-48h] BYREF
  __m128 v3; // [rsp+30h] [rbp-38h]
  __m128 v4; // [rsp+40h] [rbp-28h]
  __m128 v5; // [rsp+50h] [rbp-18h]
  __int64 v6; // [rsp+60h] [rbp-8h]

  if ( BuildNumber < 1536 || (result = ReadKernelFromDisk(GetCriticalKernelFuncAddrAndSave, 0), qword_14115DCF0) )
  {
    if ( (v1 ^ v6) == _security_cookie )
      return result;
LABEL_6:
    __debugbreak();
  }
  v2.m128_u64[0] = 0xB9609D5AC5A5E3B2uLL;
  v2.m128_u64[1] = 0x19A81ED3C25BD757LL;
  v3.m128_u64[0] = 0x43C7AD09864EDA3BLL;
  v3.m128_u64[1] = 0x1F8EE6A0E092AD36LL;
  v4.m128_u64[0] = 0xDC16F237A0F786F9uLL;
  v4.m128_u64[1] = 0x7AD85FB6B73EA206LL;
  v5.m128_u64[0] = 0x36A8CB29F221B41BLL;
  v5.m128_u64[1] = 0x1F8EE6A0E092C958LL;
  v2 = _mm_xor_ps(v2, v4);
  v3 = _mm_xor_ps(v3, v5);                      // no m_ShadowSystemCallTable
  result = MainLogFunction(128, &unk_14016FCE0, &v2);
  if ( (v1 ^ v6) != _security_cookie )
    goto LABEL_6;
  return result;
}

unsigned __int64 __fastcall FindSomeFuncsAddrs(void *a1)
{
  int v1; // esi
  PIMAGE_NT_HEADERS v2; // rax
  PIMAGE_NT_HEADERS v3; // rcx
  unsigned __int64 result; // rax
  __int64 NumberOfSymbols; // rax
  unsigned int TimeDateStamp; // edx
  DWORD PointerToSymbolTable; // ecx
  _BYTE v8[32]; // [rsp+0h] [rbp-A8h] BYREF
  __m128 v9; // [rsp+30h] [rbp-78h] BYREF
  __m128 v10; // [rsp+40h] [rbp-68h]
  __m128 v11; // [rsp+50h] [rbp-58h]
  __m128 v12; // [rsp+60h] [rbp-48h] BYREF
  __m128 v13; // [rsp+70h] [rbp-38h]
  __m128 v14; // [rsp+80h] [rbp-28h]
  __int64 v15; // [rsp+98h] [rbp-10h]

  v1 = a1;
  v2 = RtlImageNtHeader(a1);
  v3 = v2 + 1;
  result = &v2[1] + 40 * v2->FileHeader.NumberOfSections;
  if ( v3 < result )
  {
    while ( v3->Signature ^ 0x7865742E | LOBYTE(v3->FileHeader.Machine) ^ 0x74 )
    {
      v3 = (v3 + 40);
      if ( v3 >= result )
        goto LABEL_9;
    }
    v9.m128_u64[0] = 0;
    v12 = xmmword_1401E1990;
    NumberOfSymbols = v3->FileHeader.NumberOfSymbols;
    TimeDateStamp = v3->FileHeader.TimeDateStamp;
    PointerToSymbolTable = v3->FileHeader.PointerToSymbolTable;
    if ( TimeDateStamp < NumberOfSymbols )
      NumberOfSymbols = TimeDateStamp;
    LOBYTE(TimeDateStamp) = -52;
    result = sub_14006EE30(&v12, TimeDateStamp, 15, PointerToSymbolTable + v1, NumberOfSymbols, &v9);
    if ( (result & 0x80000000) == 0LL )
    {
      KiWaitNever = v9.m128_u64[0] + *(v9.m128_u64[0] + 3) + 7;
      result = *(v9.m128_u64[0] + 10) + v9.m128_u64[0] + 14;
      KiWaitAlways = result;
    }
  }
LABEL_9:
  if ( KiWaitNever )
  {
    if ( KiWaitAlways )
      goto LABEL_11;
  }
  else
  {
    v9.m128_u64[0] = 0xB9459F52D484FFAAuLL;
    v9.m128_u64[1] = 0x9BD1BD3D457D474LL;
    v10.m128_u64[0] = 0x5888AE459040E078LL;
    v10.m128_u64[1] = 0x7BE093CF86B2BD37LL;
    v11.m128_u64[0] = 0xED55E1FBB39164ADuLL;
    v11.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
    v12.m128_u64[0] = 0xDC16F237A0F786F9uLL;
    v12.m128_u64[1] = 0x7AD85FB6B73EA206LL;
    v13.m128_u64[0] = 0x36A8CB29F221B41BLL;
    v13.m128_u64[1] = 0x1F8EE6A0E092C958LL;
    v14.m128_u64[0] = 0xED55E1FBB39164ADuLL;
    v14.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
    v9 = _mm_xor_ps(v9, v12);
    v10 = _mm_xor_ps(v10, v13);
    v11 = _mm_xor_ps(v11, v14);                 // KiWaitNever not found\n
    result = MainLogFunction(128, &unk_14016FCE0, &v9);
    if ( KiWaitAlways )
    {
LABEL_11:
      if ( (v8 ^ v15) == _security_cookie )
        return result;
LABEL_15:
      __debugbreak();
    }
  }
  v9.m128_u64[0] = 0xB9459F52D484FFAAuLL;
  v9.m128_u64[1] = 0x9BD1BD3D457D474LL;
  v10.m128_u64[0] = 0x5EFBAE459040E078LL;
  v10.m128_u64[1] = 0x6BE1888097FDAD39LL;
  v11.m128_u64[0] = 0xED558595C6FE028DuLL;
  v11.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
  v12.m128_u64[0] = 0xDC16F237A0F786F9uLL;
  v12.m128_u64[1] = 0x7AD85FB6B73EA206LL;
  v13.m128_u64[0] = 0x36A8CB29F221B41BLL;
  v13.m128_u64[1] = 0x1F8EE6A0E092C958LL;
  v14.m128_u64[0] = 0xED55E1FBB39164ADuLL;
  v14.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
  v9 = _mm_xor_ps(v9, v12);
  v10 = _mm_xor_ps(v10, v13);
  v11 = _mm_xor_ps(v11, v14);                   // KiWaitAlways not found\n
  result = MainLogFunction(128, &unk_14016FCE0, &v9);
  if ( (v8 ^ v15) != _security_cookie )
    goto LABEL_15;
  return result;
}

__int64 __fastcall CheckDriversWrapper(__int64 a1, _QWORD *a2, _QWORD *a3)
{
  __int64 result; // rax
  _BYTE v6[40]; // [rsp+0h] [rbp-58h] BYREF
  __int64 v7; // [rsp+28h] [rbp-30h] BYREF
  __int64 v8; // [rsp+30h] [rbp-28h]
  unsigned int v9; // [rsp+38h] [rbp-20h]
  __int64 v10; // [rsp+40h] [rbp-18h]

  v7 = a1;
  v8 = 0;
  v9 = 0;
  CheckForAllDriversInSystem(sub_14006F2D0, &v7);
  if ( !v8 )
  {
    result = 3221226021LL;
    if ( (v6 ^ v10) == _security_cookie )
      return result;
LABEL_9:
    JUMPOUT(0x14006F3A5LL);
  }
  if ( a2 )
    *a2 = v8;
  result = 0;
  if ( a3 )
    *a3 = v9;
  if ( (v6 ^ v10) != _security_cookie )
    goto LABEL_9;
  return result;
}

__int64 __fastcall CheckForAllDriversInSystem(unsigned __int8 (__fastcall *a1)(_DWORD *, __int64), __int64 ModuleName)
{
  ULONG i; // ebp
  _DWORD *PoolWithTag; // rax
  _DWORD *v6; // r14
  NTSTATUS SystemInformation; // ebx
  _DWORD *v8; // r15
  unsigned __int64 index; // r12

  for ( i = 262144; ; i += 262144 )
  {
    PoolWithTag = ExAllocatePoolWithTag(PagedPool, i, 0x53425458u);
    if ( !PoolWithTag )
      return STATUS_INSUFFICIENT_RESOURCES;
    v6 = PoolWithTag;
    SystemInformation = ZwQuerySystemInformation(SystemModuleInformation, PoolWithTag, i, 0);
    if ( SystemInformation >= 0 )
      break;
    ExFreePoolWithTag(v6, 0x53425458u);
    if ( SystemInformation != STATUS_INFO_LENGTH_MISMATCH )
      return SystemInformation;
  }
  if ( *v6 )
  {
    v8 = v6 + 2;
    index = 0;
    while ( !a1(v8, ModuleName) )
    {
      ++index;
      v8 += 'J';
      if ( index >= *v6 )
        goto LABEL_13;
    }
    SystemInformation = 0;
  }
LABEL_13:
  ExFreePoolWithTag(v6, 0x53425458u);
  return SystemInformation;
}

