/* 000266ca FUN_000266ca */

void FUN_000266ca(int *param_1,int *param_2,int param_3,int *param_4)

{
  code *pcVar1;
  longdouble lVar2;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  if ((param_1[0x13] != 0) && (param_2 != (int *)0x0)) {
    if (param_3 < 0) {
      param_3 = 0;
    }
    else if (0x500 < param_3) {
      param_3 = 0x500;
    }
    if (param_4 != (int *)0x0) {
      local_1c = 0;
      local_18 = 0;
      local_14 = 0;
      local_10 = 0;
      local_2c = 0;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      (**(code **)(*param_4 + 0x78))(param_4,&local_1c);
      (**(code **)(*param_2 + 0x78))(param_2,&local_2c);
      param_1[param_3 * 3 + 0x8215] = (int)param_2;
      pcVar1 = *(code **)(*param_2 + 0xd0);
      lVar2 = (longdouble)FUN_0001d22e(param_1[0x13],param_1[param_3 + 0x9115]);
      (*pcVar1)(param_1[param_3 * 3 + 0x8215],(float)lVar2);
      (**(code **)(*param_1 + 0x94))(param_1,param_3);
      (**(code **)(*param_4 + 0xac))(param_4,param_1[param_3 * 3 + 0x8215]);
    }
  }
  return;
}

