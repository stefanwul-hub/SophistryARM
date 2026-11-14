/* 00004c28 LPAUSynth_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void LPAUSynth_vslot_0(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_LPAUSynth_vslot_0_000e4908;
  param_1[2] = &PTR_LAB_000e4a60;
  param_1[0x39] = &PTR_LAB_000e4a6c;
  param_1[0x3b] = &PTR_LAB_000e4ac0;
  Synth_vslot_4(param_1 + 0x3b);
  *(undefined1 *)(param_1 + 0xcad0c) = 0;
  piVar1 = (int *)param_1[0xcad0a];
  if (piVar1 != (int *)0x0) {
    _OSAtomicAdd32Barrier(0xffffffff,piVar1 + 0x9e72);
    if (piVar1[0x9e72] == 0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
    param_1[0xcad0a] = 0;
  }
  param_1[0x3d] = 0;
  FUN_000a67ae(param_1,0x267135,0,0);
  if ((void *)param_1[0xcacff] != (void *)0x0) {
    operator_delete__((void *)param_1[0xcacff]);
    param_1[0xcacff] = 0;
  }
  if ((void *)param_1[0xcad00] != (void *)0x0) {
    operator_delete__((void *)param_1[0xcad00]);
    param_1[0xcad00] = 0;
  }
  if ((void *)param_1[0xcad05] != (void *)0x0) {
    operator_delete__((void *)param_1[0xcad05]);
  }
  FUN_00045060(param_1 + 0x3b);
  *param_1 = PTR_DAT_001037e8 + 8;
  param_1[2] = PTR_DAT_001037e8 + 0x10c;
  param_1[0x39] = PTR_DAT_001037e8 + 0x118;
  FUN_000ad76c(param_1 + 0x39);
  FUN_000a7cf8();
  return;
}

