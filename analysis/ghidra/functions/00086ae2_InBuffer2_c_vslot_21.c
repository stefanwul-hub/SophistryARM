/* 00086ae2 InBuffer2_c_vslot_21 */

void InBuffer2_c_vslot_21(int param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x18) < 1) {
    return;
  }
  iVar3 = 0;
  iVar2 = param_1;
  do {
    if (*(int *)(param_1 + 0x1c) < 1) {
      if (*(int *)(param_1 + 0x18) <= iVar3 + 1) {
        return;
      }
    }
    else {
      pvVar1 = _malloc(*(int *)(param_1 + 0x1c) * 4 + 0x14);
      *(void **)(iVar2 + 0x34) = pvVar1;
      if (*(int *)(param_1 + 0x18) <= iVar3 + 1) {
        return;
      }
    }
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + 4;
  } while( true );
}

