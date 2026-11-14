/* 000410f8 Chorus1_c_vslot_6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Chorus1_c_vslot_6(int *param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  
  if (*param_2 == 0) {
    uVar2 = (**(code **)(*param_1 + 100))(param_1);
    pvVar3 = operator_new(0x20);
    FUN_000126be(pvVar3,uVar2,param_3,0xb);
    param_1[0x48] = (int)pvVar3;
    *param_2 = (int)pvVar3;
    iVar4 = FUN_00011b72(param_1[0x48],0);
    param_1[0x49] = iVar4;
    *(undefined1 *)(param_1 + 0x5c) = 1;
  }
  iVar4 = *param_2;
  param_1[0x48] = iVar4;
  if ((iVar4 != 0) && (cVar1 = FUN_00011c32(iVar4), cVar1 == '\0')) {
    iVar4 = *(int *)(param_1[0x48] + 4);
    FUN_00011652(iVar4,"Version","",0,200,0x26ac,2,200,0);
    FUN_00010290(iVar4 + 0x70,"OffOn",1);
    FUN_00011652(iVar4 + 0xe0,"Chorus Time","ms",0x40800000,1,600,2,200,0);
    FUN_00011652(iVar4 + 0x150,"Chorus TimeSpread","%",0,0,0x5a,2,0x1e,0);
    FUN_00011652(iVar4 + 0x1c0,"Chorus Speed","Hz",0x40800000,0x14,4000,3,500,0);
    FUN_00011652(iVar4 + 0x230,"Chorus SpeedSpread","%",0,0,0x5a,2,0x1e,0);
    FUN_00011652(iVar4 + 0x2a0,"Chorus Wet","%",0,0,100,2,0x3c,0);
    FUN_00011652(iVar4 + 0x310,"Chorus Mode","",0,0,1,0,0,0);
    FUN_00010290(iVar4 + 0x380,"Invert Signal",0);
    FUN_00011652(iVar4 + 0x3f0,"Chorus Dry","%",0,0,100,2,100,0);
    FUN_00011652(iVar4 + 0x460,"Chorus Stereo","%",0,0,100,2,100,0);
    FUN_00011b84();
    return;
  }
  return;
}

