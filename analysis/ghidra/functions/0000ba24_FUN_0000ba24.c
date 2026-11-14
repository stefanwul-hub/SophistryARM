/* 0000ba24 FUN_0000ba24 */

void FUN_0000ba24(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,undefined1 param_9,int param_10,int param_11)

{
  void *pvVar1;
  int iVar2;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  if ((((0 < param_7) && (param_4 != 0)) && (param_3 != 0)) && (param_10 != 0)) {
    *(int *)(param_1 + 0x54) = param_10;
    if (param_11 != 0) {
      *(undefined4 *)(param_1 + 0xc) = 1;
      *(undefined4 *)(param_1 + 0x30) = 0;
      *(undefined4 *)(param_1 + 0x34) = 0;
      *(undefined4 *)(param_1 + 0x3c) = 0;
      *(undefined4 *)(param_1 + 0x40) = 0;
      *(undefined4 *)(param_1 + 8) = param_2;
      *(int *)(param_1 + 0x48) = param_3;
      *(int *)(param_1 + 0x4c) = param_4;
      *(int *)(param_1 + 0x44) = param_11;
      *(undefined1 *)(param_1 + 4) = 1;
      FUN_0001ce0e(param_4,param_2,param_1 + 0x10);
    }
    *(undefined4 *)(param_1 + 0xc) = 6;
    if (param_8 < 0) {
      iVar2 = param_7 * -param_8;
    }
    else {
      iVar2 = 2;
    }
    local_10 = *(int *)(*(int *)(param_1 + 0x54) + 0x10) / iVar2 + param_6;
    local_14 = param_5 + *(int *)(*(int *)(param_1 + 0x54) + 0xc);
    local_1c = param_5;
    local_18 = param_6;
    pvVar1 = operator_new(200);
    FUN_000086fc(pvVar1,&local_1c,param_1,param_2,param_7,param_8,param_9,
                 *(undefined4 *)(param_1 + 0x54),0);
    FUN_0000b6b6(param_1,pvVar1);
  }
  return;
}

