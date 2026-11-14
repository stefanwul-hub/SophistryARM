/* 000260a6 SynthEditor_c_vslot_33 */

void SynthEditor_c_vslot_33(int *param_1,int param_2,char param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (*(char *)((int)param_1 + 0x51) != '\0') {
    iVar2 = param_1[0x976f];
    if (iVar2 < 0x18) {
      if (iVar2 < 1) {
        if (iVar2 == 0) {
LAB_00026131:
          param_1[iVar2 + 0x9757] = param_2;
          param_1[0x976f] = iVar2 + 1;
        }
      }
      else if (param_2 != param_1[0x9757]) {
        iVar4 = 0;
        piVar3 = param_1;
        do {
          iVar4 = iVar4 + 1;
          if (iVar2 == iVar4) goto LAB_00026131;
          piVar1 = piVar3 + 0x9758;
          piVar3 = piVar3 + 1;
        } while (param_2 != *piVar1);
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x9770) = 1;
    }
    if ((*(char *)((int)param_1 + 0x51) != '\0') && (param_3 != '\0')) {
                    /* WARNING: Could not recover jumptable at 0x000260f9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_1 + 0x94))();
      return;
    }
  }
  return;
}

