/* 00062b66 KajaInst_c_vslot_15 */

/* WARNING: Type propagation algorithm not settling */

void KajaInst_c_vslot_15(int param_1,int *param_2,undefined4 param_3)

{
  bool bVar1;
  undefined1 uVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 0x14fd4) == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x14fd8) == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x14fdc) == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x14fe0) == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x14fe4) == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x14fe8) == 0) {
    return;
  }
  if (param_2 == (int *)0x0) {
    return;
  }
  if (*param_2 != 0) {
    bVar1 = *(char *)(param_1 + 86000) != '\0' || 0 < *(int *)(param_1 + 0x14c);
    *(bool *)(param_1 + 86000) = bVar1;
    iVar5 = *(int *)(param_1 + 0x14fec);
    if (*(char *)(iVar5 + 0x2afc) == '\0') {
      if (bVar1) {
        InBuffer2_c_vslot_6(*(int *)(param_1 + 4) + 0x32b1c8,*(int *)(param_1 + 4) + 0x32b120,
                            param_3,0,0);
        iVar5 = *(int *)(param_1 + 0x14fec);
      }
      cVar4 = *(char *)(param_1 + 86000);
    }
    else {
      cVar4 = (**(code **)(**(int **)(param_1 + 0x14fd4) + 0xec))
                        (*(int **)(param_1 + 0x14fd4),bVar1,param_3);
      iVar5 = *(int *)(param_1 + 0x14fec);
    }
    if (*(char *)(iVar5 + 0x55dc) != '\0') {
      Pan51_c_vslot_56(param_1 + 0x14998,param_3);
      iVar5 = *(int *)(param_1 + 0x14fec);
    }
    if (*(char *)(iVar5 + 0x2bdc) == '\0') {
      if (*(char *)(param_1 + 86000) != '\0') {
        InBuffer2_c_vslot_6(*(int *)(param_1 + 4) + 0x32b1c8,*(int *)(param_1 + 4) + 0x32b174,
                            param_3,0,0);
        iVar5 = *(int *)(param_1 + 0x14fec);
      }
      cVar3 = *(char *)(param_1 + 86000);
    }
    else {
      cVar3 = (**(code **)(**(int **)(param_1 + 0x14fd8) + 0xec))
                        (*(int **)(param_1 + 0x14fd8),*(undefined1 *)(param_1 + 86000),param_3);
      iVar5 = *(int *)(param_1 + 0x14fec);
    }
    if ((cVar4 == '\0') && (cVar3 == '\0')) {
      uVar2 = 0;
      cVar4 = *(char *)(iVar5 + 0x2fcc);
    }
    else {
      uVar2 = 1;
      cVar4 = *(char *)(iVar5 + 0x2fcc);
    }
    if (cVar4 == '\0') {
      cVar4 = *(char *)(iVar5 + 0x30ac);
    }
    else {
      uVar2 = (**(code **)(**(int **)(param_1 + 0x14fdc) + 0xec))
                        (*(int **)(param_1 + 0x14fdc),uVar2,param_3);
      iVar5 = *(int *)(param_1 + 0x14fec);
      cVar4 = *(char *)(iVar5 + 0x30ac);
    }
    if (cVar4 == '\0') {
      cVar4 = *(char *)(iVar5 + 0x564c);
    }
    else {
      uVar2 = (**(code **)(**(int **)(param_1 + 0x14fe0) + 0xec))
                        (*(int **)(param_1 + 0x14fe0),uVar2,param_3);
      iVar5 = *(int *)(param_1 + 0x14fec);
      cVar4 = *(char *)(iVar5 + 0x564c);
    }
    if (cVar4 == '\0') {
      cVar4 = *(char *)(iVar5 + 0x318c);
    }
    else {
      Pan51_c_vslot_56(param_1 + 0x14bac,param_3);
      iVar5 = *(int *)(param_1 + 0x14fec);
      cVar4 = *(char *)(iVar5 + 0x318c);
    }
    if (cVar4 == '\0') {
      cVar4 = *(char *)(iVar5 + 0x326c);
    }
    else {
      uVar2 = (**(code **)(**(int **)(param_1 + 0x14fe4) + 0xec))
                        (*(int **)(param_1 + 0x14fe4),uVar2,param_3);
      iVar5 = *(int *)(param_1 + 0x14fec);
      cVar4 = *(char *)(iVar5 + 0x326c);
    }
    if (cVar4 == '\0') {
      cVar4 = *(char *)(iVar5 + 0x56bc);
    }
    else {
      uVar2 = (**(code **)(**(int **)(param_1 + 0x14fe8) + 0xec))
                        (*(int **)(param_1 + 0x14fe8),uVar2,param_3);
      cVar4 = *(char *)(*(int *)(param_1 + 0x14fec) + 0x56bc);
    }
    if (cVar4 != '\0') {
      Pan51_c_vslot_56(param_1 + 0x14dc0,param_3);
    }
    *(undefined1 *)(param_1 + 0x150) = uVar2;
    *(bool *)(param_1 + 86000) = 0 < *(int *)(param_1 + 0x14c);
    return;
  }
  return;
}

