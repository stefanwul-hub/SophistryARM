/* 0002ecd6 FUN_0002ecd6 */

undefined4 FUN_0002ecd6(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 8) < -1) {
    return 0xffffffff;
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  *param_3 = -1;
  iVar3 = *(int *)(param_1 + 8);
  if (iVar3 < *(int *)(param_1 + 0xc)) {
    iVar2 = iVar3 * 0x24;
    do {
      piVar1 = (int *)(iVar2 + *(int *)(param_1 + 0x10));
      if ((*piVar1 != 0) && (param_2 == piVar1[1])) {
        *param_3 = piVar1[3];
        break;
      }
      iVar3 = iVar3 + 1;
      *(int *)(param_1 + 8) = iVar3;
      iVar2 = iVar2 + 0x24;
    } while (iVar3 < *(int *)(param_1 + 0xc));
  }
  if (*param_3 == -1) {
    *(undefined4 *)(param_1 + 8) = 0xfffffffe;
  }
  return *(undefined4 *)(param_1 + 8);
}

