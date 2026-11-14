/* 000a64e2 SynthEditor_c_vslot_20 */

void SynthEditor_c_vslot_20(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  iVar2 = _TickCount();
  uVar4 = (uint)(iVar2 * 1000) / 0x3c;
  if (uVar4 < (uint)param_1[5]) {
    _RunCurrentEventLoop(0xd2f1a9fc,0x3f70624d);
    uVar4 = uVar4 + 4;
    if (uVar4 < param_1[5] - 0x32U) {
      return;
    }
  }
  (**(code **)(*param_1 + 0x1c))(param_1);
  local_30 = 0x77696e64;
  local_2c = 1;
  local_28 = 0x77696e64;
  local_24 = 2;
  iVar2 = _ReceiveNextEvent(2,&local_30,0,0,1,local_20);
  if (iVar2 == 0) {
    uVar3 = _GetEventDispatcherTarget();
    _SendEventToEventTarget(local_20[0],uVar3);
    _ReleaseEvent(local_20[0]);
  }
  param_1[5] = uVar4 + 100;
  *(undefined1 *)(param_1 + 6) = 1;
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x90))(piVar1);
  }
  *(undefined1 *)(param_1 + 6) = 0;
  return;
}

