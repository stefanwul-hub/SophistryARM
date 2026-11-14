/* 0000c4ce Instrument_c_vslot_10 */

void Instrument_c_vslot_10(int *param_1,int param_2,int param_3,int param_4,undefined1 param_5)

{
  void *pvVar1;
  
  if (param_2 != 0) {
    if ((void *)param_1[0x6b] != (void *)0x0) {
      _free((void *)param_1[0x6b]);
    }
    param_1[0x6b] = 0;
    param_1[0x3b3] = param_4;
    param_1[0x71] = param_4;
    param_1[1] = param_2;
    param_1[0x69] = param_3;
    *(undefined1 *)(param_1 + 0x72) = param_5;
    pvVar1 = _malloc(param_4 * 0x28 + 0x14);
    param_1[0x6b] = (int)pvVar1;
    if (pvVar1 != (void *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0000c563. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_1 + 0xbc))();
      return;
    }
  }
  return;
}

