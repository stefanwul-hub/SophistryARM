/* 00085ea6 InBuffer2_c_vslot_14 */

undefined4 InBuffer2_c_vslot_14(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  if ((*(char *)(param_1 + 0x24) != '\0') && (1 < *(int *)(param_1 + 0x14))) {
    if (*(char *)(param_1 + 0x26) != '\0') {
      *param_2 = *(undefined4 *)(param_1 + 0x34);
      *param_3 = *(undefined4 *)(param_1 + 0x34);
      return 1;
    }
    if (*(char *)(param_1 + 0x28) == '\0') {
      *param_2 = *(undefined4 *)(param_1 + 0x34);
      *param_3 = *(undefined4 *)(param_1 + 0x3c);
      return 1;
    }
  }
  return 0;
}

