/* 00001704 CControlPl_vslot_67 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CControlPl_vslot_67(int *param_1,int param_2,float param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  float fVar6;
  int local_18;
  
  if ((0.0 <= param_3) || (NAN(param_3))) {
    fVar6 = 1.0;
    if (param_3 <= 1.0) {
      fVar6 = param_3;
    }
  }
  else {
    fVar6 = 0.0;
  }
  if (*(char *)((int)param_1 + 0x73) != '\0') {
    fVar6 = 1.0 - fVar6;
  }
  if (0 < param_1[0x29]) {
    piVar1 = (int *)param_1[0x24];
    if (param_2 == *piVar1) {
      local_18 = 0;
      piVar5 = piVar1;
    }
    else {
      iVar3 = 0;
      iVar2 = 0x18;
      piVar4 = piVar1;
      do {
        local_18 = iVar2;
        piVar4 = piVar4 + 6;
        iVar3 = iVar3 + 1;
        if (iVar3 == param_1[0x29]) {
          return;
        }
        piVar5 = (int *)(local_18 + (int)piVar1);
        iVar2 = local_18 + 0x18;
      } while (*piVar4 != param_2);
    }
    piVar5[3] = (int)fVar6;
    if (*(float *)(local_18 + param_1[0x24] + 0xc) != *(float *)(local_18 + param_1[0x24] + 0x10)) {
                    /* WARNING: Could not recover jumptable at 0x000017d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_1 + 0x54))();
      return;
    }
  }
  return;
}

