/* 000c538e FUN_000c538e */

void FUN_000c538e(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,code *param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  char cVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  undefined4 *local_e0;
  int local_dc;
  int local_d8;
  
  iVar11 = (int)param_2 - (int)param_1 >> 5;
  if (1 < iVar11) {
    iVar12 = (iVar11 + -2) / 2;
    puVar10 = param_1 + iVar12 * 8;
    local_d8 = 0;
    while( true ) {
      FUN_000c4d08(param_1,iVar12 - local_d8,iVar11,*puVar10,puVar10[1],puVar10[2],puVar10[3],
                   puVar10[4],puVar10[5],puVar10[6],puVar10[7],param_4);
      puVar10 = puVar10 + -8;
      if (local_d8 == iVar12) break;
      local_d8 = local_d8 + 1;
    }
  }
  if (param_2 < param_3) {
    local_e0 = param_2;
    do {
      while (cVar9 = (*param_4)(local_e0,param_1), cVar9 == '\0') {
        local_e0 = local_e0 + 8;
        if (param_3 <= local_e0) goto LAB_000c54d3;
      }
      uVar1 = *local_e0;
      uVar2 = local_e0[1];
      uVar3 = local_e0[2];
      uVar4 = local_e0[3];
      uVar5 = local_e0[4];
      uVar6 = local_e0[5];
      uVar7 = local_e0[6];
      uVar8 = local_e0[7];
      *local_e0 = *param_1;
      local_e0[1] = param_1[1];
      local_e0[2] = param_1[2];
      local_e0[3] = param_1[3];
      local_e0[4] = param_1[4];
      local_e0[5] = param_1[5];
      local_e0[6] = param_1[6];
      local_e0[7] = param_1[7];
      FUN_000c4d08(param_1,0,(int)param_2 - (int)param_1 >> 5,uVar1,uVar2,uVar3,uVar4,uVar5,uVar6,
                   uVar7,uVar8,param_4);
      local_e0 = local_e0 + 8;
    } while (local_e0 < param_3);
  }
LAB_000c54d3:
  local_dc = (int)param_2 - (int)param_1;
  while (1 < local_dc >> 5) {
    local_dc = local_dc + -0x20;
    uVar1 = param_2[-8];
    uVar2 = param_2[-7];
    uVar3 = param_2[-6];
    uVar4 = param_2[-5];
    uVar5 = param_2[-4];
    uVar6 = param_2[-3];
    uVar7 = param_2[-2];
    uVar8 = param_2[-1];
    param_2[-8] = *param_1;
    param_2[-7] = param_1[1];
    param_2[-6] = param_1[2];
    param_2[-5] = param_1[3];
    param_2[-4] = param_1[4];
    param_2[-3] = param_1[5];
    param_2[-2] = param_1[6];
    param_2[-1] = param_1[7];
    FUN_000c4d08(param_1,0,(int)(param_2 + -8) - (int)param_1 >> 5,uVar1,uVar2,uVar3,uVar4,uVar5,
                 uVar6,uVar7,uVar8,param_4);
    param_2 = param_2 + -8;
  }
  return;
}

