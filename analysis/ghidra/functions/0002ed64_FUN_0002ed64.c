/* 0002ed64 FUN_0002ed64 */

bool FUN_0002ed64(int param_1,int param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  int *piVar2;
  bool bVar3;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    return false;
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  iVar1 = *(int *)(param_1 + 0xc) + -1;
  if (param_2 <= iVar1) {
    iVar1 = param_2;
  }
  *param_3 = -1;
  *param_4 = 0xffffffff;
  piVar2 = (int *)(iVar1 * 0x24 + *(int *)(param_1 + 0x10));
  bVar3 = *piVar2 == 1;
  if (bVar3) {
    *param_3 = piVar2[1];
    *param_4 = *(undefined4 *)(iVar1 * 0x24 + 0xc + *(int *)(param_1 + 0x10));
  }
  return bVar3;
}

