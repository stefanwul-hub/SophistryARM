/* 0000cd26 Instrument_c_vslot_14 */

void Instrument_c_vslot_14(int param_1,int param_2,undefined1 *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  char cVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int local_10;
  
  if (*(char *)(param_1 + 0x1b5c) == '\0') {
    return;
  }
  cVar3 = FUN_0002ddaa(param_1 + 0xe1c);
  iVar7 = *(int *)(param_1 + 0xeb8);
  if (0x17f < iVar7) goto LAB_0000ce0f;
  if (0 < iVar7) {
    if (param_2 < *(int *)(param_1 + 0x21c)) {
      local_10 = 0;
    }
    else {
      local_10 = 0;
      iVar5 = param_1;
      do {
        local_10 = local_10 + 1;
        if (iVar7 == local_10) goto LAB_0000cdc9;
        piVar1 = (int *)(iVar5 + 0x224);
        iVar5 = iVar5 + 8;
      } while (*piVar1 <= param_2);
      if (iVar7 <= local_10) goto LAB_0000cdc9;
    }
    puVar6 = (undefined4 *)(iVar7 * 8 + 0x214 + param_1);
    puVar4 = (undefined4 *)(iVar7 * 8 + 0x21c + param_1);
    do {
      iVar7 = iVar7 + -1;
      uVar2 = puVar6[1];
      *puVar4 = *puVar6;
      puVar4[1] = uVar2;
      puVar6 = puVar6 + -2;
      puVar4 = puVar4 + -2;
    } while (local_10 < iVar7);
  }
LAB_0000cdc9:
  *(int *)(param_1 + 0x21c + iVar7 * 8) = param_2;
  *(undefined1 *)(param_1 + 0x220 + iVar7 * 8) = *param_3;
  *(undefined1 *)(param_1 + 0x221 + iVar7 * 8) = param_3[1];
  *(undefined1 *)(param_1 + 0x222 + iVar7 * 8) = param_3[2];
  *(int *)(param_1 + 0xeb8) = *(int *)(param_1 + 0xeb8) + 1;
LAB_0000ce0f:
  if (cVar3 == '\0') {
    return;
  }
  FUN_0002ddc8();
  return;
}

