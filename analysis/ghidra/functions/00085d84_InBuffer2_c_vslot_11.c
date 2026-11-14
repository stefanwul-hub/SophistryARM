/* 00085d84 InBuffer2_c_vslot_11 */

undefined4 InBuffer2_c_vslot_11(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  if ((*(char *)(param_1 + 0x24) == '\0') || (*(int *)(param_1 + 0x14) < 2)) {
    return 0;
  }
  if (*(char *)(param_1 + 0x26) == '\0') {
    if (*(char *)(param_1 + 0x28) != '\0') {
      *param_2 = *(undefined4 *)(param_1 + 0x38);
      *param_3 = *(undefined4 *)(param_1 + 0x40);
      *(undefined1 *)(param_1 + 0x2a) = 1;
      goto LAB_00085dba;
    }
  }
  else {
    _memcpy(*(void **)(param_1 + 0x3c),*(void **)(param_1 + 0x34),*(int *)(param_1 + 0x2c) << 2);
    *(undefined1 *)(param_1 + 0x26) = 0;
    *(undefined1 *)(param_1 + 0x27) = 1;
  }
  *param_2 = *(undefined4 *)(param_1 + 0x34);
  *param_3 = *(undefined4 *)(param_1 + 0x3c);
LAB_00085dba:
  *(undefined4 *)(param_1 + 0x20) = 2;
  return 1;
}

