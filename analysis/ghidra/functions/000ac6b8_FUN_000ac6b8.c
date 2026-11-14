/* 000ac6b8 FUN_000ac6b8 */

int FUN_000ac6b8(int param_1,undefined4 param_2)

{
  short sVar1;
  int iVar2;
  undefined1 local_14 [4];
  short local_10;
  short local_e;
  
  _GetControlBounds(param_2,local_14);
  if (*(short *)(param_1 + 0x3e) < local_e) {
    *(short *)(param_1 + 0x3e) = local_e;
  }
  if (*(short *)(param_1 + 0x3c) < local_10) {
    *(short *)(param_1 + 0x3c) = local_10;
  }
  if (*(char *)(param_1 + 0x48) != '\0') {
    iVar2 = _HIViewAddSubview(*(undefined4 *)(param_1 + 0x38),param_2);
    return iVar2;
  }
  sVar1 = _EmbedControl(param_2,*(undefined4 *)(param_1 + 0x38));
  return (int)sVar1;
}

