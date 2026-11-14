/* 00032f76 StereoEnh1_c_vslot_31 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void StereoEnh1_c_vslot_31(int param_1)

{
  int iVar1;
  float fVar2;
  
  if ((*(char *)(param_1 + 0x15c) != '\0') && (iVar1 = *(int *)(param_1 + 0x124), iVar1 != 0)) {
    fVar2 = *(float *)(iVar1 + 0x7c) * 0.45;
    *(float *)(param_1 + 0x1f8) = fVar2;
    *(float *)(param_1 + 0x1fc) = fVar2 * -0.8 + 1.0;
    fVar2 = *(float *)(iVar1 + 0xec);
    *(float *)(param_1 + 0x200) = fVar2;
    *(int *)(param_1 + 500) = (int)(fVar2 * *(float *)(param_1 + 0x140) * 0.001);
    fVar2 = *(float *)(iVar1 + 0x15c);
    *(float *)(param_1 + 0x204) = fVar2;
    if (1.0 <= fVar2) {
      *(float *)(param_1 + 0x208) = 1.0 / fVar2;
    }
  }
  return;
}

