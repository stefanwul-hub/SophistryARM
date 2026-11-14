/* 000a90c4 AUBase_vslot_30 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int AUBase_vslot_30(int param_1,undefined4 param_2)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  char cVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  int local_90;
  char local_80 [64];
  undefined1 local_40 [4];
  int local_3c;
  int local_38;
  undefined1 local_2c [4];
  int local_28;
  int local_24;
  undefined4 local_20 [4];
  
  iVar7 = _CFGetTypeID(param_2);
  iVar8 = _CFDictionaryGetTypeID();
  if (iVar7 == iVar8) {
    sVar6 = _GetComponentInfo(*(undefined4 *)(param_1 + 4),local_40,0,0,0);
    if (sVar6 != 0) {
      return (int)sVar6;
    }
    cVar5 = _CFDictionaryContainsKey(param_2,DAT_000fd564);
    if ((cVar5 == '\0') && (local_24 = _CFDictionaryGetValue(param_2,DAT_000fd560), local_24 != 0))
    {
      _CFNumberGetValue(local_24,3,&local_28);
      if ((local_28 == 0) &&
         ((((local_24 = _CFDictionaryGetValue(param_2,DAT_000fd55c), local_24 != 0 &&
            (_CFNumberGetValue(local_24,3,&local_28), local_28 == local_3c)) &&
           (local_24 = _CFDictionaryGetValue(param_2,DAT_000fd558), local_24 != 0)) &&
          (_CFNumberGetValue(local_24,3,&local_28), local_28 == local_38)))) {
        iVar7 = _CFDictionaryGetValue(param_2,DAT_000fd554);
        if (iVar7 != 0) {
          puVar9 = (uint *)_CFDataGetBytePtr(iVar7);
          iVar7 = _CFDataGetLength(iVar7);
          puVar1 = (uint *)((int)puVar9 + iVar7);
          for (; puVar9 < puVar1; puVar9 = (uint *)FUN_000ac62e(*piVar2,puVar9 + 2)) {
            uVar3 = *puVar9;
            uVar10 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18
            ;
            uVar3 = puVar9[1];
            if (4 < uVar10) {
              puVar12 = (undefined4 *)___cxa_allocate_exception(4);
              *puVar12 = 0xffffd58e;
                    /* WARNING: Subroutine does not return */
              ___cxa_throw(puVar12,PTR_001037fc,0);
            }
            iVar7 = param_1 + 0x20 + uVar10 * 0x14;
            piVar4 = *(int **)(iVar7 + 8);
            piVar2 = piVar4 + (uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 |
                              uVar3 << 0x18);
            if (((*(int **)(iVar7 + 0xc) <= piVar2) || (piVar2 < piVar4)) || (*piVar2 == 0)) break;
          }
        }
        iVar7 = _CFDictionaryGetValue(param_2,DAT_000fd550);
        if (*(int *)(param_1 + 0xac) != 0) {
          _CFRelease(*(int *)(param_1 + 0xac));
        }
        if (iVar7 == 0) {
          *(undefined4 *)(param_1 + 0xac) = DAT_000fd54c;
          *(undefined4 *)(param_1 + 0xa8) = 0xffffffff;
        }
        else {
          *(int *)(param_1 + 0xac) = iVar7;
          *(undefined4 *)(param_1 + 0xa8) = 0xffffffff;
        }
        _CFRetain(*(undefined4 *)(param_1 + 0xac));
        FUN_000a67ae(param_1,0x1c,0,0);
        FUN_000a67ae(param_1,0x24,0,0);
        cVar5 = _CFDictionaryGetValueIfPresent(param_2,DAT_000fd548,&local_24);
        if (cVar5 != '\0') {
          _CFNumberGetValue(local_24,3,&local_28);
          FUN_000a81f0(param_1,0x1a,0,0,&local_28,4);
        }
        cVar5 = _CFDictionaryGetValueIfPresent(param_2,DAT_000fd544,&local_24);
        if (cVar5 != '\0') {
          _CFNumberGetValue(local_24,0xc,local_2c);
          FUN_000a81f0(param_1,6,0,0,local_2c,4);
        }
        cVar5 = _CFDictionaryGetValueIfPresent(param_2,DAT_000fd540,local_20);
        if (cVar5 != '\0') {
          local_90 = 0;
          iVar7 = param_1 + 0x20;
          do {
            _sprintf(local_80,"%ld",local_90);
            uVar11 = _CFStringCreateWithCString(0,local_80,0x600);
            cVar5 = _CFDictionaryGetValueIfPresent(local_20[0],uVar11,local_2c);
            if ((cVar5 != '\0') && (cVar5 = FUN_000ac056(iVar7,local_2c), cVar5 != '\0')) {
              FUN_000a67ae(param_1,0xb,local_90,0);
            }
            _CFRelease(uVar11);
            local_90 = local_90 + 1;
            iVar7 = iVar7 + 0x14;
          } while (local_90 != 5);
        }
        return 0;
      }
    }
  }
  return -0x2a63;
}

