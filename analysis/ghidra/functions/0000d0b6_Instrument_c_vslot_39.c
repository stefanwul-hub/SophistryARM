/* 0000d0b6 Instrument_c_vslot_39 */

void Instrument_c_vslot_39(int *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  char cVar2;
  
  cVar2 = FUN_0002ddfc(param_1 + 0x394);
  if (cVar2 == '\0') {
    return;
  }
  cVar2 = FUN_0002ddfc(param_1 + 0x3a1);
  if ((0xff < param_3) && (0x100 < param_3)) {
    do {
      (**(code **)(*param_1 + 0xb0))(param_1,param_2,0x100);
      param_3 = param_3 + -0x100;
      param_1[0x6d8] = param_1[0x6d8] + 0x100;
      **(int **)(param_1[1] + 0x3ba8) = **(int **)(param_1[1] + 0x3ba8) + 0x400;
      piVar1 = (int *)(*(int *)(param_1[1] + 0x3ba8) + 4);
      *piVar1 = *piVar1 + 0x400;
    } while (0x100 < param_3);
  }
  (**(code **)(*param_1 + 0xb0))(param_1,param_2,param_3);
  if (cVar2 != '\0') {
    FUN_0002de1a(param_1 + 0x3a1);
    FUN_0002de1a();
    return;
  }
  FUN_0002de1a();
  return;
}

