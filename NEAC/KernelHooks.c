void HookStoredKernelRoutine()
{
  __int64 v0; // rdi
  _QWORD *v1; // rsi
  _QWORD *v2; // rax
  _QWORD *v3; // rax
  __int64 i; // rcx
  __int64 v5; // r8
  char *v6; // rax
  __int64 v7; // rdx
  int v8; // ecx
  __int64 v9; // rdx
  __int64 v10; // rcx
  __int64 v11; // [rsp+0h] [rbp-A8h] BYREF
  int v12; // [rsp+30h] [rbp-78h] BYREF
  int v13; // [rsp+34h] [rbp-74h] BYREF
  _QWORD v14[2]; // [rsp+38h] [rbp-70h] BYREF
  int v15; // [rsp+48h] [rbp-60h]
  PVOID *v16; // [rsp+50h] [rbp-58h]
  __int64 v17; // [rsp+58h] [rbp-50h]
  _QWORD v18[2]; // [rsp+60h] [rbp-48h] BYREF
  __int128 v19; // [rsp+70h] [rbp-38h] BYREF
  __int64 v20; // [rsp+80h] [rbp-28h]
  __int64 v21; // [rsp+88h] [rbp-20h]

  v0 = qword_14115DB20;
  if ( qword_14115DB20 )
  {
    v1 = AllocateMemoryWrapper(16);
    v1[1] = 0;
    v2 = AllocateMemoryWrapper(40);
    *v2 = v2;
    v2[1] = v2;
    v2[2] = v2;
    *(v2 + 12) = 257;
    *v1 = v2;
    qword_1411360F8 = v1;
    v18[1] = 0;
    v3 = AllocateMemoryWrapper(40);
    *v3 = v3;
    v3[1] = v3;
    v3[2] = v3;
    *(v3 + 12) = 257;
    v18[0] = v3;
    v19 = 0;
    v20 = 0;
    v17 = qword_1411360F8;
    v16 = &KernelStart;
    v14[1] = 500;
    v14[0] = v0;
    v15 = 32;
    v13 = 0;
    v12 = 1280;
    std::vector(&v19, 0, v14, &v12, &v13);
    v5 = *(&v19 + 1);
    for ( i = v19; *(&v19 + 1) != v19; i = v19 )
    {
      v6 = *(v5 - 24);
      v7 = *(v5 - 16);
      v8 = *(v5 - 8);
      *(&v19 + 1) = v5 - 24;
      KernelHook(v6, v7, HandlerForHook, v14, v8);
      v5 = *(&v19 + 1);
    }
    if ( i )
    {
      v9 = v20 - i;
      if ( (v20 - i) >= 0x1000 )
      {
        if ( (i - *(i - 8) - 8) >= 0x20 )
          KeBugCheckWrapper();
        v9 += 39;
        i = *(i - 8);
      }
      FreeWrapper(i, v9);
      v19 = 0;
      v20 = 0;
    }
    v10 = v18[0];
    if ( !*(*(v18[0] + 8LL) + 25LL) )
    {
      sub_1400193B0(*(v18[0] + 8LL), v18, v18);
      v10 = v18[0];
    }
    FreeWrapper(v10, 40);
  }
  if ( (&v11 ^ v21) != _security_cookie )
    __debugbreak();
}

__int64 __fastcall HandlerForHook(int *a1, unsigned __int64 a2, __int64 a3, __int64 a4, __int64 a5, int a6)
{
  unsigned int v6; // esi
  _QWORD *v8; // rcx
  __int64 v9; // r10
  __int64 v10; // r9
  int v12; // eax
  __int64 v13; // rax
  unsigned __int64 v14; // rcx
  __int64 v15; // rdx
  __int64 v16; // rbx
  int *v17; // r8
  __int64 v18; // r11
  __int64 v19; // rax
  __int64 v20; // rdx
  __int64 v21; // rcx
  __int64 v22; // r9
  _BYTE v24[36]; // [rsp+0h] [rbp-88h] BYREF
  int v25; // [rsp+24h] [rbp-64h] BYREF
  __int64 v26; // [rsp+28h] [rbp-60h] BYREF
  unsigned __int64 v27; // [rsp+30h] [rbp-58h] BYREF
  unsigned __int64 v28; // [rsp+38h] [rbp-50h] BYREF
  _DWORD v29[4]; // [rsp+40h] [rbp-48h] BYREF
  __int64 v30; // [rsp+50h] [rbp-38h]

  v28 = a2;
  v8 = *(a5 + 32);
  LOBYTE(v6) = 1;
  if ( v8[1] > *(a5 + 8) )
    goto LABEL_34;
  v9 = *(*v8 + 8LL);
  v10 = *v8;
  if ( !*(v9 + 25) )
  {
    v10 = *v8;
    do
    {
      v18 = 16;
      if ( *(v9 + 32) >= a2 )
      {
        v10 = v9;
        v18 = 0;
      }
      v9 = *(v9 + v18);
    }
    while ( !*(v9 + 25) );
  }
  if ( !*(v10 + 25) && v10 != *v8 && a2 >= *(v10 + 32) )
    goto LABEL_34;
  sub_140018FF0(v8, v29, &v28);
  v12 = *a1;
  if ( (*a1 - 253) > 0x13 )
    goto LABEL_31;
  v13 = *(a1 + 30);
  if ( *(v13 + 152) == 1 && *(v13 + 160) == 2 )
  {
    v14 = *(v13 + 168);
    v27 = v14;
    v15 = *(a5 + 24);
    if ( v15 && sub_14001A470(v14, v15) )
    {
      sub_140017BB0(a5 + 40, &v26, &v27);
      if ( v26 == *(a5 + 40) )
      {
        sub_140017C10(a5 + 40, v29, &v27);
        if ( a6 + 1 < *(a5 + 16) )
        {
          v16 = a5 + 56;
          v29[0] = a6 + 1;
          v25 = 768;
          v17 = &v25;
LABEL_23:
          sub_140017D30(v16, &v27, v17, v29);
        }
      }
    }
    else
    {
      v19 = *(a5 + 40);
      v20 = *(v19 + 8);
      v21 = v19;
      if ( !*(v20 + 25) )
      {
        v21 = *(a5 + 40);
        do
        {
          v22 = 16;
          if ( *(v20 + 32) >= v27 )
          {
            v21 = v20;
            v22 = 0;
          }
          v20 = *(v20 + v22);
        }
        while ( !*(v20 + 25) );
      }
      if ( *(v21 + 25) || v21 == v19 || v27 < *(v21 + 32) )
      {
        sub_140017C10(a5 + 40, v29, &v27);
        if ( a6 + 1 < *(a5 + 16) )
        {
          v16 = a5 + 56;
          v29[0] = a6 + 1;
          LODWORD(v26) = 768;
          v17 = &v26;
          goto LABEL_23;
        }
      }
    }
    v12 = *a1;
    if ( *a1 == 264 )
      goto LABEL_34;
LABEL_31:
    if ( v12 == 147 )
      goto LABEL_34;
  }
  if ( a3 != 1 )
  {
    v6 = 0;
    if ( (v24 ^ v30) == _security_cookie )
      return v6;
LABEL_37:
    __debugbreak();
  }
  LOBYTE(v6) = *(a1 + 18) == 0xCC || *(a1 + 18) == 0x90;
LABEL_34:
  if ( (v24 ^ v30) != _security_cookie )
    goto LABEL_37;
  return v6;
}

void HookStoredKernelRoutine2()
{
  __int64 v0; // rdi
  _QWORD *v1; // rsi
  _QWORD *v2; // rax
  _QWORD *v3; // rax
  __int64 i; // rcx
  __int64 v5; // r8
  char *v6; // rax
  __int64 v7; // rdx
  int v8; // ecx
  __int64 v9; // rdx
  __int64 v10; // rcx
  __int64 v11; // [rsp+0h] [rbp-A8h] BYREF
  int v12; // [rsp+30h] [rbp-78h] BYREF
  int v13; // [rsp+34h] [rbp-74h] BYREF
  _QWORD v14[2]; // [rsp+38h] [rbp-70h] BYREF
  int v15; // [rsp+48h] [rbp-60h]
  PVOID *v16; // [rsp+50h] [rbp-58h]
  __int64 v17; // [rsp+58h] [rbp-50h]
  _QWORD v18[2]; // [rsp+60h] [rbp-48h] BYREF
  __int128 v19; // [rsp+70h] [rbp-38h] BYREF
  __int64 v20; // [rsp+80h] [rbp-28h]
  __int64 v21; // [rsp+88h] [rbp-20h]

  v0 = qword_14115DB28;
  if ( qword_14115DB28 )
  {
    v1 = AllocateMemoryWrapper(16);
    v1[1] = 0;
    v2 = AllocateMemoryWrapper(40);
    *v2 = v2;
    v2[1] = v2;
    v2[2] = v2;
    *(v2 + 12) = 257;
    *v1 = v2;
    qword_141136100 = v1;
    v18[1] = 0;
    v3 = AllocateMemoryWrapper(40);
    *v3 = v3;
    v3[1] = v3;
    v3[2] = v3;
    *(v3 + 12) = 257;
    v18[0] = v3;
    v19 = 0;
    v20 = 0;
    v17 = qword_141136100;
    v16 = &KernelStart;
    v14[1] = 500;
    v14[0] = v0;
    v15 = 32;
    v13 = 0;
    v12 = 1280;
    std::vector(&v19, 0, v14, &v12, &v13);
    v5 = *(&v19 + 1);
    for ( i = v19; *(&v19 + 1) != v19; i = v19 )
    {
      v6 = *(v5 - 24);
      v7 = *(v5 - 16);
      v8 = *(v5 - 8);
      *(&v19 + 1) = v5 - 24;
      KernelHook(v6, v7, HandlerForHook, v14, v8);
      v5 = *(&v19 + 1);
    }
    if ( i )
    {
      v9 = v20 - i;
      if ( (v20 - i) >= 0x1000 )
      {
        if ( (i - *(i - 8) - 8) >= 0x20 )
          KeBugCheckWrapper();
        v9 += 39;
        i = *(i - 8);
      }
      FreeWrapper(i, v9);
      v19 = 0;
      v20 = 0;
    }
    v10 = v18[0];
    if ( !*(*(v18[0] + 8LL) + 25LL) )
    {
      sub_1400193B0(*(v18[0] + 8LL), v18, v18);
      v10 = v18[0];
    }
    FreeWrapper(v10, 40);
  }
  if ( (&v11 ^ v21) != _security_cookie )
    __debugbreak();
}

void HookStoredKernelRoutine3()
{
  __int64 v0; // rdi
  _QWORD *v1; // rsi
  _QWORD *v2; // rax
  _QWORD *v3; // rax
  __int64 i; // rcx
  __int64 v5; // r8
  char *v6; // rax
  __int64 v7; // rdx
  int v8; // ecx
  __int64 v9; // rdx
  __int64 v10; // rcx
  __int64 v11; // [rsp+0h] [rbp-A8h] BYREF
  int v12; // [rsp+30h] [rbp-78h] BYREF
  int v13; // [rsp+34h] [rbp-74h] BYREF
  _QWORD v14[2]; // [rsp+38h] [rbp-70h] BYREF
  int v15; // [rsp+48h] [rbp-60h]
  PVOID *v16; // [rsp+50h] [rbp-58h]
  __int64 v17; // [rsp+58h] [rbp-50h]
  _QWORD v18[2]; // [rsp+60h] [rbp-48h] BYREF
  __int128 v19; // [rsp+70h] [rbp-38h] BYREF
  __int64 v20; // [rsp+80h] [rbp-28h]
  __int64 v21; // [rsp+88h] [rbp-20h]

  v0 = qword_14115DB18;
  if ( qword_14115DB18 )
  {
    v1 = AllocateMemoryWrapper(16);
    v1[1] = 0;
    v2 = AllocateMemoryWrapper(40);
    *v2 = v2;
    v2[1] = v2;
    v2[2] = v2;
    *(v2 + 12) = 257;
    *v1 = v2;
    qword_141136108 = v1;
    v18[1] = 0;
    v3 = AllocateMemoryWrapper(40);
    *v3 = v3;
    v3[1] = v3;
    v3[2] = v3;
    *(v3 + 12) = 257;
    v18[0] = v3;
    v19 = 0;
    v20 = 0;
    v17 = qword_141136108;
    v16 = &KernelStart;
    v14[1] = 500;
    v14[0] = v0;
    v15 = 32;
    v13 = 0;
    v12 = 1280;
    std::vector(&v19, 0, v14, &v12, &v13);
    v5 = *(&v19 + 1);
    for ( i = v19; *(&v19 + 1) != v19; i = v19 )
    {
      v6 = *(v5 - 24);
      v7 = *(v5 - 16);
      v8 = *(v5 - 8);
      *(&v19 + 1) = v5 - 24;
      KernelHook(v6, v7, HandlerForHook, v14, v8);
      v5 = *(&v19 + 1);
    }
    if ( i )
    {
      v9 = v20 - i;
      if ( (v20 - i) >= 0x1000 )
      {
        if ( (i - *(i - 8) - 8) >= 0x20 )
          KeBugCheckWrapper();
        v9 += 39;
        i = *(i - 8);
      }
      FreeWrapper(i, v9);
      v19 = 0;
      v20 = 0;
    }
    v10 = v18[0];
    if ( !*(*(v18[0] + 8LL) + 25LL) )
    {
      sub_1400193B0(*(v18[0] + 8LL), v18, v18);
      v10 = v18[0];
    }
    FreeWrapper(v10, 40);
  }
  if ( (&v11 ^ v21) != _security_cookie )
    __debugbreak();
}

