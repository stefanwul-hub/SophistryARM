/* 000b39f2 SamTC3_c_vslot_31 */

void SamTC3_c_vslot_31(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x124);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x1e4) = *(undefined4 *)(iVar1 + 0x3fc);
    *(undefined1 *)(param_1 + 0x3b0) = *(undefined1 *)(iVar1 + 0x39c);
  }
  return;
}

