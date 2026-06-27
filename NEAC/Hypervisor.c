__int64 __fastcall EnterHV()
{
  unsigned int v0; // esi

  v0 = STATUS_UNSUCCESSFUL;
  if ( !vmcall() )
    return 0;
  return v0;
}

__int64 __fastcall vmcall()
{
  char v0; // cf
  char v1; // zf

  __asm { vmcall }
  if ( v1 )
    return 1;
  if ( v0 )
    return 2;
  return 0;
}

__int64 HV_VendorCheck()
{
  unsigned int v0; // r8d
  __int64 _RAX; // rax
  __int64 _RCX; // rcx
  __int64 _RAX; // rax
  __int64 _RAX; // rax
  __int64 _RBX; // rbx

  v0 = 0;
  _RAX = 1;
  __asm { cpuid }
  if ( _RCX < 0 )
  {
    _RAX = '@\0\0\x01';
    __asm { cpuid }
    v0 = _RBX;
    LOBYTE(v0) = _RAX == 'FUCK'; // lmao
  }
  return v0;
}

__int64 sub_141163710()
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  v0 = 0;
  _RAX = 1;
  __asm { cpuid }
  if ( _RCX >= 0 )
    goto LABEL_3;
  _RAX = 1073741825;
  __asm { cpuid }
  if ( _RAX != 1179992907 )
  {
LABEL_3:
    v13 = '\xC0\0\0\x01';
    if ( IoGetCurrentProcess() != PsInitialSystemProcess )
    {
      v15 = 1;
      KeInitializeEvent(&Event, NotificationEvent, 0);
      WorkItem.WorkerRoutine = VMM_init;
      WorkItem.Parameter = &v13;
      WorkItem.List.Flink = 0;
      ExQueueWorkItem(&WorkItem, DelayedWorkQueue);
      KeWaitForSingleObject(&Event, Executive, 0, 0, 0);
      v0 = v13;
      if ( v13 >= 0 )
        goto LABEL_5;
LABEL_8:
      v16.m128_u64[0] = 0x45B08CC847C4C1B3LL;
      v16.m128_u64[1] = 0x55360C9C0B90844ALL;
      v17.m128_u64[0] = 0x3BD6109BDDC83827LL;
      v17.m128_u64[1] = 0x4420CE6FEF9209FLL;
      v18.m128_u64[0] = 0x29E6AC1D06A606B1LL;
      v18.m128_u64[1] = 0x95EB7F74492D43FAuLL;
      WorkItem.List.Flink = 0x24D9F8A1298DACE5LL;
      WorkItem.List.Blink = 0x3B5965E86AEAED26LL;
      WorkItem.WorkerRoutine = 0x1BB275F7B4A95E07LL;
      WorkItem.Parameter = 0x3C7229C6968D49E8LL;
      v20.m128_u64[0] = 0x29E6AC1D06A628E9LL;
      v20.m128_u64[1] = 0x95EB7F74492D43FAuLL;
      v16 = _mm_xor_ps(v16, WorkItem.List);
      v17 = _mm_xor_ps(v17, *&WorkItem.WorkerRoutine);
      v18 = _mm_xor_ps(v18, v20);               // VMInit_Fail_Status: 0x%x
      MainLogFunction(128, &unk_14016FCE0, &v16);
      v0 = v13;
      if ( (v12 ^ v21) == _security_cookie )
        return v0;
LABEL_9:
      __debugbreak();
    }
    v15 = 0;
    VMM_init(&v13);
    v0 = v13;
    if ( v13 < 0 )
      goto LABEL_8;
  }
LABEL_5:
  if ( (v12 ^ v21) != _security_cookie )
    goto LABEL_9;
  return v0;
}

__int64 CheckForHVAndForSelfHV()
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  _RAX = 1;
  __asm { cpuid }
  if ( _RCX >= 0 )
    goto LABEL_5;
  _RAX = 1073741825;
  __asm { cpuid }
  if ( result != 'FUCK' )
  {
LABEL_5:
    if ( (v10 ^ v17) == _security_cookie )
      return result;
LABEL_8:
    __debugbreak();
  }
  v11.m128_u64[0] = 0x48B88CD247E4C2B0LL;
  v11.m128_u64[1] = 0x761433C80D84844ALL;
  v12.m128_u64[0] = 0x1BB275F7B4A95E29LL;
  v12.m128_u64[1] = 0x3C7229C6968D49E8LL;
  v14.m128_u64[0] = 0x24D9F8A1298DACE5LL;
  v14.m128_u64[1] = 0x3B5965E86AEAED26LL;
  v15.m128_u64[0] = 0x1BB275F7B4A95E07LL;
  v15.m128_u64[1] = 0x3C7229C6968D49E8LL;
  v11 = _mm_xor_ps(v11, v14);
  v12 = _mm_xor_ps(v12, v15);                   // VMM_Init_Success
  MainLogFunction(32, &unk_14016FCE0, &v11);
  v9 = SetupVirt(PrepareCoreCallback, 0);
  if ( v9 >= 0 )
  {
    v11.m128_u64[0] = 0x494B5F709E8C4B1LL;
    v11.m128_u64[1] = 0x553C008A4A998C4ELL;
    v12.m128_u64[0] = 0x7AC60699DDC72B27LL;
    v12.m128_u64[1] = 0x3C7229E8F2E82584LL;
    v14.m128_u64[0] = 0x24D9F8A1298DACE5LL;
    v14.m128_u64[1] = 0x3B5965E86AEAED26LL;
    v15.m128_u64[0] = 0x1BB275F7B4A95E07LL;
    v15.m128_u64[1] = 0x3C7229C6968D49E8LL;
    v11 = _mm_xor_ps(v11, v14);
    v12 = _mm_xor_ps(v12, v15);                 // VMM_All_Core_OK\n
    result = MainLogFunction(32, &unk_14016FCE0, &v11);
    goto LABEL_5;
  }
  v11.m128_u64[0] = 0x494B5F709E8C4B1LL;
  v11.m128_u64[1] = 0x1B2D0A864A998C4ELL;
  v12.m128_u64[0] = 0x72DC00D7DACC3B65LL;
  v12.m128_u64[1] = 0x581745AAF7F93A86LL;
  v13.m128_u64[0] = 0x7CFD425368300C9LL;
  v13.m128_u64[1] = 0x95EB7F74492D43FAuLL;
  v14.m128_u64[0] = 0x24D9F8A1298DACE5LL;
  v14.m128_u64[1] = 0x3B5965E86AEAED26LL;
  v15.m128_u64[0] = 0x1BB275F7B4A95E07LL;
  v15.m128_u64[1] = 0x3C7229C6968D49E8LL;
  v16.m128_u64[0] = 0x29E6AC1D06A628E9LL;
  v16.m128_u64[1] = 0x95EB7F74492D43FAuLL;
  v11 = _mm_xor_ps(v11, v14);
  v12 = _mm_xor_ps(v12, v15);
  v13 = _mm_xor_ps(v13, v16);                   // VMM_Core_Init_Error: 0x%x\n
  result = MainLogFunction(64, &unk_14016FCE0, &v11, v9);
  if ( (v10 ^ v17) != _security_cookie )
    goto LABEL_8;
  return result;
}

