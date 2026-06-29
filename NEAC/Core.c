NTSTATUS __fastcall ManualFunctionsResolver(__int64 a1)
{
  // [COLLAPSED LOCAL DECLARATIONS. PRESS NUMPAD "+" TO EXPAND]

  memset(&VersionInformation.dwMajorVersion, 0, 280);
  KeInitializeEvent(&Event, NotificationEvent, 0);
  result = KernelHooksCheck();
  if ( result < 0 )
    return result;
  VersionInformation.dwOSVersionInfoSize = 284;
  result = RtlGetVersion(&VersionInformation);
  if ( result )
    return result;
  *(a1 + 4) = (VersionInformation.dwMajorVersion << 8) | (16 * VersionInformation.dwMinorVersion) | v414;
  *a1 = VersionInformation.dwBuildNumber;
  if ( qword_14115DF18 )
  {
    v3 = *(qword_14115DF18 + *(qword_14115DF18 + 15) + 120);
    if ( *(qword_14115DF18 + v3 + 24) )
      sub_14006F3C0(
        a1,
        qword_14115DF18 + *(qword_14115DF18 + v3 + 32),
        qword_14115DF18,
        qword_14115DF18 + *(qword_14115DF18 + v3 + 36),
        qword_14115DF18 + *(qword_14115DF18 + v3 + 28),
        qword_14115DF18 + v3 + 24);
  }
  v403.m128_u64[0] = 0x6A7F82B31059EEC1LL;
  v403.m128_u64[1] = 0x54BCE50B15736EA1LL;
  v404.m128_u64[0] = 0x5CAB459272EAD505LL;
  v404.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v406.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
  v406.m128_u64[1] = 0x54D5E54D151D6EC4LL;
  v407.m128_u64[0] = 0x5CAB4592728FD569LL;
  v407.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v403 = _mm_xor_ps(v403, v406);
  v404 = _mm_xor_ps(v404, v407);                // IoCreateDriver
  SystemRoutineName = 0;
  v4 = &v403;
  v5 = 32764;
  if ( v403.m128_i16[0] )
  {
    while ( 1 )
    {
      if ( !v4->m128_i16[1] )
      {
        LOWORD(v5) = v5 + 2;
        goto LABEL_15;
      }
      if ( !v4->m128_i16[2] )
        break;
      if ( !v5 )
        goto LABEL_16;
      if ( !v4->m128_i16[3] )
        goto LABEL_15;
      v4 = (v4 + 8);
      v5 -= 4;
      if ( !v4->m128_i16[0] )
        goto LABEL_12;
    }
    LOWORD(v5) = v5 + 1;
  }
  else
  {
LABEL_12:
    LOWORD(v5) = v5 + 3;
  }
LABEL_15:
  v6 = 2 * v5;
  SystemRoutineName.Length = v6 ^ 0xFFFE;
  SystemRoutineName.MaximumLength = -v6;
  SystemRoutineName.Buffer = &v403;
LABEL_16:
  SystemRoutineAddress = MmGetSystemRoutineAddress(&SystemRoutineName);
  CheckForAllDriversInSystem(LookingForKernelInMem, SystemRoutineAddress);
  v8 = KernelStart;
  v403.m128_u64[0] = 0x3976F099657C9AC1LL;
  v403.m128_u64[1] = 0x32BBAC2070691DBDLL;
  v404.m128_u64[0] = 0x32C42CE613E2A706LL;
  v404.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v406.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
  v406.m128_u64[1] = 0x54D5E54D151D6EC4LL;
  v407.m128_u64[0] = 0x5CAB4592728FD569LL;
  v407.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v403 = _mm_xor_ps(v403, v406);
  v404 = _mm_xor_ps(v404, v407);                // ExAllocatePool
  v337 = a1;
  if ( KernelStart
    && (v9 = KernelStart + *(KernelStart + 15), v9 != -24LL)
    && (v10 = KernelStart + *(v9 + 34)) != 0
    && (v11 = *(v9 + 35)) != 0 )
  {
    v12 = 0;
    v13 = *(v10 + 6) - 1;
    if ( v13 >= 0 )
    {
      v381 = v11;
      v14 = KernelStart + *(v10 + 8);
      v338 = v10;
      v360 = KernelStart + *(v10 + 9);
      v15 = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          v16 = (v15 + v13) >> 1;
          v17 = strcmp(&v403, &v8[*&v14[4 * v16]]);
          if ( v17 >= 0 )
            break;
          v13 = v16 - 1;
          if ( v16 - 1 < v15 )
            goto LABEL_28;
        }
        if ( !v17 )
          break;
        v15 = v16 + 1;
        if ( v13 < v16 + 1 )
          goto LABEL_28;
      }
      v36 = *&v360[2 * v16];
      if ( *(v338 + 5) <= v36 )
      {
        v12 = 0;
      }
      else
      {
        v37 = &v8[*&v8[4 * v36 + *(v338 + 7)]];
        v12 = 0;
        if ( &v338[v381] <= v37 )
          v12 = v37;
        if ( v37 <= v338 )
          v12 = v37;
      }
    }
  }
  else
  {
    v12 = 0;
  }
LABEL_28:
  *(a1 + 160) = v12;
  v403.m128_u64[0] = 0x1860C49972429CDFLL;
  v403.m128_u64[1] = 0x54D5E54D717C0B96LL;
  v406.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
  v406.m128_u64[1] = 0x54D5E54D151D6EC4LL;
  v403 = _mm_xor_ps(v403, v406);                // NtOpenProcess
  if ( v8 && (v18 = &v8[*(v8 + 15)], v18 != -24LL) && (v19 = &v8[*(v18 + 34)]) != 0 && (v20 = *(v18 + 35)) != 0 )
  {
    v339 = v20;
    v21 = 0;
    v22 = *(v19 + 6) - 1;
    if ( v22 >= 0 )
    {
      v23 = &v8[*(v19 + 8)];
      v361 = v19;
      v382 = &v8[*(v19 + 9)];
      v24 = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          v25 = (v24 + v22) >> 1;
          v26 = strcmp(&v403, &v8[*&v23[4 * v25]]);
          if ( v26 >= 0 )
            break;
          v22 = v25 - 1;
          if ( v25 - 1 < v24 )
            goto LABEL_40;
        }
        if ( !v26 )
          break;
        v24 = v25 + 1;
        if ( v22 < v25 + 1 )
          goto LABEL_40;
      }
      v38 = *&v382[2 * v25];
      if ( *(v361 + 5) <= v38 )
      {
        v21 = 0;
      }
      else
      {
        v39 = &v8[*&v8[4 * v38 + *(v361 + 7)]];
        v21 = 0;
        if ( &v361[v339] <= v39 )
          v21 = v39;
        if ( v39 <= v361 )
          v21 = v39;
      }
    }
  }
  else
  {
    v21 = 0;
  }
LABEL_40:
  *(a1 + 704) = v21;
  v403.m128_u64[0] = 0x1860C49972429CDFLL;
  v403.m128_u64[1] = 0x54D5E52861741C93LL;
  v406.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
  v406.m128_u64[1] = 0x54D5E54D151D6EC4LL;
  v403 = _mm_xor_ps(v403, v406);                // NtOpenThread
  if ( v8 )
  {
    v27 = &v8[*(v8 + 15)];
    if ( v27 != -24LL && (v28 = &v8[*(v27 + 34)]) != 0 && (v29 = *(v27 + 35)) != 0 )
    {
      v30 = 0;
      v31 = *(v28 + 6) - 1;
      if ( v31 >= 0 )
      {
        v383 = v29;
        v32 = &v8[*(v28 + 8)];
        v340 = v28;
        v362 = &v8[*(v28 + 9)];
        v33 = 0;
        while ( 1 )
        {
          while ( 1 )
          {
            v34 = (v33 + v31) >> 1;
            v35 = strcmp(&v403, &v8[*&v32[4 * v34]]);
            if ( v35 >= 0 )
              break;
            v31 = v34 - 1;
            if ( v34 - 1 < v33 )
              goto LABEL_76;
          }
          if ( !v35 )
            break;
          v33 = v34 + 1;
          if ( v31 < v34 + 1 )
            goto LABEL_76;
        }
        v40 = *&v362[2 * v34];
        if ( *(v340 + 5) <= v40 )
        {
          v30 = 0;
        }
        else
        {
          v41 = &v8[*&v8[4 * v40 + *(v340 + 7)]];
          v30 = 0;
          if ( &v340[v383] <= v41 )
            v30 = v41;
          if ( v41 <= v340 )
            v30 = v41;
        }
      }
    }
    else
    {
      v30 = 0;
    }
  }
  else
  {
    v30 = 0;
  }
