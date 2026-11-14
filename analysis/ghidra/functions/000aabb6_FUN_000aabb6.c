/* 000aabb6 FUN_000aabb6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

uint FUN_000aabb6(int param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  void *pvVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  void *pvVar11;
  void *pvStack_48;
  uint uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  undefined1 auStack_1d [13];
  
  if (param_2 == (int *)0x0) {
    return 0xffffffce;
  }
  switch(*(undefined2 *)(param_1 + 2)) {
  case 1:
    uVar9 = FUN_000a65d4(param_2);
    break;
  case 2:
    FUN_000a661e(param_2);
    uVar9 = 0;
    break;
  case 3:
    puVar6 = *(undefined4 **)(param_1 + 8);
    puVar7 = *(undefined1 **)(param_1 + 4);
    uVar9 = FUN_000aa1dc(param_2,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x10),
                         *(undefined4 *)(param_1 + 0xc),&uStack_24,auStack_1d);
    if (puVar6 != (undefined4 *)0x0) {
      *puVar6 = uStack_24;
    }
    if (puVar7 != (undefined1 *)0x0) {
      *puVar7 = auStack_1d[0];
    }
    break;
  case 4:
    uVar1 = *(undefined4 *)(param_1 + 0x14);
    uVar2 = *(undefined4 *)(param_1 + 0x10);
    uVar4 = *(undefined4 *)(param_1 + 0xc);
    pvVar5 = *(void **)(param_1 + 8);
    puVar10 = *(uint **)(param_1 + 4);
    if (puVar10 == (uint *)0x0) {
      return 0xffffffce;
    }
    if (pvVar5 == (void *)0x0) {
      uVar9 = FUN_000aa1dc(param_2,uVar1,uVar2,uVar4,&uStack_28,&uStack_24);
      *puVar10 = uStack_28;
    }
    else {
      uVar8 = *puVar10;
      if (uVar8 == 0) {
        return 0xffffffce;
      }
      uVar9 = FUN_000aa1dc(param_2,uVar1,uVar2,uVar4,&uStack_2c,auStack_1d);
      if (uVar9 == 0) {
        if (uVar8 < uStack_2c) {
          pvVar11 = operator_new__(uStack_2c);
          pvStack_48 = pvVar11;
        }
        else {
          pvStack_48 = (void *)0x0;
          pvVar11 = pvVar5;
        }
        uVar9 = FUN_000a983c(param_2,uVar1,uVar2,uVar4,pvVar11);
        if (uVar9 == 0) {
          if (uVar8 < uStack_2c) {
            _memcpy(pvVar5,pvStack_48,uVar8);
            if (pvStack_48 != (void *)0x0) {
              operator_delete__(pvStack_48);
            }
          }
          else {
            *puVar10 = uStack_2c;
          }
        }
        else {
          *puVar10 = 0;
        }
      }
    }
    break;
  case 5:
    iVar3 = *(int *)(param_1 + 4);
    if (*(int *)(param_1 + 8) == 0) {
      if (iVar3 != 0) {
        return 0xffffffce;
      }
      uVar9 = FUN_000a6816(param_2,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x10),
                           *(undefined4 *)(param_1 + 0xc));
    }
    else {
      if (iVar3 == 0) {
        return 0xffffffce;
      }
      uVar9 = FUN_000a81f0(param_2,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x10),
                           *(undefined4 *)(param_1 + 0xc),*(int *)(param_1 + 8),iVar3);
    }
    break;
  case 6:
    if (*(int *)(param_1 + 4) == 0) {
      return 0xffffffce;
    }
    uVar9 = (**(code **)(*param_2 + 0x40))
                      (param_2,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0xc),
                       *(undefined4 *)(param_1 + 8),*(int *)(param_1 + 4));
    break;
  case 7:
    uVar9 = (**(code **)(*param_2 + 0x44))
                      (param_2,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x10),
                       *(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 8),
                       *(undefined4 *)(param_1 + 4));
    break;
  case 9:
    uVar1 = *(undefined4 *)(param_1 + 8);
    uVar2 = *(undefined4 *)(param_1 + 4);
    param_2[0x26] = 0;
    param_2[0x27] = -0x40100000;
    uVar9 = (**(code **)(*param_2 + 0x1c))(param_2,uVar1,uVar2);
    break;
  case 10:
    uVar9 = (**(code **)(*param_2 + 0x30))
                      (param_2,*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 8),
                       *(undefined4 *)(param_1 + 4));
    break;
  case 0xb:
    uVar9 = (**(code **)(*param_2 + 0x34))
                      (param_2,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 4));
    break;
  case 0xe:
    puVar10 = *(uint **)(param_1 + 0x14);
    if (*(int *)(param_1 + 0x10) == 0) {
      return 0xffffffce;
    }
    if (*(int *)(param_1 + 4) == 0) {
      return 0xffffffce;
    }
    if (puVar10 == (uint *)0x0) {
      uStack_28 = 0;
      puVar10 = &uStack_28;
    }
    uVar9 = FUN_000a7014(param_2,puVar10,*(int *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0xc),
                         *(undefined4 *)(param_1 + 8),*(int *)(param_1 + 4));
    break;
  case 0xf:
    uVar9 = (**(code **)(*param_2 + 0x38))
                      (param_2,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 4));
    break;
  case 0x10:
    uVar9 = (**(code **)(*param_2 + 0x3c))
                      (param_2,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 4));
    break;
  case 0x11:
    if (*(byte *)((int)param_2 + 0xe) < 2) {
      uVar9 = 0x80008002;
    }
    else {
      uVar9 = (**(code **)(*param_2 + 0x50))
                        (param_2,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 4));
    }
    break;
  case 0xfffd:
    if (*(uint *)(param_1 + 4) < 0x12) {
      uVar9 = 1 << ((byte)*(undefined4 *)(param_1 + 4) & 0x1f);
      if ((uVar9 & 0xefe) != 0) {
        return 1;
      }
      if ((uVar9 & 0x3c000) != 0) {
        return (uint)(1 < *(byte *)((int)param_2 + 0xe));
      }
    }
  default:
    uVar9 = FUN_000ab74e(param_1,param_2);
  }
  return uVar9;
}

