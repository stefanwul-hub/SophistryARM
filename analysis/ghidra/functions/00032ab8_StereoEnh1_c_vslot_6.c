/* 00032ab8 StereoEnh1_c_vslot_6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void StereoEnh1_c_vslot_6(int *param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  
  if (*param_2 == 0) {
    uVar2 = (**(code **)(*param_1 + 100))(param_1);
    pvVar3 = operator_new(0x20);
    FUN_000126be(pvVar3,uVar2,param_3,4);
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
    FUN_00011652(iVar4 + 0x70,"Wet","%",0,0,100,2,0x32,0);
    FUN_00011652(iVar4 + 0xe0,"Roomsize","msec",0,5,100,1,0x32,0);
    FUN_00011652(iVar4 + 0x150,"Factor","n",0,10,0x28,1,0x14,0);
    FUN_00011b84(param_1[0x48]);
                    /* WARNING: Could not recover jumptable at 0x00032c77. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0xd8))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00032b12. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xd8))();
  return;
}

