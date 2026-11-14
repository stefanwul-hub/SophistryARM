/* 0008a516 FUN_0008a516 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0008a516(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined1 param_12,
                 undefined1 param_13,undefined1 param_14,undefined1 param_15)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  FUN_000021e2(param_1,param_2,param_3,param_4);
  *param_1 = &PTR_CStepSeqPl_vslot_0_000f2da8;
  param_1[0xd8] = 0;
  param_1[0xd9] = 0;
  param_1[0x2e] = param_5;
  param_1[0xd6] = param_6;
  param_1[0xd7] = param_7;
  param_1[0x2f] = param_9;
  param_1[0x30] = param_10;
  param_1[0x31] = param_11;
  *(undefined1 *)(param_1 + 0x33) = param_12;
  *(undefined1 *)((int)param_1 + 0xcd) = param_13;
  *(undefined1 *)((int)param_1 + 0xce) = param_14;
  *(undefined1 *)((int)param_1 + 0xcf) = param_15;
  *(undefined1 *)((int)param_1 + 0x6e) = 1;
  *(undefined1 *)((int)param_1 + 0x356) = 0;
  uVar1 = param_2[1];
  param_1[0xd8] = *param_2;
  param_1[0xd9] = uVar1;
  param_1[0x32] = param_1[0x2f] * param_1[0x30];
  *(bool *)((int)param_1 + 0x71) = param_1[0xd7] != 0 && param_1[0xd6] != 0;
  *(undefined1 *)(param_1 + 0x34) = 0;
  _strcpy((char *)((int)param_1 + 0x1d3),(char *)(param_1 + 0x34));
  param_1[0x21] = param_1 + 0x34;
  param_1[0x1f] = (char *)((int)param_1 + 0x1d3);
  iVar3 = 0x80;
  puVar2 = param_1;
  do {
    *(undefined1 *)((int)puVar2 + 0x2d6) = 0;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined1 *)((int)param_1 + 0x357) = 0;
  *(char *)(param_1 + 0x2d) = (char)param_8;
  *(char *)((int)param_1 + 0xb5) = (char)((uint)param_8 >> 8);
  *(char *)((int)param_1 + 0xb6) = (char)((uint)param_8 >> 0x10);
  *(char *)((int)param_1 + 0xb7) = (char)((uint)param_8 >> 0x18);
  param_1[0x2c] = 4;
  return;
}

