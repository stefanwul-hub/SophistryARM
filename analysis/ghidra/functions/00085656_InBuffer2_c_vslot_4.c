/* 00085656 InBuffer2_c_vslot_4 */

void InBuffer2_c_vslot_4(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int aiStack_28 [7];
  
  aiStack_28[1] = 0;
  aiStack_28[2] = 2;
  aiStack_28[3] = 4;
  aiStack_28[4] = 5;
  aiStack_28[5] = 6;
  aiStack_28[6] = 7;
  if (0 < *(int *)(param_1 + 0x14)) {
    iVar1 = *(int *)(param_1 + 0x14);
    iVar3 = 1;
    do {
      *(undefined4 *)(param_1 + 0x34 + aiStack_28[iVar3] * 4) =
           *(undefined4 *)(param_2 + -4 + iVar3 * 4);
      bVar2 = iVar3 < iVar1;
      iVar3 = iVar3 + 1;
    } while (bVar2);
  }
  return;
}

