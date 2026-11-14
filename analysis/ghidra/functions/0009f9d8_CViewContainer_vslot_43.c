/* 0009f9d8 CViewContainer_vslot_43 */

void CViewContainer_vslot_43(int param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (param_2 == (int *)0x0) {
    return;
  }
  puVar2 = (undefined4 *)operator_new(0xc);
  *puVar2 = param_2;
  puVar2[1] = 0;
  puVar2[2] = 0;
  (**(code **)(*param_2 + 0xc))(param_2);
  param_2[10] = *(int *)(param_1 + 0x28);
  param_2[0xb] = param_1;
  iVar1 = *(int *)(param_1 + 0x3c);
  if (*(int *)(param_1 + 0x3c) == 0) {
    *(undefined4 **)(param_1 + 0x3c) = puVar2;
    *(undefined4 **)(param_1 + 0x40) = puVar2;
  }
  else {
    do {
      iVar3 = iVar1;
      iVar1 = *(int *)(iVar3 + 4);
    } while (*(int *)(iVar3 + 4) != 0);
    *(undefined4 **)(iVar3 + 4) = puVar2;
    puVar2[2] = iVar3;
    *(undefined4 **)(param_1 + 0x40) = puVar2;
  }
  (**(code **)(*param_2 + 0x80))(param_2,param_1);
                    /* WARNING: Could not recover jumptable at 0x0009fa67. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x54))();
  return;
}

