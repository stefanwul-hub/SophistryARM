/* 00058ece FUN_00058ece */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00058ece(int param_1,int *param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  undefined4 local_b0;
  undefined4 local_ac;
  int local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  char *local_5c;
  char *local_58;
  char *local_54;
  char *local_50;
  char *local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  
  uVar1 = (**(code **)(*param_2 + 0x24))(param_2);
  if ((param_3 & 1) == 0) {
    uVar2 = 0x2a;
    uVar4 = 0x45;
    uVar6 = 0x60;
    local_a0 = 0x7b;
  }
  else {
    uVar2 = 0xe;
    uVar4 = 0x29;
    uVar6 = 0x44;
    local_a0 = 0x5f;
  }
  FUN_00056e50(param_1,param_2,param_3 + 0x338,5,uVar2,0);
  FUN_00056e50(param_1,param_2,param_3 + 0x33a,5,uVar4,0);
  FUN_00056e50(param_1,param_2,param_3 + 0x33c,5,uVar6,0);
  FUN_00056e50(param_1,param_2,param_3 + 0x342,5,local_a0,0);
  iVar5 = (-(uint)((param_3 & 1) == 0) & 0xffffff97) + 0x73;
  FUN_00026b74(param_1,param_2,param_3 + 0x344,0xba,iVar5,*(undefined4 *)(param_1 + 0x27870),0);
  FUN_00026b74(param_1,param_2,param_3 + 0x33e,0x86,iVar5,*(undefined4 *)(param_1 + 0x2793c),0);
  FUN_00058a98(param_1,param_2,param_3);
  if ((param_3 & 1) == 0) {
    local_a4 = 8;
    uVar2 = 0xb;
    local_9c = 9;
    local_98 = 0x83;
    local_94 = 0x74;
    local_90 = 0x18;
  }
  else {
    local_a4 = 0;
    uVar2 = 3;
    local_9c = 1;
    local_98 = 0x7b;
    local_94 = 0x6c;
    local_90 = 0x10;
  }
  FUN_00055a08(param_1,param_2,param_3 + 800,0x156,uVar2,0x62,10);
  local_5c = "*.WAV";
  local_58 = "*.AIF";
  local_54 = "*.AIFF";
  local_50 = "*.D4T";
  local_4c = "*.D4U";
  local_48 = 0;
  FUN_000267f6(param_1,param_2,param_3 + 0x324,"Load Sample","WAV, AIF, D4T or D4U format",&local_5c
               ,"KajaSamples",0,0x13a,uVar2,0xe,0xb);
  iVar5 = param_3 + 10;
  FUN_00026a98(param_1,param_2,param_3 + 0x322,3,iVar5,0,300,uVar2,0xe,0xb,0);
  FUN_00026a98(param_1,param_2,param_3 + 0x326,2,iVar5,0,0x148,uVar2,0xe,0xb,0);
  FUN_00026a98(param_1,param_2,param_3 + 0x328,4,iVar5,0,0x1b9,uVar2,0xe,0xb,0);
  FUN_00026b74(param_1,param_2,param_3 + 0x334,0x1c9,local_9c,*(undefined4 *)(param_1 + 0x27864),0);
  FUN_00026b74(param_1,param_2,param_3 + 0x332,0x1ee,local_9c,*(undefined4 *)(param_1 + 0x27860),0);
  FUN_000268f0(param_1,param_2,param_3 + 0x336,0x24a,uVar2,0x14,10,*(undefined4 *)(param_1 + 0x34));
  FUN_000268f0(param_1,param_2,param_3 + 0x3b6,0x14d,local_98,0x28,0xc,
               *(undefined4 *)(param_1 + 0x34));
  FUN_000268f0(param_1,param_2,param_3 + 0x3b8,0x19b,local_98,0x28,0xc,
               *(undefined4 *)(param_1 + 0x34));
  FUN_000268f0(param_1,param_2,param_3 + 0x3ba,0x1ec,local_98,0x28,0xc,
               *(undefined4 *)(param_1 + 0x34));
  FUN_000268f0(param_1,param_2,param_3 + 0x3bc,0x23f,local_98,0x28,0xc,
               *(undefined4 *)(param_1 + 0x34));
  if ((int)param_3 < 0) {
    param_3 = 0;
    local_8c = 0x32c;
    local_88 = 0x32e;
    local_84 = 0x330;
    local_80 = 0x340;
    local_64 = 0x3b2;
    local_60 = 0x3b4;
  }
  else if ((int)param_3 < 2) {
    local_8c = param_3 + 0x32c;
    local_88 = param_3 + 0x32e;
    local_84 = param_3 + 0x330;
    local_80 = param_3 + 0x340;
    local_64 = param_3 + 0x3b2;
    local_60 = param_3 + 0x3b4;
  }
  else {
    param_3 = 1;
    local_8c = 0x32d;
    local_88 = 0x32f;
    local_84 = 0x331;
    local_80 = 0x341;
    local_64 = 0x3b3;
    local_60 = 0x3b5;
  }
  piVar7 = &local_74;
  for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar7 = 0;
    piVar7 = piVar7 + 1;
  }
  local_74 = local_8c;
  local_70 = local_88;
  local_6c = local_84;
  local_68 = local_80;
  local_34 = 0x12f;
  local_30 = local_90;
  local_2c = 0x26b;
  local_28 = local_94;
  pvVar3 = operator_new(0xf0);
  FUN_000813ba(pvVar3,&local_34,param_1 + 0x20,local_74,uVar1);
  if (pvVar3 != (void *)0x0) {
    FUN_000817c0(pvVar3,*(int *)(param_1 + 0x4c) + 0x32b070 + param_3 * 4,1,
                 CONCAT31((uint3)(CONCAT22((ushort)((uint)local_ac >> 0x10) & 0xff00,0xf000) >> 8) |
                          0xfff500,0xf0),
                 CONCAT31((uint3)(CONCAT22((ushort)((uint)local_b0 >> 0x10) & 0xff00,0x6400) >> 8) |
                          0xff6400,100),0xff7df578);
    FUN_00025a06(param_1,pvVar3,&local_74,6,param_2);
    FUN_00056e50(param_1,param_2,param_3 + 0x3ac,0x236,local_94,0);
    local_20 = param_3 + 0x3b0;
    local_44 = 0x12d;
    local_40 = local_a4 + 0x70;
    local_3c = 0x22b;
    local_38 = local_a4 + 0x77;
    local_24 = param_3 + 0x3ae;
    pvVar3 = operator_new(0xdc);
    FUN_00080bec(pvVar3,&local_44,param_1 + 0x20,param_3 + 0x3ae,uVar1,0xc);
    FUN_00025a06(param_1,pvVar3,&local_24,2,param_2);
  }
  return;
}

