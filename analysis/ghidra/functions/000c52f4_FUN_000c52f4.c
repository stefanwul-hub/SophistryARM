/* 000c52f4 FUN_000c52f4 */

undefined4 * FUN_000c52f4(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 4);
  iVar4 = iVar3 - (int)param_3 >> 5;
  puVar1 = param_2;
  if (0 < iVar4) {
    iVar3 = 0;
    puVar2 = param_3;
    do {
      *puVar1 = *puVar2;
      puVar1[1] = puVar2[1];
      puVar1[2] = puVar2[2];
      puVar1[3] = puVar2[3];
      puVar1[4] = puVar2[4];
      puVar1[5] = puVar2[5];
      puVar1[6] = puVar2[6];
      puVar1[7] = puVar2[7];
      puVar2 = puVar2 + 8;
      puVar1 = puVar1 + 8;
      iVar3 = iVar3 + 1;
    } while (iVar4 != iVar3);
    iVar3 = *(int *)(param_1 + 4);
  }
  for (; *(undefined4 **)(param_1 + 4) != puVar1; puVar1 = puVar1 + 8) {
  }
  *(uint *)(param_1 + 4) = iVar3 - ((int)param_3 - (int)param_2 & 0xffffffe0U);
  return param_2;
}

