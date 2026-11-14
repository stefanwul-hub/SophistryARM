/* 000216fe Synth_vslot_22 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 Synth_vslot_22(int *param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 local_28;
  int local_20;
  
  _OSAtomicAdd32Barrier(1,param_1 + 0xecc);
  (**(code **)(*param_1 + 0x27c))(param_1);
  if (param_4 == '\0') {
    _OSAtomicAdd32Barrier(1,param_1 + 0x33f9);
    piVar1 = param_1 + 0xf3;
    iVar2 = Envelope_c_vslot_12(piVar1,0,0xb);
    param_1[0x33ed] = iVar2;
    iVar2 = Envelope_c_vslot_12(piVar1,0,0xc);
    param_1[0x33ee] = iVar2;
    (**(code **)(*param_1 + 0x278))(param_1);
    local_28 = (**(code **)(*param_1 + 0x2c4))(param_1,param_2,param_3,0);
    Envelope_c_vslot_9(piVar1,0,0xb,param_1[0x33ed]);
    Envelope_c_vslot_9(piVar1,0,0xc,param_1[0x33ee]);
    _OSAtomicAdd32Barrier(0xffffffff,param_1 + 0x33f9);
    *(undefined1 *)((int)param_1 + 0xcfc5) = 0;
    (**(code **)(*param_1 + 0x364))(param_1,0,piVar1,0xb);
    if (0 < param_1[0x33ec]) {
      local_20 = 0;
      iVar2 = (int)param_1 + 0x9bd5;
      do {
        Envelope_c_vslot_9(param_1 + 0x169,local_20,6,0);
        Envelope_c_vslot_18(param_1 + 0x169,local_20,0xe,iVar2);
        if (*(char *)((int)param_1 + 0xcfd5) == '\0') {
          FUN_00020efe(param_1,local_20,iVar2);
        }
        local_20 = local_20 + 1;
        iVar2 = iVar2 + 0x140;
      } while (local_20 < param_1[0x33ec]);
    }
    if (((char)param_1[0x33f7] == '\0') && (*(char *)((int)param_1 + 0xcfdb) == '\0')) {
      *(undefined1 *)((int)param_1 + 0xcfc9) = 1;
      (**(code **)(*param_1 + 0x35c))(param_1);
    }
    else {
      Envelope_c_vslot_18(piVar1,0,0x1e,&DAT_000fbf80);
      FUN_0001a3ce(param_1,&DAT_000fbf80);
      *(undefined1 *)((int)param_1 + 0xcfc9) = 1;
      (**(code **)(*param_1 + 0x35c))(param_1);
    }
  }
  else {
    local_28 = (**(code **)(*param_1 + 0x2c8))(param_1,param_1[0x33f8],param_2,param_3);
    Envelope_c_vslot_9(param_1 + 0x169,param_1[0x33f8],6,0);
    (**(code **)(*param_1 + 0x360))(param_1,param_1[0x33f8]);
  }
  _OSAtomicAdd32Barrier(0xffffffff,param_1 + 0xecc);
  iVar2 = FUN_0002e1c0(param_1 + 0xe28);
  param_1[0x269b] = iVar2;
  return local_28;
}

