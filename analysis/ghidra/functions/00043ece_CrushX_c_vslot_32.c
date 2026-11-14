/* 00043ece CrushX_c_vslot_32 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CrushX_c_vslot_32(int param_1,undefined4 param_2,int param_3,char param_4)

{
  undefined *local_2c;
  undefined1 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_2c = PTR_DAT_00103808 + 8;
  local_28 = *(undefined1 *)(param_3 + 4);
  local_24 = *(undefined4 *)(param_3 + 8);
  local_20 = *(undefined4 *)(param_3 + 0xc);
  Envelope_c_vslot_32(param_1,param_2,&local_2c,param_4);
  if ((*(int *)(param_1 + 0x124) != 0) && (*(undefined1 *)(param_1 + 0x1e0) = 0, param_4 == '\0')) {
    *(undefined4 *)(param_1 + 0x1f0) = 0;
    *(undefined4 *)(param_1 + 600) = 0;
    *(undefined8 *)(param_1 + 0x230) = 0;
    *(undefined8 *)(param_1 + 0x220) = 0;
    *(undefined8 *)(param_1 + 0x228) = 0;
    *(undefined8 *)(param_1 + 0x26c) = 0;
    *(undefined8 *)(param_1 + 0x25c) = 0;
    *(undefined8 *)(param_1 + 0x264) = 0;
    *(undefined4 *)(param_1 + 0x248) = *(undefined4 *)(param_1 + 0x24c);
    *(undefined4 *)(param_1 + 0x27c) = *(undefined4 *)(param_1 + 0x24c);
    *(undefined4 *)(param_1 + 0x240) = 0;
    *(undefined4 *)(param_1 + 0x274) = 0;
    *(undefined4 *)(param_1 + 0x244) = 0;
    *(undefined4 *)(param_1 + 0x278) = 0;
    *(undefined4 *)(param_1 + 0x284) = 0;
    *(undefined4 *)(param_1 + 0x280) = 0;
  }
  return;
}

