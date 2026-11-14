/* 0009cd10 FUN_0009cd10 */

void FUN_0009cd10(int *param_1,int *param_2,undefined4 *param_3,short param_4,short param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  short local_30;
  short local_28;
  short local_26;
  short local_24;
  short local_22;
  short local_20;
  short local_1e;
  short local_1c;
  short local_1a;
  undefined1 local_18 [6];
  undefined1 local_12 [6];
  
  if (param_1[0x1b] != 0) {
    local_22 = (short)*param_3;
    local_1e = (short)param_2[4] + local_22 + (short)param_2[2];
    local_30 = (short)param_3[1];
    local_20 = local_30 + (short)param_2[5] + (short)param_2[3];
    local_1a = (local_1e + (short)param_3[2]) - local_22;
    local_1c = (local_20 + (short)param_3[3]) - local_30;
    local_26 = param_4;
    local_28 = param_5;
    local_22 = (param_4 + (short)param_3[2]) - local_22;
    local_24 = (param_5 + (short)param_3[3]) - local_30;
    _GetForeColor(local_12);
    _GetBackColor(local_18);
    _BackColor(0x1e);
    _ForeColor(0x21);
    uVar1 = (**(code **)(*param_1 + 0x14))(param_1);
    uVar2 = (**(code **)(*param_2 + 0x14))(param_2);
    _CopyBits(uVar2,uVar1,&local_20,&local_28,0,0);
    (**(code **)(*param_1 + 0x18))(param_1);
    (**(code **)(*param_2 + 0x18))(param_2);
    _RGBForeColor(local_12);
    _RGBBackColor(local_18);
  }
  return;
}

