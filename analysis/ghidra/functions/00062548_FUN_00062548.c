/* 00062548 FUN_00062548 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00062548(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00010a30(param_2 * 0x70 + *(int *)(param_1 + 0x14fec));
  switch(uVar1) {
  case 0:
    Envelope_c_vslot_7(param_1 + 0xec60,*(undefined4 *)(param_1 + 0x1a4),5,param_3);
    break;
  case 1:
    Envelope_c_vslot_7(&DAT_0001349c + param_1,*(undefined4 *)(param_1 + 0x1a4),9,param_3);
    break;
  case 2:
    Envelope_c_vslot_7(param_1 + 0x14758,*(undefined4 *)(param_1 + 0x1a4),0xb,param_3);
    break;
  case 3:
    Envelope_c_vslot_7(param_1 + 0xf6f8,*(undefined4 *)(param_1 + 0x1a4),6,param_3);
    break;
  case 4:
    Envelope_c_vslot_7(param_1 + 0x11804,*(undefined4 *)(param_1 + 0x1a4),2,param_3);
    break;
  case 5:
    Envelope_c_vslot_7(param_1 + 0x1222c,*(undefined4 *)(param_1 + 0x1a4),2,param_3);
    break;
  case 6:
    Envelope_c_vslot_7(param_1 + 0x12c30,*(undefined4 *)(param_1 + 0x1a4),6,param_3);
    break;
  case 7:
    Envelope_c_vslot_7(&DAT_00013710 + param_1,*(undefined4 *)(param_1 + 0x1a4),2,param_3);
    break;
  case 8:
    Envelope_c_vslot_7(param_1 + 0x13e80,*(undefined4 *)(param_1 + 0x1a4),6,param_3);
    break;
  case 9:
    Envelope_c_vslot_7(&DAT_0001394c + param_1,*(undefined4 *)(param_1 + 0x1a4),1,param_3);
    break;
  case 0xb:
    Envelope_c_vslot_7(param_1 + 0x140d0,*(undefined4 *)(param_1 + 0x1a4),0xb,param_3);
  }
  return;
}

