/* 000318d6 GloFil_c_vslot_30 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void GloFil_c_vslot_30(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  Envelope_c_vslot_30(param_1,param_2,param_3);
  iVar2 = FUN_00011b72(*(undefined4 *)(param_1 + 0x120),param_2);
  if ((iVar2 != 0) && (((param_3 == -1 || (param_3 == 7)) || (param_3 == 10)))) {
    uVar1 = *(undefined4 *)(iVar2 + 0x468);
    Envelope_c_vslot_9(param_1 + 0x1e0,param_2,3,(int)(*(float *)(iVar2 + 0x31c) * 100.0));
    Envelope_c_vslot_9(param_1 + 0x1e0,param_2,5,uVar1);
  }
  return;
}

