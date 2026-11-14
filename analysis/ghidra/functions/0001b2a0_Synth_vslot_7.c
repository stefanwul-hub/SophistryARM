/* 0001b2a0 Synth_vslot_7 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Synth_vslot_7(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  longdouble lVar4;
  int local_28;
  
  if ((char)param_1[0x33f1] == '\0') {
    (**(code **)(*param_1 + 0xc))(param_1);
  }
  if ((char)param_1[0x33f1] != '\0') {
    _OSAtomicAdd32Barrier(1,param_1 + 0xecc);
    param_1[3] = param_2;
    param_1[0xee5] = param_2;
    lVar4 = (longdouble)FUN_000152c0(0x3f800000,param_2);
    param_1[0xee6] = (int)(float)lVar4;
    *(bool *)((int)param_1 + 0xcfc7) = 1000.0 < (float)param_1[0xee5];
    (**(code **)(*param_1 + 0x270))(param_1);
    piVar3 = (int *)param_1[0xdaf];
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0xa0))(piVar3,param_2);
    }
    if (0 < param_1[0xec9]) {
      iVar2 = 0;
      do {
        piVar3 = *(int **)(param_1[0xec3] + iVar2 * 4);
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 8))(piVar3,param_2);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_1[0xec9]);
    }
    if (0 < param_1[0x33ec]) {
      iVar2 = 0;
      do {
        piVar3 = *(int **)(param_1[0x33a9] + iVar2 * 4);
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 8))(piVar3,param_2);
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_1[0x33ec]);
    }
    if (0 < param_1[0xee2]) {
      local_28 = 0;
      piVar3 = param_1;
      do {
        if ((piVar3[0x1447] != 0) && (0 < piVar3[0x144b])) {
          iVar2 = 0;
          do {
            piVar1 = *(int **)(piVar3[0x1447] + iVar2 * 4);
            if (piVar1 != (int *)0x0) {
              (**(code **)(*piVar1 + 0xa0))(piVar1,param_1[0xee5]);
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < piVar3[0x144b]);
        }
        local_28 = local_28 + 1;
        piVar3 = piVar3 + 7;
      } while (local_28 < param_1[0xee2]);
    }
    (**(code **)(*param_1 + 0x324))(param_1);
    _OSAtomicAdd32Barrier(0xffffffff,param_1 + 0xecc);
    return;
  }
  return;
}