__int64 CheckIfSetupHVIsAllowed()
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  v0 = ReadMsr(58);
  v1 = 0;
  if ( (v0 & 1) == 0 )
  {
    sub_140003530(58, v0 | 1);
    if ( (ReadMsr(58) & 1) == 0 )
    {
      v4.m128_u64[0] = 0x4FBA97CD09E8C4B1LL;
      v4.m128_u64[1] = 0x1B2A0CC81E838F06LL;
      v5.m128_u64[0] = 0x77D1559BD8C02A74LL;
      v5.m128_u64[1] = 0x3C7229C6B8FF288DLL;
      v6.m128_u64[0] = 0x24D9F8A1298DACE5LL;
      v6.m128_u64[1] = 0x3B5965E86AEAED26LL;
      v7.m128_u64[0] = 0x1BB275F7B4A95E07LL;
      v7.m128_u64[1] = 0x3C7229C6968D49E8LL;
      v4 = _mm_xor_ps(v4, v6);
      v5 = _mm_xor_ps(v5, v7);                  // some error about VMX
      MainLogFunction(128, &unk_14016FCE0, &v4);
      v1 = -1073741438;
    }
  }
  if ( (&v3 ^ v8) != _security_cookie )
    __debugbreak();
  return v1;
}

void __fastcall SetupAndEnableHV(const void *a1, const void *a2, volatile signed __int32 *a3)
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  if ( a3 )
  {
    PoolWithTag = ExAllocatePoolWithTag(NonPagedPool, 0x1070u, 0x466B5458u);
    if ( PoolWithTag )
    {
      v7 = PoolWithTag;
      v8 = (PoolWithTag + 8);
      memset((PoolWithTag + 8), 0, 0x1068u);
      *v7 = a3;
      _InterlockedIncrement(a3);
      v9 = sub_141162760();
      v7[4] = v9;
      if ( v9 )
      {
        v10 = sub_14006DCB0();
        v7[5] = v10;
        if ( v10 )
        {
          MappingAddress = MmAllocateMappingAddress(0x100000u, 0x466B5458u);
          v7[523] = MappingAddress;
          if ( MappingAddress )
          {
            v12 = ExAllocatePoolWithTag(NonPagedPool, 0x20u, 0x466B5458u);
            if ( v7[523] )
            {
              *(v12 + 1) = 0;
              *v12 = 0;
              RtlInitializeBitMap(v7 + 262, v12, 0x100u);
            }
          }
          v13 = sub_140003260(24576);
          *v8 = v13;
          if ( v13 )
          {
            memset(v13, 0, 0x6000u);
            v14 = ExAllocatePoolWithTag(NonPagedPool, 0x1000u, 0x466B5458u);
            v7[3] = v14;
            if ( v14 )
            {
              memset(v14, 0, 0x1000u);
              v15 = ExAllocatePoolWithTag(NonPagedPool, 0x1000u, 0x466B5458u);
              v7[2] = v15;
              if ( v15 )
              {
                memset(v15, 0, 0x1000u);
                v16 = v7[1];
                v17 = v16 + 3072;
                v18 = v16 + 3071;
                v16[3071] = v7;
                v19 = v16 + 3066;
                MainLogFunction(16, &unk_14016FCE0, "vmm_stack_limit       = %p", v7[1]);
                MainLogFunction(16, &unk_14016FCE0, "vmm_stack_region_base = %p", v17);
                MainLogFunction(16, &unk_14016FCE0, "vmm_stack_data        = %p", v18);
                MainLogFunction(16, &unk_14016FCE0, "vmm_stack_base        = %p", v19);
                MainLogFunction(16, &unk_14016FCE0, "processor_data        = %p stored at %p", v7, v18);
                MainLogFunction(16, &unk_14016FCE0, "guest_stack_pointer   = %p", a1);
                MainLogFunction(16, &unk_14016FCE0, "guest_inst_pointer    = %p", a2);
                v20 = ReadMsr(1158);
                v21 = ReadMsr(1159);
                v22 = __readcr0();
                __writecr0(v20 | v21 & v22);
                v23 = ReadMsr(1160);
                v24 = ReadMsr(1161);
                v25 = __readcr4();
                __writecr4(v23 | v24 & v25);
                *v7[2] = ReadMsr(1152) & 0x7FFFFFFF;
                v30[0] = MmGetPhysicalAddress(v7[2]).QuadPart;
                _RAX = v30;
                __asm { vmxon   qword ptr [rax] }
                if ( !(v27 + v27 + v28) )
                {
                  sub_140003540();
                  sub_140003590();
                  if ( sub_141164040(v7) )
                  {
                    HvCore(v7, a1, a2, v19);
                    LaunchHV();
                  }
                  __vmx_off();
                }
              }
            }
          }
        }
      }
      MaybeAntiDMA(v7);
    }
  }
  if ( (&v29 ^ v30[1]) != _security_cookie )
    __debugbreak();
}

