/* 000adaf4 FUN_000adaf4 */

undefined4 FUN_000adaf4(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (int *)0x0) {
    uVar1 = 0xffffffce;
  }
  else if (*(short *)(param_1 + 2) == 0x101) {
    uVar1 = (**(code **)(*param_2 + 0x14))
                      (param_2,*(uint *)(param_1 + 0x10) & 0xf0,*(uint *)(param_1 + 0x10) & 0xf,
                       *(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 8),
                       *(undefined4 *)(param_1 + 4));
  }
  else if (*(short *)(param_1 + 2) == 0x102) {
    if (*(char *)(param_2[1] + 0xd) == '\0') {
      uVar1 = 0xffffd58d;
    }
    else {
      (**(code **)(*param_2 + 0x48))
                (param_2,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 4));
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0x80008002;
  }
  return uVar1;
}

