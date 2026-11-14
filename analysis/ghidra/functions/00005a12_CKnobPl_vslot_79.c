/* 00005a12 CKnobPl_vslot_79 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble CKnobPl_vslot_79(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  float fVar5;
  float fVar6;
  
  iVar3 = param_2[1] -
          ((*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0xc)) / 2 + *(int *)(param_1 + 0xc));
  iVar2 = *param_2 -
          ((*(int *)(param_1 + 0x10) - *(int *)(param_1 + 8)) / 2 + *(int *)(param_1 + 8));
  if ((iVar2 == 0) && (iVar3 == 0)) {
    lVar4 = (longdouble)FUN_000019d6();
    return lVar4;
  }
  lVar4 = (longdouble)_atan2((double)iVar2,-(double)iVar3);
  fVar5 = ((float)lVar4 + *(float *)(param_1 + 0xd8)) * *(float *)(param_1 + 0xd4);
  if ((0.0 <= fVar5) || (NAN(fVar5))) {
    fVar6 = 1.0;
    if (fVar5 <= 1.0) {
      fVar6 = fVar5;
    }
    cVar1 = *(char *)(param_1 + 0xb5);
  }
  else {
    fVar6 = 0.0;
    cVar1 = *(char *)(param_1 + 0xb5);
  }
  if ((cVar1 == '\0') &&
     (lVar4 = (longdouble)FUN_000019e8(param_1), 0.7 < ABS(fVar6 - (float)lVar4))) {
    lVar4 = (longdouble)FUN_000019e8();
    return lVar4;
  }
  return (longdouble)fVar6;
}

