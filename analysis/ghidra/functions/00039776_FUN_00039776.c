/* 00039776 FUN_00039776 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00039776(int *param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  undefined1 local_3dc [320];
  undefined1 local_29c [320];
  char local_15c [332];
  
  if (param_2 != 0) {
    FUN_00012482(param_1[0x48],0,3,local_15c);
    if (local_15c[0] != '\0') {
      piVar1 = param_1 + 0x116;
      FUN_000098ea(piVar1,local_15c,local_29c);
      FUN_00009fa4(piVar1,param_2,local_29c);
      cVar2 = FUN_000096d0(piVar1,local_29c);
      if (cVar2 == '\0') {
        FUN_00009996(piVar1,param_2,local_3dc);
        FUN_0000a024(piVar1,local_3dc,"Samples");
        FUN_000098ea(piVar1,local_15c,local_29c);
        FUN_00009fa4(piVar1,local_3dc,local_29c);
      }
      FUN_00012432(param_1[0x48],0,3,local_29c);
      (**(code **)(*param_1 + 0x78))(param_1,0,3);
      (**(code **)(*param_1 + 0x78))(param_1,0,0xb);
      return;
    }
  }
  return;
}

