/* 00001a18 CControlPl_vslot_68 */

undefined4 CControlPl_vslot_68(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  float *pfVar1;
  float fVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  float *pfVar7;
  int local_14;
  
  if (*(int *)(param_1 + 0xa4) < 1) {
    return 0;
  }
  puVar3 = *(undefined4 **)(param_1 + 0x90);
  if ((float)puVar3[2] == (float)puVar3[1]) {
    iVar5 = 0;
    iVar4 = 0x18;
    pfVar7 = (float *)(puVar3 + 8);
    do {
      local_14 = iVar4;
      iVar5 = iVar5 + 1;
      if (iVar5 == *(int *)(param_1 + 0xa4)) {
        return 0;
      }
      puVar6 = (undefined4 *)(local_14 + (int)puVar3);
      pfVar1 = pfVar7 + -1;
      fVar2 = *pfVar7;
      iVar4 = local_14 + 0x18;
      pfVar7 = pfVar7 + 6;
    } while (*pfVar1 == fVar2);
  }
  else {
    local_14 = 0;
    puVar6 = puVar3;
  }
  *param_2 = *puVar6;
  *param_3 = *(undefined4 *)(local_14 + 4 + *(int *)(param_1 + 0x90));
  local_14 = local_14 + *(int *)(param_1 + 0x90);
  *(undefined4 *)(local_14 + 8) = *(undefined4 *)(local_14 + 4);
  return 1;
}

