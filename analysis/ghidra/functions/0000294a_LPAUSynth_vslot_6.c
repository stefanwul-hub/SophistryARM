/* 0000294a LPAUSynth_vslot_6 */

void LPAUSynth_vslot_6(int param_1)

{
  if (*(int *)(param_1 + 0x32b3f4) != 0) {
    _RemoveEventLoopTimer(*(int *)(param_1 + 0x32b3f4));
  }
  if (*(int *)(param_1 + 0x32b3f8) != 0) {
    _DisposeEventLoopTimerUPP(*(int *)(param_1 + 0x32b3f8));
  }
  *(undefined4 *)(param_1 + 0x32b3f4) = 0;
  *(undefined4 *)(param_1 + 0x32b3f8) = 0;
  (**(code **)(*(int *)(param_1 + 0xec) + 8))(param_1 + 0xec,0xc,0,0,0,0);
  if (*(void **)(param_1 + 0x32b400) != (void *)0x0) {
    operator_delete__(*(void **)(param_1 + 0x32b400));
    *(undefined4 *)(param_1 + 0x32b400) = 0;
  }
  if (*(void **)(param_1 + 0x32b3fc) != (void *)0x0) {
    operator_delete__(*(void **)(param_1 + 0x32b3fc));
    *(undefined4 *)(param_1 + 0x32b3fc) = 0;
  }
  return;
}

