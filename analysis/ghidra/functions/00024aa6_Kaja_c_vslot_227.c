/* 00024aa6 Kaja_c_vslot_227 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Kaja_c_vslot_227(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined *local_54;
  undefined1 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined *local_40;
  undefined1 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined *local_2c;
  undefined1 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_1[0x33ec] + -1 < param_2) {
    param_2 = param_1[0x33ec] + -1;
  }
  iVar1 = *(int *)(param_1[0x33a9] + param_2 * 4);
  if (iVar1 != 0) {
    if (param_1[2] != 0) {
      local_50 = *(undefined1 *)(param_3 + 4);
      local_4c = *(undefined4 *)(param_3 + 8);
      local_44 = *(undefined4 *)(param_3 + 0x10);
      local_48 = 0;
      local_54 = PTR_DAT_00103814 + 8;
      (**(code **)(*(int *)param_1[2] + 0x88))((int *)param_1[2],0,&local_54);
      local_54 = PTR_DAT_00103808 + 8;
    }
    local_3c = *(undefined1 *)(param_3 + 4);
    local_38 = *(undefined4 *)(param_3 + 8);
    local_34 = *(undefined4 *)(param_3 + 0xc);
    local_40 = PTR_DAT_00103814 + 8;
    local_30 = *(undefined4 *)(param_3 + 0x10);
    iVar2 = FUN_0002fdc4(param_1 + 0xe33,param_2,&local_40);
    local_40 = PTR_DAT_00103808 + 8;
    if (-1 < iVar2) {
      Envelope_c_vslot_9(param_1 + 0x169,param_2,6,*(undefined4 *)(iVar1 + 0x14c));
      if ((-1 < param_1[0xed5]) && (-1 < param_1[0xed9])) {
        (**(code **)(*param_1 + 0x34c))(param_1,param_1[0xed5] + param_1[0xed9] * param_2,0);
      }
      local_2c = PTR_DAT_00103808 + 8;
      local_28 = *(undefined1 *)(param_3 + 4);
      local_24 = *(undefined4 *)(param_3 + 8);
      local_20 = *(undefined4 *)(param_3 + 0xc);
      (**(code **)(**(int **)(param_1[0xec3] + iVar2 * 4) + 0x20))
                (*(undefined4 *)(iVar2 * 4 + param_1[0xec3]),param_2,&local_2c);
    }
  }
  return;
}

