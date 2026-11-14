/* 000789c2 FilterMoogSI_c_vslot_32 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FilterMoogSI_c_vslot_32(int param_1,undefined4 param_2,int param_3,char param_4)

{
  int iVar1;
  undefined *local_2c;
  undefined1 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_2c = PTR_DAT_00103808 + 8;
  local_28 = *(undefined1 *)(param_3 + 4);
  local_24 = *(undefined4 *)(param_3 + 8);
  local_20 = *(undefined4 *)(param_3 + 0xc);
  VariatorTone_c_vslot_32(param_1,param_2,&local_2c,param_4);
  local_2c = PTR_DAT_00103808 + 8;
  if ((*(int *)(param_1 + 0x124) != 0) && (param_4 == '\0')) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x124) + 0xe8);
    *(int *)(param_1 + 0x432c) = iVar1;
    if (iVar1 == 2) {
      _memset((void *)(param_1 + 0x2e8),0,0x2000);
      _memset((void *)(param_1 + 0x22e8),0,0x2000);
    }
    *(undefined4 *)(param_1 + 0x42e8) = 0;
    *(undefined4 *)(param_1 + 0x208) = 0;
    *(undefined4 *)(param_1 + 0x20c) = 0;
    *(undefined4 *)(param_1 + 0x210) = 0;
    *(undefined4 *)(param_1 + 0x214) = 0;
    *(undefined4 *)(param_1 + 0x218) = 0;
    *(undefined4 *)(param_1 + 0x21c) = 0;
    *(undefined4 *)(param_1 + 0x220) = 0;
    *(undefined4 *)(param_1 + 0x224) = 0;
    *(undefined4 *)(param_1 + 0x228) = 0;
    *(undefined4 *)(param_1 + 0x22c) = 0;
    *(undefined4 *)(param_1 + 0x230) = 0;
    *(undefined4 *)(param_1 + 0x234) = 0;
    *(undefined4 *)(param_1 + 0x238) = 0;
    *(undefined4 *)(param_1 + 0x23c) = 0;
    *(undefined4 *)(param_1 + 0x240) = 0;
    *(undefined4 *)(param_1 + 0x244) = 0;
    *(undefined8 *)(param_1 + 0x288) = 0;
    *(undefined8 *)(param_1 + 0x248) = 0;
    *(undefined8 *)(param_1 + 0x290) = 0;
    *(undefined8 *)(param_1 + 0x250) = 0;
    *(undefined8 *)(param_1 + 0x298) = 0;
    *(undefined8 *)(param_1 + 600) = 0;
    *(undefined8 *)(param_1 + 0x2a0) = 0;
    *(undefined8 *)(param_1 + 0x260) = 0;
    *(undefined8 *)(param_1 + 0x2a8) = 0;
    *(undefined8 *)(param_1 + 0x268) = 0;
    *(undefined8 *)(param_1 + 0x2b0) = 0;
    *(undefined8 *)(param_1 + 0x270) = 0;
    *(undefined8 *)(param_1 + 0x2b8) = 0;
    *(undefined8 *)(param_1 + 0x278) = 0;
    *(undefined8 *)(param_1 + 0x2c0) = 0;
    *(undefined8 *)(param_1 + 0x280) = 0;
    *(undefined4 *)(param_1 + 0x431c) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x4318) = 0;
    *(undefined4 *)(param_1 + 0x4310) = 0;
    *(undefined4 *)(param_1 + 0x42f4) = 0;
    *(undefined4 *)(param_1 + 0x42f8) = 0;
  }
  return;
}

