/* 00025a06 FUN_00025a06 */

void FUN_00025a06(int *param_1,int *param_2,int param_3,int param_4,int *param_5)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  int local_10;
  
  if ((((param_1[0x13] != 0) && (param_2 != (int *)0x0)) && (param_3 != 0)) &&
     (param_5 != (int *)0x0)) {
    if (0 < param_4) {
      local_10 = 0;
      do {
        iVar2 = *(int *)(param_3 + local_10 * 4);
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        iVar3 = param_1[0x9615];
        if (iVar2 <= param_1[0x9615]) {
          iVar3 = iVar2;
        }
        param_1[iVar3 * 3 + 0x8215] = (int)param_2;
        pcVar1 = *(code **)(*param_2 + 0xd0);
        lVar4 = (longdouble)FUN_0001d22e(param_1[0x13],param_1[iVar3 + 0x9115]);
        (*pcVar1)(param_1[iVar3 * 3 + 0x8215],(float)lVar4);
        (**(code **)(*(int *)param_1[iVar3 * 3 + 0x8215] + 0x108))
                  ((int *)param_1[iVar3 * 3 + 0x8215],local_10,iVar3);
        (**(code **)(*param_1 + 0x94))(param_1,iVar3);
        local_10 = local_10 + 1;
      } while (param_4 != local_10);
    }
                    /* WARNING: Could not recover jumptable at 0x00025b36. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_5 + 0xac))();
    return;
  }
  return;
}

