/* 00018e04 Synth_vslot_200 */

void Synth_vslot_200(int *param_1,double param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int local_18;
  
  piVar3 = (int *)param_1[0xdaf];
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0xa4))(piVar3,(float)param_2);
  }
  if (0 < param_1[0xee2]) {
    local_18 = 0;
    piVar3 = param_1;
    do {
      if ((piVar3[0x1447] != 0) && (0 < piVar3[0x144b])) {
        iVar2 = 0;
        do {
          piVar1 = *(int **)(piVar3[0x1447] + iVar2 * 4);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 0xa4))(piVar1,(float)param_2);
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < piVar3[0x144b]);
      }
      local_18 = local_18 + 1;
      piVar3 = piVar3 + 7;
    } while (local_18 < param_1[0xee2]);
                    /* WARNING: Could not recover jumptable at 0x00018ecf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x324))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00018ee4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x324))();
  return;
}