LABEL_76:
  *(a1 + 712) = v30;
  v403.m128_u64[0] = 0x2376F099657C9AC1LL;
  v403.m128_u64[1] = 0x3DA18420677208AALL;
  v404.m128_u64[0] = 0x2FCE26FD00DFBB06LL;
  v404.m128_u64[1] = 0x919655DB2FEDD645uLL;
  v406.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
  v406.m128_u64[1] = 0x54D5E54D151D6EC4LL;
  v407.m128_u64[0] = 0x5CAB4592728FD569LL;
  v407.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v403 = _mm_xor_ps(v403, v406);
  v404 = _mm_xor_ps(v404, v407);                // NtQueryInformationProcess
  if ( v8 && (v42 = &v8[*(v8 + 15)], v42 != -24LL) && (v43 = &v8[*(v42 + 34)]) != 0 && (v44 = *(v42 + 35)) != 0 )
  {
    v45 = 0;
    v46 = *(v43 + 6) - 1;
    if ( v46 >= 0 )
    {
      v384 = v44;
      v47 = &v8[*(v43 + 8)];
      v341 = v43;
      v363 = &v8[*(v43 + 9)];
      v48 = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          v49 = (v48 + v46) >> 1;
          v50 = strcmp(&v403, &v8[*&v47[4 * v49]]);
          if ( v50 >= 0 )
            break;
          v46 = v49 - 1;
          if ( v49 - 1 < v48 )
            goto LABEL_88;
        }
        if ( !v50 )
          break;
        v48 = v49 + 1;
        if ( v46 < v49 + 1 )
          goto LABEL_88;
      }
      v167 = *&v363[2 * v49];
      if ( *(v341 + 5) <= v167 )
      {
        v45 = 0;
      }
      else
      {
        v168 = &v8[*&v8[4 * v167 + *(v341 + 7)]];
        v45 = 0;
        if ( &v341[v384] <= v168 )
          v45 = v168;
        if ( v168 <= v341 )
          v45 = v168;
      }
    }
  }
  else
  {
    v45 = 0;
  }
LABEL_88:
  *(a1 + 720) = v45;
  v403.m128_u64[0] = 0xB60CE88757E9DDFLL;
  v403.m128_u64[1] = 0x3B9B802A747027A0LL;
  v404.m128_u64[0] = 0x28DE2AC00BE9BC1DLL;
  v404.m128_u64[1] = 0x919655DB2F88B85FuLL;
  v406.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
  v406.m128_u64[1] = 0x54D5E54D151D6EC4LL;
  v407.m128_u64[0] = 0x5CAB4592728FD569LL;
  v407.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v403 = _mm_xor_ps(v403, v406);
  v404 = _mm_xor_ps(v404, v407);                // NtSetInformationProcess
  if ( v8 && (v51 = &v8[*(v8 + 15)], v51 != -24LL) && (v52 = &v8[*(v51 + 34)]) != 0 && (v53 = *(v51 + 35)) != 0 )
  {
    v54 = 0;
    v55 = *(v52 + 6) - 1;
    if ( v55 >= 0 )
    {
      v409 = v53;
      v56 = &v8[*(v52 + 8)];
      v364 = v52;
      v385 = &v8[*(v52 + 9)];
      v57 = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          v58 = (v57 + v55) >> 1;
          v59 = strcmp(&v403, &v8[*&v56[4 * v58]]);
          if ( v59 >= 0 )
            break;
          v55 = v58 - 1;
          if ( v58 - 1 < v57 )
            goto LABEL_98;
        }
        if ( !v59 )
          break;
        v57 = v58 + 1;
        if ( v55 < v58 + 1 )
        {
LABEL_98:
          a1 = v337;
          goto LABEL_99;
        }
      }
      v169 = *&v385[2 * v58];
      if ( *(v364 + 5) <= v169 )
      {
        v54 = 0;
      }
      else
      {
        v170 = &v8[*&v8[4 * v169 + *(v364 + 7)]];
        v54 = 0;
        if ( &v409[v364] <= v170 )
          v54 = v170;
        if ( v170 <= v364 )
          v54 = v170;
      }
      a1 = v337;
    }
  }
  else
  {
LABEL_99:
    v54 = 0;
  }
  *(a1 + 408) = v54;
  v60 = *a1;
  if ( *a1 >= 0x3FABu )
  {
    v403.m128_u64[0] = 0xB60CE88757E9DDFLL;
    v403.m128_u64[1] = 0x3B9B802A747027A0LL;
    v404.m128_u64[0] = 0x28DE2AC00BE9BC1DLL;
    v404.m128_u64[1] = 0x919655A36A88B85FuLL;
    v406.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
    v406.m128_u64[1] = 0x54D5E54D151D6EC4LL;
    v407.m128_u64[0] = 0x5CAB4592728FD569LL;
    v407.m128_u64[1] = 0x919655DB2FEDD636uLL;
    v403 = _mm_xor_ps(v403, v406);
    v404 = _mm_xor_ps(v404, v407);              // NtQuerySystemInformation
    if ( v8 && (v61 = &v8[*(v8 + 15)], v61 != -24LL) && (v62 = &v8[*(v61 + 34)]) != 0 && (v63 = *(v61 + 35)) != 0 )
    {
      v64 = 0;
      v65 = *(v62 + 6) - 1;
      if ( v65 >= 0 )
      {
        v409 = v63;
        v342 = v60;
        v66 = &v8[*(v62 + 8)];
        v365 = v62;
        v386 = &v8[*(v62 + 9)];
        v67 = 0;
        while ( 1 )
        {
          while ( 1 )
          {
            v68 = (v65 + v67) >> 1;
            v69 = strcmp(&v403, &v8[*&v66[4 * v68]]);
            if ( v69 >= 0 )
              break;
            v65 = v68 - 1;
            if ( v68 - 1 < v67 )
              goto LABEL_650;
          }
          if ( !v69 )
            break;
          v67 = v68 + 1;
          if ( v65 < v68 + 1 )
            goto LABEL_650;
        }
        v203 = *&v386[2 * v68];
        if ( *(v365 + 5) <= v203 )
        {
          v64 = 0;
        }
        else
        {
          v204 = &v8[*&v8[4 * v203 + *(v365 + 7)]];
          v64 = 0;
          if ( &v409[v365] <= v204 )
            v64 = v204;
          if ( v204 <= v365 )
            v64 = v204;
        }
LABEL_650:
        a1 = v337;
        v60 = v342;
      }
    }
    else
    {
      v64 = 0;
    }
    *(a1 + 416) = v64;
  }
  v403.m128_u64[0] = 0xF79ED91757F9DDFLL;
  v403.m128_u64[1] = 0x33B48804717C0188LL;
  v404.m128_u64[0] = 0xED223FB06E09B0CLL;
  v404.m128_u64[1] = 0x919630B54699A359uLL;
  v406.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
  v406.m128_u64[1] = 0x54D5E54D151D6EC4LL;
  v407.m128_u64[0] = 0x5CAB4592728FD569LL;
  v407.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v403 = _mm_xor_ps(v403, v406);
  v404 = _mm_xor_ps(v404, v407);                // NtQuerySystemInformationEx
  if ( v8 && (v70 = &v8[*(v8 + 15)], v70 != -24LL) && (v71 = &v8[*(v70 + 34)]) != 0 && (v72 = *(v70 + 35)) != 0 )
  {
    v73 = 0;
    v74 = *(v71 + 6) - 1;
    if ( v74 >= 0 )
    {
      v409 = v72;
      v343 = v60;
      v75 = &v8[*(v71 + 8)];
      v366 = v71;
      v387 = &v8[*(v71 + 9)];
      v76 = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          v77 = (v76 + v74) >> 1;
          v78 = strcmp(&v403, &v8[*&v75[4 * v77]]);
          if ( v78 >= 0 )
            break;
          v74 = v77 - 1;
          if ( v77 - 1 < v76 )
            goto LABEL_364;
        }
        if ( !v78 )
          break;
        v76 = v77 + 1;
        if ( v74 < v77 + 1 )
          goto LABEL_364;
      }
      v171 = *&v387[2 * v77];
      if ( *(v366 + 5) <= v171 )
      {
        v73 = 0;
      }
      else
      {
        v172 = &v8[*&v8[4 * v171 + *(v366 + 7)]];
        v73 = 0;
        if ( &v409[v366] <= v172 )
          v73 = v172;
        if ( v172 <= v366 )
          v73 = v172;
      }
