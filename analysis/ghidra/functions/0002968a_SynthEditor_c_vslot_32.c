/* 0002968a SynthEditor_c_vslot_32 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void SynthEditor_c_vslot_32(int *param_1,int param_2,undefined1 param_3)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  longdouble lVar4;
  int local_24;
  int *local_20;
  
  if ((*(char *)((int)param_1 + 0x51) != '\0') && (-1 < param_2)) {
    (**(code **)(*param_1 + 0x84))(param_1,param_2,param_3);
    uVar2 = FUN_00094786(param_1 + 0x9dfa,param_2);
    if (-1 < (int)uVar2) {
      do {
        (**(code **)(*param_1 + 0x84))(param_1,uVar2,param_3);
        uVar2 = FUN_000946a0(param_1 + 0x9dfa);
      } while (uVar2 < 0x80000000);
    }
    if ((param_2 == param_1[0x9776]) && (*(char *)((int)param_1 + 0x51) != '\0')) {
      lVar4 = (longdouble)(**(code **)(*(int *)param_1[0x13] + 0x2b4))((int *)param_1[0x13],param_2)
      ;
      if (0 < param_1[0x9615]) {
        local_20 = param_1;
        local_24 = 0;
        piVar3 = param_1;
        do {
          piVar1 = (int *)local_20[0x22];
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 0x100))(piVar1,(float)lVar4 < 0.5);
          }
          piVar1 = (int *)piVar3[0x8215];
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 0x100))(piVar1,(float)lVar4 < 0.5);
          }
          local_24 = local_24 + 1;
          local_20 = local_20 + 0x1a;
          piVar3 = piVar3 + 3;
        } while (local_24 < param_1[0x9615]);
      }
    }
  }
  return;
}

