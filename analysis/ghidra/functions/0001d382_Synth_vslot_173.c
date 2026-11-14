/* 0001d382 Synth_vslot_173 */

longdouble Synth_vslot_173(int param_1,int param_2)

{
  int iVar1;
  longdouble lVar2;
  int local_28;
  int *local_24;
  undefined4 local_20 [4];
  
  if ((*(char *)(param_1 + 0xcfc4) != '\0') && (param_2 < *(int *)(param_1 + 0x9a48))) {
    iVar1 = param_1 + 0x3b30;
    _OSAtomicAdd32Barrier(1,iVar1);
    local_28 = -1;
    FUN_0001cb52(param_1,param_2,&local_24,&local_28,local_20);
    if ((local_28 != -1) && (local_24 != (int *)0x0)) {
      lVar2 = (longdouble)(**(code **)(*local_24 + 0x20))(local_24,local_20[0],local_28);
      _OSAtomicAdd32Barrier(0xffffffff,iVar1);
      return (longdouble)(float)lVar2;
    }
    _OSAtomicAdd32Barrier(0xffffffff,iVar1);
  }
  return (longdouble)0;
}

