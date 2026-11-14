/* 000a6e76 LPAUSynth_vslot_26 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4
LPAUSynth_vslot_26(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  undefined4 *puVar2;
  
  piVar1 = *(int **)(param_1 + 0x3c) + param_3;
  if (((piVar1 < *(int **)(param_1 + 0x40)) && (*(int **)(param_1 + 0x3c) <= piVar1)) &&
     (*piVar1 != 0)) {
    FUN_000ab312(*piVar1,param_4,param_5);
    FUN_000a67ae(param_1,param_2,1,param_3);
    return 0;
  }
  puVar2 = (undefined4 *)___cxa_allocate_exception(4);
  *puVar2 = 0xffffd583;
                    /* WARNING: Subroutine does not return */
  ___cxa_throw(puVar2,PTR_001037fc,0);
}

