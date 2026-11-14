/* 00005238 _LPAUViewEntry */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 _LPAUViewEntry(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (*(short *)(param_1 + 2) != -1) {
    uVar1 = FUN_000ad378(param_1,param_2);
    return uVar1;
  }
  uVar1 = *(undefined4 *)(param_1 + 4);
  puVar2 = (undefined4 *)operator_new(0x5c);
  FUN_000acdae(puVar2,uVar1,0x3dcccccd);
  *puVar2 = &PTR_LPAUView_vslot_0_000e4f48;
  puVar2[2] = &PTR_LAB_000e4f80;
  puVar2[0x15] = 0;
  puVar2[0x16] = 0;
  LPAUView_vslot_3(puVar2);
  _SetComponentInstanceStorage(uVar1,puVar2);
  return 0;
}

