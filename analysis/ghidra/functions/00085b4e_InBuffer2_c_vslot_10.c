/* 00085b4e InBuffer2_c_vslot_10 */

undefined4 InBuffer2_c_vslot_10(int param_1,undefined4 *param_2,char param_3)

{
  if ((*(char *)(param_1 + 0x24) != '\0') &&
     (((param_3 == '\0' || (*(char *)(param_1 + 0x25) != '\0')) && (0 < *(int *)(param_1 + 0x14)))))
  {
    if (((*(char *)(param_1 + 0x28) == '\0') && (*(char *)(param_1 + 0x27) == '\0')) ||
       (param_3 != '\0')) {
      *param_2 = *(undefined4 *)(param_1 + 0x34);
    }
    else {
      *param_2 = *(undefined4 *)(param_1 + 0x38);
      *(undefined1 *)(param_1 + 0x29) = 1;
    }
    *(undefined4 *)(param_1 + 0x20) = 1;
    return 1;
  }
  return 0;
}

