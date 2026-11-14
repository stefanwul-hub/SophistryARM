/* 0009310a FUN_0009310a */

void FUN_0009310a(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int *param_5,
                 int param_6)

{
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14 [2];
  
  local_14[0] = (param_5[3] / 6 + (param_5[3] >> 0x1f)) - (param_5[3] >> 0x1f);
  local_18 = param_4 + param_5[4];
  local_24 = param_3;
  local_20 = param_4;
  local_1c = local_14[0] + param_3;
  local_14[0] = local_14[0] * param_6;
  local_14[1] = 0;
  (**(code **)(*param_5 + 0x10))(param_5,param_2,&local_24,local_14);
  return;
}

