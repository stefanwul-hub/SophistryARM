/* 000087dc CRadioButtonPl_vslot_72 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble CRadioButtonPl_vslot_72(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  float fVar5;
  
  cVar1 = FUN_0009c968(param_1 + 8,param_2);
  if (cVar1 != '\0') {
    iVar2 = ((*param_2 - *(int *)(param_1 + 8)) + -1) / *(int *)(param_1 + 0xc0);
    iVar3 = ((param_2[1] - *(int *)(param_1 + 0xc)) + -1) / *(int *)(param_1 + 0xc4);
    if (*(char *)(param_1 + 0xbc) == '\0') {
      iVar2 = iVar3 + iVar2 * *(int *)(param_1 + 0xb8);
    }
    else {
      iVar2 = iVar2 + iVar3 * *(int *)(param_1 + 0xb4);
    }
    fVar5 = (float)iVar2 / ((float)(*(int *)(param_1 + 0xb4) * *(int *)(param_1 + 0xb8)) - 1.0);
    if ((0.0 <= fVar5) || (NAN(fVar5))) {
      if (1.0 < fVar5) {
        fVar5 = 1.0;
      }
    }
    else {
      fVar5 = 0.0;
    }
    return (longdouble)fVar5;
  }
  lVar4 = (longdouble)FUN_000019d6();
  return lVar4;
}

