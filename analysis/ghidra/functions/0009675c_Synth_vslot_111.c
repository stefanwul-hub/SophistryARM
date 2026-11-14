/* 0009675c Synth_vslot_111 */

undefined4 Synth_vslot_111(undefined4 param_1,undefined4 *param_2,int param_3)

{
  ulong uVar1;
  void *pvVar2;
  
  if ((void *)*param_2 != (void *)0x0) {
    operator_delete__((void *)*param_2);
  }
  uVar1 = param_3 * 0x70 + 8;
  pvVar2 = operator_new__(uVar1);
  if (pvVar2 != (void *)0x0) {
    _memset(pvVar2,0,uVar1);
    *param_2 = pvVar2;
    *(int *)((int)pvVar2 + 4) = param_3;
    return 1;
  }
  return 0;
}

