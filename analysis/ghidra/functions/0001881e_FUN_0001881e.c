/* 0001881e FUN_0001881e */

void FUN_0001881e(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_0002f80e(param_1 + 0xe33,param_2);
  if (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 4);
    Envelope_c_vslot_9(param_1 + 0x169,iVar1,6,*(undefined4 *)(*(int *)(iVar2 + 8) + 0x14c));
    if ((-1 < param_1[0xed5]) && (-1 < param_1[0xed9])) {
      (**(code **)(*param_1 + 0x34c))(param_1,param_1[0xed5] + param_1[0xed9] * iVar1,0);
    }
                    /* WARNING: Could not recover jumptable at 0x000188bd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1[0xec3] + param_2 * 4) + 0x24))();
    return;
  }
  return;
}

