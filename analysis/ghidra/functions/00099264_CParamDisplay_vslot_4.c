/* 00099264 CParamDisplay_vslot_4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CParamDisplay_vslot_4(int param_1,undefined4 param_2)

{
  code *pcVar1;
  char local_11c [268];
  
  local_11c[0] = '\0';
  pcVar1 = *(code **)(param_1 + 0x70);
  if ((pcVar1 == (code *)0x0) && (pcVar1 = *(code **)(param_1 + 0x6c), pcVar1 == (code *)0x0)) {
    _sprintf(local_11c,"%2.2f",(double)*(float *)(param_1 + 0x4c));
  }
  else {
    (*pcVar1)(*(undefined4 *)(param_1 + 0x4c),local_11c);
  }
  FUN_00098ac0(param_1,param_2,local_11c,0);
  return;
}

