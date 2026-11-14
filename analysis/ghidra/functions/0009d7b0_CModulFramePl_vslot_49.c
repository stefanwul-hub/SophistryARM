/* 0009d7b0 CModulFramePl_vslot_49 */

undefined4 CModulFramePl_vslot_49(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = *(undefined4 **)(param_1 + 0x3c);
  if (puVar2 == (undefined4 *)0x0) {
    return 0;
  }
  if (param_2 == 0) {
    uVar1 = *puVar2;
  }
  else {
    iVar3 = 0;
    do {
      puVar2 = (undefined4 *)puVar2[1];
      iVar3 = iVar3 + 1;
      if (puVar2 == (undefined4 *)0x0) {
        return 0;
      }
    } while (param_2 != iVar3);
    uVar1 = *puVar2;
  }
  return uVar1;
}

