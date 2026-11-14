/* 000aecdc FUN_000aecdc */

bool FUN_000aecdc(int param_1)

{
  int iVar1;
  bool bVar2;
  
  *(undefined4 *)(param_1 + 0x22c) = 0;
  bVar2 = *(int *)(param_1 + 0x21c) == 0;
  if (bVar2) {
    iVar1 = *(int *)(param_1 + 0x220);
  }
  else {
    *(undefined4 *)(param_1 + 0x22c) = 0;
    _free(*(void **)(param_1 + 0x21c));
    *(undefined4 *)(param_1 + 0x21c) = 0;
    iVar1 = *(int *)(param_1 + 0x220);
  }
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x22c) = 0;
    _free(*(void **)(param_1 + 0x220));
    *(undefined4 *)(param_1 + 0x220) = 0;
  }
  *(undefined4 *)(param_1 + 0x22c) = 0;
  *(undefined1 *)(param_1 + 0x214) = 0;
  *(undefined1 *)(param_1 + 0x230) = 0;
  *(undefined1 *)(param_1 + 0x231) = 0;
  *(undefined1 *)(param_1 + 0x232) = 0;
  *(undefined1 *)(param_1 + 600) = 0;
  *(undefined1 *)(param_1 + 0x260) = 0;
  *(undefined1 *)(param_1 + 0x233) = 0;
  *(undefined1 *)(param_1 + 0x234) = 0;
  return iVar1 != 0 || !bVar2;
}

