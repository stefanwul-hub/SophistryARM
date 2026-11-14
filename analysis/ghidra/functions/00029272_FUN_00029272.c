/* 00029272 FUN_00029272 */

void FUN_00029272(int *param_1,int *param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,char param_8,char param_9,undefined4 param_10)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  longdouble lVar4;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  if (((param_2 != (int *)0x0) && (param_5 != 0)) && (param_1[0x13] != 0)) {
    local_10 = *(short *)(param_5 + 0x10) + param_7;
    local_14 = *(short *)(param_5 + 0xc) + param_6;
    local_1c = param_6;
    local_18 = param_7;
    if (param_9 == '\0') {
      if (param_8 == '\0') {
        piVar3 = (int *)operator_new(0x140);
        FUN_000061da(piVar3,&local_1c,param_1 + 8,param_3,param_5,
                     param_4 * 0x574 + *(int *)(param_1[0x13] + 0x38f8),param_4,param_1[0x13],
                     param_10);
      }
      else {
        piVar3 = (int *)operator_new(0x140);
        FUN_000061da(piVar3,&local_1c,param_1 + 8,param_3,param_5,
                     param_4 * 0x574 + *(int *)(param_1[0x13] + 0x38f4),param_4,param_1[0x13],
                     param_10);
      }
    }
    else if (param_8 == '\0') {
      piVar3 = (int *)operator_new(0x140);
      FUN_000061da(piVar3,&local_1c,param_1 + 8,param_3,param_5,
                   *(undefined4 *)(param_1[0x13] + 0x38f0),0,param_1[0x13],param_10);
    }
    else {
      piVar3 = (int *)operator_new(0x140);
      FUN_000061da(piVar3,&local_1c,param_1 + 8,param_3,param_5,
                   *(undefined4 *)(param_1[0x13] + 0x38ec),0,param_1[0x13],param_10);
    }
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x100))(piVar3,3);
      (**(code **)(*piVar3 + 0x104))(piVar3,param_1[0xd]);
      param_1[param_3 * 3 + 0x8217] = 10;
      if (param_1[0x13] != 0) {
        if (param_3 < 0) {
          param_3 = 0;
          iVar2 = param_3;
        }
        else {
          iVar2 = 0x500;
          if (param_3 < 0x501) {
            iVar2 = param_3;
          }
        }
        param_3 = iVar2;
        param_1[param_3 * 3 + 0x8215] = 0;
        param_1[param_3 * 3 + 0x8216] = (int)piVar3;
        pcVar1 = *(code **)(*piVar3 + 0xd0);
        lVar4 = (longdouble)FUN_0001d22e(param_1[0x13],param_1[param_3 + 0x9115]);
        (*pcVar1)(param_1[param_3 * 3 + 0x8216],(float)lVar4);
        (**(code **)(*param_1 + 0x94))(param_1,param_3);
        (**(code **)(*param_2 + 0xac))(param_2,param_1[param_3 * 3 + 0x8216]);
      }
    }
  }
  return;
}