LABEL_364:
      a1 = v337;
      v60 = v343;
    }
  }
  else
  {
    v73 = 0;
  }
  *(a1 + 432) = v73;
  v403.m128_u64[0] = 0xF7DC188757E9DDFLL;
  v403.m128_u64[1] = 0x35B0972541781AA5LL;
  v404.m128_u64[0] = 0xED223FB06E09B0DLL;
  v404.m128_u64[1] = 0x919630B54699A359uLL;
  v406.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
  v406.m128_u64[1] = 0x54D5E54D151D6EC4LL;
  v407.m128_u64[0] = 0x5CAB4592728FD569LL;
  v407.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v403 = _mm_xor_ps(v403, v406);
  v404 = _mm_xor_ps(v404, v407);                // NtAllocateVirtualMemory
  if ( v8 && (v79 = &v8[*(v8 + 15)], v79 != -24LL) && (v80 = &v8[*(v79 + 34)]) != 0 && (v81 = *(v79 + 35)) != 0 )
  {
    v82 = 0;
    v83 = *(v80 + 6) - 1;
    if ( v83 >= 0 )
    {
      v410 = v81;
      v344 = v60;
      v84 = &v8[*(v80 + 8)];
      v388 = v80;
      v409 = &v8[*(v80 + 9)];
      v85 = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          v86 = (v85 + v83) >> 1;
          v87 = strcmp(&v403, &v8[*&v84[4 * v86]]);
          if ( v87 >= 0 )
            break;
          v83 = v86 - 1;
          if ( v86 - 1 < v85 )
            goto LABEL_366;
        }
        if ( !v87 )
          break;
        v85 = v86 + 1;
        if ( v83 < v86 + 1 )
          goto LABEL_366;
      }
      v173 = *&v409[2 * v86];
      if ( *(v388 + 5) <= v173 )
      {
        v82 = 0;
      }
      else
      {
        v174 = &v8[*&v8[4 * v173 + *(v388 + 7)]];
        v82 = 0;
        if ( &v388[v410] <= v174 )
          v82 = v174;
        if ( v174 <= v388 )
          v82 = v174;
      }
LABEL_366:
      a1 = v337;
      v60 = v344;
    }
  }
  else
  {
    v82 = 0;
  }
  *(a1 + 424) = v82;
  v403.m128_u64[0] = 0xF7DC188757E9DDFLL;
  v403.m128_u64[1] = 0x31B68A3F45781AA5LL;
  v404.m128_u64[0] = 0x25CD2CE61DC1A61ALL;
  v404.m128_u64[1] = 0x91F33BB25B98B964uLL;
  v406.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
  v406.m128_u64[1] = 0x54D5E54D151D6EC4LL;
  v407.m128_u64[0] = 0x5CAB4592728FD569LL;
  v407.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v403 = _mm_xor_ps(v403, v406);
  v404 = _mm_xor_ps(v404, v407);
  if ( v8 && (v88 = &v8[*(v8 + 15)], v88 != -24LL) && (v89 = &v8[*(v88 + 34)]) != 0 && (v90 = *(v88 + 35)) != 0 )
  {
    v91 = 0;
    v92 = *(v89 + 6) - 1;
    if ( v92 >= 0 )
    {
      v410 = v90;
      v345 = v60;
      v93 = &v8[*(v89 + 8)];
      v389 = v89;
      v409 = &v8[*(v89 + 9)];
      v94 = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          v95 = (v92 + v94) >> 1;
          v96 = strcmp(&v403, &v8[*&v93[4 * v95]]);
          if ( v96 >= 0 )
            break;
          v92 = v95 - 1;
          if ( v95 - 1 < v94 )
            goto LABEL_148;
        }
        if ( !v96 )
          break;
        v94 = v95 + 1;
        if ( v92 < v95 + 1 )
        {
LABEL_148:
          a1 = v337;
          v60 = v345;
          goto LABEL_149;
        }
      }
      v175 = *&v409[2 * v95];
      if ( *(v389 + 5) <= v175 )
      {
        v91 = 0;
      }
      else
      {
        v176 = &v8[*&v8[4 * v175 + *(v389 + 7)]];
        v91 = 0;
        if ( &v389[v410] <= v176 )
          v91 = v176;
        if ( v176 <= v389 )
          v91 = v176;
      }
      a1 = v337;
      v60 = v345;
    }
  }
  else
  {
LABEL_149:
    v91 = 0;
  }
  *(a1 + 392) = v91;
  if ( v60 >= 0x1770 )
  {
    v403.m128_u64[0] = 0xF7DC188757E9DDFLL;
    v403.m128_u64[1] = 0x31B68A3F45781AA5LL;
    v404.m128_u64[0] = 0x25CD2CE61DC1A61ALL;
    v404.m128_u64[1] = 0xD4F33BB25B98B964uLL;
    v405.m128_u64[0] = 0x7B4E72C06E151B0BLL;
    v405.m128_u64[1] = 0xAB2A09817ACB3C58uLL;
    v406.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
    v406.m128_u64[1] = 0x54D5E54D151D6EC4LL;
    v407.m128_u64[0] = 0x5CAB4592728FD569LL;
    v407.m128_u64[1] = 0x919655DB2FEDD636uLL;
    v408.m128_u64[0] = 0x7B4E72C06E151B73LL;
    v408.m128_u64[1] = 0xAB2A09817ACB3C58uLL;
    v403 = _mm_xor_ps(v403, v406);
    v404 = _mm_xor_ps(v404, v407);
    v405 = _mm_xor_ps(v405, v408);              // NtProtectVirtualMemoryEx
    if ( v8 && (v97 = &v8[*(v8 + 15)], v97 != -24LL) && (v98 = &v8[*(v97 + 34)]) != 0 && (v99 = *(v97 + 35)) != 0 )
    {
      v100 = 0;
      v101 = *(v98 + 6) - 1;
      if ( v101 >= 0 )
      {
        v390 = v99;
        v102 = &v8[*(v98 + 8)];
        v346 = v98;
        v367 = &v8[*(v98 + 9)];
        v103 = 0;
        while ( 1 )
        {
          while ( 1 )
          {
            v104 = (v101 + v103) >> 1;
            v105 = strcmp(&v403, &v8[*&v102[4 * v104]]);
            if ( v105 >= 0 )
              break;
            v101 = v104 - 1;
            if ( v104 - 1 < v103 )
              goto LABEL_652;
          }
          if ( !v105 )
            break;
          v103 = v104 + 1;
          if ( v101 < v104 + 1 )
            goto LABEL_652;
        }
        v205 = *&v367[2 * v104];
        if ( *(v346 + 5) <= v205 )
        {
          v100 = 0;
        }
        else
        {
          v206 = &v8[*&v8[4 * v205 + *(v346 + 7)]];
          v100 = 0;
          if ( &v346[v390] <= v206 )
            v100 = v206;
          if ( v206 <= v346 )
            v100 = v206;
        }
LABEL_652:
        a1 = v337;
      }
    }
    else
    {
      v100 = 0;
    }
    *(a1 + 400) = v100;
  }
  v403.m128_u64[0] = 0xB7FEF9353419ADDLL;
  v403.m128_u64[1] = 0x2DA78A2070500BB6LL;
  v404.m128_u64[0] = 0x5CAB4592728FD569LL;
  v404.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v406.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
  v406.m128_u64[1] = 0x54D5E54D151D6EC4LL;
  v407.m128_u64[0] = 0x5CAB4592728FD569LL;
  v407.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v403 = _mm_xor_ps(v403, v406);
  v404 = _mm_xor_ps(v404, v407);                // NtMapViewOfSection
  if ( v8 && (v106 = &v8[*(v8 + 15)], v106 != -24LL) && (v107 = &v8[*(v106 + 34)]) != 0 && (v108 = *(v106 + 35)) != 0 )
  {
    v109 = 0;
    v110 = *(v107 + 6) - 1;
    if ( v110 >= 0 )
    {
      v391 = v108;
      v111 = &v8[*(v107 + 8)];
      v347 = v107;
      v368 = &v8[*(v107 + 9)];
      v112 = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          v113 = (v110 + v112) >> 1;
          v114 = strcmp(&v403, &v8[*&v111[4 * v113]]);
          if ( v114 >= 0 )
            break;
          v110 = v113 - 1;
          if ( v113 - 1 < v112 )
            goto LABEL_370;
        }
        if ( !v114 )
          break;
        v112 = v113 + 1;
        if ( v110 < v113 + 1 )
          goto LABEL_370;
      }
      v177 = *&v368[2 * v113];
      if ( *(v347 + 5) <= v177 )
      {
        v109 = 0;
      }
      else
      {
        v178 = &v8[*&v8[4 * v177 + *(v347 + 7)]];
        v109 = 0;
        if ( &v347[v391] <= v178 )
          v109 = v178;
        if ( v178 <= v347 )
          v109 = v178;
      }
