/* 0003dd9c LFOSimp_c_vslot_57 */

void LFOSimp_c_vslot_57(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x124) != 0) && (*(char *)(param_1 + 0x1f8) != '\0')) {
    *(undefined4 *)(param_1 + 0x794) = **(undefined4 **)(param_1 + 0x1dc);
    *(undefined4 *)(param_1 + 0x798) = **(undefined4 **)(param_1 + 0x1d4);
    *(undefined4 *)(param_1 + 0x79c) = **(undefined4 **)(param_1 + 0x1d8);
    iVar1 = *(int *)(*(int *)(param_1 + 0x124) + 0xe8);
    if (iVar1 == 4) {
      FUN_0003dbbc(param_1);
    }
    else if (iVar1 == 5) {
      FUN_0003d326(param_1);
    }
    else {
      FUN_0003d822(param_1,*(int *)(param_1 + 0x1f0) + 1);
    }
    **(undefined4 **)(param_1 + 0x1dc) = *(undefined4 *)(param_1 + 0x794);
    **(undefined4 **)(param_1 + 0x1d4) = *(undefined4 *)(param_1 + 0x798);
    **(undefined4 **)(param_1 + 0x1d8) = *(undefined4 *)(param_1 + 0x79c);
  }
  return;
}

