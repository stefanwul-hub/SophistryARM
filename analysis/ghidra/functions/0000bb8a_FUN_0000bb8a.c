/* 0000bb8a FUN_0000bb8a */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0000bb8a(undefined4 *param_1)

{
  int iVar1;
  longdouble lVar2;
  
  *param_1 = &PTR_GenDemoNoise_c_vslot_0_000e6688;
  FUN_0002e178(param_1 + 0x208);
  iVar1 = 0x200;
  do {
    lVar2 = (longdouble)FUN_0002e314();
    param_1[8] = ((float)lVar2 - 0.5) * 0.1;
    param_1 = param_1 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

