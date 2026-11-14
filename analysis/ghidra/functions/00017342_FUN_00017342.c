/* 00017342 FUN_00017342 */

void FUN_00017342(int param_1,int param_2,int param_3,char param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_10;
  
  if (((param_2 < -1) || (param_3 == 0)) ||
     (iVar5 = *(int *)(LPAUSynth_vslot_10 + param_1 + 4), 0x7f < iVar5)) {
    return;
  }
  *(int *)(param_1 + 0x7798 + iVar5 * 4) = param_3;
  if ((-1 < param_2) && (iVar3 = param_2 * 0x1c, 0 < *(int *)(iVar3 + 0x512c + param_1))) {
    if (param_4 == '\0') {
      iVar4 = 0;
      do {
        iVar2 = *(int *)(iVar3 + 0x511c + param_1);
        if (iVar2 == 0) {
          if (*(int *)(iVar3 + 0x512c + param_1) <= iVar4 + 1) goto LAB_0001740e;
        }
        else {
          piVar1 = *(int **)(iVar2 + iVar4 * 4);
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 0xb4))(piVar1,*(undefined4 *)(param_1 + 0x7798 + iVar5 * 4));
            iVar5 = *(int *)(LPAUSynth_vslot_10 + param_1 + 4);
          }
          if (*(int *)(iVar3 + 0x512c + param_1) <= iVar4 + 1) {
LAB_0001740e:
            *(int *)(LPAUSynth_vslot_10 + param_1 + 4) = iVar5 + 1;
            return;
          }
        }
        iVar4 = iVar4 + 1;
      } while( true );
    }
    local_10 = 0;
    do {
      iVar3 = *(int *)(param_2 * 0x1c + 0x511c + param_1);
      if ((iVar3 != 0) && (piVar1 = *(int **)(iVar3 + local_10 * 4), piVar1 != (int *)0x0)) {
        (**(code **)(*piVar1 + 0xb8))(piVar1,*(undefined4 *)(param_1 + 0x7798 + iVar5 * 4));
        iVar5 = *(int *)(LPAUSynth_vslot_10 + param_1 + 4);
      }
      local_10 = local_10 + 1;
    } while (local_10 < *(int *)(param_2 * 0x1c + 0x512c + param_1));
  }
  *(int *)(LPAUSynth_vslot_10 + param_1 + 4) = iVar5 + 1;
  return;
}

