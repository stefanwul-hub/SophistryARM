/* 000adfd6 FUN_000adfd6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 FUN_000adfd6(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_2 != (int *)0x0) {
    switch(*(undefined2 *)(param_1 + 2)) {
    case 0x101:
    case 0x102:
      piVar1 = param_2 + 0x39;
      if (piVar1 == (int *)0x0) {
        uVar2 = 0xffffffce;
      }
      else if (*(short *)(param_1 + 2) == 0x101) {
        uVar2 = (**(code **)(*piVar1 + 0x14))
                          (piVar1,*(uint *)(param_1 + 0x10) & 0xf0,*(uint *)(param_1 + 0x10) & 0xf,
                           *(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
                           *(undefined4 *)(param_1 + 4));
      }
      else if (*(short *)(param_1 + 2) == 0x102) {
        if (*(char *)(param_2[0x3a] + 0xd) == '\0') {
          uVar2 = 0xffffd58d;
        }
        else {
          (**(code **)(*piVar1 + 0x48))
                    (piVar1,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 4));
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0x80008002;
      }
      return uVar2;
    case 0x103:
      UNRECOVERED_JUMPTABLE = *(code **)(*param_2 + 0xdc);
      break;
    case 0x104:
      UNRECOVERED_JUMPTABLE = *(code **)(*param_2 + 0xe0);
      break;
    case 0x105:
      uVar2 = (**(code **)(*param_2 + 0xf8))
                        (param_2,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x10),
                         *(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(param_1 + 4));
      return uVar2;
    case 0x106:
      uVar2 = (**(code **)(*param_2 + 0xe8))
                        (param_2,*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(param_1 + 4));
      return uVar2;
    default:
      uVar2 = FUN_000aabb6();
      return uVar2;
    }
                    /* WARNING: Could not recover jumptable at 0x000ae062. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)();
    return uVar2;
  }
  return 0xffffffce;
}

