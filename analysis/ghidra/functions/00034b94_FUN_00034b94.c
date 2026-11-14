/* 00034b94 FUN_00034b94 */

void FUN_00034b94(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_4 * 0x14;
  iVar1 = iVar3 + 0x1b;
  if ((((param_3 == -1) || (iVar1 == param_3)) || (iVar1 == -1)) &&
     (iVar2 = FUN_000122c2(*(undefined4 *)(param_1 + 0x120),param_2,iVar1), iVar2 == 1)) {
    if (param_4 == 0) {
      FUN_00012222(*(undefined4 *)(param_1 + 0x120),param_2,iVar1,0);
    }
    else {
      FUN_00033d1c(param_1,param_2,param_4);
    }
  }
  if (((((param_3 == -1) || (param_3 == iVar3 + 0xc)) ||
       ((iVar3 + 0xc == -1 || ((param_3 == iVar3 + 0xb || (iVar3 + 0xb == -1)))))) ||
      (param_3 == iVar3 + 0xe)) ||
     (((iVar3 + 0xe == -1 || (param_3 == iVar3 + 0xd)) || (iVar3 + 0xd == -1)))) {
    iVar1 = FUN_000122c2(*(undefined4 *)(param_1 + 0x120),param_2,iVar1);
    if (iVar1 == 1) {
      FUN_00033d1c();
      return;
    }
    param_4 = param_4 + 1;
    if (param_4 < 0x3f) {
      iVar1 = param_4 * 0x14 + 0x1b;
      while (iVar3 = FUN_000122c2(*(undefined4 *)(param_1 + 0x120),param_2,iVar1), iVar3 != 0) {
        FUN_00033d1c(param_1,param_2,param_4);
        param_4 = param_4 + 1;
        iVar1 = iVar1 + 0x14;
        if (param_4 == 0x3f) {
          return;
        }
      }
    }
  }
  return;
}

