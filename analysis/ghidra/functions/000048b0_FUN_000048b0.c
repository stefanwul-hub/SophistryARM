/* 000048b0 FUN_000048b0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000048b0(undefined4 *param_1,undefined4 param_2)

{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  
  FUN_000adb94(param_1,param_2,0,1,0,0);
  FUN_0004e876(param_1 + 0x3b,&LAB_0000273c);
  *param_1 = &PTR_LPAUSynth_vslot_0_000e4908;
  param_1[2] = &PTR_LAB_000e4a60;
  param_1[0x39] = &PTR_LAB_000e4a6c;
  param_1[0x3b] = &PTR_LAB_000e4ac0;
  param_1[0xcacfd] = 0;
  param_1[0xcacfe] = 0;
  param_1[0xcacff] = 0;
  param_1[0xcad00] = 0;
  *(undefined1 *)(param_1 + 0xcad01) = 0;
  *(undefined1 *)((int)param_1 + 0x32b405) = 1;
  *(undefined1 *)((int)param_1 + 0x32b406) = 1;
  param_1[0xcad02] = 0;
  param_1[0xcad03] = 0;
  pvVar1 = operator_new__(0x8000);
  param_1[0xcad05] = pvVar1;
  param_1[0xcad04] = 0x3ff;
  *(undefined1 *)(param_1 + 0xcad06) = 0;
  param_1[0xcad0a] = 0;
  param_1[0xcad0b] = 0xffffffff;
  *(undefined1 *)(param_1 + 0xcad0c) = 0;
  *(undefined1 *)(param_1 + 0xcad0d) = 0;
  puVar3 = param_1 + 0xcacd7;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  param_1[0xcad10] = 0x69647541;
  param_1[0xcad11] = 0x696e556f;
  *(undefined2 *)(param_1 + 0xcad12) = 0x74;
  return;
}

