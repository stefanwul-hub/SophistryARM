/* 00034afc FUN_00034afc */

void FUN_00034afc(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x120) != 0) {
    iVar1 = FUN_00011b72(*(int *)(param_1 + 0x120),param_2);
    if (iVar1 != 0) {
      iVar1 = iVar1 + 0x690;
      iVar2 = 0x40;
      do {
        FUN_000109ee(iVar1,999999999);
        FUN_000109ee(iVar1 + 0x230,999999999);
        FUN_000109ee(iVar1 + 0x2a0,999999999);
        FUN_000109ee(iVar1 + 0x460,999999999);
        iVar1 = iVar1 + 0x8c0;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  return;
}

