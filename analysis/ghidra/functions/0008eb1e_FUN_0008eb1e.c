/* 0008eb1e FUN_0008eb1e */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0008eb1e(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  longdouble lVar5;
  int local_20;
  
  FUN_00031fec(param_1);
  *param_1 = &PTR_WaveTable_c_vslot_0_000f3028;
  FUN_000aeb88(param_1 + 0x76);
  FUN_0000a5d4(param_1 + 0x115);
  uVar2 = FUN_00013124(param_1,0x2000);
  param_1[0x75] = uVar2;
  param_1[0x48] = 0;
  local_20 = 0;
  do {
    iVar3 = 0;
    iVar4 = local_20;
    do {
      iVar1 = param_1[0x75];
      lVar5 = (longdouble)_sin((double)iVar3 * 0.04908738521234052);
      *(float *)(iVar1 + iVar4) = (float)lVar5;
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 4;
    } while (iVar3 != 0x80);
    FUN_00032430(param_1,local_20 + param_1[0x75],0x80);
    local_20 = local_20 + 0x200;
  } while (local_20 != 0x8000);
  param_1[0x113] = 0x3f800000;
  *(undefined1 *)(param_1 + 0x114) = 1;
  return;
}

