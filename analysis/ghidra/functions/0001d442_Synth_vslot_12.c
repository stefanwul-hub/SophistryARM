/* 0001d442 Synth_vslot_12 */

longdouble Synth_vslot_12(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  longdouble lVar3;
  int local_28;
  int *local_24;
  undefined4 local_20 [4];
  
  if (((*(char *)(param_1 + 0xcfc4) != '\0') && (LPAUSynth_vslot_9[param_1] == (code)0x0)) &&
     (param_2 < *(int *)(param_1 + 0x9a48))) {
    iVar1 = param_1 + 0x3b30;
    _OSAtomicAdd32Barrier(1,iVar1);
    local_28 = -1;
    FUN_0001cb52(param_1,param_2,&local_24,&local_28,local_20);
    if ((local_28 != -1) && (local_24 != (int *)0x0)) {
      uVar2 = 0;
      if (*(int *)(param_2 * 0x20 + 0xc + *(int *)(param_1 + 0x8abc)) != -1) {
        uVar2 = local_20[0];
      }
      local_20[0] = uVar2;
      lVar3 = (longdouble)(**(code **)(*local_24 + 0x20))(local_24,uVar2,local_28);
      _OSAtomicAdd32Barrier(0xffffffff,iVar1);
      return (longdouble)(float)lVar3;
    }
    _OSAtomicAdd32Barrier(0xffffffff,iVar1);
  }
  return (longdouble)0;
}

