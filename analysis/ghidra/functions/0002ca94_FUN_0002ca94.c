/* 0002ca94 FUN_0002ca94 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

char * FUN_0002ca94(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  char *pcVar4;
  char local_15c [332];
  
  if (((*(int *)(param_1 + 0x298) < 1) || (param_2 < 0)) || (*(int *)(param_1 + 0x298) <= param_2))
  {
    pcVar4 = (char *)0x0;
  }
  else {
    _strcpy(local_15c,(char *)(param_1 + 1000));
    if (((*(int *)(param_1 + 0x2a4) == 0) || (local_15c[0] == '\0')) ||
       (iVar1 = *(int *)(*(int *)(param_1 + 0x2a4) + param_2 * 4),
       iVar1 == *(int *)(param_1 + 0x2a0))) {
      pcVar4 = (char *)(param_1 + 0x2a8);
      *(undefined4 *)(param_1 + 0x2a8) = 0x6c756166;
      *(undefined2 *)(param_1 + 0x2ac) = 0x74;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x52c);
      if (iVar2 == 0) {
        cVar3 = FUN_000096c4(param_1 + 4);
        pcVar4 = (char *)(param_1 + 0x2a8);
        _sprintf(pcVar4,"%s%c%s",local_15c,(int)cVar3,iVar1);
      }
      else {
        cVar3 = FUN_000096c4(param_1 + 4);
        pcVar4 = (char *)(param_1 + 0x2a8);
        _sprintf(pcVar4,"%s%c%s.%s",local_15c,(int)cVar3,iVar1,iVar2);
      }
    }
  }
  return pcVar4;
}

