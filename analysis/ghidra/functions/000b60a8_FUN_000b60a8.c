/* 000b60a8 FUN_000b60a8 */

byte FUN_000b60a8(int param_1)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  
  bVar2 = 1;
  iVar3 = 0;
  iVar1 = 0;
  do {
    bVar2 = *(int *)(iVar1 + 0x408 + param_1) != 0 & *(int *)(iVar1 + 0x1e8 + param_1) != 0 & bVar2;
    iVar3 = iVar3 + 1;
    iVar1 = iVar1 + 0x44;
  } while (iVar3 != 8);
  iVar3 = 0;
  iVar1 = 0;
  do {
    bVar2 = *(int *)(iVar1 + 0x6b8 + param_1) != 0 & *(int *)(iVar1 + 0x628 + param_1) != 0 & bVar2;
    iVar3 = iVar3 + 1;
    iVar1 = iVar1 + 0x18;
  } while (iVar3 != 6);
  return *(int *)(param_1 + 0x748) != 0 & bVar2;
}

