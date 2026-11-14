/* 0001a04e FUN_0001a04e */

void FUN_0001a04e(int *param_1,int param_2)

{
  void *pvVar1;
  int iVar2;
  
  *param_1 = param_2;
  pvVar1 = _malloc(param_2 * 4 + 4);
  param_1[1] = (int)pvVar1;
  if ((pvVar1 != (void *)0x0) && (0 < param_2)) {
    iVar2 = 0;
    do {
      *(undefined4 *)(param_1[1] + iVar2 * 4) = 0xffffffff;
      iVar2 = iVar2 + 1;
    } while (param_2 != iVar2);
  }
  return;
}

