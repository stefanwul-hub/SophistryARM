/* 00055df2 FUN_00055df2 */

void FUN_00055df2(int param_1,undefined4 param_2)

{
  int iVar1;
  int aiStackY_af8 [671];
  int local_44;
  int local_40;
  
  FUN_00026b74(param_1,param_2,0x269,0x1e8,0x106,*(undefined4 *)(param_1 + 0x27838),0);
  FUN_00026b74(param_1,param_2,0x267,0x213,0x106,*(undefined4 *)(param_1 + 0x27834),0);
  FUN_00055b42(param_1,0,param_2,0x3bf,0x1a2,0xa5,0,*(undefined4 *)(param_1 + 0x34));
  FUN_00055b42(param_1,0,param_2,0x3c0,0x1a2,0xcf,0,*(undefined4 *)(param_1 + 0x34));
  FUN_00055b42(param_1,0,param_2,0x3c1,0x1a2,0xf9,0,*(undefined4 *)(param_1 + 0x34));
  local_44 = 0x2b1;
  local_40 = 0x96;
  do {
    iVar1 = aiStackY_af8[local_44];
    FUN_00026b74(param_1,param_2,local_44,iVar1 + 0x1c3,local_40,*(undefined4 *)(param_1 + 0x27934),
                 0);
    FUN_00026e1c(param_1,param_2,*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x2789c),
                 local_44 + -0x1e,iVar1 + 0x1d4,local_40,1,1);
    FUN_00025988(param_1,param_2,local_44 + -10,0x247,local_40 + -1,0x28,0xb);
    FUN_00026e1c(param_1,param_2,*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x2789c),
                 local_44 + -0x14,0x279 - iVar1,local_40,1,1);
    local_44 = local_44 + 1;
    local_40 = local_40 + 0xb;
  } while (local_44 != 699);
  return;
}

