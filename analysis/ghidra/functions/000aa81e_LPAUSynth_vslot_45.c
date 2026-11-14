/* 000aa81e LPAUSynth_vslot_45 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4
LPAUSynth_vslot_45(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  if (param_2 == 1) {
    piVar3 = *(int **)(param_1 + 0x3c) + param_3;
    if (((piVar3 < *(int **)(param_1 + 0x40)) && (*(int **)(param_1 + 0x3c) <= piVar3)) &&
       (*piVar3 != 0)) {
      piVar3 = (int *)___dynamic_cast(*piVar3,PTR_PTR_vtable_001038c8,PTR_PTR_vtable_001038c4,0);
joined_r0x000aa8a6:
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 0xc))(piVar3,param_5);
        FUN_000a67ae(param_1,8,param_2,param_3);
        return 0;
      }
    }
  }
  else if (param_2 == 0) {
    if ((*(int **)(param_1 + 0x50) < *(int **)(param_1 + 0x54)) &&
       (iVar1 = **(int **)(param_1 + 0x50), iVar1 != 0)) {
      piVar3 = (int *)___dynamic_cast(iVar1,PTR_PTR_vtable_001038c8,PTR_PTR_vtable_001038c4,0);
      goto joined_r0x000aa8a6;
    }
  }
  else {
    if (param_2 != 2) {
      puVar2 = (undefined4 *)___cxa_allocate_exception(4);
      *puVar2 = 0xffffd58e;
      goto LAB_000aa858;
    }
    piVar3 = *(int **)(param_1 + 0x50) + param_3;
    if (((piVar3 < *(int **)(param_1 + 0x54)) && (*(int **)(param_1 + 0x50) <= piVar3)) &&
       (*piVar3 != 0)) {
      piVar3 = (int *)___dynamic_cast(*piVar3,PTR_PTR_vtable_001038c8,PTR_PTR_vtable_001038c4,0);
      goto joined_r0x000aa8a6;
    }
  }
  puVar2 = (undefined4 *)___cxa_allocate_exception(4);
  *puVar2 = 0xffffd583;
LAB_000aa858:
                    /* WARNING: Subroutine does not return */
  ___cxa_throw(puVar2,PTR_001037fc,0);
}

