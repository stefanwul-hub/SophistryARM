/* 0001f7b6 Synth_vslot_206 */

void Synth_vslot_206(int *param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_30;
  undefined1 local_24 [4];
  undefined1 local_20;
  undefined1 local_1f;
  undefined2 local_1e;
  int *local_18;
  undefined4 local_14;
  
  if (param_1[0x33fa] == 0) goto LAB_0001f8cd;
  iVar4 = param_1[0x33ed];
  iVar2 = param_1[0x33ee];
  iVar5 = iVar4;
  iVar7 = iVar2;
  if (0 < iVar4) {
    iVar7 = 0;
    local_30 = 0;
    do {
      while ((cVar3 = (**(code **)(*param_1 + 0x98))(param_1,local_30), cVar3 != '\0' &&
             (cVar3 = (**(code **)(*param_1 + 0x98))(param_1,local_30 + 1), cVar3 != '\0'))) {
        iVar7 = iVar7 + 1;
        local_30 = local_30 + 2;
        if (param_1[0x33ed] <= iVar7) goto LAB_0001f94a;
      }
      param_1[0x33ed] = iVar7;
      iVar7 = iVar7 + 1;
      local_30 = local_30 + 2;
    } while (iVar7 < param_1[0x33ed]);
LAB_0001f94a:
    iVar5 = param_1[0x33ed];
    iVar7 = param_1[0x33ee];
  }
  if (0 < iVar7) {
    iVar6 = 0;
    do {
      cVar3 = (**(code **)(*param_1 + 0x98))(param_1,iVar6 + iVar5 * 2);
      if (cVar3 == '\0') {
        param_1[0x33ee] = iVar6;
        iVar7 = iVar6;
        if (iVar6 <= iVar6 + 1) goto LAB_0001f99a;
      }
      else {
        iVar7 = param_1[0x33ee];
        if (param_1[0x33ee] <= iVar6 + 1) goto LAB_0001f99a;
      }
      iVar6 = iVar6 + 1;
      iVar5 = param_1[0x33ed];
    } while( true );
  }
  iVar7 = iVar7 + iVar5 * 2;
  goto joined_r0x0001f9a6;
LAB_0001f99a:
  iVar5 = param_1[0x33ed];
  iVar7 = iVar7 + iVar5 * 2;
joined_r0x0001f9a6:
  if (iVar7 < 2) {
    param_1[0x33ed] = 1;
    iVar5 = 1;
  }
  piVar1 = param_1 + 0xf3;
  Envelope_c_vslot_9(piVar1,0,0xb,iVar5);
  Envelope_c_vslot_9(piVar1,0,0xc,param_1[0x33ee]);
  param_1[0x33ef] = param_1[0x33ee] + param_1[0x33ed] * 2;
  if ((iVar4 != param_1[0x33ed]) || (iVar2 != param_1[0x33ee])) {
    FUN_0002b8e2(local_24);
    local_20 = 0x4c;
    local_1f = 0;
    local_1e = 0xb;
    local_14 = 0;
    local_18 = piVar1;
    FUN_0002ba10(param_1 + 0xe2e,local_24);
    HoldData_c_vslot_0(local_24);
  }
  if (0 < param_1[0x33ec]) {
    iVar7 = 0;
    do {
      iVar4 = Envelope_c_vslot_12(param_1 + 0x169,iVar7,3);
      if (param_1[0x33ed] + param_1[0x33ee] <= iVar4) {
        Envelope_c_vslot_9(param_1 + 0x169,iVar7,3,0);
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < param_1[0x33ec]);
  }
  (**(code **)(*param_1 + 0x350))(param_1);
  (**(code **)(*param_1 + 700))(param_1);
LAB_0001f8cd:
  *(undefined1 *)((int)param_1 + 0xcfc5) = 1;
  return;
}

