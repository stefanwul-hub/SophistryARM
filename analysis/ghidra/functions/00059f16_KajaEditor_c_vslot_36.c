/* 00059f16 KajaEditor_c_vslot_36 */

void KajaEditor_c_vslot_36(int param_1)

{
  undefined4 uVar1;
  undefined *puVar2;
  int iVar3;
  
  SynthEditor_c_vslot_36(param_1);
  if (*(char *)(param_1 + 0x51) == '\0') {
    return;
  }
  iVar3 = 0;
  puVar2 = &UNK_0001142c + param_1;
  do {
    uVar1 = FUN_00054462(param_1,0x29d,iVar3,0);
    FUN_0000afac(puVar2,uVar1);
    FUN_0000b124(puVar2,0);
    iVar3 = iVar3 + 1;
    puVar2 = puVar2 + 0x68;
  } while (iVar3 != 10);
  return;
}

