/* 00011a6a ParaSet_c_vslot_1 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void ParaSet_c_vslot_1(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  *param_1 = &PTR_ParaSet_c_vslot_0_000e6bc8;
  puVar2 = (undefined4 *)param_1[1];
  if (puVar2 != (undefined4 *)0x0) {
    puVar1 = puVar2 + puVar2[-1] * 0x1c;
    if (puVar2 != puVar1) {
      puVar1 = puVar1 + -0x1c;
      puVar2 = puVar1;
      while( true ) {
        (**(code **)*puVar2)(puVar1);
        puVar2 = puVar2 + -0x1c;
        if (puVar1 == (undefined4 *)param_1[1]) break;
        puVar1 = puVar1 + -0x1c;
      }
    }
    operator_delete__(puVar1 + -1);
  }
  if ((void *)param_1[7] != (void *)0x0) {
    operator_delete__((void *)param_1[7]);
    operator_delete(param_1);
    return;
  }
  operator_delete(param_1);
  return;
}

