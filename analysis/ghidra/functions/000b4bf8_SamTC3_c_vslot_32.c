/* 000b4bf8 SamTC3_c_vslot_32 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void SamTC3_c_vslot_32(int *param_1,undefined4 param_2,int param_3,undefined1 param_4)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  longdouble lVar5;
  double dVar6;
  double dVar7;
  double local_44;
  undefined *local_3c;
  undefined1 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined *local_2c;
  undefined1 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if (0.0 < (float)param_1[0x50]) {
    local_3c = PTR_DAT_00103808 + 8;
    local_38 = *(undefined1 *)(param_3 + 4);
    local_34 = *(undefined4 *)(param_3 + 8);
    local_30 = *(undefined4 *)(param_3 + 0xc);
    OscAnalog3_c_vslot_32(param_1,param_2,&local_3c,param_4);
    local_3c = PTR_DAT_00103808 + 8;
    if ((param_1[0x49] != 0) && (param_1[0xf0] != 0)) {
      (**(code **)(*param_1 + 0x7c))(param_1,0xffffffff);
      param_1[0xf1] = 0;
      local_2c = PTR_DAT_00103808 + 8;
      local_28 = *(undefined1 *)(param_3 + 4);
      local_24 = *(undefined4 *)(param_3 + 8);
      local_20 = *(undefined4 *)(param_3 + 0xc);
      FUN_0003a18e(param_1[0xf0],param_2,&local_2c,param_1 + 0xf1);
      local_2c = PTR_DAT_00103808 + 8;
      if (param_1[0xf1] != 0) {
        iVar2 = param_1[0xf1];
        piVar3 = param_1;
        piVar4 = param_1;
        if (iVar2 == 0) {
          do {
            piVar3[0xd8] = 0;
            piVar3[0xd9] = 0;
            piVar3[0xe2] = 0;
            piVar3[0xe3] = 0;
            piVar3[0x88] = 0;
            piVar3[0x89] = 0;
            param_1[0xc4] = 0;
            param_1[0xc5] = 0;
            piVar3[0x92] = 0;
            piVar3[0x93] = -0x48c00000;
            param_1[0xc6] = 0;
            param_1[199] = -0x48c00000;
            piVar3[0xba] = -0x5f4a1273;
            piVar3[0xbb] = 0x3eb0c6f7;
            param_1[0xca] = -0x5f4a1273;
            param_1[0xcb] = 0x3eb0c6f7;
            piVar3[0x9c] = 0;
            piVar3[0x9d] = -0x40100000;
            param_1[0xcc] = 0;
            param_1[0xcd] = -0x40100000;
            piVar3[0xa6] = 0;
            piVar3[0xa7] = -0x40100000;
            param_1[0xce] = 0;
            param_1[0xcf] = -0x40100000;
            *(undefined1 *)(piVar4 + 0xd6) = 1;
            piVar3 = piVar3 + 2;
            piVar4 = (int *)((int)piVar4 + 1);
          } while (param_1 + 10 != piVar3);
        }
        else {
          do {
            dVar7 = (double)*(int *)(iVar2 + 0x26c);
            *(double *)(piVar3 + 0xd8) = dVar7;
            *(double *)(piVar3 + 0xe2) = (double)*(int *)(iVar2 + 0x270);
            dVar6 = (double)*(float *)(iVar2 + 0x224) + dVar7;
            *(double *)(piVar3 + 0x88) = dVar7;
            *(double *)(param_1 + 0xc4) = dVar7;
            *(double *)(piVar3 + 0x92) = dVar6;
            *(double *)(param_1 + 0xc6) = dVar6;
            piVar3[0xba] = -0x5f4a1273;
            piVar3[0xbb] = 0x3eb0c6f7;
            param_1[0xca] = -0x5f4a1273;
            param_1[0xcb] = 0x3eb0c6f7;
            *(double *)(piVar3 + 0x9c) = dVar7 - 1.0;
            *(double *)(param_1 + 0xcc) = dVar7 - 1.0;
            *(double *)(piVar3 + 0xa6) = dVar6 - 1.0;
            *(double *)(param_1 + 0xce) = dVar6 - 1.0;
            *(undefined1 *)(piVar4 + 0xd6) = 1;
            piVar3 = piVar3 + 2;
            piVar4 = (int *)((int)piVar4 + 1);
          } while (param_1 + 10 != piVar3);
        }
        param_1[0x87] = 0;
        param_1[0xee] = (int)((float)*(int *)(iVar2 + 0x210) * (float)param_1[0x51]);
        fVar1 = *(float *)(iVar2 + 0x238);
        lVar5 = (longdouble)FUN_000130fe(param_1,(float)*(int *)(param_3 + 8));
        *(double *)(param_1 + 0xd0) = (double)(float)param_1[0xee];
        iVar2 = param_1[0x49];
        if (*(char *)(iVar2 + 700) != '\0') {
          *(double *)(param_1 + 0xd0) =
               (double)(float)param_1[0xee] * ((double)(float)lVar5 / (double)fVar1);
        }
        local_44 = (double)(float)lVar5 / (double)fVar1;
        lVar5 = (longdouble)
                _pow(0,0x40000000,
                     (double)*(float *)(iVar2 + 0xec) +
                     (double)*(float *)(iVar2 + 0x15c) * 0.08333333333333333 +
                     (double)*(float *)(iVar2 + 0x1cc) * 0.0008333333333333334);
        *(double *)(param_1 + 0xd0) = (double)lVar5 * *(double *)(param_1 + 0xd0);
        fVar1 = (float)param_1[0xee];
        param_1[0xef] = (int)fVar1;
        lVar5 = (longdouble)_pow(local_44,(double)*(float *)(iVar2 + 0x31c));
        fVar1 = fVar1 * (float)lVar5;
        param_1[0xef] = (int)fVar1;
        lVar5 = (longdouble)FUN_000152c0(fVar1,*(undefined4 *)(iVar2 + 0x23c));
        param_1[0xef] = (int)(float)lVar5;
        return;
      }
    }
  }
  return;
}

