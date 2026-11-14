/* 0008dcf0 FUN_0008dcf0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0008dcf0(int *param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  undefined1 local_3dc [320];
  undefined1 local_29c [320];
  char local_15c [332];
  
  if (param_2 != 0) {
    FUN_00012482(param_1[0x48],0,1,local_15c);
    if (local_15c[0] != '\0') {
      piVar2 = param_1 + 0x115;
      FUN_000098ea(piVar2,local_15c,local_29c);
      FUN_00009fa4(piVar2,param_2,local_29c);
      cVar1 = FUN_000096d0(piVar2,local_29c);
      if (cVar1 == '\0') {
        FUN_00009996(piVar2,param_2,local_3dc);
        FUN_0000a024(piVar2,local_3dc,"Samples");
        FUN_000098ea(piVar2,local_15c,local_29c);
        FUN_00009fa4(piVar2,local_3dc,local_29c);
      }
      FUN_00012432(param_1[0x48],0,1,local_29c);
      (**(code **)(*param_1 + 0x78))(param_1,0,1);
      return;
    }
  }
  return;
}

