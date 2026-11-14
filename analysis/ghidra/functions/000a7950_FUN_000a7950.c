/* 000a7950 FUN_000a7950 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000a7950(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  cfstringStruct *pcVar1;
  int *piVar2;
  int iVar3;
  
  param_1[1] = param_2;
  *param_1 = (int)&PTR_AUBase_vslot_0_000f4488;
  param_1[2] = (int)&PTR_LAB_000f456c;
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined1 *)((int)param_1 + 0xd) = 0;
  param_1[4] = param_3;
  param_1[5] = param_4;
  param_1[6] = param_5;
  param_1[7] = param_6;
  iVar3 = 4;
  piVar2 = param_1 + 8;
  do {
    FUN_000c5b1e(piVar2);
    piVar2 = piVar2 + 5;
    iVar3 = iVar3 + -1;
  } while (iVar3 != -1);
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  *(undefined1 *)(param_1 + 0x25) = 0;
  *(double *)(param_1 + 0x26) = -1.0;
  param_1[0x29] = 0;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x36] = 0;
  *(undefined1 *)(param_1 + 0x37) = 0;
  param_1[0x38] = 0;
  if (DAT_000fd570 == '\0') {
    DAT_000fd54c = &cf_Untitled;
    DAT_000fd560 = &cf_version;
    DAT_000fd568 = &cf_type;
    DAT_000fd55c = &cf_subtype;
    DAT_000fd558 = &cf_manufacturer;
    DAT_000fd554 = &cf_data;
    DAT_000fd550 = &cf_name;
    DAT_000fd548 = &cf_render_quality;
    DAT_000fd544 = &cf_cpu_load;
    DAT_000fd56c = &cf_vstdata;
    DAT_000fd540 = &cf_element_name;
    DAT_000fd564 = &cf_part;
    DAT_000fd570 = '\x01';
  }
  iVar3 = DAT_000e2220;
  if ((DAT_000e2220 == -1) && (iVar3 = *(int *)PTR_DAT_001038c0, *(int *)PTR_DAT_001038c0 == -1)) {
    iVar3 = FUN_000ae8a0();
  }
  DAT_000e2220 = iVar3;
  *(undefined1 *)((int)param_1 + 0xe) = 2;
  param_1[0x28] = 0x484;
  if ((char)param_1[0x37] != '\0') {
    (**(code **)(*param_1 + 0xbc))(param_1);
  }
  FUN_000a67ae(param_1,0xe,0,0);
  param_1[8] = (int)(param_1 + 2);
  param_1[9] = 0;
  FUN_000abf88(param_1 + 8,1);
  if (1 < *(byte *)((int)param_1 + 0xe)) {
    FUN_000c5ef2(param_1 + 0x2c,0x18);
  }
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x2a] = -1;
  pcVar1 = DAT_000fd54c;
  param_1[0x2b] = (int)DAT_000fd54c;
  _CFRetain(pcVar1);
  return;
}

