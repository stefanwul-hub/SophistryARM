/* 000c5172 FUN_000c5172 */

undefined4 * FUN_000c5172(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar3 = *(undefined4 **)(param_1 + 4);
  puVar4 = param_2 + 3;
  if (puVar4 != puVar3) {
    iVar1 = ((int)puVar3 - (int)puVar4 >> 2) * -0x55555555;
    if (0 < iVar1) {
      iVar2 = 0;
      puVar3 = param_2;
      do {
        *puVar3 = *puVar4;
        puVar3[1] = puVar4[1];
        puVar3[2] = puVar4[2];
        puVar4 = puVar4 + 3;
        puVar3 = puVar3 + 3;
        iVar2 = iVar2 + 1;
      } while (iVar1 != iVar2);
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -0xc;
      return param_2;
    }
  }
  *(undefined4 **)(param_1 + 4) = puVar3 + -3;
  return param_2;
}

