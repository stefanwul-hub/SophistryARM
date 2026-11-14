/* 0003ad36 FUN_0003ad36 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble FUN_0003ad36(int param_1,undefined4 param_2,char *param_3)

{
  int iVar1;
  longdouble lVar2;
  int local_2c4;
  float local_2c0;
  undefined1 local_2b0 [672];
  
  if (((*(int *)(param_1 + 0x120) == 0) || (param_3 == (char *)0x0)) || (*param_3 == '\0')) {
    return (longdouble)1.0;
  }
  FUN_0000a5d4(local_2b0);
  iVar1 = *(int *)(param_1 + 0x120);
  if (iVar1 == 0) {
LAB_0003ae11:
    local_2c4 = 0;
  }
  else {
    iVar1 = FUN_00011b72(iVar1,0);
    if ((iVar1 == 0) || (*(int *)(param_1 + 0x400) == 0)) {
      iVar1 = *(int *)(param_1 + 0x120);
      goto LAB_0003ae11;
    }
    local_2c4 = (int)((float)(*(int *)(param_1 + 0x410) + -1) * *(float *)(iVar1 + 0x77c) * 0.01 +
                     0.25);
    iVar1 = *(int *)(param_1 + 0x120);
  }
  if (iVar1 != 0) {
    iVar1 = FUN_00011b72(iVar1,0);
    if ((iVar1 != 0) && (*(int *)(param_1 + 0x400) != 0)) {
      iVar1 = (int)((float)(*(int *)(param_1 + 0x410) + -1) * *(float *)(iVar1 + 0x7ec) * 0.01 +
                   0.25);
      goto LAB_0003ae74;
    }
  }
  iVar1 = 0;
LAB_0003ae74:
  lVar2 = (longdouble)
          FUN_000152c0((float)((iVar1 - local_2c4) + 1),(float)*(int *)(param_1 + 0x410));
  local_2c0 = (float)lVar2;
  FUN_00032306(param_1,*(undefined4 *)(param_1 + 0x400),*(undefined4 *)(param_1 + 0x410));
  if (*(char *)(param_1 + 0x3f8) != '\0') {
    FUN_00032306(param_1,*(undefined4 *)(param_1 + 0x404),*(undefined4 *)(param_1 + 0x410));
  }
  FUN_000af344(param_1 + 0x1e4,local_2c4,iVar1);
  iVar1 = FUN_000b12a0(param_1 + 0x1e4,param_3);
  if (iVar1 < 1) {
    FUN_0002e53a(param_1 + 0x168,"File Error - Save failed",param_3);
    local_2c0 = -1.0;
  }
  else {
    FUN_00012432(*(undefined4 *)(param_1 + 0x120),param_2,3,param_3);
    FUN_0001218c(*(undefined4 *)(param_1 + 0x120),param_2,0xb,0);
    FUN_0001218c(*(undefined4 *)(param_1 + 0x120),param_2,0x11,0);
    FUN_0001218c(*(undefined4 *)(param_1 + 0x120),param_2,0x12,0x3f800000);
    FUN_00039ed0(param_1,param_2,param_3);
  }
  Disk_c_vslot_0(local_2b0);
  return (longdouble)local_2c0;
}

