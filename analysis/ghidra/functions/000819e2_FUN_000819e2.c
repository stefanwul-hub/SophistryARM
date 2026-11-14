/* 000819e2 FUN_000819e2 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000819e2(int param_1,undefined4 param_2,int *param_3,float param_4,undefined4 param_5)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  longdouble lVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float local_4c;
  float local_44;
  float local_40;
  int local_24;
  int local_20;
  
  fVar6 = (float)(~param_3[1] + param_3[3]) * 0.5;
  fVar8 = (float)param_3[1] + fVar6;
  fVar6 = fVar6 - 1.0;
  lVar4 = (longdouble)FUN_00001ace(param_1,5);
  if ((float)lVar4 <= 0.0) {
    local_4c = 0.0;
    lVar4 = (longdouble)FUN_00001ace(param_1,5);
  }
  else {
    local_4c = **(float **)(param_1 + 0xd4);
    lVar4 = (longdouble)FUN_00001ace(param_1,5);
  }
  if ((float)lVar4 <= 0.0) {
    fVar7 = 0.0;
  }
  else {
    fVar7 = **(float **)(param_1 + 0xd0);
  }
  lVar4 = (longdouble)FUN_000152c0(param_5,(float)*(int *)(param_1 + 0xb0));
  if (0 < *(int *)(param_1 + 0xb0)) {
    local_44 = param_4;
    uVar3 = 0;
    while( true ) {
      fVar1 = *(float *)(*(int *)(param_1 + 0xd4) + uVar3 * 4);
      fVar2 = *(float *)(*(int *)(param_1 + 0xd0) + uVar3 * 4);
      uVar5 = -(uint)(local_4c < fVar2);
      fVar2 = (float)(~uVar5 & (uint)local_4c | (uint)fVar2 & uVar5);
      uVar5 = -(uint)(fVar1 < fVar7);
      fVar7 = (float)(~uVar5 & (uint)fVar7 | (uint)fVar1 & uVar5);
      local_40 = -1.0;
      if ((-1.0 <= fVar7) && (local_40 = 1.0, fVar7 <= 1.0)) {
        local_40 = fVar7;
      }
      fVar7 = -1.0;
      if ((-1.0 <= fVar2) && (fVar7 = 1.0, fVar2 <= 1.0)) {
        fVar7 = fVar2;
      }
      FUN_000818cc(param_1,local_44,param_1 + 0x88);
      FUN_0009f51a(param_2,*(undefined4 *)(param_1 + 0x88));
      if ((uVar3 & 1) != 0) {
        local_24 = uVar3 + *param_3;
        local_20 = (int)fVar8;
        FUN_000a0df0(param_2,&local_24,*(undefined4 *)(param_1 + 0x88));
      }
      FUN_00001c3c(param_1,param_2,uVar3 + *param_3,(int)(fVar8 - local_40 * fVar6),
                   (int)(fVar8 - fVar7 * fVar6));
      local_44 = local_44 + (float)lVar4;
      uVar3 = uVar3 + 1;
      if (*(int *)(param_1 + 0xb0) <= (int)uVar3) break;
      local_4c = local_40;
    }
  }
  return;
}

