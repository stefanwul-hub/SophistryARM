/* 00039906 WaveRAM_c_vslot_6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void WaveRAM_c_vslot_6(int param_1,int *param_2)

{
  int iVar1;
  char cVar2;
  
  if (*param_2 == 0) {
    *param_2 = *(int *)(param_1 + 0x120);
  }
  cVar2 = FUN_00011c32(*(undefined4 *)(param_1 + 0x120));
  if (cVar2 == '\0') {
    iVar1 = *(int *)(*(int *)(param_1 + 0x120) + 4);
    FUN_00011652(iVar1,"Version","",0,200,0x26ac,2,300,0);
    FUN_00011652(iVar1 + 0x70,"InsIdx","",0,0,1,0,0,0);
    FUN_00011652(iVar1 + 0xe0,"SampleIdx","",0,0,1,0,0,0);
    FUN_00010f72(iVar1 + 0x150,"Filename",1,0,0);
    FUN_000117e2(iVar1 + 0x2a0,"Root",0x18,0x60,0,0x3c);
    FUN_00011652(iVar1 + 0x310,"Zone Low","",0,0,0x7f,0,0,0);
    FUN_00011652(iVar1 + 0x380,"Zone High","",0,0,0x7f,0,0x7f,0);
    FUN_00011652(iVar1 + 0x3f0,"Velo Low","",0,1,0x7f,0,1,0);
    FUN_00011652(iVar1 + 0x460,"Velo High","",0,1,0x7f,0,0x7f,0);
    FUN_00011652(iVar1 + 0x1c0,"Unus0","",0,0,999,0,0,0);
    FUN_000118be(iVar1 + 0x230,"Volume",0xffffffee,6,0,1);
    FUN_00010290(iVar1 + 0x4d0,"Reverse",0);
    FUN_00010290(iVar1 + 0x540,"MLEnable",0);
    FUN_00010290(iVar1 + 0x5b0,"Cmd Prev",0);
    FUN_00010f72(iVar1 + 0x620,"Cmd Load Filename",0,0,0);
    FUN_00010290(iVar1 + 0x690,"Cmd Next",0);
    FUN_00010290(iVar1 + 0x700,"Cmd Clear",0);
    FUN_00011652(iVar1 + 0x770,"Start Frame","%",0,0,0x3de,1,0,0);
    FUN_00011652(iVar1 + 0x7e0,"End Frame","%",0,10,1000,1,1000,0);
    FUN_00011b84();
    return;
  }
  return;
}

