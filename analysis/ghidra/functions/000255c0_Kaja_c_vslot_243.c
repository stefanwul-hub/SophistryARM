/* 000255c0 Kaja_c_vslot_243 */

void Kaja_c_vslot_243(int *param_1,int param_2)

{
  byte bVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  undefined1 local_24 [4];
  byte local_20;
  undefined1 local_1f;
  undefined2 local_1e;
  undefined4 local_18;
  undefined4 local_14;
  
  bVar1 = *(byte *)(param_2 + 4);
  if (bVar1 == 0x53) {
    if (*(char *)(param_2 + 5) == -1) {
      FUN_00024e9e(param_1);
      return;
    }
    FUN_00024cf6(param_1,*(char *)(param_2 + 5));
    return;
  }
  if (bVar1 < 0x54) {
    if (bVar1 == 0x51) {
      piVar5 = *(int **)(param_1[0x33a9] + (uint)*(byte *)(param_2 + 5) * 4);
      if (piVar5 == (int *)0x0) {
        return;
      }
      (**(code **)(*piVar5 + 0x54))(piVar5,param_2 + 0x14,1);
      return;
    }
    if (0x51 < bVar1) {
      if (0 < param_1[0x33ec]) {
        iVar6 = 0;
        do {
          piVar5 = *(int **)(param_1[0x33a9] + iVar6 * 4);
          if (piVar5 != (int *)0x0) {
            (**(code **)(*piVar5 + 0x50))(piVar5);
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < param_1[0x33ec]);
      }
      FUN_00024e9e(param_1);
      FUN_0002eb20(param_1 + 0xe33);
      FUN_0002bb04(param_1 + 0xe29);
      param_1[0xee9] = 0;
      return;
    }
    if (bVar1 == 0) {
      return;
    }
  }
  else {
    if (bVar1 == 0x58) {
      piVar5 = *(int **)(param_1[0x33a9] + (uint)*(byte *)(param_2 + 5) * 4);
      if (piVar5 == (int *)0x0) {
        return;
      }
      (**(code **)(*piVar5 + 0x54))(piVar5,param_2 + 0x14,0);
      return;
    }
    if (bVar1 == 0x59) {
      if (*(short *)(param_2 + 6) != -1) {
        (**(code **)(*param_1 + 0x3a0))
                  (param_1,*(undefined1 *)(param_2 + 5),(int)*(short *)(param_2 + 6));
        return;
      }
      (**(code **)(*param_1 + 0x398))(param_1);
      return;
    }
  }
  uVar4 = *(undefined4 *)(param_2 + 0xc);
  uVar3 = *(undefined2 *)(param_2 + 6);
  uVar2 = *(undefined1 *)(param_2 + 5);
  if ((param_1[0xed0] != 0) || (bVar1 != 0x59)) {
    FUN_0002b8e2(local_24);
    local_14 = 0;
    local_20 = bVar1;
    local_1f = uVar2;
    local_1e = uVar3;
    local_18 = uVar4;
    FUN_0002ba10(param_1 + 0xe2e,local_24);
    HoldData_c_vslot_0(local_24);
  }
  return;
}

