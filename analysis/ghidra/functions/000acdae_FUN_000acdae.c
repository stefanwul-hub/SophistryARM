/* 000acdae FUN_000acdae */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000acdae(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  *param_1 = PTR_DAT_001038d0 + 8;
  param_1[1] = param_2;
  FUN_000ad448(param_1 + 2);
  *param_1 = &PTR_AUCarbonViewBase_vslot_0_000f4688;
  param_1[2] = &PTR_LAB_000f46b4;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  uVar1 = *(undefined4 *)PTR_001038cc;
  uVar2 = _CFRunLoopGetCurrent();
  _AUListenerCreate(FUN_000ac698,param_1,uVar2,uVar1,param_3,param_1 + 5);
  return;
}

