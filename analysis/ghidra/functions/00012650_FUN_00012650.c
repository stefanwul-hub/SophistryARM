/* 00012650 FUN_00012650 */

void FUN_00012650(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_3 < 0) {
    param_3 = 0;
  }
  iVar2 = *(int *)(param_1 + 0x18) + -1;
  if (param_3 <= iVar2) {
    iVar2 = param_3;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x1c) + param_2 * 4);
  if (iVar1 != 0) {
    iVar1 = iVar1 + iVar2 * 0x70;
    *param_4 = *(undefined4 *)(iVar1 + 0x20);
    param_4[1] = *(undefined4 *)(iVar1 + 0x24);
    param_4[2] = *(undefined4 *)(iVar1 + 0x28);
    param_4[3] = *(undefined4 *)(iVar1 + 0x2c);
    param_4[4] = *(undefined4 *)(iVar1 + 0x30);
    param_4[5] = *(undefined4 *)(iVar1 + 0x34);
    param_4[6] = *(undefined4 *)(iVar1 + 0x38);
  }
  return;
}

