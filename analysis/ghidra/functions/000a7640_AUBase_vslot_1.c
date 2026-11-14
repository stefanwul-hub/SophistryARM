/* 000a7640 AUBase_vslot_1 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void AUBase_vslot_1(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  *param_1 = &PTR_AUBase_vslot_0_000f4488;
  param_1[2] = &PTR_LAB_000f456c;
  if (param_1[0x2b] != 0) {
    _CFRelease(param_1[0x2b]);
  }
  if (param_1[0x36] != 0) {
    _CFRelease(param_1[0x36]);
  }
  for (iVar2 = param_1[0x2f]; param_1[0x30] != iVar2; iVar2 = iVar2 + 0xc) {
  }
  if ((void *)param_1[0x2f] != (void *)0x0) {
    operator_delete((void *)param_1[0x2f]);
  }
  for (iVar2 = param_1[0x2c]; param_1[0x2d] != iVar2; iVar2 = iVar2 + 0x20) {
  }
  if ((void *)param_1[0x2c] != (void *)0x0) {
    operator_delete((void *)param_1[0x2c]);
  }
  puVar3 = param_1 + 0x21;
  while (puVar1 = (undefined4 *)*puVar3, puVar1 != (undefined4 *)0x0) {
    *puVar3 = *puVar1;
    _free(puVar1);
  }
  while (puVar1 = (undefined4 *)param_1[0x22], puVar1 != (undefined4 *)0x0) {
    param_1[0x22] = *puVar1;
    _free(puVar1);
  }
  while (puVar1 = (undefined4 *)param_1[0x23], puVar1 != (undefined4 *)0x0) {
    param_1[0x23] = *puVar1;
    _free(puVar1);
  }
  if ((param_1 != (undefined4 *)0xffffffe0) && (param_1 + 8 != puVar3)) {
    iVar2 = 5;
    do {
      puVar3 = puVar3 + -5;
      FUN_000abefa(puVar3);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  FUN_000ab6f0(param_1);
  operator_delete(param_1);
  return;
}

