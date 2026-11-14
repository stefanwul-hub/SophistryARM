/* 0009a78e CMenuFileList_vslot_21 */

/* WARNING: Function: __i686.get_pc_thunk.cx replaced with injection: get_pc_thunk_cx */

void CMenuFileList_vslot_21(int param_1,char param_2)

{
  *(char *)(param_1 + 0x30) = param_2;
  if (param_2 != '\0') {
    *(uint *)(param_1 + 0x44) = -(uint)(*(float *)(param_1 + 0x4c) != -1.0) & (uint)-1.0;
    return;
  }
  *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(param_1 + 0x4c);
  return;
}

