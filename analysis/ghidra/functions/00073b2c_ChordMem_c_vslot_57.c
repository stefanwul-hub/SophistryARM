/* 00073b2c ChordMem_c_vslot_57 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

bool ChordMem_c_vslot_57(int param_1,char *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 local_3d;
  
  if (*(int *)(param_1 + 0x124) != 0) {
    if (*param_2 != '\0') {
      FUN_0002d6fe(param_1 + 0x1e4 + *(int *)(param_3 + 8) * 0x14);
      *(undefined4 *)(param_1 + 0x1e0) = 0;
      *param_2 = '\0';
    }
    iVar3 = *(int *)(param_1 + 0x124);
    iVar2 = *(int *)(iVar3 + 0x158);
    if (iVar2 < 1) {
      iVar2 = 1;
    }
    iVar4 = *(int *)(param_1 + 0x1e0);
    local_3d = iVar4 < iVar2;
    if (*(int *)(param_1 + 0x1d8) != 2) {
      local_3d = iVar4 == 0;
    }
    if (local_3d != false) {
      iVar3 = (*(int *)(iVar4 * 0xe0 + 0x1c8 + iVar3) - *(int *)(iVar3 + 0x1c8)) +
              *(int *)(param_3 + 8);
      *(int *)(param_4 + 8) = iVar3;
      if (iVar3 < 0) {
        do {
          iVar3 = iVar3 + 0xc;
        } while (iVar3 < 0);
        *(int *)(param_4 + 8) = iVar3;
      }
      if (0x7f < iVar3) {
        do {
          iVar3 = iVar3 + -0xc;
        } while (0x7f < iVar3);
        *(int *)(param_4 + 8) = iVar3;
      }
      iVar3 = (*(int *)(*(int *)(param_1 + 0x1e0) * 0xe0 + 0x238 + *(int *)(param_1 + 0x124)) -
              *(int *)(*(int *)(param_1 + 0x124) + 0x238)) + *(int *)(param_3 + 0xc);
      *(int *)(param_4 + 0xc) = iVar3;
      *(undefined4 *)(param_4 + 0x10) = *(undefined4 *)(param_3 + 0x10);
      if (iVar3 < 1) {
        iVar3 = 1;
      }
      else if (0x7f < iVar3) {
        iVar3 = 0x7f;
      }
      *(int *)(param_4 + 0xc) = iVar3;
      iVar3 = *(int *)(param_4 + 8);
      uVar1 = *(undefined4 *)(param_3 + 0x10);
      iVar2 = 0;
      if (-1 < *(int *)(param_3 + 8)) {
        iVar2 = *(int *)(param_3 + 8);
      }
      iVar4 = 0x7f;
      if (SCARRY4(iVar2,-0x80) != iVar2 + -0x80 < 0) {
        iVar4 = iVar2;
      }
      if (iVar3 < 0) {
        iVar3 = 0;
      }
      else if (0x7f < iVar3) {
        iVar3 = 0x7f;
      }
      FUN_0002d756(param_1 + 0x1e4 + iVar4 * 0x14,iVar3);
      *(undefined4 *)(param_1 + 0xbe4 + iVar4 * 4) = uVar1;
      *(int *)(param_1 + 0x1e0) = *(int *)(param_1 + 0x1e0) + 1;
    }
    return local_3d;
  }
  return false;
}

