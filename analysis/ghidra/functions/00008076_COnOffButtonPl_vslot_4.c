/* 00008076 COnOffButtonPl_vslot_4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void COnOffButtonPl_vslot_4(int param_1,undefined4 param_2)

{
  longdouble lVar1;
  undefined4 local_24;
  int local_20;
  
  CControlPl_vslot_4(param_1,param_2);
  lVar1 = (longdouble)FUN_000019e8(param_1);
  local_20 = (int)((float)(*(int *)(param_1 + 0xb4) + -1) * (float)lVar1 + 0.001) *
             (*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0xc));
  local_24 = 0;
  if (*(char *)(param_1 + 0x72) != '\0') {
    (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))
              (*(int **)(param_1 + 0xb0),param_2,param_1 + 8,&local_24);
    return;
  }
  (**(code **)(**(int **)(param_1 + 0xb0) + 0x10))
            (*(int **)(param_1 + 0xb0),param_2,param_1 + 8,&local_24);
  return;
}

