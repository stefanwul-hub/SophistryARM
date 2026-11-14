/* 00085538 InBuffer2_c_vslot_22 */

void InBuffer2_c_vslot_22(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x18);
  if (0 < iVar1) {
    iVar3 = 0;
    iVar2 = param_1;
    do {
      if (((*(char *)(param_1 + 0x25) == '\0') || (iVar3 == 1)) || (iVar3 == 3)) {
        if (*(void **)(iVar2 + 0x34) != (void *)0x0) {
          _free(*(void **)(iVar2 + 0x34));
          iVar1 = *(int *)(param_1 + 0x18);
        }
        *(undefined4 *)(iVar2 + 0x34) = 0;
        if (iVar1 <= iVar3 + 1) break;
      }
      else if (iVar1 <= iVar3 + 1) break;
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 4;
    } while( true );
  }
  if (iVar1 < 8) {
    do {
      iVar1 = iVar1 + 1;
    } while (iVar1 != 8);
  }
  return;
}

