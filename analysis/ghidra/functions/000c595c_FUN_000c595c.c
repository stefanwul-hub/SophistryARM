/* 000c595c FUN_000c595c */

void FUN_000c595c(undefined4 *param_1,int param_2,int param_3,code *param_4)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  int local_38;
  int local_34;
  int local_30;
  
  local_38 = param_2;
  if (param_2 - (int)param_1 >> 5 < 0x11) {
    return;
  }
  if (param_3 != 0) {
    local_30 = param_3;
    local_34 = 0;
    do {
      local_30 = local_30 + -1;
      puVar1 = param_1 + ((local_38 - (int)param_1 >> 5) - (local_38 - (int)param_1 >> 0x1f) >> 1) *
                         8;
      puVar4 = (undefined4 *)(local_38 + -0x20);
      cVar2 = (*param_4)(param_1,puVar1);
      if (cVar2 == '\0') {
        cVar2 = (*param_4)(param_1,puVar4);
        if (cVar2 == '\0') {
          cVar2 = (*param_4)(puVar1,puVar4);
          if (cVar2 != '\0') goto LAB_000c59f3;
          goto LAB_000c59f1;
        }
LAB_000c5ae7:
        puVar4 = param_1;
      }
      else {
        cVar2 = (*param_4)(puVar1,puVar4);
        if (cVar2 == '\0') {
          cVar2 = (*param_4)(param_1,puVar4);
          if (cVar2 == '\0') goto LAB_000c5ae7;
        }
        else {
LAB_000c59f1:
          puVar4 = puVar1;
        }
      }
LAB_000c59f3:
      iVar3 = FUN_000c520e(param_1,local_38,*puVar4,puVar4[1],puVar4[2],puVar4[3],puVar4[4],
                           puVar4[5],puVar4[6],puVar4[7],param_4);
      FUN_000c595c(iVar3,local_38,local_30,param_4);
      if (iVar3 - (int)param_1 >> 5 < 0x11) {
        return;
      }
      local_34 = local_34 + 1;
      local_38 = iVar3;
    } while (local_34 != param_3);
  }
  FUN_000c538e();
  return;
}

