/* 0003eba6 DelayStereo_c_vslot_6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void DelayStereo_c_vslot_6(int *param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  
  if (*param_2 == 0) {
    uVar2 = (**(code **)(*param_1 + 100))(param_1);
    pvVar3 = operator_new(0x20);
    FUN_000126be(pvVar3,uVar2,param_3,0xe);
    param_1[0x48] = (int)pvVar3;
    *param_2 = (int)pvVar3;
    *(undefined1 *)(param_1 + 0x5c) = 1;
    iVar4 = FUN_00011b72(param_1[0x48],0);
    param_1[0x49] = iVar4;
  }
  iVar4 = *param_2;
  param_1[0x48] = iVar4;
  if (iVar4 == 0) {
    return;
  }
  cVar1 = FUN_00011c32(iVar4);
  if (cVar1 == '\0') {
    iVar4 = *(int *)(param_1[0x48] + 4);
    FUN_00011652(iVar4,"Version","",0,200,0x26ac,2,200,0);
    FUN_00010290(iVar4 + 0x70,"OffOn",1);
    FUN_00011652(iVar4 + 0xe0,"TimeL","msec",0x40800000,1,0x514,0,0x7d,0);
    FUN_00010218(iVar4 + 0x150,"SyncL","Notes",3,0x16,5,0xd,
                 " Off  1/2  1/2T 1/4* 1/4  1/4T 1/8* 1/8  1/8T1/16*1/16 1/16T1/32*1/32 1/32T 1/64 5/16 7/16 9/16 5/8 "
                 ,0);
    FUN_00011652(iVar4 + 0x1c0,"TimeR","msec",0x40800000,1,0x514,0,0xfa,0);
    FUN_00010218(iVar4 + 0x230,"SyncR","Notes",3,0x16,5,10,
                 " Off  1/2  1/2T 1/4* 1/4  1/4T 1/8* 1/8  1/8T1/16*1/16 1/16T1/32*1/32 1/32T 1/64 5/16 7/16 9/16 5/8 "
                 ,0);
    FUN_00011652(iVar4 + 0x2a0,"Feed","%",0,0,99,2,0x28,0);
    FUN_00011652(iVar4 + 0x310,"CutLo","Hz",0x40800000,0x28,22000,0,22000,0);
    FUN_00011652(iVar4 + 0x380,"CutHi","Hz",0x40800000,8,11000,0,8,0);
    FUN_00011652(iVar4 + 0x3f0,"Wet","%",0,0,100,2,0xf,0);
    FUN_00011652(iVar4 + 0x460,"Stereo","%",0,0xffffff9c,100,2,100,0);
    FUN_00010290(iVar4 + 0x4d0,"Feedback Link",1);
    FUN_00010290(iVar4 + 0x540,"Crossdelay",0);
    FUN_00010290(iVar4 + 0x5b0,"Filters in Feedback",0);
    FUN_00011b84(param_1[0x48]);
                    /* WARNING: Could not recover jumptable at 0x0003efd4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0xd8))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0003ec00. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xd8))();
  return;
}

