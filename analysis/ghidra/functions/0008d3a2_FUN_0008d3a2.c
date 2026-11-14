/* 0008d3a2 FUN_0008d3a2 */

void FUN_0008d3a2(int param_1,int param_2,int param_3,int param_4)

{
  if (*(int *)(param_1 + 800) < 0) {
    return;
  }
  if (*(char *)(param_1 + 0x1d4) == '\0') {
    return;
  }
  if (param_2 < 0) {
    return;
  }
  if (0xf < param_2) {
    return;
  }
  if (param_3 < 0) {
    return;
  }
  if (param_3 == 0x62) {
    *(undefined1 *)(param_1 + 0x330) = 1;
    *(uint *)(param_1 + 0x334) = param_4 + (*(uint *)(param_1 + 0x334) & 0xff80);
    return;
  }
  if (param_3 < 99) {
    if ((param_3 == 0x60) || (param_3 == 0x61)) {
      if (*(char *)(param_1 + 0x330) == '\0') {
        *(int *)(param_1 + 0x334) = param_4;
        param_3 = param_4;
      }
      else {
        param_3 = *(int *)(param_1 + 0x334);
      }
      goto LAB_0008d3fb;
    }
  }
  else if (param_3 == 99) {
    *(undefined1 *)(param_1 + 0x330) = 1;
    *(uint *)(param_1 + 0x334) = (*(uint *)(param_1 + 0x334) & 0x7f) + param_4 * 0x80;
    return;
  }
  *(int *)(param_1 + 0x334) = param_3;
LAB_0008d3fb:
  FUN_0008d188(param_1,param_2,param_3,*(undefined4 *)(param_1 + 0x31c),
               *(undefined4 *)(param_1 + 800),0);
  *(undefined4 *)(param_1 + 800) = 0xffffffff;
  return;
}

