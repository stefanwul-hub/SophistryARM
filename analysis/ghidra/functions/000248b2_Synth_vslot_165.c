/* 000248b2 Synth_vslot_165 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Synth_vslot_165(int *param_1,int param_2,int param_3,byte param_4,int param_5)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  longdouble lVar7;
  undefined *local_58;
  undefined1 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined *local_44;
  undefined1 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined *local_30;
  undefined1 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  puVar5 = PTR_DAT_00103814 + 8;
  local_50 = 0xffffffff;
  local_4c = 0xffffffff;
  local_48 = 0xffffffff;
  local_54 = 1;
  if (param_2 < 0) {
    param_2 = 0;
  }
  iVar6 = param_1[0x33ec] + -1;
  if (param_2 <= param_1[0x33ec] + -1) {
    iVar6 = param_2;
  }
  piVar2 = *(int **)(param_1[0x33a9] + iVar6 * 4);
  if (piVar2 != (int *)0x0) {
    bVar1 = *(byte *)(piVar2 + 0x56);
    local_58 = puVar5;
    iVar4 = (**(code **)(*piVar2 + 0x80))(piVar2);
    FUN_0002ec4e(param_1 + 0xe33,param_3,&local_58);
    if (param_1[0x33ec] < 2) {
      param_3 = param_3 << 2;
    }
    else {
      param_3 = param_3 * 4;
      iVar3 = *(int *)(param_1[0xec3] + param_3);
      local_40 = *(undefined1 *)(param_5 + 4);
      local_3c = *(undefined4 *)(param_5 + 8);
      local_38 = *(undefined4 *)(param_5 + 0xc);
      local_34 = *(undefined4 *)(param_5 + 0x10);
      local_44 = puVar5;
      lVar7 = (longdouble)(**(code **)(*param_1 + 0x28c))(param_1,iVar6,&local_44);
      *(float *)(iVar3 + 0x118) = (float)lVar7;
      local_44 = PTR_DAT_00103808 + 8;
    }
    local_2c = local_54;
    local_28 = local_50;
    local_24 = local_4c;
    local_30 = PTR_DAT_00103814 + 8;
    local_20 = local_48;
    (**(code **)(**(int **)(param_1[0xec3] + param_3) + 0x2c))
              (*(undefined4 *)(param_1[0xec3] + param_3),iVar6,&local_30,param_4,
               iVar4 < 2 & bVar1 & param_4);
    return;
  }
  return;
}

