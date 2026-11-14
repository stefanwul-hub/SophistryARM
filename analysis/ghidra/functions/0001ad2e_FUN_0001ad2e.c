/* 0001ad2e FUN_0001ad2e */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0001ad2e(int *param_1)

{
  double dVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  longdouble lVar5;
  
  iVar3 = (**(code **)(*param_1 + 300))(param_1,0x402);
  param_1[0xeca] = iVar3;
  if (iVar3 != 0) {
    dVar1 = *(double *)(iVar3 + 0x20);
    if (((dVar1 != *(double *)(param_1 + 0xec5)) && ((*(byte *)(iVar3 + 0x55) & 4) != 0)) &&
       (1.0 < dVar1)) {
      *(double *)(param_1 + 0xec5) = dVar1;
      lVar5 = (longdouble)FUN_00015302(0,0x3ff00000,SUB84(dVar1,0),(int)((ulonglong)dVar1 >> 0x20));
      *(double *)(param_1 + 0xec7) = (double)lVar5;
      (**(code **)(*param_1 + 800))
                (param_1,(int)*(undefined8 *)(param_1 + 0xec5),
                 (int)((ulonglong)*(undefined8 *)(param_1 + 0xec5) >> 0x20));
    }
    uVar4 = *(uint *)(param_1[0xeca] + 0x54) >> 1;
    if ((*(char *)((int)param_1 + 0xcfcb) == '\0') && ((uVar4 & 1) != 0)) {
      (**(code **)(*param_1 + 0x3d4))(param_1);
      cVar2 = *(char *)((int)param_1 + 0xcfcb);
    }
    else {
      cVar2 = *(char *)((int)param_1 + 0xcfcb);
    }
    if ((cVar2 != '\0') && ((uVar4 & 1) == 0)) {
      (**(code **)(*param_1 + 0x3d8))(param_1);
    }
    *(byte *)((int)param_1 + 0xcfcb) = (byte)uVar4 & 1;
  }
  return;
}

