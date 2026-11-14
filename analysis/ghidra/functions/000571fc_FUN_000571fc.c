/* 000571fc FUN_000571fc */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000571fc(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  char *pcVar2;
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
  char *local_38;
  char *local_34;
  char *local_30;
  char *local_2c;
  undefined4 local_28;
  char *local_24;
  undefined4 local_20;
  
  if ((param_3 & 1) == 0) {
    uVar1 = 0x4d;
    local_68 = 0x31;
    local_64 = 0x6d;
    local_60 = 0x56;
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
    local_68 = 0x2a;
    local_64 = 0x66;
    local_60 = 0x4f;
    local_5c = 0x17;
    local_58 = 0x32;
    local_54 = 0x4d;
    local_50 = 0x68;
    local_4c = 0x39;
    local_48 = 0x3b;
    local_44 = 0x50;
    local_40 = 0x61;
  }
  FUN_00055b42(param_1,4,param_2,param_3 + 0x60,0x1b6,uVar1,0xe,*(undefined4 *)(param_1 + 0x34));
  FUN_00055b42(param_1,1,param_2,param_3 + 0x68,0x155,local_68,0xffffffe7,
               *(undefined4 *)(param_1 + 0x34));
  FUN_00055b42(param_1,1,param_2,param_3 + 100,0x155,local_64,0xffffffe7,
               *(undefined4 *)(param_1 + 0x34));
  FUN_00026b74(param_1,param_2,param_3 + 0x5c,0x108,local_60,*(undefined4 *)(param_1 + 0x27940),0);
  FUN_00056e50(param_1,param_2,param_3 + 0x50,0x204,local_5c,0);
  FUN_00056e50(param_1,param_2,param_3 + 0x54,0x204,local_58,0);
  FUN_00056e50(param_1,param_2,param_3 + 0x58,0x204,local_54,0);
  FUN_00056e50(param_1,param_2,param_3 + 0x2dd,0x204,local_50,0);
  FUN_00026a98(param_1,param_2,param_3 + 0x2e5,0x2a,0xffffffff,param_3,0x39,local_4c,0xf,0x13,0);
  pcVar2 = "*.WAV";
  local_34 = "*.AIF";
  local_30 = "*.AIFF";
  local_2c = "*.D4T";
  local_28 = 0;
  local_38 = pcVar2;
  FUN_000267f6(param_1,param_2,param_3 + 0x2e9,"Load Sample","WAV, AIF or D4T format",&local_38,
               "KajaTables",0,0x48,local_4c,0xf,0x13,"*.WAV");
  FUN_00026a98(param_1,param_2,param_3 + 0x2ed,0x29,0xffffffff,param_3,0x57,local_4c,0xf,0x13,0);
  FUN_00026a98(param_1,param_2,param_3 + 0x2f1,0x2b,0xffffffff,param_3,0x122,local_4c,0xf,0x13,0);
  FUN_00055a08(param_1,param_2,param_3 + 0x2e1,0x66,local_48,200,0xf);
  FUN_000268f0(param_1,param_2,param_3 + 0x2f5,0x84,local_44,0x2d,0xc,
               *(undefined4 *)(param_1 + 0x34));
  FUN_000268f0(param_1,param_2,param_3 + 0x2f9,0xc1,local_44,0x2d,0xc,
               *(undefined4 *)(param_1 + 0x34));
  local_20 = 0;
  local_24 = pcVar2;
  FUN_000267f6(param_1,param_2,param_3 + 0x273,"Trim Sample","Standard Sample format",&local_24,
               "CronoXExportSamples",1,0xba,local_40,10,10);
  return;
}

