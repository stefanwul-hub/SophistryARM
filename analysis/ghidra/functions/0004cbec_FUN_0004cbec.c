/* 0004cbec FUN_0004cbec */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0004cbec(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1 + 0x32aa04;
  iVar1 = Envelope_c_vslot_12(iVar2,*(undefined4 *)(param_1 + 0xcfe0),0x5a);
  if (iVar1 == 1) {
    (**(code **)(*(int *)(param_1 + 0x8be40) + 0x44))(param_1 + 0x8be40,0,1,"");
LAB_0004ceb0:
    FUN_000349f0(param_1 + 0x8d9e0,*(undefined4 *)(param_1 + 0xcfe0));
  }
  else if (iVar1 < 2) {
    if (iVar1 == 0) {
      (**(code **)(*(int *)(param_1 + 0x8a280) + 0x44))(param_1 + 0x8a280,0,3,"");
      (**(code **)(*(int *)(param_1 + 0x8be40) + 0x44))(param_1 + 0x8be40,0,1,"");
      goto LAB_0004ceb0;
    }
  }
  else {
    if (iVar1 == 2) {
      (**(code **)(*(int *)(param_1 + 0x8a280) + 0x44))(param_1 + 0x8a280,0,3,"");
      goto LAB_0004ceb0;
    }
    if (iVar1 == 3) {
      (**(code **)(*(int *)(param_1 + 0x8a280) + 0x44))(param_1 + 0x8a280,0,3,"");
      (**(code **)(*(int *)(param_1 + 0x8be40) + 0x44))(param_1 + 0x8be40,0,1,"");
    }
  }
  iVar1 = Envelope_c_vslot_12(iVar2,*(undefined4 *)(param_1 + 0xcfe0),0x5b);
  if (iVar1 == 1) {
    (**(code **)(*(int *)(param_1 + 0x8c528) + 0x44))(param_1 + 0x8c528,0,1,"");
LAB_0004cdc0:
    FUN_000349f0(param_1 + 0x97b98,*(undefined4 *)(param_1 + 0xcfe0));
    iVar1 = Envelope_c_vslot_12(iVar2,*(undefined4 *)(param_1 + 0xcfe0),0x66);
  }
  else {
    if (iVar1 < 2) {
      if (iVar1 == 0) {
        (**(code **)(*(int *)(param_1 + 0x8a970) + 0x44))(param_1 + 0x8a970,0,3,"");
        (**(code **)(*(int *)(param_1 + 0x8c528) + 0x44))(param_1 + 0x8c528,0,1,"");
        goto LAB_0004cdc0;
      }
    }
    else {
      if (iVar1 == 2) {
        (**(code **)(*(int *)(param_1 + 0x8a970) + 0x44))(param_1 + 0x8a970,0,3,"");
        goto LAB_0004cdc0;
      }
      if (iVar1 == 3) {
        (**(code **)(*(int *)(param_1 + 0x8a970) + 0x44))(param_1 + 0x8a970,0,3,"");
        (**(code **)(*(int *)(param_1 + 0x8c528) + 0x44))(param_1 + 0x8c528,0,1,"");
      }
    }
    iVar1 = Envelope_c_vslot_12(iVar2,*(undefined4 *)(param_1 + 0xcfe0),0x66);
  }
  if (iVar1 == 1) {
    (**(code **)(*(int *)(param_1 + 0x8cc10) + 0x44))(param_1 + 0x8cc10,0,1,"");
    iVar2 = Envelope_c_vslot_12(iVar2,*(undefined4 *)(param_1 + 0xcfe0),0x67);
  }
  else {
    if (iVar1 == 2) {
      (**(code **)(*(int *)(param_1 + 0x8b060) + 0x44))(param_1 + 0x8b060,0,3,"");
    }
    else if (iVar1 == 0) {
      (**(code **)(*(int *)(param_1 + 0x8b060) + 0x44))(param_1 + 0x8b060,0,3,"");
      (**(code **)(*(int *)(param_1 + 0x8cc10) + 0x44))(param_1 + 0x8cc10,0,1,"");
    }
    iVar2 = Envelope_c_vslot_12(iVar2,*(undefined4 *)(param_1 + 0xcfe0),0x67);
  }
  if (iVar2 != 1) {
    if (iVar2 == 2) {
      (**(code **)(*(int *)(param_1 + 0x8b750) + 0x44))(param_1 + 0x8b750,0,3,"");
      return;
    }
    if (iVar2 == 0) {
      (**(code **)(*(int *)(param_1 + 0x8b750) + 0x44))(param_1 + 0x8b750,0,3,"");
      (**(code **)(*(int *)(param_1 + 0x8d2f8) + 0x44))(param_1 + 0x8d2f8,0,1,"");
    }
    return;
  }
  (**(code **)(*(int *)(param_1 + 0x8d2f8) + 0x44))(param_1 + 0x8d2f8,0,1,"");
  return;
}