LABEL_370:
      a1 = v337;
    }
  }
  else
  {
    v109 = 0;
  }
  *(a1 + 592) = v109;
  v403.m128_u64[0] = 0x1F7BF29D53419ADDLL;
  v403.m128_u64[1] = 0x2CB091237A5E0BB6LL;
  v404.m128_u64[0] = 0x5CAB4592728FD51DLL;
  v404.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v406.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
  v406.m128_u64[1] = 0x54D5E54D151D6EC4LL;
  v407.m128_u64[0] = 0x5CAB4592728FD569LL;
  v407.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v403 = _mm_xor_ps(v403, v406);
  v404 = _mm_xor_ps(v404, v407);                // NtUnmapViewOfSection
  if ( v8 && (v115 = &v8[*(v8 + 15)], v115 != -24LL) && (v116 = &v8[*(v115 + 34)]) != 0 && (v117 = *(v115 + 35)) != 0 )
  {
    v118 = 0;
    v119 = *(v116 + 6) - 1;
    if ( v119 >= 0 )
    {
      v392 = v117;
      v120 = &v8[*(v116 + 8)];
      v348 = v116;
      v369 = &v8[*(v116 + 9)];
      v121 = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          v122 = (v121 + v119) >> 1;
          v123 = strcmp(&v403, &v8[*&v120[4 * v122]]);
          if ( v123 >= 0 )
            break;
          v119 = v122 - 1;
          if ( v122 - 1 < v121 )
            goto LABEL_186;
        }
        if ( !v123 )
          break;
        v121 = v122 + 1;
        if ( v119 < v122 + 1 )
        {
LABEL_186:
          a1 = v337;
          goto LABEL_187;
        }
      }
      v179 = *&v369[2 * v122];
      if ( *(v348 + 5) <= v179 )
      {
        v118 = 0;
      }
      else
      {
        v180 = &v8[*&v8[4 * v179 + *(v348 + 7)]];
        v118 = 0;
        if ( &v348[v392] <= v180 )
          v118 = v180;
        if ( v180 <= v348 )
          v118 = v180;
      }
      a1 = v337;
    }
  }
  else
  {
LABEL_187:
    v118 = 0;
  }
  *(a1 + 600) = v118;
  v403.m128_u64[0] = 0x57BF19942419ADDLL;
  v403.m128_u64[1] = 0x2CB091237A5E0BB6LL;
  v404.m128_u64[0] = 0x5CAB4592728FD51DLL;
  v404.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v406.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
  v406.m128_u64[1] = 0x54D5E54D151D6EC4LL;
  v407.m128_u64[0] = 0x5CAB4592728FD569LL;
  v407.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v403 = _mm_xor_ps(v403, v406);
  v404 = _mm_xor_ps(v404, v407);                // RtlRunOnceExecuteOnce
  if ( v8 && (v124 = &v8[*(v8 + 15)], v124 != -24LL) && (v125 = &v8[*(v124 + 34)]) != 0 && (v126 = *(v124 + 35)) != 0 )
  {
    v127 = 0;
    v128 = *(v125 + 6) - 1;
    if ( v128 >= 0 )
    {
      v393 = v126;
      v129 = &v8[*(v125 + 8)];
      v349 = v125;
      v370 = &v8[*(v125 + 9)];
      v130 = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          v131 = (v128 + v130) >> 1;
          v132 = strcmp(&v403, &v8[*&v129[4 * v131]]);
          if ( v132 >= 0 )
            break;
          v128 = v131 - 1;
          if ( v131 - 1 < v130 )
            goto LABEL_376;
        }
        if ( !v132 )
          break;
        v130 = v131 + 1;
        if ( v128 < v131 + 1 )
          goto LABEL_376;
      }
      v181 = *&v370[2 * v131];
      if ( *(v349 + 5) <= v181 )
      {
        v127 = 0;
      }
      else
      {
        v182 = &v8[*&v8[4 * v181 + *(v349 + 7)]];
        v127 = 0;
        if ( &v349[v393] <= v182 )
          v127 = v182;
        if ( v182 <= v349 )
          v127 = v182;
      }
LABEL_376:
      a1 = v337;
    }
  }
  else
  {
    v127 = 0;
  }
  *(a1 + 608) = v127;
  v403.m128_u64[0] = 0xF67C19B656F8BC4LL;
  v403.m128_u64[1] = 0x54D5E54D6D5805A7LL;
  v406.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
  v406.m128_u64[1] = 0x54D5E54D151D6EC4LL;
  v403 = _mm_xor_ps(v403, v406);                // KeBugCheckEx
  if ( v8 && (v133 = &v8[*(v8 + 15)], v133 != -24LL) && (v134 = &v8[*(v133 + 34)]) != 0 && (v135 = *(v133 + 35)) != 0 )
  {
    v136 = 0;
    v137 = *(v134 + 6) - 1;
    if ( v137 >= 0 )
    {
      v394 = v135;
      v138 = &v8[*(v134 + 8)];
      v350 = v134;
      v371 = &v8[*(v134 + 9)];
      v139 = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          v140 = (v137 + v139) >> 1;
          v141 = strcmp(&v403, &v8[*&v138[4 * v140]]);
          if ( v141 >= 0 )
            break;
          v137 = v140 - 1;
          if ( v140 - 1 < v139 )
            goto LABEL_378;
        }
        if ( !v141 )
          break;
        v139 = v140 + 1;
        if ( v137 < v140 + 1 )
          goto LABEL_378;
      }
      v183 = *&v371[2 * v140];
      if ( *(v350 + 5) <= v183 )
      {
        v136 = 0;
      }
      else
      {
        v184 = &v8[*&v8[4 * v183 + *(v350 + 7)]];
        v136 = 0;
        if ( &v350[v394] <= v184 )
          v136 = v184;
        if ( v184 <= v350 )
          v136 = v184;
      }
LABEL_378:
      a1 = v337;
    }
  }
  else
  {
    v136 = 0;
  }
  *(a1 + 616) = v136;
  v403.m128_u64[0] = 0x1866F78D736C96CALL;
  v403.m128_u64[1] = 0x3AA28A297B683CA1LL;
  v404.m128_u64[0] = 0x35DF26F706E0A739LL;
  v404.m128_u64[1] = 0x919655DB2FEDB859uLL;
  v406.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
  v406.m128_u64[1] = 0x54D5E54D151D6EC4LL;
  v407.m128_u64[0] = 0x5CAB4592728FD569LL;
  v407.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v403 = _mm_xor_ps(v403, v406);
  v404 = _mm_xor_ps(v404, v407);                // ZwUnmapViewOfSection
  if ( v8 && (v142 = &v8[*(v8 + 15)], v142 != -24LL) && (v143 = &v8[*(v142 + 34)]) != 0 && (v144 = *(v142 + 35)) != 0 )
  {
    v145 = 0;
    v146 = *(v143 + 6) - 1;
    if ( v146 >= 0 )
    {
      v395 = v144;
      v147 = &v8[*(v143 + 8)];
      v351 = v143;
      v372 = &v8[*(v143 + 9)];
      v148 = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          v149 = (v146 + v148) >> 1;
          v150 = strcmp(&v403, &v8[*&v147[4 * v149]]);
          if ( v150 >= 0 )
            break;
          v146 = v149 - 1;
          if ( v149 - 1 < v148 )
            goto LABEL_380;
        }
        if ( !v150 )
          break;
        v148 = v149 + 1;
        if ( v146 < v149 + 1 )
          goto LABEL_380;
      }
      v185 = *&v372[2 * v149];
      if ( *(v351 + 5) <= v185 )
      {
        v145 = 0;
      }
      else
      {
        v186 = &v8[*&v8[4 * v185 + *(v351 + 7)]];
        v145 = 0;
        if ( &v351[v395] <= v186 )
          v145 = v186;
        if ( v186 <= v351 )
          v145 = v186;
      }
