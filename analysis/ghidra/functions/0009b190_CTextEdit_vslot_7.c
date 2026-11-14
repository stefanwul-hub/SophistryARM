/* 0009b190 CTextEdit_vslot_7 */

void CTextEdit_vslot_7(int *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  
  if (*(char *)((int)param_1 + 0x31) != '\0') {
    if (param_4 == 0xffffffff) {
      param_4 = FUN_0009cba2(param_2);
    }
    piVar1 = (int *)param_1[0xf];
    if ((((piVar1 == (int *)0x0) || ((param_4 & 0x78) == 0)) ||
        (iVar2 = (**(code **)(*piVar1 + 4))(piVar1,param_2,param_1,param_4), iVar2 == 0)) &&
       (((param_4 & 1) != 0 &&
        (piVar1 = (int *)(**(code **)(*(int *)param_1[10] + 0x140))((int *)param_1[10]),
        param_1 != piVar1)))) {
      if ((*(byte *)((int)param_1 + 0x81) & 0x20) != 0) {
        iVar2 = (**(code **)(*(int *)param_1[10] + 0x108))((int *)param_1[10]);
        if ((param_1[0x17] < 1) || (param_1[0x17] + param_1[0x18] <= iVar2)) {
          param_1[0x17] = iVar2;
          return;
        }
        param_1[0x17] = 0;
      }
      (**(code **)(*param_1 + 0xe0))(param_1);
                    /* WARNING: Could not recover jumptable at 0x0009b22b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_1 + 0x4c))();
      return;
    }
  }
  return;
}