char __fastcall HvCore(__int64 *a1, __int64 a2, __int64 a3, __int64 a4)
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  v103 = 0.0;
  sgdtWrapper(&v103);
  v102 = 0.0;
  __sidt(&v102);
  Msr = ReadMsr(0x480u);
  v6 = 1168;
  if ( (Msr & 0x80000000000000LL) == 0 )
    v6 = 1156;
  v7 = 1167;
  if ( (Msr & 0x80000000000000LL) == 0 )
    v7 = 1155;
  v8 = 1165;
  if ( (Msr & 0x80000000000000LL) == 0 )
    v8 = 1153;
  v9 = 1166;
  if ( (Msr & 0x80000000000000LL) == 0 )
    v9 = 1154;
  v98 = ReadMsr(v6);
  v99 = ReadMsr(v7);
  v100 = ReadMsr(v8);
  v10 = ReadMsr(v9);
  v11 = ReadMsr(0x48Bu);
  v12 = __readcr0();
  v97 = v12;
  v13 = __readcr4();
  v96 = v13;
  v101 = return0();
  v14 = KeGetCurrentProcessorNumberWrapper();
  vmwriteWrapper(0, (v14 + 1));
  v15 = _ES__Wrapper();
  vmwriteWrapper(2048, v15);
  v16 = _CS__Wrapper();
  vmwriteWrapper(2050, v16);
  v17 = _SS__Wrapper();
  vmwriteWrapper(2052, v17);
  v18 = _DS__Wrapper();
  vmwriteWrapper(2054, v18);
  v19 = _FS__Wrapper();
  vmwriteWrapper(2056, v19);
  v20 = _GS__Wrapper();
  vmwriteWrapper(2058, v20);
  v21 = sldtWrapper();
  vmwriteWrapper(2060, v21);
  v22 = strWrapper();
  vmwriteWrapper(2062, v22);
  v23 = _ES__Wrapper();
  vmwriteWrapper(3072, v23 & 0xF8);
  v24 = _CS__Wrapper();
  vmwriteWrapper(3074, v24 & 0xF8);
  v25 = _SS__Wrapper();
  vmwriteWrapper(3076, v25 & 0xF8);
  v26 = _DS__Wrapper();
  vmwriteWrapper(3078, v26 & 0xF8);
  v27 = _FS__Wrapper();
  vmwriteWrapper(3080, v27 & 0xF8);
  v28 = _GS__Wrapper();
  vmwriteWrapper(3082, v28 & 0xF8);
  v29 = strWrapper();
  vmwriteWrapper(3084, v29 & 0xF8);
  PhysicalAddress = MmGetPhysicalAddress(*(*a1 + 16));
  vmwriteWrapper(0x2000, PhysicalAddress.QuadPart);
  v31 = MmGetPhysicalAddress(*(*a1 + 24));
  vmwriteWrapper(8194, v31.QuadPart);
  v32 = MmGetPhysicalAddress(*(*a1 + 8));
  vmwriteWrapper(8196, v32.QuadPart);
  v33 = sub_140001850(a1[4]);
  vmwriteWrapper(8218, v33);
  vmwriteWrapper(10240, -1);
  v34 = ReadMsr(0x1D9u);
  vmwriteWrapper(10242, v34);
  if ( return0() )
  {
    v35 = __readcr3();
    sub_1400035E0(v35);
  }
  vmwriteWrapper(0x4000, v100);
  vmwriteWrapper(16386, v10 | (HIDWORD(v10) & 0x92000000));
  vmwriteWrapper(16388, 8);
  vmwriteWrapper(16396, v99 | (WORD2(v99) & 0x8204));
  vmwriteWrapper(16402, v98 | (WORD2(v98) & 0x204));
  vmwriteWrapper(16414, v11 | (HIDWORD(v11) & 0x10102A));
  v36 = _ES__Wrapper();
  vmwriteWrapper(18432, __segmentlimit(v36));
  v37 = _CS__Wrapper();
  vmwriteWrapper(18434, __segmentlimit(v37));
  v38 = _SS__Wrapper();
  vmwriteWrapper(18436, __segmentlimit(v38));
  v39 = _DS__Wrapper();
  vmwriteWrapper(18438, __segmentlimit(v39));
  v40 = _FS__Wrapper();
  vmwriteWrapper(18440, __segmentlimit(v40));
  v41 = _GS__Wrapper();
  vmwriteWrapper(18442, __segmentlimit(v41));
  v42 = sldtWrapper();
  vmwriteWrapper(18444, __segmentlimit(v42));
  v43 = strWrapper();
  vmwriteWrapper(18446, __segmentlimit(v43));
  vmwriteWrapper(18448, LOWORD(v103));
  vmwriteWrapper(18450, LOWORD(v102));
  v44 = _ES__Wrapper();
  v45 = 0x10000;
  v46 = 0x10000;
  if ( v44 )
    v46 = (larWrapper(v44, 0x10000) >> 8) & 0xF0FF;
  vmwriteWrapper(18452, v46);
  v47 = _CS__Wrapper();
  if ( v47 )
    v45 = (larWrapper(v47, v48) >> 8) & 0xF0FF;
  vmwriteWrapper(18454, v45);
  v49 = _SS__Wrapper();
  v50 = 0x10000;
  v51 = 0x10000;
  if ( v49 )
    v51 = (larWrapper(v49, 0x10000) >> 8) & 0xF0FF;
  vmwriteWrapper(18456, v51);
  v52 = _DS__Wrapper();
  if ( v52 )
    v50 = (larWrapper(v52, v53) >> 8) & 0xF0FF;
  vmwriteWrapper(18458, v50);
  v54 = _FS__Wrapper();
  v55 = 0x10000;
  v56 = 0x10000;
  if ( v54 )
    v56 = (larWrapper(v54, 0x10000) >> 8) & 0xF0FF;
  vmwriteWrapper(18460, v56);
  v57 = _GS__Wrapper();
  if ( v57 )
    v55 = (larWrapper(v57, v58) >> 8) & 0xF0FF;
  vmwriteWrapper(18462, v55);
  v59 = sldtWrapper();
  v60 = 0x10000;
  v61 = 0x10000;
  if ( v59 )
    v61 = (larWrapper(v59, 0x10000) >> 8) & 0xF0FF;
  vmwriteWrapper(18464, v61);
  v62 = strWrapper();
  if ( v62 )
    v60 = (larWrapper(v62, v63) >> 8) & 0xF0FF;
  v64 = 1048752;
  if ( !v101 )
    v64 = 0;
  v65 = 3758096384LL;
  if ( !v101 )
    v65 = 0;
  vmwriteWrapper(18466, v60);
  v66 = ReadMsr(0x174u);
  vmwriteWrapper(18474, v66);
  v67 = ReadMsr(0x174u);
  vmwriteWrapper(19456, v67);
  vmwriteWrapper(24576, v65);
  vmwriteWrapper(24578, v64);
  vmwriteWrapper(24580, v97);
  vmwriteWrapper(24582, v96);
  v68 = __readcr0();
  vmwriteWrapper(26624, v68);
  v69 = __readcr3();
  vmwriteWrapper(26626, v69);
  v70 = __readcr4();
  vmwriteWrapper(26628, v70);
  vmwriteWrapper(26630, 0);
  vmwriteWrapper(26632, 0);
  vmwriteWrapper(26634, 0);
  vmwriteWrapper(26636, 0);
  v71 = ReadMsr(0xC0000100);
  vmwriteWrapper(26638, v71);
  v72 = ReadMsr(0xC0000101);
  vmwriteWrapper(26640, v72);
  v73 = sldtWrapper();
  v74 = sub_140004560(*(&v103 + 2), v73);
  vmwriteWrapper(26642, v74);
  v75 = strWrapper();
  v76 = sub_140004560(*(&v103 + 2), v75);
  vmwriteWrapper(26644, v76);
  vmwriteWrapper(26646, *(&v103 + 2));
  vmwriteWrapper(26648, *(&v102 + 2));
  v77 = __readdr(7u);
  vmwriteWrapper(26650, v77);
  vmwriteWrapper(26652, a2);
  vmwriteWrapper(26654, a3);
  v78 = __readeflags();
  vmwriteWrapper(26656, v78);
  v79 = ReadMsr(0x175u);
  vmwriteWrapper(26660, v79);
  v80 = ReadMsr(0x176u);
  vmwriteWrapper(26662, v80);
  v81 = ReadMsr(0xC0000080);
  vmwriteWrapper(10246, v81);
  v82 = __readcr0();
  vmwriteWrapper(27648, v82);
  v83 = __readcr3();
  vmwriteWrapper(27650, v83);
  v84 = __readcr4();
  vmwriteWrapper(27652, v84);
  v85 = ReadMsr(0xC0000100);
  vmwriteWrapper(27654, v85);
  v86 = ReadMsr(0xC0000101);
  vmwriteWrapper(27656, v86);
  v87 = strWrapper();
  v88 = sub_140004560(*(&v103 + 2), v87);
  vmwriteWrapper(27658, v88);
  vmwriteWrapper(27660, *(&v103 + 2));
  vmwriteWrapper(27662, *(&v102 + 2));
  v89 = ReadMsr(0xC0000080);
  vmwriteWrapper(11266, v89);
  v90 = ReadMsr(0x175u);
  vmwriteWrapper(27664, v90);
  v91 = ReadMsr(0x176u);
  vmwriteWrapper(27666, v91);
  vmwriteWrapper(27668, a4);
  result = vmwriteWrapper(27670, sub_1400708C3);
  if ( (&v103 ^ v104) != _security_cookie )
    __debugbreak();
  return result;
}

