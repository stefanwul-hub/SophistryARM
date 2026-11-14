/* 0001bd38 Synth_vslot_97 */

undefined4 Synth_vslot_97(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  
  _OSAtomicAdd32Barrier(1,param_1 + 0x3b30);
  piVar1 = *(int **)(param_1 + 8);
  if (((piVar1 != (int *)0x0) && (param_2 == 0x73744341)) && (param_3 == 0x57686565)) {
    cVar2 = (**(code **)(*piVar1 + 0x3c))(piVar1,param_5);
    if (cVar2 != '\0') {
      uVar3 = 1;
      goto LAB_0001bd6b;
    }
  }
  uVar3 = 0;
LAB_0001bd6b:
  _OSAtomicAdd32Barrier(0xffffffff,param_1 + 0x3b30);
  return uVar3;
}

