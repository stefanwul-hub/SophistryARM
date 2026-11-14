/* 000ac268 LPAUOutputElement_vslot_2 */

void LPAUOutputElement_vslot_2(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  FUN_000c7106(param_1 + 0x24,param_2);
  if (0 < param_2) {
    iVar2 = 0;
    do {
      local_34 = 1;
      local_28 = 0;
      puVar1 = *(undefined4 **)(param_1 + 0x28);
      if (puVar1 == *(undefined4 **)(param_1 + 0x2c)) {
        FUN_000c6e62(param_1 + 0x24,puVar1,&local_34);
      }
      else {
        if (puVar1 != (undefined4 *)0x0) {
          *puVar1 = 1;
          puVar1[1] = local_30;
          puVar1[2] = local_2c;
          puVar1[3] = 0;
          puVar1[4] = local_24;
          puVar1[5] = local_20;
          puVar1 = *(undefined4 **)(param_1 + 0x28);
        }
        *(undefined4 **)(param_1 + 0x28) = puVar1 + 6;
      }
      iVar2 = iVar2 + 1;
    } while (param_2 != iVar2);
  }
  *(undefined1 *)(param_1 + 0x20) = 1;
  return;
}

