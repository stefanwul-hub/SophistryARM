/* 000b890c Crossfader_c_vslot_2 */

/* WARNING: Function: __i686.get_pc_thunk.cx replaced with injection: get_pc_thunk_cx */

void Crossfader_c_vslot_2(int param_1,undefined8 param_2,undefined8 param_3)

{
  *(undefined8 *)(param_1 + 8) = param_2;
  *(undefined8 *)(param_1 + 0x10) = param_3;
  *(undefined4 *)(param_1 + 0x18) = 0x3f800000;
  *(float *)(param_1 + 0x1c) = *(float *)(param_1 + 4) * -1000.0;
  *(undefined1 *)(param_1 + 0x20) = 1;
  return;
}

