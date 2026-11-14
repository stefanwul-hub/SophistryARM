/* 000ad424 FUN_000ad424 */

uint FUN_000ad424(undefined4 param_1,undefined4 param_2,int *param_3)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_3 + 0xc))(param_3,param_2);
  return -(uint)(cVar1 == '\0') & 0xffffd96e;
}

