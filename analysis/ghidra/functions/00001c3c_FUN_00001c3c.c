/* 00001c3c FUN_00001c3c */

void FUN_00001c3c(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  int local_10;
  
  local_14 = param_3;
  local_10 = param_4;
  if (param_4 != param_5) {
    local_1c = param_3;
    local_18 = param_5;
    FUN_0009df12(param_2,&local_14);
    FUN_000a0cea(param_2,&local_1c);
    return;
  }
  FUN_000a0df0(param_2,&local_14,*(undefined4 *)(param_1 + 0x88));
  return;
}

