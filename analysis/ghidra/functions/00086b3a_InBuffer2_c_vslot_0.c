/* 00086b3a InBuffer2_c_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void InBuffer2_c_vslot_0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  *param_1 = &PTR_InBuffer2_c_vslot_0_000f28e8;
  iVar1 = param_1[6];
  if (0 < iVar1) {
    iVar3 = 0;
    puVar2 = param_1;
    do {
      if (((*(char *)((int)param_1 + 0x25) == '\0') || (iVar3 == 1)) || (iVar3 == 3)) {
        if ((void *)puVar2[0xd] != (void *)0x0) {
          _free((void *)puVar2[0xd]);
          iVar1 = param_1[6];
        }
        puVar2[0xd] = 0;
        if (iVar1 <= iVar3 + 1) break;
      }
      else if (iVar1 <= iVar3 + 1) break;
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    } while( true );
  }
  if (iVar1 < 8) {
    do {
      iVar1 = iVar1 + 1;
    } while (iVar1 != 8);
  }
  return;
}

