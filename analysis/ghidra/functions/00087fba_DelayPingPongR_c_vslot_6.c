/* 00087fba DelayPingPongR_c_vslot_6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void DelayPingPongR_c_vslot_6(int *param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  
  if (*param_2 == 0) {
    uVar2 = (**(code **)(*param_1 + 100))(param_1);
    pvVar3 = operator_new(0x20);
    FUN_000126be(pvVar3,uVar2,param_3,0xc);
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
    FUN_00011652(iVar4 + 0x70,"Time Center","msec",0x40800000,1,0x514,0,0x7d,0);
    FUN_00010218(iVar4 + 0xe0,"Sync Center","Notes",3,0x16,5,0xd,
                 " Off  1/2  1/2T 1/4* 1/4  1/4T 1/8* 1/8  1/8T1/16*1/16 1/16T1/32*1/32 1/32T 1/64 5/16 7/16 9/16 5/8 "
                 ,0);
    FUN_00011652(iVar4 + 0x150,"Time Left","msec",0x40800000,1,0x514,0,0x7d,0);
    FUN_00010218(iVar4 + 0x1c0,"Sync Left","Notes",3,0x16,5,7,
                 " Off  1/2  1/2T 1/4* 1/4  1/4T 1/8* 1/8  1/8T1/16*1/16 1/16T1/32*1/32 1/32T 1/64 5/16 7/16 9/16 5/8 "
                 ,0);
    FUN_00011652(iVar4 + 0x230,"Pan Left","",0,0xffffff9c,100,2,0xffffff9c,0);
    FUN_00011652(iVar4 + 0x2a0,"Time Right","msec",0x40800000,1,0x514,0,0x7d,0);
    FUN_00010218(iVar4 + 0x310,"Sync Right","Notes",3,0x16,5,10,
                 " Off  1/2  1/2T 1/4* 1/4  1/4T 1/8* 1/8  1/8T1/16*1/16 1/16T1/32*1/32 1/32T 1/64 5/16 7/16 9/16 5/8 "
                 ,0);
    FUN_00011652(iVar4 + 0x380,"Pan Right","",0,0xffffff9c,100,2,100,0);
    FUN_00011652(iVar4 + 0x3f0,"Feedback L+R","%",0,0,99,2,0x28,0);
    FUN_00011652(iVar4 + 0x460,"Balance Pre/LR","%",0,0,100,2,0x32,0);
    FUN_00011652(iVar4 + 0x4d0,"Wet","%",0,0,100,2,0xf,0);
    FUN_00011b84(param_1[0x48]);
                    /* WARNING: Could not recover jumptable at 0x0008840b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0xd8))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00088011. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xd8))();
  return;
}

