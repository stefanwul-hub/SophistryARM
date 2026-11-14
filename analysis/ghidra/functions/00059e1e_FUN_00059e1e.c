/* 00059e1e FUN_00059e1e */

void FUN_00059e1e(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                 int param_6,int param_7)

{
  int *piVar1;
  undefined1 local_2d [17];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  if (((param_7 != 0) && (0 < *(int *)(param_7 + 0xc))) && (param_4 < 0x11)) {
    local_10 = *(int *)(param_7 + 0x10) / 2 + param_6;
    local_14 = param_4 * *(int *)(param_7 + 0xc) + param_5;
    local_1c = param_5;
    local_18 = param_6;
    piVar1 = (int *)operator_new(0xc0);
    FUN_00032500(piVar1,&local_1c,param_1 + 0x20,param_3,param_7,param_4);
    if (piVar1 != (int *)0x0) {
      FUN_0001d532(*(undefined4 *)(param_1 + 0x4c),param_3,local_2d,0x11);
      *(undefined1 *)((int)piVar1 + 0x72) = 1;
      (**(code **)(*piVar1 + 0x130))(piVar1,local_2d);
      FUN_000266ca(param_1,piVar1,param_3,param_2);
      return;
    }
  }
  return;
}

