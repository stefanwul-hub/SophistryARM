/* 000c12b8 Note_c_vslot_6 */

undefined4 Note_c_vslot_6(int param_1)

{
  if (((*(uint *)(param_1 + 8) < 0x80) && (-1 < *(int *)(param_1 + 0xc))) &&
     (*(int *)(param_1 + 0xc) < 0x80)) {
    return 1;
  }
  return 0;
}

