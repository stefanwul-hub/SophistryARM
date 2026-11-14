/* 000b48c4 FUN_000b48c4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

bool FUN_000b48c4(int param_1,undefined4 param_2,float param_3,double param_4,undefined4 param_5,
                 int *param_6)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  
  piVar2 = param_6;
  cVar3 = '\0';
LAB_000b48e4:
  iVar1 = *piVar2;
  do {
    if ((iVar1 < 1) || (cVar3 != '\0')) {
      if (*(char *)(param_1 + 0x3b0) != '\0') {
        return param_4 <= *(double *)(param_1 + 0x318);
      }
      return param_4 <= *(double *)(param_1 + 0x310);
    }
    if (param_4 < *(double *)(param_1 + 0x318) || param_4 == *(double *)(param_1 + 0x318)) {
      if (*(char *)(param_1 + 0x3b0) == '\0') {
        iVar1 = *(int *)(param_1 + 0x1dc);
        if (iVar1 == 1) {
          cVar3 = FUN_000b4642(param_1,param_2,param_4,&param_5,piVar2);
        }
        else if (iVar1 == 2) {
          cVar3 = FUN_000b401c(param_1,param_2,param_4,&param_5,piVar2);
        }
        else {
          if (iVar1 != 0) goto LAB_000b4b18;
          cVar3 = FUN_000b3a1e(param_1,param_2,param_4,&param_5,piVar2);
        }
      }
      else {
        cVar3 = '\x01';
      }
    }
    else {
      iVar1 = *(int *)(param_1 + 0x1dc);
      if (iVar1 == 1) {
        cVar3 = FUN_000b35ea(param_1,param_2,param_4,&param_5,piVar2,(double)param_3);
      }
      else if (iVar1 == 2) {
        cVar3 = FUN_000b426e(param_1,param_2,param_4,&param_5,piVar2,(double)param_3);
      }
      else if (iVar1 == 0) {
        cVar3 = FUN_000b3c58(param_1,param_2,param_4,&param_5,piVar2,(double)param_3);
      }
      else {
LAB_000b4b18:
        cVar3 = '\0';
      }
    }
    dVar4 = *(double *)(param_1 + 0x328);
    if (((0.0 <= dVar4) && (dVar4 <= 1.0)) ||
       (param_4 < *(double *)(param_1 + 0x318) || param_4 == *(double *)(param_1 + 0x318)))
    goto LAB_000b48e4;
    if (1.0 < dVar4) {
      dVar6 = (double)param_3;
      do {
        if (dVar6 < *(double *)(param_1 + 0x310)) {
          *(double *)(param_1 + 0x310) = *(double *)(param_1 + 0x310) - dVar6;
          *(double *)(param_1 + 0x318) = *(double *)(param_1 + 0x318) - dVar6;
          *(double *)(param_1 + 0x330) = *(double *)(param_1 + 0x330) - dVar6;
          *(double *)(param_1 + 0x338) = *(double *)(param_1 + 0x338) - dVar6;
        }
        dVar4 = dVar4 - 1.0;
        *(double *)(param_1 + 0x328) = dVar4;
      } while (1.0 < dVar4);
    }
    if (0.0 < *(double *)(param_1 + 0x328) || *(double *)(param_1 + 0x328) == 0.0)
    goto LAB_000b48e4;
    dVar7 = (double)param_3;
    dVar4 = *(double *)(param_1 + 0x310);
    dVar6 = *(double *)(param_1 + 0x318);
    do {
      dVar4 = dVar4 + dVar7;
      dVar6 = dVar6 + dVar7;
      *(double *)(param_1 + 0x330) = dVar7 + *(double *)(param_1 + 0x330);
      *(double *)(param_1 + 0x338) = dVar7 + *(double *)(param_1 + 0x338);
      dVar5 = *(double *)(param_1 + 0x328) + 1.0;
      *(double *)(param_1 + 0x328) = dVar5;
    } while (dVar5 < 0.0);
    *(double *)(param_1 + 0x318) = dVar6;
    *(double *)(param_1 + 0x310) = dVar4;
    iVar1 = *piVar2;
  } while( true );
}

