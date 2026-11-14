/* 00072de8 CXYPl_vslot_7 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CXYPl_vslot_7(int *param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int local_24;
  int local_20;
  
  local_24 = 0;
  local_20 = 0;
  FUN_00001bd4(param_1);
  *(undefined1 *)(param_1 + 0x1b) = 0;
  *(undefined1 *)((int)param_1 + 0x6d) = 0;
  FUN_00001ca6(param_1,*(undefined4 *)param_1[0x24]);
  FUN_00001ca6(param_1,*(undefined4 *)(param_1[0x24] + 0x18));
  uVar3 = FUN_0009cba2(param_2);
  (**(code **)(*param_1 + 0x84))(param_1,param_2,&local_24);
  param_1[0x27] = local_24;
  param_1[0x28] = local_20;
  fVar1 = *(float *)(param_1[0x24] + 0xc);
  *(float *)(param_1[0x24] + 4) = fVar1;
  fVar2 = *(float *)(param_1[0x24] + 0x24);
  *(float *)(param_1[0x24] + 0x1c) = fVar2;
  do {
    if ((uVar3 & 5) == 0) {
      FUN_00001c10(param_1,*(undefined4 *)param_1[0x24]);
      FUN_00001c10(param_1,*(undefined4 *)(param_1[0x24] + 0x18));
      return;
    }
    fVar6 = (float)(local_24 - param_1[0x27]) * 0.006666 + fVar1;
    fVar7 = (float)(param_1[0x28] - local_20) * 0.006666 + fVar2;
    if (fVar6 < 0.0) {
      fVar5 = 0.0;
      if (0.0 <= fVar7) goto LAB_00072f8b;
LAB_00072ec4:
      fVar6 = 0.0;
    }
    else {
      fVar5 = 1.0;
      if (fVar6 <= 1.0) {
        fVar5 = fVar6;
      }
      if (fVar7 < 0.0) goto LAB_00072ec4;
LAB_00072f8b:
      fVar6 = 1.0;
      if (fVar7 <= 1.0) {
        fVar6 = fVar7;
      }
    }
    iVar4 = param_1[0x24];
    if (fVar5 != *(float *)(iVar4 + 4)) {
      FUN_00001b2e(param_1,param_2,0,fVar5);
      iVar4 = param_1[0x24];
    }
    if (fVar6 != *(float *)(iVar4 + 0x1c)) {
      FUN_00001b2e(param_1,param_2,1,fVar6);
    }
    (**(code **)(*param_1 + 0xac))(param_1);
    uVar3 = FUN_0009cba2(param_2);
    (**(code **)(*param_1 + 0x84))(param_1,param_2,&local_24);
  } while( true );
}

