/* 00054f62 FUN_00054f62 */

void FUN_00054f62(int param_1,int *param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  if (param_2 != (int *)0x0) {
    iVar2 = (**(code **)(*param_2 + 0x24))(param_2);
    if (iVar2 != 0) {
      local_20 = param_5 + 0xb;
      local_24 = param_4 + 0x41;
      local_2c = param_4;
      local_28 = param_5;
      pvVar3 = operator_new(0xe4);
      iVar1 = param_1 + 0x54 + param_3 * 0x68;
      FUN_00007460(pvVar3,&local_2c,iVar1,param_3,iVar2,*(undefined4 *)(param_1 + 0x27914),0x21,
                   0x43960000,0,1);
      if (pvVar3 != (void *)0x0) {
        *(undefined1 *)((int)pvVar3 + 0x72) = 1;
        FUN_0000b7e2(iVar1,pvVar3,param_3,param_1,*(undefined4 *)(param_1 + 0x4c),param_2);
      }
    }
  }
  return;
}

