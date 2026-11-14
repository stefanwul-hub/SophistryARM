/* 000a9d60 AUBase_vslot_29 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int AUBase_vslot_29(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  short sVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  uint local_50;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_30;
  uint local_2c;
  undefined4 local_28;
  undefined1 local_24 [4];
  undefined4 local_20 [4];
  
  sVar4 = _GetComponentInfo(*(undefined4 *)(param_1 + 4),&local_44,0,0,0);
  if (sVar4 != 0) {
    return (int)sVar4;
  }
  uVar5 = _CFDictionaryCreateMutable(0,0,PTR_00103880,PTR_00103868);
  uVar7 = DAT_000fd560;
  local_20[0] = 0;
  local_28 = 0;
  uVar6 = _CFNumberCreate(0,3,&local_28);
  _CFDictionarySetValue(uVar5,uVar7,uVar6);
  _CFRelease(uVar6);
  uVar7 = DAT_000fd568;
  local_20[0] = local_44;
  local_28 = local_44;
  uVar6 = _CFNumberCreate(0,3,&local_28);
  _CFDictionarySetValue(uVar5,uVar7,uVar6);
  _CFRelease(uVar6);
  uVar7 = DAT_000fd55c;
  local_20[0] = local_40;
  local_28 = local_40;
  uVar6 = _CFNumberCreate(0,3,&local_28);
  _CFDictionarySetValue(uVar5,uVar7,uVar6);
  _CFRelease(uVar6);
  uVar7 = DAT_000fd558;
  local_20[0] = local_3c;
  local_28 = local_3c;
  uVar6 = _CFNumberCreate(0,3,&local_28);
  _CFDictionarySetValue(uVar5,uVar7,uVar6);
  _CFRelease(uVar6);
  uVar7 = _CFDataCreateMutable(0,0);
  uVar12 = 0;
  do {
    iVar9 = param_1 + 0x20 + uVar12 * 0x14;
    piVar10 = *(int **)(iVar9 + 8);
    uVar8 = *(int *)(iVar9 + 0xc) - (int)piVar10 >> 2;
    if (uVar8 != 0) {
      local_50 = 0;
      do {
        piVar1 = piVar10 + local_50;
        if ((piVar1 < *(int **)(iVar9 + 0xc)) && (piVar10 <= piVar1)) {
          iVar11 = *piVar1;
          if (*(char *)(iVar11 + 0x20) != '\0') goto LAB_000a9f54;
          iVar2 = *(int *)(iVar11 + 0x1c);
        }
        else {
          iVar11 = 0;
LAB_000a9f54:
          iVar2 = (*(int *)(iVar11 + 0x28) - *(int *)(iVar11 + 0x24) >> 3) * -0x55555555;
        }
        if (iVar2 != 0) {
          local_30 = uVar12 >> 0x18 | (uVar12 & 0xff0000) >> 8 | (uVar12 & 0xff00) << 8 |
                     uVar12 << 0x18;
          local_2c = local_50 >> 0x18 | (local_50 & 0xff0000) >> 8 | (local_50 & 0xff00) << 8 |
                     local_50 << 0x18;
          _CFDataAppendBytes(uVar7,&local_30,8);
          FUN_000ab85e(iVar11,uVar7);
        }
        local_50 = local_50 + 1;
        if (uVar8 <= local_50) break;
        piVar10 = *(int **)(iVar9 + 8);
      } while( true );
    }
    do {
      uVar12 = uVar12 + 1;
      if (3 < uVar12) {
        _CFDictionarySetValue(uVar5,DAT_000fd554,uVar7);
        _CFRelease(uVar7);
        _CFDictionarySetValue(uVar5,DAT_000fd550,*(undefined4 *)(param_1 + 0xac));
        local_20[0] = 0;
        iVar9 = FUN_000a983c(param_1,0x1a,0,0,local_20);
        uVar7 = DAT_000fd548;
        if (iVar9 == 0) {
          local_28 = local_20[0];
          uVar6 = _CFNumberCreate(0,3,&local_28);
          _CFDictionarySetValue(uVar5,uVar7,uVar6);
          _CFRelease(uVar6);
        }
        iVar9 = FUN_000a983c(param_1,6,0,0,local_24);
        if (iVar9 == 0) {
          uVar7 = _CFNumberCreate(0,0xc,local_24);
          _CFDictionarySetValue(uVar5,DAT_000fd544,uVar7);
          _CFRelease(uVar7);
        }
        iVar11 = 0;
        iVar9 = param_1 + 0x20;
        goto LAB_000aa0ab;
      }
    } while (uVar12 == 3);
  } while( true );
LAB_000aa0ab:
  cVar3 = FUN_000abe9e(iVar9);
  if (cVar3 != '\0') {
    local_28 = _CFDictionaryCreateMutable(0,0,PTR_00103880,PTR_00103868);
    iVar9 = 0;
    param_1 = param_1 + 0x20;
    do {
      FUN_000abce6(param_1,&local_28);
      iVar9 = iVar9 + 1;
      param_1 = param_1 + 0x14;
    } while (iVar9 != 5);
    _CFDictionarySetValue(uVar5,DAT_000fd540,local_28);
    _CFRelease(local_28);
LAB_000aa0c6:
    *param_2 = uVar5;
    return 0;
  }
  iVar11 = iVar11 + 1;
  iVar9 = iVar9 + 0x14;
  if (iVar11 == 5) goto LAB_000aa0c6;
  goto LAB_000aa0ab;
}

