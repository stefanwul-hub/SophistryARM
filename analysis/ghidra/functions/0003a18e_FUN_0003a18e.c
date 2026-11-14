/* 0003a18e FUN_0003a18e */

void FUN_0003a18e(int param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  longdouble lVar2;
  
  if ((*(int *)(param_1 + 0x120) != 0) && (0 < *(int *)(param_1 + 0x1dc))) {
    iVar1 = FUN_00011b72(*(int *)(param_1 + 0x120),0);
    if (*(int *)(iVar1 + 0x78) == param_2) {
      if ((((*(int *)(iVar1 + 0x318) <= *(int *)(param_3 + 8)) &&
           (*(int *)(param_3 + 8) <= *(int *)(iVar1 + 0x388))) &&
          (*(int *)(iVar1 + 0x3f8) <= *(int *)(param_3 + 0xc))) &&
         (*(int *)(param_3 + 0xc) <= *(int *)(iVar1 + 0x468))) {
        *param_4 = param_1 + 0x1e4;
        iVar1 = FUN_000122c2(*(undefined4 *)(param_1 + 0x120),0,6);
        lVar2 = (longdouble)FUN_000130fe(param_1,(float)iVar1);
        *(float *)(param_1 + 0x41c) = (float)lVar2;
        lVar2 = (longdouble)FUN_000152c0((float)*(int *)(param_1 + 0x3f4),(float)lVar2);
        *(float *)(param_1 + 0x408) = (float)lVar2;
      }
    }
  }
  return;
}

