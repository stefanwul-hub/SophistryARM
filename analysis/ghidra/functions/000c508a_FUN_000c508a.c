/* 000c508a FUN_000c508a */

void FUN_000c508a(int param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  if ((int)param_2 - param_1 >> 5 < 0x11) {
    FUN_000c4ef4();
    return;
  }
  puVar1 = (undefined4 *)(param_1 + 0x200);
  FUN_000c4ef4(param_1,puVar1,param_3);
  for (; puVar1 != param_2; puVar1 = puVar1 + 8) {
    FUN_000c4e64(puVar1,*puVar1,puVar1[1],puVar1[2],puVar1[3],puVar1[4],puVar1[5],puVar1[6],
                 puVar1[7],param_3);
  }
  return;
}

