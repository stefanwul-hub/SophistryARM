/* 0006fc06 StepSeq_c_vslot_30 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void StepSeq_c_vslot_30(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x1d8) != 0) {
    Envelope_c_vslot_30(param_1,param_2,param_3);
    if (((*(char *)(param_1 + 0x15c) != '\0') && (param_3 == 0xc)) &&
       (*(int *)(param_1 + 0x1d8) != 0)) {
      uVar1 = FUN_000122c2(*(undefined4 *)(param_1 + 0x120),param_2,0xc);
      FUN_000b5a12(*(int *)(param_1 + 0x1d8) + 0x44f4,param_1,param_2,uVar1,"Arpeggiator");
      return;
    }
  }
  return;
}

