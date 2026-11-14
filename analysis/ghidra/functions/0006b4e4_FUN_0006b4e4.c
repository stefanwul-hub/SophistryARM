/* 0006b4e4 FUN_0006b4e4 */

int FUN_0006b4e4(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined2 local_24;
  undefined2 local_22;
  int local_20 [4];
  
  FUN_00009b22(param_1 + 4,local_20);
  iVar6 = local_20[0] + 3;
  if (-1 < local_20[0]) {
    iVar6 = local_20[0];
  }
  iVar1 = (iVar6 >> 2) + -1;
  *param_2 = iVar1;
  piVar2 = (int *)operator_new__(iVar1 * 0x7c + 4);
  piVar3 = piVar2 + 1;
  *piVar2 = iVar1;
  if (iVar6 >> 2 != 1) {
    iVar6 = 0;
    piVar2 = piVar3;
    do {
      piVar5 = piVar2 + 2;
      piVar2[2] = -1;
      *(undefined1 *)(piVar2 + 3) = 0;
      piVar2[9] = -1;
      piVar2[10] = 0x3f800000;
      piVar2[0xb] = 0;
      piVar2[0xc] = 0x7f;
      piVar2[0xd] = 0;
      piVar2[0xe] = 0x7f;
      piVar2[0xf] = 0x3f800000;
      piVar2[0x10] = 0;
      piVar2[0x11] = 0;
      piVar2[0x12] = -1;
      piVar2[0x13] = -1;
      piVar2[0x14] = -1;
      piVar2[0x15] = -1;
      piVar2[0x16] = -1;
      piVar2[0x17] = -1;
      *(undefined1 *)(piVar2 + 0x18) = 0;
      *(undefined1 *)((int)piVar2 + 0x61) = 0;
      iVar4 = 6;
      do {
        piVar5[0x17] = 0;
        piVar5 = piVar5 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      piVar2[0x1d] = 0x3f800000;
      *(undefined2 *)piVar2 = 0;
      *(undefined2 *)((int)piVar2 + 2) = 0;
      *(undefined2 *)(piVar2 + 1) = 0;
      *(undefined2 *)((int)piVar2 + 6) = 0;
      piVar2 = piVar2 + 0x1f;
      iVar6 = iVar6 + 1;
    } while (iVar6 != iVar1);
  }
  param_2[1] = (int)piVar3;
  if ((piVar3 != (int *)0x0) && (-1 < iVar1)) {
    iVar6 = 0;
    iVar4 = 0;
    do {
      FUN_00009b6e(param_1 + 4,&local_24,4);
      if (iVar6 < iVar1) {
        *(undefined2 *)(iVar4 + param_2[1]) = local_24;
        *(undefined2 *)(iVar4 + 4 + param_2[1]) = local_22;
      }
      if (0 < iVar6) {
        *(undefined2 *)(param_2[1] + -0x7a + iVar4) = local_24;
        *(undefined2 *)(param_2[1] + -0x76 + iVar4) = local_22;
      }
      iVar6 = iVar6 + 1;
      iVar4 = iVar4 + 0x7c;
    } while (iVar6 <= iVar1);
    return local_20[0] + 4;
  }
  return local_20[0] + 4;
}

