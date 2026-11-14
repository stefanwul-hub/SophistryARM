/* 000a8134 AUBase_vslot_16 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 AUBase_vslot_16(int *param_1,undefined4 param_2,uint param_3,int param_4,float *param_5)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  longdouble lVar4;
  
  if (param_3 == 3) {
                    /* WARNING: Could not recover jumptable at 0x000a81d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (**(code **)(*param_1 + 0x4c))();
    return uVar3;
  }
  if (param_3 < 5) {
    piVar1 = (int *)param_1[param_3 * 5 + 10] + param_4;
    if (((piVar1 < (int *)param_1[param_3 * 5 + 0xb]) &&
        ((int *)param_1[param_3 * 5 + 10] <= piVar1)) && (*piVar1 != 0)) {
      lVar4 = (longdouble)FUN_000ac3ea(*piVar1,param_2);
      *param_5 = (float)lVar4;
      return 0;
    }
    puVar2 = (undefined4 *)___cxa_allocate_exception(4);
    *puVar2 = 0xffffd583;
  }
  else {
    puVar2 = (undefined4 *)___cxa_allocate_exception(4);
    *puVar2 = 0xffffd58e;
  }
                    /* WARNING: Subroutine does not return */
  ___cxa_throw(puVar2,PTR_001037fc,0);
}

