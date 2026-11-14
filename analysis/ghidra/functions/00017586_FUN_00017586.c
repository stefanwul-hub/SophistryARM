/* 00017586 FUN_00017586 */

void FUN_00017586(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int local_1c;
  int local_10;
  
  if ((*(int *)(param_1 + 0x3bb0) == 0) || (*(int *)(LPAUSynth_vslot_10 + param_1) < 1)) {
    return;
  }
  local_10 = param_1;
  local_1c = 0;
  do {
    if ((*(int *)(local_10 + 0x62a8) == -1) ||
       (iVar5 = (**(code **)(**(int **)(param_1 + 0x3bb0) + 0x30))
                          (*(int **)(param_1 + 0x3bb0),param_2,*(int *)(local_10 + 0x62a8)),
       iVar5 == *(int *)(local_10 + 0x62ac))) {
      uVar1 = *(undefined4 *)(local_10 + 0x62a0);
      uVar2 = *(undefined4 *)(local_10 + 0x62a4);
      iVar5 = *(int *)(CMenuBase_vslot_1 + local_10) * 0x1c;
      if (0 < *(int *)(iVar5 + 0x512c + param_1)) {
        iVar6 = 0;
        do {
          iVar3 = *(int *)(iVar5 + 0x511c + param_1);
          if (iVar3 == 0) {
LAB_0001766d:
            if (*(int *)(iVar5 + 0x512c + param_1) <= iVar6 + 1) break;
          }
          else {
            piVar4 = *(int **)(iVar3 + iVar6 * 4);
            if (piVar4 != (int *)0x0) {
              (**(code **)(*piVar4 + 0xbc))(piVar4,param_2,uVar1,uVar2);
              goto LAB_0001766d;
            }
            if (*(int *)(iVar5 + 0x512c + param_1) <= iVar6 + 1) break;
          }
          iVar6 = iVar6 + 1;
        } while( true );
      }
      if (*(int *)(LPAUSynth_vslot_10 + param_1) <= local_1c + 1) {
        return;
      }
    }
    else if (*(int *)(LPAUSynth_vslot_10 + param_1) <= local_1c + 1) {
      return;
    }
    local_10 = local_10 + 0x18;
    local_1c = local_1c + 1;
  } while( true );
}

