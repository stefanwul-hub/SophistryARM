/* 00071336 FUN_00071336 */

uint FUN_00071336(uint param_1)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  char local_14c [320];
  
  iVar4 = (*(int *)(param_1 + 0x794) + 1) % *(int *)(param_1 + 0x1ec);
  *(int *)(param_1 + 0x794) = iVar4;
  FUN_00010aee(*(int *)(param_1 + 0x124) + 0x460,local_14c);
  local_14c[0] = (char)iVar4 + '\x01';
  FUN_00010e34(*(int *)(param_1 + 0x124) + 0x460,local_14c);
  piVar2 = *(int **)(param_1 + 0x1d8);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x358))(piVar2);
  }
  *(undefined4 *)(param_1 + 0x778) = 0;
  bVar1 = *(byte *)(*(int *)(param_1 + 0x794) + 0x28c + param_1);
  uVar3 = (uint)bVar1;
  if ((bVar1 != 0x80) && (bVar1 != 0)) {
    if (*(int *)(param_1 + 0x314) == 9) {
      if (0 < *(int *)(param_1 + 0x758)) {
        iVar4 = *(int *)(param_1 + 0x310) + 1;
        *(int *)(param_1 + 0x310) = iVar4 % *(int *)(param_1 + 0x30c);
        return iVar4 / *(int *)(param_1 + 0x30c);
      }
      *(undefined1 *)(param_1 + 0x75c) = 0xff;
      *(undefined4 *)(param_1 + 0x778) = 0xffffffff;
      uVar3 = param_1;
    }
    else {
      uVar3 = FUN_00070c94(param_1);
      if (*(char *)(param_1 + 0x75c) < '\0') {
        *(undefined4 *)(param_1 + 0x778) = 0xffffffff;
        return uVar3;
      }
    }
  }
  return uVar3;
}

