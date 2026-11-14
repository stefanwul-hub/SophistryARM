/* 00025e4e FUN_00025e4e */

int FUN_00025e4e(int param_1,int param_2)

{
  int iVar1;
  
  if (((0 < param_2) && (param_2 < 0xc0)) &&
     (iVar1 = *(int *)(param_1 + 0x25858 + param_2 * 4), iVar1 != 0)) {
    return iVar1;
  }
  return 0;
}

