/* 00019d66 Kaja_c_vslot_247 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Kaja_c_vslot_247(int param_1,undefined4 param_2,int *param_3,uint *param_4,int param_5,
                     uint param_6)

{
  char cVar1;
  uint uVar2;
  char local_15c [332];
  
  _sprintf(local_15c,"%sStereoOuts",param_2);
  cVar1 = FUN_0002e72e(param_1 + 0x38a0,local_15c,param_3);
  if (cVar1 == '\0') {
    *param_3 = param_5;
  }
  _sprintf(local_15c,"%sMonoOuts",param_2);
  cVar1 = FUN_0002e72e(param_1 + 0x38a0,local_15c,param_4);
  if (cVar1 == '\0') {
    *param_4 = param_6;
  }
  uVar2 = *param_4;
  if ((uVar2 & 1) != 0) {
    uVar2 = uVar2 - 1;
    *param_4 = uVar2;
  }
  if (uVar2 + *param_3 == 0) {
    *param_3 = 1;
  }
  return;
}

