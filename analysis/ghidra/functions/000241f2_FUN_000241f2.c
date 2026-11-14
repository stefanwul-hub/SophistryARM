/* 000241f2 FUN_000241f2 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000241f2(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined *local_48;
  undefined1 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined *local_34;
  undefined1 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_20 [16];
  
  if (0 < param_1[0xec9]) {
    iVar6 = 0;
    piVar1 = param_1 + 0xe33;
    do {
      cVar4 = FUN_0002ec86(piVar1,iVar6,param_2,local_20);
      if (cVar4 != '\0') {
        local_48 = PTR_DAT_00103814 + 8;
        local_40 = 0xffffffff;
        local_3c = 0xffffffff;
        local_38 = 0xffffffff;
        local_44 = 1;
        FUN_0002ec4e(piVar1,iVar6,&local_48);
        local_3c = 0;
        piVar2 = (int *)param_1[2];
        if (piVar2 != (int *)0x0) {
          local_30 = local_44;
          local_2c = local_40;
          local_28 = 0;
          local_34 = PTR_DAT_00103814 + 8;
          local_24 = local_38;
          (**(code **)(*piVar2 + 0x88))(piVar2,0,&local_34);
          local_34 = PTR_DAT_00103808 + 8;
        }
        iVar5 = FUN_0002f86e(piVar1,iVar6);
        if (iVar5 != 0) {
          iVar3 = *(int *)(iVar5 + 4);
          if (*(int *)(iVar5 + 8) != 0) {
            Envelope_c_vslot_9(param_1 + 0x169,iVar3,6,*(undefined4 *)(*(int *)(iVar5 + 8) + 0x14c))
            ;
            if ((-1 < param_1[0xed5]) && (-1 < param_1[0xed9])) {
              (**(code **)(*param_1 + 0x34c))(param_1,param_1[0xed5] + iVar3 * param_1[0xed9],0);
            }
          }
        }
        local_48 = PTR_DAT_00103808 + 8;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_1[0xec9]);
  }
  return;
}

