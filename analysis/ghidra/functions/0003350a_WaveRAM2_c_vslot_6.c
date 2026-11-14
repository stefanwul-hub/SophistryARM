/* 0003350a WaveRAM2_c_vslot_6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void WaveRAM2_c_vslot_6(int param_1,int *param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int local_20;
  
  if (*param_2 == 0) {
    *param_2 = *(int *)(param_1 + 0x120);
  }
  cVar2 = FUN_00011c32(*(undefined4 *)(param_1 + 0x120));
  if (cVar2 == '\0') {
    iVar1 = *(int *)(*(int *)(param_1 + 0x120) + 4);
    FUN_00011652(iVar1,"Version","",0,200,0x26ac,2,300,0);
    FUN_00010290(iVar1 + 0x70,"Reserve00",0);
    FUN_00011652(iVar1 + 0xe0,"Distortion","%",0,0,100,2,0,0);
    FUN_00011652(iVar1 + 0x150,"Compression",":1",0,100,2000,2,100,0);
    FUN_00011652(iVar1 + 0x1c0,"BitCrushing","Bit",0,10,0xf0,1,0xf0,0);
    FUN_00010290(iVar1 + 0x230,"Key Sync",0);
    FUN_00010290(iVar1 + 0x2a0,"Reserve05",0);
    FUN_00010290(iVar1 + 0x310,"Reserve06",0);
    FUN_00010290(iVar1 + 0x380,"Reserve07",0);
    iVar3 = iVar1 + 0x3f0;
    local_20 = 0x40;
    do {
      FUN_00010f72(iVar3,"Filename",1,0,0);
      FUN_000117e2(iVar3 + 0x70,"Root",0,0x7f,0,0x3c);
      FUN_000117e2(iVar3 + 0xe0,"Zone Lo",0,0x7f,0,0);
      FUN_000117e2(iVar3 + 0x150,"Zone Hi",0,0x80,0,0x7f);
      FUN_00011652(iVar3 + 0x1c0,"Velo Lo","",0,1,0x7f,0,1,0);
      FUN_00011652(iVar3 + 0x230,"Velo Hi","",0,1,0x7f,0,0x7f,0);
      FUN_00011652(iVar3 + 0x2a0,"Start Frame","Samples",0,0,9999999,0,0,0);
      FUN_00011652(iVar3 + 0x310,"End Frame","Samples",0,0,9999999,0,0,0);
      FUN_000118be(iVar3 + 0x380,"Volume",0xffffffd0,6,0,1);
      FUN_00011652(iVar3 + 0x3f0,"Panorama","",0,0xffffff9c,100,2,0,0);
      FUN_00010290(iVar3 + 0x460,"Reverse",0);
      FUN_00011652(iVar3 + 0x4d0,"Loop Start Frame","Samples",0,0,9999999,0,0,0);
      FUN_00011652(iVar3 + 0x540,"Loop End Frame","Samples",0,0,9999999,0,0,0);
      FUN_00011652(iVar3 + 0x5b0,"Loop Counter","Samples",0,1,9999,0,9999,0);
      FUN_00011652(iVar3 + 0x620,"Loop Mode","",0,0,3,0,0,0);
      FUN_00010f72(iVar3 + 0x690,"Cmd Load Filename",0,0,0);
      FUN_00011652(iVar3 + 0x700,"Loop Mod Range","Samples",0,1,9999999,0,10,0);
      FUN_00010290(iVar3 + 0x770,"Suppress AutoXCross",0);
      FUN_00010290(iVar3 + 0x7e0,"Alterne",0);
      FUN_00010290(iVar3 + 0x850,"Reserve4",0);
      iVar3 = iVar3 + 0x8c0;
      local_20 = local_20 + -1;
    } while (local_20 != 0);
    FUN_00010218(iVar1 + 0x233f0,"Alt Mode","",1,3,7,1,"CyclingRandom Random+",0);
    FUN_00011b84();
    return;
  }
  return;
}

