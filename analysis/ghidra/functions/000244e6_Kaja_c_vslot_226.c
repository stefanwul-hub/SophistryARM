/* 000244e6 Kaja_c_vslot_226 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int Kaja_c_vslot_226(int *param_1,int param_2,int param_3,int param_4)

{
  undefined1 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined *local_5c;
  undefined1 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined *local_48;
  undefined1 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined *local_34;
  undefined1 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_1d [13];
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  iVar7 = param_1[0x33ec] + -1;
  if (param_2 <= param_1[0x33ec] + -1) {
    iVar7 = param_2;
  }
  piVar2 = *(int **)(param_1[0x33a9] + iVar7 * 4);
  if (piVar2 != (int *)0x0) {
    iVar4 = Envelope_c_vslot_12(param_1 + 0x169,iVar7,4);
    if (iVar4 == 0) {
      uVar1 = *(undefined1 *)((int)param_1 + 0xcfd3);
      local_58 = *(undefined1 *)(param_3 + 4);
      local_54 = *(undefined4 *)(param_3 + 8);
      local_50 = *(undefined4 *)(param_3 + 0xc);
      local_5c = PTR_DAT_00103814 + 8;
      local_4c = *(undefined4 *)(param_3 + 0x10);
      uVar5 = (**(code **)(*piVar2 + 0x80))(piVar2);
      iVar4 = FUN_0002fb5c(param_1 + 0xe33,iVar7,piVar2,uVar5,&local_5c,local_1d,uVar1);
      local_5c = PTR_DAT_00103808 + 8;
      if (iVar4 < 0) {
        return iVar4;
      }
      Envelope_c_vslot_9(param_1 + 0x169,iVar7,6,piVar2[0x53]);
      if ((-1 < param_1[0xed5]) && (-1 < param_1[0xed9])) {
        (**(code **)(*param_1 + 0x34c))(param_1,param_1[0xed5] + param_1[0xed9] * iVar7,0);
      }
      piVar3 = (int *)param_1[2];
      if (piVar3 != (int *)0x0) {
        local_44 = *(undefined1 *)(param_3 + 4);
        local_40 = *(undefined4 *)(param_3 + 8);
        local_3c = *(undefined4 *)(param_3 + 0xc);
        local_48 = PTR_DAT_00103814 + 8;
        local_38 = *(undefined4 *)(param_3 + 0x10);
        (**(code **)(*piVar3 + 0x88))(piVar3,0,&local_48);
        local_48 = PTR_DAT_00103808 + 8;
      }
      iVar6 = (**(code **)(*piVar2 + 0x88))(piVar2,*(undefined4 *)(param_3 + 0x10));
      if (iVar6 == -1) {
        (**(code **)(*piVar2 + 0x90))
                  (piVar2,*(undefined4 *)(param_3 + 0x10),*(undefined4 *)(param_3 + 8));
      }
      local_30 = *(undefined1 *)(param_4 + 4);
      local_2c = *(undefined4 *)(param_4 + 8);
      local_28 = *(undefined4 *)(param_4 + 0xc);
      local_34 = PTR_DAT_00103814 + 8;
      local_24 = *(undefined4 *)(param_4 + 0x10);
      (**(code **)(*param_1 + 0x294))(param_1,iVar7,iVar4,local_1d[0],&local_34);
      local_34 = PTR_DAT_00103808 + 8;
      (**(code **)(*piVar2 + 0x90))
                (piVar2,*(undefined4 *)(param_3 + 0x10),*(undefined4 *)(param_3 + 8));
      return iVar4;
    }
  }
  return -1;
}