PBOOLEAN LaunchHV()
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  v0 = sub_140003490(0x4400u);
  v1 = 0;
  v2 = v0 == 0;
  if ( v0 )
  {
    v6.m128_u64[0] = 0x768DABEF60D2E1B3LL;
    v6.m128_u64[1] = 0x7E062BA723BEAE73LL;
    v7.m128_u64[0] = 0x3E9248D7E6E60C55LL;
    v7.m128_u64[1] = 0x3C7229C6968D3CA1LL;
    v8.m128_u64[0] = 0x24D9F8A1298DACE5LL;
    v8.m128_u64[1] = 0x3B5965E86AEAED26LL;
    v9.m128_u64[0] = 0x1BB275F7B4A95E07LL;
    v9.m128_u64[1] = 0x3C7229C6968D49E8LL;
    v6 = _mm_xor_ps(v6, v8);
    v7 = _mm_xor_ps(v7, v9);                    // VMX_LAUNCH_FAILED, ERROR < %Iu\n (first block)
    MainLogFunction(64, &unk_14016FCE0, &v6, v0);
  }
  __asm { vmlaunch }
  if ( v1 + v1 + v2 == 1 )
  {
    v4 = sub_140003490(0x4400u);
    v6.m128_u64[0] = 0x768DABEF60D2E1B3LL;
    v6.m128_u64[1] = 0x7E062BA723BEAE73LL;
    v7.m128_u64[0] = 0x3E9248D7E6E60C55LL;
    v7.m128_u64[1] = 0x3C7229C6968D3CA1LL;
    v8.m128_u64[0] = 0x24D9F8A1298DACE5LL;
    v8.m128_u64[1] = 0x3B5965E86AEAED26LL;
    v9.m128_u64[0] = 0x1BB275F7B4A95E07LL;
    v9.m128_u64[1] = 0x3C7229C6968D49E8LL;
    v6 = _mm_xor_ps(v6, v8);
    v7 = _mm_xor_ps(v7, v9);                    // VMX_LAUNCH_FAILED, ERROR < %Iu\n (second block)
    MainLogFunction(128, &unk_14016FCE0, &v6, v4);
    result = KdDebuggerNotPresent;
    if ( KdDebuggerNotPresent )
    {
LABEL_5:
      if ( (v5 ^ v10) == _security_cookie )
        return result;
LABEL_9:
      JUMPOUT(0x141164B86LL);
    }
  }
  else
  {
    result = KdDebuggerNotPresent;
    if ( KdDebuggerNotPresent )
      goto LABEL_5;
  }
  __debugbreak();
  if ( (v5 ^ v10) != _security_cookie )
    goto LABEL_9;
  return result;
}

