/* 000153b6 SynGlo_c_vslot_5 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void SynGlo_c_vslot_5(int *param_1,int *param_2)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  if (*param_2 == 0) {
    uVar3 = (**(code **)(*param_1 + 100))(param_1);
    pvVar4 = operator_new(0x20);
    FUN_000126be(pvVar4,uVar3,1,0x22);
    param_1[0x48] = (int)pvVar4;
    *param_2 = (int)pvVar4;
    *(undefined1 *)(param_1 + 0x5c) = 1;
  }
  iVar1 = *param_2;
  param_1[0x48] = iVar1;
  if ((iVar1 != 0) && (cVar2 = FUN_00011c32(iVar1), cVar2 == '\0')) {
    iVar1 = *(int *)(param_1[0x48] + 4);
    FUN_00011652(iVar1,"Version","",0,200,0x26ac,2,200,0);
    FUN_00011652(iVar1 + 0x70,"Edit Ins","",0,0,0x40,0,0,0);
    FUN_00010290(iVar1 + 0xe0,"Undo/Redo",0);
    FUN_00011652(iVar1 + 0x150,"Glo Tune","",0,0x1039,0x1236,1,0x1130,0);
    FUN_00010290(iVar1 + 0x1c0,"CCAssignActive",0);
    FUN_00010290(iVar1 + 0x230,"Dummy for Save/Load Presets notification to host",0);
    FUN_00011652(iVar1 + 0x2a0,"CPU Load","%",0,0,1000,1,0,0);
    FUN_00011652(iVar1 + 0x310,"SRFactor","",0,10,100,2,100,0);
    FUN_00011652(iVar1 + 0x380,"VelCurve","",0,0,9,0,5,0);
    FUN_00010290(iVar1 + 0x3f0,"Automatik 1",0);
    FUN_00011652(iVar1 + 0x460,"keyboard","",0,0,&PTR_CFrame_vslot_62_000f4240,0,0,0);
    FUN_00011652(iVar1 + 0x4d0,"Stereo Outs","",0,0,param_1[0x75],0,1,0);
    FUN_00011652(iVar1 + 0x540,"Mono Outs","",0,0,param_1[0x75],0,0,0);
    FUN_00010218(iVar1 + 0x5b0,"RM Ins MPD","",0,2,5,0,"Pan  LevelTune ",0);
    FUN_00010218(iVar1 + 0x620,"","",0,1,8,0,"Circular Linear ",0);
    FUN_00010290(iVar1 + 0x690,"",0);
    FUN_00011652(iVar1 + 0x700,"Generation Range","%",0x40800000,0,100,2,5,0);
    FUN_00010f72(iVar1 + 0x770,"ECS Save Path",0,0,0);
    FUN_00010f72(iVar1 + 0x7e0,"ECS Load Path",0,0,0);
    FUN_00010f72(iVar1 + 0x850,"Unused, use the one in SynGloIns",0,0,0);
    FUN_00011652(iVar1 + 0x8c0,"System Error Code","",0,0,0xffff,0,0,0);
    FUN_00010290(iVar1 + 0x930,"SynthEdited",0);
    FUN_00010290(iVar1 + 0x9a0,"Choke",1);
    FUN_00010218(iVar1 + 0xa10,"Sample Display","",0,1,4,0,"Off Norm",0);
    FUN_00010f72(iVar1 + 0xa80,"Kit Name Display",1,1,0);
    FUN_00011652(iVar1 + 0xaf0,"Edit Page","",0,0,99,0,0,0);
    FUN_00011652(iVar1 + 0xb60,"Program","",0,0,0x7f,0,0,0);
    FUN_00011652(iVar1 + 0xbd0,"Bank","",0,0,0x7f,0,0,0);
    FUN_000118be(iVar1 + 0xc40,"Master Vol",0xffffffe8,6,0,1);
    FUN_00010f72(iVar1 + 0xcb0,"Multi Save",0,0,0);
    FUN_00010f72(iVar1 + 0xd20,"Multi Load",0,0,0);
    FUN_00011652(iVar1 + 0xd90,"Pitch Bend Up Amount","semitones",0,0,0x18,0,2,0);
    FUN_00010218(iVar1 + 0xe00,"Pitch Bend Down Amount","semitones",0xffffffff,0x18,4,0xffffffff,
                 "link  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24 "
                 ,0);
    FUN_00010218(iVar1 + 0xe70,"MIDI CC Mode","",0,1,0xc,1,"receive onlyreceive+send",0);
    FUN_00011b84();
    return;
  }
  return;
}

