/* 00027580 SynthEditor_c_vslot_37 */

void SynthEditor_c_vslot_37(int param_1,int param_2)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  longdouble lVar6;
  undefined1 local_14c [320];
  
  if (*(int *)(param_1 + 0x4c) != 0) {
    FUN_000274c4(param_1,param_2);
    iVar2 = *(int *)(param_2 * 0x68 + 0x5c + param_1);
    if (iVar2 < 0) {
      iVar2 = param_2 * 0xc + param_1;
      if ((*(int *)(iVar2 + 0x20858) != 0) || (*(int *)(iVar2 + 0x20854) != 0)) {
        FUN_0001d532(*(undefined4 *)(param_1 + 0x4c),
                     *(undefined4 *)(param_1 + 0x24454 + param_2 * 4),local_14c,0x13f);
        lVar6 = (longdouble)
                (**(code **)(**(int **)(param_1 + 0x4c) + 0x2b4))
                          (*(int **)(param_1 + 0x4c),
                           *(undefined4 *)(param_1 + 0x24454 + param_2 * 4));
        fVar1 = (float)lVar6;
        piVar3 = *(int **)(iVar2 + 0x20858);
        if (piVar3 != (int *)0x0) {
          iVar4 = *(int *)(iVar2 + 0x2085c);
          if (iVar4 == 10) {
            uVar5 = FUN_0001d28c(*(undefined4 *)(param_1 + 0x4c),
                                 *(undefined4 *)(param_1 + 0x24454 + param_2 * 4));
            FUN_00006082(*(undefined4 *)(iVar2 + 0x20858),uVar5);
          }
          else if (iVar4 == 0x11) {
            (**(code **)(*piVar3 + 0x130))(piVar3,local_14c);
            (**(code **)(**(int **)(iVar2 + 0x20858) + 0xb0))(*(int **)(iVar2 + 0x20858),fVar1);
          }
          else if (iVar4 == 9) {
            (**(code **)(*piVar3 + 0x174))(piVar3,fVar1);
          }
        }
        param_1 = param_1 + param_2 * 0xc;
        piVar3 = *(int **)(param_1 + 0x20854);
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 0x130))(piVar3,local_14c);
          piVar3 = *(int **)(param_1 + 0x20854);
          (**(code **)(*piVar3 + 0x10c))(piVar3,param_2,fVar1);
          return;
        }
      }
    }
    else {
      lVar6 = (longdouble)
              (**(code **)(**(int **)(param_1 + 0x4c) + 0x2b4))
                        (*(int **)(param_1 + 0x4c),*(undefined4 *)(param_1 + 0x24454 + iVar2 * 4));
      FUN_0000afe2(param_2 * 0x68 + 0x54 + param_1,(float)lVar6);
    }
  }
  return;
}

