/* 0003e6b4 LFOSimp_c_vslot_59 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void LFOSimp_c_vslot_59(int param_1,double param_2)

{
  int iVar1;
  double dVar2;
  
  if ((0.0 <= param_2) || (NAN(param_2))) {
    dVar2 = 1.0;
    if (param_2 <= 1.0) {
      dVar2 = param_2;
    }
  }
  else {
    dVar2 = 0.0;
  }
  if (*(int *)(param_1 + 0x124) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x124) + 0xe8);
    if (iVar1 == 4) {
      FUN_0003d5ec(param_1,dVar2,1);
    }
    else if (iVar1 == 5) {
      FUN_0003d5ec(param_1,dVar2,0);
    }
    else {
      FUN_0003e1b4(param_1,dVar2,iVar1);
    }
  }
  **(undefined4 **)(param_1 + 0x1dc) = *(undefined4 *)(param_1 + 0x794);
  **(undefined4 **)(param_1 + 0x1d4) = *(undefined4 *)(param_1 + 0x798);
  **(undefined4 **)(param_1 + 0x1d8) = *(undefined4 *)(param_1 + 0x79c);
  return;
}

