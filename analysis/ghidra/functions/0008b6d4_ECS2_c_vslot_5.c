/* 0008b6d4 ECS2_c_vslot_5 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void ECS2_c_vslot_5(int *param_1,int *param_2)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  int local_20;
  
  if (*param_2 == 0) {
    uVar2 = (**(code **)(*param_1 + 100))(param_1);
    pvVar3 = operator_new(0x20);
    FUN_000126be(pvVar3,uVar2,1,0x587);
    param_1[0x48] = (int)pvVar3;
    *param_2 = (int)pvVar3;
    *(undefined1 *)(param_1 + 0x5c) = 1;
  }
  iVar4 = *param_2;
  param_1[0x48] = iVar4;
  if (iVar4 != 0) {
    cVar1 = FUN_00011c32(iVar4);
    if (cVar1 == '\0') {
      iVar4 = *(int *)(param_1[0x48] + 4);
      FUN_00011652(iVar4,"Version","",0,200,0x26ac,2,200,0);
      FUN_00010290(iVar4 + 0x70,"On/Off",0);
      FUN_00010218(iVar4 + 0xe0,"Mode","",0,6,9,0,
                   "Off      Learn    Clear    Clear AllLoad     Save     Rest.Fact",0);
      FUN_00011652(iVar4 + 0x150,"Glo Reserved0","",0,0,1,0,0,0);
      FUN_00011652(iVar4 + 0x1c0,"Glo Reserved1","",0,0,1,0,0,0);
      FUN_00010290(iVar4 + 0x230,"Glo Reserved Sw0",0);
      FUN_00010290(iVar4 + 0x2a0,"Glo Reserved Sw1",0);
      iVar4 = iVar4 + 0x310;
      local_20 = 0x80;
      do {
        FUN_00011652(iVar4,"CCIdx","",0,0,999999999,0,0,0);
        FUN_00011652(iVar4 + 0x70,"EditIdx","",0,0,999999999,0,0,0);
        FUN_00011652(iVar4 + 0xe0,"Min Par","",0,0,1000,1,0,0);
        FUN_00011652(iVar4 + 0x150,"Max Par","",0,0,1000,1,1000,0);
        FUN_00011652(iVar4 + 0x1c0,"Ins Idx","",0,0,0x400,0,0,0);
        FUN_00011652(iVar4 + 0x230,"MIDI Ch","",0,0,0xf,0,0,0);
        FUN_00011652(iVar4 + 0x2a0,"Curve","",0,0xfffffff7,9,0,0,0);
        FUN_00010218(iVar4 + 0x310,"Mode","",0,4,10,0,
                     "Unused    Normal    Relative ARelative BRelative C",0);
        FUN_00011652(iVar4 + 0x380,"Min CC","",0,0,0x7f,0,0,0);
        FUN_00011652(iVar4 + 0x3f0,"Max CC","",0,0,0x7f,0,0,0);
        FUN_00011652(iVar4 + 0x460,"Res2","",0,0,1,0,0,0);
        iVar4 = iVar4 + 0x4d0;
        local_20 = local_20 + -1;
      } while (local_20 != 0);
      FUN_00011b84(param_1[0x48]);
    }
    param_1[0x49] = *(int *)(param_1[0x48] + 4);
  }
  return;
}

