/* 000abce6 FUN_000abce6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000abce6(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  uint local_24;
  
  piVar6 = *(int **)(param_1 + 8);
  uVar5 = 0;
  if (*(int *)(param_1 + 0xc) - (int)piVar6 >> 2 != 0) {
    do {
      piVar7 = piVar6 + uVar5;
      if ((((piVar7 < *(int **)(param_1 + 0xc)) && (piVar6 <= piVar7)) && (*piVar7 != 0)) &&
         (*(int *)(*piVar7 + 0x30) != 0)) {
        uVar3 = _CFDictionaryCreateMutable(0,0,PTR_00103880,PTR_00103868);
        local_24 = 0;
        piVar7 = *(int **)(param_1 + 8);
        piVar6 = *(int **)(param_1 + 0xc);
        if ((int)piVar6 - (int)piVar7 >> 2 != 0) {
          do {
            piVar1 = piVar7 + local_24;
            if ((piVar1 < piVar6) && (piVar7 <= piVar1)) {
              iVar2 = *piVar1;
              if ((iVar2 != 0) && (*(int *)(iVar2 + 0x30) != 0)) {
                _sprintf(&DAT_000fd580,"%ld",local_24);
                uVar4 = _CFStringCreateWithCString(0,&DAT_000fd580,0x600);
                _CFDictionarySetValue(uVar3,uVar4,*(undefined4 *)(iVar2 + 0x30));
                _CFRelease(uVar4);
                piVar7 = *(int **)(param_1 + 8);
              }
            }
            local_24 = local_24 + 1;
            piVar6 = *(int **)(param_1 + 0xc);
          } while (local_24 < (uint)((int)piVar6 - (int)piVar7 >> 2));
        }
        _sprintf(&DAT_000fd580,"%ld",*(undefined4 *)(param_1 + 4));
        uVar4 = _CFStringCreateWithCString(0,&DAT_000fd580,0x600);
        _CFDictionarySetValue(*param_2,uVar4,uVar3);
        _CFRelease(uVar4);
        _CFRelease();
        return;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < (uint)(*(int *)(param_1 + 0xc) - (int)piVar6 >> 2));
  }
  return;
}

