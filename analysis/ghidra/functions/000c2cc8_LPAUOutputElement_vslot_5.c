/* 000c2cc8 LPAUOutputElement_vslot_5 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 LPAUOutputElement_vslot_5(undefined4 param_1,undefined4 *param_2)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_0010386c;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)PTR_DAT_0010386c;
    param_2[1] = *(undefined4 *)(puVar1 + 4);
  }
  return 2;
}

