/* 00081cc0 FUN_00081cc0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00081cc0(int param_1,undefined4 param_2,float param_3,float param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  int local_34;
  int local_30;
  int local_24;
  int local_20;
  
  if (0.0 < param_4) {
    fVar5 = param_4 + param_3;
    lVar4 = (longdouble)FUN_00001ace(param_1,0);
    fVar6 = (float)lVar4 * *(float *)(param_1 + 0xe8);
    lVar4 = (longdouble)FUN_00001ace(param_1,1);
    fVar7 = (float)lVar4 * *(float *)(param_1 + 0xe8);
    lVar4 = (longdouble)FUN_00001ace(param_1,2);
    fVar8 = (float)lVar4 * *(float *)(param_1 + 0xe8);
    lVar4 = (longdouble)FUN_00001ace(param_1,3);
    fVar9 = (float)lVar4 * *(float *)(param_1 + 0xe8);
    fVar10 = (float)(*(int *)(param_1 + 0x10) - *(int *)(param_1 + 8));
    iVar3 = (int)(((fVar6 - param_3) / param_4) * fVar10 * 0.999);
    iVar1 = (int)(((fVar7 - param_3) / param_4) * fVar10 * 0.999);
    iVar2 = (int)(((fVar8 - param_3) / param_4) * fVar10 * 0.999);
    if ((param_3 <= fVar6) && (fVar6 <= fVar5)) {
      FUN_0009f51a(param_2,0xff08ff20);
      local_20 = *(int *)(param_1 + 0xc) + 3;
      local_24 = iVar3 + *(int *)(param_1 + 8);
      FUN_0009df12(param_2,&local_24);
      local_20 = *(int *)(param_1 + 0x14) + -1;
      local_24 = iVar3 + *(int *)(param_1 + 8);
      FUN_000a0cea(param_2,&local_24);
    }
    if ((param_3 <= fVar7) && (fVar7 <= fVar5)) {
      FUN_0009f51a(param_2,0xff0040ff);
      local_20 = *(int *)(param_1 + 0xc) + 3;
      local_24 = iVar1 + *(int *)(param_1 + 8);
      FUN_0009df12(param_2,&local_24);
      local_20 = *(int *)(param_1 + 0x14) + -1;
      local_24 = iVar1 + *(int *)(param_1 + 8);
      FUN_000a0cea(param_2,&local_24);
    }
    if ((param_3 <= fVar8) && (fVar8 <= fVar5)) {
      FUN_0009f51a(param_2,0xff4000a0);
      local_20 = *(int *)(param_1 + 0xc) + 3;
      local_24 = iVar2 + *(int *)(param_1 + 8);
      FUN_0009df12(param_2,&local_24);
      local_20 = *(int *)(param_1 + 0x14) + -1;
      local_24 = iVar2 + *(int *)(param_1 + 8);
      FUN_000a0cea(param_2,&local_24);
    }
    fVar11 = fVar7 - fVar9;
    fVar7 = fVar7 + fVar9;
    fVar6 = fVar11;
    if (fVar11 <= param_3) {
      fVar6 = param_3;
    }
    fVar12 = fVar7;
    if (fVar5 <= fVar7) {
      fVar12 = fVar5;
    }
    if ((fVar11 <= fVar5) && (param_3 <= fVar7)) {
      FUN_0009f51a(param_2,0xff0040ff);
      local_34 = (int)(((fVar6 - param_3) / param_4) * fVar10 * 0.999);
      iVar1 = (int)(((fVar12 - param_3) / param_4) * fVar10 * 0.999);
      iVar2 = (int)fVar10 + -1;
      if (local_34 < 0) {
        local_34 = 0;
      }
      else if (iVar2 < local_34) {
        local_34 = iVar2;
      }
      if (iVar1 < 0) {
        iVar1 = 0;
      }
      else if (iVar2 < iVar1) {
        iVar1 = iVar2;
      }
      local_20 = *(int *)(param_1 + 0xc) + 3;
      local_24 = local_34 + *(int *)(param_1 + 8);
      FUN_0009df12(param_2,&local_24);
      local_20 = *(int *)(param_1 + 0xc) + 3;
      local_24 = iVar1 + *(int *)(param_1 + 8);
      FUN_000a0cea(param_2,&local_24);
      local_20 = *(int *)(param_1 + 0xc) + 7;
      local_24 = iVar1 + *(int *)(param_1 + 8);
      FUN_000a0cea(param_2,&local_24);
      local_20 = *(int *)(param_1 + 0xc) + 7;
      local_24 = local_34 + *(int *)(param_1 + 8);
      FUN_000a0cea(param_2,&local_24);
      local_20 = *(int *)(param_1 + 0xc) + 3;
      local_24 = local_34 + *(int *)(param_1 + 8);
      FUN_000a0cea(param_2,&local_24);
    }
    fVar7 = fVar8 - fVar9;
    fVar8 = fVar8 + fVar9;
    fVar6 = fVar7;
    if (fVar7 <= param_3) {
      fVar6 = param_3;
    }
    fVar9 = fVar8;
    if (fVar5 <= fVar8) {
      fVar9 = fVar5;
    }
    if ((fVar7 <= fVar5) && (param_3 <= fVar8)) {
      FUN_0009f51a(param_2,0xff4000a0);
      local_30 = (int)(((fVar6 - param_3) / param_4) * fVar10 * 0.999);
      iVar1 = (int)(((fVar9 - param_3) / param_4) * fVar10 * 0.999);
      iVar2 = (int)fVar10 + -1;
      if (local_30 < 0) {
        local_30 = 0;
      }
      else if (iVar2 < local_30) {
        local_30 = iVar2;
      }
      if (iVar1 < 0) {
        iVar1 = 0;
      }
      else if (iVar2 < iVar1) {
        iVar1 = iVar2;
      }
      local_20 = *(int *)(param_1 + 0xc) + 3;
      local_24 = local_30 + *(int *)(param_1 + 8);
      FUN_0009df12(param_2,&local_24);
      local_20 = *(int *)(param_1 + 0xc) + 3;
      local_24 = iVar1 + *(int *)(param_1 + 8);
      FUN_000a0cea(param_2,&local_24);
      local_20 = *(int *)(param_1 + 0xc) + 7;
      local_24 = iVar1 + *(int *)(param_1 + 8);
      FUN_000a0cea(param_2,&local_24);
      local_20 = *(int *)(param_1 + 0xc) + 7;
      local_24 = local_30 + *(int *)(param_1 + 8);
      FUN_000a0cea(param_2,&local_24);
      local_20 = *(int *)(param_1 + 0xc) + 3;
      local_24 = local_30 + *(int *)(param_1 + 8);
      FUN_000a0cea(param_2,&local_24);
      return;
    }
  }
  return;
}

