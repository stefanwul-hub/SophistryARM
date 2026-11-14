/* 0007eb5a C51Map_vslot_79 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void C51Map_vslot_79(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  if (param_3 != (int *)0x0) {
    if (0 < *(int *)(param_1 + 0xb4)) {
      fVar6 = 99999.9;
      iVar1 = 0;
      iVar3 = 0;
      do {
        iVar2 = iVar3 + *(int *)(param_1 + 0x90);
        if (0.5 < *(float *)(iVar2 + 0x3c)) {
          fVar5 = (float)*(int *)(param_1 + 0xc0) * *(float *)(iVar2 + 0xc) -
                  (float)(*param_2 - *(int *)(param_1 + 8));
          fVar4 = (float)*(int *)(param_1 + 0xc4) * *(float *)(iVar2 + 0x24) -
                  (float)(param_2[1] - *(int *)(param_1 + 0xc));
          fVar4 = SQRT(fVar5 * fVar5 + fVar4 * fVar4);
          if (fVar4 < fVar6) {
            *param_3 = iVar1;
            fVar6 = fVar4;
          }
        }
        iVar1 = iVar1 + 1;
        iVar3 = iVar3 + 0x48;
      } while (iVar1 < *(int *)(param_1 + 0xb4));
    }
    if (*param_3 < 0) {
      *param_3 = 0;
    }
    iVar1 = *(int *)(param_1 + 0xb4) + -1;
    if (iVar1 < *param_3) {
      *param_3 = iVar1;
    }
  }
  return;
}

