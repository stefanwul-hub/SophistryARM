/* 00014e50 FUN_00014e50 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

byte FUN_00014e50(int param_1,char *param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  longdouble lVar9;
  float fVar10;
  float fVar11;
  byte local_405;
  int local_404;
  undefined1 local_3f0 [660];
  char local_15c [332];
  
  if (((*(int *)(param_1 + 0x1d4) == 0) || (param_2 == (char *)0x0)) || (*param_2 == '\0')) {
    return 0;
  }
  FUN_0000a5d4(local_3f0);
  FUN_00009720(local_3f0,param_2);
  local_405 = 1;
LAB_00014ec2:
  while( true ) {
    iVar6 = FUN_00009a68(local_3f0,local_15c,0x140);
    if (iVar6 < 0) {
      Disk_c_vslot_0(local_3f0);
      return local_405;
    }
    if (' ' < local_15c[0]) goto LAB_00014f14;
    if (local_15c[0] == '\0') break;
    iVar7 = 0;
    do {
      iVar6 = iVar7 + 1;
      cVar4 = local_15c[iVar7 + 1];
      if (' ' < cVar4) goto LAB_00014f16;
      iVar7 = iVar6;
    } while (cVar4 != '\0');
  }
  iVar6 = 0;
  cVar4 = '\0';
  goto LAB_00014f1a;
LAB_00014f14:
  iVar6 = 0;
  cVar4 = local_15c[0];
LAB_00014f16:
  if (cVar4 != ';') {
LAB_00014f1a:
    if (((((cVar4 == 'n') || (cVar4 == 'N')) &&
         ((local_15c[iVar6 + 1] == 'o' || (local_15c[iVar6 + 1] == 'O')))) &&
        ((local_15c[iVar6 + 2] == 't' || (local_15c[iVar6 + 2] == 'T')))) &&
       ((local_15c[iVar6 + 3] == 'e' || (local_15c[iVar6 + 3] == 'E')))) {
      pcVar8 = local_15c + iVar6 + 4;
      local_404 = 0;
      cVar4 = *pcVar8;
      iVar6 = iVar6 + 5;
      iVar7 = local_404;
      do {
        if ((byte)(cVar4 - 0x30U) < 10) {
          local_404 = cVar4 + -0x30 + iVar7 * 10;
        }
        else {
          if (cVar4 == '\0') goto LAB_000150b4;
          local_404 = iVar7;
          if (' ' < cVar4) goto code_r0x00014fa7;
        }
        pcVar8 = pcVar8 + 1;
        cVar4 = *pcVar8;
        iVar6 = iVar6 + 1;
        iVar7 = local_404;
      } while( true );
    }
  }
  goto LAB_00014ec2;
code_r0x00014fa7:
  if (cVar4 == '=') {
LAB_000150b4:
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if (iVar7 < 0) {
    local_404 = 0;
  }
  else {
    local_404 = 0x7f;
    if (iVar7 < 0x80) {
      local_404 = iVar7;
    }
  }
  pcVar8 = local_15c + iVar6;
  fVar10 = 0.0;
  cVar4 = *pcVar8;
  do {
    iVar6 = iVar6 + 1;
    if ((byte)(cVar4 - 0x30U) < 10) {
      fVar10 = (fVar10 * 10.0 + (float)(int)cVar4) - 48.0;
    }
    else {
      if (cVar4 == '\0') goto LAB_000150c0;
      if (' ' < cVar4) break;
    }
    pcVar8 = pcVar8 + 1;
    cVar4 = *pcVar8;
  } while( true );
  if ((cVar4 == ',') || (cVar4 == '.')) {
    pcVar8 = local_15c + iVar6;
    fVar11 = 10.0;
    cVar4 = *pcVar8;
    if (9 < (byte)(cVar4 - 0x30U)) goto LAB_0001516d;
    do {
      fVar10 = fVar10 + (float)(cVar4 + -0x30) / fVar11;
      fVar11 = fVar11 * 10.0;
      while( true ) {
        pcVar8 = pcVar8 + 1;
        cVar4 = *pcVar8;
        if ((byte)(cVar4 - 0x30U) < 10) break;
LAB_0001516d:
        if (cVar4 == '\0') goto LAB_000150c0;
        if (' ' < cVar4) goto LAB_0001504c;
      }
    } while( true );
  }
LAB_0001504c:
  bVar2 = false;
  bVar1 = false;
joined_r0x000150cc:
  if ((bVar3) && (bVar1 = bVar2, bVar2)) {
    iVar6 = *(int *)(param_1 + 0x1d4);
    lVar9 = (longdouble)_pow(0,0x40000000,(double)fVar10 * 0.00083333333333333);
    *(float *)(iVar6 + local_404 * 4) = (float)((double)lVar9 * 8.175798915643707);
  }
  if ((bVar3) && (bVar1)) {
    bVar5 = 1;
  }
  else {
    bVar5 = 0;
  }
  local_405 = local_405 & bVar5;
  goto LAB_00014ec2;
LAB_000150c0:
  bVar2 = true;
  bVar1 = true;
  goto joined_r0x000150cc;
}

