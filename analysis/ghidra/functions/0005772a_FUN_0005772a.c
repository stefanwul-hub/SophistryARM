/* 0005772a FUN_0005772a */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0005772a(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  char *local_3c;
  char *local_38;
  char *local_34;
  char *local_30;
  char *local_2c;
  undefined4 local_28;
  char *local_24;
  undefined4 local_20;
  
  if ((param_3 & 1) == 0) {
    uVar1 = 0x4d;
    local_68 = 0x56;
    local_64 = 0x31;
    local_60 = 0x6d;
    local_5c = 0x1e;
    local_58 = 0x39;
    local_54 = 0x54;
    local_50 = 0x6f;
    local_4c = 0x40;
    local_48 = 0x42;
    local_44 = 0x57;
    local_40 = 0x68;
  }
  else {
    uVar1 = 0x46;
    local_68 = 0x4f;
    local_64 = 0x2a;
    local_60 = 0x66;
    local_5c = 0x17;
    local_58 = 0x32;
    local_54 = 0x4d;
    local_50 = 0x68;
    local_4c = 0x39;
    local_48 = 0x3b;
    local_44 = 0x50;
    local_40 = 0x61;
  }
  FUN_00055b42(param_1,4,param_2,param_3 + 0x2c,0x1b6,uVar1,0xf,*(undefined4 *)(param_1 + 0x34));
  FUN_00026b74(param_1,param_2,param_3 + 0x30,0xe0,local_68,*(undefined4 *)(param_1 + 0x27810),0);
  FUN_00026b74(param_1,param_2,param_3 + 0x34,0xf4,local_68,*(undefined4 *)(param_1 + 0x27868),0);
  FUN_00026b74(param_1,param_2,param_3 + 0x44,0x108,local_68,*(undefined4 *)(param_1 + 0x27940),0);
  FUN_00055b42(param_1,1,param_2,param_3 + 0x4c,0x155,local_64,0xffffffe7,
               *(undefined4 *)(param_1 + 0x34));
  FUN_00055b42(param_1,1,param_2,param_3 + 0x48,0x155,local_60,0xffffffe7,
               *(undefined4 *)(param_1 + 0x34));
  FUN_00056e50(param_1,param_2,param_3 + 0x38,0x204,local_5c,0);
  FUN_00056e50(param_1,param_2,param_3 + 0x3c,0x204,local_58,0);
  FUN_00056e50(param_1,param_2,param_3 + 0x40,0x204,local_54,0);
  FUN_00056e50(param_1,param_2,param_3 + 0x2c1,0x204,local_50,0);
  FUN_00026a98(param_1,param_2,param_3 + 0x2c5,3,param_3,0,0x39,local_4c,0xf,0x13,0);
  local_3c = "*.WAV";
  local_38 = "*.AIF";
  local_34 = "*.AIFF";
  local_30 = "*.D4T";
  local_2c = "*.D4U";
  local_28 = 0;
  FUN_000267f6(param_1,param_2,param_3 + 0x2c9,"Load Sample","WAV, AIF, D4T or D4U format",&local_3c
               ,"KajaSamples",0,0x48,local_4c,0xf,0x13);
  FUN_00026a98(param_1,param_2,param_3 + 0x2cd,2,param_3,0,0x57,local_4c,0xf,0x13,0);
  FUN_00055a08(param_1,param_2,param_3 + 0x2bd,0x66,local_48,0xbc,0xf);
  FUN_00026a98(param_1,param_2,param_3 + 0x2d1,4,param_3,0,0x122,local_4c,0xf,0x13,0);
  FUN_000268f0(param_1,param_2,param_3 + 0x2d5,0x68,local_44,0x37,0xc,
               *(undefined4 *)(param_1 + 0x34));
  FUN_000268f0(param_1,param_2,param_3 + 0x2d9,0xa5,local_44,0x37,0xc,
               *(undefined4 *)(param_1 + 0x34));
  local_24 = "*.aif";
  local_20 = 0;
  FUN_000267f6(param_1,param_2,param_3 + 0x26f,"Trim Sample","Standard Sample format",&local_24,
               "CronoXExportSamples",1,0x9e,local_40,10,10);
  return;
}

