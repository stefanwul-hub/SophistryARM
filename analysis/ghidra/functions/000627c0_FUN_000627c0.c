/* 000627c0 FUN_000627c0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000627c0(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  
  switch(param_2) {
  case 0:
    Envelope_c_vslot_7(param_1 + 0x31f0,*(undefined4 *)(param_1 + 0x1a4),5,param_3);
    Envelope_c_vslot_7(param_1 + 0x7a2c,*(undefined4 *)(param_1 + 0x1a4),9,param_3);
    Envelope_c_vslot_7(param_1 + 0x8ce8,*(undefined4 *)(param_1 + 0x1a4),0xb,param_3);
    Envelope_c_vslot_7(param_1 + 0x3c88,*(undefined4 *)(param_1 + 0x1a4),6,param_3);
    Envelope_c_vslot_7(param_1 + 0x5d94,*(undefined4 *)(param_1 + 0x1a4),2,param_3);
    Envelope_c_vslot_7(param_1 + 0x67bc,*(undefined4 *)(param_1 + 0x1a4),2,param_3);
    Envelope_c_vslot_7(param_1 + 0x71c0,*(undefined4 *)(param_1 + 0x1a4),6,param_3);
    Envelope_c_vslot_7(param_1 + 0x7ca0,*(undefined4 *)(param_1 + 0x1a4),2,param_3);
    Envelope_c_vslot_7(param_1 + 0x8410,*(undefined4 *)(param_1 + 0x1a4),6,param_3);
    Envelope_c_vslot_7(param_1 + 0x7edc,*(undefined4 *)(param_1 + 0x1a4),1,param_3);
    Envelope_c_vslot_7(param_1 + 0x8660,*(undefined4 *)(param_1 + 0x1a4),0xb,param_3);
    return;
  case 1:
    Envelope_c_vslot_7(param_1 + 0x8f28,*(undefined4 *)(param_1 + 0x1a4),5,param_3);
    Envelope_c_vslot_7(&UNK_0000d764 + param_1,*(undefined4 *)(param_1 + 0x1a4),9,param_3);
    Envelope_c_vslot_7(param_1 + 0xea20,*(undefined4 *)(param_1 + 0x1a4),0xb,param_3);
    Envelope_c_vslot_7(param_1 + 0x99c0,*(undefined4 *)(param_1 + 0x1a4),6,param_3);
    Envelope_c_vslot_7(param_1 + 0xbacc,*(undefined4 *)(param_1 + 0x1a4),2,param_3);
    Envelope_c_vslot_7(param_1 + 0xc4f4,*(undefined4 *)(param_1 + 0x1a4),2,param_3);
    Envelope_c_vslot_7(param_1 + 0xcef8,*(undefined4 *)(param_1 + 0x1a4),6,param_3);
    Envelope_c_vslot_7(param_1 + 0xd9d8,*(undefined4 *)(param_1 + 0x1a4),2,param_3);
    Envelope_c_vslot_7(param_1 + 0xe148,*(undefined4 *)(param_1 + 0x1a4),6,param_3);
    Envelope_c_vslot_7(param_1 + 0xdc14,*(undefined4 *)(param_1 + 0x1a4),1,param_3);
    Envelope_c_vslot_7(param_1 + 0xe398,*(undefined4 *)(param_1 + 0x1a4),0xb,param_3);
    return;
  case 2:
    param_2 = 0x6c;
    break;
  case 3:
    param_2 = 0x6e;
    break;
  case 4:
    param_2 = 0x70;
    break;
  case 5:
    param_2 = 0x72;
    break;
  default:
    return;
  }
  uVar1 = FUN_00010a30(param_2 * 0x70 + *(int *)(param_1 + 0x14fec));
  if (uVar1 < 0xc) {
                    /* WARNING: Could not recover jumptable at 0x00062581. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((&switchD_00062581::switchdataD_00062584)[uVar1] + 0x62555))();
    return;
  }
  return;
}

