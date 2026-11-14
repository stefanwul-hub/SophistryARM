/* 00056fc6 FUN_00056fc6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00056fc6(int param_1,int param_2)

{
  char *local_24;
  undefined4 local_20;
  
  FUN_00025b40(param_1,0x279);
  FUN_00028e00(param_1,param_2,0x2fd,0x54,0x4e,0xff202020);
  FUN_00025b40(param_1,0x291);
  FUN_00056e50(param_1,param_2,0x27a,0x117,0x19,1);
  FUN_00056e50(param_1,param_2,0x27d,0x117,0x34,1);
  FUN_00056e50(param_1,param_2,0x27e,0x117,0x4f,1);
  FUN_00055a08(param_1,param_2,699,0x145,0x76,0x78,0xe);
  local_24 = "*.TUN";
  local_20 = 0;
  FUN_000267f6(param_1,param_2,700,"Load Microtuning Definition","TUN format",&local_24,
               "NoteFreqTables",0,0x1b8,0x75,0x26,0x10);
  *(code **)(param_2 + 0x60) = FUN_00059942;
  FUN_00026b74(param_1,param_2,0x292,0x1ce,0x65,*(undefined4 *)(param_1 + 0x27934),0);
  FUN_00055b42(param_1,1,param_2,0x261,0x19f,0x39,0,*(undefined4 *)(param_1 + 0x34));
  return;
}

