/* 0001c98c Synth_vslot_9 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Synth_vslot_9(int *param_1,undefined4 *param_2,int *param_3,int param_4)

{
  int iVar1;
  void *pvVar2;
  int local_20;
  
  if ((((char)param_1[0x33f5] == '\0') || (param_4 < 1)) || (param_1[4] < param_4)) {
    return;
  }
  if (0 < param_1[0x33f0]) {
    param_1[0x1e6d] = param_1[0x1e6b];
    param_1[0x1e6e] = param_1[0x1e6c];
    if (param_2 == (undefined4 *)0x0) {
      return;
    }
    if ((void *)*param_2 == (void *)0x0) {
      return;
    }
    if (param_2[1] == 0) {
      return;
    }
    if (param_1[0x33fa] != 0x11) {
      _memcpy((void *)param_1[0x1e6b],(void *)*param_2,param_4 << 2);
      _memcpy((void *)param_1[0x1e6c],(void *)param_2[1],param_4 << 2);
    }
  }
  param_1[0xeea] = (int)(param_1 + 0x1e6d);
  if (*(char *)((int)param_1 + 0xcfc5) == '\0') {
    (**(code **)(*param_1 + 0x338))(param_1);
  }
  if ((0 < param_1[0x33ef]) && (pvVar2 = (void *)*param_3, pvVar2 != (void *)0x0)) {
    local_20 = 0;
    do {
      iVar1 = param_4;
      if (0x100 < param_4) {
        do {
          _memcpy(pvVar2,&DAT_001016a0,0x400);
          pvVar2 = (void *)((int)pvVar2 + 0x400);
          iVar1 = iVar1 + -0x100;
        } while (0x100 < iVar1);
      }
      _memcpy(pvVar2,&DAT_001016a0,iVar1 * 4);
      local_20 = local_20 + 1;
    } while ((local_20 < param_1[0x33ef]) &&
            (pvVar2 = (void *)param_3[local_20], pvVar2 != (void *)0x0));
  }
                    /* WARNING: Could not recover jumptable at 0x0001cb3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x394))();
  return;
}

