/* 00006f5a CMenuWithSub_vslot_102 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CMenuWithSub_vslot_102(int *param_1,int *param_2,int param_3,int param_4,char param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  undefined4 *puVar7;
  int iVar8;
  
  iVar1 = *param_2;
  iVar8 = param_1[0x44];
  puVar7 = (undefined4 *)operator_new(0x140);
  iVar2 = param_1[0x3e];
  iVar3 = param_1[0x3d];
  iVar4 = *param_2;
  iVar5 = param_1[0xd];
  FUN_0009c638(puVar7,param_1 + 2,param_1 + 0x43,param_1[0x10],iVar5,param_1[0x30],param_1[0x20]);
  *puVar7 = &PTR_CMenuBase_vslot_0_000e53e8;
  puVar7[0x39] = 0;
  if (iVar5 == 0) {
    *(undefined1 *)((int)puVar7 + 0x32) = 1;
  }
  *puVar7 = &PTR_CSubMenuPl_vslot_0_000e5568;
  puVar7[0x4f] = param_1 + 0x43;
  *(undefined1 *)(puVar7 + 0x3a) = 0;
  puVar7[0x39] = iVar4;
  puVar7[0x4e] = iVar2 - iVar3;
  CMenuFileList_vslot_64(puVar7,4);
  CMenuFileList_vslot_65(puVar7,iVar8);
  iVar8 = *param_2;
  if (iVar8 < param_3) {
    if (param_5 == '\0') {
      do {
        (**(code **)(*param_1 + 0x17c))(param_1,puVar7,iVar8,iVar8 - iVar1);
        cVar6 = (**(code **)(*param_1 + 0x194))(param_1,*param_2,param_3);
        iVar8 = *param_2 + 1;
        *param_2 = iVar8;
        if (cVar6 == '\0') break;
      } while (iVar8 < param_3);
    }
    else {
      do {
        (**(code **)(*param_1 + 0x178))(param_1,puVar7,iVar8,iVar8 - iVar1,param_4 + 1);
        cVar6 = (**(code **)(*param_1 + 0x194))(param_1,*param_2,param_3);
        iVar8 = *param_2 + 1;
        *param_2 = iVar8;
        if (cVar6 == '\0') break;
      } while (iVar8 < param_3);
    }
  }
  if ((*param_2 <= param_3) && (param_1[0x369] < 0x20)) {
    param_1[param_1[0x369] + 0x45] = (int)puVar7;
  }
  return;
}

