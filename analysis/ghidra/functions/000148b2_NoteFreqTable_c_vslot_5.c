/* 000148b2 NoteFreqTable_c_vslot_5 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void NoteFreqTable_c_vslot_5(int *param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  if (*param_2 == 0) {
    uVar3 = (**(code **)(*param_1 + 100))(param_1);
    pvVar4 = operator_new(0x20);
    FUN_000126be(pvVar4,uVar3,1,5);
    param_1[0x48] = (int)pvVar4;
    *param_2 = (int)pvVar4;
    *(undefined1 *)(param_1 + 0x5c) = 1;
  }
  iVar2 = *param_2;
  param_1[0x48] = iVar2;
  if (iVar2 != 0) {
    cVar1 = FUN_00011c32(iVar2);
    if (cVar1 == '\0') {
      iVar2 = *(int *)(param_1[0x48] + 4);
      FUN_00011652(iVar2,"Version","",0,200,0x26ac,2,200,0);
      FUN_00010290(iVar2 + 0x70,"On/Off",0);
      FUN_00010318(iVar2 + 0xe0,"Frequencies",0x81);
      FUN_00010f72(iVar2 + 0x150,"TUN-File Path",1,0,0);
      FUN_00010f72(iVar2 + 0x1c0,"Load Command ",0,0,0);
      FUN_00011b84(param_1[0x48]);
    }
    iVar2 = FUN_00011b72(param_1[0x48],0);
    param_1[0x49] = iVar2;
    if (iVar2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0001492c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_1 + 0xe0))();
      return;
    }
  }
  return;
}

