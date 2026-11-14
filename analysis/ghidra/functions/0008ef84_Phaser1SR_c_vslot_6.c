/* 0008ef84 Phaser1SR_c_vslot_6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Phaser1SR_c_vslot_6(int *param_1,int *param_2,undefined4 param_3)

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
    *(undefined1 *)(param_1 + 0x5c) = 1;
    iVar4 = FUN_00011b72(param_1[0x48],0);
    param_1[0x49] = iVar4;
  }
  iVar4 = *param_2;
  param_1[0x48] = iVar4;
  if ((iVar4 != 0) && (cVar1 = FUN_00011c32(iVar4), cVar1 == '\0')) {
    iVar4 = *(int *)(param_1[0x48] + 4);
    FUN_00011652(iVar4,"Version","",0,200,0x26ac,2,200,0);
    FUN_00010290(iVar4 + 0x70,"OffOn",1);
    FUN_00011652(iVar4 + 0xe0,"Phaser Wet","%",0,0,100,2,0x3c,0);
    FUN_00011652(iVar4 + 0x150,"Phaser Speed","Hz",0x40000000,0x28,1000,3,400,0);
    FUN_00011652(iVar4 + 0x1c0,"Phaser Center","Hz",0,100,10000,0,0x6e0,0);
    FUN_00011652(iVar4 + 0x230,"Phaser Depth","%",0,1,99,2,0x3c,0);
    FUN_00011652(iVar4 + 0x2a0,"Phaser Feedb","%",0,0,99,2,0x32,0);
    FUN_00010290(iVar4 + 0x310,"Phaser FBInv",1);
    FUN_00011652(iVar4 + 0x380,"Phaser Stages","",0,1,9,0,5,0);
    FUN_00011652(iVar4 + 0x3f0,"Phaser Stereo","%",0,0,100,2,0,0);
    FUN_00010218(iVar4 + 0x460,"Frequency","Notes",0xfffffff3,0xb,5,0xfffffff3,
                 " Off 16/1*16/1 16/1T 8/1* 8/1  8/1T 4/1* 4/1  4/1T 2/1* 2/1  2/1T 1/1* 1/1  1/1T 1/2* 1/2  1/2T 1/4* 1/4  1/4T 1/8* 1/8  1/8T"
                 ,0);
    FUN_00011b84();
    return;
  }
  return;
}

