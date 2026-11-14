/* 000a81f0 FUN_000a81f0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int FUN_000a81f0(int *param_1,undefined4 param_2,uint param_3,int param_4,byte *param_5,uint param_6
                )

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  size_t sVar7;
  size_t sVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  bool bVar13;
  undefined8 uStack_6c;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 auStack_44 [4];
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  switch(param_2) {
  case 0:
    if (param_6 != 4) {
      return -0x2a63;
    }
    if (param_3 == 0) {
      iVar3 = (**(code **)(*param_1 + 0x78))(param_1,*(undefined4 *)param_5);
      return iVar3;
    }
    goto code_r0x000a87ee;
  case 1:
    if (param_6 < 0xc) {
      return -0x2a63;
    }
    iVar3 = (**(code **)(*param_1 + 100))(param_1,param_5);
    break;
  case 2:
    if (param_6 != 8) {
      return -0x2a63;
    }
    if (4 < param_3) goto code_r0x000a8994;
    piVar6 = (int *)param_1[param_3 * 5 + 10] + param_4;
    if ((int *)param_1[param_3 * 5 + 0xb] <= piVar6) {
      return -0x2a7d;
    }
    if (piVar6 < (int *)param_1[param_3 * 5 + 10]) {
      return -0x2a7d;
    }
    if (*piVar6 == 0) {
      return -0x2a7d;
    }
    iVar3 = (**(code **)(*param_1 + 0xb0))(param_1,param_3,param_4);
    uStack_64 = *(undefined4 *)(iVar3 + 8);
    uStack_60 = *(undefined4 *)(iVar3 + 0xc);
    uStack_5c = *(undefined4 *)(iVar3 + 0x10);
    uStack_58 = *(undefined4 *)(iVar3 + 0x14);
    uStack_54 = *(undefined4 *)(iVar3 + 0x18);
    uStack_50 = *(undefined4 *)(iVar3 + 0x1c);
    uStack_4c = *(undefined4 *)(iVar3 + 0x20);
    uStack_48 = *(undefined4 *)(iVar3 + 0x24);
    uStack_6c = *(undefined8 *)param_5;
    cVar2 = (**(code **)(*param_1 + 0xac))(param_1,param_3,param_4,&uStack_6c);
    if (cVar2 == '\0') {
      return -0x2a74;
    }
    cVar2 = FUN_000ae6e0(iVar3,&uStack_6c);
    if (cVar2 != '\0') {
      return 0;
    }
    cVar2 = FUN_000a6dba(param_1,param_3,param_4);
    if (cVar2 != '\0') {
      iVar3 = (**(code **)(*param_1 + 0xb4))(param_1,param_3,param_4,iVar3,&uStack_6c);
      return iVar3;
    }
    goto code_r0x000a856d;
  default:
    iVar3 = (**(code **)(*param_1 + 0x28))(param_1,param_2,param_3,param_4,param_5,param_6);
    if (iVar3 == 0) {
      FUN_000a67ae(param_1,param_2,param_3,param_4);
      return 0;
    }
    break;
  case 8:
    if (param_6 < 0x24) {
      return -0x2a63;
    }
    if (4 < param_3) goto code_r0x000a8994;
    piVar6 = (int *)param_1[param_3 * 5 + 10] + param_4;
    if ((int *)param_1[param_3 * 5 + 0xb] <= piVar6) {
      return -0x2a7d;
    }
    if (piVar6 < (int *)param_1[param_3 * 5 + 10]) {
      return -0x2a7d;
    }
    if (*piVar6 == 0) {
      return -0x2a7d;
    }
    puVar5 = auStack_44;
    for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    puVar5 = auStack_44;
    for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    auStack_44[0] = *(undefined4 *)param_5;
    auStack_44[1] = *(undefined4 *)(param_5 + 4);
    auStack_44[2] = *(undefined4 *)(param_5 + 8);
    auStack_44[3] = *(undefined4 *)(param_5 + 0xc);
    uStack_34 = *(undefined4 *)(param_5 + 0x10);
    uStack_30 = *(undefined4 *)(param_5 + 0x14);
    uStack_2c = *(undefined4 *)(param_5 + 0x18);
    uStack_28 = *(undefined4 *)(param_5 + 0x1c);
    uStack_24 = *(undefined4 *)(param_5 + 0x20);
    cVar2 = (**(code **)(*param_1 + 0xac))(param_1,param_3,param_4,auStack_44);
    if (cVar2 == '\0') {
      return -0x2a74;
    }
    puVar4 = (undefined8 *)(**(code **)(*param_1 + 0xb0))(param_1,param_3,param_4);
    uStack_6c = *puVar4;
    uStack_64 = *(undefined4 *)(puVar4 + 1);
    uStack_60 = *(undefined4 *)((int)puVar4 + 0xc);
    uStack_5c = *(undefined4 *)(puVar4 + 2);
    uStack_58 = *(undefined4 *)((int)puVar4 + 0x14);
    uStack_54 = *(undefined4 *)(puVar4 + 3);
    uStack_50 = *(undefined4 *)((int)puVar4 + 0x1c);
    uStack_4c = *(undefined4 *)(puVar4 + 4);
    uStack_48 = *(undefined4 *)((int)puVar4 + 0x24);
    cVar2 = FUN_000ae6e0(&uStack_6c,auStack_44);
    if (cVar2 != '\0') {
      return 0;
    }
    cVar2 = FUN_000a6dba(param_1,param_3,param_4);
    if (cVar2 != '\0') {
      iVar3 = (**(code **)(*param_1 + 0xb4))(param_1,param_3,param_4,&uStack_6c,auStack_44);
      return iVar3;
    }
    goto code_r0x000a856d;
  case 0xb:
    if (param_6 != 4) {
      return -0x2a63;
    }
    cVar2 = (**(code **)(*param_1 + 0x5c))(param_1,param_3);
    if (cVar2 != '\0') {
      iVar3 = (**(code **)(*param_1 + 0x60))(param_1,param_3,*(undefined4 *)param_5);
      if (iVar3 == 0) {
        FUN_000a67ae(param_1,0xb,param_3,param_4);
        return 0;
      }
      return iVar3;
    }
code_r0x000a856d:
    iVar3 = -0x2a71;
    break;
  case 0xe:
    if (param_6 != 4) {
      return -0x2a63;
    }
    iVar3 = (**(code **)(*param_1 + 0xc4))(param_1);
    if (iVar3 == 0) {
      (**(code **)(*param_1 + 0xc0))(param_1,*(undefined4 *)param_5);
    }
    break;
  case 0xf:
    if (param_6 < 8) {
      return -0x2a63;
    }
    if (*(char *)((int)param_1 + 0xd) == '\0') {
      return -0x2a73;
    }
    if ((*param_5 & 0xf) != 0) {
      return -0x32;
    }
    if (param_3 == 1) {
      piVar6 = (int *)param_1[0xf] + param_4;
      if ((piVar6 < (int *)param_1[0x10]) && ((int *)param_1[0xf] <= piVar6)) goto code_r0x000a89fd;
    }
    else {
      piVar6 = (int *)param_1[0x14] + param_4;
      if ((piVar6 < (int *)param_1[0x15]) && ((int *)param_1[0x14] <= piVar6)) {
code_r0x000a89fd:
        iVar3 = *piVar6;
        if (iVar3 != 0) {
          FUN_000ae1e6(iVar3 + 0x5c,iVar3 + 0x34,param_5);
          return 0;
        }
      }
    }
    puVar5 = (undefined4 *)___cxa_allocate_exception(4);
    *puVar5 = 0xffffd583;
    goto code_r0x000a89a6;
  case 0x13:
    if (param_6 < *(int *)(param_5 + 8) * 0x14 + 0xcU) {
      return -0x2a63;
    }
    iVar3 = (**(code **)(*param_1 + 0xcc))(param_1,param_3,param_4,param_5);
    if (iVar3 == 0) {
      FUN_000a67ae(param_1,0x13,param_3,param_4);
    }
    break;
  case 0x17:
    if (param_6 < 8) {
      return -0x2a63;
    }
    if (*(byte *)((int)param_1 + 0xe) < 2) {
      iVar3 = -0x2a7f;
    }
    else {
      iVar3 = (**(code **)(*param_1 + 0x68))
                        (param_1,0x17,param_4,*(undefined4 *)param_5,*(undefined4 *)(param_5 + 4));
    }
    break;
  case 0x19:
    if (param_6 != 4) {
      return -0x2a63;
    }
    if (param_3 == 0) {
      iVar3 = *(int *)param_5;
      if (param_1[0x36] != 0) {
        _CFRelease(param_1[0x36]);
      }
      if (iVar3 != 0) {
        _CFRetain(iVar3);
      }
      param_1[0x36] = iVar3;
      FUN_000a67ae(param_1,0x19,0,param_4);
      return 0;
    }
    goto code_r0x000a87ee;
  case 0x1b:
    if (param_3 == 0) {
      sVar8 = 0x10;
      if (param_6 < 0x11) {
        sVar8 = param_6;
      }
      bVar13 = true;
      sVar7 = sVar8;
      pbVar9 = (byte *)(param_1 + 0x32);
      pbVar11 = param_5;
      do {
        pbVar10 = pbVar9;
        pbVar12 = pbVar11;
        if (sVar7 == 0) break;
        sVar7 = sVar7 - 1;
        pbVar12 = pbVar11 + 1;
        pbVar10 = pbVar9 + 1;
        bVar13 = *pbVar9 == *pbVar11;
        pbVar9 = pbVar10;
        pbVar11 = pbVar12;
      } while (bVar13);
      iVar3 = 0;
      if (!bVar13) {
        iVar3 = (uint)pbVar10[-1] - (uint)pbVar12[-1];
      }
      param_1[0x32] = 0;
      param_1[0x33] = 0;
      param_1[0x34] = 0;
      param_1[0x35] = 0;
      _memcpy(param_1 + 0x32,param_5,sVar8);
      if (iVar3 != 0) {
        return 0;
      }
      FUN_000a67ae(param_1,0x1b,0,param_4);
      return 0;
    }
    goto code_r0x000a87ee;
  case 0x1c:
  case 0x24:
    if (param_6 != 8) {
      return -0x2a63;
    }
    if (param_3 == 0) {
      if (*(int *)param_5 < 0) {
        if (*(int *)(param_5 + 4) == 0) {
          return -0x2a63;
        }
        _CFRelease(param_1[0x2b]);
        iVar3 = *(int *)(param_5 + 4);
        param_1[0x2a] = *(int *)param_5;
        param_1[0x2b] = iVar3;
        _CFRetain(param_1[0x2b]);
        FUN_000a67ae(param_1,param_2,0,param_4);
        return 0;
      }
      iVar3 = (**(code **)(*param_1 + 0x84))(param_1,param_5);
      if (iVar3 == 0) {
        FUN_000a67ae(param_1,param_2,0,param_4);
        return 0;
      }
      return iVar3;
    }
code_r0x000a87ee:
    iVar3 = -0x2a72;
    break;
  case 0x1e:
    if (param_3 < 5) {
      piVar1 = (int *)param_1[param_3 * 5 + 10];
      piVar6 = piVar1 + param_4;
      if (((piVar6 < (int *)param_1[param_3 * 5 + 0xb]) && (piVar1 <= piVar6)) && (*piVar6 != 0)) {
        if (param_6 != 4) {
          return -0x2a63;
        }
        if ((piVar6 < (int *)param_1[param_3 * 5 + 0xb]) && (piVar1 <= piVar6)) {
          iVar3 = *piVar6;
        }
        else {
          iVar3 = 0;
        }
        FUN_000ab7bc(iVar3,*(undefined4 *)param_5);
        FUN_000a67ae(param_1,0x1e,param_3,param_4);
        return 0;
      }
      return -0x2a7d;
    }
code_r0x000a8994:
    puVar5 = (undefined4 *)___cxa_allocate_exception(4);
    *puVar5 = 0xffffd58e;
code_r0x000a89a6:
                    /* WARNING: Subroutine does not return */
    ___cxa_throw(puVar5,PTR_001037fc,0);
  }
  return iVar3;
}

