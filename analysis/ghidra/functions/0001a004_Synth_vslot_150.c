/* 0001a004 Synth_vslot_150 */

undefined4 Synth_vslot_150(int *param_1)

{
  _OSAtomicAdd32Barrier(1,param_1 + 0xecc);
  (**(code **)(*param_1 + 0x27c))(param_1);
  _OSAtomicAdd32Barrier(0xffffffff,param_1 + 0xecc);
  return 1;
}

