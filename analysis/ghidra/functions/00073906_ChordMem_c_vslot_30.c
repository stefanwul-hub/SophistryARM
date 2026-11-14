/* 00073906 ChordMem_c_vslot_30 */

void ChordMem_c_vslot_30(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  Envelope_c_vslot_30(param_1,param_2,param_3);
  if (param_3 == 1) {
    iVar1 = FUN_000122c2(*(undefined4 *)(param_1 + 0x120),param_2,1);
    if (iVar1 == 0) {
      uVar3 = 0;
      uVar2 = 2;
      goto LAB_0007399c;
    }
    if (iVar1 == 1) {
      uVar3 = 2;
      uVar2 = 2;
      goto LAB_0007399c;
    }
LAB_00073939:
    if (param_3 != -1) {
      return;
    }
    iVar1 = FUN_000122c2(*(undefined4 *)(param_1 + 0x120),param_2,2);
    if (iVar1 != 1) {
      return;
    }
    FUN_00012222(*(undefined4 *)(param_1 + 0x120),param_2,2,0);
    uVar3 = 0;
  }
  else {
    if (param_3 != 2) goto LAB_00073939;
    iVar1 = FUN_000122c2(*(undefined4 *)(param_1 + 0x120),param_2,2);
    if (iVar1 == 1) {
      uVar3 = 1;
      uVar2 = 1;
      goto LAB_0007399c;
    }
    if (iVar1 != 2) {
      if (iVar1 != 0) {
        return;
      }
      uVar3 = 0;
      uVar2 = 1;
      goto LAB_0007399c;
    }
    uVar3 = 1;
  }
  uVar2 = 1;
LAB_0007399c:
  FUN_00012222(*(undefined4 *)(param_1 + 0x120),param_2,uVar2,uVar3);
  return;
}

