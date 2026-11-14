/* 0003a358 WaveRAM_c_vslot_30 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void WaveRAM_c_vslot_30(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  longdouble lVar7;
  char local_29c [320];
  char local_15c [332];
  
  if (param_1[0x48] == 0) {
    return;
  }
  if (param_2 < 0) {
    return;
  }
  if (0 < param_2) {
    return;
  }
  if ((param_3 == -1) || (param_3 == 3)) {
    FUN_00012482(param_1[0x48],param_2,3,local_15c);
    piVar1 = param_1 + param_2 * 0x9d + 0x79;
    cVar3 = FUN_0002ddaa(param_1 + param_2 * 0x9d + 0xee);
    if (param_1[param_2 * 0x9d + 0x100] != 0) {
      FUN_000aecdc(piVar1);
      param_1[param_2 * 0x9d + 0x100] = 0;
      param_1[param_2 * 0x9d + 0x101] = 0;
      param_1[0x77] = param_1[0x77] + -1;
    }
    if (cVar3 != '\0') {
      FUN_0002ddc8(param_1 + param_2 * 0x9d + 0xee);
    }
    if (((char)param_1[0x78] != '\0') && (local_15c[0] != '\0')) {
      _strcpy(local_29c,local_15c);
      FUN_00012432(param_1[0x48],param_2,3,local_29c);
      cVar3 = FUN_00039ed0(param_1,param_2,local_29c);
      if (cVar3 == '\0') {
        FUN_0002e53a(param_1 + 0x5a,"File Error - Load failed",local_15c);
      }
      else {
        if (((param_1[0x48] == 0) || (iVar5 = FUN_00011b72(param_1[0x48],0), iVar5 == 0)) ||
           (param_1[0x100] == 0)) {
          iVar5 = 0;
        }
        else {
          iVar5 = (int)((float)(param_1[0x104] + -1) * *(float *)(iVar5 + 0x77c) * 0.01 + 0.25);
        }
        FUN_000af6ec(piVar1,iVar5);
        if (((param_1[0x48] == 0) || (iVar5 = FUN_00011b72(param_1[0x48],0), iVar5 == 0)) ||
           (param_1[0x100] == 0)) {
          iVar5 = 0;
        }
        else {
          iVar5 = (int)((float)(param_1[0x104] + -1) * *(float *)(iVar5 + 0x7ec) * 0.01 + 0.25);
        }
        FUN_000af6fe(piVar1,iVar5);
        (**(code **)(*param_1 + 0x78))(param_1,param_2,0xb);
      }
    }
    if (param_3 != -1) goto LAB_0003a39f;
LAB_0003a4f5:
    iVar5 = FUN_000122c2(param_1[0x48],param_2,7);
    param_1[param_2 * 0x9d + 0x108] = iVar5;
    if ((param_3 != -1) && (param_3 != 7)) goto LAB_0003a3a9;
    if ((*(char *)((int)param_1 + 0x1e1) != '\0') && ((char)param_1[0x1bb] == '\0')) {
      *(undefined1 *)(param_1 + 0x1bb) = 1;
      pcVar2 = *(code **)(*param_1 + 0x24);
      uVar6 = (**(code **)(*param_1 + 0x30))(param_1,param_2,7);
      (*pcVar2)(param_1,param_2,8,uVar6);
      *(undefined1 *)(param_1 + 0x1bb) = 0;
    }
    if (param_3 != -1) goto LAB_0003a3a9;
LAB_0003a55e:
    iVar5 = FUN_000122c2(param_1[0x48],param_2,8);
    param_1[param_2 * 0x9d + 0x109] = iVar5;
    if ((param_3 != -1) && (param_3 != 8)) goto LAB_0003a3b3;
    if ((*(char *)((int)param_1 + 0x1e1) != '\0') && ((char)param_1[0x1bb] == '\0')) {
      *(undefined1 *)(param_1 + 0x1bb) = 1;
      pcVar2 = *(code **)(*param_1 + 0x24);
      uVar6 = (**(code **)(*param_1 + 0x30))(param_1,param_2,8);
      (*pcVar2)(param_1,param_2,7,uVar6);
      *(undefined1 *)(param_1 + 0x1bb) = 0;
    }
    if (param_3 != -1) goto LAB_0003a3b3;
LAB_0003a5c7:
    iVar5 = FUN_000122c2(param_1[0x48],param_2,9);
    param_1[param_2 * 0x9d + 0x10a] = iVar5;
    if (param_3 != -1) goto LAB_0003a3bd;
LAB_0003a607:
    iVar5 = FUN_000122c2(param_1[0x48],param_2,10);
    param_1[param_2 * 0x9d + 0x10b] = iVar5;
    if (param_3 != -1) goto LAB_0003a3c7;
LAB_0003a647:
    iVar5 = FUN_000122c2(param_1[0x48],param_2,0x11);
    iVar4 = FUN_000122c2(param_1[0x48],param_2,0x12);
    if (iVar4 + -10 < iVar5) {
      FUN_00012222(param_1[0x48],param_2,0x11,iVar4 + -10);
    }
    if (((param_1[0x48] == 0) || (iVar5 = FUN_00011b72(param_1[0x48],0), iVar5 == 0)) ||
       (param_1[0x100] == 0)) {
      iVar5 = 0;
    }
    else {
      iVar5 = (int)((float)(param_1[0x104] + -1) * *(float *)(iVar5 + 0x77c) * 0.01 + 0.25);
    }
    FUN_000af6ec(param_1 + param_2 * 0x9d + 0x79,iVar5);
    if (((param_1[0x48] == 0) || (iVar5 = FUN_00011b72(param_1[0x48],0), iVar5 == 0)) ||
       (param_1[0x100] == 0)) {
      iVar5 = 0;
    }
    else {
      iVar5 = (int)((float)(param_1[0x104] + -1) * *(float *)(iVar5 + 0x7ec) * 0.01 + 0.25);
    }
    FUN_000af6fe(param_1 + param_2 * 0x9d + 0x79,iVar5);
    if (param_3 != -1) goto LAB_0003a3d1;
LAB_0003a78f:
    iVar5 = FUN_000122c2(param_1[0x48],param_2,0x11);
    iVar4 = FUN_000122c2(param_1[0x48],param_2,0x12);
    if (iVar4 + -10 < iVar5) {
      FUN_00012222(param_1[0x48],param_2,0x12,iVar5 + 10);
    }
    if (((param_1[0x48] == 0) || (iVar5 = FUN_00011b72(param_1[0x48],0), iVar5 == 0)) ||
       (param_1[0x100] == 0)) {
      iVar5 = 0;
    }
    else {
      iVar5 = (int)((float)(param_1[0x104] + -1) * *(float *)(iVar5 + 0x77c) * 0.01 + 0.25);
    }
    FUN_000af6ec(param_1 + param_2 * 0x9d + 0x79,iVar5);
    if (((param_1[0x48] == 0) || (iVar5 = FUN_00011b72(param_1[0x48],0), iVar5 == 0)) ||
       (param_1[0x100] == 0)) {
      iVar5 = 0;
    }
    else {
      iVar5 = (int)((float)(param_1[0x104] + -1) * *(float *)(iVar5 + 0x7ec) * 0.01 + 0.25);
    }
    FUN_000af6fe(param_1 + param_2 * 0x9d + 0x79,iVar5);
    if (param_3 != -1) goto LAB_0003a3db;
LAB_0003a8d7:
    lVar7 = (longdouble)FUN_000123ec(param_1[0x48],param_2,5);
    param_1[param_2 * 0x9d + 0x110] = (int)(float)lVar7;
    if (param_3 != -1) goto LAB_0003a3e5;
  }
  else {
LAB_0003a39f:
    if (param_3 == 7) goto LAB_0003a4f5;
LAB_0003a3a9:
    if (param_3 == 8) goto LAB_0003a55e;
LAB_0003a3b3:
    if (param_3 == 9) goto LAB_0003a5c7;
LAB_0003a3bd:
    if (param_3 == 10) goto LAB_0003a607;
LAB_0003a3c7:
    if (param_3 == 0x11) goto LAB_0003a647;
LAB_0003a3d1:
    if (param_3 == 0x12) goto LAB_0003a78f;
LAB_0003a3db:
    if (param_3 == 5) goto LAB_0003a8d7;
LAB_0003a3e5:
    if (param_3 != 0xb) goto LAB_0003a3ef;
  }
  cVar3 = FUN_0002ddaa(param_1 + param_2 * 0x9d + 0xee);
  if (cVar3 != '\0') {
    iVar5 = FUN_000122c2(param_1[0x48],param_2,0xb);
    FUN_000af164(param_1 + param_2 * 0x9d + 0x79,iVar5 != 0);
    FUN_0002ddc8(param_1 + param_2 * 0x9d + 0xee);
  }
LAB_0003a3ef:
  if (param_3 == 0xe) {
    FUN_00012482(param_1[0x48],param_2,0xe,local_29c);
    if (local_29c[0] != '\0') {
      FUN_00012432(param_1[0x48],param_2,3,local_29c);
      (**(code **)(*param_1 + 0x78))(param_1,param_2,3);
      (**(code **)(*param_1 + 0x78))(param_1,param_2,0xb);
    }
  }
  else if (param_3 == 0x10) {
    cVar3 = FUN_0002e50e(param_1 + 0x5a,"Clear Sample","Do you want to unload the sample ?");
    if (cVar3 != '\0') {
      FUN_00012432(param_1[0x48],param_2,3,"");
      (**(code **)(*param_1 + 0x78))(param_1,param_2,3);
    }
  }
  else if (param_3 == 0xd) {
    FUN_0003a05c(param_1,0,param_2);
  }
  else if (param_3 == 0xf) {
    FUN_0003a05c(param_1,1,param_2);
  }
  return;
}

