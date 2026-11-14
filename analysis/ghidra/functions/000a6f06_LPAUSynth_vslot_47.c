/* 000a6f06 LPAUSynth_vslot_47 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void LPAUSynth_vslot_47(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int local_24;
  int local_20;
  
  FUN_000a6a2a(param_1);
  iVar3 = *(int *)(param_1 + 0x54) - *(int *)(param_1 + 0x50) >> 2;
  if (0 < iVar3) {
    local_24 = 0;
    do {
      piVar1 = *(int **)(param_1 + 0x50) + local_24;
      if (((*(int **)(param_1 + 0x54) <= piVar1) || (piVar1 < *(int **)(param_1 + 0x50))) ||
         (*piVar1 == 0)) goto LAB_000a6f53;
      FUN_000ab9ac(*piVar1,0);
      local_24 = local_24 + 1;
    } while (iVar3 != local_24);
  }
  iVar3 = *(int *)(param_1 + 0x40) - *(int *)(param_1 + 0x3c) >> 2;
  if (0 < iVar3) {
    local_20 = 0;
    do {
      piVar1 = *(int **)(param_1 + 0x3c) + local_20;
      if (((*(int **)(param_1 + 0x40) <= piVar1) || (piVar1 < *(int **)(param_1 + 0x3c))) ||
         (*piVar1 == 0)) {
LAB_000a6f53:
        puVar2 = (undefined4 *)___cxa_allocate_exception(4);
        *puVar2 = 0xffffd583;
                    /* WARNING: Subroutine does not return */
        ___cxa_throw(puVar2,PTR_001037fc,0);
      }
      FUN_000ab9ac(*piVar1,0);
      local_20 = local_20 + 1;
    } while (iVar3 != local_20);
  }
  *(undefined1 *)(param_1 + 0xdc) = 1;
  return;
}