char __fastcall DeployHVStub(unsigned __int8 a1, char a2, unsigned __int64 a3)
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  v3 = 48 * a1;
  if ( *(&unk_14115A820 + v3) )
  {
    v16.m128_u64[0] = 0xAE7A9317C583E290uLL;
    v16.m128_u64[1] = 0x15B73796CE5AC363LL;
    v17.m128_u64[0] = 0x36A8CB29DC45D170LL;
    v17.m128_u64[1] = 0x1F8EE6A0E092C958LL;
    v18.m128_u64[0] = 0xDC16F237A0F786F9uLL;
    v18.m128_u64[1] = 0x7AD85FB6B73EA206LL;
    v19.m128_u64[0] = 0x36A8CB29F221B41BLL;
    v19.m128_u64[1] = 0x1F8EE6A0E092C958LL;
    v16 = _mm_xor_ps(v16, v18);
    v17 = _mm_xor_ps(v17, v19);                 // Control structure already initialized.
    MainLogFunction(128, &unk_14016FCE0, &v16);
    goto LABEL_3;
  }
  v8 = &unk_14115A820 + v3;
  if ( SomeFlagWrapper() && !*(v8 + 4) )
  {
    v16.m128_u64[0] = 0xAB45C145E396F0B2uLL;
    v16.m128_u64[1] = 0xEB73196DF5DD66FLL;
    v17.m128_u64[0] = 0x3686AF47874ED23BLL;
    v17.m128_u64[1] = 0x1F8EE6A0E092C958LL;
    v18.m128_u64[0] = 0xDC16F237A0F786F9uLL;
    v18.m128_u64[1] = 0x7AD85FB6B73EA206LL;
    v19.m128_u64[0] = 0x36A8CB29F221B41BLL;
    v19.m128_u64[1] = 0x1F8EE6A0E092C958LL;     // Invalid state for control structure init
  }
  else if ( SomeFlagWrapper() && !*(v8 + 5) )
  {
    v16.m128_u64[0] = 0xB342825AEA96F0B2uLL;
    v16.m128_u64[1] = 0x8AC31F3DB5FC754LL;
    v17.m128_u64[0] = 0x59CEEB5D9D4F9462LL;
    v17.m128_u64[1] = 0x1F8EE6A0CEF6A72DLL;
    v18.m128_u64[0] = 0xDC16F237A0F786F9uLL;
    v18.m128_u64[1] = 0x7AD85FB6B73EA206LL;
    v19.m128_u64[0] = 0x36A8CB29F221B41BLL;
    v19.m128_u64[1] = 0x1F8EE6A0E092C958LL;     // Prerequisite condition not met
  }
  else
  {
    if ( !SomeFlagWrapper() )
    {
      PoolWithTag = ExAllocatePoolWithTag(NonPagedPool, 0x1000u, 0x53425458u);
      v11 = PoolWithTag;
      if ( PoolWithTag )
      {
        LOBYTE(v10) = -52;
        memset(PoolWithTag, v10, 0x1000u);
        v12 = qword_140070A70;
        if ( a2 )
          v12 = byte_140070D13;
        memove(v11, v12, 0x500u);
      }
      v13 = *(v8 + 1);
      v14 = GetInstructionLength(v11);
      *(v11->m128_u64 + v14) = v13;
      *(&v11->m128_u64[1] + v14) = a3;
      v18.m128_i8[8] = a1;
      v18.m128_u64[0] = v11;
      SetupVirt(EnterHV_Wrapper, &v18);
      *v8 = 2;
LABEL_3:
      result = 1;
      if ( (v15 ^ v20) == _security_cookie )
        return result;
LABEL_22:
      JUMPOUT(0x1400455A4LL);
    }
    if ( HV_VendorCheck() && return1() )
    {
      EnterHV();
      goto LABEL_3;
    }
    v16.m128_u64[0] = 0xAC6687448083E997uLL;
    v16.m128_u64[1] = 0x5AAA30D0974AD069LL;
    v17.m128_u64[0] = 0x59CCAA41A140C250LL;
    v17.m128_u64[1] = 0x1F8EE6A0E092E72FLL;
    v18.m128_u64[0] = 0xDC16F237A0F786F9uLL;
    v18.m128_u64[1] = 0x7AD85FB6B73EA206LL;
    v19.m128_u64[0] = 0x36A8CB29F221B41BLL;
    v19.m128_u64[1] = 0x1F8EE6A0E092C958LL;     // Failed to initialize HV
  }
  v16 = _mm_xor_ps(v16, v18);
  v17 = _mm_xor_ps(v17, v19);
  MainLogFunction(128, &unk_14016FCE0, &v16);
  result = 0;
  if ( (v15 ^ v20) != _security_cookie )
    goto LABEL_22;
  return result;
}

__int64 SafeStartHV()
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  v0 = 0;
  _RAX = 1;
  __asm { cpuid }
  if ( _RCX >= 0 )
    goto LABEL_3;
  _RAX = 1073741825;
  __asm { cpuid }
  if ( _RAX != 1179992907 )
  {
LABEL_3:
    v13 = '\xC0\0\0\x01';
    if ( IoGetCurrentProcess() != PsInitialSystemProcess )
    {
      v15 = 1;
      KeInitializeEvent(&Event, NotificationEvent, 0);
      WorkItem.WorkerRoutine = VMM_init;
      WorkItem.Parameter = &v13;
      WorkItem.List.Flink = 0;
      ExQueueWorkItem(&WorkItem, DelayedWorkQueue);
      KeWaitForSingleObject(&Event, Executive, 0, 0, 0);
      v0 = v13;
      if ( v13 >= 0 )
        goto LABEL_5;
LABEL_8:
      v16.m128_u64[0] = 0x45B08CC847C4C1B3LL;
      v16.m128_u64[1] = 0x55360C9C0B90844ALL;
      v17.m128_u64[0] = 0x3BD6109BDDC83827LL;
      v17.m128_u64[1] = 0x4420CE6FEF9209FLL;
      v18.m128_u64[0] = 0x29E6AC1D06A606B1LL;
      v18.m128_u64[1] = 0x95EB7F74492D43FAuLL;
      WorkItem.List.Flink = 0x24D9F8A1298DACE5LL;
      WorkItem.List.Blink = 0x3B5965E86AEAED26LL;
      WorkItem.WorkerRoutine = 0x1BB275F7B4A95E07LL;
      WorkItem.Parameter = 0x3C7229C6968D49E8LL;
      v20.m128_u64[0] = 0x29E6AC1D06A628E9LL;
      v20.m128_u64[1] = 0x95EB7F74492D43FAuLL;
      v16 = _mm_xor_ps(v16, WorkItem.List);
      v17 = _mm_xor_ps(v17, *&WorkItem.WorkerRoutine);
      v18 = _mm_xor_ps(v18, v20);               // VMInit_Fail_Status: 0x%x
      MainLogFunction(128, &unk_14016FCE0, &v16);
      v0 = v13;
      if ( (v12 ^ v21) == _security_cookie )
        return v0;
LABEL_9:
      __debugbreak();
    }
    v15 = 0;
    VMM_init(&v13);
    v0 = v13;
    if ( v13 < 0 )
      goto LABEL_8;
  }
LABEL_5:
  if ( (v12 ^ v21) != _security_cookie )
    goto LABEL_9;
  return v0;
}

