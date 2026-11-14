/* 000c4ef4 FUN_000c4ef4 */

void FUN_000c4ef4(undefined4 *param_1,undefined4 *param_2,code *param_3)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  if ((param_2 != param_1) && (puVar6 = param_1 + 8, param_2 != puVar6)) {
    while( true ) {
      local_4c = *puVar6;
      local_48 = puVar6[1];
      local_44 = puVar6[2];
      local_40 = puVar6[3];
      local_3c = puVar6[4];
      local_38 = puVar6[5];
      local_34 = puVar6[6];
      local_30 = puVar6[7];
      cVar1 = (*param_3)(&local_4c,param_1);
      if (cVar1 == '\0') {
        local_2c = local_4c;
        local_28 = local_48;
        local_24 = local_44;
        local_20 = local_40;
        local_1c = local_3c;
        local_18 = local_38;
        local_14 = local_34;
        local_10 = local_30;
        FUN_000c4e64(puVar6,local_4c,local_48,local_44,local_40,local_3c,local_38,local_34,local_30,
                     param_3);
      }
      else {
        puVar4 = puVar6 + 8;
        iVar3 = (int)puVar6 - (int)param_1 >> 5;
        if (0 < iVar3) {
          iVar5 = 0;
          puVar2 = puVar6;
          do {
            puVar4[-8] = puVar2[-8];
            puVar4[-7] = puVar2[-7];
            puVar4[-6] = puVar2[-6];
            puVar4[-5] = puVar2[-5];
            puVar4[-4] = puVar2[-4];
            puVar4[-3] = puVar2[-3];
            puVar4[-2] = puVar2[-2];
            puVar4[-1] = puVar2[-1];
            iVar5 = iVar5 + 1;
            puVar2 = puVar2 + -8;
            puVar4 = puVar4 + -8;
          } while (iVar3 != iVar5);
        }
        *param_1 = local_4c;
        param_1[1] = local_48;
        param_1[2] = local_44;
        param_1[3] = local_40;
        param_1[4] = local_3c;
        param_1[5] = local_38;
        param_1[6] = local_34;
        param_1[7] = local_30;
      }
      if (param_2 == puVar6 + 8) break;
      puVar6 = puVar6 + 8;
    }
  }
  return;
}

