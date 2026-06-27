__m128 *__fastcall CopyAndMapImage(char *BaseAddress, SIZE_T Size)
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  Pool = ExAllocatePool(NonPagedPool, Size);
  if ( !Pool )
  {
    v14.m128_u64[0] = 0xB8779D5BC5A5E3B2uLL;
    v14.m128_u64[1] = 0x3CA12DD7C55CCB4ALL;
    v15.m128_u64[0] = 0x44C7A64CBF4CDB69LL;
    v15.m128_u64[1] = 0x7BEB8AC981F4E921LL;
    v16.m128_u64[0] = 0x82398D9A93FE108DuLL;
    v16.m128_u64[1] = 0xF154A6CA76DE28A9uLL;
    v17.m128_u64[0] = 0x2B7AD6EE15F9798DLL;
    v17.m128_u64[1] = 0x66DC2C40D04027CLL;
    v18.m128_u64[0] = 0xDC16F237A0F786F9uLL;
    v18.m128_u64[1] = 0x7AD85FB6B73EA206LL;
    v19.m128_u64[0] = 0x36A8CB29F221B41BLL;
    v19.m128_u64[1] = 0x1F8EE6A0E092C958LL;
    v20.m128_u64[0] = 0xED55E1FBB39164ADuLL;
    v20.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
    v21.m128_u64[0] = 0x2B7AF89D708D00EFLL;
    v21.m128_u64[1] = 0x66DC2C40D04027CLL;
    v14 = _mm_xor_ps(v14, v18);
    v15 = _mm_xor_ps(v15, v19);
    v16 = _mm_xor_ps(v16, v20);
    v17 = _mm_xor_ps(v17, v21);                 // Failed to allocate memory for Image Copy: %llX\n
    MainLogFunction(128, &unk_14016FCE0, &v14, Size);
  }
  memset(Pool, 0, Size);
  v5 = RtlImageNtHeader(BaseAddress);
  if ( v5 )
  {
    NtHeaders = v5;
    NumberOfSections = v5->FileHeader.NumberOfSections;
    if ( NumberOfSections )
    {
      Section = (&NtHeaders->OptionalHeader.SizeOfInitializedData + NtHeaders->FileHeader.SizeOfOptionalHeader);
      for ( i = 0; i < NumberOfSections; ++i )
      {
        if ( (Section[7] & 0x80000000) == 0 && *(Section - 2) != 'TINI' )// 0x80000000 - NtHeaders.FileHeader.Characteristics
        {
          v10 = *Section;
          v11 = Section[1];
          v18.m128_i32[0] = 0;
          CopyMemory(Pool + v11, &BaseAddress[v11], v10, &v18);
          NumberOfSections = NtHeaders->FileHeader.NumberOfSections;
        }
        Section += 10;
      }
    }
  }
  if ( (&v13 ^ v22) != _security_cookie )
    JUMPOUT(0x1411FE051LL);
  return Pool;
}

__int64 __fastcall CopyMemory(char *Pool, unsigned __int64 BaseAddress, size_t a3, size_t *a4)
{
  __int64 result; // rax
  size_t v6; // rsi
  char *v9; // rdi
  __int64 (__fastcall *MmCopyMemory)(char *, unsigned __int64, size_t, __int64, size_t *); // rax
  int v11; // eax
  size_t v12; // rbx
  bool v13; // cf
  _BYTE v14[32]; // [rsp+0h] [rbp-78h] BYREF
  size_t v15; // [rsp+28h] [rbp-50h] BYREF
  struct _UNICODE_STRING DestinationString; // [rsp+30h] [rbp-48h] BYREF
  __int64 v17; // [rsp+40h] [rbp-38h]

  result = 0xC000000DLL;
  if ( Pool == 0 || BaseAddress == 0 || a3 == 0 || (result = 0xC0000184LL, (KeGetCurrentIrql() & 0xFE) != 0) )
  {
LABEL_16:
    if ( (v14 ^ v17) == _security_cookie )
      return result;
LABEL_19:
    __debugbreak();
  }
  v6 = 4096 - (BaseAddress & 0xFFF);
  if ( a3 < v6 )
    v6 = a3;
  if ( BaseAddress <= MmHighestUserAddress )
  {
    v12 = 0;
    goto LABEL_10;
  }
  v9 = Pool;
  RtlInitUnicodeString(&DestinationString, L"MmCopyMemory");
  MmCopyMemory = MmGetSystemRoutineAddress(&DestinationString);
  qword_14115DA08 = MmCopyMemory;
  if ( MmCopyMemory )
  {
    v15 = 0;
    v11 = MmCopyMemory(v9, BaseAddress, v6, 2, &v15);
    v12 = v15;
    v13 = v6 < v15;
    v6 -= v15;
    if ( v13 || v6 == 0 || v11 >= 0 && v6 == 0 )
      goto LABEL_11;
    Pool = &v9[v15];
LABEL_10:
    memset(Pool, 0, v6);
LABEL_11:
    if ( !a4 )
      goto LABEL_13;
    goto LABEL_12;
  }
  v12 = 0;
  if ( a4 )
LABEL_12:
    *a4 = v12;
LABEL_13:
  if ( v12 )
  {
    result = 2147483661LL;
    if ( v12 >= a3 )
      result = 0;
    goto LABEL_16;
  }
  result = 3221225477LL;
  if ( (v14 ^ v17) != _security_cookie )
    goto LABEL_19;
  return result;
}