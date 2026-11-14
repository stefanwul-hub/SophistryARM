/* 00012930 Envelope_c_vslot_41 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Envelope_c_vslot_41(int *param_1,float param_2)

{
  if ((10.0 < param_2) && (0.01 < ABS(param_2 - (float)param_1[0x54]))) {
    param_1[0x54] = (int)param_2;
    param_1[0x55] = (int)(1.0 / param_2);
                    /* WARNING: Could not recover jumptable at 0x0001299f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0xd8))();
    return;
  }
  return;
}

