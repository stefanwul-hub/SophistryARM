/* 0002f80e FUN_0002f80e */

int FUN_0002f80e(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    if (param_2 < 0) {
      param_2 = 0;
    }
    iVar1 = *(int *)(param_1 + 0xc) + -1;
    if (param_2 <= iVar1) {
      iVar1 = param_2;
    }
    FUN_0002f468(param_1,iVar1,3,0);
    return *(int *)(param_1 + 0x10) + iVar1 * 0x24;
  }
  return 0;
}

