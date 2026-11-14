/* 000a485c CFrame_vslot_88 */

void CFrame_vslot_88(int *param_1,int *param_2)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int *local_10;
  
  if ((param_2 == (int *)0x0) ||
     (cVar2 = (**(code **)(*param_1 + 0xbc))(param_1,param_2), cVar2 == '\0')) {
    local_10 = (int *)0x0;
    piVar3 = (int *)param_1[0x25];
    param_2 = local_10;
  }
  else {
    piVar3 = (int *)param_1[0x25];
  }
  if (piVar3 == (int *)0x0) {
    iVar1 = param_1[0x19];
    piVar3 = (int *)operator_new(0x68);
    FUN_000a171a(piVar3,param_1,0,iVar1);
  }
  else {
    (**(code **)(*piVar3 + 0xc))(piVar3);
    piVar3 = (int *)param_1[0x25];
  }
  if (piVar3 != (int *)0x0) {
    if (param_2 == (int *)0x0) {
      (**(code **)(*param_1 + 0x10))(param_1,piVar3);
                    /* WARNING: Could not recover jumptable at 0x000a4939. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*piVar3 + 8))();
      return;
    }
    (**(code **)(*param_2 + 0x10))(param_2,piVar3);
                    /* WARNING: Could not recover jumptable at 0x000a48d3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar3 + 8))();
    return;
  }
  return;
}

