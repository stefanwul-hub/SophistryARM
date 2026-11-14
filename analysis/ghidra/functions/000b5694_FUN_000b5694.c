/* 000b5694 FUN_000b5694 */

undefined4 FUN_000b5694(int param_1,int *param_2,char *param_3,undefined4 param_4)

{
  FILE *pFVar1;
  char cVar2;
  int iVar3;
  size_t sVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  void *local_34;
  size_t local_24;
  int local_20 [4];
  
  if (((((param_2 == (int *)0x0) || (param_3 == (char *)0x0)) || (*(int *)(param_1 + 0x950) == 0))
      || ((iVar3 = FUN_00017d68(*(int *)(param_1 + 0x950),param_4), iVar3 == 0 ||
          (cVar2 = (**(code **)(**(int **)(param_1 + 0x950) + 0x17c))
                             (*(int **)(param_1 + 0x950),param_1 + 0x95c), cVar2 == '\0')))) ||
     (*param_3 == '\0')) {
    return 0;
  }
  FUN_0000979c(param_1 + 4,param_3);
  pFVar1 = *(FILE **)(param_1 + 0xc);
  if (pFVar1 == (FILE *)0x0) {
LAB_000b5717:
    local_34 = (void *)0x0;
  }
  else {
    _fread(local_20,1,4,pFVar1);
    iVar3 = (**(code **)(*param_2 + 100))(param_2);
    if (iVar3 != local_20[0]) goto LAB_000b5717;
    _fread(&local_24,1,4,pFVar1);
    if ((int)local_24 < 1) {
      local_34 = (void *)0x0;
      uVar7 = 0;
      goto LAB_000b5720;
    }
    local_34 = _malloc(local_24 + 1);
    if (local_34 != (void *)0x0) {
      _fseek(pFVar1,0,0);
      sVar4 = _fread(local_34,1,local_24,pFVar1);
      if ((local_24 == sVar4) && (piVar6 = (int *)param_2[0x48], piVar6 != (int *)0x0)) {
        piVar5 = (int *)FUN_00017d68(*(undefined4 *)(param_1 + 0x950),param_4);
        (**(code **)(*piVar5 + 0x4c))(piVar5,0);
        FUN_000243a6(*(undefined4 *)(param_1 + 0x950),param_4);
        (**(code **)(*piVar6 + 0x10))(piVar6,local_34,local_24,param_4);
        (**(code **)(*param_2 + 0x78))(param_2,param_4,0xffffffff);
        FUN_00017a3a(*(undefined4 *)(param_1 + 0x950),0xffffffff,0);
        (**(code **)(**(int **)(param_1 + 0x950) + 0x360))(*(int **)(param_1 + 0x950),param_4);
        FUN_00019410(*(undefined4 *)(param_1 + 0x950));
        piVar6 = (int *)FUN_00017d68(*(undefined4 *)(param_1 + 0x950),param_4);
        (**(code **)(*piVar6 + 0x4c))(piVar6,1);
        uVar7 = 1;
        goto LAB_000b5720;
      }
    }
  }
  uVar7 = 0;
LAB_000b5720:
  FUN_000098c4(param_1 + 4);
  if (local_34 == (void *)0x0) {
    return uVar7;
  }
  _free(local_34);
  return uVar7;
}

