/* 0009dd0a FUN_0009dd0a */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

bool FUN_0009dd0a(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_b8 [152];
  undefined4 local_20 [4];
  
  uVar1 = _CFStringCreateWithFormat(0,0,&cf_net_sourceforge_vstgui__d,param_1);
  *(undefined4 *)(param_1 + 0x74) = 1;
  *(undefined4 *)(param_1 + 0x78) = 0;
  _memcpy(local_b8,&DAT_000e1ec0,0x98);
  local_20[0] = 0;
  iVar2 = _RegisterToolboxObjectClass(uVar1,0,0x13,local_b8,FUN_000a4ba0,param_1,local_20);
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 + 0x78) = local_20[0];
  }
  _CFRelease(uVar1);
  return *(int *)(param_1 + 0x78) != 0;
}

