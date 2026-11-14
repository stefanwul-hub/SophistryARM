/* 0008e28c FUN_0008e28c */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

char FUN_0008e28c(int param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  int local_20;
  
  if ((*(int *)(param_1 + 0x120) != 0) &&
     (iVar2 = FUN_00011b72(*(int *)(param_1 + 0x120),param_2), iVar2 != 0)) {
    iVar2 = param_1 + param_2 * 0x274 + 0x1d8;
    cVar1 = FUN_000b2f68(iVar2,param_3);
    if (cVar1 != '\0') {
      FUN_000af2b2(iVar2);
      FUN_00032430(iVar2,*(undefined4 *)(iVar2 + 0x21c),*(undefined4 *)(iVar2 + 0x22c));
      if ((*(int *)(param_1 + 0x120) != 0) &&
         (iVar3 = FUN_00011b72(*(int *)(param_1 + 0x120),param_2), iVar3 != 0)) {
        if ((*(int *)(param_1 + 0x120) != 0) &&
           (iVar4 = FUN_00011b72(*(int *)(param_1 + 0x120),param_2), iVar4 != 0)) {
          if (*(int *)(iVar2 + 0x21c) == 0) {
            return cVar1;
          }
          fVar5 = (float)(*(int *)(iVar2 + 0x22c) + -1);
          local_20 = (int)(fVar5 * *(float *)(iVar4 + 0x15c) * 0.01 + 0.25);
          iVar2 = (int)(fVar5 * *(float *)(iVar4 + 0x1cc) * 0.01 + 0.25);
        }
        if (local_20 < iVar2) {
          FUN_0008de6a(param_1,param_2,*(undefined4 *)(iVar3 + 0xe8),local_20,iVar2);
        }
      }
    }
    return cVar1;
  }
  return '\0';
}

