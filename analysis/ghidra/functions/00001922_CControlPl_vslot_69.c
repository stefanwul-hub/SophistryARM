/* 00001922 CControlPl_vslot_69 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CControlPl_vslot_69(int param_1,int param_2,float param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  float fVar6;
  
  if ((0.0 <= param_3) || (NAN(param_3))) {
    fVar6 = 1.0;
    if (param_3 <= 1.0) {
      fVar6 = param_3;
    }
  }
  else {
    fVar6 = 0.0;
  }
  if (0 < *(int *)(param_1 + 0xa4)) {
    piVar1 = *(int **)(param_1 + 0x90);
    if (param_2 == *piVar1) {
      piVar1[5] = (int)fVar6;
    }
    else {
      iVar3 = 0;
      iVar2 = 0x18;
      piVar5 = piVar1;
      do {
        iVar4 = iVar2;
        piVar5 = piVar5 + 6;
        iVar3 = iVar3 + 1;
        if (iVar3 == *(int *)(param_1 + 0xa4)) {
          return;
        }
        iVar2 = iVar4 + 0x18;
      } while (param_2 != *piVar5);
      *(float *)((int)piVar1 + iVar4 + 0x14) = fVar6;
    }
  }
  return;
}

