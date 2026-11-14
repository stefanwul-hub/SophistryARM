/* 00019910 Synth_vslot_180 */

undefined4 Synth_vslot_180(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (param_2 < *(int *)(param_1 + 0x9a4c)) {
    if (param_3 != (undefined4 *)0x0) {
      FUN_00019748(param_1,param_2,param_2);
      uVar1 = FUN_0002e032(*(undefined4 *)(*(int *)(param_1 + 0xcea0) + param_2 * 4));
      *param_3 = uVar1;
      uVar1 = FUN_0002e026();
      return uVar1;
    }
    uVar1 = 0xfffffffe;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

