/* 0001a7c4 FUN_0001a7c4 */

undefined4 FUN_0001a7c4(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x3b88))) {
    iVar1 = param_2 * 0x1c + param_1;
    if ((*(int *)(iVar1 + 0x511c) != 0) &&
       (((-1 < param_3 && (param_3 < *(int *)(iVar1 + 0x512c))) && (param_4 != 0)))) {
      *(int *)(*(int *)(iVar1 + 0x511c) + param_3 * 4) = param_4;
      if (param_3 == *(int *)(iVar1 + 0x512c) + -1) {
        FUN_0001a686(param_1,param_2);
      }
      return 1;
    }
  }
  return 0;
}