void HookStoredKernelRoutine4()
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  v0 = qword_14115DB70;
  if ( !qword_14115DB70 )
    goto LABEL_24;
  v1 = AllocateMemoryWrapper(16);
  v1[1] = 0;
  v2 = AllocateMemoryWrapper(40);
  *v2 = v2;
  v2[1] = v2;
  v2[2] = v2;
  *(v2 + 12) = 257;
  *v1 = v2;
  qword_141136110 = v1;
  v35[1] = 0;
  v3 = AllocateMemoryWrapper(40);
  *v3 = v3;
  v3[1] = v3;
  v3[2] = v3;
  *(v3 + 12) = 257;
  v35[0] = v3;
  v36 = 0;
  v37 = 0;
  v34 = qword_141136110;
  v33 = &KernelStart;
  v31[1] = 100;
  v31[0] = v0;
  v32 = 32;
  LODWORD(v23[0]) = 0;
  v30 = 1280;
  std::vector(&v36, 0, v31, &v30, v23);
  for ( i = *(&v36 + 1); *(&v36 + 1) != v36; i = *(&v36 + 1) )
  {
    v5 = *(i - 24);
    v6 = *(i - 16);
    v7 = *(i - 8);
    *(&v36 + 1) = i - 24;
    KernelHook(v5, v6, HandlerForHook, v31, v7);
  }
  if ( *(qword_141136110 + 8) <= 0x1Du )
  {
    sub_14001A760(v0, 100, sub_1411C39F0, 0);
    if ( qword_14115DBA0 )
    {
      v8 = AllocateMemoryWrapper(16);
      v8[1] = 0;
      v9 = AllocateMemoryWrapper(40);
      *v9 = v9;
      v9[1] = v9;
      v9[2] = v9;
      *(v9 + 12) = 257;
      *v8 = v9;
      qword_141136130 = v8;
      v27[1] = 0;
      v10 = AllocateMemoryWrapper(40);
      *v10 = v10;
      v10[1] = v10;
      v10[2] = v10;
      *(v10 + 12) = 257;
      v27[0] = v10;
      v28 = 0;
      v29 = 0;
      v26 = qword_141136130;
      v25 = &KernelStart;
      v23[1] = 1000;
      v23[0] = qword_14115DBA0;
      v24 = 32;
      v30 = 0;
      v22 = 5376;
      std::vector(&v28, 0, v23, &v22, &v30);
      v12 = *(&v28 + 1);
      for ( j = v28; *(&v28 + 1) != v28; j = v28 )
      {
        v13 = *(v12 - 24);
        v14 = *(v12 - 16);
        v15 = *(v12 - 8);
        *(&v28 + 1) = v12 - 24;
        KernelHook(v13, v14, HandlerForHook, v23, v15);
        v12 = *(&v28 + 1);
      }
      if ( j )
      {
        v16 = v29 - j;
        if ( (v29 - j) >= 0x1000 )
        {
          if ( (j - *(j - 8) - 8) >= 0x20 )
            goto LABEL_26;
          v16 += 39;
          j = *(j - 8);
        }
        FreeWrapper(j, v16);
        v28 = 0;
        v29 = 0;
      }
      v17 = v27[0];
      if ( !*(*(v27[0] + 8LL) + 25LL) )
      {
        sub_1400193B0(*(v27[0] + 8LL), v27, v27);
        v17 = v27[0];
      }
      FreeWrapper(v17, 40);
    }
  }
  v18 = v36;
  if ( v36 )
  {
    v19 = v37 - v36;
    if ( (v37 - v36) < 0x1000 )
    {
LABEL_20:
      FreeWrapper(v18, v19);
      v36 = 0;
      v37 = 0;
      goto LABEL_21;
    }
    if ( (v36 - 8 - *(v36 - 8)) < 0x20 )
    {
      v19 += 39;
      v18 = *(v36 - 8);
      goto LABEL_20;
    }
LABEL_26:
    KeBugCheckWrapper();
  }
LABEL_21:
  v20 = v35[0];
  if ( !*(*(v35[0] + 8LL) + 25LL) )
  {
    sub_1400193B0(*(v35[0] + 8LL), v35, v35);
    v20 = v35[0];
  }
  FreeWrapper(v20, 40);
LABEL_24:
  if ( (&v21 ^ v38) != _security_cookie )
    __debugbreak();
}

void HookStoredKernelRoutine5()
{
  __int64 v0; // rdi
  _QWORD *v1; // rsi
  _QWORD *v2; // rax
  _QWORD *v3; // rax
  __int64 i; // rcx
  __int64 v5; // r8
  char *v6; // rax
  __int64 v7; // rdx
  int v8; // ecx
  __int64 v9; // rdx
  __int64 v10; // rcx
  __int64 v11; // [rsp+0h] [rbp-A8h] BYREF
  int v12; // [rsp+30h] [rbp-78h] BYREF
  int v13; // [rsp+34h] [rbp-74h] BYREF
  _QWORD v14[2]; // [rsp+38h] [rbp-70h] BYREF
  int v15; // [rsp+48h] [rbp-60h]
  PVOID *v16; // [rsp+50h] [rbp-58h]
  __int64 v17; // [rsp+58h] [rbp-50h]
  _QWORD v18[2]; // [rsp+60h] [rbp-48h] BYREF
  __int128 v19; // [rsp+70h] [rbp-38h] BYREF
  __int64 v20; // [rsp+80h] [rbp-28h]
  __int64 v21; // [rsp+88h] [rbp-20h]

  v0 = qword_14115DBA8;
  if ( qword_14115DBA8 )
  {
    v1 = AllocateMemoryWrapper(16);
    v1[1] = 0;
    v2 = AllocateMemoryWrapper(40);
    *v2 = v2;
    v2[1] = v2;
    v2[2] = v2;
    *(v2 + 12) = 257;
    *v1 = v2;
    qword_141136138 = v1;
    v18[1] = 0;
    v3 = AllocateMemoryWrapper(40);
    *v3 = v3;
    v3[1] = v3;
    v3[2] = v3;
    *(v3 + 12) = 257;
    v18[0] = v3;
    v19 = 0;
    v20 = 0;
    v17 = qword_141136138;
    v16 = &KernelStart;
    v14[1] = 100;
    v14[0] = v0;
    v15 = 32;
    v13 = 0;
    v12 = 1280;
    std::vector(&v19, 0, v14, &v12, &v13);
    v5 = *(&v19 + 1);
    for ( i = v19; *(&v19 + 1) != v19; i = v19 )
    {
      v6 = *(v5 - 24);
      v7 = *(v5 - 16);
      v8 = *(v5 - 8);
      *(&v19 + 1) = v5 - 24;
      KernelHook(v6, v7, HandlerForHook, v14, v8);
      v5 = *(&v19 + 1);
    }
    if ( i )
    {
      v9 = v20 - i;
      if ( (v20 - i) >= 0x1000 )
      {
        if ( (i - *(i - 8) - 8) >= 0x20 )
          KeBugCheckWrapper();
        v9 += 39;
        i = *(i - 8);
      }
      FreeWrapper(i, v9);
      v19 = 0;
      v20 = 0;
    }
    v10 = v18[0];
    if ( !*(*(v18[0] + 8LL) + 25LL) )
    {
      sub_1400193B0(*(v18[0] + 8LL), v18, v18);
      v10 = v18[0];
    }
    FreeWrapper(v10, 40);
  }
  if ( (&v11 ^ v21) != _security_cookie )
    __debugbreak();
}

__int64 __fastcall KernelHook(
        char *VirtualAddress,
        __int64 a2,
        unsigned __int8 (__fastcall *Detour)(__int64, char *, __int64, _QWORD, __int64, int),
        __int64 a4,
        int a5)
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  v6 = sub_140002FC0(VirtualAddress);
  if ( v6 )
  {
    v7 = v6;
    v8 = RtlImageNtHeader(v6);
    if ( v8 )
    {
      v9 = v8;
      if ( v8->FileHeader.NumberOfSections )
      {
        v10 = (&v8->OptionalHeader.Magic + v8->FileHeader.SizeOfOptionalHeader);
        v11 = &VirtualAddress[a2 - 1];
        v12 = 0;
        v13 = 0;
        ImageSectionHandle = 0;
        while ( 1 )
        {
          v14 = v10[3];
          if ( VirtualAddress < &v7[v14] || VirtualAddress >= &v7[v14 + v10[4]] )
            goto LABEL_10;
          if ( *v10 == 1414090313 )
            goto LABEL_18;
          if ( *v10 == 1162297680 )
          {
            v13 = MmLockPagableDataSection(VirtualAddress);
            v15 = &v7[v10[3]];
            if ( v11 >= v15 )
            {
LABEL_11:
              if ( v11 < v10[4] + v15 && *v10 == 1162297680 )
                ImageSectionHandle = MmLockPagableDataSection(v11);
            }
          }
          else
          {
LABEL_10:
            v15 = &v7[v14];
            if ( v11 >= v15 )
              goto LABEL_11;
          }
          ++v12;
          v10 += 10;
          if ( v12 >= v9->FileHeader.NumberOfSections )
            goto LABEL_17;
        }
      }
    }
  }
  ImageSectionHandle = 0;
  v13 = 0;
LABEL_17:
  v27 = 0;
  if ( sub_1400739A0(3, 8, &v27) )
  {
LABEL_18:
    v16 = 0;
    if ( v13 + 1 < 2 )
      goto LABEL_19;
LABEL_26:
    MmUnlockPagableImageSection(v13);
    v17 = ImageSectionHandle;
    if ( ImageSectionHandle + 1 < 2 )
      return v16;
LABEL_27:
    MmUnlockPagableImageSection(v17);
    return v16;
  }
  v29[0] = 0;
  if ( sub_140073AB0(v27, 2u, 3u) )
  {
LABEL_22:
    v19 = 0;
LABEL_23:
    v16 = 0;
    v20 = v29[0];
    if ( v29[0] )
    {
LABEL_24:
      sub_140073950(v20, v19);
      v29[0] = 0;
    }
  }
  else
  {
    v26 = &VirtualAddress[a2];
    v16 = 1;
    v19 = 0;
    while ( 1 )
    {
      if ( v29[0] )
      {
        sub_140073950(v29[0], v19);
        v29[0] = 0;
      }
      if ( (VirtualAddress + 15) >= MmUserProbeAddress )
      {
        if ( !MmIsAddressValid(VirtualAddress) || !MmIsAddressValid(VirtualAddress + 15) )
          goto LABEL_23;
      }
      else
      {
        ProbeForRead(VirtualAddress, 0xFu, 1u);
      }
      v21 = sub_1400733C0(v27, VirtualAddress, 0xFu, VirtualAddress, 1, v29);
      if ( !v21 )
        goto LABEL_22;
      v19 = v21;
      v20 = v29[0];
      v22 = *(v29[0] + 16);
      if ( !*(v29[0] + 16) )
      {
        v16 = 0;
        goto LABEL_24;
      }
      if ( Detour(v29[0], VirtualAddress, v22, v16, a4, a5) )
        break;
      VirtualAddress += v22;
      ++v16;
      if ( VirtualAddress >= v26 )
        goto LABEL_23;
    }
    LOBYTE(v16) = 1;
    v20 = v29[0];
    if ( v29[0] )
      goto LABEL_24;
  }
  sub_140073338(&v27);
  if ( v13 + 1 >= 2 )
    goto LABEL_26;
LABEL_19:
  v17 = ImageSectionHandle;
  if ( ImageSectionHandle + 1 >= 2 )
    goto LABEL_27;
  return v16;
}

bool __fastcall sub_14001AA40(unsigned __int64 *a1)
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  v1 = a1;
  v53 = xmmword_1401E1CC8;
  *&v54[6] = 0xC300000000042444uLL;
  *v54 = 0x2444C70000000068LL;
  v52 = xmmword_1401E1CE8;
  *(a1 + 32) = 0;
  a1[5] = 0;
  v51 = 0;
  if ( sub_1400739A0(3, 8, &v51) )
  {
    result = 1;
    v3 = 0;
    goto LABEL_96;
  }
  v50 = 0;
  if ( sub_140073AB0(v51, 2, 3) )
  {
    LOBYTE(v4) = 0;
    v5 = 0;
    goto LABEL_95;
  }
  v6 = v50;
  v7 = 0;
  v46 = 0;
  v4 = 0;
  v8 = 0;
  v49 = v1;
  do
  {
    v9 = (*v1 + v8);
    v10 = v1[2];
    if ( v6 )
    {
      sub_140073950(v6, v7);
      v50 = 0;
    }
    v7 = sub_1400733C0(v51, v9, 15, v9, 1, &v50);
    if ( !v7 )
    {
      v31 = 1;
      v30 = v50;
      if ( !v50 )
        goto LABEL_60;
      goto LABEL_59;
    }
    if ( !v50 || (v11 = *(v50 + 240)) == 0 )
    {
      v31 = 1;
      v58.m128_u64[0] = 0xAE79D244D484E890uLL;
      v58.m128_u64[1] = 0x1FBC7FC2C450CB26LL;
      v59.m128_u64[0] = 0x42C7A5099E48D56FLL;
      v59.m128_u64[1] = 0x6BE083D385E0B978LL;
      v60.m128_u64[0] = 0xED55E1FBB39164ADuLL;
      v60.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
      v63.m128_u64[0] = 0xDC16F237A0F786F9uLL;
      v63.m128_u64[1] = 0x7AD85FB6B73EA206LL;
      v64.m128_u64[0] = 0x36A8CB29F221B41BLL;
      v64.m128_u64[1] = 0x1F8EE6A0E092C958LL;
      v65.m128_u64[0] = 0xED55E1FBB39164ADuLL;
      v65.m128_u64[1] = 0xD12C83EA13AA49CAuLL;  // "Invalid memory access detected in code section."
      goto LABEL_54;
    }
    v12 = v4;
    v13 = v8;
    v14 = *(v50 + 16);
    v48 = v13;
    if ( v13 < 0xEu )
    {
      v47 = v7;
      v45 = v4;
      v19 = *(v11 + 98);
      if ( (v19 & 0xC7) == 5 )
      {
        memove(v62, v9, v14);
        v12 = v4;
        *&v62[v14 - *(v11 + 192) - 4] = *(v11 + 104) + v9 - (v4 + v10);
        v15 = *(v11 + 92) == 0xFF && (v19 & 0x38) == 32;
        v17 = v62;
        v4 = v45;
        v7 = v47;
        v1 = v49;
        goto LABEL_29;
      }
      v20 = *(v11 + 92);
      if ( v20 == 232 )
      {
        *(&v53 + 1) = &v9[v14 + *(v11 + 168)];
        v16 = 16;
        v15 = 0;
        v17 = &v53;
        v4 = v45;
        v7 = v47;
      }
      else
      {
        v7 = v47;
        if ( (v20 & 0xFFFFFFFD) == 0xE9 )
        {
          v21 = &v9[v14];
          v22 = 32;
          if ( v20 == 0xEB )
            v22 = 56;
          v23 = &v21[(*(v11 + 168) << v22) >> v22];
          if ( v23 >= *v1 && v23 < *v1 + 5 )
          {
            v24 = v46;
            if ( v46 <= v23 )
              v24 = v23;
            v46 = v24;
LABEL_39:
            v15 = 0;
            v17 = v9;
            v4 = v45;
            goto LABEL_29;
          }
          *&v54[1] = v21 + ((*(v11 + 168) << v22) >> v22);
          *&v54[9] = HIDWORD(v23);
          v15 = v9 >= v46;
          v16 = 14;
          v17 = v54;
          v4 = v45;
        }
        else
        {
          v27 = 56;
          if ( (v20 & 0xFFFFFFF0) != 112 && (v20 & 0xFFFFFFFC) != 224 )
          {
            v27 = 32;
            if ( *(v11 + 93) > -113 )
            {
              v4 = v45;
              v15 = (v20 & 0xFFFFFFFE) == 0xC2 && v9 >= v46;
              v17 = v9;
              goto LABEL_29;
            }
          }
          v28 = &v9[v14 + ((*(v11 + 168) << v27) >> v27)];
          if ( v28 >= *v1 && v28 < *v1 + 5 )
          {
            v29 = v46;
            if ( v46 <= v28 )
              v29 = &v9[v14 + ((*(v11 + 168) << v27) >> v27)];
            v46 = v29;
            goto LABEL_39;
          }
          v4 = v45;
          if ( (v20 & 0xFC) == 0xE0 )
          {
            v31 = 1;
            LOBYTE(v8) = v48;
            v30 = v50;
            goto LABEL_59;
          }
          if ( v20 == 15 )
            LOBYTE(v20) = *(v11 + 93);
          LOBYTE(v52) = v20 & 0xF ^ 0x71;
          *(&v52 + 1) = v28;
          v16 = 16;
          v15 = 0;
          v17 = &v52;
        }
      }
    }
    else
    {
      *&v54[9] = HIDWORD(v9);
      *&v54[1] = v9;
      v15 = 1;
      v16 = 14;
      v17 = v54;
    }
    v18 = v9 < v46 && v16 != v14;
    v14 = v16;
    if ( v18 )
    {
      v31 = 1;
      v58.m128_u64[0] = 0xFC629D598099E79AuLL;
      v58.m128_u64[1] = 0x12AC7FC4D24ACE67LL;
      v59.m128_u64[0] = 0x43DABF5A9C48947ELL;
      v59.m128_u64[1] = 0x7AE2C6CE8FFBBD3BLL;
      v60.m128_u64[0] = 0xCD3B88DBDBE503C3uLL;
      v60.m128_u64[1] = 0xB94FED8B61C869ABuLL;
      v61.m128_u64[0] = 0x2B7AF89D708D00C1LL;
      v61.m128_u64[1] = 0x66DC2C40D04027CLL;
      v63.m128_u64[0] = 0xDC16F237A0F786F9uLL;
      v63.m128_u64[1] = 0x7AD85FB6B73EA206LL;
      v64.m128_u64[0] = 0x36A8CB29F221B41BLL;
      v64.m128_u64[1] = 0x1F8EE6A0E092C958LL;
      v65.m128_u64[0] = 0xED55E1FBB39164ADuLL;
      v65.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
      v66.m128_u64[0] = 0x2B7AF89D708D00EFLL;
      v66.m128_u64[1] = 0x66DC2C40D04027CLL;
      v58 = _mm_xor_ps(v58, v63);
      v59 = _mm_xor_ps(v59, v64);
      v60 = _mm_xor_ps(v60, v65);
      v61 = _mm_xor_ps(v61, v66);               // "Buffer overflow detected while processing instructions."
      goto LABEL_58;
    }
LABEL_29:
    v25 = v14;
    if ( v14 + v12 >= 0x33 )
    {
      v31 = 1;
      v58.m128_u64[0] = 0xB57A9D47CD96F48DuLL;
      v58.m128_u64[1] = 0x16F830D9C31EC768LL;
      v59.m128_u64[0] = 0x36A8CB079746C67ALL;
      v59.m128_u64[1] = 0x1F8EE6A0E092C958LL;
      v63.m128_u64[0] = 0xDC16F237A0F786F9uLL;
      v63.m128_u64[1] = 0x7AD85FB6B73EA206LL;
      v64.m128_u64[0] = 0x36A8CB29F221B41BLL;
      v64.m128_u64[1] = 0x1F8EE6A0E092C958LL;
      v58 = _mm_xor_ps(v58, v63);
      v59 = _mm_xor_ps(v59, v64);               // "Code range overlap detected. Possible self-modifying code."
LABEL_58:
      MainLogFunction(128, &unk_14016FCE0, &v58);
      LOBYTE(v8) = v48;
      v30 = v50;
      if ( !v50 )
        goto LABEL_60;
      goto LABEL_59;
    }
    v26 = v1[5];
    v8 = v48;
    if ( v26 >= 0x20 )
    {
      v31 = 1;
      v58.m128_u64[0] = 0xB57A9D47CD96F48DuLL;
      v58.m128_u64[1] = 0xEF82CD7DF1EC768LL;
      v59.m128_u64[0] = 0x16D1A5489F01DB74LL;
      v59.m128_u64[1] = 0x6BED93D294E1A731LL;
      v60.m128_u64[0] = 0xED55E1D5C0FF0BC4uLL;
      v60.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
      v63.m128_u64[0] = 0xDC16F237A0F786F9uLL;
      v63.m128_u64[1] = 0x7AD85FB6B73EA206LL;
      v64.m128_u64[0] = 0x36A8CB29F221B41BLL;
      v64.m128_u64[1] = 0x1F8EE6A0E092C958LL;
      v65.m128_u64[0] = 0xED55E1FBB39164ADuLL;
      v65.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
LABEL_54:
      v58 = _mm_xor_ps(v58, v63);
      v59 = _mm_xor_ps(v59, v64);
      v60 = _mm_xor_ps(v60, v65);               // "Invalid instruction sequence detected at address: %p"
      MainLogFunction(128, &unk_14016FCE0, &v58);
      v30 = v50;
      if ( !v50 )
        goto LABEL_60;
      goto LABEL_59;
    }
    *(v1 + v26 + 48) = v48;
    *(v1 + v1[5]++ + 80) = v4;
    memove((v12 + v1[2]), v17, v25);
    LOBYTE(v4) = v25 + v4;
    v6 = v50;
    LOBYTE(v8) = *(v50 + 16) + v8;
  }
  while ( !v15 );
  v31 = 0;
  v30 = v50;
  if ( !v50 )
    goto LABEL_60;
