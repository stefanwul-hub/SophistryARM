/* 000459d8 Kaja_c_vslot_1 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Kaja_c_vslot_1(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  
  *param_1 = &PTR_Kaja_c_vslot_0_000e8da8;
  InBuffer2_c_vslot_0(param_1 + 0xcac87);
  InBuffer2_c_vslot_0(param_1 + 0xcac72);
  InBuffer2_c_vslot_0(param_1 + 0xcac5d);
  InBuffer2_c_vslot_0(param_1 + 0xcac48);
  InBuffer2_c_vslot_0(param_1 + 0xcac33);
  InBuffer2_c_vslot_0(param_1 + 0xcac1e);
  InBuffer2_c_vslot_0(param_1 + 0xcac04);
  InBuffer2_c_vslot_0(param_1 + 0xcabef);
  InBuffer2_c_vslot_0(param_1 + 0xcabda);
  InBuffer2_c_vslot_0(param_1 + 0xcabc5);
  InBuffer2_c_vslot_0(param_1 + 0xcabb0);
  InBuffer2_c_vslot_0(param_1 + 0xcab9b);
  Disk_c_vslot_0(param_1 + 0xcaaf6);
  KajaGlo_c_vslot_0(param_1 + 0xcaa81);
  if ((param_1 != (undefined4 *)0xfff492bc) &&
     (puVar3 = param_1 + 0xcaa31, param_1 + 0x2db51 != puVar3)) {
    puVar1 = param_1 + 0xc5bba;
    local_3c = 0x20;
    do {
      puVar3 = puVar3 + -0x4e77;
      (**(code **)*puVar1)(puVar3);
      puVar1 = puVar1 + -0x4e77;
      local_3c = local_3c + -1;
    } while (local_3c != 0);
  }
  puVar3 = param_1 + 0x28754;
  if ((puVar3 != (undefined4 *)0x0) && (puVar3 != param_1 + 0x2db51)) {
    (**(code **)param_1[0x28754])(puVar3);
  }
  puVar3 = param_1 + 0x23678;
  if ((puVar3 != (undefined4 *)0x0) && (puVar1 = param_1 + 0x28754, puVar3 != puVar1)) {
    puVar2 = param_1 + 0x25ee6;
    local_38 = 2;
    do {
      puVar1 = puVar1 + -0x286e;
      (**(code **)*puVar2)(puVar1);
      puVar2 = puVar2 + -0x286e;
      local_38 = local_38 + -1;
    } while (local_38 != 0);
  }
  puVar1 = param_1 + 0x22f90;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1 != puVar3)) {
    puVar2 = param_1 + 0x234be;
    local_34 = 4;
    do {
      puVar3 = puVar3 + -0x1ba;
      (**(code **)*puVar2)(puVar3);
      puVar2 = puVar2 + -0x1ba;
      local_34 = local_34 + -1;
    } while (local_34 != 0);
  }
  if ((param_1 != (undefined4 *)0xfff75d80) && (param_1 + 0x228a0 != puVar1)) {
    puVar3 = param_1 + 0x22dd4;
    local_30 = 4;
    do {
      puVar1 = puVar1 + -0x1bc;
      (**(code **)*puVar3)(puVar1);
      puVar3 = puVar3 + -0x1bc;
      local_30 = local_30 + -1;
    } while (local_30 != 0);
  }
  FUN_0001ea78(param_1);
  operator_delete(param_1);
  return;
}

