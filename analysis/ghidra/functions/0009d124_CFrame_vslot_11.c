/* 0009d124 CFrame_vslot_11 */

int CFrame_vslot_11(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x6c);
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x2c))(piVar1,param_2), iVar2 != -1)
     ) {
    return iVar2;
  }
  if (*(int **)(param_1 + 0x68) == (int *)0x0) {
    return -1;
  }
                    /* WARNING: Could not recover jumptable at 0x0009d169. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (**(code **)(**(int **)(param_1 + 0x68) + 0x2c))();
  return iVar2;
}

