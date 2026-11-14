/* 00015d52 SynGloIns_c_vslot_6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void SynGloIns_c_vslot_6(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  if (*param_2 == 0) {
    uVar3 = (**(code **)(*param_1 + 100))(param_1);
    pvVar4 = operator_new(0x20);
    FUN_000126be(pvVar4,uVar3,param_3,0x1f);
    param_1[0x48] = (int)pvVar4;
    *param_2 = (int)pvVar4;
    *(undefined1 *)(param_1 + 0x5c) = 1;
  }
  iVar1 = *param_2;
  param_1[0x48] = iVar1;
  if ((iVar1 != 0) && (cVar2 = FUN_00011c32(iVar1), cVar2 == '\0')) {
    iVar1 = *(int *)(param_1[0x48] + 4);
    FUN_00011652(iVar1,"Version","",0,200,0x26ac,2,200,0);
    FUN_00011652(iVar1 + 0x70,"Program","",0,0,param_1[0x75] + -1,0,0,0);
    FUN_00010290(iVar1 + 0xe0,"Unused",1);
    FUN_00011652(iVar1 + 0x150,"Output","",0,0,param_1[0x76] + -1,0,0,0);
    FUN_00010290(iVar1 + 0x1c0,"Mute",0);
    FUN_00010290(iVar1 + 0x230,"Solo",0);
    FUN_00011652(iVar1 + 0x2a0,"NotesOn","",0,0,8,0,0,0);
    param_1[0x77] = (int)"0  X  P  N  1  2  3  4  xxx";
    FUN_00010218(iVar1 + 0x310,"Choke","",0,8,3,0," - me prvnxt 1  2  3  4  5 ",param_1 + 0x77);
    FUN_00011728(iVar1 + 0x380,"InsChIdx",0,0x10,0x10);
    FUN_00010290(iVar1 + 0x460,"Edited",0);
    FUN_00010290(iVar1 + 0x4d0,"Legato",0);
    FUN_00011652(iVar1 + 0x540,"Pitch Bend Up Amount","semitones",0,0,0x18,0,2,0);
    FUN_00010218(iVar1 + 0x5b0,"Unused","",1,9,3,9," 1  2  3  4  5  6  7  8 all",0);
    FUN_00010f72(iVar1 + 0x620,"Preset Load Path",0,0,0);
    FUN_00010f72(iVar1 + 0x690,"Preset Save Path",0,0,0);
    FUN_00010f72(iVar1 + 0x700,"Global Display",0,0,0);
    FUN_000117e2(iVar1 + 0x770,"Trigger",0,0x7f,0,0x24);
    FUN_00011652(iVar1 + 0x7e0,"Bank","",0,0,0x7f,0,0,0);
    FUN_000117e2(iVar1 + 0x850,"Note Lo",0,0x7f,0,0);
    FUN_000117e2(iVar1 + 0x8c0,"Note Lo",0,0x7f,0,0x7f);
    FUN_00011652(iVar1 + 0x930,"Velo Lo","",0,1,0x7f,0,1,0);
    FUN_00011652(iVar1 + 0x9a0,"Velo Hi","",0,1,0x7f,0,0x7f,0);
    FUN_00011652(iVar1 + 0xa10,"Note Fade","",0,0xffffffe8,0x18,0,0,0);
    FUN_00011652(iVar1 + 0xa80,"Velo Fade","",0,0xffffff81,0x7f,0,0,0);
    FUN_00010218(iVar1 + 0xaf0,"Pitch Bend Down Amount","semitones",0xffffffff,0x18,4,0xffffffff,
                 "link  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23  24 "
                 ,0);
    FUN_00010290(iVar1 + 0xb60,"Receive Mod Wheel",1);
    FUN_00010290(iVar1 + 0xbd0,"Receive Pitchwheel",1);
    FUN_00010290(iVar1 + 0xc40,"Receive Aftertouch",1);
    FUN_00010290(iVar1 + 0xcb0,"Receive SustainPed",1);
    FUN_000118be(iVar1 + 0xd20,"Master Vol",0xffffffe8,6,0,1);
    FUN_00011b84();
    return;
  }
  return;
}

