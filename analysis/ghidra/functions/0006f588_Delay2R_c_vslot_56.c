/* 0006f588 Delay2R_c_vslot_56 */

void Delay2R_c_vslot_56(int param_1,undefined4 param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  
  if (*(char *)(param_1 + 0x15c) == '\0') {
    return;
  }
  iVar3 = *(int *)(param_1 + 0xa48);
  if (iVar3 * 0x20 <= *(int *)(param_1 + 0x204)) {
    *(int *)(param_1 + 0x204) = *(int *)(param_1 + 0x204) + iVar3 * -0x1e;
    *(double *)(param_1 + 0x1e0) = *(double *)(param_1 + 0x1e0) - (double)(iVar3 * 0x1e);
    *(double *)(param_1 + 0x1e8) = *(double *)(param_1 + 0x1e8) - (double)(iVar3 * 0x1e);
  }
  (**(code **)(**(int **)(param_1 + 0x118) + 0x2c))
            (*(int **)(param_1 + 0x118),param_1 + 0xa14,param_1 + 0xa18);
  piVar4 = *(int **)(param_1 + 0x10);
  cVar1 = *(char *)((int)piVar4 + 0x27);
  if (cVar1 == '\0') {
    (**(code **)(*piVar4 + 0x34))(piVar4,param_1 + 0xa1c,0);
    cVar2 = *(char *)(param_1 + 0xa40);
  }
  else {
    (**(code **)(*piVar4 + 0x38))(piVar4,param_1 + 0xa1c,param_1 + 0xa20);
    cVar2 = *(char *)(param_1 + 0xa40);
  }
  if (cVar2 != '\0') {
    if (cVar1 != '\0') {
      FUN_0006f14e(param_1,param_2);
                    /* WARNING: Could not recover jumptable at 0x0006f72f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(param_1 + 0x118) + 0x44))();
      return;
    }
    FUN_0006d598(param_1,param_2);
                    /* WARNING: Could not recover jumptable at 0x0006f640. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x118) + 0x44))();
    return;
  }
  if (*(char *)(param_1 + 0xa41) == '\0') {
    if (cVar1 == '\0') {
      FUN_0006e41a(param_1,param_2,*(undefined4 *)(param_1 + 0xa24));
    }
    else {
      FUN_0006df90(param_1,param_2,*(undefined4 *)(param_1 + 0xa24));
    }
  }
  else if (cVar1 == '\0') {
    FUN_0006ecfc(param_1,param_2,*(undefined4 *)(param_1 + 0xa24));
  }
  else {
    FUN_0006e882(param_1,param_2,*(undefined4 *)(param_1 + 0xa24));
  }
                    /* WARNING: Could not recover jumptable at 0x0006f6a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x118) + 0x44))();
  return;
}

