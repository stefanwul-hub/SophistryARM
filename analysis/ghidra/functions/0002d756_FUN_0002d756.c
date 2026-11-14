/* 0002d756 FUN_0002d756 */

void FUN_0002d756(int param_1,uint param_2)

{
  uint *puVar1;
  
  if (param_2 < 0x80) {
    puVar1 = (uint *)(param_1 + 4 + ((int)param_2 >> 5) * 4);
    *puVar1 = *puVar1 | 1 << ((byte)param_2 & 0x1f);
  }
  return;
}

