/* 00018ee6 Synth_vslot_207 */

void Synth_vslot_207(int *param_1,int param_2,char param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *local_24;
  int local_18;
  int local_14;
  int local_10;
  
  if ((param_1[0xed1] < 1) && (param_3 != '\0')) {
    if (0 < param_1[0x33ec]) {
      local_10 = *(int *)param_1[0x33a9];
      if (local_10 != 0) {
        iVar1 = 0;
        do {
          uVar3 = Envelope_c_vslot_12(param_1 + 0x169,iVar1,4);
          *(undefined4 *)(local_10 + 0x15c) = uVar3;
          iVar1 = iVar1 + 1;
          if (param_1[0x33ec] <= iVar1) goto LAB_00018f15;
          local_10 = *(int *)(param_1[0x33a9] + iVar1 * 4);
        } while (local_10 != 0);
      }
      return;
    }
LAB_00018f23:
    local_18 = 0;
    if (param_3 == '\0') goto LAB_00018f34;
LAB_0001905f:
    local_24 = param_1 + 0x169;
    iVar1 = Envelope_c_vslot_12(local_24,param_2,5);
    iVar1 = 1 - iVar1;
    uVar3 = 4;
LAB_00018f6d:
    local_24 = param_1 + 0x169;
    Envelope_c_vslot_9(local_24,param_2,uVar3,iVar1);
  }
  else {
LAB_00018f15:
    if (param_1[0x33ec] < 1) goto LAB_00018f23;
    iVar1 = 0;
    local_18 = 0;
    do {
      local_24 = param_1 + 0x169;
      iVar2 = Envelope_c_vslot_12(local_24,iVar1,5);
      local_18 = local_18 + iVar2;
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_1[0x33ec]);
    if (param_3 != '\0') goto LAB_0001905f;
LAB_00018f34:
    local_24 = param_1 + 0x169;
    iVar1 = Envelope_c_vslot_12(local_24,param_2,4);
    if (iVar1 != 0) {
      iVar1 = 0;
      uVar3 = 5;
      goto LAB_00018f6d;
    }
    if (0 < local_18) {
      iVar1 = 1;
      uVar3 = 5;
      goto LAB_00018f6d;
    }
  }
  local_24 = param_1 + 0x169;
  if (param_1[0x33ec] < 1) {
    local_14 = 0;
  }
  else {
    iVar1 = 0;
    local_14 = 0;
    do {
      iVar2 = Envelope_c_vslot_12(local_24,iVar1,5);
      local_14 = local_14 + iVar2;
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_1[0x33ec]);
    if (0 < local_14) {
      if (0 < param_1[0x33ec]) {
        iVar1 = 0;
        do {
          if (iVar1 != param_2) {
            iVar2 = Envelope_c_vslot_12(local_24,iVar1,5);
            if (iVar2 == 0) {
              Envelope_c_vslot_9(local_24,iVar1,4,1);
            }
            else {
              Envelope_c_vslot_9(local_24,iVar1,4,0);
            }
          }
          iVar1 = iVar1 + 1;
        } while (iVar1 < param_1[0x33ec]);
      }
      goto LAB_00018ff6;
    }
  }
  if ((0 < param_1[0xed1]) && (0 < param_1[0x33ec])) {
    if (param_3 == '\0') {
      iVar1 = 0;
      do {
        if (param_2 != iVar1) {
          iVar2 = *(int *)(param_1[0x33a9] + iVar1 * 4);
          if (iVar2 == 0) {
            return;
          }
          Envelope_c_vslot_9(local_24,iVar1,4,*(undefined4 *)(iVar2 + 0x15c));
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < param_1[0x33ec]);
    }
    else {
      iVar1 = 0;
      do {
        iVar2 = *(int *)(param_1[0x33a9] + iVar1 * 4);
        if (iVar2 == 0) {
          return;
        }
        Envelope_c_vslot_9(local_24,iVar1,4,*(undefined4 *)(iVar2 + 0x15c));
        iVar1 = iVar1 + 1;
      } while (iVar1 < param_1[0x33ec]);
    }
  }
LAB_00018ff6:
  param_1[0xed1] = local_14;
                    /* WARNING: Could not recover jumptable at 0x00019010. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x350))();
  return;
}

