/* 000953e4 Synth_vslot_41 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Synth_vslot_41(int *param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0xa8);
  (**(code **)(*param_1 + 0x80))(param_1);
                    /* WARNING: Could not recover jumptable at 0x00095458. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

