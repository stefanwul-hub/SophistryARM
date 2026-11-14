/* 00029b92 SysGlo_c_vslot_5 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void SysGlo_c_vslot_5(int *param_1,int *param_2)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  if (*param_2 == 0) {
    uVar3 = (**(code **)(*param_1 + 100))(param_1);
    pvVar4 = operator_new(0x20);
    FUN_000126be(pvVar4,uVar3,1,8);
    param_1[0x48] = (int)pvVar4;
    *param_2 = (int)pvVar4;
    *(undefined1 *)(param_1 + 0x5c) = 1;
  }
  iVar1 = *param_2;
  param_1[0x48] = iVar1;
  if ((iVar1 != 0) && (cVar2 = FUN_00011c32(iVar1), cVar2 == '\0')) {
    iVar1 = *(int *)(param_1[0x48] + 4);
    FUN_00011652(iVar1,"Version","",0,200,0x26ac,2,200,0);
    FUN_00010f72(iVar1 + 0x70,"Serial Number",0,0,0);
    FUN_00010218(iVar1 + 0xe0,"Cir/Lin Knob Movement","",0,1,8,1,"Circular Linear ",0);
    FUN_00010290(iVar1 + 0x150,"NoteDisplayType",0);
    FUN_00010290(iVar1 + 0x1c0,"Pad Velocity",1);
    FUN_00010218(iVar1 + 0x230,"PanMode","",0,1,5,1,"EqVolEqPow",0);
    FUN_00010290(iVar1 + 0x2a0,"Jump To Save Dir",1);
    FUN_00010218(iVar1 + 0x310,"Font Color","",0,2,8,0,"Red     LightRedWhite   ",0);
    FUN_00011b84();
    return;
  }
  return;
}

