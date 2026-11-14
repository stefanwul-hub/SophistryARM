/* 00094944 CKeyboard2_vslot_80 */

void CKeyboard2_vslot_80(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0x80;
  iVar1 = param_1;
  do {
    *(undefined4 *)(iVar1 + 0xb0) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined1 *)(param_1 + 0x74) = 1;
  return;
}