__int64 __fastcall ReadMTRR()
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  v1 = ReadMsr(767);
  byte_141135C58 = v1;
  v2 = ReadMsr(254);
  v3 = v2;
  v4 = v2 >> 8;
  result = MainLogFunction(
             16,
             &unk_14016FCE0,
             "MTRR Default=%lld, VariableCount=%lld, FixedSupported=%lld, FixedEnabled=%lld",
             v1,
             v2,
             BYTE1(v2) & 1,
             (v1 >> 10) & 1);
  if ( (v4 & (v1 >> 10) & 1) != 0 )
  {
    v6 = ReadMsr(592);
    word_141133C30[0] = 257;
    byte_141133C32 = v6;
    qword_141133C38 = 0;
    qword_141133C40 = 0xFFFF;
    word_141133C48 = 257;
    byte_141133C4A = BYTE1(v6);
    qword_141133C50 = 0x10000;
    qword_141133C58 = 0x1FFFF;
    word_141133C60 = 257;
    byte_141133C62 = BYTE2(v6);
    qword_141133C68 = 0x20000;
    qword_141133C70 = 196607;
    word_141133C78 = 257;
    byte_141133C7A = BYTE3(v6);
    qword_141133C80 = 196608;
    qword_141133C88 = 0x3FFFF;
    word_141133C90 = 257;
    byte_141133C92 = BYTE4(v6);
    qword_141133C98 = 0x40000;
    qword_141133CA0 = 327679;
    word_141133CA8 = 257;
    byte_141133CAA = BYTE5(v6);
    qword_141133CB0 = 327680;
    qword_141133CB8 = 393215;
    word_141133CC0 = 257;
    byte_141133CC2 = BYTE6(v6);
    qword_141133CC8 = 393216;
    qword_141133CD0 = 458751;
    word_141133CD8 = 257;
    byte_141133CDA = HIBYTE(v6);
    qword_141133CE0 = 458752;
    qword_141133CE8 = 0x7FFFF;
    v7 = ReadMsr(600);
    word_141133CF0 = 257;
    byte_141133CF2 = v7;
    qword_141133CF8 = 0x80000;
    qword_141133D00 = 540671;
    word_141133D08 = 257;
    byte_141133D0A = BYTE1(v7);
    qword_141133D10 = 540672;
    qword_141133D18 = 557055;
    word_141133D20 = 257;
    byte_141133D22 = BYTE2(v7);
    qword_141133D28 = 557056;
    qword_141133D30 = 573439;
    word_141133D38 = 257;
    byte_141133D3A = BYTE3(v7);
    qword_141133D40 = 573440;
    qword_141133D48 = 589823;
    word_141133D50 = 257;
    byte_141133D52 = BYTE4(v7);
    qword_141133D58 = 589824;
    qword_141133D60 = 606207;
    word_141133D68 = 257;
    byte_141133D6A = BYTE5(v7);
    qword_141133D70 = 606208;
    qword_141133D78 = 622591;
    word_141133D80 = 257;
    byte_141133D82 = BYTE6(v7);
    qword_141133D88 = 622592;
    qword_141133D90 = 638975;
    word_141133D98 = 257;
    byte_141133D9A = HIBYTE(v7);
    qword_141133DA0 = 638976;
    qword_141133DA8 = 655359;
    v8 = ReadMsr(601);
    word_141133DB0 = 257;
    byte_141133DB2 = v8;
    qword_141133DB8 = 655360;
    qword_141133DC0 = 671743;
    word_141133DC8 = 257;
    byte_141133DCA = BYTE1(v8);
    qword_141133DD0 = 671744;
    qword_141133DD8 = 688127;
    word_141133DE0 = 257;
    byte_141133DE2 = BYTE2(v8);
    qword_141133DE8 = 688128;
    qword_141133DF0 = 704511;
    word_141133DF8 = 257;
    byte_141133DFA = BYTE3(v8);
    qword_141133E00 = 704512;
    qword_141133E08 = 720895;
    word_141133E10 = 257;
    byte_141133E12 = BYTE4(v8);
    qword_141133E18 = 720896;
    qword_141133E20 = 737279;
    word_141133E28 = 257;
    byte_141133E2A = BYTE5(v8);
    qword_141133E30 = 737280;
    qword_141133E38 = 753663;
    word_141133E40 = 257;
    byte_141133E42 = BYTE6(v8);
    qword_141133E48 = 753664;
    qword_141133E50 = 770047;
    word_141133E58 = 257;
    byte_141133E5A = HIBYTE(v8);
    qword_141133E60 = 770048;
    qword_141133E68 = 786431;
    v9 = 616;
    v10 = &unk_141133E70;
    v11 = 819199;
    do
    {
      v12 = ReadMsr(v9);
      *v10 = 257;
      v10[2] = v12;
      *(v10 + 1) = v11 - 0x7FFF;
      *(v10 + 2) = v11 - 28672;
      *(v10 + 12) = 257;
      v10[26] = BYTE1(v12);
      v13 = HIBYTE(v12);
      *(v10 + 4) = v11 - 28671;
      *(v10 + 5) = v11 - 24576;
      *(v10 + 24) = 257;
      v10[50] = BYTE2(v12);
      *(v10 + 7) = v11 - 24575;
      *(v10 + 8) = v11 - 20480;
      *(v10 + 36) = 257;
      v10[74] = BYTE3(v12);
      *(v10 + 10) = v11 - 20479;
      *(v10 + 11) = v11 - 0x4000;
      *(v10 + 48) = 257;
      v10[98] = BYTE4(v12);
      *(v10 + 13) = v11 - 0x3FFF;
      *(v10 + 14) = v11 - 12288;
      *(v10 + 60) = 257;
      v10[122] = BYTE5(v12);
      *(v10 + 16) = v11 - 12287;
      *(v10 + 17) = v11 - 0x2000;
      *(v10 + 72) = 257;
      v10[146] = BYTE6(v12);
      *(v10 + 19) = v11 - 0x1FFF;
      *(v10 + 20) = v11 - 4096;
      result = v11 - 4095;
      *(v10 + 84) = 257;
      v10[170] = v13;
      *(v10 + 22) = v11 - 4095;
      *(v10 + 23) = v11;
      ++v9;
      v10 += 192;
      v11 += 0x8000;
    }
    while ( v11 != 1081343 );
    v14 = 88;
    if ( !v3 )
      return result;
  }
  else
  {
    v14 = 0;
    if ( !v3 )
      return result;
  }
  v15 = 2 * v3;
  v16 = 0;
  do
  {
    result = ReadMsr((v16 + 513));
    if ( (result & 0x800) != 0 )
    {
      if ( !_BitScanForward64(&v18, result & 0xFFFFFFFFF000LL) )
        LODWORD(v18) = v0;
      v19 = ReadMsr((v16 + 512));
      v20 = 3LL * v14;
      word_141133C30[4 * v20] = 1;
      LOBYTE(word_141133C30[4 * v20 + 1]) = v19;
      result = v19 & 0xFFFFFFFFF000LL;
      *&word_141133C30[4 * v20 + 4] = result;
      *&word_141133C30[4 * v20 + 8] = result + ~(-1LL << v18);
      ++v14;
      v0 = v18;
    }
    v16 += 2;
  }
  while ( v15 != v16 );
  return result;
}

