/* 0005984e FUN_0005984e */

void FUN_0005984e(int param_1,int *param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  int local_10;
  
  if (param_2 != (int *)0x0) {
    iVar2 = (**(code **)(*param_2 + 0x24))(param_2);
    if (iVar2 != 0) {
      local_10 = param_3 * 0xd + 0x15;
      local_18 = param_3 * 0xd + 10;
      local_1c = 0xc;
      local_14 = 0x43;
      uVar1 = *(undefined4 *)(param_1 + 0x34);
      piVar3 = (int *)operator_new(0xd8);
      FUN_00005f56(piVar3,&local_1c,param_1 + 0x20,0,iVar2,4,uVar1,0);
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0x130))(piVar3,param_4);
        (**(code **)(*param_2 + 0xac))(param_2,piVar3);
      }
    }
  }
  return;
}

