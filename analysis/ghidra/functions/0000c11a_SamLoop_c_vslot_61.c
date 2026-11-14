/* 0000c11a SamLoop_c_vslot_61 */

undefined1 SamLoop_c_vslot_61(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined1 uVar2;
  
  if (((char)param_1[0x75] != '\0') && (param_1[0x7b] != 0)) {
    _memset(*(void **)(param_1[0x7b] + param_3 * 4),0,(param_2 + -1 >> 3) + 1);
  }
  iVar1 = param_1[0x77];
  if (iVar1 == 1) {
    uVar2 = (**(code **)(*param_1 + 0x100))(param_1,param_2,param_3);
    return uVar2;
  }
  if (iVar1 == 2) {
    uVar2 = (**(code **)(*param_1 + 0xfc))(param_1,param_2,param_3);
    return uVar2;
  }
  if (iVar1 != 0) {
    return 0;
  }
  uVar2 = (**(code **)(*param_1 + 0xf8))(param_1,param_2,param_3);
  return uVar2;
}