void __fastcall VMM_init(__int64 a1)
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  PoolWithTag = ExAllocatePoolWithTag(NonPagedPool, 0x28u, 0x466B5458u);
  if ( !PoolWithTag )
    goto LABEL_14;
  v3 = PoolWithTag;
  PoolWithTag[1] = 0;
  *PoolWithTag = 0;
  *(PoolWithTag + 4) = 0;
  v4 = 0;
  v5 = ExAllocatePoolWithTag(NonPagedPool, 0x1000u, 0x466B5458u);
  if ( !v5 )
  {
    *(v3 + 1) = 0;
    goto LABEL_13;
  }
  v6 = v5;
  memset(v5 + 128, 0, 0x800u);
  memset(v6, 0xFFu, 0x800u);
  BitMapHeader = 0;
  RtlInitializeBitMap(&BitMapHeader, v6, 0x2000u);
  RtlClearBits(&BitMapHeader, 0xE7u, 2u);
  do
    ReadMsr(v4++);
  while ( v4 != 4096 );
  v26 = 0;
  RtlInitializeBitMap(&v26, &v6[64], 0x2000u);
  RtlClearBits(&v26, 0x101u, 2u);
  *(v3 + 1) = v6;
  v7 = ExAllocatePoolWithTag(NonPagedPool, 0x2000u, 0x466B5458u);
  if ( !v7 )
    goto LABEL_11;
  v8 = &v7[256];
  v9 = v7;
  memset(v7, 0, 0x2000u);
  BitMapHeader = 0;
  RtlInitializeBitMap(&BitMapHeader, v9, 0x8000u);
  v26 = 0;
  RtlInitializeBitMap(&v26, v8, 0x8000u);
  *(v3 + 2) = v9;
  *(v3 + 3) = v8;
  v10 = sub_14006DCE0();
  *(v3 + 4) = v10;
  if ( !v10 )
  {
LABEL_11:
    ExFreePoolWithTag(*(v3 + 1), 0x466B5458u);
LABEL_13:
    ExFreePoolWithTag(v3, 0x466B5458u);
LABEL_14:
    *a1 = -1073741664;
    goto LABEL_15;
  }
  ReadMTRR();
  _RAX = 0;
  __asm { cpuid }
  if ( _RBX ^ 0x756E6547 | _RDX ^ 0x49656E69 | _RCX ^ 0x6C65746E )
  {
    *&v26.SizeOfBitMap = 0x56B688D15CFEC2B0LL;
    v26.Buffer = 0x1B0C35AB4A8E8852LL;
    v27.m128_u64[0] = 0x1B9C0798D0C73B71LL;
    v27.m128_u64[1] = 0x3C7229C6968D49E8LL;
    *&BitMapHeader.SizeOfBitMap = 0x24D9F8A1298DACE5LL;
    BitMapHeader.Buffer = 0x3B5965E86AEAED26LL;
    v24.m128_u64[0] = 0x1BB275F7B4A95E07LL;
    v24.m128_u64[1] = 0x3C7229C6968D49E8LL;
    v26 = _mm_xor_ps(v26, BitMapHeader);
    v27 = _mm_xor_ps(v27, v24);                 // Intel CPU is required for this driver.
    MainLogFunction(128, &unk_14016FCE0, &v26);
    *a1 = -1073741823;
    goto LABEL_15;
  }
  _RAX = 1;
  __asm { cpuid }
  if ( (_RCX & 0x20) != 0 )
  {
    if ( (ReadMsr(1152) & 0x3C000000000000LL) == 0x18000000000000LL )
    {
      v21 = ReadMsr(58);
      if ( (v21 & 1) == 0 )
      {
        *&v26.SizeOfBitMap = 0x4FBA97CD09E8C4B1LL;
        v26.Buffer = 0x1B2A0CC81E838F06LL;
        v27.m128_u64[0] = 0x5A925B85D5CC3264LL;
        v27.m128_u64[1] = 0x521B5DB6FBE83D9CLL;
        v28.m128_u64[0] = 0x5D83DF3D69D2088ELL;
        v28.m128_u64[1] = 0x95EB7F74490372DAuLL;
        *&BitMapHeader.SizeOfBitMap = 0x24D9F8A1298DACE5LL;
        BitMapHeader.Buffer = 0x3B5965E86AEAED26LL;
        v24.m128_u64[0] = 0x1BB275F7B4A95E07LL;
        v24.m128_u64[1] = 0x3C7229C6968D49E8LL;
        v25.m128_u64[0] = 0x29E6AC1D06A628E9LL;
        v25.m128_u64[1] = 0x95EB7F74492D43FAuLL;
        v26 = _mm_xor_ps(v26, BitMapHeader);
        v27 = _mm_xor_ps(v27, v24);
        v28 = _mm_xor_ps(v28, v25);             // "VMX virtualization technology is not supported."
        MainLogFunction(32, &unk_14016FCE0, &v26);
        if ( SetupVirt(CheckIfSetupHVIsAllowed, 0) < 0 )
          goto LABEL_27;
      }
      if ( (v21 & 4) == 0 )
      {
        *&v26.SizeOfBitMap = 0x50B89DC709D5E1B3LL;
        v26.Buffer = 0x5E2B04C8198F9F53LL;
        v27.m128_u64[0] = 0x7ADC10D7C0C63027LL;
        v27.m128_u64[1] = 0x3C7229E8F2E8258ALL;
        *&BitMapHeader.SizeOfBitMap = 0x24D9F8A1298DACE5LL;
        BitMapHeader.Buffer = 0x3B5965E86AEAED26LL;
        v24.m128_u64[0] = 0x1BB275F7B4A95E07LL;
        v24.m128_u64[1] = 0x3C7229C6968D49E8LL; // "Failed to enable Hyper-V compatibility mode."
        goto LABEL_10;
      }
      if ( ReadMsrWrapper() )
      {
        v22 = SetupVirt(VMM_init1, v3);
        *a1 = v22;
        if ( v22 < 0 )
          SetupVirt(PrepareCoreCallback, 0);
        else
          CreateAndRegisterCallback();
        goto LABEL_15;
      }
      *&v26.SizeOfBitMap = 0x50B89DC709D9FCA0LL;
      v26.Buffer = 0x5E2B04C8198F9F53LL;
      v27.m128_u64[0] = 0x77C713D7C0C63027LL;
      v27.m128_u64[1] = 0x530259B3E5AD3084LL;
      v28.m128_u64[0] = 0x29E6AC3362C35C9BLL;
      v28.m128_u64[1] = 0x95EB7F74492D43FAuLL;
      *&BitMapHeader.SizeOfBitMap = 0x24D9F8A1298DACE5LL;
      BitMapHeader.Buffer = 0x3B5965E86AEAED26LL;
      v24.m128_u64[0] = 0x1BB275F7B4A95E07LL;
      v24.m128_u64[1] = 0x3C7229C6968D49E8LL;
      v25.m128_u64[0] = 0x29E6AC1D06A628E9LL;
      v25.m128_u64[1] = 0x95EB7F74492D43FAuLL;  // "Hyper-V Code Integrity (HVCI) is active. Disable it in Windows Security."
    }
    else
    {
      *&v26.SizeOfBitMap = 0x45BBD5C45DE4DEB2LL;
      v26.Buffer = 0x5E31068909CA8645LL;
      v27.m128_u64[0] = 0x68DB5592C4D02A27LL;
      v27.m128_u64[1] = 0x4C075AE6E2E227C8LL;
      v28.m128_u64[0] = 0x29C8C87872D44799LL;
      v28.m128_u64[1] = 0x95EB7F74492D43FAuLL;
      *&BitMapHeader.SizeOfBitMap = 0x24D9F8A1298DACE5LL;
      BitMapHeader.Buffer = 0x3B5965E86AEAED26LL;
      v24.m128_u64[0] = 0x1BB275F7B4A95E07LL;
      v24.m128_u64[1] = 0x3C7229C6968D49E8LL;
      v25.m128_u64[0] = 0x29E6AC1D06A628E9LL;
      v25.m128_u64[1] = 0x95EB7F74492D43FAuLL;
    }
    v26 = _mm_xor_ps(v26, BitMapHeader);
    v27 = _mm_xor_ps(v27, v24);
    v28 = _mm_xor_ps(v28, v25);                 // "UEFI firmware has locked virtualization settings. Check BIOS."
    goto LABEL_26;
  }
  *&v26.SizeOfBitMap = 0x50B89DC709D5E1B3LL;
  v26.Buffer = 0x5E2B04C8198F9F53LL;
  v27.m128_u64[0] = 0x6BC706D7C0C63027LL;
  v27.m128_u64[1] = 0x3C5C4DA3E2FF2698LL;
  *&BitMapHeader.SizeOfBitMap = 0x24D9F8A1298DACE5LL;
  BitMapHeader.Buffer = 0x3B5965E86AEAED26LL;
  v24.m128_u64[0] = 0x1BB275F7B4A95E07LL;
  v24.m128_u64[1] = 0x3C7229C6968D49E8LL;
