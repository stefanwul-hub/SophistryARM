/* 000773ac FilterMoogSI_c_vslot_31 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FilterMoogSI_c_vslot_31(int *param_1)

{
  int iVar1;
  longdouble lVar2;
  float local_10;
  
  iVar1 = param_1[0x49];
  if (iVar1 != 0) {
    local_10 = *(float *)(iVar1 + 0x15c) * 5e-05;
    (**(code **)(*param_1 + 0xac))(param_1,&local_10,*(undefined4 *)(iVar1 + 0x2ac));
    lVar2 = (longdouble)_log(1.0 / (double)local_10);
    param_1[0x10ca] = (int)(float)((double)lVar2 * -0.1803368777036667 + 1.0);
  }
  return;
}

