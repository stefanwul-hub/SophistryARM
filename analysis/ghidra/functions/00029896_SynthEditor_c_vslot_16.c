/* 00029896 SynthEditor_c_vslot_16 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 SynthEditor_c_vslot_16(int *param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  longdouble lVar5;
  int local_24;
  int *local_20;
  
  piVar4 = (int *)param_1[0x13];
  if (piVar4 == (int *)0x0) {
    return 1;
  }
  cVar2 = (**(code **)(*piVar4 + 0x26c))(piVar4);
  if (cVar2 == '\0') {
    return 1;
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (2 < param_2) {
    param_2 = 2;
  }
  _OSAtomicAdd32Barrier(1,param_1[0x13] + 0x3b30);
  if (param_1[0x9776] < 0) goto LAB_000299e8;
  FUN_0001d1ca(param_1[0x13],param_1[0x9776],param_2 == 2);
  if (*(char *)((int)param_1 + 0x51) == '\0') {
LAB_000299cb:
    iVar3 = param_1[0x9776];
  }
  else {
    iVar3 = param_1[0x9776];
    if (-1 < iVar3) {
      lVar5 = (longdouble)(**(code **)(*(int *)param_1[0x13] + 0x2b4))((int *)param_1[0x13],iVar3);
      if (0 < param_1[0x9615]) {
        local_20 = param_1;
        local_24 = 0;
        piVar4 = param_1;
        do {
          piVar1 = (int *)local_20[0x22];
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 0x100))(piVar1,(float)lVar5 < 0.5);
          }
          piVar1 = (int *)piVar4[0x8215];
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 0x100))(piVar1,(float)lVar5 < 0.5);
          }
          local_24 = local_24 + 1;
          local_20 = local_20 + 0x1a;
          piVar4 = piVar4 + 3;
        } while (local_24 < param_1[0x9615]);
      }
      goto LAB_000299cb;
    }
  }
  (**(code **)(*param_1 + 0x80))(param_1,iVar3,1);
LAB_000299e8:
  _OSAtomicAdd32Barrier(0xffffffff,param_1[0x13] + 0x3b30);
  return 1;
}

