/* 000128a6 Part_c_vslot_40 */

void Part_c_vslot_40(int *param_1,int param_2)

{
  longdouble lVar1;
  float fVar2;
  
  param_1[0x50] = param_2;
  lVar1 = (longdouble)FUN_000152c0(0x3f800000,param_2);
  param_1[0x51] = (int)(float)lVar1;
  lVar1 = (longdouble)FUN_000152c0(0x40000000,param_1[0x50]);
  param_1[0x52] = (int)(float)lVar1;
  lVar1 = (longdouble)FUN_000152c0(0x472c4400,param_1[0x50]);
  fVar2 = 1.0;
  if ((float)lVar1 <= 1.0) {
    fVar2 = (float)lVar1;
  }
  param_1[0x53] = (int)fVar2;
                    /* WARNING: Could not recover jumptable at 0x0001292e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xd8))();
  return;
}

