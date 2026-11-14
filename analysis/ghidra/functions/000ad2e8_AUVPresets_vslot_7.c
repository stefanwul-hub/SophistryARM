/* 000ad2e8 AUVPresets_vslot_7 */

void AUVPresets_vslot_7(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_1c;
  undefined4 local_18;
  
  iVar1 = _GetControl32BitValue(*(undefined4 *)(param_1 + 8));
  if (0 < iVar1) {
    uVar2 = _CFArrayGetValueAtIndex(*(undefined4 *)(param_1 + 0x14),iVar1 + -1);
    _AudioUnitSetProperty
              (*(undefined4 *)(*(int *)(param_1 + 0x18) + 0x10),*(undefined4 *)(param_1 + 0x1c),0,0,
               uVar2,8);
    local_1c = *(undefined4 *)(*(int *)(param_1 + 0x18) + 0x10);
    local_18 = 0xffffffff;
    _AUParameterListenerNotify(0,0,&local_1c);
  }
  return;
}

