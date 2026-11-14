/* 00073214 ChordMem_c_vslot_6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void ChordMem_c_vslot_6(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  if (*param_2 == 0) {
    uVar3 = (**(code **)(*param_1 + 100))(param_1);
    pvVar4 = operator_new(0x20);
    FUN_000126be(pvVar4,uVar3,param_3,0x14);
    param_1[0x48] = (int)pvVar4;
    *param_2 = (int)pvVar4;
    *(undefined1 *)(param_1 + 0x5c) = 1;
  }
  iVar1 = *param_2;
  param_1[0x48] = iVar1;
  if ((iVar1 != 0) && (cVar2 = FUN_00011c32(iVar1), cVar2 == '\0')) {
    iVar1 = *(int *)(param_1[0x48] + 4);
    FUN_00011652(iVar1,"Version","",0,200,0x26ac,2,200,0);
    FUN_00010290(iVar1 + 0x70,"On/Off",0);
    FUN_00010218(iVar1 + 0xe0,"Op.Mode","",0,2,5,0,"Off  LearnPlay ",0);
    FUN_00011652(iVar1 + 0x150,"Polyphony","",0,0,8,0,1,0);
    FUN_000117e2(iVar1 + 0x1c0,"Note 0",0,0x7f,0,0x3c);
    FUN_00011652(iVar1 + 0x230,"Velo 0","",0,0,0x7f,0,100,0);
    FUN_000117e2(iVar1 + 0x2a0,"Note 1",0,0x7f,0,0x40);
    FUN_00011652(iVar1 + 0x310,"Velo 1","",0,0,0x7f,0,100,0);
    FUN_000117e2(iVar1 + 0x380,"Note 2",0,0x7f,0,0x43);
    FUN_00011652(iVar1 + 0x3f0,"Velo 2","",0,0,0x7f,0,100,0);
    FUN_000117e2(iVar1 + 0x460,"Note 3",0,0x7f,0,0x3c);
    FUN_00011652(iVar1 + 0x4d0,"Velo 3","",0,0,0x7f,0,100,0);
    FUN_000117e2(iVar1 + 0x540,"Note 4",0,0x7f,0,0x3c);
    FUN_00011652(iVar1 + 0x5b0,"Velo 4","",0,0,0x7f,0,100,0);
    FUN_000117e2(iVar1 + 0x620,"Note 5",0,0x7f,0,0x3c);
    FUN_00011652(iVar1 + 0x690,"Velo 5","",0,0,0x7f,0,100,0);
    FUN_000117e2(iVar1 + 0x700,"Note 6",0,0x7f,0,0x3c);
    FUN_00011652(iVar1 + 0x770,"Velo 6","",0,0,0x7f,0,100,0);
    FUN_000117e2(iVar1 + 0x7e0,"Note 7",0,0x7f,0,0x3c);
    FUN_00011652(iVar1 + 0x850,"Velo 7","",0,0,0x7f,0,100,0);
    FUN_00011b84();
    return;
  }
  return;
}

