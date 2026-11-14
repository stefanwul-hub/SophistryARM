/* 0000dc22 Instrument_c_vslot_25 */

void Instrument_c_vslot_25(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined1 local_10 [4];
  
  *(undefined4 *)(FUN_00001ace + param_1 + 6) = param_2;
  if ((-1 < *(int *)(param_1 + 0x1a4)) && (*(char *)(param_1 + 0xec2) != '\0')) {
    *(undefined4 *)(param_1 + 0x118) = param_2;
    iVar2 = FUN_0002f3da(*(int *)(param_1 + 4) + 0x38cc,*(undefined4 *)(param_1 + 0x1a4),local_10);
    while (-1 < iVar2) {
      if (*(char *)(param_1 + 0xec2) == '\0') {
        iVar3 = *(int *)(param_1 + 4);
      }
      else {
        iVar3 = *(int *)(param_1 + 4);
        piVar1 = *(int **)(*(int *)(iVar3 + 0x3b0c) + iVar2 * 4);
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 0x3c))(piVar1,*(undefined4 *)(param_1 + 0x118));
          iVar3 = *(int *)(param_1 + 4);
        }
      }
      iVar2 = FUN_0002ecd6(iVar3 + 0x38cc,*(undefined4 *)(param_1 + 0x1a4),local_10);
    }
  }
  return;
}

