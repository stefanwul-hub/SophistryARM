/* 000c4d08 FUN_000c4d08 */

void FUN_000c4d08(int param_1,int param_2,int param_3)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  code *in_stack_00000030;
  int local_34;
  int local_30;
  
  iVar4 = param_2 * 2 + 2;
  if (iVar4 < param_3) {
    local_30 = param_2;
    do {
      cVar1 = (*in_stack_00000030)(iVar4 * 0x20 + param_1,iVar4 * 0x20 + -0x20 + param_1);
      local_34 = iVar4 + -1 + (uint)(cVar1 == '\0');
      puVar3 = (undefined4 *)(param_1 + local_30 * 0x20);
      puVar2 = (undefined4 *)(local_34 * 0x20 + param_1);
      *puVar3 = *puVar2;
      puVar3[1] = puVar2[1];
      puVar3[2] = puVar2[2];
      puVar3[3] = puVar2[3];
      puVar3[4] = puVar2[4];
      puVar3[5] = puVar2[5];
      puVar3[6] = puVar2[6];
      puVar3[7] = puVar2[7];
      iVar4 = local_34 * 2 + 2;
      local_30 = local_34;
    } while (iVar4 < param_3);
  }
  else {
    local_34 = param_2;
  }
  if (param_3 == iVar4) {
    puVar3 = (undefined4 *)(param_1 + local_34 * 0x20);
    puVar2 = (undefined4 *)(param_3 * 0x20 + -0x20 + param_1);
    *puVar3 = *puVar2;
    puVar3[1] = puVar2[1];
    puVar3[2] = puVar2[2];
    puVar3[3] = puVar2[3];
    puVar3[4] = puVar2[4];
    puVar3[5] = puVar2[5];
    puVar3[6] = puVar2[6];
    puVar3[7] = puVar2[7];
  }
  FUN_000c4c2e();
  return;
}

