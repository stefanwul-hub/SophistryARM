/* 0008e6b4 WaveTable_c_vslot_30 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void WaveTable_c_vslot_30(int param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  dword *unaff_ESI;
  char *unaff_EDI;
  longdouble lVar5;
  float fVar6;
  char *local_540;
  undefined1 local_530 [660];
  dword local_29c [80];
  char local_15c [332];
  
  if (*(int *)(param_1 + 0x120) == 0) {
    return;
  }
  FUN_0000a5d4(local_530);
  if ((param_3 == -1) || (param_3 == 1)) {
    unaff_EDI = local_15c;
    FUN_00012482(*(undefined4 *)(param_1 + 0x120),param_2,1,unaff_EDI);
    if (local_15c[0] == '\0') {
      if (*(int *)(param_1 + 0x120) != 0) {
        FUN_00012432(*(int *)(param_1 + 0x120),param_2,1,"");
        FUN_000aecdc(param_1 + param_2 * 0x274 + 0x1d8);
        local_540 = (char *)0x0;
        do {
          iVar3 = 0;
          unaff_EDI = local_540;
          do {
            iVar4 = *(int *)(param_1 + 0x1d4);
            lVar5 = (longdouble)_sin((double)iVar3 * 0.04908738521234052);
            *(float *)(unaff_EDI + iVar4) = (float)lVar5;
            iVar3 = iVar3 + 1;
            unaff_EDI = unaff_EDI + 4;
          } while (iVar3 != 0x80);
          FUN_00032430(param_1,local_540 + *(int *)(param_1 + 0x1d4),0x80);
          local_540 = local_540 + 0x200;
        } while (local_540 != "");
        *(undefined4 *)(param_1 + 0x44c) = 0x3f800000;
        unaff_ESI = &section_00000054.align;
      }
    }
    else if (*(char *)(param_1 + 0x450) != '\0') {
      unaff_ESI = local_29c;
      _strcpy((char *)unaff_ESI,unaff_EDI);
      FUN_00012432(*(undefined4 *)(param_1 + 0x120),param_2,1,unaff_ESI);
      cVar2 = FUN_0008e28c(param_1,param_2,unaff_ESI);
      if (cVar2 == '\0') {
        FUN_0002e53a(param_1 + 0x168,"File Error - Load failed",unaff_EDI);
      }
    }
    if (param_3 != -1) goto LAB_0008e6f2;
LAB_0008e7f8:
    unaff_ESI = (dword *)FUN_000122c2(*(undefined4 *)(param_1 + 0x120),param_2,3);
    iVar3 = FUN_000122c2(*(undefined4 *)(param_1 + 0x120),param_2,4);
    if (iVar3 + -10 < (int)unaff_ESI) {
      FUN_00012222(*(undefined4 *)(param_1 + 0x120),param_2,3,iVar3 + -10);
    }
    if (param_3 != -1) goto LAB_0008e6fc;
LAB_0008e84f:
    unaff_ESI = (dword *)FUN_000122c2(*(undefined4 *)(param_1 + 0x120),param_2,3);
    iVar3 = FUN_000122c2(*(undefined4 *)(param_1 + 0x120),param_2,4);
    if (iVar3 < (int)unaff_ESI) {
      FUN_00012222(*(undefined4 *)(param_1 + 0x120),param_2,4,(char *)((int)unaff_ESI + 10));
    }
    if (param_3 != -1) goto LAB_0008e706;
  }
  else {
LAB_0008e6f2:
    if (param_3 == 3) goto LAB_0008e7f8;
LAB_0008e6fc:
    if (param_3 == 4) goto LAB_0008e84f;
LAB_0008e706:
    if (((param_3 != 3) && (param_3 != 4)) && (param_3 != 2)) goto LAB_0008e724;
  }
  if ((*(int *)(param_1 + 0x120) != 0) &&
     (iVar3 = FUN_00011b72(*(int *)(param_1 + 0x120),param_2), iVar3 != 0)) {
    if ((*(int *)(param_1 + 0x120) != 0) &&
       (iVar4 = FUN_00011b72(*(int *)(param_1 + 0x120),param_2), iVar4 != 0)) {
      iVar1 = param_1 + param_2 * 0x274 + 0x1d8;
      if (*(int *)(iVar1 + 0x21c) == 0) goto LAB_0008e724;
      fVar6 = (float)(*(int *)(iVar1 + 0x22c) + -1);
      unaff_EDI = (char *)(int)(fVar6 * *(float *)(iVar4 + 0x15c) * 0.01 + 0.25);
      unaff_ESI = (dword *)(int)(fVar6 * *(float *)(iVar4 + 0x1cc) * 0.01 + 0.25);
    }
    if ((int)unaff_EDI < (int)unaff_ESI) {
      FUN_0008de6a(param_1,param_2,*(undefined4 *)(iVar3 + 0xe8),unaff_EDI,unaff_ESI);
    }
  }
LAB_0008e724:
  Disk_c_vslot_0(local_530);
  return;
}

