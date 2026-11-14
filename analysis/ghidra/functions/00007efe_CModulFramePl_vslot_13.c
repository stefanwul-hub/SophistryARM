/* 00007efe CModulFramePl_vslot_13 */

undefined1
CModulFramePl_vslot_13
          (int *param_1,undefined4 param_2,int *param_3,undefined4 param_4,undefined4 param_5)

{
  undefined1 uVar1;
  int *piVar2;
  int local_14;
  int local_10;
  
  piVar2 = (int *)(**(code **)(*param_1 + 0xec))(param_1,param_3,0);
  if (piVar2 != (int *)0x0) {
    local_14 = *param_3 - param_1[2];
    local_10 = param_3[1] - param_1[3];
    uVar1 = (**(code **)(*piVar2 + 0x34))(piVar2,param_2,&local_14,param_4,param_5);
    return uVar1;
  }
  return 0;
}

