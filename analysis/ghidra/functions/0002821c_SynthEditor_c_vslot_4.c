/* 0002821c SynthEditor_c_vslot_4 */

undefined4 SynthEditor_c_vslot_4(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  char cVar4;
  int *piVar5;
  void *pvVar6;
  undefined4 uVar7;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar1 = param_1[0x13];
  if ((iVar1 != 0) && (LPAUSynth_vslot_9[iVar1] == (code)0x0)) {
    _OSAtomicAdd32Barrier(1,iVar1 + 0x3b30);
    if (param_1[7] != 0) {
      (**(code **)(*param_1 + 0x14))(param_1);
    }
    param_1[2] = param_2;
    cVar4 = (**(code **)(*(int *)param_1[0x13] + 0x380))((int *)param_1[0x13]);
    if (cVar4 == '\0') {
      cVar4 = (**(code **)(*(int *)param_1[0x13] + 900))((int *)param_1[0x13]);
      if (cVar4 == '\0') {
        cVar4 = (**(code **)(*(int *)param_1[0x13] + 0x37c))((int *)param_1[0x13]);
        if (cVar4 == '\0') {
          cVar4 = (**(code **)(*(int *)param_1[0x13] + 0x378))((int *)param_1[0x13]);
          if (cVar4 == '\0') {
            *(undefined1 *)(param_1 + 0x9774) = 1;
          }
        }
      }
    }
    uVar7 = *(undefined4 *)(param_1[0xb] + 0xc);
    uVar2 = *(undefined4 *)(param_1[0xb] + 0x10);
    local_1c = 0;
    local_18 = 0;
    local_14 = uVar7;
    local_10 = uVar2;
    piVar5 = (int *)operator_new(0xa4);
    FUN_000a3fb4(piVar5,&local_1c,param_2,param_1);
    param_1[7] = (int)piVar5;
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 0x20))(piVar5,0);
      pvVar6 = operator_new(0x68);
      FUN_00007d88(pvVar6,0,0,uVar7,uVar2,param_1[7],param_1[0xb],0);
      param_1[9] = (int)pvVar6;
      param_1[10] = 0;
      iVar1 = param_1[0xc];
      if (iVar1 != 0) {
        uVar7 = *(undefined4 *)(iVar1 + 0xc);
        uVar2 = *(undefined4 *)(iVar1 + 0x10);
        pvVar6 = operator_new(0x68);
        FUN_00007d88(pvVar6,0,0,uVar7,uVar2,param_1[7],param_1[0xc],0);
        param_1[10] = (int)pvVar6;
      }
      if (param_1[9] != 0) {
        (**(code **)(*(int *)param_1[7] + 0xac))((int *)param_1[7],param_1[9]);
        if ((char)param_1[0x9774] != '\0') {
          (**(code **)(*param_1 + 0x98))(param_1);
        }
      }
    }
    pcVar3 = *(code **)(*param_1 + 0x6c);
    uVar7 = Envelope_c_vslot_12(param_1[0x13] + 0xb4,0,7);
    (*pcVar3)(param_1,uVar7);
    _OSAtomicAdd32Barrier(0xffffffff,param_1[0x13] + 0x3b30);
    return 1;
  }
  return 0;
}

