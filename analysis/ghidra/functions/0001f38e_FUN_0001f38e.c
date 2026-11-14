/* 0001f38e FUN_0001f38e */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0001f38e(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  char cVar6;
  char *pcVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  uint local_60;
  uint local_5c;
  undefined2 local_54;
  undefined1 local_50;
  undefined1 local_4c [4];
  undefined1 local_48;
  undefined1 local_47;
  undefined2 local_46;
  char *local_40;
  char *local_3c;
  undefined1 local_31;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  undefined1 uStack_2e;
  undefined1 local_2d;
  int local_2c;
  uint local_28;
  int local_24;
  undefined4 local_20 [4];
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_1[0x33ec] + -1 < param_2) {
    param_2 = param_1[0x33ec] + -1;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  if (param_1[0x2693] + -1 < param_3) {
    param_3 = param_1[0x2693] + -1;
  }
  iVar10 = *(int *)(param_1[0x33a9] + param_2 * 4);
  if ((iVar10 != 0) && (iVar1 = *(int *)(param_1[0x33a8] + param_3 * 4), iVar1 != 0)) {
    cVar5 = FUN_0002ddaa(iVar10 + 0xe50);
    if (2 < param_1[0xee2]) {
      iVar10 = 2;
      piVar9 = param_1;
      do {
        iVar2 = piVar9[0x145a];
        if ((iVar2 != 0) && (param_2 < *(int *)(iVar2 + 8))) {
          FUN_00011b02(iVar2,param_2);
        }
        iVar10 = iVar10 + 1;
        piVar9 = piVar9 + 7;
      } while (iVar10 < param_1[0xee2]);
    }
    local_60 = 0;
    local_5c = 0;
    bVar4 = true;
    while (((((uVar8 = FUN_0002e026(iVar1), local_60 < uVar8 >> 2 &&
              (cVar6 = FUN_0002e0fc(iVar1,local_60,&local_24), cVar6 != '\0')) &&
             (cVar6 = FUN_0002e13a(iVar1,local_60 + 1,&local_28), cVar6 != '\0')) &&
            ((cVar6 = FUN_0002e13a(iVar1,local_60 + 2,&local_2c), cVar6 != '\0' &&
             (cVar6 = FUN_0002e0b2(iVar1,local_60,local_20), cVar6 != '\0')))) && (bVar4))) {
      local_2d = 0;
      _local_31 = CONCAT13((char)local_24,
                           CONCAT12((char)((uint)local_24 >> 8),
                                    CONCAT11((char)((uint)local_24 >> 0x10),
                                             (char)((uint)local_24 >> 0x18))));
      if ((int)local_28 < 1) break;
      if (param_1[0xee2] < 3) {
LAB_0001f43f:
        cVar6 = (**(code **)(*param_1 + 0x298))(param_1,local_24);
        if ((cVar6 == '\0') && (*(char *)((int)param_1 + 0xcfd7) == '\0')) {
          pcVar7 = (char *)_malloc(0x141);
          if (pcVar7 == (char *)0x0) {
            local_5c = 0;
            bVar4 = false;
          }
          else {
            _sprintf(pcVar7,"format mismatch %s Order %ld",&local_31,local_2c);
            FUN_0002b8e2(local_4c);
            local_48 = 0x50;
            local_50 = (undefined1)param_2;
            local_47 = local_50;
            local_54 = (undefined2)param_3;
            local_46 = local_54;
            local_3c = "Instrument Load Error";
            local_40 = pcVar7;
            FUN_0002ba10(param_1 + 0xe2e,local_4c);
            HoldData_c_vslot_0(local_4c);
            local_5c = 0;
            bVar4 = false;
          }
        }
        else {
          local_5c = 0;
          bVar4 = true;
        }
      }
      else {
        iVar10 = 2;
        piVar9 = param_1;
        bVar4 = false;
        do {
          while ((bVar3 = bVar4, piVar9[0x1457] != local_24 || (piVar9[0x1458] != local_2c))) {
            iVar10 = iVar10 + 1;
            piVar9 = piVar9 + 7;
            bVar4 = bVar3;
            if (param_1[0xee2] <= iVar10) goto LAB_0001f650;
          }
          local_5c = (**(code **)(*(int *)piVar9[0x145a] + 0x10))
                               ((int *)piVar9[0x145a],local_20[0],local_28,param_2);
          bVar3 = true;
          iVar10 = iVar10 + 1;
          piVar9 = piVar9 + 7;
          bVar4 = true;
        } while (iVar10 < param_1[0xee2]);
LAB_0001f650:
        if (!bVar3) goto LAB_0001f43f;
        bVar4 = true;
      }
      uVar8 = local_28;
      if ((int)local_28 < (int)local_5c) {
        uVar8 = local_5c;
      }
      local_60 = local_60 + (uVar8 >> 2);
    }
    if (cVar5 != '\0') {
      FUN_0002ddc8(*(int *)(param_2 * 4 + param_1[0x33a9]) + 0xe50);
    }
  }
  return;
}