LABEL_59:
  sub_140073950(v30, v7);
  v50 = 0;
LABEL_60:
  sub_140073338(&v51);
  if ( v8 > 4u )
  {
    v5 = v31;
  }
  else
  {
    v32 = *v1;
    v33 = *(*v1 + v8);
    v5 = v31;
    if ( *(*v1 + v8) && v33 != 204 && v33 != 144 )
      goto LABEL_70;
    if ( v8 != 4 )
    {
      v34 = v8;
      while ( *(v32 + v34 + 1) == v33 )
      {
        if ( ++v34 == 4 )
          goto LABEL_95;
      }
LABEL_70:
      if ( v8 > 1u || (!*(*v1 + v8) || v33 == 204 || v33 == 144) && (v8 || *(v32 + 1) == v33) )
      {
        v35 = (v32 - 5);
        if ( MmIsAddressValid(v35) )
        {
          if ( (ReadMsr(3221225600LL) & 0x800) == 0
            || (v36 = sub_140003110(v35), v37 = sub_140003150(v35), *v36 >= 0)
            && ((*v36 & 0x80u) != 0LL || v37 && *v37 >= 0) )
          {
            v38 = *v1;
            v39 = *(*v1 - 5);
            v5 = v31;
            if ( *(*v1 - 5) && v39 != 204 && v39 != 144
              || *(v38 - 4) != v39
              || *(v38 - 3) != v39
              || *(v38 - 2) != v39
              || *(v38 - 1) != v39 )
            {
              v58.m128_u64[0] = 0xBB639D59C5D7E997uLL;
              v58.m128_u64[1] = 0x5ABD3CD7C74D826ELL;
              v59.m128_u64[0] = 0x5BC9B95DD253DB7DLL;
              v59.m128_u64[1] = 0x7CAE83CE89FEA628LL;
              v60.m128_u64[0] = 0xED55E1C893F400C2uLL;
              v60.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
              v63.m128_u64[0] = 0xDC16F237A0F786F9uLL;
              v63.m128_u64[1] = 0x7AD85FB6B73EA206LL;
              v64.m128_u64[0] = 0x36A8CB29F221B41BLL;
              v64.m128_u64[1] = 0x1F8EE6A0E092C958LL;
              v65.m128_u64[0] = 0xED55E1FBB39164ADuLL;
              v65.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
              v58 = _mm_xor_ps(v58, v63);
              v59 = _mm_xor_ps(v59, v64);
              v60 = _mm_xor_ps(v60, v65);       // "Code integrity check failed. Patch verification error."
              MainLogFunction(128, &unk_14016FCE0, &v58);
              goto LABEL_93;
            }
            goto LABEL_94;
          }
        }
        v55.m128_u64[0] = 0xBB639D59C5D7E997uLL;
        v55.m128_u64[1] = 0x5ABD3CD7C74D826ELL;
        v56.m128_u64[0] = 0x5BC9B95DD253DB7DLL;
        v56.m128_u64[1] = 0x7CAE83CE89FEA628LL;
        v57.m128_u64[0] = 0xED55E1C993F400C2uLL;
        v40 = &v58;
      }
      else
      {
        v55.m128_u64[0] = 0xBB639D59C5D7E997uLL;
        v55.m128_u64[1] = 0x5ABD3CD7C74D826ELL;
        v56.m128_u64[0] = 0x5BC9B95DD253DB7DLL;
        v56.m128_u64[1] = 0x7CAE83CE89FEA628LL;
        v57.m128_u64[0] = 0xED55E1CA93F400C2uLL;
        v40 = &v63;
      }
      v57.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
      v40->m128_u64[0] = 0xDC16F237A0F786F9uLL;
      v40->m128_u64[1] = 0x7AD85FB6B73EA206LL;
      v40[1].m128_u64[0] = 0x36A8CB29F221B41BLL;
      v40[1].m128_u64[1] = 0x1F8EE6A0E092C958LL;
      v40[2].m128_u64[0] = 0xED55E1FBB39164ADuLL;
      v40[2].m128_u64[1] = 0xD12C83EA13AA49CAuLL;
      v55 = _mm_xor_ps(v55, *v40);
      v56 = _mm_xor_ps(v56, v40[1]);
      v57 = _mm_xor_ps(v57, v40[2]);            // "Digital signature verification failed. Driver may be tampered."
      MainLogFunction(128, &unk_14016FCE0, &v55);
LABEL_93:
      v5 = 1;
LABEL_94:
      *(v1 + 32) = 1;
    }
  }
LABEL_95:
  v3 = v4;
  result = v5 == 0;
LABEL_96:
  v41 = v1[1];
  *&v54[9] = HIDWORD(v41);
  *&v54[1] = v41;
  v42 = v1[2];
  v1[3] = v42 + v3;
  v43 = *v54;
  *(v42 + v3 + 6) = *&v54[6];
  *(v42 + v3) = v43;
  if ( (&v44 ^ v67) != _security_cookie )
    __debugbreak();
  return result;
}

