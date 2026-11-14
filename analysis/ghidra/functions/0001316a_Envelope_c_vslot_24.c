/* 0001316a Envelope_c_vslot_24 */

void Envelope_c_vslot_24(int *param_1,undefined4 param_2,int param_3,int param_4,int *param_5)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if ((param_5 != (int *)0x0) && (((param_3 == -1 || (param_3 == param_4)) || (param_4 == -1)))) {
    UNRECOVERED_JUMPTABLE = *(code **)(*param_5 + 0x1c);
    (**(code **)(*param_1 + 0x20))(param_1,param_2,param_4);
                    /* WARNING: Could not recover jumptable at 0x000131d5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  return;
}

