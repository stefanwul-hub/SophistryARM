/* 000967f2 Synth_vslot_113 */

undefined4 Synth_vslot_113(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  if ((param_3 != (undefined4 *)0x0) && (param_2 != (undefined4 *)0x0)) {
    _strncpy((char *)(param_2 + 4),(char *)(param_3 + 4),0x3f);
    *(undefined1 *)((int)param_2 + 0x4f) = 0;
    param_2[0x14] = param_3[0x14];
    *param_2 = *param_3;
    param_2[1] = param_3[1];
    param_2[2] = param_3[2];
    param_2[3] = param_3[3];
    param_2[0x15] = param_3[0x15];
    param_2[0x16] = param_3[0x16];
    param_2[0x17] = param_3[0x17];
    param_2[0x18] = param_3[0x18];
    param_2[0x19] = param_3[0x19];
    param_2[0x1a] = param_3[0x1a];
    param_2[0x1b] = param_3[0x1b];
    return 1;
  }
  return 0;
}

