/* 000104be FUN_000104be */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000104be(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int local_30;
  char local_24 [20];
  
  local_30 = *(int *)(param_1 + 100);
  if (local_30 == 0) {
    iVar3 = 0;
    local_30 = 0;
switchD_00010546_caseD_0:
    _sprintf(local_24,"C%d",iVar3);
  }
  else {
    iVar2 = *(int *)(param_1 + 0x5c) / local_30;
    local_30 = *(int *)(param_1 + 0x5c) % local_30;
    iVar3 = iVar2 / 0xc + -2;
    switch(iVar2 % 0xc) {
    case 0:
      goto switchD_00010546_caseD_0;
    case 1:
      _sprintf(local_24,"C#%d",iVar3);
      break;
    case 2:
      _sprintf(local_24,"D%d",iVar3);
      break;
    case 3:
      _sprintf(local_24,"D#%d",iVar3);
      break;
    case 4:
      _sprintf(local_24,"E%d",iVar3);
      break;
    case 5:
      _sprintf(local_24,"F%d",iVar3);
      break;
    case 6:
      _sprintf(local_24,"F#%d",iVar3);
      break;
    case 7:
      _sprintf(local_24,"G%d",iVar3);
      break;
    case 8:
      _sprintf(local_24,"G#%d",iVar3);
      break;
    case 9:
      _sprintf(local_24,"A%d",iVar3);
      break;
    case 10:
      _sprintf(local_24,"A#%d",iVar3);
      break;
    case 0xb:
      _sprintf(local_24,"B%d",iVar3);
    }
  }
  if (param_2 == (char *)0x0) {
    return;
  }
  if (*(int *)(param_1 + 0x5c) == 0x80) {
    builtin_strncpy(param_2,"all",4);
    return;
  }
  if (*(int *)(param_1 + 0x54) == 0) {
    cVar1 = FUN_0002d6ea(param_1 + 0x68,4);
    if (cVar1 != '\0') {
      _strcpy(param_2,local_24);
      return;
    }
    if (*(int *)(param_1 + 0x54) == 0) {
      cVar1 = FUN_0002d6ea(param_1 + 0x68,4);
      if (cVar1 == '\0') {
        _sprintf(param_2,"%d",*(undefined4 *)(param_1 + 0x5c));
        return;
      }
      if (*(int *)(param_1 + 0x54) != 2) {
        return;
      }
      goto LAB_000105eb;
    }
  }
  if (*(int *)(param_1 + 0x54) != 2) {
    return;
  }
LAB_000105eb:
  _sprintf(param_2,"%s %02dc",local_24,local_30);
  return;
}

