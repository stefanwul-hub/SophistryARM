/* 000c4a16 FUN_000c4a16 */

uint FUN_000c4a16(int *param_1,undefined1 *param_2,uint param_3)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  uint local_10;
  
  iVar2 = *param_1;
  if (param_3 >> 2 != 0) {
    puVar3 = (undefined1 *)(param_1[2] + iVar2 + 2);
    local_10 = 0;
    puVar1 = (undefined1 *)(param_1[2] + iVar2 + 3);
    do {
      if (((puVar1[-2] == (char)param_1[3]) && (puVar1[-1] == *(char *)((int)param_1 + 0xd))) &&
         (puVar3[1] == *(char *)((int)param_1 + 0xe))) {
        *param_2 = 0;
      }
      else {
        *param_2 = puVar1[-3];
      }
      param_2[1] = puVar1[-2];
      param_2[2] = *puVar3;
      param_2[3] = *puVar1;
      param_2 = param_2 + 4;
      local_10 = local_10 + 1;
      puVar1 = puVar1 + 4;
      puVar3 = puVar3 + 4;
    } while (local_10 != param_3 >> 2);
    iVar2 = *param_1;
  }
  *param_1 = param_3 + iVar2;
  return param_3;
}

