/* 00028578 SynthEditor_c_vslot_41 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void SynthEditor_c_vslot_41(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  undefined1 local_15c [332];
  
  if ((*(int *)(param_1 + 0x4c) != 0) && (param_3 != (int *)0x0)) {
    _OSAtomicAdd32Barrier(1,*(int *)(param_1 + 0x4c) + 0x3b30);
    iVar1 = (**(code **)(*param_3 + 0xdc))(param_3);
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    iVar3 = *(int *)(param_1 + 0x25854) + -1;
    if (iVar1 <= iVar3) {
      iVar3 = iVar1;
    }
    iVar1 = *(int *)(param_1 + 0x2085c + iVar3 * 0xc);
    if (iVar1 == 10) {
      iVar1 = (**(code **)(*param_3 + 0x138))(param_3,0,1);
      iVar2 = (**(code **)(*param_3 + 0x150))(param_3);
      if (iVar2 != 1) {
        (**(code **)(**(int **)(param_1 + 0x4c) + 0x34))
                  (*(int **)(param_1 + 0x4c),*(undefined4 *)(param_1 + 0x24454 + iVar3 * 4),
                   (float)iVar1 * 0.007874016);
      }
    }
    else if (iVar1 == 0x11) {
      (**(code **)(*param_3 + 0x134))(param_3,local_15c);
      (**(code **)(**(int **)(param_1 + 0x4c) + 0x36c))
                (*(int **)(param_1 + 0x4c),*(undefined4 *)(param_1 + 0x24454 + iVar3 * 4),local_15c)
      ;
    }
    else if (iVar1 == 9) {
      lVar4 = (longdouble)(**(code **)(*param_3 + 0xb4))(param_3);
      (**(code **)(**(int **)(param_1 + 0x4c) + 0x34))
                (*(int **)(param_1 + 0x4c),*(undefined4 *)(param_1 + 0x24454 + iVar3 * 4),
                 (float)lVar4);
    }
    else {
      FUN_0002790a(param_1,param_2,param_3);
    }
    _OSAtomicAdd32Barrier(0xffffffff,*(int *)(param_1 + 0x4c) + 0x3b30);
  }
  return;
}

