/* 00085ef6 InBuffer2_c_vslot_12 */

undefined4 InBuffer2_c_vslot_12(int param_1,undefined4 *param_2)

{
  if ((*(char *)(param_1 + 0x24) != '\0') && (5 < *(int *)(param_1 + 0x14))) {
    if (*(char *)(param_1 + 0x26) == '\0') {
      if (*(char *)(param_1 + 0x27) != '\0') {
        _memcpy(*(void **)(param_1 + 0x4c),*(void **)(param_1 + 0x34),*(int *)(param_1 + 0x2c) << 2)
        ;
        _memcpy(*(void **)(param_1 + 0x50),*(void **)(param_1 + 0x3c),*(int *)(param_1 + 0x2c) << 2)
        ;
        *(undefined1 *)(param_1 + 0x27) = 0;
        *(undefined1 *)(param_1 + 0x28) = 1;
      }
    }
    else {
      _memcpy(*(void **)(param_1 + 0x3c),*(void **)(param_1 + 0x34),*(int *)(param_1 + 0x2c) << 2);
      _memcpy(*(void **)(param_1 + 0x4c),*(void **)(param_1 + 0x34),*(int *)(param_1 + 0x2c) << 2);
      _memcpy(*(void **)(param_1 + 0x50),*(void **)(param_1 + 0x34),*(int *)(param_1 + 0x2c) << 2);
      *(undefined1 *)(param_1 + 0x26) = 0;
      *(undefined1 *)(param_1 + 0x28) = 1;
    }
    *param_2 = *(undefined4 *)(param_1 + 0x34);
    param_2[1] = *(undefined4 *)(param_1 + 0x3c);
    param_2[2] = *(undefined4 *)(param_1 + 0x44);
    param_2[3] = *(undefined4 *)(param_1 + 0x48);
    param_2[4] = *(undefined4 *)(param_1 + 0x4c);
    param_2[5] = *(undefined4 *)(param_1 + 0x50);
    *(undefined4 *)(param_1 + 0x20) = 3;
    return 1;
  }
  return 0;
}

