/* 0003b236 Gator_c_vslot_6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Gator_c_vslot_6(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  if (*param_2 == 0) {
    uVar3 = (**(code **)(*param_1 + 100))(param_1);
    pvVar4 = operator_new(0x20);
    FUN_000126be(pvVar4,uVar3,param_3,7);
    param_1[0x48] = (int)pvVar4;
    *param_2 = (int)pvVar4;
    *(undefined1 *)(param_1 + 0x5c) = 1;
  }
  iVar1 = *param_2;
  param_1[0x48] = iVar1;
  if ((iVar1 != 0) && (cVar2 = FUN_00011c32(iVar1), cVar2 == '\0')) {
    iVar1 = *(int *)(param_1[0x48] + 4);
    FUN_00011652(iVar1,"Version","",0,200,0x26ac,2,200,0);
    FUN_00011652(iVar1 + 0x2a0,"Wet","%",0,0,100,2,100,0);
    FUN_00010f72(iVar1 + 0x70,"Step On/Off",0,0,"1010101010101010");
    FUN_00010f72(iVar1 + 0xe0,"Step On/Off",0,0,"0101010101010101");
    FUN_00010218(iVar1 + 0x150,"Frequency","Notes",1,0x11,5,0xd,
                 " 1/1  1/1T 1/2* 1/2  1/2T 1/4* 1/4  1/4T 1/8* 1/8  1/8T1/16*1/16 1/16T1/32*1/32 1/32T"
                 ,0);
    FUN_00011652(iVar1 + 0x1c0,"Smooth","%",0,0,100,2,5,0);
    FUN_00010218(iVar1 + 0x230,"Link","Mode",0,2,5,0," off link xlink",0);
    FUN_00011b84();
    return;
  }
  return;
}

