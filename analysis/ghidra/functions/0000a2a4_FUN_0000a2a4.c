/* 0000a2a4 FUN_0000a2a4 */

bool FUN_0000a2a4(undefined4 param_1,char *param_2,char *param_3,undefined4 param_4)

{
  bool bVar1;
  void *pvVar2;
  int local_10;
  
  if (((param_2 != (char *)0x0) && (*param_2 != '\0')) && (param_3 != (char *)0x0)) {
    local_10 = 0;
    pvVar2 = _malloc(0xa0000);
    if (pvVar2 != (void *)0x0) {
      FUN_0000a13a(param_1,param_2,pvVar2,&local_10,param_4);
      bVar1 = 0 < local_10;
      if (bVar1) {
        FUN_00009cd6(param_1,pvVar2,local_10);
        _strcpy(param_3,param_2);
        FUN_0000a024(param_1,param_3,pvVar2);
      }
      else {
        *param_3 = '\0';
      }
      _free(pvVar2);
      return bVar1;
    }
  }
  return false;
}

