/* 0001ce0e FUN_0001ce0e */

void FUN_0001ce0e(int param_1,int param_2,undefined4 *param_3)

{
  int local_18;
  int *local_14;
  undefined4 local_10;
  
  if (param_3 != (undefined4 *)0x0) {
    FUN_0001cb52(param_1,param_2 % *(int *)(param_1 + 0x3b3c),&local_14,&local_18,&local_10);
    if (local_18 == -1) {
      *param_3 = *(undefined4 *)(param_1 + 0x92e8);
      param_3[1] = *(undefined4 *)(param_1 + 0x92ec);
      param_3[2] = *(undefined4 *)(param_1 + 0x92f0);
      param_3[3] = *(undefined4 *)(param_1 + 0x92f4);
      param_3[4] = *(undefined4 *)(param_1 + 0x92f8);
      param_3[5] = *(undefined4 *)(param_1 + 0x92fc);
      param_3[6] = *(undefined4 *)(param_1 + 0x9300);
      return;
    }
    if (local_14 != (int *)0x0) {
      (**(code **)(*local_14 + 0x5c))(local_14,local_10,local_18,param_3);
    }
  }
  return;
}

