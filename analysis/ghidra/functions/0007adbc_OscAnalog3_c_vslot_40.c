/* 0007adbc OscAnalog3_c_vslot_40 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void OscAnalog3_c_vslot_40(int param_1,float param_2)

{
  int iVar1;
  
  Part_c_vslot_40(param_1,param_2);
  iVar1 = (param_2 < 50000.0) + 1;
  *(int *)(param_1 + 0x478) = iVar1;
  *(uint *)(param_1 + 0x47c) = (uint)(param_2 < 50000.0);
  *(double *)(param_1 + 0x480) = 1.0 / (double)iVar1;
  *(int *)(param_1 + 0x488) = iVar1 * 8 + -1;
  *(undefined4 *)(param_1 + 0x48c) = 0x1f;
  *(int *)(param_1 + 0x490) = iVar1 * 0x20;
  *(int *)(param_1 + 0x494) = iVar1 * 0x20 + -1;
  return;
}

