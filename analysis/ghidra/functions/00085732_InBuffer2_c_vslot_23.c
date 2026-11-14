/* 00085732 InBuffer2_c_vslot_23 */

void InBuffer2_c_vslot_23(int param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  
  if (0 < *(int *)(param_1 + 0x18)) {
    iVar3 = 0;
    iVar2 = param_1;
    do {
      while (pvVar1 = *(void **)(iVar2 + 0x34), pvVar1 != (void *)0x0) {
        if (*(char *)(param_1 + 0x25) == '\0') {
          _memcpy(pvVar1,*(void **)(param_1 + 0xc),*(int *)(param_1 + 0x1c) << 2);
        }
        else {
          if ((iVar3 != 1) && (iVar3 != 3)) break;
          _memcpy(pvVar1,*(void **)(param_1 + 0xc),*(int *)(param_1 + 0x1c) << 2);
        }
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 4;
        if (*(int *)(param_1 + 0x18) <= iVar3) {
          return;
        }
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 4;
    } while (iVar3 < *(int *)(param_1 + 0x18));
  }
  return;
}

