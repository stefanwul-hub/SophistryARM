/* 000817c0 FUN_000817c0 */

void FUN_000817c0(int param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  void *pvVar1;
  undefined1 local_34;
  undefined1 local_30;
  undefined1 local_2c;
  undefined1 local_28;
  undefined1 local_24;
  undefined1 local_20;
  
  *(undefined4 *)(param_1 + 200) = param_2;
  *(char *)(param_1 + 0xbc) = (char)param_4;
  *(char *)(param_1 + 0xbd) = (char)((uint)param_4 >> 8);
  local_24 = (undefined1)((uint)param_4 >> 0x10);
  *(undefined1 *)(param_1 + 0xbe) = local_24;
  local_20 = (undefined1)((uint)param_4 >> 0x18);
  *(undefined1 *)(param_1 + 0xbf) = local_20;
  *(undefined1 *)(param_1 + 0xc0) = (undefined1)param_5;
  *(char *)(param_1 + 0xc1) = (char)((uint)param_5 >> 8);
  local_2c = (undefined1)((uint)param_5 >> 0x10);
  *(undefined1 *)(param_1 + 0xc2) = local_2c;
  local_28 = (undefined1)((uint)param_5 >> 0x18);
  *(undefined1 *)(param_1 + 0xc3) = local_28;
  *(undefined1 *)(param_1 + 0xc4) = (undefined1)param_6;
  *(char *)(param_1 + 0xc5) = (char)((uint)param_6 >> 8);
  local_34 = (undefined1)((uint)param_6 >> 0x10);
  *(undefined1 *)(param_1 + 0xc6) = local_34;
  local_30 = (undefined1)((uint)param_6 >> 0x18);
  *(undefined1 *)(param_1 + 199) = local_30;
  *(undefined1 *)(param_1 + 0xd8) = param_3;
  *(undefined1 *)(param_1 + 0x74) = 1;
  pvVar1 = _malloc(*(int *)(param_1 + 0xb0) * 4 + 0x18);
  *(void **)(param_1 + 0xd4) = pvVar1;
  pvVar1 = _malloc(*(int *)(param_1 + 0xb0) * 4 + 0x18);
  *(void **)(param_1 + 0xd0) = pvVar1;
  return;
}

