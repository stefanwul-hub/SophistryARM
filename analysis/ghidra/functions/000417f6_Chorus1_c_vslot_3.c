/* 000417f6 Chorus1_c_vslot_3 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Chorus1_c_vslot_3(int param_1)

{
  int iVar1;
  undefined *local_4c;
  undefined1 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined *local_3c;
  undefined1 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined *local_2c;
  undefined1 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if (*(char *)(param_1 + 0x15c) != '\0') {
    Envelope_c_vslot_17(param_1 + 0x1e0,*(undefined4 *)(param_1 + 0x128),2,"Triang");
    Envelope_c_vslot_17(param_1 + 0x984,*(undefined4 *)(param_1 + 0x128),2,"Triang");
    Envelope_c_vslot_17(param_1 + 0x1128,*(undefined4 *)(param_1 + 0x128),2,"Triang");
    local_4c = PTR_DAT_00103808 + 8;
    local_48 = 0;
    local_44 = 0x3c;
    local_40 = 100;
    LFOSimp_c_vslot_33(param_1 + 0x1e0,*(undefined4 *)(param_1 + 0x128),&local_4c,0,0);
    local_4c = PTR_DAT_00103808 + 8;
    local_3c = PTR_DAT_00103808 + 8;
    local_38 = 0;
    local_34 = 0x3c;
    local_30 = 100;
    LFOSimp_c_vslot_33(param_1 + 0x984,*(undefined4 *)(param_1 + 0x128),&local_3c,0,0);
    local_3c = PTR_DAT_00103808 + 8;
    local_2c = PTR_DAT_00103808 + 8;
    local_28 = 0;
    local_24 = 0x3c;
    local_20 = 100;
    LFOSimp_c_vslot_33(param_1 + 0x1128,*(undefined4 *)(param_1 + 0x128),&local_2c,0,0);
    *(undefined4 *)(param_1 + 0x20f4) = 100;
    *(undefined8 *)(param_1 + 0x20ac) = 0;
    *(undefined8 *)(param_1 + 0x20b4) = 0;
    *(undefined8 *)(param_1 + 0x20bc) = 0;
    *(undefined8 *)(param_1 + 0x20c4) = 0;
    if (0 < *(int *)(param_1 + 0x20ec)) {
      iVar1 = 0;
      do {
        *(undefined4 *)(*(int *)(param_1 + 0x20f8) + iVar1 * 4) = 0;
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 0x20ec));
      return;
    }
  }
  return;
}

