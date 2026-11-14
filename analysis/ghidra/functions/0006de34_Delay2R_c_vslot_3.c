/* 0006de34 Delay2R_c_vslot_3 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Delay2R_c_vslot_3(int param_1)

{
  int iVar1;
  float fVar2;
  
  if (*(int *)(param_1 + 0xa44) != 0) {
    *(undefined8 *)(param_1 + 0x1e0) = 0;
    *(undefined8 *)(param_1 + 0x1e8) = 0;
    *(undefined8 *)(param_1 + 0x1f0) = 0;
    *(undefined8 *)(param_1 + 0x1f8) = 0;
    *(int *)(param_1 + 0x204) = *(int *)(param_1 + 0xa48) + *(int *)(param_1 + 0xa48) / 2;
    if (0 < *(int *)(param_1 + 0xa48)) {
      fVar2 = 1e-07;
      iVar1 = 0;
      do {
        *(float *)(*(int *)(param_1 + 0xa44) + iVar1 * 4) = fVar2;
        fVar2 = -fVar2;
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 0xa48));
    }
  }
  *(undefined4 *)(param_1 + 0xa08) = 0;
  *(undefined4 *)(param_1 + 0xa0c) = 0;
  *(undefined4 *)(param_1 + 0xa10) = 0;
  *(undefined1 *)(param_1 + 0x200) = 1;
  return;
}

