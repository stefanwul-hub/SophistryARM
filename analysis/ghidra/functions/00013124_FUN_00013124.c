/* 00013124 FUN_00013124 */

void * FUN_00013124(undefined4 param_1,int param_2)

{
  void *pvVar1;
  uint uVar2;
  
  uVar2 = (param_2 + 0x10U & 0x3ffffffc) * 4 + 0x10 | 0x10;
  pvVar1 = _malloc(uVar2);
  if (pvVar1 != (void *)0x0) {
    _memset(pvVar1,0,uVar2);
  }
  return pvVar1;
}

