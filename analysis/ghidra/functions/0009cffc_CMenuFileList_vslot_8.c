/* 0009cffc CMenuFileList_vslot_8 */

void CMenuFileList_vslot_8(int *param_1,int *param_2)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[0xd];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  param_1[0xd] = (int)param_2;
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 0xc))(param_2);
  }
                    /* WARNING: Could not recover jumptable at 0x0009d03d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x54))();
  return;
}

