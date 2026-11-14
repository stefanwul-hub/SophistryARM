/* 0003c90e EnvADSFR_c_vslot_57 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void EnvADSFR_c_vslot_57(int param_1)

{
  int iVar1;
  char cVar2;
  float *pfVar3;
  undefined4 local_14;
  undefined4 local_10;
  
  if (*(int *)(param_1 + 0x124) != 0) {
    if ((*(char *)(*(int *)(param_1 + 0x124) + 0x40c) != '\0') &&
       (cVar2 = FUN_0000f0ee(param_1,&local_14,&local_10), cVar2 != '\0')) {
      **(undefined4 **)(param_1 + 0x1d8) = local_14;
      **(undefined4 **)(param_1 + 0x1dc) = local_10;
      return;
    }
    iVar1 = *(int *)(param_1 + 0x1f0);
    if (iVar1 == 2) {
      **(undefined4 **)(param_1 + 0x1d8) = 0;
      **(undefined4 **)(param_1 + 0x1dc) = 0x7ffffbff;
      pfVar3 = *(float **)(param_1 + 0x1d4);
      if (0.0001 <= ABS(*pfVar3)) {
        return;
      }
      if (NAN(ABS(*pfVar3))) {
        return;
      }
      if (*(char *)(param_1 + 0x1f8) == '\0') {
        return;
      }
      *(undefined4 *)(param_1 + 0x1f0) = 4;
    }
    else {
      if (iVar1 < 3) {
        FUN_0003c484(param_1,iVar1 + 1);
        return;
      }
      if (*(char *)(param_1 + 0x1f8) == '\0') {
        return;
      }
      *(undefined4 *)(param_1 + 0x1f0) = 4;
      pfVar3 = *(float **)(param_1 + 0x1d4);
    }
    *pfVar3 = 0.0;
    **(undefined4 **)(param_1 + 0x1d8) = 0;
    **(undefined4 **)(param_1 + 0x1dc) = 0x7ffffbff;
    *(undefined1 *)(param_1 + 0x1e0) = 1;
  }
  return;
}

