/* 000a8f1a AUBase_vslot_24 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 AUBase_vslot_24(int param_1,uint param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  if (param_2 < 5) {
    FUN_000abf88(param_1 + 0x20 + param_2 * 0x14,param_3);
    return 0;
  }
  puVar1 = (undefined4 *)___cxa_allocate_exception(4);
  *puVar1 = 0xffffd58e;
                    /* WARNING: Subroutine does not return */
  ___cxa_throw(puVar1,PTR_001037fc,0);
}

