/* 0000269c CFileDialog3Pl_vslot_7 */

void CFileDialog3Pl_vslot_7(int param_1,undefined4 param_2)

{
  uint uVar1;
  char *pcVar2;
  
  if (((-1 < *(int *)(param_1 + 0x76c)) && (uVar1 = FUN_0009cba2(param_2), (uVar1 & 0x20) != 0)) &&
     (uVar1 = FUN_0009cba2(param_2), (uVar1 & 8) != 0)) {
    (**(code **)(**(int **)(param_1 + 0x768) + 0x32c))
              (*(int **)(param_1 + 0x768),*(undefined4 *)(param_1 + 0x76c),
               *(undefined4 *)(param_1 + 0x770),*(undefined4 *)(param_1 + 0x774),param_2);
    return;
  }
  pcVar2 = (char *)FileDialog_c_vslot_2(param_1 + 0xb0);
  *(char **)(param_1 + 0x7c) = pcVar2;
  if (*pcVar2 == '\0') {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000026f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)**(undefined4 **)(param_1 + 0x94))();
  return;
}

