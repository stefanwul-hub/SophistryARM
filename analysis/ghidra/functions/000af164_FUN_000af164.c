/* 000af164 FUN_000af164 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000af164(int param_1,char param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (*(char *)(param_1 + 600) != param_2) {
    iVar5 = *(int *)(param_1 + 0x21c);
    if (iVar5 != 0) {
      iVar4 = *(int *)(param_1 + 0x22c);
      fVar2 = *(float *)(iVar5 + -4 + iVar4 * 4);
      iVar6 = iVar4 + -2;
      if (-1 < iVar6) {
        iVar4 = iVar6 * 4;
        iVar7 = 0;
        while( true ) {
          pfVar1 = (float *)(iVar5 + iVar7 * 4);
          fVar3 = *pfVar1;
          *pfVar1 = fVar2 - *(float *)(iVar5 + iVar4);
          *(float *)(*(int *)(param_1 + 0x21c) + iVar4) = fVar2 - fVar3;
          iVar6 = iVar6 + -1;
          iVar7 = iVar7 + 1;
          iVar4 = iVar4 + -4;
          if (iVar6 < iVar7) break;
          iVar5 = *(int *)(param_1 + 0x21c);
        }
        iVar5 = *(int *)(param_1 + 0x21c);
        iVar4 = *(int *)(param_1 + 0x22c);
      }
      *(float *)(iVar5 + -4 + iVar4 * 4) = fVar2 + 0.0;
    }
    iVar5 = *(int *)(param_1 + 0x220);
    if (iVar5 != 0) {
      iVar4 = *(int *)(param_1 + 0x22c);
      fVar2 = *(float *)(iVar5 + -4 + iVar4 * 4);
      iVar6 = iVar4 + -2;
      if (-1 < iVar6) {
        iVar4 = iVar6 * 4;
        iVar7 = 0;
        while( true ) {
          pfVar1 = (float *)(iVar5 + iVar7 * 4);
          fVar3 = *pfVar1;
          *pfVar1 = fVar2 - *(float *)(iVar5 + iVar4);
          *(float *)(*(int *)(param_1 + 0x220) + iVar4) = fVar2 - fVar3;
          iVar6 = iVar6 + -1;
          iVar7 = iVar7 + 1;
          iVar4 = iVar4 + -4;
          if (iVar6 < iVar7) break;
          iVar5 = *(int *)(param_1 + 0x220);
        }
        iVar4 = *(int *)(param_1 + 0x22c);
        iVar5 = *(int *)(param_1 + 0x220);
      }
      *(float *)(iVar5 + -4 + iVar4 * 4) = fVar2 + 0.0;
    }
    *(char *)(param_1 + 600) = param_2;
  }
  return;
}