LABEL_380:
      a1 = v337;
    }
  }
  else
  {
    v145 = 0;
  }
  *(a1 + 632) = v145;
  v403.m128_u64[0] = 0x186BE6BD636483C2LL;
  v403.m128_u64[1] = 0x30BC892C436E1DA1LL;
  v404.m128_u64[0] = 0x5CAB4592728FD569LL;
  v404.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v406.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
  v406.m128_u64[1] = 0x54D5E54D151D6EC4LL;
  v407.m128_u64[0] = 0x5CAB4592728FD569LL;
  v407.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v403 = _mm_xor_ps(v403, v406);
  v404 = _mm_xor_ps(v404, v407);                // NtQueueApcThread
  if ( v8 && (v151 = &v8[*(v8 + 15)], v151 != -24LL) && (v152 = &v8[*(v151 + 34)]) != 0 && (v153 = *(v151 + 35)) != 0 )
  {
    v154 = 0;
    v155 = *(v152 + 6) - 1;
    if ( v155 >= 0 )
    {
      v396 = v153;
      v156 = &v8[*(v152 + 8)];
      v352 = v152;
      v373 = &v8[*(v152 + 9)];
      v157 = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          v158 = (v155 + v157) >> 1;
          v159 = strcmp(&v403, &v8[*&v156[4 * v158]]);
          if ( v159 >= 0 )
            break;
          v155 = v158 - 1;
          if ( v158 - 1 < v157 )
            goto LABEL_382;
        }
        if ( !v159 )
          break;
        v157 = v158 + 1;
        if ( v155 < v158 + 1 )
          goto LABEL_382;
      }
      v187 = *&v373[2 * v158];
      if ( *(v352 + 5) <= v187 )
      {
        v154 = 0;
      }
      else
      {
        v188 = &v8[*&v8[4 * v187 + *(v352 + 7)]];
        v154 = 0;
        if ( &v352[v396] <= v188 )
          v154 = v188;
        if ( v188 <= v352 )
          v154 = v188;
      }
LABEL_382:
      a1 = v337;
    }
  }
  else
  {
    v154 = 0;
  }
  *(a1 + 504) = v154;
  v403.m128_u64[0] = 0xF7DD288756A96CALL;
  v403.m128_u64[1] = 0x30BAA83E607207B2LL;
  v404.m128_u64[0] = 0x5CAB4592728FD50CLL;
  v404.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v406.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
  v406.m128_u64[1] = 0x54D5E54D151D6EC4LL;
  v407.m128_u64[0] = 0x5CAB4592728FD569LL;
  v407.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v403 = _mm_xor_ps(v403, v406);
  v404 = _mm_xor_ps(v404, v407);                // NtOpenSection
  if ( v8 )
  {
    v160 = &v8[*(v8 + 15)];
    if ( v160 != -24LL )
    {
      v161 = &v8[*(v160 + 34)];
      if ( v161 )
      {
        v353 = *(v160 + 35);
        if ( *(v160 + 35) )
        {
          v162 = *(v161 + 6) - 1;
          if ( v162 >= 0 )
          {
            v163 = &v8[*(v161 + 8)];
            v374 = &v8[*(v161 + 9)];
            v164 = 0;
            while ( 1 )
            {
              while ( 1 )
              {
                v165 = (v162 + v164) >> 1;
                v166 = strcmp(&v403, &v8[*&v163[4 * v165]]);
                if ( v166 >= 0 )
                  break;
                v162 = v165 - 1;
                if ( v165 - 1 < v164 )
                  goto LABEL_324;
              }
              if ( !v166 )
                break;
              v164 = v165 + 1;
              if ( v162 < v165 + 1 )
                goto LABEL_324;
            }
            v189 = *&v374[2 * v165];
            if ( *(v161 + 5) > v189 )
            {
              v190 = &v8[*&v8[4 * v189 + *(v161 + 7)]];
              if ( v190 <= v161 || &v161[v353] <= v190 )
              {
                v191 = v337;
                if ( !v190 )
                  goto LABEL_325;
                v336 = v190[1];
                if ( *v190 )
                {
                  if ( !v336 )
                  {
LABEL_659:
                    if ( v190[2] )
                    {
LABEL_660:
                      if ( v190[3] )
                      {
LABEL_661:
                        if ( !v190[4] )
                          goto LABEL_662;
                        goto LABEL_666;
                      }
                      goto LABEL_665;
                    }
                    if ( v190[3] == -61 )
                    {
                      ++v190;
                      goto LABEL_766;
                    }
                    goto LABEL_655;
                  }
                }
                else if ( !v336 )
                {
                  if ( v190[2] == -61 )
                    goto LABEL_766;
                  goto LABEL_659;
                }
                if ( v190[2] )
                  goto LABEL_660;
LABEL_655:
                if ( v190[3] )
                  goto LABEL_661;
                if ( v190[4] != -61 )
                {
LABEL_665:
                  if ( !v190[4] )
                  {
                    if ( v190[5] == -61 )
                    {
                      v190 += 3;
                      goto LABEL_766;
                    }
LABEL_662:
                    if ( !v190[5] )
                    {
                      if ( v190[6] == -61 )
                      {
                        v190 += 4;
                        goto LABEL_766;
                      }
                      goto LABEL_671;
                    }
                    goto LABEL_667;
                  }
LABEL_666:
                  if ( !v190[5] )
                  {
LABEL_671:
                    if ( v190[6] )
                    {
LABEL_672:
                      if ( v190[7] )
                      {
LABEL_673:
                        if ( !v190[8] )
                          goto LABEL_674;
                        goto LABEL_678;
                      }
LABEL_677:
                      if ( !v190[8] )
                      {
                        if ( v190[9] == -61 )
                        {
                          v190 += 7;
                          goto LABEL_766;
                        }
LABEL_674:
                        if ( !v190[9] )
                        {
                          if ( v190[10] == -61 )
                          {
                            v190 += 8;
                            goto LABEL_766;
                          }
                          goto LABEL_683;
                        }
                        goto LABEL_679;
                      }
LABEL_678:
                      if ( !v190[9] )
                      {
LABEL_683:
                        if ( v190[10] )
                        {
LABEL_684:
                          if ( v190[11] )
                          {
LABEL_685:
                            if ( !v190[12] )
                              goto LABEL_686;
                            goto LABEL_690;
                          }
LABEL_689:
                          if ( !v190[12] )
                          {
                            if ( v190[13] == -61 )
                            {
                              v190 += 11;
                              goto LABEL_766;
                            }
LABEL_686:
                            if ( !v190[13] )
                            {
                              if ( v190[14] == -61 )
                              {
                                v190 += 12;
                                goto LABEL_766;
                              }
                              goto LABEL_695;
                            }
                            goto LABEL_691;
                          }
LABEL_690:
                          if ( !v190[13] )
                          {
LABEL_695:
                            if ( v190[14] )
                            {
LABEL_696:
                              if ( v190[15] )
                              {
LABEL_697:
                                if ( !v190[16] )
                                  goto LABEL_698;
                                goto LABEL_702;
                              }
LABEL_701:
                              if ( !v190[16] )
                              {
                                if ( v190[17] == -61 )
                                {
                                  v190 += 15;
                                  goto LABEL_766;
                                }
LABEL_698:
                                if ( !v190[17] )
                                {
                                  if ( v190[18] == -61 )
                                  {
                                    v190 += 16;
                                    goto LABEL_766;
                                  }
                                  goto LABEL_709;
                                }
                                goto LABEL_703;
                              }
LABEL_702:
                              if ( !v190[17] )
                              {
LABEL_709:
                                if ( v190[18] )
                                {
LABEL_710:
                                  if ( v190[19] )
                                  {
LABEL_711:
                                    if ( !v190[20] )
                                      goto LABEL_712;
                                    goto LABEL_718;
                                  }
LABEL_717:
                                  if ( !v190[20] )
                                  {
                                    if ( v190[21] == -61 )
                                    {
                                      v190 += 19;
                                      goto LABEL_766;
                                    }
LABEL_712:
                                    if ( !v190[21] )
                                    {
                                      if ( v190[22] == -61 )
                                      {
                                        v190 += 20;
                                        goto LABEL_766;
                                      }
                                      goto LABEL_725;
                                    }
                                    goto LABEL_719;
                                  }
LABEL_718:
                                  if ( !v190[21] )
                                  {
LABEL_725:
                                    if ( v190[22] )
                                    {
LABEL_726:
                                      if ( v190[23] )
                                      {
LABEL_727:
                                        if ( !v190[24] )
                                          goto LABEL_728;
                                        goto LABEL_734;
                                      }
LABEL_733:
                                      if ( !v190[24] )
                                      {
                                        if ( v190[25] == -61 )
                                        {
                                          v190 += 23;
                                          goto LABEL_766;
                                        }
LABEL_728:
                                        if ( !v190[25] )
                                        {
                                          if ( v190[26] == -61 )
                                          {
                                            v190 += 24;
                                            goto LABEL_766;
                                          }
                                          goto LABEL_741;
                                        }
                                        goto LABEL_735;
                                      }
LABEL_734:
                                      if ( !v190[25] )
                                      {
LABEL_741:
                                        if ( v190[26] )
                                        {
LABEL_742:
                                          if ( v190[27] )
                                          {
LABEL_743:
                                            if ( v190[28] )
                                              goto LABEL_325;
                                            goto LABEL_744;
                                          }
LABEL_749:
                                          if ( v190[28] )
                                            goto LABEL_325;
                                          if ( v190[29] == -61 )
                                          {
                                            v190 += 27;
                                            goto LABEL_766;
                                          }
LABEL_744:
                                          if ( v190[29] || v190[30] != -61 )
                                            goto LABEL_325;
                                          v190 += 28;
                                          goto LABEL_766;
                                        }
                                        if ( v190[27] == -61 )
                                        {
                                          v190 += 25;
                                          goto LABEL_766;
                                        }
LABEL_736:
                                        if ( v190[27] )
                                          goto LABEL_743;
                                        if ( v190[28] == -61 )
                                        {
                                          v190 += 26;
                                          goto LABEL_766;
                                        }
                                        goto LABEL_749;
                                      }
LABEL_735:
                                      if ( v190[26] )
                                        goto LABEL_742;
                                      goto LABEL_736;
                                    }
                                    if ( v190[23] == -61 )
                                    {
                                      v190 += 21;
                                      goto LABEL_766;
                                    }
LABEL_720:
                                    if ( v190[23] )
                                      goto LABEL_727;
                                    if ( v190[24] == -61 )
                                    {
                                      v190 += 22;
                                      goto LABEL_766;
                                    }
                                    goto LABEL_733;
                                  }
LABEL_719:
                                  if ( v190[22] )
                                    goto LABEL_726;
                                  goto LABEL_720;
                                }
                                if ( v190[19] == -61 )
                                {
                                  v190 += 17;
                                  goto LABEL_766;
                                }
LABEL_704:
                                if ( v190[19] )
                                  goto LABEL_711;
                                if ( v190[20] == -61 )
                                {
                                  v190 += 18;
                                  goto LABEL_766;
                                }
                                goto LABEL_717;
                              }
LABEL_703:
                              if ( v190[18] )
                                goto LABEL_710;
                              goto LABEL_704;
                            }
                            if ( v190[15] == -61 )
                            {
                              v190 += 13;
                              goto LABEL_766;
                            }
LABEL_692:
                            if ( v190[15] )
                              goto LABEL_697;
                            if ( v190[16] == -61 )
                            {
                              v190 += 14;
                              goto LABEL_766;
                            }
                            goto LABEL_701;
                          }
LABEL_691:
                          if ( v190[14] )
                            goto LABEL_696;
                          goto LABEL_692;
                        }
                        if ( v190[11] == -61 )
                        {
                          v190 += 9;
                          goto LABEL_766;
                        }
LABEL_680:
                        if ( v190[11] )
                          goto LABEL_685;
                        if ( v190[12] == -61 )
                        {
                          v190 += 10;
                          goto LABEL_766;
                        }
                        goto LABEL_689;
                      }
LABEL_679:
                      if ( v190[10] )
                        goto LABEL_684;
                      goto LABEL_680;
                    }
                    if ( v190[7] == -61 )
                    {
                      v190 += 5;
                      goto LABEL_766;
                    }
LABEL_668:
                    if ( v190[7] )
                      goto LABEL_673;
                    if ( v190[8] == -61 )
                    {
                      v190 += 6;
                      goto LABEL_766;
                    }
                    goto LABEL_677;
                  }
LABEL_667:
                  if ( v190[6] )
                    goto LABEL_672;
                  goto LABEL_668;
                }
                v190 += 2;
LABEL_766:
                *(v337 + 16) = *(v190 - 2);
                goto LABEL_325;
              }
            }
          }
        }
      }
    }
  }
