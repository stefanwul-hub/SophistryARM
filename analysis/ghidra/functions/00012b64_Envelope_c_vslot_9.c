/* 00012b64 Envelope_c_vslot_9 */

void Envelope_c_vslot_9(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1[0x48] != 0) {
    FUN_00012222(param_1[0x48],param_2,param_3,param_4);
                    /* WARNING: Could not recover jumptable at 0x00012bb3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x78))();
    return;
  }
  return;
}

