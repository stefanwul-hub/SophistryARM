/* 00039ed0 FUN_00039ed0 */

char FUN_00039ed0(int param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  
  if (((-1 < param_2) && (param_2 < 1)) && (*(int *)(param_1 + 0x120) != 0)) {
    iVar2 = param_2 * 0x274 + 0x1e0 + param_1;
    cVar1 = FUN_0002ddaa(iVar2 + 0x1d8);
    if (cVar1 != '\0') {
      if (*(int *)(iVar2 + 0x220) != 0) {
        FUN_000aecdc(iVar2 + 4);
        *(undefined4 *)(iVar2 + 0x220) = 0;
        *(int *)(param_1 + 0x1dc) = *(int *)(param_1 + 0x1dc) + -1;
      }
      cVar1 = FUN_000b2f68(iVar2 + 4,param_3);
      if (cVar1 != '\0') {
        if (*(char *)(iVar2 + 0x238) == '\0') {
          FUN_0003225a(param_1,*(undefined4 *)(iVar2 + 0x220),*(undefined4 *)(iVar2 + 0x230));
          FUN_00032430(param_1,*(undefined4 *)(iVar2 + 0x220),*(undefined4 *)(iVar2 + 0x230));
          FUN_000322d4(param_1,*(undefined4 *)(iVar2 + 0x220),*(undefined4 *)(iVar2 + 0x230));
          if (*(char *)(iVar2 + 0x218) != '\0') {
            FUN_0003225a(param_1,*(undefined4 *)(iVar2 + 0x224),*(undefined4 *)(iVar2 + 0x230));
            FUN_00032430(param_1,*(undefined4 *)(iVar2 + 0x224),*(undefined4 *)(iVar2 + 0x230));
            FUN_000322d4(param_1,*(undefined4 *)(iVar2 + 0x224),*(undefined4 *)(iVar2 + 0x230));
          }
        }
        if (*(int *)(iVar2 + 0x220) != 0) {
          *(int *)(param_1 + 0x1dc) = *(int *)(param_1 + 0x1dc) + 1;
        }
      }
      FUN_0002ddc8(iVar2 + 0x1d8);
      return cVar1;
    }
  }
  return '\0';
}

