/* 000884a6 DelayPingPongR_c_vslot_56 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void DelayPingPongR_c_vslot_56(int *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  float *pfVar8;
  
  if ((char)param_1[0x57] == '\0') {
    return;
  }
  (**(code **)(*(int *)param_1[0x46] + 0x2c))((int *)param_1[0x46],param_1 + 0x82,param_1 + 0x83);
  (**(code **)(*(int *)param_1[4] + 0x38))((int *)param_1[4],param_1 + 0x84,param_1 + 0x85);
  param_2 = param_2 + 1;
  while (param_2 = param_2 + -1, 0 < param_2) {
    while( true ) {
      fVar1 = *(float *)param_1[0x84];
      param_1[0x84] = (int)((float *)param_1[0x84] + 1);
      fVar2 = *(float *)param_1[0x85];
      param_1[0x85] = (int)((float *)param_1[0x85] + 1);
      pfVar8 = (float *)(param_1[0x78] * 4 + param_1[0x7b]);
      fVar3 = *pfVar8;
      fVar4 = *(float *)(param_1[0x78] * 4 + param_1[0x7c]);
      *pfVar8 = fVar1;
      *(float *)(param_1[0x7c] + param_1[0x78] * 4) = fVar2;
      pfVar8 = (float *)(param_1[0x7d] + param_1[0x79] * 4);
      fVar5 = *pfVar8;
      fVar6 = *(float *)(param_1[0x7f] + param_1[0x7a] * 4);
      *pfVar8 = (fVar3 + fVar4) * 0.5 + fVar6 * (float)param_1[0x8f];
      *(float *)(param_1[0x7f] + param_1[0x7a] * 4) = fVar5;
      (**(code **)(*param_1 + 0xcc))
                (param_1,param_1 + 0x82,
                 fVar1 + (fVar3 * (float)param_1[0x89] + fVar5 * (float)param_1[0x8a] +
                         fVar6 * (float)param_1[0x8d]) * (float)param_1[0x8e]);
      (**(code **)(*param_1 + 0xcc))
                (param_1,param_1 + 0x83,
                 fVar2 + (fVar4 * (float)param_1[0x89] + fVar6 * (float)param_1[0x8c] +
                         fVar5 * (float)param_1[0x8b]) * (float)param_1[0x8e]);
      iVar7 = param_1[0x78];
      param_1[0x78] = iVar7 + 1;
      if (param_1[0x86] < iVar7 + 1) {
        param_1[0x78] = 0;
      }
      iVar7 = param_1[0x79];
      param_1[0x79] = iVar7 + 1;
      if (param_1[0x87] < iVar7 + 1) {
        param_1[0x79] = 0;
      }
      iVar7 = param_1[0x7a];
      param_1[0x7a] = iVar7 + 1;
      if (iVar7 + 1 <= param_1[0x88]) break;
      param_1[0x7a] = 0;
      param_2 = param_2 + -1;
      if (param_2 < 1) goto LAB_0008870c;
    }
  }
LAB_0008870c:
                    /* WARNING: Could not recover jumptable at 0x00088721. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)param_1[0x46] + 0x44))();
  return;
}

