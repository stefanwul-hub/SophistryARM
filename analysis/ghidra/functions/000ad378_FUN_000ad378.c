/* 000ad378 FUN_000ad378 */

undefined4 FUN_000ad378(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 != (int *)0x0) {
    if (*(short *)(param_1 + 2) != 0x301) {
      if (*(short *)(param_1 + 2) == 0x302) {
        iVar1 = *(int *)(param_1 + 4);
        param_2[6] = *(int *)(param_1 + 8);
        param_2[7] = iVar1;
        return 0;
      }
      uVar2 = FUN_000ab74e();
      return uVar2;
    }
    if ((((*(int *)(param_1 + 0x18) != 0) && (*(int *)(param_1 + 0x14) != 0)) &&
        (*(int *)(param_1 + 0x10) != 0)) &&
       (((*(int *)(param_1 + 8) != 0 && (*(int *)(param_1 + 0xc) != 0)) &&
        (*(int *)(param_1 + 4) != 0)))) {
      uVar2 = (**(code **)(*param_2 + 0x14))
                        (param_2,*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x14),
                         *(int *)(param_1 + 0x10),*(int *)(param_1 + 0xc),*(int *)(param_1 + 8),
                         *(int *)(param_1 + 4));
      return uVar2;
    }
  }
  return 0xffffffce;
}

