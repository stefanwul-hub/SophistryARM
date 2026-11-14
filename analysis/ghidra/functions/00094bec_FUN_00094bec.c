/* 00094bec FUN_00094bec */

undefined4
FUN_00094bec(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = *(int **)(param_1 + 0x40);
  if (param_2 != 1) {
                    /* WARNING: Could not recover jumptable at 0x00094c2e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*piVar1 + 8))();
    return uVar2;
  }
  (**(code **)(*piVar1 + 8))(piVar1,1,param_3,param_4,param_5,param_6);
  (**(code **)(*piVar1 + 4))(piVar1);
  return 1;
}

