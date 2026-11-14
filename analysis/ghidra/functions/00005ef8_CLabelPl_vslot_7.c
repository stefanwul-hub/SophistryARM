/* 00005ef8 CLabelPl_vslot_7 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CLabelPl_vslot_7(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x5c))(param_1);
  if (cVar1 == '\0') {
    return;
  }
  FUN_000019d6(param_1);
  FUN_00001b2e();
  return;
}

