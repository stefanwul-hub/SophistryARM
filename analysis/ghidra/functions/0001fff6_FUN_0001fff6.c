/* 0001fff6 FUN_0001fff6 */

void FUN_0001fff6(int param_1,int param_2,undefined1 param_3,undefined2 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  undefined1 local_24 [4];
  undefined1 local_20;
  undefined1 local_1f;
  undefined2 local_1e;
  undefined4 local_18;
  undefined4 local_14;
  
  if ((*(int *)(param_1 + 0x3b40) != 0) || (param_2 != 0x59)) {
    FUN_0002b8e2(local_24);
    local_20 = (undefined1)param_2;
    local_1f = param_3;
    local_1e = param_4;
    local_18 = param_5;
    local_14 = param_6;
    FUN_0002ba10(param_1 + 0x38b8,local_24);
    HoldData_c_vslot_0(local_24);
  }
  return;
}