LABEL_324:
  v191 = v337;
LABEL_325:
  v403.m128_u64[0] = 0x3D6AF799657C96CALL;
  v403.m128_u64[1] = 0x54B880395C761CABLL;
  v406.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
  v406.m128_u64[1] = 0x54D5E54D151D6EC4LL;
  v403 = _mm_xor_ps(v403, v406);                // NtMapViewOfSectionEx
  if ( v8 )
  {
    v192 = &v8[*(v8 + 15)];
    if ( v192 != -24LL && (v193 = &v8[*(v192 + 34)]) != 0 && (v194 = *(v192 + 35)) != 0 )
    {
      v195 = 0;
      v196 = *(v193 + 6) - 1;
      if ( v196 >= 0 )
      {
        v397 = v194;
        v197 = &v8[*(v193 + 8)];
        v354 = v193;
        v375 = &v8[*(v193 + 9)];
        v198 = 0;
        while ( 1 )
        {
          while ( 1 )
          {
            v199 = (v196 + v198) >> 1;
            v200 = strcmp(&v403, &v8[*&v197[4 * v199]]);
            if ( v200 >= 0 )
              break;
            v196 = v199 - 1;
            if ( v199 - 1 < v198 )
              goto LABEL_384;
          }
          if ( !v200 )
            break;
          v198 = v199 + 1;
          if ( v196 < v199 + 1 )
            goto LABEL_384;
        }
        v201 = *&v375[2 * v199];
        if ( *(v354 + 5) <= v201 )
        {
          v195 = 0;
        }
        else
        {
          v202 = &v8[*&v8[4 * v201 + *(v354 + 7)]];
          v195 = 0;
          if ( &v354[v397] <= v202 )
            v195 = v202;
          if ( v202 <= v354 )
            v195 = v202;
        }
LABEL_384:
        v191 = v337;
      }
    }
    else
    {
      v195 = 0;
    }
  }
  else
  {
    v195 = 0;
  }
  *(v191 + 640) = v195;
  v403.m128_u64[0] = 0x766D688757E8BC4LL;
  v403.m128_u64[1] = 0x54D5E54D151D1CA1LL;
  v406.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
  v406.m128_u64[1] = 0x54D5E54D151D6EC4LL;
  v403 = _mm_xor_ps(v403, v406);                // NtClose
  if ( v8 && (v207 = &v8[*(v8 + 15)], v207 != -24LL) && (v208 = &v8[*(v207 + 34)]) != 0 && (v209 = *(v207 + 35)) != 0 )
  {
    v210 = 0;
    v211 = *(v208 + 6) - 1;
    if ( v211 >= 0 )
    {
      v398 = v209;
      v212 = &v8[*(v208 + 8)];
      v355 = v208;
      v376 = &v8[*(v208 + 9)];
      v213 = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          v214 = (v211 + v213) >> 1;
          v215 = strcmp(&v403, &v8[*&v212[4 * v214]]);
          if ( v215 >= 0 )
            break;
          v211 = v214 - 1;
          if ( v214 - 1 < v213 )
            goto LABEL_636;
        }
        if ( !v215 )
          break;
        v213 = v214 + 1;
        if ( v211 < v214 + 1 )
          goto LABEL_636;
      }
      v326 = *&v376[2 * v214];
      if ( *(v355 + 5) <= v326 )
      {
        v210 = 0;
      }
      else
      {
        v327 = &v8[*&v8[4 * v326 + *(v355 + 7)]];
        v210 = 0;
        if ( &v355[v398] <= v327 )
          v210 = v327;
        if ( v327 <= v355 )
          v210 = v327;
      }
LABEL_636:
      v191 = v337;
    }
  }
  else
  {
    v210 = 0;
  }
  *(v191 + 648) = v210;
  v403.m128_u64[0] = 0x361CB88756A81C6LL;
  v403.m128_u64[1] = 0x37B4911E797C07B0LL;
  v404.m128_u64[0] = 0x5CAB4592728FD502LL;
  v404.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v406.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
  v406.m128_u64[1] = 0x54D5E54D151D6EC4LL;
  v407.m128_u64[0] = 0x5CAB4592728FD569LL;
  v407.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v403 = _mm_xor_ps(v403, v406);
  v404 = _mm_xor_ps(v404, v407);                // NtDuplicateObject
  if ( v8 && (v216 = &v8[*(v8 + 15)], v216 != -24LL) && (v217 = &v8[*(v216 + 34)]) != 0 && (v218 = *(v216 + 35)) != 0 )
  {
    v219 = 0;
    v220 = *(v217 + 6) - 1;
    if ( v220 >= 0 )
    {
      v399 = v218;
      v221 = &v8[*(v217 + 8)];
      v356 = v217;
      v377 = &v8[*(v217 + 9)];
      v222 = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          v223 = (v220 + v222) >> 1;
          v224 = strcmp(&v403, &v8[*&v221[4 * v223]]);
          if ( v224 >= 0 )
            break;
          v220 = v223 - 1;
          if ( v223 - 1 < v222 )
            goto LABEL_638;
        }
        if ( !v224 )
          break;
        v222 = v223 + 1;
        if ( v220 < v223 + 1 )
          goto LABEL_638;
      }
      v328 = *&v377[2 * v223];
      if ( *(v356 + 5) <= v328 )
      {
        v219 = 0;
      }
      else
      {
        v329 = &v8[*&v8[4 * v328 + *(v356 + 7)]];
        v219 = 0;
        if ( &v356[v399] <= v329 )
          v219 = v329;
        if ( v329 <= v356 )
          v219 = v329;
      }
