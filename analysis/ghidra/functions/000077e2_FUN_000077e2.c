/* 000077e2 FUN_000077e2 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000077e2(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  undefined *puVar1;
  
  FUN_000021e2(param_1,param_2,param_3,param_4);
  *param_1 = &PTR_CModDepthDisp_vslot_0_000e5ba8;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = param_5;
  param_1[0x3c] = param_12;
  param_1[0x3b] = param_11;
  param_1[0x3a] = param_10;
  param_1[0x39] = param_9;
  param_1[0x38] = param_8;
  param_1[0x37] = param_7;
  param_1[0x36] = param_6;
  param_1[0x31] = *param_2;
  param_1[0x32] = param_2[1];
  param_1[0x3d] = 0;
  *(undefined1 *)((int)param_1 + 0x6d) = 0;
  *(undefined1 *)(param_1 + 0x1b) = 0;
  puVar1 = PTR_DAT_00103804;
  *(undefined *)(param_1 + 0x34) = *PTR_DAT_00103804;
  *(undefined *)((int)param_1 + 0xd1) = puVar1[1];
  *(undefined *)((int)param_1 + 0xd2) = puVar1[2];
  *(undefined *)((int)param_1 + 0xd3) = puVar1[3];
  puVar1 = PTR_DAT_00103800;
  *(undefined *)(param_1 + 0x22) = *PTR_DAT_00103800;
  *(undefined *)((int)param_1 + 0x89) = puVar1[1];
  *(undefined *)((int)param_1 + 0x8a) = puVar1[2];
  *(undefined *)((int)param_1 + 0x8b) = puVar1[3];
  CControlPl_vslot_77(param_1,0xd);
  param_1[0x3e] = 0xbf800000;
  CControlPl_vslot_70(param_1,1);
  return;
}

