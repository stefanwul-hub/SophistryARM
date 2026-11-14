/* 00095536 Synth_vslot_39 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Synth_vslot_39(int *param_1,float param_2,char *param_3,size_t param_4)

{
  int iVar1;
  
  if ((param_2 <= 0.0) && (!NAN(param_2))) {
    _strncpy(param_3,"-oo",param_4);
    param_3[param_4] = '\0';
    return;
  }
  iVar1 = *param_1;
  _log10((double)param_2);
                    /* WARNING: Could not recover jumptable at 0x000955a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar1 + 0xa8))();
  return;
}

