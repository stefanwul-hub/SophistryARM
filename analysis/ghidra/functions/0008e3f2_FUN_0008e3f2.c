/* 0008e3f2 FUN_0008e3f2 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble FUN_0008e3f2(int param_1,int param_2,char *param_3,char param_4)

{
  int iVar1;
  int iVar2;
  longdouble lVar3;
  float fVar4;
  int local_2c8;
  int local_2c4;
  float local_2c0;
  undefined1 local_2b0 [672];
  
  if ((((*(int *)(param_1 + 0x120) == 0) || (param_3 == (char *)0x0)) || (*param_3 == '\0')) ||
     ((param_2 < 0 || (0 < param_2)))) {
    local_2c0 = 1.0;
  }
  else {
    FUN_0000a5d4(local_2b0);
    iVar2 = param_1 + param_2 * 0x274 + 0x1d8;
    if ((*(int *)(param_1 + 0x120) != 0) &&
       (iVar1 = FUN_00011b72(*(int *)(param_1 + 0x120),param_2), iVar1 != 0)) {
      if (*(int *)(iVar2 + 0x21c) == 0) {
        local_2c8 = 0;
        local_2c4 = 0;
      }
      else {
        fVar4 = (float)(*(int *)(iVar2 + 0x22c) + -1);
        local_2c8 = (int)(fVar4 * *(float *)(iVar1 + 0x15c) * 0.01 + 0.25);
        local_2c4 = (int)(fVar4 * *(float *)(iVar1 + 0x1cc) * 0.01 + 0.25);
      }
    }
    lVar3 = (longdouble)
            FUN_000152c0((float)((local_2c4 - local_2c8) + 1),(float)*(int *)(iVar2 + 0x22c));
    local_2c0 = (float)lVar3;
    FUN_000af344(iVar2,local_2c8,local_2c4);
    if (param_4 == '\0') {
      iVar2 = FUN_000b12a0(iVar2,param_3);
    }
    else {
      iVar2 = FUN_000afa8c(iVar2,param_3);
    }
    if (iVar2 < 1) {
      FUN_0002e53a(param_1 + 0x168,"File Error - Save failed",param_3);
      local_2c0 = -1.0;
    }
    else {
      FUN_00012432(*(undefined4 *)(param_1 + 0x120),param_2,1,param_3);
      FUN_0001218c(*(undefined4 *)(param_1 + 0x120),param_2,3,0);
      FUN_0001218c(*(undefined4 *)(param_1 + 0x120),param_2,4,0x3f800000);
      FUN_0008e28c(param_1,param_2,param_3);
    }
    Disk_c_vslot_0(local_2b0);
  }
  return (longdouble)local_2c0;
}

