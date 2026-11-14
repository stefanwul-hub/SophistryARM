/* 000adcce MusicDeviceBase_vslot_9 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int MusicDeviceBase_vslot_9(int *param_1,int param_2,int param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  
  if (param_2 == 5) {
    if (param_4 != 0x101) {
      return -0x2a7d;
    }
    *param_5 = FUN_000ae0da;
    return 0;
  }
  if (param_2 != 1000) {
    iVar1 = AUBase_vslot_9(param_1,param_2,param_3,param_4,param_5);
    if (iVar1 != -0x2a7f) {
      return iVar1;
    }
    iVar1 = AUMIDIBase_vslot_3();
    return iVar1;
  }
  if (param_3 != 0) {
    return -0x2a72;
  }
                    /* WARNING: Could not recover jumptable at 0x000addb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)(*param_1 + 0xf4))();
  return iVar1;
}

