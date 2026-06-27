__int64 __fastcall SetUpUmHooks(void *a1, _WORD *a2, __int64 a3)
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  Process = 0;
  v5 = PsLookupProcessByProcessId(a1, &Process);
  if ( v5 >= 0 )
  {
    if ( !PsGetProcessWow64Process(Process) )
    {
      v7 = -1073741823;
      goto LABEL_29;
    }
    v13 = a3;
    KeStackAttachProcess(Process, &ApcState);
    v19.m128_u64[0] = 0xBF738658D2A7F1A3uLL;
    v19.m128_u64[1] = 0x16B92AC2C557F472LL;
    v20.m128_u64[0] = 0x36A8B25B9D4CD156LL;
    v20.m128_u64[1] = 0x1F8EE6A0E092C958LL;
    v23.m128_u64[0] = 0xDC16F237A0F786F9uLL;
    v23.m128_u64[1] = 0x7AD85FB6B73EA206LL;
    v24.m128_u64[0] = 0x36A8CB29F221B41BLL;
    v24.m128_u64[1] = 0x1F8EE6A0E092C958LL;
    v19 = _mm_xor_ps(v19, v23);
    v20 = _mm_xor_ps(v20, v24);                 // ntdll.dll?
    if ( a2 && *a2 == 23117 )
    {
      FindFuncByOrdinalOrName(a2, &v19, &v23);
      v6 = v23.m128_u64[0];
    }
    else
    {
      v6 = 0;
    }
    v19.m128_u64[0] = 0x98729358EC85E2B5uLL;
    v19.m128_u64[1] = 0x7AD85FB6B73ECE6ALL;
    v23.m128_u64[0] = 0xDC16F237A0F786F9uLL;
    v23.m128_u64[1] = 0x7AD85FB6B73EA206LL;
    v19 = _mm_xor_ps(v19, v23);                 // kernel32.dll?
    if ( a2 && *a2 == 23117 )
    {
      FindFuncByOrdinalOrName(a2, &v19, &v23);
      v8 = v23.m128_u64[0];
    }
    else
    {
      v8 = 0;
    }
    v19.m128_u64[0] = 0xB0578644C5A3F1A3uLL;
    v19.m128_u64[1] = 0x7AD85FB6B74AD063LL;
    v23.m128_u64[0] = 0xDC16F237A0F786F9uLL;
    v23.m128_u64[1] = 0x7AD85FB6B73EA206LL;
    v19 = _mm_xor_ps(v19, v23);                 // user32.dll?
    if ( a2 && *a2 == 23117 )
    {
      FindFuncByOrdinalOrName(a2, &v19, &v23);
      v9 = v23.m128_u64[0];
      if ( !v8 )
      {
LABEL_25:
        v19.m128_u64[0] = 0xA8369652CC9EE7BFuLL;
        v19.m128_u64[1] = 0x1FAC3ED5D8528269LL;
        v20.m128_u64[0] = 0x52C9A4658045F83BLL;
        v20.m128_u64[1] = 0x1F8EE6A0CEFEA51CLL;
        v23.m128_u64[0] = 0xDC16F237A0F786F9uLL;
        v23.m128_u64[1] = 0x7AD85FB6B73EA206LL;
        v24.m128_u64[0] = 0x36A8CB29F221B41BLL;
        v24.m128_u64[1] = 0x1F8EE6A0E092C958LL;
        v19 = _mm_xor_ps(v19, v23);
        v20 = _mm_xor_ps(v20, v24);             // Failed to find ntdll\n
        MainLogFunction(128, &unk_14016FCE0, &v19);
        if ( !v6 )
        {
LABEL_26:
          v19.m128_u64[0] = 0xA8369652CC9EE7BFuLL;
          v19.m128_u64[1] = 0x1FAC3ED5D8528269LL;
          v20.m128_u64[0] = 0x53DCA45BA255FA3BLL;
          v20.m128_u64[1] = 0x7EFB92D289C4BD3BLL;
          v21.m128_u64[0] = 0xC32C9394DEF429C1uLL;
          v21.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
          v23.m128_u64[0] = 0xDC16F237A0F786F9uLL;
          v23.m128_u64[1] = 0x7AD85FB6B73EA206LL;
          v24.m128_u64[0] = 0x36A8CB29F221B41BLL;
          v24.m128_u64[1] = 0x1F8EE6A0E092C958LL;
          v25.m128_u64[0] = 0xED55E1FBB39164ADuLL;
          v25.m128_u64[1] = 0xD12C83EA13AA49CAuLL;
          v19 = _mm_xor_ps(v19, v23);
          v20 = _mm_xor_ps(v20, v24);
          v21 = _mm_xor_ps(v21, v25);           // Failed to find kernel32\n
          MainLogFunction(128, &unk_14016FCE0, &v19);
          if ( !v9 )
            goto LABEL_27;
          goto LABEL_20;
        }
LABEL_19:
        if ( !v9 )
        {
LABEL_27:
          v19.m128_u64[0] = 0xA8369652CC9EE7BFuLL;
          v19.m128_u64[1] = 0x1FAC3ED5D8528269LL;
          v20.m128_u64[0] = 0x77DCB84CA656EE3BLL;
          v20.m128_u64[1] = 0x1F8EE68E94E0AC34LL;
          v23.m128_u64[0] = 0xDC16F237A0F786F9uLL;
          v23.m128_u64[1] = 0x7AD85FB6B73EA206LL;
          v24.m128_u64[0] = 0x36A8CB29F221B41BLL;
          v24.m128_u64[1] = 0x1F8EE6A0E092C958LL;
          v19 = _mm_xor_ps(v19, v23);
          v20 = _mm_xor_ps(v20, v24);           // Failed to find user32\n
          MainLogFunction(128, &unk_14016FCE0, &v19);
          v7 = -1073741823;
LABEL_28:
          KeUnstackDetachProcess(&ApcState);
LABEL_29:
          ObfDereferenceObject(Process);
          if ( (v12 ^ v26) == _security_cookie )
            return v7;
LABEL_7:
          __debugbreak();
        }
LABEL_20:
        v7 = -1073741823;
        if ( v6 != 0 && v8 != 0 )
        {
          v10 = DynamicHookCreate(a2, v8, v9, v6, v13);
          if ( v10 )
          {
            v17 = -23;
            v14 = 0;
            v23.m128_u64[0] = v9;
            v19.m128_u64[0] = 5;
            v18 = v10 - v9 - 5;
            v7 = sub_14006EAB0(-1, &v23, &v19, 64, &v14);
            if ( v7 >= 0 )
            {
              sub_14006EA60(-1, v9, &v17, 5, v16);
              sub_14006EAB0(-1, &v23, &v19, v14, &v14);
            }
          }
        }
        goto LABEL_28;
      }
    }
    else
    {
      v9 = 0;
      if ( !v8 )
        goto LABEL_25;
    }
    if ( !v6 )
      goto LABEL_26;
    goto LABEL_19;
  }
  v7 = v5;
  if ( (v12 ^ v26) != _security_cookie )
    goto LABEL_7;
  return v7;
}

__int64 __fastcall HookOnDllMain(void *ProcessID, _WORD *DllBase, __int64 Parameter)
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

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