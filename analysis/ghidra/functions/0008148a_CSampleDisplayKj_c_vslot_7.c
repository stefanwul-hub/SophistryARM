/* 0008148a CSampleDisplayKj_c_vslot_7 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CSampleDisplayKj_c_vslot_7(int *param_1,undefined4 param_2)

{
  uint uVar1;
  byte bVar2;
  longdouble lVar3;
  longdouble lVar4;
  float fVar5;
  float fVar6;
  float local_34;
  int local_2c;
  int local_28;
  float local_24;
  float local_20 [4];
  
  FUN_00001bd4(param_1);
  if (0 < param_1[0x38]) {
    local_2c = 0;
    local_28 = 0;
    (**(code **)(*param_1 + 0x84))(param_1,param_2,&local_2c);
    FUN_00081258(param_1,local_20,&local_24);
    lVar3 = (longdouble)FUN_000152c0((float)param_1[0x38],param_1[0x37]);
    param_1[0x3a] = (int)(float)lVar3;
    lVar3 = (longdouble)
            FUN_000152c0((float)(local_2c - param_1[2]),(float)(param_1[4] - param_1[2]));
    lVar3 = (longdouble)
            FUN_000152c0(local_20[0] + (local_24 - local_20[0]) * (float)lVar3,param_1[0x3a]);
    fVar6 = (float)lVar3;
    lVar3 = (longdouble)FUN_00001ace(param_1,0);
    local_34 = ABS(fVar6 - (float)lVar3);
    if (param_1[3] + 0xc < local_28) {
      lVar3 = (longdouble)FUN_00001ace(param_1,1);
      bVar2 = ABS(fVar6 - (float)lVar3) <= local_34;
      if ((bool)bVar2) {
        lVar3 = (longdouble)FUN_00001ace(param_1,1);
        local_34 = ABS(fVar6 - (float)lVar3);
      }
      lVar3 = (longdouble)FUN_00001ace(param_1,2);
      if (ABS(fVar6 - (float)lVar3) <= local_34) {
        FUN_00001ace(param_1,2);
        bVar2 = 2;
      }
    }
    else {
      bVar2 = 3;
    }
    lVar3 = (longdouble)FUN_00001ace(param_1,0);
    lVar4 = (longdouble)FUN_00001ace(param_1,1);
    if ((((float)lVar3 == (float)lVar4) && (!NAN((float)lVar3) && !NAN((float)lVar4))) &&
       (bVar2 < 2)) {
      lVar3 = (longdouble)FUN_00001ace(param_1,0);
      bVar2 = (float)lVar3 <= fVar6;
    }
    while (uVar1 = FUN_0009cba2(param_2), (uVar1 & 5) != 0) {
      lVar3 = (longdouble)
              FUN_000152c0((float)(local_2c - param_1[2]),(float)(param_1[4] - param_1[2]));
      lVar3 = (longdouble)
              FUN_000152c0(local_20[0] + (local_24 - local_20[0]) * (float)lVar3,param_1[0x3a]);
      fVar6 = (float)lVar3;
      if (bVar2 == 3) {
        lVar3 = (longdouble)FUN_00001ace(param_1,1);
        fVar6 = fVar6 - (float)lVar3;
      }
      if ((0.0 <= fVar6) || (NAN(fVar6))) {
        fVar5 = 1.0;
        if (fVar6 <= 1.0) {
          fVar5 = fVar6;
        }
      }
      else {
        fVar5 = 0.0;
      }
      FUN_00001b2e(param_1,param_2,bVar2,fVar5);
      (**(code **)(*param_1 + 0x84))(param_1,param_2,&local_2c);
      (**(code **)(*param_1 + 0xac))(param_1);
    }
  }
  return;
}

