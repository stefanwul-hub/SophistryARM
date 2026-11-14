/* 00028e00 FUN_00028e00 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00028e00(int param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
                 uint param_6)

{
  undefined1 uVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  ushort uVar8;
  char *pcVar9;
  undefined1 uVar10;
  bool bVar11;
  char local_15c [332];
  
  uVar6 = param_6 >> 0x18;
  uVar10 = (undefined1)(param_6 >> 8);
  uVar1 = (undefined1)param_6;
  piVar5 = *(int **)(param_1 + 0x4c);
  if (piVar5 == (int *)0x0) {
    return;
  }
  cVar2 = (**(code **)(*piVar5 + 0x380))(piVar5);
  cVar3 = (**(code **)(**(int **)(param_1 + 0x4c) + 0x37c))(*(int **)(param_1 + 0x4c));
  if (cVar2 == '\0') {
    cVar4 = (**(code **)(**(int **)(param_1 + 0x4c) + 0x378))(*(int **)(param_1 + 0x4c));
    bVar11 = cVar4 != '\0';
    if (cVar3 == '\0') {
      if (bVar11) {
LAB_00028fb8:
        uVar8 = (ushort)(byte)(param_6 >> 0x10);
        goto LAB_00028ead;
      }
      piVar5 = *(int **)(param_1 + 0x4c);
      iVar7 = *piVar5;
      pcVar9 = "Enter here";
      goto LAB_00028e84;
    }
    _strcpy(local_15c,(char *)(*(int *)(param_1 + 0x4c) + 0xcfec));
    (**(code **)(**(int **)(param_1 + 0x4c) + 0x36c))(*(int **)(param_1 + 0x4c),param_3,local_15c);
    if (bVar11) goto LAB_00028fb8;
  }
  else {
    piVar5 = *(int **)(param_1 + 0x4c);
    iVar7 = *piVar5;
    pcVar9 = "Demo Version";
LAB_00028e84:
    (**(code **)(iVar7 + 0x36c))(piVar5,param_3,pcVar9);
    bVar11 = false;
  }
  uVar6 = 0xffffffff;
  uVar8 = 0;
  uVar10 = 0;
  uVar1 = 0xff;
LAB_00028ead:
  FUN_00027206(param_1,param_2,param_3,param_4,param_5 + 1,0x5a,0xb,
               CONCAT31(CONCAT21((ushort)((uVar6 << 0x18) >> 0x10) | uVar8,uVar10),uVar1));
  if ((cVar2 != '\0') || (bVar11)) {
    param_1 = param_1 + param_3 * 0xc;
    piVar5 = *(int **)(param_1 + 0x20854);
  }
  else {
    if (cVar3 == '\0') {
      return;
    }
    param_1 = param_1 + param_3 * 0xc;
    piVar5 = *(int **)(param_1 + 0x20854);
  }
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 0x58))(piVar5,0);
  }
  piVar5 = *(int **)(param_1 + 0x20858);
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 0x58))(piVar5,0);
  }
  return;
}

