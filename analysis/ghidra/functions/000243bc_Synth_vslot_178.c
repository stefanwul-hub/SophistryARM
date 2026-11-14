/* 000243bc Synth_vslot_178 */

undefined4 Synth_vslot_178(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  
  if ((-1 < param_2) && (param_2 < param_1[0x2693])) {
    iVar2 = param_2 * 4;
    iVar3 = param_1[0x33a8];
    piVar1 = *(int **)(iVar3 + iVar2);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 4))(piVar1);
      iVar3 = param_1[0x33a8];
    }
    pvVar4 = operator_new(0x10);
    FUN_0002df20(pvVar4,param_4,0);
    *(void **)(iVar3 + iVar2) = pvVar4;
    if (pvVar4 != (void *)0x0) {
      FUN_0002e03e(*(undefined4 *)(iVar2 + param_1[0x33a8]),param_3,param_4);
    }
    piVar1 = *(int **)(param_1[0x33a9] + iVar2);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x4c))(piVar1,0);
      param_1[0x2289e] = param_1[0x2289e] + 1;
      FUN_000241f2(param_1,param_2);
      (**(code **)(*param_1 + 0x2cc))(param_1,param_2,param_2);
      param_1[0x2289f] = param_1[0x2289f] + 1;
      (**(code **)(*param_1 + 0x270))(param_1);
      return param_4;
    }
  }
  return 0;
}

