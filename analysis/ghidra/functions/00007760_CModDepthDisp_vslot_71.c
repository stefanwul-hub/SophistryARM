/* 00007760 CModDepthDisp_vslot_71 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CModDepthDisp_vslot_71(int param_1)

{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0xf8);
  if ((fVar1 <= -0.99) && (!NAN(fVar1))) {
    *(undefined4 *)(param_1 + 0xf8) = *(undefined4 *)(*(int *)(param_1 + 0x90) + 4);
    *(undefined4 *)(*(int *)(param_1 + 0x90) + 4) = 0x3f000000;
    return;
  }
  *(float *)(*(int *)(param_1 + 0x90) + 4) = fVar1;
  *(undefined4 *)(param_1 + 0xf8) = 0xbf800000;
  return;
}