__int64 __fastcall CheckForHooks2(__int64 a1, unsigned int a2, __int64 a3, unsigned int a4, _DWORD *a5)
{
  unsigned int v5; // edi
  __int64 v8; // r14
  __int64 v9; // rdx
  __int64 v10; // rcx
  __int64 v11; // rdx
  __int64 v12; // rcx
  __int64 v13; // rdx
  __int64 v14; // rcx
  __int64 v15; // rdx
  __int64 v16; // rcx
  __int64 v17; // rdx
  __int64 v18; // rcx
  __int64 v19; // rdx
  __int64 v20; // rcx
  PVOID v21; // rdi
  PVOID v22; // rbx
  const char *v23; // rdx
  __int64 v24; // r9
  __int64 v25; // r9
  __int64 v26; // r9
  __int64 v27; // r9
  __int64 v28; // r9
  __int64 v29; // r9
  PRUNTIME_FUNCTION v31; // rax
  struct _STRING DestinationString; // [rsp+20h] [rbp-30h] BYREF
  struct _STRING v33; // [rsp+38h] [rbp-18h] BYREF
  DWORD64 ControlPc[5]; // [rsp+48h] [rbp-8h] BYREF

  ControlPc[0] = 0;
  v5 = -1073741811;
  if ( a2 >= 9 )
  {
    if ( a1 + a2 < MmUserProbeAddress )
    {
      v8 = a1;
      ProbeForRead(a1, a2, 1u);
      a1 = v8;
    }
    if ( a4 >= 0x210 )
    {
      ControlPc[0] = *(a1 + 1);
      DestinationString = 0;
      if ( qword_1411360D8 )
      {
        v9 = *(*qword_1411360D8 + 8LL);
        v10 = *qword_1411360D8;
        if ( !*(v9 + 25) )
        {
          v10 = *qword_1411360D8;
          do
          {
            v24 = 16;
            if ( *(v9 + 32) >= ControlPc[0] )
            {
              v10 = v9;
              v24 = 0;
            }
            v9 = *(v9 + v24);
          }
          while ( !*(v9 + 25) );
        }
        if ( !*(v10 + 25) && v10 != *qword_1411360D8 && ControlPc[0] >= *(v10 + 32) )
        {
          v21 = KernelStart;
          v22 = qword_14115DC70;
          v23 = "nt!memmove";
          goto LABEL_114;
        }
      }
      if ( qword_1411360E8 )
      {
        v11 = *(*qword_1411360E8 + 8LL);
        v12 = *qword_1411360E8;
        if ( !*(v11 + 25) )
        {
          v12 = *qword_1411360E8;
          do
          {
            v25 = 16;
            if ( *(v11 + 32) >= ControlPc[0] )
            {
              v12 = v11;
              v25 = 0;
            }
            v11 = *(v11 + v25);
          }
          while ( !*(v11 + 25) );
        }
        if ( !*(v12 + 25) && v12 != *qword_1411360E8 && ControlPc[0] >= *(v12 + 32) )
        {
          v21 = KernelStart;
          v22 = qword_14115DC78;
          v23 = "nt!MiGetPhysicalAddress";
          goto LABEL_114;
        }
      }
      if ( qword_1411360E0 )
      {
        v13 = *(*qword_1411360E0 + 8LL);
        v14 = *qword_1411360E0;
        if ( !*(v13 + 25) )
        {
          v14 = *qword_1411360E0;
          do
          {
            v26 = 16;
            if ( *(v13 + 32) >= ControlPc[0] )
            {
              v14 = v13;
              v26 = 0;
            }
            v13 = *(v13 + v26);
          }
          while ( !*(v13 + 25) );
        }
        if ( !*(v14 + 25) && v14 != *qword_1411360E0 && ControlPc[0] >= *(v14 + 32) )
        {
          v21 = KernelStart;
          v22 = qword_14115DC80;
          v23 = "nt!MmProbeAndLockPages";
          goto LABEL_114;
        }
      }
      if ( qword_1411360F0 )
      {
        v15 = *(*qword_1411360F0 + 8LL);
        v16 = *qword_1411360F0;
        if ( !*(v15 + 25) )
        {
          v16 = *qword_1411360F0;
          do
          {
            v27 = 16;
            if ( *(v15 + 32) >= ControlPc[0] )
            {
              v16 = v15;
              v27 = 0;
            }
            v15 = *(v15 + v27);
          }
          while ( !*(v15 + 25) );
        }
        if ( !*(v16 + 25) && v16 != *qword_1411360F0 && ControlPc[0] >= *(v16 + 32) )
        {
          v21 = KernelStart;
          v22 = qword_14115DC88;
          v23 = "nt!MmCopyVirtualMemory";
          goto LABEL_114;
        }
      }
      if ( qword_1411360F8 )
      {
        v17 = *(*qword_1411360F8 + 8LL);
        v18 = *qword_1411360F8;
        if ( !*(v17 + 25) )
        {
          v18 = *qword_1411360F8;
          do
          {
            v28 = 16;
            if ( *(v17 + 32) >= ControlPc[0] )
            {
              v18 = v17;
              v28 = 0;
            }
            v17 = *(v17 + v28);
          }
          while ( !*(v17 + 25) );
        }
        if ( !*(v18 + 25) && v18 != *qword_1411360F8 && ControlPc[0] >= *(v18 + 32) )
        {
          v21 = KernelStart;
          v22 = qword_14115DB20;
          v23 = "nt!NtReadVirtualMemory";
          goto LABEL_114;
        }
      }
      if ( qword_141136100 )
      {
        v19 = *(*qword_141136100 + 8LL);
        v20 = *qword_141136100;
        if ( !*(v19 + 25) )
        {
          v20 = *qword_141136100;
          do
          {
            v29 = 16;
            if ( *(v19 + 32) >= ControlPc[0] )
            {
              v20 = v19;
              v29 = 0;
            }
            v19 = *(v19 + v29);
          }
          while ( !*(v19 + 25) );
        }
        if ( !*(v20 + 25) && v20 != *qword_141136100 && ControlPc[0] >= *(v20 + 32) )
        {
          v21 = KernelStart;
          v22 = qword_14115DB28;
          v23 = "nt!NtWriteVirtualMemory";
          goto LABEL_114;
        }
      }
      if ( qword_141136108 )
      {
        sub_140017BB0(qword_141136108, &v33, ControlPc);
        if ( *&v33.Length != *qword_141136108 )
        {
          v21 = KernelStart;
          v22 = qword_14115DB18;
          v23 = "nt!NtAllocateVirtualMemory";
LABEL_114:
          RtlInitAnsiString(&DestinationString, v23);
          goto LABEL_115;
        }
      }
      if ( qword_141136110 )
      {
        sub_140017BB0(qword_141136110, &v33, ControlPc);
        if ( *&v33.Length != *qword_141136110 )
        {
          v21 = KernelStart;
          v22 = qword_14115DB70;
          v23 = "nt!NtDeviceIoControlFile";
          goto LABEL_114;
        }
      }
      if ( qword_141136118 )
      {
        sub_140017BB0(qword_141136118, &v33, ControlPc);
        if ( *&v33.Length != *qword_141136110 )
        {
          v21 = KernelStart;
          v22 = qword_14115DB78;
          v23 = "nt!NtFsControlFile";
          goto LABEL_114;
        }
      }
      if ( qword_141136120 )
      {
        sub_140017BB0(qword_141136120, &v33, ControlPc);
        if ( *&v33.Length != *qword_141136120 )
        {
          v21 = KernelStart;
          v22 = qword_14115DB80;
          v23 = "nt!NtWriteFile";
          goto LABEL_114;
        }
      }
      if ( qword_141136128 )
      {
        sub_140017BB0(qword_141136128, &v33, ControlPc);
        if ( *&v33.Length != *qword_141136128 )
        {
          v21 = KernelStart;
          v22 = qword_14115DB98;
          v23 = "nt!NtReadFile";
          goto LABEL_114;
        }
      }
      if ( qword_141136130 )
      {
        sub_140017BB0(qword_141136130, &v33, ControlPc);
        if ( *&v33.Length != *qword_141136130 )
        {
          v21 = KernelStart;
          v22 = qword_14115DBA0;
          v23 = "nt!IopXxxControlFile";
          goto LABEL_114;
        }
      }
      if ( qword_141136138 )
      {
        sub_140017BB0(qword_141136138, &v33, ControlPc);
        if ( *&v33.Length != *qword_141136138 )
        {
          v21 = KernelStart;
          v22 = qword_14115DBA8;
          v23 = "nt!IofCallDriver";
          goto LABEL_114;
        }
      }
      if ( qword_141136150 )
      {
        sub_140017BB0(qword_141136150, &v33, ControlPc);
        if ( *&v33.Length != *qword_141136150 )
        {
          v21 = KernelStart;
          v22 = qword_14115DC98;
          v23 = "nt!MmAdjustWorkingSetSizeEx";
          goto LABEL_114;
        }
      }
      if ( qword_141136140 )
      {
        sub_140017BB0(qword_141136140, &v33, ControlPc);
        if ( *&v33.Length != *qword_141136140 )
        {
          v21 = KernelStart;
          v22 = qword_14115DBB8;
          v23 = "nt!NtReplyWaitReceivePort";
          goto LABEL_114;
        }
      }
      if ( qword_141136148 )
      {
        sub_140017BB0(qword_141136148, &v33, ControlPc);
        if ( *&v33.Length != *qword_141136148 )
        {
          v21 = KernelStart;
          v22 = qword_14115DBC0;
          v23 = "nt!NtReplyWaitReceivePortEx";
          goto LABEL_114;
        }
      }
      if ( qword_141136158 )
      {
        sub_140017BB0(qword_141136158, &v33, ControlPc);
        if ( *&v33.Length != *qword_141136158 )
        {
          v21 = KernelStart;
          v22 = qword_14115DD08;
          v23 = "nt!KeDelayExecutionThread";
          goto LABEL_114;
        }
      }
      if ( qword_141136160 )
      {
        sub_140017BB0(qword_141136160, &v33, ControlPc);
        if ( *&v33.Length != *qword_141136160 )
        {
          v21 = KernelStart;
          v22 = qword_14115DD10;
          v23 = "nt!ProbeForRead";
          goto LABEL_114;
        }
      }
      if ( qword_141136168 )
      {
        sub_140017BB0(qword_141136168, &v33, ControlPc);
        if ( *&v33.Length != *qword_141136168 )
        {
          v21 = KernelStart;
          v22 = qword_14115DD18;
          v23 = "nt!ProbeForWrite";
          goto LABEL_114;
        }
      }
      if ( qword_141136170 )
      {
        sub_140017BB0(qword_141136170, &v33, ControlPc);
        if ( *&v33.Length != *qword_141136170 )
        {
          v21 = KernelStart;
          v22 = qword_14115DD20;
LABEL_107:
          v23 = "nt!NtQueryInformationProcess";
          goto LABEL_114;
        }
      }
      if ( qword_14115DD38 != 0 && qword_14115DD38 == ControlPc[0] )
      {
        v21 = KernelStart;
        v22 = qword_14115DD30;
        v23 = "nt!PsCallImageNotifyRoutines";
        goto LABEL_114;
      }
      if ( someAddr != 0 && someAddr == ControlPc[0] )
      {
        v21 = KernelStart;
        v22 = ::ControlPc;
        v23 = "nt!PspCallProcessNotifyRoutines";
        goto LABEL_114;
      }
      if ( qword_14115DD58 != 0 && qword_14115DD58 == ControlPc[0] )
      {
        v21 = KernelStart;
        v22 = qword_14115DD50;
        v23 = "nt!PspCallThreadNotifyRoutines";
        goto LABEL_114;
      }
      *&v33.Length = 0;
      v22 = 0;
      v31 = RtlLookupFunctionEntry(ControlPc[0], &v33.Length, 0);
      v21 = 0;
      if ( v31 )
      {
        v21 = KernelStart;
        if ( *&v33.Length == KernelStart )
        {
          v22 = (v31->BeginAddress + *&v33.Length);
          if ( v22 == qword_14115DD20 )
            goto LABEL_107;
        }
        v22 = 0;
        v21 = 0;
      }
LABEL_115:
      if ( v22 )
      {
        sub_140038580(a3, 528);
        *a3 = v21;
        *(a3 + 8) = v22;
        v33.Buffer = (a3 + 16);
        *&v33.Length = 33488896;
        if ( DestinationString.Buffer && DestinationString.Length )
          RtlCopyString(&v33, &DestinationString);
        *a5 = 528;
        return 0;
      }
      else
      {
        return -1073741772;
      }
    }
  }
  return v5;
}

__int64 __fastcall RegisterInterruptHook(unsigned __int8 a1, char *a2, PVOID *a3, __int64 a4)
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  v35 = 0;
  MemoryWrapper = AllocateMemoryWrapper(40);
  *MemoryWrapper = MemoryWrapper;
  MemoryWrapper[1] = MemoryWrapper;
  MemoryWrapper[2] = MemoryWrapper;
  *(MemoryWrapper + 12) = 257;
  v34 = MemoryWrapper;
  v37 = 0;
  v9 = AllocateMemoryWrapper(40);
  *v9 = v9;
  v9[1] = v9;
  v9[2] = v9;
  *(v9 + 12) = 257;
  v36 = v9;
  v38 = 0;
  v39 = 0;
  v42 = 0;
  v10 = AllocateMemoryWrapper(40);
  *v10 = v10;
  v10[1] = v10;
  v10[2] = v10;
  *(v10 + 12) = 257;
  v41 = v10;
  v28 = a2;
  v29 = 0;
  v30 = 0;
  v40 = 3000;
  v31 = 32;
  v43 = a4;
  v32 = a3;
  v26 = 0;
  v27 = 0;
  v11 = RtlImageNtHeader(*a3);
  v12 = v11 + 1;
  v13 = &v11[1] + 40 * v11->FileHeader.NumberOfSections;
  if ( v12 < v13 )
  {
    v14 = 0;
    do
    {
      if ( !(v12->Signature ^ 0x7865742E | LOBYTE(v12->FileHeader.Machine) ^ 0x74) )
      {
        v14 = *a3 + v12->FileHeader.PointerToSymbolTable;
        *(&v26 + 1) = &v14[v12->FileHeader.TimeDateStamp];
      }
      v12 = (v12 + 40);
    }
    while ( v12 < v13 );
    *&v26 = v14;
  }
  v33 = &v26;
  v48.m128_i32[0] = 0;
  v44.m128_i32[0] = 768;
  std::vector(&v38, 0, &v28, &v44, &v48);
  for ( i = *(&v38 + 1); *(&v38 + 1) != v38; i = *(&v38 + 1) )
  {
    v16 = *(i - 24);
    v17 = *(i - 16);
    v18 = *(i - 8);
    *(&v38 + 1) = i - 24;
    KernelHook(v16, v17, sub_1400444D0, &v28, v18);
  }
  if ( v30 )
  {
    if ( SomeFlagWrapper() == 0 || v29 != 0 )
    {
      v19 = *a3;
      v30 = KernelStart + v30 - *a3;
      v28 = KernelStart + v28 - v19;
      v20 = v28;
      *&v29 = KernelStart + v29 - v19;
      v21 = v29;
      *(&v29 + 1) = KernelStart + *(&v29 + 1) - v19;
      v22 = *(&v29 + 1);
      v23 = 48 * a1;
      *(&unk_14115A820 + v23 + 24) = v30;
      *(&unk_14115A820 + v23 + 8) = v20;
      *(&unk_14115A820 + v23 + 32) = v21;
      *(&unk_14115A820 + v23 + 40) = v22;
      LOBYTE(a2) = 1;
      goto LABEL_15;
    }
    v44.m128_u64[0] = 0xA87F854480C4F49AuLL;
    v44.m128_u64[1] = 0x1CF82BD9D91ECA65LL;
    v45.m128_u64[0] = 0x36A8CB07964FC174LL;
    v45.m128_u64[1] = 0x1F8EE6A0E092C958LL;
    v48.m128_u64[0] = 0xDC16F237A0F786F9uLL;
    v48.m128_u64[1] = 0x7AD85FB6B73EA206LL;
    v49.m128_u64[0] = 0x36A8CB29F221B41BLL;
    v49.m128_u64[1] = 0x1F8EE6A0E092C958LL;
    v44 = _mm_xor_ps(v44, v48);
    v45 = _mm_xor_ps(v45, v49);                 // Failed to locate interrupt handler for vector: %02X\n
    MainLogFunction(128, &unk_14016FCE0, &v44);
  }
  else
  {
    v44.m128_u64[0] = 0xBE77D253CE82E9BFuLL;
    v44.m128_u64[1] = 0x13F833D7DA4CCD68LL;
    v45.m128_u64[0] = 0x42D8BE5B8044C075LL;
    v45.m128_u64[1] = 0x33AE9FD294FCAC78LL;
    v46.m128_u64[0] = 0x882F9897D2FF058DuLL;
    v46.m128_u64[1] = 0xF40CEE8561CC69AEuLL;
    v47.m128_u64[0] = 0x2B7AF89D708D009FLL;
    v47.m128_u64[1] = 0x66DC2C40D04027CLL;
    v48.m128_u64[0] = 0xDC16F237A0F786F9uLL;
    v48.m128_u64[1] = 0x7AD85FB6B73EA206LL;
    v49.m128_u64[0] = 0x36A8CB29F221B41BLL;
    v49.m128_u64[1] = 0x1F8EE6A0E092C958LL;
    v50.m128_u64[0] = 0xED55E1FBB39164ADuLL;
    v50.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
    v51.m128_u64[0] = 0x2B7AF89D708D00EFLL;
    v51.m128_u64[1] = 0x66DC2C40D04027CLL;
    v44 = _mm_xor_ps(v44, v48);
    v45 = _mm_xor_ps(v45, v49);
    v46 = _mm_xor_ps(v46, v50);
    v47 = _mm_xor_ps(v47, v51);                 // Failed to register interrupt handler for vector: %02X\n
    MainLogFunction(128, &unk_14016FCE0, &v44, a2);
  }
  LODWORD(a2) = 0;
LABEL_15:
  sub_140044DE0(&v28);
  if ( (&v25 ^ v52) != _security_cookie )
    __debugbreak();
  return a2;
}

__int64 __fastcall SSDThook(int *a1, unsigned __int64 a2, __int64 a3, unsigned int a4, __int64 a5, int a6)
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  v32 = a2;
  LOBYTE(v6) = 1;
  if ( *(a5 + 64) <= *(a5 + 112) )
  {
    v8 = *(a5 + 56);
    v9 = *(v8 + 8);
    v10 = v8;
    if ( !*(v9 + 25) )
    {
      v10 = *(a5 + 56);
      do
      {
        v24 = 16;
        if ( *(v9 + 32) >= a2 )
        {
          v10 = v9;
          v24 = 0;
        }
        v9 = *(v9 + v24);
      }
      while ( !*(v9 + 25) );
    }
    if ( *(v10 + 25) || v10 == v8 || a2 < *(v10 + 32) )
    {
      sub_140018FF0(a5 + 56, v33, &v32);
      if ( SomeFlagWrapper() )
      {
        if ( *a1 == 0x1C1 )                     // NtCreateUserProcess
        {
          v13 = *(a1 + 30);
          if ( *(v13 + 152) == 2 && *(v13 + 160) == 1 && *(v13 + 208) == 1 && *(v13 + 168) == 53 )
          {
            *(a5 + 8) = v32;
            goto LABEL_50;
          }
        }
      }
      v14 = SomeFlagWrapper() != 0;
      v15 = *a1;
      if ( v14 && *a1 == 51 )                   // NtQuerySystemInformation
      {
        v16 = *(a1 + 30);
        v17 = a4;
        v18 = a3;
        if ( *(v16 + 152) == 2 && *(v16 + 160) == 3 && *(v16 + 208) == 2 && *(v16 + 168) == 33 && *(v16 + 216) == 1 )
          dword_14115DE24 = *(v16 + 184);
        goto LABEL_51;
      }
      v17 = a4;
      v18 = a3;
      if ( (v15 - 253) > 19 )                   // syscalls from 253 to 280
      {
        if ( v15 != 56 )                        // NtAllocateVirtualMemory
          goto LABEL_51;
        v25 = *(a1 + 30);
        if ( *(v25 + 152) != 1 || *(v25 + 160) != 2 )
          goto LABEL_51;
        v26 = *(v25 + 168);
        v31 = v26;
        if ( sub_14001A470(v26, *(a5 + 40)) )
        {
          if ( v32 + 4096 > v26 && v32 < v26 || v26 + 4096 > v32 && v32 > v26 )
            goto LABEL_54;
          sub_140017C10(a5 + 120, v33, &v31);
        }
        goto LABEL_50;
      }
      v19 = *(a1 + 30);
      if ( *(v19 + 152) != 1 || *(v19 + 160) != 2 )
        goto LABEL_51;
      v20 = *(v19 + 168);
      v31 = v20;
      if ( sub_14001A470(v20, *(a5 + 40)) )
      {
        v21 = *(a5 + 72);
        v22 = *(v21 + 8);
        v23 = v21;
        if ( !*(v22 + 25) )
        {
          v23 = *(a5 + 72);
          do
          {
            v27 = 16;
            if ( *(v22 + 32) >= v20 )
            {
              v23 = v22;
              v27 = 0;
            }
            v22 = *(v22 + v27);
          }
          while ( !*(v22 + 25) );
        }
        if ( *(v23 + 25) || v23 == v21 || *(v23 + 32) > v20 )
        {
          sub_140017C10(a5 + 72, v33, &v31);
          if ( a6 + 1 < *(a5 + 32) )
          {
            v33[0] = a6 + 1;
            v30 = 1280;
            sub_140017D30(a5 + 88, &v31, &v30, v33);
          }
        }
      }
      if ( *a1 != 264 )
      {
LABEL_50:
        v17 = a4;
        v18 = a3;
LABEL_51:
        if ( (*(a5 + 136))(a1, v32, v18, v17, a5) )
          *(a5 + 24) = v32;
        LOBYTE(v6) = (*a1 - 231) < 3;
        goto LABEL_54;
      }
      if ( *(a5 + 8) && sub_14001A470(v31, *(a5 + 48)) )
        *(a5 + 16) = v32;
    }
  }
