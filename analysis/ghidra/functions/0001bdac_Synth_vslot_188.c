/* 0001bdac Synth_vslot_188 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Synth_vslot_188(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_15c [332];
  
  if ((param_1[0xe3b] != 0) && (param_1[0xe3c] != 0)) {
    FUN_00009996(param_1 + 0x30f6,param_2,local_15c);
    *(undefined1 *)((int)param_1 + 0xcfdb) = 1;
    FUN_0002d328(param_1[0xe3b],local_15c,1);
    FUN_0002d328(param_1[0xe3c],param_2,0);
    if (0 < *(int *)(param_1[0xe3c] + 0x528)) {
      iVar1 = FUN_0002ca94(param_1[0xe3c],0);
      if (iVar1 != 0) {
        (**(code **)(*param_1 + 0x2dc))(param_1,0,iVar1);
        Envelope_c_vslot_18(param_1 + 0xf3,0,0x1e,&DAT_000fbf80);
      }
    }
    *(undefined1 *)((int)param_1 + 0xcfdb) = 0;
  }
  return;
}

