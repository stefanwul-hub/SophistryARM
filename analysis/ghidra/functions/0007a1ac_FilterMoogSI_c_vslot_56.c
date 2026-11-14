/* 0007a1ac FilterMoogSI_c_vslot_56 */

void FilterMoogSI_c_vslot_56(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x124) == 0) {
    return;
  }
  cVar1 = *(char *)(*(int *)(param_1 + 0x10) + 0x27);
  (**(code **)(**(int **)(param_1 + 0x118) + 0x2c))
            (*(int **)(param_1 + 0x118),param_1 + 0x200,param_1 + 0x204);
  *(undefined4 *)(param_1 + 0x42fc) = *(undefined4 *)(param_1 + 0x1e8);
  *(undefined4 *)(param_1 + 0x4300) = *(undefined4 *)(param_1 + 0x1ec);
  *(undefined4 *)(param_1 + 0x4304) = *(undefined4 *)(param_1 + 0x1f0);
  *(undefined4 *)(param_1 + 0x4308) = *(undefined4 *)(param_1 + 500);
  if (cVar1 == '\0') {
    (**(code **)(**(int **)(param_1 + 0x10) + 0x34))(*(int **)(param_1 + 0x10),param_1 + 0x1f8,0);
    iVar2 = *(int *)(param_1 + 0x432c);
    if (iVar2 == 0) {
      FUN_0007909c(param_1,param_2,*(undefined4 *)(param_1 + 0x1f8));
                    /* WARNING: Could not recover jumptable at 0x0007a31b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(param_1 + 0x118) + 0x44))();
      return;
    }
    if (iVar2 < 1) {
      if (iVar2 == -1) {
        FUN_00079c72(param_1,param_2,*(undefined4 *)(param_1 + 0x1f8));
      }
    }
    else if (iVar2 == 1) {
      FUN_0007818a(param_1,param_2,*(undefined4 *)(param_1 + 0x1f8));
    }
    else if (iVar2 == 2) {
      FUN_00078bb4(param_1,param_2,*(undefined4 *)(param_1 + 0x1f8));
    }
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x10) + 0x38))
              (*(int **)(param_1 + 0x10),param_1 + 0x1f8,param_1 + 0x1fc);
    iVar2 = *(int *)(param_1 + 0x432c);
    if (iVar2 == 0) {
      FUN_000795d2(param_1,param_2,*(undefined4 *)(param_1 + 0x1f8),*(undefined4 *)(param_1 + 0x1fc)
                  );
                    /* WARNING: Could not recover jumptable at 0x0007a354. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(param_1 + 0x118) + 0x44))();
      return;
    }
    if (iVar2 < 1) {
      if (iVar2 == -1) {
        FUN_00077a8a(param_1,param_2,*(undefined4 *)(param_1 + 0x1f8),
                     *(undefined4 *)(param_1 + 0x1fc));
      }
    }
    else if (iVar2 == 1) {
      FUN_00078528(param_1,param_2,*(undefined4 *)(param_1 + 0x1f8),*(undefined4 *)(param_1 + 0x1fc)
                  );
    }
    else if (iVar2 == 2) {
      FUN_000774fa(param_1,param_2,*(undefined4 *)(param_1 + 0x1f8),*(undefined4 *)(param_1 + 0x1fc)
                  );
    }
  }
                    /* WARNING: Could not recover jumptable at 0x0007a282. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x118) + 0x44))();
  return;
}

