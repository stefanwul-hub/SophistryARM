/* 00085a72 InBuffer2_c_vslot_9 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void InBuffer2_c_vslot_9(int param_1,char param_2)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  
  if (*(char *)(param_1 + 0x27) != '\0') {
    if (param_2 == '\0') {
      iVar5 = *(int *)(param_1 + 0x2c);
      *(undefined1 *)(param_1 + 0x26) = 1;
      *(undefined1 *)(param_1 + 0x27) = 0;
      cVar1 = *(char *)(param_1 + 0x29);
    }
    else {
      *(undefined4 *)(param_1 + 0x20) = 1;
      iVar5 = *(int *)(param_1 + 0x2c);
      if (0 < iVar5) {
        iVar3 = (iVar5 + -1) * 4;
        iVar5 = iVar5 + -1;
        do {
          pfVar4 = (float *)(iVar3 + *(int *)(param_1 + 0x34));
          *pfVar4 = (*pfVar4 + *(float *)(iVar3 + *(int *)(param_1 + 0x3c))) * 0.5;
          iVar3 = iVar3 + -4;
          bVar2 = 0 < iVar5;
          iVar5 = iVar5 + -1;
        } while (bVar2);
        iVar5 = *(int *)(param_1 + 0x2c);
      }
      *(undefined4 *)(param_1 + 0x20) = 4;
      *(undefined1 *)(param_1 + 0x26) = 1;
      *(undefined1 *)(param_1 + 0x27) = 0;
      cVar1 = *(char *)(param_1 + 0x29);
    }
    if (cVar1 != '\0') {
      _memcpy(*(void **)(param_1 + 0x38),*(void **)(param_1 + 0xc),iVar5 << 2);
      iVar5 = *(int *)(param_1 + 0x2c);
    }
    *(undefined1 *)(param_1 + 0x29) = 0;
    _memcpy(*(void **)(param_1 + 0x3c),*(void **)(param_1 + 0xc),iVar5 << 2);
  }
  return;
}

