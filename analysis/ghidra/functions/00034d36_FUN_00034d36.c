/* 00034d36 FUN_00034d36 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00034d36(undefined4 *param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  
  FUN_00031fec(param_1);
  *param_1 = &PTR_WaveRAM2_c_vslot_0_000e8348;
  puVar2 = param_1 + 0x78;
  iVar3 = 0x3e;
  do {
    FUN_000aeb88(puVar2);
    puVar2 = puVar2 + 0x9d;
    iVar3 = iVar3 + -1;
  } while (iVar3 != -2);
  FUN_0000a5d4(param_1 + 0x27c8);
  FUN_0002e178(param_1 + 0x286d);
  pvVar1 = operator_new(0x20);
  FUN_000126be(pvVar1,0x544d3034,1,0x50a);
  param_1[0x48] = pvVar1;
  if ((pvVar1 != (void *)0x0) && (*(int *)((int)pvVar1 + 4) != 0)) {
    *(undefined1 *)((int)param_1 + 0x1dd) = 0;
    *(undefined1 *)(param_1 + 0x77) = 1;
    *(undefined1 *)(param_1 + 0x75) = 1;
    *(undefined1 *)((int)param_1 + 0x1d5) = 0;
    *(undefined1 *)((int)param_1 + 0x1d6) = 1;
    *(undefined1 *)((int)param_1 + 0x1d7) = 1;
    param_1[0x76] = 0xffffffff;
    iVar3 = 0;
    puVar2 = param_1;
    do {
      puVar2[0xfa] = iVar3;
      *(char *)(param_1 + 0x27b8) = (char)iVar3;
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 0x9d;
      param_1 = (undefined4 *)((int)param_1 + 1);
    } while (iVar3 != 0x40);
  }
  return;
}