LABEL_638:
      v191 = v337;
    }
  }
  else
  {
    v219 = 0;
  }
  *(v191 + 656) = v219;
  v403.m128_u64[0] = 0x2F76E39075698BC4LL;
  v403.m128_u64[1] = 0x3ABA8C39607E0BBCLL;
  v404.m128_u64[0] = 0x5CAB21F317FDBD3DLL;
  v404.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v406.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
  v406.m128_u64[1] = 0x54D5E54D151D6EC4LL;
  v407.m128_u64[0] = 0x5CAB4592728FD569LL;
  v407.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v403 = _mm_xor_ps(v403, v406);
  v404 = _mm_xor_ps(v404, v407);                // NtQueryVirtualMemory
  if ( v8 && (v225 = &v8[*(v8 + 15)], v225 != -24LL) && (v226 = &v8[*(v225 + 34)]) != 0 && (v227 = *(v225 + 35)) != 0 )
  {
    v228 = 0;
    v229 = *(v226 + 6) - 1;
    if ( v229 >= 0 )
    {
      v400 = v227;
      v230 = &v8[*(v226 + 8)];
      v357 = v226;
      v378 = &v8[*(v226 + 9)];
      v231 = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          v232 = (v229 + v231) >> 1;
          v233 = strcmp(&v403, &v8[*&v230[4 * v232]]);
          if ( v233 >= 0 )
            break;
          v229 = v232 - 1;
          if ( v232 - 1 < v231 )
            goto LABEL_640;
        }
        if ( !v233 )
          break;
        v231 = v232 + 1;
        if ( v229 < v232 + 1 )
          goto LABEL_640;
      }
      v330 = *&v378[2 * v232];
      if ( *(v357 + 5) <= v330 )
      {
        v228 = 0;
      }
      else
      {
        v331 = &v8[*&v8[4 * v330 + *(v357 + 7)]];
        v228 = 0;
        if ( &v357[v400] <= v331 )
          v228 = v331;
        if ( v331 <= v357 )
          v228 = v331;
      }
LABEL_640:
      v191 = v337;
    }
  }
  else
  {
    v228 = 0;
  }
  *(v191 + 696) = v228;
  v403.m128_u64[0] = 0x1A7AE9937F619DDFLL;
  v403.m128_u64[1] = 0x16A6962876721C94LL;
  v404.m128_u64[0] = 0x2FD820F11DFD8510LL;
  v404.m128_u64[1] = 0x919655DB2FEDB27FuLL;
  v406.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
  v406.m128_u64[1] = 0x54D5E54D151D6EC4LL;
  v407.m128_u64[0] = 0x5CAB4592728FD569LL;
  v407.m128_u64[1] = 0x919655DB2FEDD636uLL;
  v403 = _mm_xor_ps(v403, v406);
  v404 = _mm_xor_ps(v404, v407);                // NtReadVirtualMemory
  if ( v8 && (v234 = &v8[*(v8 + 15)], v234 != -24LL) && (v235 = &v8[*(v234 + 34)]) != 0 && (v236 = *(v234 + 35)) != 0 )
  {
    v237 = 0;
    v238 = *(v235 + 6) - 1;
    if ( v238 >= 0 )
    {
      v401 = v236;
      v239 = &v8[*(v235 + 8)];
      v358 = v235;
      v379 = &v8[*(v235 + 9)];
      v240 = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          v241 = (v238 + v240) >> 1;
          v242 = strcmp(&v403, &v8[*&v239[4 * v241]]);
          if ( v242 >= 0 )
            break;
          v238 = v241 - 1;
          if ( v241 - 1 < v240 )
            goto LABEL_642;
        }
        if ( !v242 )
          break;
        v240 = v241 + 1;
        if ( v238 < v241 + 1 )
          goto LABEL_642;
      }
      v332 = *&v379[2 * v241];
      if ( *(v358 + 5) <= v332 )
      {
        v237 = 0;
      }
      else
      {
        v333 = &v8[*&v8[4 * v332 + *(v358 + 7)]];
        v237 = 0;
        if ( &v358[v401] <= v333 )
          v237 = v333;
        if ( v333 <= v358 )
          v237 = v333;
      }
