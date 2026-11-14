/* 0000b616 FUN_0000b616 */

void FUN_0000b616(int param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  longdouble lVar2;
  
  lVar2 = (longdouble)(**(code **)(*param_3 + 0xb4))(param_3);
  piVar1 = *(int **)(param_1 + 0x48);
  if (piVar1 == (int *)0x0) {
LAB_0000b6ad:
    if (*(int *)(param_1 + 0xc) == 0xb) goto LAB_0000b651;
  }
  else if (*(int *)(param_1 + 0xc) == 0xb) {
    (**(code **)(*piVar1 + 0x98))(piVar1);
    goto LAB_0000b6ad;
  }
  FUN_0000b41c(param_1,(float)lVar2);
LAB_0000b651:
  if ((*(uint *)(param_1 + 0xc) < 0xe) &&
     ((1 << ((byte)*(undefined4 *)(param_1 + 0xc) & 0x1f) & 0x36f8U) != 0)) {
    piVar1 = *(int **)(param_1 + 0x3c);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x54))(piVar1,1);
    }
    if (*(int **)(param_1 + 0x34) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0000b6a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(param_1 + 0x34) + 0x54))();
      return;
    }
  }
  return;
}

