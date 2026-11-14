/* 00027f7a SynthEditor_c_vslot_1 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void SynthEditor_c_vslot_1(undefined4 *param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  int local_24;
  
  *param_1 = &PTR_SynthEditor_c_vslot_0_000e7428;
  param_1[8] = &PTR_LAB_000e74e4;
  *(undefined1 *)((int)param_1 + 0x51) = 0;
  FUN_0002e340(param_1 + 0x9775,0xfa);
  do {
    cVar2 = FUN_0002ddaa(DAT_00101ea0);
  } while (cVar2 == '\0');
  iVar3 = _OSAtomicAdd32Barrier(0xffffffff,&DAT_000e2020);
  if (iVar3 == 0) {
    piVar6 = &DAT_00101ec0;
    do {
      piVar1 = (int *)*piVar6;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
        *piVar6 = 0;
      }
      piVar6 = piVar6 + 1;
    } while (piVar6 != (int *)&DAT_00102824);
  }
  FUN_0002ddc8(DAT_00101ea0);
  iVar3 = 0;
  piVar6 = param_1 + 0x8216;
  do {
    if (piVar6[-1] != 0) {
      iVar4 = 0x4ff;
      puVar5 = param_1;
      do {
        while (puVar5[0x9112] == piVar6[-1]) {
          puVar5[0x9112] = 0;
          iVar4 = iVar4 + -1;
          puVar5 = puVar5 + -3;
          if (iVar4 < iVar3) goto LAB_00028065;
        }
        iVar4 = iVar4 + -1;
        puVar5 = puVar5 + -3;
      } while (iVar3 <= iVar4);
LAB_00028065:
      piVar1 = (int *)piVar6[-1];
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))(piVar1);
      }
      piVar6[-1] = 0;
    }
    if (*piVar6 != 0) {
      iVar4 = 0x4ff;
      puVar5 = param_1;
      do {
        while (puVar5[0x9113] == *piVar6) {
          puVar5[0x9113] = 0;
          iVar4 = iVar4 + -1;
          puVar5 = puVar5 + -3;
          if (iVar4 < iVar3) goto LAB_000280b3;
        }
        iVar4 = iVar4 + -1;
        puVar5 = puVar5 + -3;
      } while (iVar3 <= iVar4);
LAB_000280b3:
      piVar1 = (int *)*piVar6;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))(piVar1);
      }
      *piVar6 = 0;
    }
    iVar3 = iVar3 + 1;
    piVar6 = piVar6 + 3;
    if (iVar3 == 0x500) {
      Dependency_c_vslot_0(param_1 + 0x9dfa);
      if ((param_1 != (undefined4 *)0xfffda218) &&
         (puVar5 = param_1 + 0x9dfa, param_1 + 0x977a != puVar5)) {
        iVar3 = 0x40;
        do {
          puVar5 = puVar5 + -0x1a;
          FUN_00080750(puVar5);
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      OsLib_c_vslot_0(param_1 + 0x9775);
      if ((param_1 != (undefined4 *)0xffffffac) &&
         (puVar5 = param_1 + 0x8215, param_1 + 0x15 != puVar5)) {
        piVar6 = param_1 + 0x81fb;
        local_24 = 0x500;
        do {
          puVar5 = puVar5 + -0x1a;
          (**(code **)(*piVar6 + 0xc))(puVar5);
          piVar6 = piVar6 + -0x1a;
          local_24 = local_24 + -1;
        } while (local_24 != 0);
      }
      FUN_000a63c2(param_1);
      operator_delete(param_1);
      return;
    }
  } while( true );
}

