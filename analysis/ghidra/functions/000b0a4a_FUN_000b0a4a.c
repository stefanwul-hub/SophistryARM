/* 000b0a4a FUN_000b0a4a */

undefined4 FUN_000b0a4a(int param_1,FILE *param_2)

{
  size_t sVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 local_18 [4];
  int local_14;
  int local_10;
  
  sVar1 = _fread(&local_10,1,4,param_2);
  if (sVar1 == 4) {
    sVar1 = _fread(&local_14,1,4,param_2);
    if (sVar1 == 4) {
      sVar1 = _fread(local_18,1,4,param_2);
      if (sVar1 == 4) {
        if (*(char *)(param_1 + 0x260) == '\0') {
          piVar2 = *(int **)(param_1 + 0x264);
          if (piVar2 != (int *)0x0) {
            iVar4 = 0;
            do {
              if (local_10 == *piVar2) {
                iVar4 = piVar2[1];
                goto LAB_000b0af3;
              }
              piVar2 = piVar2 + 2;
              iVar4 = iVar4 + 8;
            } while (iVar4 != 0x20);
          }
          iVar4 = 0;
LAB_000b0af3:
          *(int *)(param_1 + 0x24c) = iVar4;
          *(int *)(param_1 + 0x250) = iVar4 + local_14;
        }
        uVar3 = 0;
      }
      else {
        _fclose(param_2);
        uVar3 = 0xfffffe4e;
      }
    }
    else {
      _fclose(param_2);
      uVar3 = 0xfffffe50;
    }
  }
  else {
    _fclose(param_2);
    uVar3 = 0xfffffe52;
  }
  return uVar3;
}

