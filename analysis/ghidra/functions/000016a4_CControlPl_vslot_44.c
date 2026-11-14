/* 000016a4 CControlPl_vslot_44 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CControlPl_vslot_44(int *param_1,float param_2)

{
  if (*(char *)((int)param_1 + 0x73) != '\0') {
    param_2 = 1.0 - param_2;
  }
  *(float *)(param_1[0x24] + 0xc) = param_2;
  if (*(float *)(param_1[0x24] + 0xc) != *(float *)(param_1[0x24] + 0x10)) {
                    /* WARNING: Could not recover jumptable at 0x00001701. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x54))();
    return;
  }
  return;
}

