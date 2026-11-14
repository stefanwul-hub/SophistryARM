/* 000ad132 FUN_000ad132 */

void FUN_000ad132(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = _CFArrayGetCount(*(undefined4 *)(param_1 + 0x14));
  if (*param_2 < 0) {
    _SetControl32BitValue(*(undefined4 *)(param_1 + 8),0);
  }
  else if (0 < iVar1) {
    iVar3 = 0;
    do {
      piVar2 = (int *)_CFArrayGetValueAtIndex(*(undefined4 *)(param_1 + 0x14),iVar3);
      if (*param_2 == *piVar2) {
        _SetControl32BitValue(*(undefined4 *)(param_1 + 8),iVar3 + 1);
        break;
      }
      iVar3 = iVar3 + 1;
    } while (iVar1 != iVar3);
  }
  if (param_2[1] != 0) {
    _CFRelease();
    return;
  }
  return;
}

