/* 0000fa9e RampGlide_c_vslot_33 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void RampGlide_c_vslot_33(int param_1,int param_2,int param_3,char param_4,undefined1 param_5)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  undefined *local_2c;
  undefined1 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_2c = PTR_DAT_00103808 + 8;
  local_28 = *(undefined1 *)(param_3 + 4);
  local_24 = *(undefined4 *)(param_3 + 8);
  local_20 = *(undefined4 *)(param_3 + 0xc);
  Modulator_c_vslot_33(param_1,param_2,&local_2c,param_4,param_5);
  local_2c = PTR_DAT_00103808 + 8;
  if (*(int *)(param_1 + 0x124) == 0) {
    return;
  }
  if (*(char *)(param_1 + 0x1f8) == '\0') {
    return;
  }
  *(float *)(param_1 + 0x1ec) = 1.0;
  *(float *)(param_1 + 0x1e8) = 1.0;
  *(undefined1 *)(param_1 + 0x1e0) = 0;
  iVar3 = *(int *)(param_1 + 0x1fc + param_2 * 4);
  fVar6 = 0.0;
  if (-1 < iVar3) {
    fVar6 = (float)(iVar3 - *(int *)(param_3 + 8)) / 48.0;
  }
  iVar3 = *(int *)(*(int *)(param_1 + 0x124) + 0x78);
  if (iVar3 == 1) {
    if (*(char *)(param_2 + 0x200 + param_1) != '\0') {
LAB_0000fcab:
      pfVar1 = *(float **)(param_1 + 0x1d4);
      if (param_4 == '\0') {
        *pfVar1 = fVar6;
      }
      else {
        *pfVar1 = fVar6 + *pfVar1;
      }
      goto LAB_0000fb97;
    }
  }
  else if (1 < iVar3) {
    if (iVar3 == 2) goto LAB_0000fcab;
    if (iVar3 == 3) {
      **(float **)(param_1 + 0x1d4) = *(float *)(*(int *)(param_1 + 0x124) + 0xec) / 48.0;
      goto LAB_0000fb97;
    }
  }
  **(undefined4 **)(param_1 + 0x1d4) = 0;
LAB_0000fb97:
  pfVar1 = *(float **)(param_1 + 0x1d4);
  fVar5 = *pfVar1;
  if ((-1.0 <= fVar5) || (NAN(fVar5))) {
    fVar7 = 1.0;
    if (fVar5 <= 1.0) {
      fVar7 = fVar5;
    }
    *pfVar1 = fVar7;
    iVar3 = *(int *)(param_1 + 0x124);
    fVar5 = *(float *)(iVar3 + 0x15c);
    iVar2 = *(int *)(iVar3 + 0x78);
  }
  else {
    *pfVar1 = -1.0;
    iVar3 = *(int *)(param_1 + 0x124);
    fVar5 = *(float *)(iVar3 + 0x15c);
    iVar2 = *(int *)(iVar3 + 0x78);
  }
  if ((iVar2 - 1U < 2) && (*(int *)(iVar3 + 0x1c8) == 1)) {
    fVar5 = fVar5 * ABS(fVar6);
  }
  **(int **)(param_1 + 0x1dc) = (int)(fVar5 * *(float *)(param_1 + 0x140) + 0.5);
  iVar3 = **(int **)(param_1 + 0x1dc);
  if (iVar3 < 1) {
    iVar3 = 1;
  }
  else if (0x7ffffbff < iVar3) {
    iVar3 = 0x7ffffbff;
  }
  **(int **)(param_1 + 0x1dc) = iVar3;
  pfVar1 = *(float **)(param_1 + 0x1d8);
  lVar4 = (longdouble)
          FUN_000152c0(**(undefined4 **)(param_1 + 0x1d4),(float)**(int **)(param_1 + 0x1dc));
  *pfVar1 = -(float)lVar4;
  return;
}

