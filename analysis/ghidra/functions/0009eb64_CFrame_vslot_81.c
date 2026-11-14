/* 0009eb64 CFrame_vslot_81 */

undefined4 CFrame_vslot_81(int param_1,char param_2)

{
  if (*(char *)(param_1 + 0x72) == '\0') {
    if (param_2 == '\0') {
      return 1;
    }
  }
  else if (param_2 == '\0') {
    FUN_0009ea98();
    goto LAB_0009eb83;
  }
  FUN_0009eaf4();
LAB_0009eb83:
  *(char *)(param_1 + 0x72) = param_2;
  return 1;
}

