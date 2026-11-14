/* 0009dff8 FUN_0009dff8 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 FUN_0009dff8(int *param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if (param_2 != 0) {
    param_1[0x21] = 0;
    cVar2 = FUN_0009dd0a(param_1);
    if (cVar2 != '\0') {
      *(undefined1 *)(param_1 + 0x20) = 0;
      local_24 = CONCAT22((short)param_1[2],(short)param_1[3]);
      local_20 = CONCAT22((short)param_1[4],(short)param_1[5]);
      iVar3 = _CreateCustomControl(0,&local_24,param_1 + 0x1d,0,param_1 + 0x1f);
      if (iVar3 == 0) {
        local_2c = 0x74657874;
        local_28 = 2;
        uVar4 = _GetWindowEventTarget(param_2);
        _InstallEventHandler(uVar4,FUN_000a4ba0,1,&local_2c,param_1,0);
        _SetControlDragTrackingEnabled(param_1[0x1f],1);
        _SetAutomaticControlDragTrackingEnabledForWindow(param_2,1);
        iVar3 = param_1[3];
        iVar1 = param_1[2];
        param_1[2] = 0;
        param_1[4] = param_1[4] - iVar1;
        param_1[3] = param_1[3] + -iVar3;
        param_1[5] = param_1[5] + -iVar3;
        param_1[6] = param_1[6];
        param_1[8] = param_1[8];
        param_1[7] = param_1[7] + -param_1[3];
        param_1[9] = param_1[9] + -param_1[3];
        (**(code **)(*param_1 + 0x144))(param_1,1);
        return 1;
      }
      _fprintf((FILE *)(PTR_001037f8 + 0xb0),"Could not create Control : %d\n",iVar3);
      return 0;
    }
  }
  return 0;
}

