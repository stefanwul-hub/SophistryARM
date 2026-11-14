/* 000ae1e6 FUN_000ae1e6 */

void FUN_000ae1e6(int param_1,int param_2,undefined4 *param_3)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_3[1] & 0xfffffff0;
  pvVar1 = *(void **)(param_1 + 0xc);
  if ((pvVar1 != (void *)0x0) && (*(uint *)(param_1 + 0x18) <= uVar3)) {
    *(undefined4 *)(param_1 + 0xc) = *param_3;
    *(uint *)(param_1 + 0x18) = uVar3;
    if ((*(int *)(param_2 + 8) == 0x6c70636d) && ((*(byte *)(param_2 + 0xc) & 0x20) != 0)) {
      iVar2 = *(int *)(param_2 + 0x1c);
    }
    else {
      iVar2 = 1;
    }
    *(uint *)(param_1 + 0x14) = uVar3 / (uint)(iVar2 * *(int *)(param_2 + 0x18));
    *(undefined1 *)(param_1 + 4) = 1;
    _free(pvVar1);
    return;
  }
  return;
}

