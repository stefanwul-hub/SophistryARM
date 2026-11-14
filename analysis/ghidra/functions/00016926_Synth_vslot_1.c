/* 00016926 Synth_vslot_1 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Synth_vslot_1(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  *param_1 = &PTR_Synth_vslot_0_000e7028;
  iVar1 = param_1[0xe3d];
  if (iVar1 != 0) {
    puVar3 = (undefined4 *)(iVar1 + *(int *)(iVar1 + -4) * 0x574);
    puVar4 = puVar3;
    while (puVar4 = puVar4 + -0x15d, puVar3 != (undefined4 *)param_1[0xe3d]) {
      puVar3 = puVar3 + -0x15d;
      (**(code **)*puVar4)(puVar3);
    }
    operator_delete__(puVar3 + -1);
  }
  param_1[0xe3d] = 0;
  iVar1 = param_1[0xe3e];
  if (iVar1 != 0) {
    puVar3 = (undefined4 *)(iVar1 + *(int *)(iVar1 + -4) * 0x574);
    puVar4 = puVar3;
    while (puVar4 = puVar4 + -0x15d, puVar3 != (undefined4 *)param_1[0xe3e]) {
      puVar3 = puVar3 + -0x15d;
      (**(code **)*puVar4)(puVar3);
    }
    operator_delete__(puVar3 + -1);
  }
  param_1[0xe3e] = 0;
  piVar2 = (int *)param_1[0xe3b];
  if (piVar2 == (int *)0x0) {
    param_1[0xe3b] = 0;
    piVar2 = (int *)param_1[0xe3c];
  }
  else {
    (**(code **)(*piVar2 + 4))(piVar2);
    param_1[0xe3b] = 0;
    piVar2 = (int *)param_1[0xe3c];
  }
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  param_1[0xe3c] = 0;
  if ((void *)param_1[0x1e6b] != (void *)0x0) {
    _free((void *)param_1[0x1e6b]);
  }
  param_1[0x1e6b] = 0;
  if ((void *)param_1[0x1e6c] != (void *)0x0) {
    _free((void *)param_1[0x1e6c]);
  }
  param_1[0x1e6c] = 0;
  NRPN_c_vslot_0(param_1 + 0x33aa);
  GenDemoNoise_c_vslot_0(param_1 + 0x319b);
  Disk_c_vslot_0(param_1 + 0x30f6);
  Timer_c_vslot_0(param_1 + 0x2689);
  Lock_c_vslot_0(param_1 + 0x267c);
  FileDialog_c_vslot_0(param_1 + 0x24ce);
  Parameter_c_vslot_0(param_1 + 0x24b2);
  ModuleManager_c_vslot_0(param_1 + 0x113d);
  Key_c_vslot_0(param_1 + 0xe3f);
  PolyNoteTable_c_vslot_0(param_1 + 0xe33);
  CmdBuffer_c_vslot_0(param_1 + 0xe2e);
  CmdBuffer_c_vslot_0(param_1 + 0xe29);
  OsLib_c_vslot_0(param_1 + 0xe28);
  NoteFreqTable_c_vslot_0(param_1 + 0xdb0);
  ECS2_c_vslot_0(param_1 + 0x1e1);
  SynGloIns_c_vslot_0(param_1 + 0x169);
  SynGlo_c_vslot_0(param_1 + 0xf3);
  SysGlo_c_vslot_0(param_1 + 0x2d);
  *param_1 = PTR_DAT_00103818 + 8;
  FUN_00094cea(param_1);
  operator_delete(param_1);
  return;
}

