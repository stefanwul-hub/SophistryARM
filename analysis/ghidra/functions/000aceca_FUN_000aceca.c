/* 000aceca FUN_000aceca */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000aceca(undefined4 *param_1)

{
  int *piVar1;
  void *pvVar2;
  void *pvVar3;
  int *piVar4;
  
  *param_1 = &PTR_AUCarbonViewBase_vslot_0_000f4688;
  param_1[2] = &PTR_LAB_000f46b4;
  if (param_1[0xe] != 0) {
    _DisposeControl(param_1[0xe]);
  }
  piVar4 = (int *)param_1[8];
  if (piVar4 != (int *)param_1[9]) {
    do {
      piVar1 = (int *)*piVar4;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))(piVar1);
      }
      piVar4 = piVar4 + 1;
    } while (piVar4 != (int *)param_1[9]);
  }
  _AUListenerDispose(param_1[5]);
  if (param_1[0xb] != 0) {
    _RemoveEventLoopTimer(param_1[0xb]);
  }
  if (param_1[0xc] != 0) {
    _DisposeEventLoopTimerUPP(param_1[0xc]);
  }
  pvVar2 = (void *)param_1[8];
  for (pvVar3 = pvVar2; (void *)param_1[9] != pvVar3; pvVar3 = (void *)((int)pvVar3 + 4)) {
  }
  if (pvVar2 != (void *)0x0) {
    operator_delete(pvVar2);
  }
  FUN_000ad464(param_1 + 2);
  FUN_000ab6f0();
  return;
}

