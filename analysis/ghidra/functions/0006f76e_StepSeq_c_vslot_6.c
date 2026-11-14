/* 0006f76e StepSeq_c_vslot_6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void StepSeq_c_vslot_6(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  if (*param_2 == 0) {
    uVar3 = (**(code **)(*param_1 + 100))(param_1);
    pvVar4 = operator_new(0x20);
    FUN_000126be(pvVar4,uVar3,param_3,0xe);
    param_1[0x48] = (int)pvVar4;
    *param_2 = (int)pvVar4;
    *(undefined1 *)(param_1 + 0x5c) = 1;
  }
  iVar1 = *param_2;
  param_1[0x48] = iVar1;
  if ((iVar1 != 0) && (cVar2 = FUN_00011c32(iVar1), cVar2 == '\0')) {
    iVar1 = *(int *)(param_1[0x48] + 4);
    FUN_00011652(iVar1,"Version","",0,200,0x26ac,2,200,0);
    FUN_00010290(iVar1 + 0x70,"On/Off",1);
    FUN_00010218(iVar1 + 0xe0,"Op.Mode","",0,10,8,0,
                 "Off     Mod-OnlyUp      Down    Up/Down Up/Down+Down/Up Down/Up+Random  Chord   AsPlayed"
                 ,0);
    FUN_00010218(iVar1 + 0x150,"Resolution","Notes",1,0x12,5,0xd,
                 " 1/1  1/1T 1/2* 1/2  1/2T 1/4* 1/4  1/4T 1/8* 1/8  1/8T1/16*1/16 1/16T1/32*1/32 1/32T 1/64"
                 ,0);
    FUN_00011652(iVar1 + 0x1c0,"Length","Steps",0,2,param_1[0x77],0,0x10,0);
    FUN_00011652(iVar1 + 0x230,"Octaves","Oct",0,1,4,0,1,0);
    FUN_00011652(iVar1 + 0x2a0,"Swing","%",0,0,100,0,0,0);
    FUN_00011652(iVar1 + 0x310,"Played Veloc","%",0,0,100,0,0x32,0);
    FUN_000117e2(iVar1 + 0x380,"FixNote",0,0x7f,0,0x3c);
    FUN_00011652(iVar1 + 0x3f0,"FixVelo","",0,0,0x7f,0,100,0);
    FUN_00010f72(iVar1 + 0x460,"StepData",0,0,param_1 + 0x1e6);
    FUN_00011652(iVar1 + 0x4d0,"Note Length","%",0,0,100,0,0x32,0);
    FUN_00010218(iVar1 + 0x540,"File IO","",0,4,5,0,"Load Save Copy PasteInit ",0);
    FUN_00010290(iVar1 + 0x5b0,"On/Off",1);
    FUN_00011b84();
    return;
  }
  return;
}

