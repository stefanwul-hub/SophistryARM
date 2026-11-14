/* 000023ba FUN_000023ba */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000023ba(int *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  FUN_0009a7d2(param_1,param_2,param_3,param_4,0);
  *param_1 = (int)&PTR_CControlPl_vslot_0_000e4648;
  FUN_0002e178(param_1 + 0x23);
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x2a] = 0x12;
  param_1[0x1e] = -0x3ee1999a;
  param_1[0x20] = (int)"";
  param_1[0x1f] = (int)"";
  param_1[0x21] = (int)(param_1 + 0x26);
  (**(code **)(*param_1 + 0x54))(param_1,1);
  *(undefined1 *)((int)param_1 + 0x6d) = 0;
  *(undefined1 *)(param_1 + 0x1b) = 0;
  *(undefined1 *)((int)param_1 + 0x6e) = 0;
  *(undefined1 *)(param_1 + 0x1c) = 0;
  *(undefined1 *)((int)param_1 + 0x6f) = 0;
  *(undefined1 *)((int)param_1 + 0x75) = 1;
  *(undefined1 *)((int)param_1 + 0x76) = 0;
  *(undefined1 *)((int)param_1 + 0x77) = 0;
  param_1[0x29] = param_5;
  puVar1 = (undefined4 *)_malloc(param_5 * 0x18 + 0x18);
  param_1[0x24] = (int)puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    if (0 < param_1[0x29]) {
      iVar2 = 0;
      iVar3 = 0;
      do {
        *(undefined4 *)(param_1[0x24] + iVar3) = 0xffffffff;
        *(undefined4 *)(param_1[0x24] + 4 + iVar3) = 0;
        *(undefined4 *)(param_1[0x24] + 8 + iVar3) = 0;
        *(undefined4 *)(param_1[0x24] + 0xc + iVar3) = 0;
        *(undefined4 *)(param_1[0x24] + 0x10 + iVar3) = 0;
        *(undefined4 *)(param_1[0x24] + 0x14 + iVar3) = 0x3f000000;
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x18;
      } while (iVar2 < param_1[0x29]);
    }
    puVar1 = (undefined4 *)param_1[0x24];
  }
  if ((puVar1 != (undefined4 *)0x0) && (0 < param_1[0x29])) {
    *puVar1 = param_4;
  }
  param_1[0x16] = 0x3dcccccd;
  *(undefined1 *)(param_1 + 0x2b) = 0;
  *(undefined1 *)((int)param_1 + 0x71) = 1;
  *(undefined1 *)((int)param_1 + 0x72) = 0;
  *(undefined1 *)((int)param_1 + 0x73) = 0;
  *(undefined1 *)(param_1 + 0x26) = 0;
  *(undefined1 *)(param_1 + 0x22) = 0xff;
  *(undefined1 *)((int)param_1 + 0x89) = 0;
  *(undefined1 *)((int)param_1 + 0x8a) = 0;
  *(undefined1 *)((int)param_1 + 0x8b) = 0xff;
  param_1[0x25] = param_3;
  return;
}

