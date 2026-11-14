/* 000aa6f0 LPAUSynth_vslot_44 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int LPAUSynth_vslot_44(int param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (param_2 == 1) {
    piVar1 = *(int **)(param_1 + 0x3c) + param_3;
    if (((piVar1 < *(int **)(param_1 + 0x40)) && (*(int **)(param_1 + 0x3c) <= piVar1)) &&
       (*piVar1 != 0)) {
      iVar3 = ___dynamic_cast(*piVar1,PTR_PTR_vtable_001038c8,PTR_PTR_vtable_001038c4,0);
joined_r0x000aa773:
      if (iVar3 != 0) {
        return iVar3 + 0x34;
      }
    }
  }
  else if (param_2 == 0) {
    if ((*(int **)(param_1 + 0x50) < *(int **)(param_1 + 0x54)) &&
       (iVar3 = **(int **)(param_1 + 0x50), iVar3 != 0)) {
      iVar3 = ___dynamic_cast(iVar3,PTR_PTR_vtable_001038c8,PTR_PTR_vtable_001038c4,0);
      goto joined_r0x000aa773;
    }
  }
  else {
    if (param_2 != 2) {
      puVar2 = (undefined4 *)___cxa_allocate_exception(4);
      *puVar2 = 0xffffd58e;
      goto LAB_000aa725;
    }
    piVar1 = *(int **)(param_1 + 0x50) + param_3;
    if (((piVar1 < *(int **)(param_1 + 0x54)) && (*(int **)(param_1 + 0x50) <= piVar1)) &&
       (*piVar1 != 0)) {
      iVar3 = ___dynamic_cast(*piVar1,PTR_PTR_vtable_001038c8,PTR_PTR_vtable_001038c4,0);
      goto joined_r0x000aa773;
    }
  }
  puVar2 = (undefined4 *)___cxa_allocate_exception(4);
  *puVar2 = 0xffffd583;
LAB_000aa725:
                    /* WARNING: Subroutine does not return */
  ___cxa_throw(puVar2,PTR_001037fc,0);
}

