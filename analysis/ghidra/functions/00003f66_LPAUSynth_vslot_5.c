/* 00003f66 LPAUSynth_vslot_5 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 LPAUSynth_vslot_5(int *param_1)

{
  double dVar1;
  int iVar2;
  undefined4 *puVar3;
  void *pvVar4;
  double *pdVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  longdouble lVar9;
  
  FUN_000a66b8(param_1,1);
  if ((char)param_1[0xcad0c] == '\0') {
    (**(code **)(param_1[0x3b] + 0xc))(param_1 + 0x3b);
    *(undefined1 *)(param_1 + 0xcad0c) = 1;
  }
  FUN_000037ce(param_1);
  iVar2 = param_1[0x15] - param_1[0x14] >> 2;
  param_1[0xcad07] = iVar2;
  param_1[0xcad08] = 0;
  if (iVar2 != 0) {
    uVar8 = 0;
    iVar2 = param_1[0xcad08];
    do {
      piVar7 = (int *)param_1[0x14] + uVar8;
      if ((((int *)param_1[0x15] <= piVar7) || (piVar7 < (int *)param_1[0x14])) || (*piVar7 == 0))
      goto LAB_00003fe5;
      iVar2 = iVar2 + *(int *)(*piVar7 + 0x50);
      param_1[0xcad08] = iVar2;
      uVar8 = uVar8 + 1;
    } while (uVar8 < (uint)param_1[0xcad07]);
  }
  param_1[0xcad09] = 0;
  uVar8 = 0;
  piVar7 = (int *)param_1[0xf];
  while( true ) {
    if (((uint)(param_1[0x10] - param_1[0xf] >> 2) <= uVar8) || (uVar8 == 2)) {
      param_1[0x342b] = param_1[0xcad09];
      if ((param_1[0xcad07] != 0) && (param_1[0xcad08] != 0)) {
        pvVar4 = operator_new__(0x18);
        param_1[0xcad00] = (int)pvVar4;
        if (pvVar4 != (void *)0x0) {
          pvVar4 = operator_new__(8);
          param_1[0xcacff] = (int)pvVar4;
          if (pvVar4 != (void *)0x0) {
            pdVar5 = (double *)(**(code **)(*param_1 + 0xb0))(param_1,0,0);
            dVar1 = *pdVar5;
            piVar7 = param_1 + 0x3b;
            (**(code **)(param_1[0x3b] + 0x1c))(piVar7,(float)dVar1);
            lVar9 = (longdouble)(**(code **)(param_1[0x3b] + 0x80))(piVar7);
            if ((dVar1 == (double)(float)lVar9) && (!NAN(dVar1) && !NAN((double)(float)lVar9))) {
              iVar2 = _GetMainEventLoop();
              if (iVar2 != 0) {
                iVar6 = _NewEventLoopTimerUPP(FUN_00003aba);
                param_1[0xcacfe] = iVar6;
                if (iVar6 != 0) {
                  _InstallEventLoopTimer
                            (iVar2,0x47ae147b,0x3f747ae1,0,0x3fd00000,iVar6,param_1,
                             param_1 + 0xcacfd);
                }
              }
              (**(code **)(param_1[0x3b] + 8))(piVar7,0xc,0,1,0,0);
              *(undefined1 *)((int)param_1 + 0x32b431) = 0;
              param_1[0xcad0e] = 0;
              param_1[0xcad0f] = 0;
              *(undefined1 *)((int)param_1 + 0xd0b2) = 1;
              *(undefined1 *)((int)param_1 + 0x32b432) = 0;
              *(undefined1 *)((int)param_1 + 0x32b433) = 0;
              return 0;
            }
          }
        }
      }
      return 0xffffd585;
    }
    if (((int *)param_1[0x10] <= piVar7) || ((piVar7 < (int *)param_1[0xf] || (*piVar7 == 0))))
    break;
    param_1[0xcad08] = param_1[0xcad08] + *(int *)(*piVar7 + 0x50);
    uVar8 = uVar8 + 1;
    piVar7 = piVar7 + 1;
  }
LAB_00003fe5:
  puVar3 = (undefined4 *)___cxa_allocate_exception(4);
  *puVar3 = 0xffffd583;
                    /* WARNING: Subroutine does not return */
  ___cxa_throw(puVar3,PTR_001037fc,0);
}

