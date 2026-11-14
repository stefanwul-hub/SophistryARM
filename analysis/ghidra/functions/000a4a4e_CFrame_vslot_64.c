/* 000a4a4e CFrame_vslot_64 */

void CFrame_vslot_64(int *param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  
  cVar2 = (**(code **)(*param_1 + 0x150))(param_1);
  if (cVar2 != '\0') {
    if ((param_1[0x19] != 0) && (cVar2 = _IsWindowCollapsed(param_1[0x19]), cVar2 != '\0')) {
      return;
    }
    if (((char)param_1[0x1c] == '\0') &&
       (cVar2 = (**(code **)(*param_1 + 0x50))(param_1), cVar2 != '\0')) {
      piVar3 = (int *)param_1[0x25];
      if (piVar3 == (int *)0x0) {
        iVar1 = param_1[0x19];
        piVar3 = (int *)operator_new(0x68);
        FUN_000a171a(piVar3,param_1,0,iVar1);
      }
      else {
        (**(code **)(*piVar3 + 0xc))(piVar3);
        piVar3 = (int *)param_1[0x25];
      }
      (**(code **)(*param_1 + 0xa8))(param_1,piVar3);
                    /* WARNING: Could not recover jumptable at 0x000a4ac9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*piVar3 + 8))();
      return;
    }
  }
  return;
}

