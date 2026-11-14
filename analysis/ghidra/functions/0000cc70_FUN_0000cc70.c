/* 0000cc70 FUN_0000cc70 */

void FUN_0000cc70(int param_1,char param_2)

{
  if ((*(char *)(param_1 + 0xec2) != '\0') && (param_2 == '\0')) {
    *(undefined4 *)(param_1 + 0x118) = 0;
  }
  if ((*(char *)(param_1 + 0xec2) == '\0') && (param_2 != '\0')) {
    *(undefined4 *)(param_1 + 0x118) = *(undefined4 *)(FUN_00001ace + param_1 + 6);
  }
  *(char *)(param_1 + 0xec2) = param_2;
  return;
}

