/* 00084e96 EnvDAD_c_vslot_6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void EnvDAD_c_vslot_6(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  if (*param_2 == 0) {
    uVar3 = (**(code **)(*param_1 + 100))(param_1);
    pvVar4 = operator_new(0x20);
    FUN_000126be(pvVar4,uVar3,param_3,6);
    param_1[0x48] = (int)pvVar4;
    *param_2 = (int)pvVar4;
    *(undefined1 *)(param_1 + 0x5c) = 1;
  }
  iVar1 = *param_2;
  param_1[0x48] = iVar1;
  if ((iVar1 != 0) && (cVar2 = FUN_00011c32(iVar1), cVar2 == '\0')) {
    iVar1 = *(int *)(param_1[0x48] + 4);
    FUN_00011652(iVar1,"Version","",0,200,0x26ac,2,200,0);
    FUN_00011652(iVar1 + 0x70,"A Time","sec",0x40800000,0,10000,3,0,0);
    FUN_00011652(iVar1 + 0xe0,"H Time","sec",0x40800000,0,10000,3,0,0);
    FUN_00011652(iVar1 + 0x150,"D Time","sec",0x40800000,1,0x2711,3,0x2711,0);
    FUN_0001042e(iVar1 + 0x150,1);
    FUN_00011652(iVar1 + 0x1c0,"Pitch Scal","%",0,0xffffff9c,100,0,0,0);
    FUN_00011652(iVar1 + 0x230,"Veloc.Scal","%",0,0xffffff9c,100,0,0,0);
    FUN_00011b84();
    return;
  }
  return;
}

