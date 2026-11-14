/* 000b5cae Reverb2R_c_vslot_6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Reverb2R_c_vslot_6(int *param_1,int *param_2,undefined4 param_3)

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
    FUN_00011652(iVar4 + 0xe0,"WetOld","%",0,0xffffffff,100,2,0xffffffff,0);
    FUN_00011652(iVar4 + 0x150,"RevTime","s",0,1,100,1,0x14,0);
    FUN_00011652(iVar4 + 0x1c0,"Damping ","%",0,0,0x5a,2,0x14,0);
    FUN_00011652(iVar4 + 0x230,"Predelay","ms",0,0,0x7d,0,0x19,0);
    FUN_00011652(iVar4 + 0x2a0,"Wet","%",0x40800000,0,1000,3,0x50,0);
    FUN_00010218(iVar4 + 0x310,"Frequency","Notes",9,0x1a,5,9,
                 " Off  1/8  1/8T1/16*1/16 1/16T1/32*1/32 1/32T 1/64 5/16 7/16 9/16 5/8 11/1613/16 7/8 15/16"
                 ,0);
    FUN_00010290(iVar4 + 0x380,"Modulation On/Off",0);
    FUN_00011652(iVar4 + 0x3f0,"Diffusors","",0,2,6,0,4,0);
    FUN_00011652(iVar4 + 0x460,"Mod Freq","Hz",0,3,0x14,0,10,0);
    FUN_00011b84();
    return;
  }
  return;
}

