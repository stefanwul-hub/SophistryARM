/* 000826d6 CSampleDisplayKj_c_vslot_4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CSampleDisplayKj_c_vslot_4(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  longdouble lVar7;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  float local_24;
  float local_20 [4];
  
  if (param_2 != 0) {
    CControlPl_vslot_4(param_1,param_2);
    uVar1 = *(undefined4 *)(param_1 + 0x14);
    uVar2 = *(undefined4 *)(param_1 + 0x10);
    uVar3 = *(undefined4 *)(param_1 + 0xc);
    uVar4 = *(undefined4 *)(param_1 + 8);
    piVar5 = *(int **)(param_1 + 0xcc);
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 0x10))(piVar5,param_2,param_1 + 8,param_1 + 0xb4);
      piVar5 = *(int **)(param_1 + 200);
      if (((piVar5 != (int *)0x0) && (iVar6 = *piVar5, iVar6 != 0)) &&
         (*(int *)(iVar6 + 0x21c) != 0)) {
        iVar6 = *(int *)(iVar6 + 0x210);
        *(float *)(param_1 + 0xdc) = (float)iVar6;
        *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(*piVar5 + 0x22c);
        *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(*piVar5 + 0x26c);
        lVar7 = (longdouble)FUN_000152c0((float)*(int *)(param_1 + 0xe0),(float)iVar6);
        *(float *)(param_1 + 0xe8) = (float)lVar7;
        if ((1000.0 < *(float *)(param_1 + 0xdc)) && (0 < *(int *)(param_1 + 0xe0))) {
          FUN_00081258(param_1,local_20,&local_24);
          *(float *)(param_1 + 0xec) = local_24 - local_20[0];
          local_34 = uVar4;
          local_30 = uVar3;
          local_2c = uVar2;
          local_28 = uVar1;
          FUN_0008231e(param_1,param_2,&local_34,local_20[0],local_24 - local_20[0]);
          FUN_00081cc0(param_1,param_2,local_20[0],*(undefined4 *)(param_1 + 0xec));
        }
      }
    }
  }
  return;
}

