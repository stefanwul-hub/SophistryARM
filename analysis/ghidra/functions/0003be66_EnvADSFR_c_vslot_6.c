/* 0003be66 EnvADSFR_c_vslot_6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void EnvADSFR_c_vslot_6(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  if (*param_2 == 0) {
    uVar3 = (**(code **)(*param_1 + 100))(param_1);
    pvVar4 = operator_new(0x20);
    FUN_000126be(pvVar4,uVar3,param_3,0x13);
    param_1[0x48] = (int)pvVar4;
    *param_2 = (int)pvVar4;
    *(undefined1 *)(param_1 + 0x5c) = 1;
  }
  iVar1 = *param_2;
  param_1[0x48] = iVar1;
  if ((iVar1 != 0) && (cVar2 = FUN_00011c32(iVar1), cVar2 == '\0')) {
    iVar1 = *(int *)(param_1[0x48] + 4);
    FUN_00011652(iVar1,"Version","",0,200,0x26ac,2,200,0);
    FUN_00011652(iVar1 + 0x70,"A Time","sec",0x40800000,1,10000,3,1,0);
    FUN_00011652(iVar1 + 0xe0,"D Time","sec",0x40800000,1,10000,3,1,0);
    FUN_00011652(iVar1 + 0x150,"S Level","",0x40000000,0,1000,3,1000,0);
    FUN_00011652(iVar1 + 0x1c0,"F Time","",0,0xfffffc18,1000,2,0,0);
    FUN_00011652(iVar1 + 0x230,"R Time","sec",0x40800000,1,10000,3,4,0);
    FUN_00011652(iVar1 + 0x2a0,"Pitch Scal","%",0,0xffffff9c,100,0,0,0);
    FUN_00011652(iVar1 + 0x310,"Veloc.Scal","%",0,0xffffff9c,100,0,0,0);
    FUN_00010290(iVar1 + 0x380,"Velocity Attack",1);
    FUN_00010290(iVar1 + 0x3f0,"Log Decay",0);
    FUN_00011652(iVar1 + 0x460,"A c","",0,0xf,0xb9,2,0x47,0);
    FUN_00011652(iVar1 + 0x4d0,"D c","",0,0xf,0xb9,2,0x21,0);
    FUN_00011652(iVar1 + 0x540,"F c","",0,0xf,0xb9,2,0x5a,0);
    FUN_00011652(iVar1 + 0x5b0,"R c","",0,0xf,0xb9,2,0x21,0);
    FUN_00010290(iVar1 + 0x620,"Sync",0);
    FUN_00011652(iVar1 + 0x690,"ASync","16th",0,0,&DAT_00002580,2,100,0);
    FUN_00011652(iVar1 + 0x700,"DSync","16th",0,0,&DAT_00002580,2,100,0);
    FUN_00011652(iVar1 + 0x770,"FSync","16th",0,0xffffda80,&DAT_00002580,2,0,0);
    FUN_00011652(iVar1 + 0x7e0,"RSync","16th",0,0,&DAT_00002580,2,100,0);
    FUN_00011b84();
    return;
  }
  return;
}