LABEL_54:
  if ( (&v29 ^ v34) != _security_cookie )
    JUMPOUT(0x140044862LL);
  return v6;
}

__int64 HookPageFault()
{
  __int64 result; // rax
  __int64 v1; // [rsp+0h] [rbp-38h] BYREF
  _BYTE v2[2]; // [rsp+26h] [rbp-12h] BYREF
  __int64 v3; // [rsp+28h] [rbp-10h]
  __int64 v4; // [rsp+30h] [rbp-8h]

  __sidt(v2);
  result = RegisterInterruptHook(
             0xEu,
             ((*(v3 + 232) << 32) | (*(v3 + 230) << 16) | *(v3 + 224)),
             &KernelStart,
             SomeConstantWrapper);
  if ( (&v1 ^ v4) != _security_cookie )
    JUMPOUT(0x140045783LL);
  return result;
}

PVOID __fastcall DynamicHookCreate(unsigned __int64 a1, int a2, __int64 a3, int a4, __int64 a5)
{
  PVOID Memory; // rax
  PVOID v10; // rsi
  int v11; // eax
  __m128i v12; // xmm0
  __m128i v13; // xmm0
  int v14; // r14d
  _BYTE v16[32]; // [rsp+0h] [rbp-698h] BYREF
  __int64 v17; // [rsp+20h] [rbp-678h]
  __m128 v18; // [rsp+30h] [rbp-668h] BYREF
  __m128 v19; // [rsp+40h] [rbp-658h]
  _OWORD Dst[96]; // [rsp+50h] [rbp-648h] BYREF
  __m128 v21; // [rsp+650h] [rbp-48h]
  __m128 v22; // [rsp+660h] [rbp-38h]
  __int64 v23; // [rsp+670h] [rbp-28h]

  memset(Dst, 0, 0x5F8u);
  Memory = AllocateMemory(0xFFFFFFFFFFFFFFFFLL, a1, 0x1000u);
  if ( Memory )
  {
    v10 = Memory;
    v17 = 0;
    v11 = RisePrivilegesToCallKernelFunc(-1);
    if ( v11 >= 0 )
    {
      v12 = _mm_loadl_epi64(a5);
      v13 = _mm_sub_epi16(v12, _mm_subs_epu16(v12, xmmword_140D85BD0));
      LODWORD(Dst[33]) = _mm_cvtsi128_si32(v13);
      DWORD1(Dst[33]) = v10 + 544;
      *(&Dst[32] + 1) = a3;
      memove(&Dst[34], *(a5 + 8), _mm_extract_epi16(v13, 0));
      Dst[0] = loc_140D85BE0;
      Dst[2] = *(&loc_140D85BFF + 1);
      Dst[3] = xmmword_140D85C10;
      Dst[5] = xmmword_140D85C30;
      Dst[6] = xmmword_140D85C40;
      Dst[1] = *(&loc_140D85BEF + 1);
      Dst[4] = xmmword_140D85C20;
      LOBYTE(Dst[7]) = -52;
      *(Dst + 7) = v10 + 520;
      v14 = a4 - v10;
      *(&Dst[2] + 6) = v14 - 42;
      HIDWORD(Dst[2]) = v10 + 520;
      *(&Dst[3] + 1) = v10 + 512;
      DWORD2(Dst[3]) = v10 + 516;
      *(&Dst[5] + 1) = v14 - 85;
      *(&Dst[5] + 6) = v10 + 1520;
      *(&Dst[5] + 11) = v10 + 528;
      DWORD1(Dst[6]) = a2 - v10 - 104;
      HIDWORD(Dst[6]) = a3 - v10 - 112;
      v17 = 0;
      sub_14006EA60(-1);
      if ( (v16 ^ v23) != _security_cookie )
        goto LABEL_4;
      return v10;
    }
    v18.m128_u64[0] = 0xA8369652CC9EE7BFuLL;
    v18.m128_u64[1] = 0x15F83BD7D24C8269LL;
    v19.m128_u64[0] = 0x16C4AA479B46DD69LL;
    v19.m128_u64[1] = 0x1FD6C38085F6A63BLL;
    v21.m128_u64[0] = 0xDC16F237A0F786F9uLL;
    v21.m128_u64[1] = 0x7AD85FB6B73EA206LL;
    v22.m128_u64[0] = 0x36A8CB29F221B41BLL;
    v22.m128_u64[1] = 0x1F8EE6A0E092C958LL;
    v18 = _mm_xor_ps(v18, v21);
    v19 = _mm_xor_ps(v19, v22);                 // Failed to read Original Code
    MainLogFunction(128, &unk_14016FCE0, &v18, v11, v17);
  }
  else
  {
    v18.m128_u64[0] = 0xA8369652CC9EE7BFuLL;
    v18.m128_u64[1] = 0x1BBB30DADB5F8269LL;
    v19.m128_u64[0] = 0x44C7A64C9F01D16FLL;
    v19.m128_u64[1] = 0x1F8EE6A0E092C321LL;
    v21.m128_u64[0] = 0xDC16F237A0F786F9uLL;
    v21.m128_u64[1] = 0x7AD85FB6B73EA206LL;
    v22.m128_u64[0] = 0x36A8CB29F221B41BLL;
    v22.m128_u64[1] = 0x1F8EE6A0E092C958LL;
    v18 = _mm_xor_ps(v18, v21);
    v19 = _mm_xor_ps(v19, v22);                 // Failed to allocate Memory
    MainLogFunction(128, &unk_14016FCE0, &v18);
  }
  v10 = 0;
  if ( (v16 ^ v23) != _security_cookie )
LABEL_4:
    __debugbreak();
  return v10;
}

__int64 __fastcall HookOnDllMain(void *ProcessID, _WORD *DllBase, __int64 Parameter)
{
  NTSTATUS v5; // eax
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // r14
  __int64 v8; // r15
  int v9; // ebp
  __int64 v10; // rax
  _BYTE v12[32]; // [rsp+0h] [rbp-128h] BYREF
  __int64 v13; // [rsp+28h] [rbp-100h]
  int v14; // [rsp+34h] [rbp-F4h] BYREF
  PEPROCESS Process; // [rsp+38h] [rbp-F0h] BYREF
  _BYTE v16[7]; // [rsp+44h] [rbp-E4h] BYREF
  char v17; // [rsp+4Bh] [rbp-DDh] BYREF
  int v18; // [rsp+4Ch] [rbp-DCh]
  __m128 FuncName; // [rsp+50h] [rbp-D8h] BYREF
  __m128 v20; // [rsp+60h] [rbp-C8h]
  __m128 v21; // [rsp+70h] [rbp-B8h]
  struct _KAPC_STATE ApcState; // [rsp+80h] [rbp-A8h] BYREF
  __m128 OutRVA; // [rsp+B0h] [rbp-78h] BYREF
  __m128 v24; // [rsp+C0h] [rbp-68h]
  __m128 v25; // [rsp+D0h] [rbp-58h]
  __int64 v26; // [rsp+E0h] [rbp-48h]

  Process = 0;
  v5 = PsLookupProcessByProcessId(ProcessID, &Process);
  if ( v5 >= 0 )
  {
    v13 = Parameter;
    KeStackAttachProcess(Process, &ApcState);
    FuncName.m128_u64[0] = 0xBF738658D2A7F1A3uLL;
    FuncName.m128_u64[1] = 0x16B92AC2C557F472LL;
    v20.m128_u64[0] = 0x36A8B25B9D4CD156LL;
    v20.m128_u64[1] = 0x1F8EE6A0E092C958LL;
    OutRVA.m128_u64[0] = 0xDC16F237A0F786F9uLL;
    OutRVA.m128_u64[1] = 0x7AD85FB6B73EA206LL;
    v24.m128_u64[0] = 0x36A8CB29F221B41BLL;
    v24.m128_u64[1] = 0x1F8EE6A0E092C958LL;
    FuncName = _mm_xor_ps(FuncName, OutRVA);    // GetModuleHandle
    v20 = _mm_xor_ps(v20, v24);
    if ( DllBase && *DllBase == 'ZM' )
    {
      FindFuncByOrdinalOrName(DllBase, &FuncName, &OutRVA);
      v6 = OutRVA.m128_u64[0];
    }
    else
    {
      v6 = 0;
    }
    FuncName.m128_u64[0] = 0x98729358EC85E2B5uLL;
    FuncName.m128_u64[1] = 0x7AD85FB6B73ECE6ALL;
    OutRVA.m128_u64[0] = 0xDC16F237A0F786F9uLL;
    OutRVA.m128_u64[1] = 0x7AD85FB6B73EA206LL;
    FuncName = _mm_xor_ps(FuncName, OutRVA);    // LoadLibraryA
    if ( DllBase && *DllBase == 'ZM' )
    {
      FindFuncByOrdinalOrName(DllBase, &FuncName, &OutRVA);
      v7 = OutRVA.m128_u64[0];
    }
    else
    {
      v7 = 0;
    }
    FuncName.m128_u64[0] = 0xB0578644C5A3F1A3uLL;
    FuncName.m128_u64[1] = 0x7AD85FB6B74AD063LL;
    OutRVA.m128_u64[0] = 0xDC16F237A0F786F9uLL;
    OutRVA.m128_u64[1] = 0x7AD85FB6B73EA206LL;
    FuncName = _mm_xor_ps(FuncName, OutRVA);    // DllMain
    if ( DllBase && *DllBase == 'ZM' )
    {
      FindFuncByOrdinalOrName(DllBase, &FuncName, &OutRVA);
      v8 = OutRVA.m128_u64[0];
      if ( !v7 )
      {
LABEL_24:
        FuncName.m128_u64[0] = 0xA8369652CC9EE7BFuLL;
        FuncName.m128_u64[1] = 0x1FAC3ED5D8528269LL;
        v20.m128_u64[0] = 0x52C9A4658045F83BLL;
        v20.m128_u64[1] = 0x1F8EE6A0CEFEA51CLL;
        OutRVA.m128_u64[0] = 0xDC16F237A0F786F9uLL;
        OutRVA.m128_u64[1] = 0x7AD85FB6B73EA206LL;
        v24.m128_u64[0] = 0x36A8CB29F221B41BLL;
        v24.m128_u64[1] = 0x1F8EE6A0E092C958LL;
        FuncName = _mm_xor_ps(FuncName, OutRVA);
        v20 = _mm_xor_ps(v20, v24);             // ZwSetInformationThread
        MainLogFunction(128, &unk_14016FCE0, &FuncName);
        if ( !v6 )
        {
LABEL_25:
          FuncName.m128_u64[0] = 0xA8369652CC9EE7BFuLL;
          FuncName.m128_u64[1] = 0x1FAC3ED5D8528269LL;
          v20.m128_u64[0] = 0x53DCA45BA255FA3BLL;
          v20.m128_u64[1] = 0x7EFB92D289C4BD3BLL;
          v21.m128_u64[0] = 0xC32C9394DEF429C1uLL;
          v21.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
          OutRVA.m128_u64[0] = 0xDC16F237A0F786F9uLL;
          OutRVA.m128_u64[1] = 0x7AD85FB6B73EA206LL;
          v24.m128_u64[0] = 0x36A8CB29F221B41BLL;
          v24.m128_u64[1] = 0x1F8EE6A0E092C958LL;
          v25.m128_u64[0] = 0xED55E1FBB39164ADuLL;
          v25.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
          FuncName = _mm_xor_ps(FuncName, OutRVA);
          v20 = _mm_xor_ps(v20, v24);
          v21 = _mm_xor_ps(v21, v25);           // HideFromDebugger
          MainLogFunction(128, &unk_14016FCE0, &FuncName);
          if ( !v8 )
            goto LABEL_26;
          goto LABEL_17;
        }
LABEL_16:
        if ( !v8 )
        {
LABEL_26:
          FuncName.m128_u64[0] = 0xA8369652CC9EE7BFuLL;
          FuncName.m128_u64[1] = 0x1FAC3ED5D8528269LL;
          v20.m128_u64[0] = 0x77DCB84CA656EE3BLL;
          v20.m128_u64[1] = 0x1F8EE68E94E0AC34LL;
          OutRVA.m128_u64[0] = 0xDC16F237A0F786F9uLL;
          OutRVA.m128_u64[1] = 0x7AD85FB6B73EA206LL;
          v24.m128_u64[0] = 0x36A8CB29F221B41BLL;
          v24.m128_u64[1] = 0x1F8EE6A0E092C958LL;
          FuncName = _mm_xor_ps(FuncName, OutRVA);
          v20 = _mm_xor_ps(v20, v24);           // SetThreadHideFromDebugger
          MainLogFunction(128, &unk_14016FCE0, &FuncName);
          v9 = STATUS_UNSUCCESSFUL;
          goto LABEL_27;
        }
LABEL_17:
        v9 = STATUS_UNSUCCESSFUL;
        if ( v6 != 0 && v7 != 0 && !PsGetProcessWow64Process(Process) )
        {
          v10 = SettingUpHooks_Maybe(DllBase, v7, v8, v6, v13);
          if ( v10 )
          {
            v17 = '\xE9';
            v14 = 0;
            OutRVA.m128_u64[0] = v8;
            FuncName.m128_u64[0] = 5;
            v18 = v10 - v8 - 5;
            v9 = sub_14006EAB0(-1, &OutRVA, &FuncName, 64, &v14);
            if ( v9 >= 0 )
            {
              sub_14006EA60(-1, v8, &v17, 5, v16);
              sub_14006EAB0(-1, &OutRVA, &FuncName, v14, &v14);
            }
          }
        }
LABEL_27:
        KeUnstackDetachProcess(&ApcState);
        ObfDereferenceObject(Process);
        if ( (v12 ^ v26) == _security_cookie )
          return v9;
LABEL_23:
        __debugbreak();
      }
    }
    else
    {
      v8 = 0;
      if ( !v7 )
        goto LABEL_24;
    }
    if ( !v6 )
      goto LABEL_25;
    goto LABEL_16;
  }
  v9 = v5;
  if ( (v12 ^ v26) != _security_cookie )
    goto LABEL_23;
  return v9;
}

