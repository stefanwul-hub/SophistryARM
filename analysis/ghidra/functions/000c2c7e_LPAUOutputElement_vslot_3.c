/* 000c2c7e LPAUOutputElement_vslot_3 */

int LPAUOutputElement_vslot_3(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = AUOutputElement_vslot_3(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0x790006;
    if (*(int *)(param_1 + 0x50) != 6) {
      uVar2 = 0x650002;
    }
    FUN_000ae5a0(param_1 + 0x78,uVar2);
  }
  return iVar1;
}

