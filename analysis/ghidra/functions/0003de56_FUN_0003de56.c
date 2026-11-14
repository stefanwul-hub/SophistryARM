/* 0003de56 FUN_0003de56 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0003de56(int param_1,undefined4 param_2,int param_3,char param_4,char param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined *local_2c;
  undefined1 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_2c = PTR_DAT_00103808 + 8;
  local_28 = *(undefined1 *)(param_3 + 4);
  local_24 = *(undefined4 *)(param_3 + 8);
  local_20 = *(undefined4 *)(param_3 + 0xc);
  Modulator_c_vslot_33(param_1,param_2,&local_2c,param_4,param_5);
  local_2c = PTR_DAT_00103808 + 8;
  if ((*(int *)(param_1 + 0x124) != 0) && (*(char *)(param_1 + 0x1f8) != '\0')) {
    if (param_4 == '\0') {
      uVar2 = 0;
    }
    else {
      uVar2 = **(undefined4 **)(param_1 + 0x1d4);
    }
    *(undefined4 *)(param_1 + 0x798) = uVar2;
    if (param_5 == '\0') {
      *(undefined4 *)(param_1 + 0x1e8) = 0x3f800000;
      *(undefined4 *)(param_1 + 0x1ec) = 0x3f800000;
      *(undefined4 *)(param_1 + 0x794) = 0;
      *(undefined4 *)(param_1 + 0x79c) = 0;
      iVar1 = *(int *)(*(int *)(param_1 + 0x124) + 0xe8);
      if (iVar1 == 4) {
        uVar3 = FUN_0002e30a();
        uVar3 = uVar3 & 0x800000ff;
        if ((int)uVar3 < 0) {
          uVar3 = (uVar3 - 1 | 0xffffff00) + 1;
        }
        *(uint *)(param_1 + 0x1f0) = uVar3;
        FUN_0003dbbc(param_1);
        return;
      }
      if (iVar1 == 5) {
        uVar3 = FUN_0002e30a();
        uVar3 = uVar3 & 0x800000ff;
        if ((int)uVar3 < 0) {
          uVar3 = (uVar3 - 1 | 0xffffff00) + 1;
        }
        *(uint *)(param_1 + 0x1f0) = uVar3;
        FUN_0003d326(param_1);
      }
      else {
        FUN_0003d822(param_1,0);
      }
    }
  }
  return;
}