LABEL_642:
      v191 = v337;
    }
  }
  else
  {
    v237 = 0;
  }
  *(v191 + 728) = v237;
  v403.m128_u64[0] = 0x2E63EE9D534B81C6LL;
  v403.m128_u64[1] = 0x54D5E53F706B07B6LL;
  v406.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
  v406.m128_u64[1] = 0x54D5E54D151D6EC4LL;
  v403 = _mm_xor_ps(v403, v406);                // NtWriteVirtualMemory
  if ( v8 && (v243 = &v8[*(v8 + 15)], v243 != -24LL) && (v244 = &v8[*(v243 + 34)]) != 0 && (v245 = *(v243 + 35)) != 0 )
  {
    v246 = 0;
    v247 = *(v244 + 6) - 1;
    if ( v247 >= 0 )
    {
      v402 = v245;
      v248 = &v8[*(v244 + 8)];
      v359 = v244;
      v380 = &v8[*(v244 + 9)];
      v249 = 0;
      while ( 1 )
      {
        while ( 1 )
        {
          v250 = (v247 + v249) >> 1;
          v251 = strcmp(&v403, &v8[*&v248[4 * v250]]);
          if ( v251 >= 0 )
            break;
          v247 = v250 - 1;
          if ( v250 - 1 < v249 )
            goto LABEL_644;
        }
        if ( !v251 )
          break;
        v249 = v250 + 1;
        if ( v247 < v250 + 1 )
          goto LABEL_644;
      }
      v334 = *&v380[2 * v250];
      if ( *(v359 + 5) <= v334 )
      {
        v246 = 0;
      }
      else
      {
        v335 = &v8[*&v8[4 * v334 + *(v359 + 7)]];
        v246 = 0;
        if ( &v359[v402] <= v335 )
          v246 = v335;
        if ( v335 <= v359 )
          v246 = v335;
      }
LABEL_644:
      v191 = v337;
    }
  }
  else
  {
    v246 = 0;
  }
  *(v191 + 344) = v246;
  if ( ZwQuerySystemInformation(SystemSessionMappedViewInformation|0x80, SystemInformation, 4u, 0) >= 0 )
    *(v191 + 1160) = SystemInformation[0] & 1;
  FindSomeFuncsAddrs(v8);
  v252 = KiWaitAlways;
  if ( !KiWaitAlways )
    v252 = KiWaitNever;
  if ( v252 && (v253 = *(v191 + 80), v252[2] >= v253) )
    v254 = *v252 + (*(*v252 + 4 * v253) >> 4);
  else
    v254 = 0;
  *(v191 + 184) = v254;
  v255 = KiWaitAlways;
  if ( !KiWaitAlways )
    v255 = KiWaitNever;
  if ( v255 && (v256 = *(v191 + 84), v255[2] >= v256) )
    v257 = *v255 + (*(*v255 + 4 * v256) >> 4);
  else
    v257 = 0;
  *(v191 + 192) = v257;
  v258 = KiWaitAlways;
  if ( !KiWaitAlways )
    v258 = KiWaitNever;
  if ( v258 && (v259 = *(v191 + 88), v258[2] >= v259) )
    v260 = *v258 + (*(*v258 + 4 * v259) >> 4);
  else
    v260 = 0;
  *(v191 + 176) = v260;
  v261 = KiWaitAlways;
  if ( !KiWaitAlways )
    v261 = KiWaitNever;
  if ( v261 && (v262 = *(v191 + 76), v261[2] >= v262) )
    v263 = *v261 + (*(*v261 + 4 * v262) >> 4);
  else
    v263 = 0;
  *(v191 + 240) = v263;
  v264 = KiWaitAlways;
  if ( !KiWaitAlways )
    v264 = KiWaitNever;
  if ( v264 && (v265 = *(v191 + 72), v264[2] >= v265) )
    v266 = *v264 + (*(*v264 + 4 * v265) >> 4);
  else
    v266 = 0;
  *(v191 + 208) = v266;
  v267 = KiWaitAlways;
  if ( !KiWaitAlways )
    v267 = KiWaitNever;
  if ( v267 && (v268 = *(v191 + 68), v267[2] >= v268) )
    v269 = *v267 + (*(*v267 + 4 * v268) >> 4);
  else
    v269 = 0;
  *(v191 + 216) = v269;
  v270 = KiWaitAlways;
  if ( !KiWaitAlways )
    v270 = KiWaitNever;
  if ( v270 && (v271 = *(v191 + 56), v270[2] >= v271) )
    v272 = *v270 + (*(*v270 + 4 * v271) >> 4);
  else
    v272 = 0;
  *(v191 + 200) = v272;
  v273 = KiWaitAlways;
  if ( !KiWaitAlways )
    v273 = KiWaitNever;
  if ( v273 && (v274 = *(v191 + 60), v273[2] >= v274) )
    v275 = *v273 + (*(*v273 + 4 * v274) >> 4);
  else
    v275 = 0;
  *(v191 + 224) = v275;
  v276 = KiWaitAlways;
  if ( !KiWaitAlways )
    v276 = KiWaitNever;
  if ( v276 && (v277 = *(v191 + 64), v276[2] >= v277) )
    v278 = *v276 + (*(*v276 + 4 * v277) >> 4);
  else
    v278 = 0;
  *(v191 + 232) = v278;
  v279 = KiWaitAlways;
  if ( !KiWaitAlways )
    v279 = KiWaitNever;
  if ( v279 && (v280 = *(v191 + 100), v279[2] >= v280) )
    v281 = *v279 + (*(*v279 + 4 * v280) >> 4);
  else
    v281 = 0;
  *(v191 + 168) = v281;
  v282 = KiWaitAlways;
  if ( !KiWaitAlways )
    v282 = KiWaitNever;
  if ( v282 && (v283 = *(v191 + 104), v282[2] >= v283) )
    v284 = *v282 + (*(*v282 + 4 * v283) >> 4);
  else
    v284 = 0;
  *(v191 + 248) = v284;
  v285 = KiWaitAlways;
  if ( !KiWaitAlways )
    v285 = KiWaitNever;
  if ( v285 && (v286 = *(v191 + 108), v285[2] >= v286) )
    v287 = *v285 + (*(*v285 + 4 * v286) >> 4);
  else
    v287 = 0;
  *(v191 + 272) = v287;
  v288 = KiWaitAlways;
  if ( !KiWaitAlways )
    v288 = KiWaitNever;
  if ( v288 && (v289 = *(v191 + 116), v288[2] >= v289) )
    v290 = *v288 + (*(*v288 + 4 * v289) >> 4);
  else
    v290 = 0;
  *(v191 + 256) = v290;
  v291 = KiWaitAlways;
  if ( !KiWaitAlways )
    v291 = KiWaitNever;
  if ( v291 && (v292 = *(v191 + 120), v291[2] >= v292) )
    v293 = *v291 + (*(*v291 + 4 * v292) >> 4);
  else
    v293 = 0;
  *(v191 + 288) = v293;
  v294 = KiWaitAlways;
  if ( !KiWaitAlways )
    v294 = KiWaitNever;
  if ( v294 && (v295 = *(v191 + 124), v294[2] >= v295) )
    v296 = *v294 + (*(*v294 + 4 * v295) >> 4);
  else
    v296 = 0;
  *(v191 + 352) = v296;
  v297 = KiWaitAlways;
  if ( !KiWaitAlways )
    v297 = KiWaitNever;
  if ( v297 && (v298 = *(v191 + 128), v297[2] >= v298) )
    v299 = *v297 + (*(*v297 + 4 * v298) >> 4);
  else
    v299 = 0;
  *(v191 + 360) = v299;
  v300 = KiWaitAlways;
  if ( !KiWaitAlways )
    v300 = KiWaitNever;
  if ( v300 && (v301 = *(v191 + 132), v300[2] >= v301) )
    v302 = *v300 + (*(*v300 + 4 * v301) >> 4);
  else
    v302 = 0;
  *(v191 + 368) = v302;
  v303 = KiWaitAlways;
  if ( !KiWaitAlways )
    v303 = KiWaitNever;
  if ( v303 && (v304 = *(v191 + 136), v303[2] >= v304) )
    v305 = *v303 + (*(*v303 + 4 * v304) >> 4);
  else
    v305 = 0;
  *(v191 + 376) = v305;
  v306 = KiWaitAlways;
  if ( !KiWaitAlways )
    v306 = KiWaitNever;
  if ( v306 && (v307 = *(v191 + 140), v306[2] >= v307) )
    v308 = *v306 + (*(*v306 + 4 * v307) >> 4);
  else
    v308 = 0;
  *(v191 + 152) = v308;
  v309 = KiWaitAlways;
  if ( !KiWaitAlways )
    v309 = KiWaitNever;
  if ( v309 && (v310 = *(v191 + 148), v309[2] >= v310) )
    v311 = *v309 + (*(*v309 + 4 * v310) >> 4);
  else
    v311 = 0;
  *(v191 + 328) = v311;
  v312 = KiWaitAlways;
  if ( !KiWaitAlways )
    v312 = KiWaitNever;
  if ( v312 && (v313 = *(v191 + 144), v312[2] >= v313) )
    v314 = *v312 + (*(*v312 + 4 * v313) >> 4);
  else
    v314 = 0;
  *(v191 + 304) = v314;
  v315 = KiWaitAlways;
  if ( !KiWaitAlways )
    v315 = KiWaitNever;
  if ( v315 && (v316 = *(v191 + 96), v315[2] >= v316) )
    v317 = *v315 + (*(*v315 + 4 * v316) >> 4);
  else
    v317 = 0;
  *(v191 + 320) = v317;
  v318 = KiWaitAlways;
  if ( !KiWaitAlways )
    v318 = KiWaitNever;
  if ( v318 && (v319 = *(v191 + 92), v318[2] >= v319) )
    v320 = *v318 + (*(*v318 + 4 * v319) >> 4);
  else
    v320 = 0;
  *(v191 + 312) = v320;
  HookPageFault();
  VerifyShadowTable(v8);
  InitWin32kOffsets(v8);
  ScanWin32kModule(v8);
  AnalyzeAndHookRegisterWindowMessage(v8);
  HookMmProbeAndLockPages(v8);
  HookMmGetSystemRoutineAddress(v8);
  HookStoredKernelRoutine(v8);
  HookStoredKernelRoutine2(v8);
  HookStoredKernelRoutine3(v8);
  HookStoredKernelRoutine4(v8);
  HookStoredKernelRoutine5(v8);
  HookStoredKernelRoutine6(v8);
  HookMmAdjustWorkingSetSize(v8);
  HookMmWorkingSetInternal(v8);
  HookWorkingSetInternalSubroutines(v8);
  HookWorkingSetLargeSubroutine(v8);
  LocateRegistryCallbackList(v8);
  FindMmSessionSpaceStructures(v8);
  KernelMemoryDump(v8);
  PhysicalMemoryScanner(v8);
  FindImageNotifyRoutineBounds();
  FindProcessNotifyRoutineBounds();
  if ( !qword_14115DC90 )
  {
    LOBYTE(v321) = 14;
    v322 = sub_1400444A0(v321);
    if ( v322 )
      ParseKiPageFault(v322, &KernelStart);
  }
  if ( !qword_14115DCF8 )
  {
    v403.m128_u64[0] = 0xB49E79B717D87C4LL;
    v403.m128_u64[1] = 0x74A18A23356902B1LL;
    v404.m128_u64[0] = 0x5CAB45F61CFABA0FLL;
    v404.m128_u64[1] = 0x919655DB2FEDD636uLL;
    v406.m128_u64[0] = 0x6A0F82FC102DEE8FLL;
    v406.m128_u64[1] = 0x54D5E54D151D6EC4LL;
    v407.m128_u64[0] = 0x5CAB4592728FD569LL;
    v407.m128_u64[1] = 0x919655DB2FEDD636uLL;
    v403 = _mm_xor_ps(v403, v406);
    v404 = _mm_xor_ps(v404, v407);              // no m_SystemCallTable
    MainLogFunction(128, &unk_14016FCE0, &v403);
  }
  ClearImageImports(v8);
  InitCodeIntegrityMonitoring();
  v323 = *(v191 + 112);
  if ( *(v191 + 112) )
  {
    v324 = KiWaitAlways;
    if ( !KiWaitAlways )
      v324 = KiWaitNever;
    if ( v324 && v324[2] >= v323 )
      v325 = *v324 + (*(*v324 + 4 * v323) >> 4);
    else
      v325 = 0;
    *(v191 + 280) = v325;
  }
  return 0;
}