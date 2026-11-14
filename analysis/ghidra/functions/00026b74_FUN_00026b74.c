/* 00026b74 FUN_00026b74 */

void FUN_00026b74(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 undefined1 param_7)

{
  void *pvVar1;
  int iVar2;
  undefined1 local_38 [4];
  int local_34;
  int local_30;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  if ((param_2 != 0) && (param_6 != 0)) {
    FUN_0001ce0e(*(undefined4 *)(param_1 + 0x4c),*(undefined4 *)(param_1 + 0x24454 + param_3 * 4),
                 local_38);
    iVar2 = (local_30 - local_34) + 1;
    local_10 = (int)*(short *)(param_6 + 0x10) / iVar2 + param_5;
    local_14 = *(short *)(param_6 + 0xc) + param_4;
    local_1c = param_4;
    local_18 = param_5;
    pvVar1 = operator_new(0xb8);
    FUN_00007fba(pvVar1,&local_1c,param_1 + 0x20,param_3,param_6,iVar2);
    if (pvVar1 != (void *)0x0) {
      FUN_000266ca(param_1,pvVar1,param_3,param_2);
      param_1 = param_1 + param_3 * 0xc;
      (**(code **)(**(int **)(param_1 + 0x20854) + 0x134))(*(int **)(param_1 + 0x20854),5);
      *(undefined1 *)(*(int *)(param_1 + 0x20854) + 0x72) = param_7;
      *(undefined4 *)(param_1 + 0x2085c) = 5;
    }
  }
  return;
}

