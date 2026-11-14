/* 0008601a InBuffer2_c_vslot_15 */

undefined4 InBuffer2_c_vslot_15(int param_1,undefined4 *param_2)

{
  if ((*(char *)(param_1 + 0x24) == '\0') || (*(int *)(param_1 + 0x14) < 6)) {
    return 0;
  }
  if (*(char *)(param_1 + 0x26) != '\0') {
    *param_2 = *(undefined4 *)(param_1 + 0x34);
    param_2[1] = *(undefined4 *)(param_1 + 0x34);
    param_2[2] = *(undefined4 *)(param_1 + 0x44);
    param_2[3] = *(undefined4 *)(param_1 + 0x48);
    param_2[4] = *(undefined4 *)(param_1 + 0x34);
    param_2[5] = *(undefined4 *)(param_1 + 0x34);
    return 1;
  }
  if (*(char *)(param_1 + 0x27) == '\0') {
    *param_2 = *(undefined4 *)(param_1 + 0x34);
    param_2[1] = *(undefined4 *)(param_1 + 0x3c);
    param_2[2] = *(undefined4 *)(param_1 + 0x44);
    param_2[3] = *(undefined4 *)(param_1 + 0x48);
    param_2[4] = *(undefined4 *)(param_1 + 0x4c);
    param_2[5] = *(undefined4 *)(param_1 + 0x50);
    return 1;
  }
  *param_2 = *(undefined4 *)(param_1 + 0x34);
  param_2[1] = *(undefined4 *)(param_1 + 0x3c);
  param_2[2] = *(undefined4 *)(param_1 + 0x44);
  param_2[3] = *(undefined4 *)(param_1 + 0x48);
  param_2[4] = *(undefined4 *)(param_1 + 0x34);
  param_2[5] = *(undefined4 *)(param_1 + 0x3c);
  return 1;
}

