/* 0000180e CControlPl_vslot_76 */

void CControlPl_vslot_76(int *param_1,char *param_2)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  
  piVar3 = (int *)param_1[0x21];
  if ((param_2 != (char *)0x0) &&
     ((*(char *)((int)param_1 + 0x6e) != '\0' || ((char)param_1[0x1c] != '\0')))) {
    iVar4 = _strcmp(param_2,(char *)piVar3);
    if (iVar4 != 0) {
      piVar1 = param_1 + 0x26;
      if (piVar3 != piVar1) {
        param_1[0x21] = (int)piVar1;
        _free(piVar3);
      }
      iVar4 = -1;
      pcVar5 = param_2;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        cVar2 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar2 != '\0');
      pcVar5 = (char *)_malloc(-iVar4);
      param_1[0x21] = (int)pcVar5;
      if (pcVar5 != (char *)0x0) {
        _strcpy(pcVar5,param_2);
                    /* WARNING: Could not recover jumptable at 0x000018ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*param_1 + 0x54))();
        return;
      }
      param_1[0x21] = (int)piVar1;
                    /* WARNING: Could not recover jumptable at 0x000018d3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_1 + 0x54))();
      return;
    }
  }
  return;
}

