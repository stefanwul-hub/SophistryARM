/* 0008d9dc FUN_0008d9dc */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0008d9dc(undefined4 param_1,int param_2,int param_3,float param_4,int param_5,int param_6,
                 float param_7,float *param_8,int param_9)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  
  if (((((0 < param_3) && (0 < param_6)) && (0 < param_9)) && ((param_2 != 0 && (param_5 != 0)))) &&
     (param_8 != (float *)0x0)) {
    fVar2 = ((float)(param_3 + -1) * 0.9999) / (float)(param_9 + -1);
    fVar3 = ((float)(param_6 + -1) * 0.9999) / (float)(param_9 + -1);
    fVar4 = 0.0;
    fVar1 = 0.0;
    iVar7 = 0;
    do {
      while( true ) {
        iVar5 = (int)fVar1;
        iVar6 = (int)fVar4;
        if ((iVar5 + 1 < param_3) && (iVar6 + 1 < param_6)) break;
        *param_8 = 0.0;
        fVar1 = fVar1 + fVar2;
        fVar4 = fVar4 + fVar3;
        iVar7 = iVar7 + 1;
        param_8 = param_8 + 1;
        if (param_9 == iVar7) {
          return;
        }
      }
      fVar8 = (*(float *)(param_5 + iVar5 * 4) * (1.0 - (fVar1 - (float)iVar5)) +
              (fVar1 - (float)iVar5) * *(float *)(param_5 + 4 + iVar5 * 4)) * param_4 +
              (*(float *)(param_2 + iVar6 * 4) * (1.0 - (fVar4 - (float)iVar6)) +
              (fVar4 - (float)iVar6) * *(float *)(param_2 + 4 + iVar6 * 4)) * param_7;
      *param_8 = fVar8;
      fVar8 = (float)(~-(uint)(-1.0 <= fVar8) & (uint)-1.0 | (uint)fVar8 & -(uint)(-1.0 <= fVar8));
      *param_8 = fVar8;
      if (1.0 < fVar8) {
        *param_8 = 1.0;
      }
      fVar1 = fVar1 + fVar2;
      fVar4 = fVar4 + fVar3;
      iVar7 = iVar7 + 1;
      param_8 = param_8 + 1;
    } while (param_9 != iVar7);
  }
  return;
}

