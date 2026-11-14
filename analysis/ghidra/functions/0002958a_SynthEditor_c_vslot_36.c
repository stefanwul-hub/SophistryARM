/* 0002958a SynthEditor_c_vslot_36 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void SynthEditor_c_vslot_36(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  longdouble lVar5;
  int local_20;
  
  if (0 < param_1[0x9615]) {
    iVar3 = 0;
    do {
      (**(code **)(*param_1 + 0x94))(param_1,iVar3);
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1[0x9615]);
  }
  if ((-1 < param_1[0x9776]) && (*(char *)((int)param_1 + 0x51) != '\0')) {
    lVar5 = (longdouble)
            (**(code **)(*(int *)param_1[0x13] + 0x2b4))((int *)param_1[0x13],param_1[0x9776]);
    if (0 < param_1[0x9615]) {
      local_20 = 0;
      piVar2 = param_1;
      piVar4 = param_1;
      do {
        piVar1 = (int *)piVar4[0x22];
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 0x100))(piVar1,(float)lVar5 < 0.5);
        }
        piVar1 = (int *)piVar2[0x8215];
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 0x100))(piVar1,(float)lVar5 < 0.5);
        }
        local_20 = local_20 + 1;
        piVar4 = piVar4 + 0x1a;
        piVar2 = piVar2 + 3;
      } while (local_20 < param_1[0x9615]);
      return;
    }
  }
  return;
}