char *__fastcall SettingUpHooks_Maybe(unsigned __int64 a1, int a2, __int64 a3, int a4, __int64 a5)
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]// Injecting shellcode, shellcode itself registering this
                                                // function as a handler to every hooked call

  memset(
    Dst,
    0,
    sizeof(Dst));
  v9 = AllocateMemory(0xFFFFFFFFFFFFFFFFLL, a1, 0x1000u);
  if ( v9 )
  {
    v10 = v9;
    v11 = RisePrivilegesToCallKernelFunc(-1, a3, &Dst[512], 8, 0);
    if ( v11 >= 0 )
    {
      v12 = _mm_loadl_epi64(a5);
      v13 = _mm_sub_epi16(v12, _mm_subs_epu16(v12, xmmword_140D85BD0));
      *&Dst[528] = _mm_cvtsi128_si32(v13);
      *&Dst[536] = v10 + 544;
      *&Dst[520] = a3;
      memove(&Dst[544], *(a5 + 8), _mm_extract_epi16(v13, 0));
      memove(Dst, Shellcode, 0xAAu);
      *&Dst[16] = 500;
      v14 = a4 - v10;
      *&Dst[65] = v14 - 69;
      *&Dst[71] = '\x01\xB5';
      *&Dst[83] = '\x01\xB1';
      *&Dst[96] = '\x01\xA0';
      *&Dst[124] = v14 - 128;
      *&Dst[131] = '\x05i';
      *&Dst[140] = '\x01\x80';
      *&Dst[147] = a2 - v10 - 151;
      *&Dst[165] = a3 - 169 - v10;
      v16[4] = 0;
      sub_14006EA60(-1);
      if ( (v16 ^ v24) != _security_cookie )
        goto LABEL_4;
      return v10;
    }
    v17.m128_u64[0] = 0xA8369652CC9EE7BFuLL;
    v17.m128_u64[1] = 0x15F83BD7D24C8269LL;
    v18.m128_u64[0] = 0x16C4AA479B46DD69LL;
    v18.m128_u64[1] = 0x15D6C38085F6A63BLL;
    v19.m128i_i64[0] = 0xED55E1FBB39164ADuLL;
    v19.m128i_i64[1] = 0xD12C83EA13AA49CAuLL;
    v21.m128_u64[0] = 0xDC16F237A0F786F9uLL;
    v21.m128_u64[1] = 0x7AD85FB6B73EA206LL;
    v22.m128_u64[0] = 0x36A8CB29F221B41BLL;
    v22.m128_u64[1] = 0x1F8EE6A0E092C958LL;
    v23.m128i_i64[0] = 0xED55E1FBB39164ADuLL;
    v23.m128i_i64[1] = 0xD12C83EA13AA49CAuLL;
    v17 = _mm_xor_ps(v17, v21);
    v18 = _mm_xor_ps(v18, v22);                 // Failed to read Original Code -X\n
    v19 = _mm_xor_si128(_mm_load_si128(&v19), v23);
    MainLogFunction(128, &unk_14016FCE0, &v17, v11);
  }
  else
  {
    v17.m128_u64[0] = 0xA8369652CC9EE7BFuLL;
    v17.m128_u64[1] = 0x1BBB30DADB5F8269LL;
    v18.m128_u64[0] = 0x44C7A64C9F01D16FLL;
    v18.m128_u64[1] = 0x1F8EE6A0E092C321LL;
    v21.m128_u64[0] = 0xDC16F237A0F786F9uLL;
    v21.m128_u64[1] = 0x7AD85FB6B73EA206LL;
    v22.m128_u64[0] = 0x36A8CB29F221B41BLL;
    v22.m128_u64[1] = 0x1F8EE6A0E092C958LL;
    v17 = _mm_xor_ps(v17, v21);                 // Failed to allocate Memory\n
    v18 = _mm_xor_si128(_mm_load_si128(&v18), v22);
    MainLogFunction(128, &unk_14016FCE0, &v17);
  }
  v10 = 0;
  if ( (v16 ^ v24) != _security_cookie )
LABEL_4:
    __debugbreak();
  return v10;
}

__int64 __fastcall AnalyzeAndHookRegisterWindowMessage(__int64 a1)
{
  __int64 result; // rax
  void *v2; // rsi
  __int64 *v3; // rbx
  __int64 v4; // rax
  __int64 v5; // rax
  __int64 v6; // rdx
  __int64 v7; // r8
  __int64 v8; // rcx
  void *v9; // rax
  int v10; // ecx
  __int64 v11; // rdx
  __int64 v12; // rcx
  __int64 v13; // [rsp+0h] [rbp-C8h] BYREF
  int v14; // [rsp+2Ch] [rbp-9Ch] BYREF
  __m128 v15; // [rsp+30h] [rbp-98h] BYREF
  __m128 v16; // [rsp+40h] [rbp-88h]
  __int64 v17; // [rsp+50h] [rbp-78h]
  _QWORD v18[2]; // [rsp+58h] [rbp-70h] BYREF
  __int128 v19; // [rsp+68h] [rbp-60h] BYREF
  __int64 v20; // [rsp+78h] [rbp-50h]
  __m128 v21; // [rsp+80h] [rbp-48h] BYREF
  __m128 v22; // [rsp+90h] [rbp-38h]
  __int64 v23; // [rsp+A8h] [rbp-20h]

  v21.m128_u64[0] = 0xA57EA243C5B0EBB4uLL;
  v21.m128_u64[1] = 0x1EBC1EDAD65DCB75LL;
  v22.m128_u64[0] = 0x36A8CB298152D169LL;
  v22.m128_u64[1] = 0x1F8EE6A0E092C958LL;
  v15.m128_u64[0] = 0xDC16F237A0F786F9uLL;
  v15.m128_u64[1] = 0x7AD85FB6B73EA206LL;
  v16.m128_u64[0] = 0x36A8CB29F221B41BLL;
  v16.m128_u64[1] = 0x1F8EE6A0E092C958LL;
  v21 = _mm_xor_ps(v21, v15);
  v22 = _mm_xor_ps(v22, v16);                   // NtUserRegisterWindowMessage
  result = sub_141166B20(a1, &v21);
  if ( !result )
    goto LABEL_17;
  v2 = result;
  v3 = AllocateMemoryWrapper(16);
  v3[1] = 0;
  v4 = AllocateMemoryWrapper(40);
  *v4 = v4;
  *(v4 + 8) = v4;
  *(v4 + 16) = v4;
  *(v4 + 24) = 257;
  *v3 = v4;
  qword_1411360E8 = v3;
  v18[1] = 0;
  v5 = AllocateMemoryWrapper(40);
  *v5 = v5;
  *(v5 + 8) = v5;
  *(v5 + 16) = v5;
  *(v5 + 24) = 257;
  v18[0] = v5;
  v19 = 0;
  v20 = 0;
  v16.m128_u64[1] = &KernelStart;
  v17 = qword_1411360E8;
  v15.m128_u64[1] = 200;
  v16.m128_i32[0] = 32;
  sub_14001A760(v2);
  v15.m128_u64[0] = v2;
  v21.m128_i32[0] = 0;
  v14 = 1280;
  v6 = *(&v19 + 1);
  if ( *(&v19 + 1) != v20 )
  {
    **(&v19 + 1) = v2;
    *(v6 + 8) = 1280;
    *(v6 + 16) = 0;
    v7 = *(&v19 + 1) + 24LL;
    *(&v19 + 1) = v7;
    v8 = v19;
    if ( v7 == v19 )
      goto LABEL_9;
    do
    {
LABEL_8:
      v9 = *(v7 - 24);
      v10 = *(v7 - 8);
      *(&v19 + 1) = v7 - 24;
      KernelHook(v9, v10);
      v7 = *(&v19 + 1);
      v8 = v19;
    }
    while ( *(&v19 + 1) != v19 );
    goto LABEL_9;
  }
  std::vector(&v19, DWORD2(v19), &v15, &v14, &v21);
  v7 = *(&v19 + 1);
  v8 = v19;
  if ( *(&v19 + 1) != v19 )
    goto LABEL_8;
LABEL_9:
  qword_14115DC78 = v15.m128_u64[0];
  if ( v8 )
  {
    v11 = v20 - v8;
    if ( (v20 - v8) >= 0x1000 )
    {
      if ( (v8 - *(v8 - 8) - 8) >= 0x20 )
        KeBugCheckWrapper();
      v11 += 39;
      v8 = *(v8 - 8);
    }
    FreeWrapper(v8, v11);
    v19 = 0;
    v20 = 0;
  }
  v12 = v18[0];
  if ( !*(*(v18[0] + 8LL) + 25LL) )
  {
    sub_1400193B0(*(v18[0] + 8LL), v18, v18);
    v12 = v18[0];
  }
  result = FreeWrapper(v12, 40);
LABEL_17:
  if ( (&v13 ^ v23) != _security_cookie )
    __debugbreak();
  return result;
}

__int64 __fastcall HookMmProbeAndLockPages(__int64 a1)
{
  __int64 result; // rax
  unsigned __int64 v2; // rbx
  __int64 *v3; // rsi
  __int64 v4; // rax
  __int64 v5; // rax
  __int64 i; // rcx
  __int64 v7; // r8
  void *v8; // rax
  int v9; // ecx
  __int64 v10; // rdx
  __int64 v11; // rcx
  __int64 v12; // [rsp+0h] [rbp-C8h] BYREF
  int v13; // [rsp+2Ch] [rbp-9Ch] BYREF
  __m128 v14; // [rsp+30h] [rbp-98h] BYREF
  __m128 v15; // [rsp+40h] [rbp-88h]
  __int64 v16; // [rsp+50h] [rbp-78h]
  _QWORD v17[2]; // [rsp+58h] [rbp-70h] BYREF
  __int128 v18; // [rsp+68h] [rbp-60h] BYREF
  __int64 v19; // [rsp+78h] [rbp-50h]
  __m128 v20; // [rsp+80h] [rbp-48h] BYREF
  __m128 v21; // [rsp+90h] [rbp-38h]
  __int64 v22; // [rsp+A8h] [rbp-20h]

  v20.m128_u64[0] = 0x9D739058D2A7EBB4uLL;
  v20.m128_u64[1] = 0x1B8834D5D872C668LL;
  v21.m128_u64[0] = 0x36A8CB29F252D17CLL;
  v21.m128_u64[1] = 0x1F8EE6A0E092C958LL;
  v14.m128_u64[0] = 0xDC16F237A0F786F9uLL;
  v14.m128_u64[1] = 0x7AD85FB6B73EA206LL;
  v15.m128_u64[0] = 0x36A8CB29F221B41BLL;
  v15.m128_u64[1] = 0x1F8EE6A0E092C958LL;
  v20 = _mm_xor_ps(v20, v14);
  v21 = _mm_xor_ps(v21, v15);                   // MmProbeAndLockPages
  result = GetProcAddrCustom(a1, &v20);
  if ( result )
  {
    v2 = result;
    v3 = AllocateMemoryWrapper(16);
    v3[1] = 0;
    v4 = AllocateMemoryWrapper(40);
    *v4 = v4;
    *(v4 + 8) = v4;
    *(v4 + 16) = v4;
    *(v4 + 24) = 257;
    *v3 = v4;
    qword_1411360E0 = v3;
    v17[1] = 0;
    v5 = AllocateMemoryWrapper(40);
    *v5 = v5;
    *(v5 + 8) = v5;
    *(v5 + 16) = v5;
    *(v5 + 24) = 257;
    v17[0] = v5;
    v18 = 0;
    v19 = 0;
    v16 = qword_1411360E0;
    v15.m128_u64[1] = &KernelStart;
    v14.m128_u64[1] = 3000;
    v14.m128_u64[0] = v2;
    v15.m128_i32[0] = 32;
    v20.m128_i32[0] = 0;
    v13 = 2048;
    std::vector(&v18, 0, &v14, &v13, &v20);
    v7 = *(&v18 + 1);
    for ( i = v18; *(&v18 + 1) != v18; i = v18 )
    {
      v8 = *(v7 - 24);
      v9 = *(v7 - 8);
      *(&v18 + 1) = v7 - 24;
      KernelHook(v8, v9);
      v7 = *(&v18 + 1);
    }
    qword_14115DC80 = v14.m128_u64[0];
    if ( i )
    {
      v10 = v19 - i;
      if ( (v19 - i) >= 0x1000 )
      {
        if ( (i - *(i - 8) - 8) >= 0x20 )
          KeBugCheckWrapper();
        v10 += 39;
        i = *(i - 8);
      }
      FreeWrapper(i, v10);
      v18 = 0;
      v19 = 0;
    }
    v11 = v17[0];
    if ( !*(*(v17[0] + 8LL) + 25LL) )
    {
      sub_1400193B0(*(v17[0] + 8LL), v17, v17);
      v11 = v17[0];
    }
    result = FreeWrapper(v11, 40);
  }
  if ( (&v12 ^ v22) != _security_cookie )
    __debugbreak();
  return result;
}

