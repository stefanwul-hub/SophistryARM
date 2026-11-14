/* 00083418 AUCronoX_vslot_81 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void AUCronoX_vslot_81(int param_1,undefined4 param_2,float param_3)

{
  longdouble lVar1;
  undefined4 uVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  undefined1 auVar5 [12];
  int local_38;
  int local_34;
  int local_30;
  int local_24;
  float local_20;
  
  FUN_0001ce0e(param_1 + 0xec,param_2,&local_38);
  if (local_38 == 5) {
    param_3 = param_3 * 5.0;
    uVar2 = 0;
  }
  else if (((local_38 == 6) || (local_38 == 2)) || (local_24 < 1)) {
    uVar2 = 0;
  }
  else {
    lVar1 = (longdouble)_pow(0,0x40240000,(double)local_24);
    uVar2 = (undefined4)((ulonglong)((double)lVar1 + 0.5) >> 0x20);
    param_3 = (float)(int)((double)lVar1 + 0.5) * param_3;
  }
  auVar3 = (undefined1  [16])0x0;
  if (local_34 < local_30) {
    auVar3._0_4_ = (param_3 - (float)local_34) / ((float)local_30 - (float)local_34);
    auVar3._4_4_ = uVar2;
    auVar3._8_8_ = 0;
  }
  if ((0.01 < local_20) || ((local_20 < -0.01 && (!NAN(local_20))))) {
    auVar4._8_8_ = auVar3._8_8_;
    auVar4._0_8_ = (double)auVar3._0_4_;
    auVar5 = auVar4._4_12_;
    lVar1 = (longdouble)_exp((double)local_20);
    lVar1 = (longdouble)_log(((double)lVar1 * auVar4._0_8_ - auVar4._0_8_) + 1.0);
    auVar3._0_4_ = (float)lVar1 / local_20;
    auVar3._4_12_ = auVar5;
  }
  Synth_vslot_11(param_1 + 0xec,param_2,auVar3._0_4_);
  return;
}

