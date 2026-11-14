/* 000ac302 FUN_000ac302 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000ac302(undefined4 *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  
  FUN_000c723a(param_1,param_2);
  *param_1 = &PTR_AUIOElement_vslot_0_000f4648;
  puVar3 = param_1 + 0xd;
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  param_1[0x17] = 0;
  *(undefined1 *)(param_1 + 0x18) = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  cVar1 = *(char *)(param_2 + 0xe);
  param_1[0xf] = 0x6c70636d;
  param_1[0x10] = 9;
  param_1[0x15] = 0x20;
  param_1[0x14] = 2;
  param_1[0x12] = 1;
  if (cVar1 != '\x01') {
    param_1[0x13] = 4;
    param_1[0x11] = 4;
    param_1[0x10] = 0x29;
    param_1[0xd] = 0;
    param_1[0xe] = 0x40e58880;
    return;
  }
  param_1[0x13] = 8;
  param_1[0x11] = 8;
  param_1[0xd] = 0;
  param_1[0xe] = 0x40e58880;
  return;
}

