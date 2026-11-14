/* 0001786e Synth_vslot_94 */

undefined4 * Synth_vslot_94(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0x506e694c;
    param_2[1] = 0x67756c;
    param_2 = (undefined4 *)((int)&mach_header_00000000.magic + 1);
  }
  return param_2;
}

