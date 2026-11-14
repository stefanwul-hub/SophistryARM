/* 00054214 FUN_00054214 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00054214(int param_1,undefined4 param_2)

{
  char *local_24;
  undefined4 local_20;
  
  FUN_00025b40(param_1,0x26a);
  FUN_00029272(param_1,param_2,0x27b,0,*(undefined4 *)(param_1 + 0x278a0),0x1b,0xbf,1,0,"- - -");
  FUN_00029272(param_1,param_2,0x27c,0,*(undefined4 *)(param_1 + 0x278a0),0x1b,0xcf,0,0,"- - -");
  FUN_00026a98(param_1,param_2,0x26d,0x10,0xffffffff,0,0x15,0xe4,0x26,0xf,0);
  local_24 = "*.fxp";
  local_20 = 0;
  FUN_000267f6(param_1,param_2,0x26c,"Import Sound Program","Standard FXP format",&local_24,
               "CronoXPresets",0,0x3b,0xe4,0x26,0xf);
  FUN_00026a98(param_1,param_2,0x26e,0xf,0xffffffff,0,0x61,0xe4,0x26,0xf,0);
  FUN_000267f6(param_1,param_2,0x26b,"Export Sound Program","Standard FXP format",&local_24,
               "CronoXPresets",1,0x87,0xe4,0x26,0xf);
  return;
}

