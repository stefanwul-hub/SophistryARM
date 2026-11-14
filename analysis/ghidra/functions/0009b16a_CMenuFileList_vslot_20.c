/* 0009b16a CMenuFileList_vslot_20 */

undefined4 CMenuFileList_vslot_20(int param_1)

{
  if (((*(float *)(param_1 + 0x44) == *(float *)(param_1 + 0x4c)) &&
      (!NAN(*(float *)(param_1 + 0x44)) && !NAN(*(float *)(param_1 + 0x4c)))) &&
     (*(char *)(param_1 + 0x30) == '\0')) {
    return 0;
  }
  return 1;
}

