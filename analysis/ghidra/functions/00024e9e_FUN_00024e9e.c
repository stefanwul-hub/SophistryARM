/* 00024e9e FUN_00024e9e */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00024e9e(int *param_1)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined *local_60;
  undefined1 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined *local_4c;
  undefined1 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined *local_38;
  undefined1 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 local_24 [4];
  undefined4 local_20 [4];
  
  if (0 < param_1[0xec9]) {
    iVar5 = 0;
    piVar1 = param_1 + 0xe33;
    do {
      cVar3 = FUN_0002ed64(piVar1,iVar5,local_20,local_24);
      if (cVar3 == '\0') {
        if (param_1[0xec9] <= iVar5 + 1) break;
      }
      else {
        local_60 = PTR_DAT_00103814 + 8;
        local_58 = 0xffffffff;
        local_54 = 0xffffffff;
        local_50 = 0xffffffff;
        local_5c = 1;
        FUN_0002ec4e(piVar1,iVar5,&local_60);
        local_48 = local_5c;
        local_44 = local_58;
        local_40 = local_54;
        local_4c = PTR_DAT_00103814 + 8;
        local_3c = local_50;
        (**(code **)(*param_1 + 0x38c))(param_1,local_20[0],&local_4c);
        local_4c = PTR_DAT_00103808 + 8;
        iVar4 = FUN_0002f3a6(piVar1,iVar5);
        if (iVar4 == 0) {
          return;
        }
        piVar2 = *(int **)(iVar4 + 8);
        if (piVar2 == (int *)0x0) {
          return;
        }
        local_34 = local_5c;
        local_30 = local_58;
        local_2c = local_54;
        local_38 = PTR_DAT_00103814 + 8;
        local_28 = local_50;
        (**(code **)(*piVar2 + 0x60))(piVar2,&local_38);
        local_38 = PTR_DAT_00103808 + 8;
        local_60 = PTR_DAT_00103808 + 8;
        if (param_1[0xec9] <= iVar5 + 1) break;
      }
      iVar5 = iVar5 + 1;
    } while( true );
  }
  piVar1 = (int *)param_1[2];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x8c))(piVar1);
  }
  return;
}

