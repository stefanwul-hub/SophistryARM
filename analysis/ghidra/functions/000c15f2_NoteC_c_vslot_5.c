/* 000c15f2 NoteC_c_vslot_5 */

undefined4 NoteC_c_vslot_5(int param_1)

{
  if ((((*(uint *)(param_1 + 8) < 0x80) && (0 < *(int *)(param_1 + 0xc))) &&
      (*(int *)(param_1 + 0xc) < 0x80)) &&
     ((-1 < *(int *)(param_1 + 0x10) && (*(int *)(param_1 + 0x10) < 0x10)))) {
    return 1;
  }
  return 0;
}

