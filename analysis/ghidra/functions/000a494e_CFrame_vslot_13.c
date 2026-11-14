/* 000a494e CFrame_vslot_13 */

undefined1
CFrame_vslot_13(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  undefined1 uVar4;
  int *piVar5;
  
  piVar5 = (int *)param_1[0x1a];
  if ((piVar5 == (int *)0x0) &&
     (piVar5 = (int *)(**(code **)(*param_1 + 0xec))(param_1,param_3,0), piVar5 == (int *)0x0)) {
    return 0;
  }
  if (param_2 == (int *)0x0) {
    piVar1 = (int *)param_1[0x25];
    if (piVar1 == (int *)0x0) {
      iVar2 = param_1[0x19];
      param_2 = (int *)operator_new(0x68);
      FUN_000a171a(param_2,param_1,0,iVar2);
      bVar3 = true;
    }
    else {
      (**(code **)(*piVar1 + 0xc))(piVar1);
      param_2 = (int *)param_1[0x25];
      bVar3 = true;
    }
  }
  else {
    bVar3 = false;
  }
  uVar4 = (**(code **)(*piVar5 + 0x34))(piVar5,param_2,param_3,param_4,param_5);
  if (bVar3) {
    (**(code **)(*param_2 + 8))(param_2);
  }
  return uVar4;
}

