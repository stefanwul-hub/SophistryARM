/* 000ab0d8 FUN_000ab0d8 */

undefined4
FUN_000ab0d8(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint param_5)

{
  char cVar1;
  undefined4 uVar2;
  int *local_10;
  
  if ((param_1[0x1e] != 0) && ((char)param_1[0x1f] == '\0')) {
    cVar1 = (**(code **)(*param_1 + 0x10))(param_1);
    if ((cVar1 != '\0') && ((uint)param_1[0x1c] < param_5)) {
      FUN_000ae25c(param_1 + 0x17,param_1 + 0xd,param_5);
    }
    local_10 = param_1 + 0x17;
    if (param_1[0x1e] == 1) {
      uVar2 = FUN_000ae41e(local_10,param_1 + 0xd,param_5);
    }
    else {
      uVar2 = FUN_000ae306(local_10,param_1 + 0xd,param_5);
    }
    if (param_1[0x1e] == 1) {
      if ((code *)param_1[0x25] == (code *)0x0) {
        uVar2 = _AudioUnitRender(param_1[0x22],param_2,param_3,param_1[0x23],param_5,uVar2);
      }
      else {
        uVar2 = (*(code *)param_1[0x25])(param_1[0x26],param_2,param_3,param_1[0x23],param_5,uVar2);
      }
    }
    else {
      uVar2 = (*(code *)param_1[0x20])(param_1[0x21],param_2,param_3,param_4,param_5,uVar2);
    }
    if (param_1[0x1e] != 0) {
      return uVar2;
    }
  }
  return 0xffffd584;
}

