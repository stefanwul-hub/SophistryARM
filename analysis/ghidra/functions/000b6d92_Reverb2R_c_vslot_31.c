/* 000b6d92 Reverb2R_c_vslot_31 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Reverb2R_c_vslot_31(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  float fVar5;
  
  iVar2 = *(int *)(param_1 + 0x124);
  if (iVar2 == 0) {
    return;
  }
  if (*(char *)(param_1 + 0x15c) == '\0') {
    return;
  }
  if ((((param_2 == -1) || (param_2 == 6)) &&
      (*(float *)(param_1 + 0x1e0) = *(float *)(iVar2 + 0x2ac) + *(float *)(iVar2 + 0x2ac),
      param_2 == -1)) || (param_2 == 3)) {
    lVar4 = (longdouble)_pow(0xd2f1a9fc,0x3f50624d,0.029 / (double)*(float *)(iVar2 + 0x15c));
    iVar3 = 0;
    iVar2 = 0;
    do {
      *(float *)(iVar2 + 0x1e4 + param_1) = (float)lVar4;
      *(float *)(iVar2 + 0x404 + param_1) = (float)lVar4;
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x44;
    } while (iVar3 != 8);
    if (param_2 == -1) {
      iVar2 = *(int *)(param_1 + 0x124);
    }
    else {
      iVar2 = *(int *)(param_1 + 0x124);
      if (param_2 != 4) goto joined_r0x000b6f0b;
    }
LAB_000b6ed6:
    uVar1 = *(undefined4 *)(iVar2 + 0x1cc);
    iVar2 = 0;
    iVar3 = 0;
    do {
      *(undefined4 *)(iVar3 + 0x200 + param_1) = uVar1;
      *(undefined4 *)(iVar3 + 0x420 + param_1) = uVar1;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x44;
    } while (iVar2 != 8);
    if (param_2 != -1) {
      iVar2 = *(int *)(param_1 + 0x124);
      goto joined_r0x000b6f0b;
    }
    iVar2 = *(int *)(param_1 + 0x124);
  }
  else {
    if (param_2 == 4) goto LAB_000b6ed6;
joined_r0x000b6f0b:
    if ((param_2 != 5) && (param_2 != 7)) goto LAB_000b6df3;
  }
  fVar5 = 0.0;
  if (iVar2 != 0) {
    fVar5 = *(float *)(iVar2 + 0x23c) * 0.001;
    if (*(int *)(iVar2 + 0x334) < *(int *)(iVar2 + 0x318)) {
      lVar4 = (longdouble)FUN_0001354c(param_1,*(int *)(iVar2 + 0x318));
      fVar5 = (float)lVar4;
    }
    for (; 0.125 < fVar5; fVar5 = fVar5 * 0.5) {
    }
  }
  FUN_000b6884(param_1 + 0x744,(int)(fVar5 * *(float *)(param_1 + 0x140) + 0.5));
  iVar2 = *(int *)(param_1 + 0x124);
LAB_000b6df3:
  *(undefined1 *)(param_1 + 0x860) = *(undefined1 *)(iVar2 + 0x39c);
  iVar2 = *(int *)(iVar2 + 0x3f8);
  *(int *)(param_1 + 0x864) = iVar2;
  *(float *)(param_1 + 0x868) = (float)iVar2 * -0.01 + 0.07;
  if ((param_2 != -1) && (param_2 != 10)) {
    return;
  }
  FUN_000b666a();
  return;
}

