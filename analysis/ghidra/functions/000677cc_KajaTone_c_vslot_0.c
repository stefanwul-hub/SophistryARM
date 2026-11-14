/* 000677cc KajaTone_c_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void KajaTone_c_vslot_0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int local_24;
  
  *param_1 = &PTR_KajaTone_c_vslot_0_000f0e28;
  Amp_c_vslot_0(param_1 + 0x4d3a);
  Amp_c_vslot_0(param_1 + 0x4cb8);
  DistSimp2_c_vslot_0(param_1 + 0x4c3b);
  FilterFree_c_vslot_0(param_1 + 0x4b84);
  FilterFree_c_vslot_0(param_1 + 0x4acd);
  FilterMoogSI_c_vslot_0(param_1 + 0x39fe);
  FilterMoogSI_c_vslot_0(param_1 + 0x292f);
  Satur_c_vslot_0(param_1 + 0x28b5);
  Satur_c_vslot_0(param_1 + 0x283b);
  Pan51_c_vslot_0(param_1 + 0x27b6);
  Pan51_c_vslot_0(param_1 + 0x2731);
  Pan51_c_vslot_0(param_1 + 0x26ac);
  Pan51_c_vslot_0(param_1 + 0x2627);
  Pan_c_vslot_0(param_1 + 0x25a5);
  Pan_c_vslot_0(param_1 + 0x2523);
  Pan_c_vslot_0(param_1 + 0x24a1);
  Pan_c_vslot_0(param_1 + 0x241f);
  SamLoop_c_vslot_0(param_1 + 0x2307);
  SamLoop_c_vslot_0(param_1 + 0x21ef);
  if ((param_1 != (undefined4 *)0xffff8274) &&
     (puVar2 = param_1 + 0x21ef, param_1 + 0x1f63 != puVar2)) {
    puVar1 = param_1 + 0x214c;
    local_24 = 4;
    do {
      puVar2 = puVar2 + -0xa3;
      (**(code **)*puVar1)(puVar2);
      puVar1 = puVar1 + -0xa3;
      local_24 = local_24 + -1;
    } while (local_24 != 0);
  }
  SamTC3_c_vslot_0(param_1 + 0x1e71);
  SamTC3_c_vslot_0(param_1 + 0x1d7f);
  SamTC3_c_vslot_0(param_1 + 0x1c8d);
  SamTC3_c_vslot_0(param_1 + 0x1b9b);
  OscAnalog3_c_vslot_0(param_1 + 0x1a75);
  OscAnalog3_c_vslot_0(param_1 + 0x194f);
  OscAnalog3_c_vslot_0(param_1 + 0x1829);
  OscAnalog3_c_vslot_0(param_1 + 0x1703);
  RampGlide_c_vslot_0(param_1 + 0x1682);
  EnvADSFR_c_vslot_0(param_1 + 0x15a0);
  EnvADSFR_c_vslot_0(param_1 + 0x14be);
  EnvADSFR_c_vslot_0(param_1 + 0x13dc);
  EnvADSFR_c_vslot_0(param_1 + 0x12fa);
  EnvADSFR_c_vslot_0(param_1 + 0x1218);
  EnvADSFR_c_vslot_0(param_1 + 0x1136);
  EnvADSFR_c_vslot_0(param_1 + 0x1054);
  AdvLFO_c_vslot_0(param_1 + 0xd04);
  AdvLFO_c_vslot_0(param_1 + 0x9b4);
  AdvLFO_c_vslot_0(param_1 + 0x664);
  AdvLFO_c_vslot_0(param_1 + 0x314);
  FUN_0002b820();
  return;
}

