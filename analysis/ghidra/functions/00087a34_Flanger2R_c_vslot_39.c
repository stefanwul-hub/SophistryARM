/* 00087a34 Flanger2R_c_vslot_39 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Flanger2R_c_vslot_39(int param_1,int param_2)

{
  int iVar1;
  float fVar2;
  
  if ((((*(char *)(param_2 + 0x1b4 + param_1) != '\0') && (param_2 == *(int *)(param_1 + 0x128))) &&
      (*(char *)(param_1 + 0x15c) != '\0')) &&
     (((*(int *)(param_1 + 0x20c) != 0 && (*(int *)(param_1 + 0x210) != 0)) &&
      (0 < *(int *)(param_1 + 0x1e0))))) {
    fVar2 = 1e-07;
    iVar1 = 0;
    do {
      *(float *)(*(int *)(param_1 + 0x20c) + iVar1 * 4) = fVar2;
      fVar2 = -fVar2;
      *(float *)(*(int *)(param_1 + 0x210) + iVar1 * 4) = fVar2;
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x1e0));
    return;
  }
  return;
}

