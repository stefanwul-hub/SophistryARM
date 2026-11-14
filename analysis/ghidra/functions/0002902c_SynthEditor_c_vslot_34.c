/* 0002902c SynthEditor_c_vslot_34 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void SynthEditor_c_vslot_34(int *param_1,char param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  code *pcVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int local_64;
  undefined *local_30;
  undefined1 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if (param_1[0x13] != 0) {
    if (param_2 == '\0') {
      local_2c = *(undefined1 *)(param_3 + 4);
      uVar5 = *(undefined4 *)(param_3 + 8);
      uVar2 = *(undefined4 *)(param_3 + 0xc);
      local_20 = *(undefined4 *)(param_3 + 0x10);
      local_30 = PTR_DAT_00103814 + 8;
      local_28 = uVar5;
      local_24 = uVar2;
      iVar4 = (**(code **)(*(int *)param_1[0x13] + 0x2b8))((int *)param_1[0x13],&local_30);
      if ((((-1 < iVar4) && (iVar4 < 3)) && (*(char *)((int)param_1 + 0x51) != '\0')) &&
         ((piVar6 = (int *)param_1[iVar4 + 0x9771], piVar6 != (int *)0x0 &&
          ((char)param_1[0x9774] == '\0')))) {
        (**(code **)(*piVar6 + 0x13c))(piVar6,uVar5,uVar2);
        pcVar3 = *(code **)(*param_1 + 0x80);
        uVar5 = (**(code **)(*(int *)param_1[iVar4 + 0x9771] + 0xdc))
                          ((int *)param_1[iVar4 + 0x9771]);
        (*pcVar3)(param_1,uVar5,0);
      }
      return;
    }
    local_64 = 0;
    piVar6 = param_1;
    do {
      while( true ) {
        if (((-1 < local_64) && (*(char *)((int)param_1 + 0x51) != '\0')) &&
           ((piVar1 = (int *)piVar6[0x9771], piVar1 != (int *)0x0 && ((char)param_1[0x9774] == '\0')
            ))) break;
        local_64 = local_64 + 1;
        piVar6 = piVar6 + 1;
        if (local_64 == 3) {
          return;
        }
      }
      (**(code **)(*piVar1 + 0x13c))
                (piVar1,*(undefined4 *)(param_3 + 8),*(undefined4 *)(param_3 + 0xc));
      pcVar3 = *(code **)(*param_1 + 0x80);
      uVar5 = (**(code **)(*(int *)piVar6[0x9771] + 0xdc))((int *)piVar6[0x9771]);
      (*pcVar3)(param_1,uVar5,0);
      local_64 = local_64 + 1;
      piVar6 = piVar6 + 1;
    } while (local_64 != 3);
  }
  return;
}

