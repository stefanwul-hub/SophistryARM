/* 000168e2 Synth_vslot_4 */

void Synth_vslot_4(int *param_1)

{
  if ((char)param_1[0x33f1] != '\0') {
    param_1[0xece] = 1;
    (**(code **)(*param_1 + 0x264))(param_1);
    (**(code **)(*param_1 + 0x268))(param_1);
    param_1[0xece] = 0;
  }
  return;
}

