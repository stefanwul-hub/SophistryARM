/* 00007296 FUN_00007296 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00007296(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined1 param_7,undefined4 param_8,
                 undefined4 param_9,uint param_10,undefined1 param_11)

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  undefined4 *puVar4;
  int iVar5;
  
  bVar2 = (byte)((uint)param_6 >> 0x18);
  bVar3 = (byte)((uint)param_6 >> 0x10);
  uVar1 = (undefined1)((uint)param_6 >> 8);
  FUN_000071aa(param_1,param_2,param_3,param_4,param_5,
               CONCAT31(CONCAT21((ushort)(((uint)bVar2 << 0x18) >> 0x10) | (ushort)bVar3,uVar1),
                        (char)param_6),param_7,param_8,param_9,param_10 & 0xfbff,0);
  *param_1 = &PTR_CMenuWithSub_vslot_0_000e5888;
  param_1[0x43] = &PTR_LAB_000e5a30;
  iVar5 = 0;
  puVar4 = param_1;
  do {
    puVar4[0x45] = 0;
    iVar5 = iVar5 + 1;
    puVar4 = puVar4 + 1;
  } while (iVar5 != 0x20);
  puVar4 = param_1;
  do {
    puVar4[0x65] = param_1;
    puVar4[0x165] = 0xbf800000;
    puVar4[0x265] = 0xffffffff;
    puVar4 = puVar4 + 1;
  } while (param_1 + 0x100 != puVar4);
  param_1[0x368] = 0;
  param_1[0x36a] = 0;
  param_1[0x369] = 0;
  *(char *)(param_1 + 0x44) = (char)param_6;
  *(undefined1 *)((int)param_1 + 0x111) = uVar1;
  *(byte *)((int)param_1 + 0x112) = bVar3;
  *(byte *)((int)param_1 + 0x113) = bVar2;
  *(undefined1 *)(param_1 + 0x367) = param_11;
  param_1[0x36b] = 0;
  CMenuWithSub_vslot_96(param_1);
  return;
}

