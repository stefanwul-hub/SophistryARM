/* 000a9772 LPAUSynth_vslot_50 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void LPAUSynth_vslot_50(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  if (param_2 < 5) {
    iVar1 = param_1 + 0x20 + param_2 * 0x14;
    piVar2 = *(int **)(iVar1 + 8);
    piVar3 = piVar2 + param_3;
    if (((piVar3 < *(int **)(iVar1 + 0xc)) && (piVar2 <= piVar3)) && (*piVar3 != 0)) {
      piVar3 = (int *)___dynamic_cast(*piVar3,PTR_PTR_vtable_001038c8,PTR_PTR_vtable_001038c4,0);
      if (piVar3 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000a97f9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*piVar3 + 0x18))();
        return;
      }
    }
    puVar4 = (undefined4 *)___cxa_allocate_exception(4);
    *puVar4 = 0xffffd583;
  }
  else {
    puVar4 = (undefined4 *)___cxa_allocate_exception(4);
    *puVar4 = 0xffffd58e;
  }
                    /* WARNING: Subroutine does not return */
  ___cxa_throw(puVar4,PTR_001037fc,0);
}

