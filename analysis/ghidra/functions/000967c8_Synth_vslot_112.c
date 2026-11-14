/* 000967c8 Synth_vslot_112 */

undefined4 Synth_vslot_112(undefined4 param_1,undefined4 *param_2)

{
  if ((void *)*param_2 != (void *)0x0) {
    operator_delete__((void *)*param_2);
    *param_2 = 0;
  }
  return 1;
}

