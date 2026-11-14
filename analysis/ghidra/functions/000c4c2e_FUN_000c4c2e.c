/* 000c4c2e FUN_000c4c2e */

void FUN_000c4c2e(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                 undefined4 param_10,undefined4 param_11,code *param_12)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar4 = param_2 + -1;
  if (param_3 < param_2) {
    do {
      iVar2 = iVar4 / 2;
      puVar5 = (undefined4 *)(param_1 + iVar2 * 0x20);
      cVar1 = (*param_12)(puVar5,&param_4);
      if (cVar1 == '\0') goto LAB_000c4c4d;
      puVar3 = (undefined4 *)(param_1 + param_2 * 0x20);
      *puVar3 = *puVar5;
      puVar3[1] = puVar5[1];
      puVar3[2] = puVar5[2];
      puVar3[3] = puVar5[3];
      puVar3[4] = puVar5[4];
      puVar3[5] = puVar5[5];
      puVar3[6] = puVar5[6];
      puVar3[7] = puVar5[7];
      iVar4 = iVar2 + -1;
      param_2 = iVar2;
    } while (param_3 < iVar2);
  }
  else {
LAB_000c4c4d:
    puVar5 = (undefined4 *)(param_1 + param_2 * 0x20);
  }
  *puVar5 = param_4;
  puVar5[1] = param_5;
  puVar5[2] = param_6;
  puVar5[3] = param_7;
  puVar5[4] = param_8;
  puVar5[5] = param_9;
  puVar5[6] = param_10;
  puVar5[7] = param_11;
  return;
}

