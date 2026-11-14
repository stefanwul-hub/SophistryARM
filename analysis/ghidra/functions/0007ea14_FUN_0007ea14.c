/* 0007ea14 FUN_0007ea14 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0007ea14(undefined4 *param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5
                 ,int param_6)

{
  int iVar1;
  int iVar2;
  longdouble lVar3;
  
  FUN_000023ba(param_1,param_2,param_3,param_4,param_6 * 3);
  *param_1 = &PTR_C51Map_vslot_0_000f1888;
  if (param_5 != 0) {
    param_1[0x2c] = param_5;
    param_1[0x2d] = param_6;
    iVar1 = *(int *)(param_5 + 0xc);
    param_1[0x2e] = iVar1;
    iVar2 = *(int *)(param_5 + 0x10) / (int)param_1[0x2d];
    param_1[0x2f] = iVar2;
    param_1[0x30] = (param_2[2] - *param_2) - iVar1;
    param_1[0x31] = (param_2[3] - param_2[1]) - iVar2;
    lVar3 = (longdouble)FUN_000152c0(0x3f800000,(float)(int)param_1[0x30]);
    param_1[0x32] = (float)lVar3;
    lVar3 = (longdouble)FUN_000152c0(0x3f800000,(float)(int)param_1[0x31]);
    param_1[0x33] = (float)lVar3;
    CControlPl_vslot_77(param_1,0x12);
  }
  return;
}

