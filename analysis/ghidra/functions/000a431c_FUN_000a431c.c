/* 000a431c FUN_000a431c */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 FUN_000a431c(short param_1,undefined4 param_2,int *param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 local_28;
  undefined4 local_24;
  ushort local_1e [7];
  
  if (DAT_000fd520 == '\0') {
    if (param_1 == 3) {
      piVar3 = (int *)param_3[0x25];
      if (piVar3 == (int *)0x0) {
        iVar1 = param_3[0x19];
        piVar3 = (int *)operator_new(0x68);
        FUN_000a171a(piVar3,param_3,0,iVar1);
      }
      else {
        (**(code **)(*piVar3 + 0xc))(piVar3);
        piVar3 = (int *)param_3[0x25];
      }
      local_28 = 0;
      local_24 = 0;
      (**(code **)(*param_3 + 0x84))(param_3,piVar3,&local_28);
      (**(code **)(*param_3 + 0x44))(param_3,piVar3,DAT_000fd51c,&local_28);
      (**(code **)(*piVar3 + 8))(piVar3);
      return 0;
    }
    if (param_1 == 4) {
      piVar3 = (int *)param_3[0x25];
      if (piVar3 == (int *)0x0) {
        iVar1 = param_3[0x19];
        piVar3 = (int *)operator_new(0x68);
        FUN_000a171a(piVar3,param_3,0,iVar1);
      }
      else {
        (**(code **)(*piVar3 + 0xc))(piVar3);
        piVar3 = (int *)param_3[0x25];
      }
      local_28 = 0;
      local_24 = 0;
      (**(code **)(*param_3 + 0x84))(param_3,piVar3,&local_28);
      (**(code **)(*param_3 + 0x40))(param_3,piVar3,DAT_000fd51c,&local_28);
      (**(code **)(*param_3 + 0x138))(param_3,0);
      (**(code **)(*piVar3 + 8))(piVar3);
      (**(code **)(*DAT_000fd51c + 8))(DAT_000fd51c);
      DAT_000fd51c = (int *)0x0;
      return 0;
    }
    if (param_1 == 2) {
      if (DAT_000fd51c != (int *)0x0) {
        (**(code **)(*DAT_000fd51c + 8))(DAT_000fd51c);
      }
      piVar2 = (int *)operator_new(0x18);
      piVar2[1] = 1;
      *piVar2 = (int)&PTR_CDragContainer_vslot_0_000f4400;
      piVar2[2] = param_4;
      piVar2[3] = 0;
      piVar2[4] = 0;
      piVar2[5] = 0;
      _CountDragItems(param_4,local_1e);
      piVar2[3] = (uint)local_1e[0];
      piVar3 = (int *)param_3[0x25];
      DAT_000fd51c = piVar2;
      if (piVar3 == (int *)0x0) {
        iVar1 = param_3[0x19];
        piVar3 = (int *)operator_new(0x68);
        FUN_000a171a(piVar3,param_3,0,iVar1);
      }
      else {
        (**(code **)(*piVar3 + 0xc))(piVar3);
        piVar3 = (int *)param_3[0x25];
      }
      local_28 = 0;
      local_24 = 0;
      (**(code **)(*param_3 + 0x138))(param_3,8);
      (**(code **)(*param_3 + 0x84))(param_3,piVar3,&local_28);
      (**(code **)(*param_3 + 0x3c))(param_3,piVar3,DAT_000fd51c,&local_28);
      (**(code **)(*piVar3 + 8))(piVar3);
    }
  }
  return 0;
}

