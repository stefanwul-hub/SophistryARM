/* 0008cb50 ECS2_c_vslot_30 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void ECS2_c_vslot_30(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iStack_50;
  undefined **ppuStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  Envelope_c_vslot_30(param_1,param_2,param_3);
  if (*(int *)(param_1 + 0x124) == 0) {
    return;
  }
  *(undefined1 *)(param_1 + 0x316) = 0;
  if (param_3 == 1) {
    iVar2 = *(int *)(param_1 + 0x124);
    if (*(int *)(iVar2 + 0x78) != 0) {
      if (*(int *)(iVar2 + 0x78) != 1) goto LAB_0008cb98;
      FUN_0008b5e4(param_1);
code_r0x0008cc0d:
      FUN_000109c8(*(int *)(param_1 + 0x124) + 0x70,1);
      iVar2 = *(int *)(param_1 + 0x124);
      goto LAB_0008cb98;
    }
code_r0x0008cbb9:
    FUN_0008bfe6(param_1);
    iVar2 = *(int *)(param_1 + 0x124);
    goto LAB_0008cb98;
  }
  iVar2 = *(int *)(param_1 + 0x124);
  if (param_3 != 2) goto LAB_0008cb98;
  switch(*(undefined4 *)(iVar2 + 0xe8)) {
  case 0:
    FUN_000109c8(iVar2 + 0x70,0);
    goto code_r0x0008cbb9;
  case 1:
    FUN_0008b5e4(param_1);
    FUN_000109c8(*(int *)(param_1 + 0x124) + 0xe0,1);
    goto code_r0x0008cc0d;
  case 2:
    FUN_000109c8(iVar2 + 0x70,1);
    *(undefined1 *)(param_1 + 0x316) = 1;
    iVar2 = *(int *)(param_1 + 0x124);
    goto LAB_0008cb98;
  case 3:
    FUN_000109c8(iVar2 + 0x70,0);
    cVar1 = FUN_0002e50e(param_1 + 0x168,
                         "Do you want to clear all Controller Assigments of this instrument?",
                         "Clear ECS");
    if (cVar1 != '\0') {
      FUN_0008c872(param_1);
      FUN_0008bfe6(param_1);
    }
    break;
  case 4:
    FUN_000109c8(iVar2 + 0x70,0);
    if (*(int *)(param_1 + 0x318) != 0) {
      FUN_000b5a12(*(int *)(param_1 + 0x318) + 0x44f4,param_1,0,0,"ECS");
    }
code_r0x0008cd3f:
    FUN_0008bfe6(param_1);
    break;
  case 5:
    FUN_000109c8(iVar2 + 0x70,0);
    FUN_0008bfe6(param_1);
    if (*(int *)(param_1 + 0x318) != 0) {
      FUN_000b5a12(*(int *)(param_1 + 0x318) + 0x44f4,param_1,0,1,"ECS");
    }
    break;
  case 6:
    FUN_000109c8(iVar2 + 0x70,0);
    cVar1 = FUN_0002e50e(param_1 + 0x168,"Do you want to restore the ECS factory settings?",
                         "Restore Factory ECS");
    if (cVar1 != '\0') {
      FUN_0008c872(param_1);
      if (*(int *)(param_1 + 0x120) != 0) {
        iStack_50 = 0;
        iVar2 = param_1 + 0x1938;
        do {
          uStack_44 = *(undefined4 *)(iVar2 + 4);
          uStack_40 = *(undefined4 *)(iVar2 + 8);
          uStack_3c = *(undefined4 *)(iVar2 + 0xc);
          uStack_38 = *(undefined4 *)(iVar2 + 0x10);
          uStack_34 = *(undefined4 *)(iVar2 + 0x14);
          uStack_30 = *(undefined4 *)(iVar2 + 0x18);
          uStack_2c = *(undefined4 *)(iVar2 + 0x1c);
          uStack_28 = *(undefined4 *)(iVar2 + 0x20);
          uStack_24 = *(undefined4 *)(iVar2 + 0x24);
          uStack_20 = *(undefined4 *)(iVar2 + 0x28);
          ppuStack_48 = &PTR_CCAss_c_vslot_0_000f2f08;
          FUN_0008bcda(param_1,iStack_50,&ppuStack_48);
          ppuStack_48 = &PTR_CCAss_c_vslot_0_000f2f08;
          iStack_50 = iStack_50 + 1;
          iVar2 = iVar2 + 0x2c;
        } while (iStack_50 != 0x80);
      }
      goto code_r0x0008cd3f;
    }
    break;
  default:
    goto LAB_0008cb98;
  }
  FUN_000109c8(*(int *)(param_1 + 0x124) + 0xe0,0);
  iVar2 = *(int *)(param_1 + 0x124);
LAB_0008cb98:
  *(bool *)(param_1 + 0x1d4) = *(int *)(iVar2 + 0x78) != 0;
  return;
}

