/* 00074934 FilterFree_c_vslot_31 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FilterFree_c_vslot_31(int *param_1)

{
  int iVar1;
  longdouble lVar2;
  
  iVar1 = param_1[0x49];
  if (iVar1 != 0) {
    *(bool *)(param_1 + 0xb2) = *(int *)(iVar1 + 0x238) == 2;
    param_1[0xb3] = (int)(*(float *)(iVar1 + 0xec) * 5e-05);
    param_1[0xb5] = (int)(*(float *)(iVar1 + 0x15c) * 0.01);
    param_1[0xb6] = *(int *)(iVar1 + 0x1cc);
    (**(code **)(*param_1 + 0xac))(param_1,param_1 + 0xb3,*(undefined4 *)(iVar1 + 0x2ac));
    lVar2 = (longdouble)_log((double)(float)param_1[0xb3]);
    param_1[0xb4] = (int)(float)((double)lVar2 * 0.1803368777036667 + 1.0);
  }
  return;
}

