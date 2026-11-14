/* 000192ca Synth_vslot_211 */

void Synth_vslot_211(int param_1,int param_2,undefined1 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  if ((piVar1 != (int *)0x0) &&
     ((**(code **)(*piVar1 + 0x80))(piVar1,param_2,param_3), *(int *)(param_1 + 0x8ac0) != 0)) {
    iVar3 = 0;
    do {
      iVar2 = *(int *)(iVar3 * 4 + *(int *)(param_1 + 0x8ac0) + param_2 * 0x10);
      if (iVar2 < 0) {
        return;
      }
      piVar1 = *(int **)(param_1 + 8);
      if (piVar1 == (int *)0x0) {
        return;
      }
      (**(code **)(*piVar1 + 0x80))(piVar1,iVar2,param_3);
      iVar3 = iVar3 + 1;
    } while (iVar3 != 4);
  }
  return;
}

