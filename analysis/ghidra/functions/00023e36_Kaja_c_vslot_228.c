/* 00023e36 Kaja_c_vslot_228 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Kaja_c_vslot_228(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined *local_6c;
  undefined1 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined *local_58;
  undefined1 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined *puStack_44;
  undefined1 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined *puStack_30;
  undefined1 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  iVar4 = param_1[0x33ec] + -1;
  if (param_2 <= param_1[0x33ec] + -1) {
    iVar4 = param_2;
  }
  piVar5 = param_1 + 0x169;
  iVar1 = Envelope_c_vslot_12(piVar5,iVar4,7);
  if (iVar1 != 1) {
    local_68 = *(undefined1 *)(param_4 + 4);
    local_64 = *(undefined4 *)(param_4 + 8);
    local_60 = *(undefined4 *)(param_4 + 0xc);
    local_6c = PTR_DAT_00103814 + 8;
    local_5c = *(undefined4 *)(param_4 + 0x10);
    local_54 = *(undefined1 *)(param_3 + 4);
    local_50 = *(undefined4 *)(param_3 + 8);
    local_4c = *(undefined4 *)(param_3 + 0xc);
    local_58 = PTR_DAT_00103814 + 8;
    local_48 = *(undefined4 *)(param_3 + 0x10);
    (**(code **)(*param_1 + 0x388))(param_1,iVar4,&local_58,&local_6c);
    local_58 = PTR_DAT_00103808 + 8;
    local_6c = PTR_DAT_00103808 + 8;
  }
  iVar1 = Envelope_c_vslot_12(piVar5,iVar4,7);
  switch(iVar1) {
  case 1:
    piVar6 = param_1 + 0xe33;
    iVar1 = FUN_0002edda(piVar6,iVar4,0x80,0x10,piVar5,iVar1,piVar6);
    while (-1 < iVar1) {
      FUN_0001881e(param_1,iVar1);
      iVar1 = FUN_0002edda(piVar6,iVar4,0x80,0x10);
    }
    uStack_40 = *(undefined1 *)(param_4 + 4);
    uStack_3c = *(undefined4 *)(param_4 + 8);
    uStack_38 = *(undefined4 *)(param_4 + 0xc);
    puStack_44 = PTR_DAT_00103814 + 8;
    uStack_34 = *(undefined4 *)(param_4 + 0x10);
    uStack_2c = *(undefined1 *)(param_3 + 4);
    uStack_28 = *(undefined4 *)(param_3 + 8);
    uStack_24 = *(undefined4 *)(param_3 + 0xc);
    puStack_30 = PTR_DAT_00103814 + 8;
    uStack_20 = *(undefined4 *)(param_3 + 0x10);
    (**(code **)(*param_1 + 0x388))(param_1,iVar4,&puStack_30,&puStack_44);
    return;
  case 2:
    iVar1 = param_1[0x33ec];
    while (iVar3 = FUN_0002edda(param_1 + 0xe33,(iVar4 + -1 + iVar1) % iVar1,0x80,0x10), -1 < iVar3)
    {
      FUN_0001881e(param_1,iVar3);
    }
    return;
  case 3:
    iVar1 = param_1[0x33ec];
    while (iVar3 = FUN_0002edda(param_1 + 0xe33,(iVar4 + 1) % iVar1,0x80,0x10), -1 < iVar3) {
      FUN_0001881e(param_1,iVar3);
    }
    return;
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
    if (0 < param_1[0x33ec]) {
      iVar3 = 0;
      do {
        iVar2 = Envelope_c_vslot_12(piVar5,iVar3,7);
        if ((iVar1 == iVar2) && (iVar4 != iVar3)) {
          iVar2 = FUN_0002edda(param_1 + 0xe33,iVar3,0x80,0x10);
          while (-1 < iVar2) {
            FUN_0001881e(param_1,iVar2);
            iVar2 = FUN_0002edda(param_1 + 0xe33,iVar3,0x80,0x10);
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_1[0x33ec]);
    }
  }
  return;
}

