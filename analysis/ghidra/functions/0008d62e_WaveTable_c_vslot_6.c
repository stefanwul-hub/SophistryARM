/* 0008d62e WaveTable_c_vslot_6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void WaveTable_c_vslot_6(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  if (*param_2 == 0) {
    uVar3 = (**(code **)(*param_1 + 100))(param_1);
    pvVar4 = operator_new(0x20);
    FUN_000126be(pvVar4,uVar3,param_3,5);
    param_1[0x48] = (int)pvVar4;
    *param_2 = (int)pvVar4;
    *(undefined1 *)(param_1 + 0x5c) = 1;
  }
  iVar1 = *param_2;
  param_1[0x48] = iVar1;
  if ((iVar1 != 0) && (cVar2 = FUN_00011c32(iVar1), cVar2 == '\0')) {
    iVar1 = *(int *)(param_1[0x48] + 4);
    FUN_00011652(iVar1,"Version","",0,200,0x26ac,2,200,0);
    FUN_00010f72(iVar1 + 0x70,"Filename",1,0,0);
    FUN_000117e2(iVar1 + 0xe0,"Root",0,0x7f,0,0x3c);
    FUN_00011652(iVar1 + 0x150,"Start Frame","%",0,0,0x3de,1,0,0);
    FUN_00011652(iVar1 + 0x1c0,"End Frame","%",0,10,1000,1,1000,0);
    FUN_00011b84();
    return;
  }
  return;
}

