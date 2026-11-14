/* 000a639e AEffGUIEditor_vslot_7 */

void AEffGUIEditor_vslot_7(int param_1)

{
  if ((*(char *)(param_1 + 0x18) == '\0') && (*(int **)(param_1 + 0x1c) != (int *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x000a63bd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x1c) + 0x100))();
    return;
  }
  return;
}

