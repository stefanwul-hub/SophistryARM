/* 00097484 CTextEdit_vslot_76 */

void CTextEdit_vslot_76(int *param_1,char *param_2)

{
  int iVar1;
  
  if (param_2 == (char *)0x0) {
    if ((char)param_1[0x2d] != '\0') {
      *(undefined1 *)(param_1 + 0x2d) = 0;
                    /* WARNING: Could not recover jumptable at 0x00097501. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_1 + 0x54))();
      return;
    }
  }
  else {
    iVar1 = _strcmp((char *)(param_1 + 0x2d),param_2);
    if (iVar1 != 0) {
      _strcpy((char *)(param_1 + 0x2d),param_2);
                    /* WARNING: Could not recover jumptable at 0x000974da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_1 + 0x54))();
      return;
    }
  }
  return;
}

