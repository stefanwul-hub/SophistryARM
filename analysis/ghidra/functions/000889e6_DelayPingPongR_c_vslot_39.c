/* 000889e6 DelayPingPongR_c_vslot_39 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void DelayPingPongR_c_vslot_39(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  float fVar3;
  
  if ((((*(char *)(param_2 + 0x1b4 + param_1) != '\0') && (param_2 == *(int *)(param_1 + 0x128))) &&
      (*(char *)(param_1 + 0x15c) != '\0')) && (0 < *(int *)(param_1 + 0x204))) {
    fVar3 = 1e-07;
    iVar2 = 0;
    do {
      iVar1 = iVar2 * 4;
      *(float *)(*(int *)(param_1 + 0x1ec) + iVar1) = fVar3;
      *(float *)(*(int *)(param_1 + 0x1f0) + iVar1) = fVar3;
      *(float *)(*(int *)(param_1 + 500) + iVar1) = fVar3;
      *(float *)(*(int *)(param_1 + 0x1f8) + iVar1) = fVar3;
      *(float *)(*(int *)(param_1 + 0x1fc) + iVar1) = fVar3;
      *(float *)(iVar1 + *(int *)(param_1 + 0x200)) = fVar3;
      fVar3 = -fVar3;
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x204));
    return;
  }
  return;
}

