/* 0009fc26 CDrawContext_vslot_2 */

void CDrawContext_vslot_2(int *param_1)

{
  int iVar1;
  
  if (((char)param_1[0x19] != '\0') && (param_1[0x18] != 0)) {
    _CGContextSynchronize(param_1[0x18]);
    *(undefined1 *)(param_1 + 0x19) = 0;
  }
  iVar1 = param_1[1];
  param_1[1] = iVar1 + -1;
  if (iVar1 + -1 != 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0009fc69. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 4))();
  return;
}

