/* 00054d76 FUN_00054d76 */

void FUN_00054d76(int param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  if (*(int *)(param_1 + 0x278ac) != 0) {
    local_1c = 0x3a;
    local_18 = 0x22;
    local_14 = 0x2c2;
    local_10 = 0x81;
    pvVar1 = operator_new(0x4e4);
    FUN_00093004(pvVar1,&local_1c,param_1 + 0x20,0x260,*(undefined4 *)(param_1 + 0x278b0),
                 *(undefined4 *)(param_1 + 0x278b4),*(undefined4 *)(param_1 + 0x4c),0x12,0x5f,10,
                 0x3c,0xd);
    FUN_000266ca(param_1,pvVar1,0x260,param_2);
    *(void **)(param_1 + 0x25dc4) = pvVar1;
    FUN_00026b74(param_1,param_2,0x265,0x52,0xd,*(undefined4 *)(param_1 + 0x27848),0);
    FUN_0002666e(param_1,param_2,*(undefined4 *)(param_1 + 0x34),0x264,0x62,0xd,0x1f,0x13,1,0);
    FUN_00026b74(param_1,param_2,0x263,0x8f,0xd,*(undefined4 *)(param_1 + 0x27844),0);
    FUN_0002666e(param_1,param_2,*(undefined4 *)(param_1 + 0x34),0x262,0x9f,0xd,0x1f,0x10,0,0);
  }
  return;
}

