/* 00089d3a Amp_c_vslot_56 */

void Amp_c_vslot_56(int param_1)

{
  int iVar1;
  
  if ((*(char *)(param_1 + 0x15c) != '\0') &&
     (iVar1 = *(int *)(param_1 + 0x10), *(int *)(iVar1 + 0x20) != 0)) {
    if (*(int *)(param_1 + 0x1f0) != 0) {
      FUN_00089a22();
      return;
    }
    if (*(char *)(iVar1 + 0x26) != '\0') {
      FUN_00089c3e();
      return;
    }
    if (*(char *)(iVar1 + 0x27) != '\0') {
      FUN_000898fe();
      return;
    }
  }
  return;
}

