/* 000a6c4e LPAUSynth_vslot_46 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void * LPAUSynth_vslot_46(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  void *pvVar2;
  
  switch(param_2) {
  case 0:
  case 3:
  case 4:
    pvVar2 = operator_new(0x34);
    FUN_000c5b4c(pvVar2,param_1);
    return pvVar2;
  case 1:
    pvVar2 = operator_new(0x9c);
    FUN_000ab370(pvVar2,param_1);
    return pvVar2;
  case 2:
    pvVar2 = operator_new(0x78);
    FUN_000ab56a(pvVar2,param_1);
    return pvVar2;
  default:
    puVar1 = (undefined4 *)___cxa_allocate_exception(4);
    *puVar1 = 0xffffd58e;
                    /* WARNING: Subroutine does not return */
    ___cxa_throw(puVar1,PTR_001037fc,0);
  }
}

