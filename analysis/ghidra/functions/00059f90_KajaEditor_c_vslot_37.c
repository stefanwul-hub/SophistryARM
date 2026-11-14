/* 00059f90 KajaEditor_c_vslot_37 */

void KajaEditor_c_vslot_37(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int iVar4;
  
  if (param_2 - 0xd7U < 4) {
    FUN_000599d2(param_1,param_2);
    if (param_2 != 0x1e4) goto LAB_00059fbf;
LAB_0005a0b6:
    piVar1 = *(int **)(param_1 + 0x21ff4);
joined_r0x0005a105:
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x54))(piVar1,1);
    }
joined_r0x0005a0ce:
    if (param_2 != 499) goto LAB_0005a003;
    piVar1 = *(int **)(param_1 + 0x2209c);
  }
  else {
    if (param_2 == 0x1e4) goto LAB_0005a0b6;
LAB_00059fbf:
    if (param_2 == 0x1e5) {
      piVar1 = *(int **)(param_1 + 0x22000);
      goto joined_r0x0005a105;
    }
    if (param_2 == 0x1e6) {
      piVar1 = *(int **)(param_1 + 0x2200c);
      goto joined_r0x0005a105;
    }
    if (param_2 != 0x1e7) {
      if (((param_2 == 0x1e8) || (param_2 == 0x1ea)) &&
         (piVar1 = *(int **)(param_1 + 0x22024), piVar1 != (int *)0x0)) {
        (**(code **)(*piVar1 + 0x54))(piVar1,1);
      }
      if (((param_2 == 0x1e9) || (param_2 == 0x1eb)) &&
         (piVar1 = *(int **)(param_1 + 0x22030), piVar1 != (int *)0x0)) {
        (**(code **)(*piVar1 + 0x54))(piVar1,1);
      }
      if (param_2 == 0x1f2) {
        piVar1 = *(int **)(param_1 + 0x22090);
        goto joined_r0x0005a184;
      }
      goto joined_r0x0005a0ce;
    }
    piVar1 = *(int **)(param_1 + 0x22018);
  }
joined_r0x0005a184:
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x54))(piVar1,1);
  }
LAB_0005a003:
  if ((param_2 - 0x29dU < 10) && (*(char *)(param_1 + 0x51) != '\0')) {
    iVar4 = 0;
    puVar3 = &UNK_0001142c + param_1;
    do {
      uVar2 = FUN_00054462(param_1,0x29d,iVar4,0);
      FUN_0000afac(puVar3,uVar2);
      FUN_0000b124(puVar3,0);
      iVar4 = iVar4 + 1;
      puVar3 = puVar3 + 0x68;
    } while (iVar4 != 10);
    SynthEditor_c_vslot_37();
    return;
  }
  SynthEditor_c_vslot_37();
  return;
}

