/* 0001c602 FUN_0001c602 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0001c602(int param_1,char *param_2)

{
  undefined4 uVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  undefined1 local_3dc [320];
  char local_29c [320];
  char local_15c [332];
  
  if (*(int *)(param_1 + 0x9a80) == 0) {
    iVar4 = FUN_00009ba6(param_1 + 0xc3d8,param_1);
    *(int *)(param_1 + 0x9a80) = iVar4;
    if (iVar4 == 0) {
      return;
    }
  }
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    _sprintf(local_15c,"%sMod_%s",*(undefined4 *)(param_1 + 0x3bac),param_2);
    cVar2 = FUN_000096c4(param_1 + 0xc3d8);
    uVar1 = *(undefined4 *)(param_1 + 0x3bac);
    cVar3 = FUN_000096c4(param_1 + 0xc3d8);
    _sprintf(local_29c,"%s%c%sMod%c%s",*(undefined4 *)(param_1 + 0x9a80),(int)cVar3,uVar1,(int)cVar2
             ,param_2);
    if (local_15c[0] != '\0') {
      cVar2 = FUN_0002e564(param_1 + 0x38a0,local_15c,local_3dc,0x13f);
      if (cVar2 == '\0') {
        FUN_0002e63a(param_1 + 0x38a0,local_15c,local_29c);
      }
    }
  }
  return;
}

