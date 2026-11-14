/* 0001d532 FUN_0001d532 */

void FUN_0001d532(int *param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  int local_18;
  int *local_14;
  undefined4 local_10;
  
  if (param_3 != (undefined4 *)0x0) {
    if ((char)param_1[0x33f1] == '\0') {
      (**(code **)(*param_1 + 0xc))(param_1);
    }
    if ((char)param_1[0x33f1] == '\0') {
      *param_3 = 0x2d2d2d;
      return;
    }
    _OSAtomicAdd32Barrier(1,param_1 + 0xecc);
    local_18 = -1;
    FUN_0001cb52(param_1,param_2 % param_1[0xecf],&local_14,&local_18,&local_10);
    if (local_18 == -1) {
      *(undefined2 *)param_3 = 0x2d;
    }
    else if (local_14 != (int *)0x0) {
      (**(code **)(*local_14 + 0x50))(local_14,local_10,local_18,param_3,param_4);
    }
    _OSAtomicAdd32Barrier(0xffffffff,param_1 + 0xecc);
  }
  return;
}

