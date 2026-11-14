/* 00026c9e FUN_00026c9e */

void FUN_00026c9e(int *param_1,int *param_2,undefined4 param_3,int param_4,int param_5,int param_6,
                 int param_7,undefined1 param_8,char param_9,undefined1 param_10)

{
  code *pcVar1;
  int *piVar2;
  longdouble lVar3;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  if (param_5 < 0) {
    param_5 = 0;
  }
  else if (0x500 < param_5) {
    param_5 = 0x500;
  }
  if (param_4 != 0) {
    local_10 = param_7 + *(int *)(param_4 + 0x10);
    local_14 = param_6 + *(int *)(param_4 + 0xc);
    local_1c = param_6;
    local_18 = param_7;
    piVar2 = (int *)operator_new(0xdb0);
    FUN_00007296(piVar2,&local_1c,param_1 + 8,param_5,param_1[0x13],param_3,param_10,param_4,0,
                 ~-(uint)(param_9 == '\0') & 0x400,param_8);
    if (((piVar2 != (int *)0x0) && (param_1[0x13] != 0)) && (param_2 != (int *)0x0)) {
      param_1[param_5 * 3 + 0x8216] = (int)piVar2;
      pcVar1 = *(code **)(*piVar2 + 0xd0);
      lVar3 = (longdouble)FUN_0001d22e(param_1[0x13],param_1[param_5 + 0x9115]);
      (*pcVar1)(param_1[param_5 * 3 + 0x8216],(float)lVar3);
      param_1[param_5 * 3 + 0x8217] = 9;
      (**(code **)(*param_1 + 0x94))(param_1,param_5);
      (**(code **)(*param_2 + 0xac))(param_2,param_1[param_5 * 3 + 0x8216]);
    }
  }
  return;
}

