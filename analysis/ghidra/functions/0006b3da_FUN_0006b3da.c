/* 0006b3da FUN_0006b3da */

int FUN_0006b3da(int param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  ushort *puVar3;
  int iVar4;
  int local_24;
  undefined4 local_14;
  uint local_10;
  
  FUN_00009b22(param_1 + 4,&local_10);
  uVar1 = local_10;
  if (0x7fffffff < local_10) {
    uVar1 = local_10 + 3;
  }
  iVar2 = ((int)uVar1 >> 2) + -1;
  if (0 < iVar2) {
    local_24 = 0;
    do {
      FUN_00009b6e(param_1 + 4,&local_14,4);
      iVar4 = -1;
      puVar3 = (ushort *)param_2[1];
      do {
        iVar4 = iVar4 + 1;
        if (((iVar4 < *param_2) && ((int)(uint)*puVar3 <= local_24)) &&
           (local_24 < (int)(uint)puVar3[1])) goto LAB_0006b49f;
        puVar3 = puVar3 + 0x3e;
      } while (iVar4 < *param_2);
      iVar4 = 0;
LAB_0006b49f:
      FUN_0006ab56(param_1,local_14,(ushort *)param_2[1] + iVar4 * 0x3e + 4);
      local_24 = local_24 + 1;
    } while (iVar2 != local_24);
  }
  _fseek(*(FILE **)(param_1 + 0xc),4,1);
  return local_10 + 4;
}

