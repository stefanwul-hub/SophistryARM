/* 000437a2 CrushX_c_vslot_6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CrushX_c_vslot_6(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  if (*param_2 == 0) {
    uVar3 = (**(code **)(*param_1 + 100))(param_1);
    pvVar4 = operator_new(0x20);
    FUN_000126be(pvVar4,uVar3,param_3,0xc);
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
    FUN_00011652(iVar1 + 0xe0,"Resolution","bit",0x40000000,100,0x641,2,400,0);
    FUN_0001042e(iVar1 + 0xe0,1);
    FUN_00010290(iVar1 + 0x150,"Dither On/Off",0);
    FUN_00011652(iVar1 + 0x1c0,"Divider","Samples",0x40000000,1,0x20,0,1,0);
    FUN_00010218(iVar1 + 0x230,"Divider Mode","",1,3,3,3,"AVGSTPSLD",0);
    FUN_00010218(iVar1 + 0x2a0,"Filter Type ","",1,4,4,1,"LP12HP12BP12BR12",0);
    FUN_00011652(iVar1 + 0x310,"Cutoff","",0x40800000,0x28,20000,0,20000,0);
    FUN_00011652(iVar1 + 0x380,"Resonance","",0,0,100,0,0,0);
    FUN_00010290(iVar1 + 0x3f0,"FilterPostDiv On/Off",0);
    FUN_00010290(iVar1 + 0x460,"Auto Volume compensation",1);
    FUN_00011652(iVar1 + 0x4d0,"Wet","%",0,0,100,2,100,0);
    FUN_00011b84();
    return;
  }
  return;
}

