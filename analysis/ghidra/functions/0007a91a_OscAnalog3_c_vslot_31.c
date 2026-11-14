/* 0007a91a OscAnalog3_c_vslot_31 */

/* WARNING: Function: __i686.get_pc_thunk.cx replaced with injection: get_pc_thunk_cx */

void OscAnalog3_c_vslot_31(int param_1)

{
  float fVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x124);
  if (iVar2 != 0) {
    *(double *)(param_1 + 0x20c) = (double)*(float *)(iVar2 + 0x15c);
    fVar1 = *(float *)(iVar2 + 0xf4);
    *(double *)(param_1 + 0x214) = (double)fVar1;
    *(double *)(param_1 + 0x21c) = 1.0 - (double)fVar1;
    *(double *)(param_1 + 0x224) =
         (double)*(float *)(iVar2 + 0x62c) * (double)*(float *)(iVar2 + 0x62c);
    *(undefined4 *)(param_1 + 0x1e4) = *(undefined4 *)(iVar2 + 0x54c);
  }
  return;
}

