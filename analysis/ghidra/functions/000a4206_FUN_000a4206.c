/* 000a4206 FUN_000a4206 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 FUN_000a4206(undefined4 param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 local_24;
  undefined4 local_20;
  
  if ((DAT_000fd520 == '\0') && (DAT_000fd51c != (int *)0x0)) {
    piVar2 = (int *)param_2[0x25];
    if (piVar2 == (int *)0x0) {
      iVar1 = param_2[0x19];
      piVar2 = (int *)operator_new(0x68);
      FUN_000a171a(piVar2,param_2,0,iVar1);
    }
    else {
      (**(code **)(*piVar2 + 0xc))(piVar2);
      piVar2 = (int *)param_2[0x25];
    }
    local_24 = 0;
    local_20 = 0;
    (**(code **)(*param_2 + 0x84))(param_2,piVar2,&local_24);
    (**(code **)(*param_2 + 0x38))(param_2,piVar2,DAT_000fd51c,&local_24);
    (**(code **)(*param_2 + 0x138))(param_2,0);
    (**(code **)(*piVar2 + 8))(piVar2);
    (**(code **)(*DAT_000fd51c + 8))(DAT_000fd51c);
    DAT_000fd51c = (int *)0x0;
  }
  return 0;
}

