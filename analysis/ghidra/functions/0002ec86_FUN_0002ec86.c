/* 0002ec86 FUN_0002ec86 */

undefined4 FUN_0002ec86(int param_1,int param_2,int param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    if (param_2 < 0) {
      param_2 = 0;
    }
    iVar2 = *(int *)(param_1 + 0xc) + -1;
    if (param_2 <= iVar2) {
      iVar2 = param_2;
    }
    piVar1 = (int *)(*(int *)(param_1 + 0x10) + iVar2 * 0x24);
    if ((*piVar1 != 0) && (piVar1[1] == param_3)) {
      *param_4 = piVar1[3];
      return 1;
    }
  }
  return 0;
}