LABEL_10:
  v26 = _mm_xor_ps(v26, BitMapHeader);
  v27 = _mm_xor_ps(v27, v24);                   // "AMD SVM is not supported. Intel VMX required for this driver."
LABEL_26:
  MainLogFunction(128, &unk_14016FCE0, &v26);
LABEL_27:
  *a1 = -1070268386;
LABEL_15:
  if ( *(a1 + 32) == 1 )
    KeSetEvent((a1 + 8), 0, 0);
}

__int64 __fastcall VMM_init1(__int64 a1)
{
  unsigned int v2; // eax
  char v3; // cl
  __int64 result; // rax
  unsigned int v5; // eax
  __int64 v6; // [rsp+0h] [rbp-B8h] BYREF
  __m128 v7; // [rsp+20h] [rbp-98h] BYREF
  __m128 v8; // [rsp+30h] [rbp-88h]
  __m128 v9; // [rsp+40h] [rbp-78h]
  __m128 v10; // [rsp+50h] [rbp-68h]
  __m128 v11; // [rsp+60h] [rbp-58h]
  __m128 v12; // [rsp+70h] [rbp-48h]
  __int64 v13; // [rsp+88h] [rbp-30h]

  v2 = KeGetCurrentProcessorNumberWrapper();
  v7.m128_u64[0] = 0x4DB599C85DE4C2ACLL;
  v7.m128_u64[1] = 0x631433C80D84845CLL;
  v8.m128_u64[0] = 0x7EDA01D7C6C63827LL;
  v8.m128_u64[1] = 0x4F014CA5F9FF39C8LL;
  v9.m128_u64[0] = 0x29E6827923865A86LL;
  v9.m128_u64[1] = 0x95EB7F74492D43FAuLL;
  v10.m128_u64[0] = 0x24D9F8A1298DACE5LL;
  v10.m128_u64[1] = 0x3B5965E86AEAED26LL;
  v11.m128_u64[0] = 0x1BB275F7B4A95E07LL;
  v11.m128_u64[1] = 0x3C7229C6968D49E8LL;
  v12.m128_u64[0] = 0x29E6AC1D06A628E9LL;
  v12.m128_u64[1] = 0x95EB7F74492D43FAuLL;
  v7 = _mm_xor_ps(v7, v10);
  v8 = _mm_xor_ps(v8, v11);
  v9 = _mm_xor_ps(v9, v12);                     // Initialize Process...
  MainLogFunction(32, &unk_14016FCE0, &v7, v2);
  v3 = sub_1400707F0(SetupAndEnableHV, a1);
  result = 3221225473LL;
  if ( v3 )
  {
    v5 = KeGetCurrentProcessorNumberWrapper();
    v7.m128_u64[0] = 0x4AAC99CD09D5E1B3LL;
    v7.m128_u64[1] = 0x493603C80E8F8545LL;
    v8.m128_u64[0] = 0x68C11094DBDB2E27LL;
    v8.m128_u64[1] = 0x3C7207A2B3AD3B87LL;
    v10.m128_u64[0] = 0x24D9F8A1298DACE5LL;
    v10.m128_u64[1] = 0x3B5965E86AEAED26LL;
    v11.m128_u64[0] = 0x1BB275F7B4A95E07LL;
    v11.m128_u64[1] = 0x3C7229C6968D49E8LL;
    v7 = _mm_xor_ps(v7, v10);
    v8 = _mm_xor_ps(v8, v11);                   // VMX launch check for Process success.
    MainLogFunction(32, &unk_14016FCE0, &v7, v5);
    result = 0;
  }
  if ( (&v6 ^ v13) != _security_cookie )
    __debugbreak();
  return result;
}