unsigned __int64 __fastcall HookMmGetSystemRoutineAddress(__int64 a1)
{
  unsigned __int64 result; // rax
  unsigned __int64 v2; // rbx
  _QWORD *v3; // rsi
  _QWORD *v4; // rax
  _QWORD *v5; // rax
  __int64 i; // rcx
  __int64 v7; // r8
  char *v8; // rax
  __int64 v9; // rdx
  int v10; // ecx
  __int64 v11; // rdx
  __int64 v12; // rcx
  __int64 v13; // [rsp+0h] [rbp-C8h] BYREF
  int v14; // [rsp+2Ch] [rbp-9Ch] BYREF
  __m128 v15; // [rsp+30h] [rbp-98h] BYREF
  __m128 v16; // [rsp+40h] [rbp-88h]
  __int64 v17; // [rsp+50h] [rbp-78h]
  _QWORD v18[2]; // [rsp+58h] [rbp-70h] BYREF
  __int128 v19; // [rsp+68h] [rbp-60h] BYREF
  __int64 v20; // [rsp+78h] [rbp-50h]
  __m128 v21; // [rsp+80h] [rbp-48h] BYREF
  __m128 v22; // [rsp+90h] [rbp-38h]
  __int64 v23; // [rsp+A8h] [rbp-20h]

  v21.m128_u64[0] = 0xB5408B47CFB4EBB4uLL;
  v21.m128_u64[1] = 0x17BD12DAD64BD674LL;
  v22.m128_u64[0] = 0x36A8CB29F258C674LL;
  v22.m128_u64[1] = 0x1F8EE6A0E092C958LL;
  v15.m128_u64[0] = 0xDC16F237A0F786F9uLL;
  v15.m128_u64[1] = 0x7AD85FB6B73EA206LL;
  v16.m128_u64[0] = 0x36A8CB29F221B41BLL;
  v16.m128_u64[1] = 0x1F8EE6A0E092C958LL;
  v21 = _mm_xor_ps(v21, v15);
  v22 = _mm_xor_ps(v22, v16);                   // MmGetSystemRoutineAddress
  result = GetProcAddrCustom(a1, &v21);
  if ( result )
  {
    v2 = result;
    v3 = AllocateMemoryWrapper(16);
    v3[1] = 0;
    v4 = AllocateMemoryWrapper(40);
    *v4 = v4;
    v4[1] = v4;
    v4[2] = v4;
    *(v4 + 12) = 257;
    *v3 = v4;
    qword_1411360F0 = v3;
    v18[1] = 0;
    v5 = AllocateMemoryWrapper(40);
    *v5 = v5;
    v5[1] = v5;
    v5[2] = v5;
    *(v5 + 12) = 257;
    v18[0] = v5;
    v19 = 0;
    v20 = 0;
    v17 = qword_1411360F0;
    v16.m128_u64[1] = &KernelStart;
    v15.m128_u64[1] = 500;
    v15.m128_u64[0] = v2;
    v16.m128_i32[0] = 32;
    v21.m128_i32[0] = 0;
    v14 = 1280;
    std::vector(&v19, 0, &v15, &v14, &v21);
    v7 = *(&v19 + 1);
    for ( i = v19; *(&v19 + 1) != v19; i = v19 )
    {
      v8 = *(v7 - 24);
      v9 = *(v7 - 16);
      v10 = *(v7 - 8);
      *(&v19 + 1) = v7 - 24;
      KernelHook(v8, v9, HandlerForHook, &v15, v10);
      v7 = *(&v19 + 1);
    }
    qword_14115DC88 = v15.m128_u64[0];
    if ( i )
    {
      v11 = v20 - i;
      if ( (v20 - i) >= 0x1000 )
      {
        if ( (i - *(i - 8) - 8) >= 0x20 )
          KeBugCheckWrapper();
        v11 += 39;
        i = *(i - 8);
      }
      FreeWrapper(i, v11);
      v19 = 0;
      v20 = 0;
    }
    v12 = v18[0];
    if ( !*(*(v18[0] + 8LL) + 25LL) )
    {
      sub_1400193B0(*(v18[0] + 8LL), v18, v18);
      v12 = v18[0];
    }
    result = FreeWrapper(v12, 40);
  }
  if ( (&v13 ^ v23) != _security_cookie )
    __debugbreak();
  return result;
}

char *__fastcall HookMmAdjustWorkingSetSize(__int64 a1)
{
  char *result; // rax
  _QWORD *v2; // rsi
  _QWORD *v3; // rax
  _QWORD *v4; // rax
  __int64 i; // rcx
  __int64 v6; // r8
  char *v7; // rax
  __int64 v8; // rdx
  int v9; // ecx
  __int64 v10; // rdx
  unsigned __int64 v11; // rcx
  _BYTE v12[32]; // [rsp+0h] [rbp-F8h] BYREF
  int v13; // [rsp+2Ch] [rbp-CCh] BYREF
  __m128 v14; // [rsp+30h] [rbp-C8h] BYREF
  __m128 v15; // [rsp+40h] [rbp-B8h]
  __m128 v16; // [rsp+50h] [rbp-A8h] BYREF
  __int64 v17; // [rsp+60h] [rbp-98h]
  __int128 v18; // [rsp+68h] [rbp-90h] BYREF
  __int64 v19; // [rsp+78h] [rbp-80h]
  __m128 v20; // [rsp+80h] [rbp-78h] BYREF
  __m128 v21; // [rsp+90h] [rbp-68h]
  __m128 v22; // [rsp+A0h] [rbp-58h]
  __int64 v23; // [rsp+B8h] [rbp-40h]

  v20.m128_u64[0] = 0xA865875DC4B6EBB4uLL;
  v20.m128_u64[1] = 0x29BF31DFDC4CCD51LL;
  v21.m128_u64[0] = 0x36A8AE539B72C07ELL;
  v21.m128_u64[1] = 0x1F8EE6A0E092C958LL;
  v14.m128_u64[0] = 0xDC16F237A0F786F9uLL;
  v14.m128_u64[1] = 0x7AD85FB6B73EA206LL;
  v15.m128_u64[0] = 0x36A8CB29F221B41BLL;
  v15.m128_u64[1] = 0x1F8EE6A0E092C958LL;
  v20 = _mm_xor_ps(v20, v14);
  v21 = _mm_xor_ps(v21, v15);                   // MmAdjustWorkingSetSize
  result = GetProcAddrCustom(a1, &v20);
  if ( !result )
    goto LABEL_13;
  KernelHook2(result, 80, sub_140017D80, 0); // the same with KernelHook
  if ( qword_14115DC98 )
  {
    v2 = AllocateMemoryWrapper(16);
    v2[1] = 0;
    v3 = AllocateMemoryWrapper(40);
    *v3 = v3;
    v3[1] = v3;
    v3[2] = v3;
    *(v3 + 12) = 257;
    *v2 = v3;
    qword_141136150 = v2;
    v17 = 0;
    v4 = AllocateMemoryWrapper(40);
    *v4 = v4;
    v4[1] = v4;
    v4[2] = v4;
    *(v4 + 12) = 257;
    v16.m128_u64[1] = v4;
    v18 = 0;
    v19 = 0;
    v14.m128_u64[0] = qword_14115DC98;
    v15.m128_u64[1] = &KernelStart;
    v16.m128_u64[0] = qword_141136150;
    v14.m128_u64[1] = 800;
    v15.m128_i32[0] = 32;
    v20.m128_i32[0] = 0;
    v13 = 2048;
    std::vector(&v18, 0, &v14, &v13, &v20);
    v6 = *(&v18 + 1);
    for ( i = v18; *(&v18 + 1) != v18; i = v18 )
    {
      v7 = *(v6 - 24);
      v8 = *(v6 - 16);
      v9 = *(v6 - 8);
      *(&v18 + 1) = v6 - 24;
      KernelHook(v7, v8, HandlerForHook, &v14, v9);
      v6 = *(&v18 + 1);
    }
    if ( i )
    {
      v10 = v19 - i;
      if ( (v19 - i) >= 0x1000 )
      {
        if ( (i - *(i - 8) - 8) >= 0x20 )
          KeBugCheckWrapper();
        v10 += 39;
        i = *(i - 8);
      }
      FreeWrapper(i, v10);
      v18 = 0;
      v19 = 0;
    }
    v11 = v16.m128_u64[1];
    if ( !*(*(v16.m128_u64[1] + 8) + 25LL) )
    {
      sub_1400193B0(*(v16.m128_u64[1] + 8), &v16.m128_u16[4], &v16.m128_u16[4]);
      v11 = v16.m128_u64[1];
    }
    result = FreeWrapper(v11, 40);
LABEL_13:
    if ( (v12 ^ v23) == _security_cookie )
      return result;
LABEL_16:
    __debugbreak();
  }
  v20.m128_u64[0] = 0xA865875DC4B6EBB4uLL;
  v20.m128_u64[1] = 0x29BF31DFDC4CCD51LL;
  v21.m128_u64[0] = 0x4EEDAE539B72C07ELL;
  v21.m128_u64[1] = 0x6AE1808094FDA778LL;
  v22.m128_u64[0] = 0xED55E1FBB39100C3uLL;
  v22.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
  v14.m128_u64[0] = 0xDC16F237A0F786F9uLL;
  v14.m128_u64[1] = 0x7AD85FB6B73EA206LL;
  v15.m128_u64[0] = 0x36A8CB29F221B41BLL;
  v15.m128_u64[1] = 0x1F8EE6A0E092C958LL;
  v16.m128_u64[0] = 0xED55E1FBB39164ADuLL;
  v16.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
  v20 = _mm_xor_ps(v20, v14);
  v21 = _mm_xor_ps(v21, v15);
  v22 = _mm_xor_ps(v22, v16);                   // MmAdjustWorkingSetSizeEx Not Found
  result = MainLogFunction(128, &unk_14016FCE0, &v20);
  if ( (v12 ^ v23) != _security_cookie )
    goto LABEL_16;
  return result;
}

void HookMmWorkingSetInternal()
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  v0 = qword_14115DD08;
  if ( qword_14115DD08 )
  {
    v1 = AllocateMemoryWrapper(16);
    v1[1] = 0;
    v2 = AllocateMemoryWrapper(40);
    *v2 = v2;
    v2[1] = v2;
    v2[2] = v2;
    *(v2 + 12) = 257;
    *v1 = v2;
    qword_141136158 = v1;
    v18[1] = 0;
    v3 = AllocateMemoryWrapper(40);
    *v3 = v3;
    v3[1] = v3;
    v3[2] = v3;
    *(v3 + 12) = 257;
    v18[0] = v3;
    v19 = 0;
    v20 = 0;
    v17 = qword_141136158;
    v16 = &KernelStart;
    v14[1] = 800;
    v14[0] = v0;
    v15 = 32;
    v13 = 0;
    v12 = 1280;
    std::vector(&v19, 0, v14, &v12, &v13);
    v5 = *(&v19 + 1);
    for ( i = v19; *(&v19 + 1) != v19; i = v19 )
    {
      v6 = *(v5 - 24);
      v7 = *(v5 - 16);
      v8 = *(v5 - 8);
      *(&v19 + 1) = v5 - 24;
      KernelHook(v6, v7, HandlerForHook, v14, v8);
      v5 = *(&v19 + 1);
    }
    if ( i )
    {
      v9 = v20 - i;
      if ( (v20 - i) >= 0x1000 )
      {
        if ( (i - *(i - 8) - 8) >= 0x20 )
          KeBugCheckWrapper();
        v9 += 39;
        i = *(i - 8);
      }
      FreeWrapper(i, v9);
      v19 = 0;
      v20 = 0;
    }
    v10 = v18[0];
    if ( !*(*(v18[0] + 8LL) + 25LL) )
    {
      sub_1400193B0(*(v18[0] + 8LL), v18, v18);
      v10 = v18[0];
    }
    FreeWrapper(v10, 40);
  }
  if ( (&v11 ^ v21) != _security_cookie )
    __debugbreak();
}

void HookWorkingSetInternalSubroutines()
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  v0 = qword_14115DD10;
  if ( qword_14115DD10 )
  {
    v1 = AllocateMemoryWrapper(16);
    v1[1] = 0;
    v2 = AllocateMemoryWrapper(40);
    *v2 = v2;
    v2[1] = v2;
    v2[2] = v2;
    *(v2 + 12) = 257;
    *v1 = v2;
    qword_141136160 = v1;
    v31 = 0;
    v3 = AllocateMemoryWrapper(40);
    *v3 = v3;
    v3[1] = v3;
    v3[2] = v3;
    *(v3 + 12) = 257;
    v30 = v3;
    v32 = 0;
    v33 = 0;
    v29 = qword_141136160;
    v28 = &KernelStart;
    v26 = 800;
    v25 = v0;
    v27 = 32;
    v24 = 0;
    v23 = 256;
    std::vector(&v32, 0, &v25, &v23, &v24);
    v5 = *(&v32 + 1);
    for ( i = v32; *(&v32 + 1) != v32; i = v32 )
    {
      v6 = *(v5 - 24);
      v7 = *(v5 - 16);
      v8 = *(v5 - 8);
      *(&v32 + 1) = v5 - 24;
      KernelHook(v6, v7, HandlerForHook, &v25, v8);
      v5 = *(&v32 + 1);
    }
    if ( i )
    {
      v9 = v33 - i;
      if ( (v33 - i) >= 0x1000 )
      {
        if ( (i - *(i - 8) - 8) >= 0x20 )
          goto LABEL_25;
        v9 += 39;
        i = *(i - 8);
      }
      FreeWrapper(i, v9);
      v32 = 0;
      v33 = 0;
    }
    v10 = v30;
    if ( !*(v30[1] + 25LL) )
    {
      sub_1400193B0(v30[1], &v30, &v30);
      v10 = v30;
    }
    FreeWrapper(v10, 40);
  }
  v11 = qword_14115DD18;
  if ( !qword_14115DD18 )
    goto LABEL_23;
  v12 = AllocateMemoryWrapper(16);
  v12[1] = 0;
  v13 = AllocateMemoryWrapper(40);
  *v13 = v13;
  v13[1] = v13;
  v13[2] = v13;
  *(v13 + 12) = 257;
  *v12 = v13;
  qword_141136168 = v12;
  v31 = 0;
  v14 = AllocateMemoryWrapper(40);
  *v14 = v14;
  v14[1] = v14;
  v14[2] = v14;
  *(v14 + 12) = 257;
  v30 = v14;
  v32 = 0;
  v33 = 0;
  v29 = qword_141136168;
  v28 = &KernelStart;
  v26 = 800;
  v25 = v11;
  v27 = 32;
  v24 = 0;
  v23 = 256;
  std::vector(&v32, 0, &v25, &v23, &v24);
  v16 = *(&v32 + 1);
  for ( j = v32; *(&v32 + 1) != v32; j = v32 )
  {
    v17 = *(v16 - 24);
    v18 = *(v16 - 16);
    v19 = *(v16 - 8);
    *(&v32 + 1) = v16 - 24;
    KernelHook(v17, v18, HandlerForHook, &v25, v19);
    v16 = *(&v32 + 1);
  }
  if ( j )
  {
    v20 = v33 - j;
    if ( (v33 - j) < 0x1000 )
    {
LABEL_19:
      FreeWrapper(j, v20);
      v32 = 0;
      v33 = 0;
      goto LABEL_20;
    }
    if ( (j - *(j - 8) - 8) < 0x20 )
    {
      v20 += 39;
      j = *(j - 8);
      goto LABEL_19;
    }
LABEL_25:
    KeBugCheckWrapper();
  }
LABEL_20:
  v21 = v30;
  if ( !*(v30[1] + 25LL) )
  {
    sub_1400193B0(v30[1], &v30, &v30);
    v21 = v30;
  }
  FreeWrapper(v21, 40);
LABEL_23:
  if ( (&v22 ^ v34) != _security_cookie )
    __debugbreak();
}

