/* 00082fd0 AUCronoX_vslot_31 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 AUCronoX_vslot_31(int *param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int local_48;
  int local_44;
  int local_40;
  int local_38;
  int local_34;
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  undefined1 local_24 [4];
  undefined4 local_20 [4];
  
  FUN_00002918(param_1);
  if (param_2 == 0) {
    local_20[0] = param_3;
    cVar1 = (**(code **)(*param_1 + 0x134))(param_1,local_20);
    if (cVar1 == '\0') {
      uVar2 = LPAUSynth_vslot_31(param_1,0,param_3,param_4);
      return uVar2;
    }
    FUN_0001ce0e(param_1 + 0x3b,param_3,&local_48);
    FUN_0001cb52(param_1 + 0x3b,param_3,local_24,local_28,local_2c);
    if ((local_48 == 2) && (local_38 != 0)) {
      if (param_4 != (undefined4 *)0x0) {
        uVar2 = *(undefined4 *)PTR_001037ec;
        uVar3 = _CFNumberCreate(uVar2,10,local_20);
        cVar1 = _CFDictionaryContainsKey(param_1[0xcad19],uVar3);
        if (cVar1 == '\0') {
          iVar4 = (local_40 - local_44) + 1;
          if (0 < iVar4) {
            pvVar5 = operator_new__(iVar4 * 4);
            iVar6 = _CFStringCreateWithCString(uVar2,local_38,0x8000100);
            if (iVar6 != 0) {
              iVar8 = 0;
              do {
                uVar7 = _CFStringCreateWithSubstring(uVar2,iVar6,local_34 * iVar8,local_34);
                *(undefined4 *)((int)pvVar5 + iVar8 * 4) = uVar7;
                iVar8 = iVar8 + 1;
              } while (iVar4 != iVar8);
              iVar8 = _CFArrayCreate(*(undefined4 *)PTR_001037ec,pvVar5,iVar4,PTR_00103824);
              if (iVar8 != 0) {
                _CFDictionaryAddValue(param_1[0xcad19],uVar3,iVar8);
                _CFRelease(iVar8);
              }
              _CFRelease(iVar6);
              iVar6 = 0;
              do {
                iVar8 = *(int *)((int)pvVar5 + iVar6 * 4);
                if (iVar8 != 0) {
                  _CFRelease(iVar8);
                }
                iVar6 = iVar6 + 1;
              } while (iVar4 != iVar6);
            }
            if (pvVar5 != (void *)0x0) {
              operator_delete__(pvVar5);
            }
          }
        }
        uVar2 = _CFDictionaryGetValue(param_1[0xcad19],uVar3);
        uVar2 = _CFArrayCreateCopy(*(undefined4 *)PTR_001037ec,uVar2);
        *param_4 = uVar2;
        _CFRelease(uVar3);
      }
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffd59d;
    }
  }
  else {
    uVar2 = 0xffffd58e;
  }
  return uVar2;
}

