/* 000b58fc FUN_000b58fc */

bool FUN_000b58fc(int param_1,int param_2,char *param_3,undefined4 param_4)

{
  int *piVar1;
  void *pvVar2;
  size_t sVar3;
  undefined1 local_3a0 [8];
  FILE *local_398;
  char local_10c [256];
  
  if ((((param_2 != 0) && (*(int *)(param_1 + 0x954) != 0)) && (param_3 != (char *)0x0)) &&
     (*param_3 != '\0')) {
    _strcpy(local_10c,param_3);
    piVar1 = *(int **)(param_2 + 0x120);
    if (piVar1 != (int *)0x0) {
      pvVar2 = *(void **)(param_1 + 0x954);
      sVar3 = (**(code **)(*piVar1 + 0xc))(piVar1,pvVar2,param_4);
      if ((0 < (int)sVar3) && (pvVar2 != (void *)0x0)) {
        FUN_0000a5d4(local_3a0);
        FUN_00009848(local_3a0,local_10c);
        if (local_398 != (FILE *)0x0) {
          _fwrite(pvVar2,1,sVar3,local_398);
          FUN_000098c4(local_3a0);
        }
        Disk_c_vslot_0(local_3a0);
        return local_398 != (FILE *)0x0;
      }
    }
  }
  return false;
}