void HookWorkingSetLargeSubroutine()
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  v0 = qword_14115DD20;
  if ( qword_14115DD20 )
  {
    v1 = AllocateMemoryWrapper(16);
    v1[1] = 0;
    v2 = AllocateMemoryWrapper(40);
    *v2 = v2;
    v2[1] = v2;
    v2[2] = v2;
    *(v2 + 12) = 257;
    *v1 = v2;
    qword_141136170 = v1;
    v18[1] = 0;
    v3 = AllocateMemoryWrapper(40);
    *v3 = v3;
    v3[1] = v3;
    v3[2] = v3;
    *(v3 + 12) = 257;
    v18[0] = v3;
    v19 = 0;
    v20 = 0;
    v17 = qword_141136170;
    v16 = &KernelStart;
    v14[1] = 5000;
    v14[0] = v0;
    v15 = 32;
    v13 = 0;
    v12 = 0x2000;
    std::vector(&v19, 0, v14, &v12, &v13);
    v5 = *(&v19 + 1);
    for ( i = v19; *(&v19 + 1) != v19; i = v19 )
    {
      v6 = *(v5 - 24);
      v7 = *(v5 - 16);
      v8 = *(v5 - 8);
      *(&v19 + 1) = v5 - 24;
      KernelHook(v6, v7, HandlerForHook, v14, v8);
      v5 = *(&v19 + 1);
    }
    if ( i )
    {
      v9 = v20 - i;
      if ( (v20 - i) >= 0x1000 )
      {
        if ( (i - *(i - 8) - 8) >= 0x20 )
          KeBugCheckWrapper();
        v9 += 39;
        i = *(i - 8);
      }
      FreeWrapper(i, v9);
      v19 = 0;
      v20 = 0;
    }
    v10 = v18[0];
    if ( !*(*(v18[0] + 8LL) + 25LL) )
    {
      sub_1400193B0(*(v18[0] + 8LL), v18, v18);
      v10 = v18[0];
    }
    FreeWrapper(v10, 40);
  }
  if ( (&v11 ^ v21) != _security_cookie )
    __debugbreak();
}

__int64 KernelHooksCheck()
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  v11 = 0x6A7C8285107EEED3LL;
  *SourceString = 0x6A7C8285107EEED3LL;
  *&SourceString[4] = 0x5487E52015786EB0LL;
  v17.m128_u64[0] = 0x5CF745E672E0D506LL;
  v17.m128_u64[1] = 0x91C155A82F94D665uLL;
  v18.m128_u64[0] = 0x7B7A72F66E421B3CLL;
  v18.m128_u64[1] = 0xAB4E09F57AA53C04uLL;
  v19.m128_u64[0] = 0x51197328FADC5161LL;
  v19.m128_u64[1] = 0x787531FF31C85286LL;
  v9 = 0x6A0F82FC102DEE8FLL;
  Object.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
  v8 = 0x54D5E54D151D6EC4LL;
  Object.m128_u64[1] = 0x54D5E54D151D6EC4LL;
  v7 = 0x5CAB4592728FD569LL;
  v21.m128_u64[0] = 0x5CAB4592728FD569LL;
  v6 = 0x919655DB2FEDD636uLL;
  v21.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v10 = 0x7B4E72C06E151B73LL;
  v22.m128_u64[0] = 0x7B4E72C06E151B73LL;
  v5 = 0xAB2A09817ACB3C58uLL;
  v22.m128_u64[1] = 0xAB2A09817ACB3C58uLL;
  v23.m128_u64[0] = 0x517D7306FAB0510DLL;
  v23.m128_u64[1] = 0x787531FF31A452EALL;
  *SourceString = _mm_xor_ps(*SourceString, Object);
  v17 = _mm_xor_ps(v17, v21);
  v18 = _mm_xor_ps(v18, v22);
  v19 = _mm_xor_ps(v19, v23);                   // \SystemRoot\System32\ntoskrnl.exe
  RtlInitUnicodeString(&DestinationString, SourceString);
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = 0;
  ObjectAttributes.Attributes = 576;
  ObjectAttributes.ObjectName = &DestinationString;
  *&ObjectAttributes.SecurityDescriptor = 0;
  v0 = ZwOpenFile(&qword_14115DF08, 0x120089u, &ObjectAttributes, &IoStatusBlock, 3u, 0x20u);
  if ( v0 == STATUS_SHARING_VIOLATION )
    v0 = ZwOpenFile(&qword_14115DF08, 0x120089u, &ObjectAttributes, &IoStatusBlock, 1u, 0x20u);
  if ( v0 < 0 )
  {
    *SourceString = 0xE7BECDC7E489EE0LL;
    wmemcpy(&SourceString[4], L"ʨ✮荭㶴뀅勫⳥㓟៝喃醖", 12);
    Object.m128_u64[0] = v9;
    Object.m128_u64[1] = v8;
    v21.m128_u64[0] = v7;
    v21.m128_u64[1] = v6;
    *SourceString = _mm_xor_ps(*SourceString, Object);
    v17 = _mm_xor_ps(v17, v21);                 // "Failed to open NTOSKRNL: %08X\n"
    goto LABEL_20;
  }
  ObjectAttributes.ObjectName = 0;
  v0 = ZwCreateSection(&SectionHandle, 0xF001Fu, &ObjectAttributes, 0, 2u, 0x1000000u, qword_14115DF08);
  if ( v0 < 0 )
  {
    *SourceString = 0x42FE78871489CECLL;
    *&SourceString[4] = 0x27F5D77E79710AB0LL;
    v17.m128_u64[0] = 0x3A8B2BFD1BFBB60CLL;
    v17.m128_u64[1] = 0xF8E175BF4A81BF57uLL;
    v18.m128_u64[0] = 0x7B164AF04B357307LL;
    v18.m128_u64[1] = v5;
    Object.m128_u64[0] = v9;
    Object.m128_u64[1] = v8;
    v21.m128_u64[0] = v7;
    v21.m128_u64[1] = v6;
    v22.m128_u64[0] = v10;
    v22.m128_u64[1] = v5;
LABEL_19:
    *SourceString = _mm_xor_ps(*SourceString, Object);
    v17 = _mm_xor_ps(v17, v21);
    v18 = _mm_xor_ps(v18, v22);                 // Failed to create NTOSKRNL section: %08X\n
LABEL_20:
    v1 = v0;
    MainLogFunction(128, &unk_14016FCE0, SourceString, v0);
    if ( (v4 ^ v24) != _security_cookie )
      goto LABEL_24;
    return v1;
  }
  v0 = ZwMapViewOfSection(
         SectionHandle,
         0xFFFFFFFFFFFFFFFFLL,
         &qword_14115DF18,
         0,
         0,
         0,
         &ViewSize,
         ViewShare,
         0x100000u,
         2u);
  if ( v0 < 0 )
  {
    wmemcpy(SourceString, L"迢そ٫嶨㔯耾₶먀勡⓴ヂ뉓壍↲뇾⭖㘭狀筎", 20);
    v18.m128_u64[1] = v5;
    Object.m128_u64[0] = v9;
    Object.m128_u64[1] = v8;
    v21.m128_u64[0] = v7;
    v21.m128_u64[1] = v6;
    v22.m128_u64[0] = v10;
    v22.m128_u64[1] = v5;
    goto LABEL_19;
  }
  qword_14115DF50 = ExAllocatePoolWithTag(PagedPool, 0x208u, 0x53425458u);
  if ( qword_14115DF50 )
  {
    dword_14115DF48 = 34078720;
    Object.m128_u64[0] = 0;
    if ( ObReferenceObjectByHandle(qword_14115DF08, 0x120089u, IoFileObjectType, 0, &Object, 0) >= 0 )
    {
      sub_140044000(Object.m128_i64[0], &dword_14115DF48);
      ObfDereferenceObject(Object.m128_u64[0]);
    }
  }
  *SourceString = v11;
  *&SourceString[4] = 0x5487E52015786EB0LL;
  v17.m128_u64[0] = 0x5CF745E672E0D506LL;
  v17.m128_u64[1] = 0x91E255A82F94D665uLL;
  v18.m128_u64[0] = 0x7B7C72F36E781B16LL;
  v18.m128_u64[1] = 0xAB4E09F57AA53C04uLL;
  v19.m128_u64[0] = 0x51197328FADC5161LL;
  v19.m128_u64[1] = 0x787531FF31C85286LL;
  Object.m128_u64[0] = v9;
  Object.m128_u64[1] = v8;
  v21.m128_u64[0] = v7;
  v21.m128_u64[1] = v6;
  v22.m128_u64[0] = v10;
  v22.m128_u64[1] = v5;
  v23.m128_u64[0] = 0x517D7306FAB0510DLL;
  v23.m128_u64[1] = 0x787531FF31A452EALL;
  *SourceString = _mm_xor_ps(*SourceString, Object);
  v17 = _mm_xor_ps(v17, v21);
  v18 = _mm_xor_ps(v18, v22);
  v19 = _mm_xor_ps(v19, v23);                   // Failed to map NTOSKRNL view: %08X\n
  RtlInitUnicodeString(&DestinationString, SourceString);
  ObjectAttributes.Length = 48;
  ObjectAttributes.RootDirectory = 0;
  ObjectAttributes.Attributes = 576;
  ObjectAttributes.ObjectName = &DestinationString;
  *&ObjectAttributes.SecurityDescriptor = 0;
  v0 = ZwOpenFile(&Handle, 0x120089u, &ObjectAttributes, &IoStatusBlock, 3u, 0x20u);
  if ( v0 == STATUS_SHARING_VIOLATION )
    v0 = ZwOpenFile(&Handle, 0x120089u, &ObjectAttributes, &IoStatusBlock, 1u, 0x20u);
  if ( v0 < 0 )
  {
    *SourceString = 0x1E6EECDC7E489EE0LL;
    *&SourceString[4] = 0x38B19123357818ADLL;
    v17.m128_u64[0] = 0x38CE29FB13E9F505LL;
    v17.m128_u64[1] = 0xA1B375B35B84A116uLL;
    v18.m128_u64[0] = 0x7B4E72C06E15434BLL;
    v18.m128_u64[1] = v5;
    Object.m128_u64[0] = v9;
    Object.m128_u64[1] = v8;
    v21.m128_u64[0] = v7;
    v21.m128_u64[1] = v6;
    v22.m128_u64[0] = v10;
    v22.m128_u64[1] = v5;
    goto LABEL_19;
  }
  v1 = v0;
  qword_14115DF40 = ExAllocatePoolWithTag(PagedPool, 0x208u, 0x53425458u);
  if ( qword_14115DF40 )
  {
    dword_14115DF38 = 34078720;
    Object.m128_u64[0] = 0;
    v2 = ObReferenceObjectByHandle(Handle, 0x120089u, IoFileObjectType, 0, &Object, 0);
    if ( v2 < 0 )
    {
      v1 = v2;
    }
    else
    {
      v1 = sub_140044000(Object.m128_i64[0], &dword_14115DF38);
      ObfDereferenceObject(Object.m128_u64[0]);
    }
  }
  ZwClose(Handle);
  if ( (v4 ^ v24) != _security_cookie )
LABEL_24:
    JUMPOUT(0x141202341LL);
  return v1;
}

void InitCodeIntegrityMonitoring()
{
  char *ProcAddrCustom; // rax
  _BYTE v1[32]; // [rsp+0h] [rbp-B8h] BYREF
  __int64 v2; // [rsp+20h] [rbp-98h] BYREF
  __int64 v3; // [rsp+28h] [rbp-90h] BYREF
  __m128 v4; // [rsp+30h] [rbp-88h] BYREF
  __m128 v5; // [rsp+40h] [rbp-78h]
  __m128 v6; // [rsp+50h] [rbp-68h] BYREF
  __m128 v7; // [rsp+60h] [rbp-58h]
  __m128 v8; // [rsp+70h] [rbp-48h]
  __m128 v9; // [rsp+80h] [rbp-38h]
  __int64 v10; // [rsp+90h] [rbp-28h]

  v3 = 0;
  v2 = 0;
  if ( BuildNumber < 1536 )
  {
LABEL_5:
    if ( (v1 ^ v10) == _security_cookie )
      return;
LABEL_11:
    __debugbreak();
  }
  v6.m128_u64[0] = 0xDC169E5BC4D9EF9AuLL;
  v6.m128_u64[1] = 0x7AD85FB6B73EA206LL;
  v8.m128_u64[0] = 0xDC16F237A0F786F9uLL;
  v8.m128_u64[1] = 0x7AD85FB6B73EA206LL;
  v6 = _mm_xor_ps(v6, v8);                      // CI.dll
  if ( sub_14006F310(&v6, &v3, &v2) < 0 )
  {
    v6.m128_u64[0] = 0xB2369E5BC4D9EF9AuLL;
    v6.m128_u64[1] = 0x1EB62AD9D11ED669LL;
    v7.m128_u64[0] = 0x36A8CB29F221B41BLL;
    v7.m128_u64[1] = 0x1F8EE6A0E092C958LL;
    v8.m128_u64[0] = 0xDC16F237A0F786F9uLL;
    v8.m128_u64[1] = 0x7AD85FB6B73EA206LL;
LABEL_9:
    v9.m128_u64[0] = 0x36A8CB29F221B41BLL;
    v9.m128_u64[1] = 0x1F8EE6A0E092C958LL;
    v6 = _mm_xor_ps(v6, v8);
    v7 = _mm_xor_ps(v7, v9);                    // Failed to find CI.dll base
    MainLogFunction(128, &unk_14016FCE0, &v6);
    goto LABEL_10;
  }
  ProcAddrCustom = GetProcAddrCustom(v3, "CiInitialize");
  if ( !ProcAddrCustom )
  {
    v6.m128_u64[0] = 0xBD7F865ECEBEEFBAuLL;
    v6.m128_u64[1] = 0xEB73196D244CB6ALL;
    v7.m128_u64[0] = 0x36A8AF47874ED23BLL;
    v7.m128_u64[1] = 0x1F8EE6A0E092C958LL;
    v8.m128_u64[0] = 0xDC16F237A0F786F9uLL;
    v8.m128_u64[1] = 0x7AD85FB6B73EA206LL;
    goto LABEL_9;
  }
  v7.m128_i32[2] = 0;
  v6.m128_u64[0] = 0;
  v6.m128_u64[1] = v3;
  v7.m128_u64[0] = v2 + v3;
  KernelHook2(ProcAddrCustom, 80, HandlerForHook2, &v6);
  if ( qword_14115DBD0 )
    goto LABEL_5;
  v4.m128_u64[0] = 0xB2799B43D0B8EFBAuLL;
  v4.m128_u64[1] = 0x15BE7FC2D8508275LL;
  v5.m128_u64[0] = 0x36A8CB29F245DA6ELL;
  v5.m128_u64[1] = 0x1F8EE6A0E092C958LL;
  v8.m128_u64[0] = 0xDC16F237A0F786F9uLL;
  v8.m128_u64[1] = 0x7AD85FB6B73EA206LL;
  v9.m128_u64[0] = 0x36A8CB29F221B41BLL;
  v9.m128_u64[1] = 0x1F8EE6A0E092C958LL;
  v4 = _mm_xor_ps(v4, v8);
  v5 = _mm_xor_ps(v5, v9);                      // Failed to find CiInitialize
  MainLogFunction(128, &unk_14016FCE0, &v4);
LABEL_10:
  if ( (v1 ^ v10) != _security_cookie )
    goto LABEL_11;
}

bool __fastcall HandlerForHook2(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  char *v7; // r14
  bool result; // al

  if ( a3 != 5
    || (*a2 & 0xFE) != 0xE8
    || (v7 = (a2 + *(a2 + 1) + 5), !sub_14001A470(v7, (a5 + 8)))
    || (KernelHook2(v7, 100, sub_140017A00, a5), result = 1, !qword_14115DBD0) )
  {
    result = 1;
    if ( *a1 != 147 )
      return a3 == 1 && (*(a1 + 18) == 0xCC || *(a1 + 18) == 0x90);
  }
  return result;
}