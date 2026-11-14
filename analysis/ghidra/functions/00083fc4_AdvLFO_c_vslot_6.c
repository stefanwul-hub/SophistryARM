/* 00083fc4 AdvLFO_c_vslot_6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void AdvLFO_c_vslot_6(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  if (*param_2 == 0) {
    uVar3 = (**(code **)(*param_1 + 100))(param_1);
    pvVar4 = operator_new(0x20);
    FUN_000126be(pvVar4,uVar3,param_3,0xd);
    param_1[0x48] = (int)pvVar4;
    *param_2 = (int)pvVar4;
    *(undefined1 *)(param_1 + 0x5c) = 1;
  }
  iVar1 = *param_2;
  param_1[0x48] = iVar1;
  if ((iVar1 != 0) && (cVar2 = FUN_00011c32(iVar1), cVar2 == '\0')) {
    iVar1 = *(int *)(param_1[0x48] + 4);
    FUN_00011652(iVar1,"Version","",0,200,0x26ac,2,200,0);
    FUN_00010290(iVar1 + 0x70,"S0 On/Off",1);
    FUN_00010218(iVar1 + 0xe0,"Waveform","",0,5,6,1,"Sine  TriangSawtooSquareNoise Sam&Ho",0);
    FUN_00011652(iVar1 + 0x150,"Frequency","Hz",0x40800000,1,0xc80,2,100,0);
    FUN_00010290(iVar1 + 0x1c0,"Sync",1);
    FUN_00010218(iVar1 + 0x230,"Frequency","Notes",0xfffffff3,0x1a,5,7,
                 " Off 16/1*16/1 16/1T 8/1* 8/1  8/1T 4/1* 4/1  4/1T 2/1* 2/1  2/1T 1/1* 1/1  1/1T 1/2* 1/2  1/2T 1/4* 1/4  1/4T 1/8* 1/8  1/8T1/16*1/16 1/16T1/32*1/32 1/32T 1/64 5/16 7/16 9/16 5/8 11/1613/16 7/8 15/16"
                 ,0);
    FUN_00011652(iVar1 + 0x2a0,"Delay","sec",0x40800000,0,10000,3,0,4);
    FUN_00011652(iVar1 + 0x310,"Attack","sec",0x40800000,0,10000,3,0,4);
    FUN_00011652(iVar1 + 0x380,"Decay","sec",0x40800000,0,0x2711,3,0x2711,4);
    FUN_0001042e(iVar1 + 0x380,1);
    FUN_00011652(iVar1 + 0x460,"Symmetry","%",0,4,0x60,2,0x32,0);
    FUN_00011652(iVar1 + 0x4d0,"Phase","%",0,0,99,2,0,0);
    FUN_00011652(iVar1 + 0x540,"KeyTrack","%",0,0xffffff9c,100,0,0,0);
    FUN_00011b84();
    return;
  }
  return;
}

