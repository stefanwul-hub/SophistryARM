/* 00085322 EnvDAD_c_vslot_33 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void EnvDAD_c_vslot_33(int param_1,undefined4 param_2,int param_3,char param_4,byte param_5)

{
  int iVar1;
  bool bVar2;
  longdouble lVar3;
  float fVar4;
  undefined *local_2c;
  undefined1 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  bVar2 = (*(byte *)(param_1 + 0x15d) & param_5) != 0;
  local_2c = PTR_DAT_00103808 + 8;
  local_28 = *(undefined1 *)(param_3 + 4);
  local_24 = *(undefined4 *)(param_3 + 8);
  local_20 = *(undefined4 *)(param_3 + 0xc);
  Envelope_c_vslot_33(param_1,param_2,&local_2c,param_4,bVar2);
  local_2c = PTR_DAT_00103808 + 8;
  if ((*(int *)(param_1 + 0x124) != 0) && (*(int *)(param_1 + 0x1d4) != 0)) {
    *(undefined4 *)(param_1 + 0x1e8) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x1ec) = 0x3f800000;
    if (param_4 == '\0') {
      **(undefined4 **)(param_1 + 0x1d4) = 0;
    }
    if ((!bVar2) && (*(undefined1 *)(param_1 + 0x1e0) = 0, *(char *)(param_1 + 0x1f8) != '\0')) {
      *(undefined4 *)(param_1 + 0x1f0) = 0;
      *(undefined4 *)(param_1 + 500) = 0;
      if ((*(int *)(param_1 + 0x124) == 0) ||
         ((*(float *)(param_1 + 0x140) <= 0.0 ||
          (iVar1 = (int)(((*(float *)(*(int *)(param_1 + 0x124) + 0x7c) *
                          *(float *)(param_1 + 0x1e8)) / *(float *)(param_1 + 0x1ec)) *
                        *(float *)(param_1 + 0x140)), iVar1 < 1)))) {
        iVar1 = 1;
        fVar4 = 1.0;
      }
      else {
        fVar4 = (float)iVar1;
      }
      lVar3 = (longdouble)
              FUN_000152c0(*(float *)(param_1 + 500) - **(float **)(param_1 + 0x1d4),fVar4);
      **(float **)(param_1 + 0x1d8) = (float)lVar3;
      **(int **)(param_1 + 0x1dc) = iVar1;
    }
  }
  return;
}

