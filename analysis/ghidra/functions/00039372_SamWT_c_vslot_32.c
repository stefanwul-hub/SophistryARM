/* 00039372 SamWT_c_vslot_32 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void SamWT_c_vslot_32(int *param_1,undefined4 param_2,int param_3,undefined1 param_4)

{
  int *piVar1;
  int iVar2;
  longdouble lVar3;
  longdouble lVar4;
  double local_54;
  undefined *local_40;
  undefined1 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined *local_30;
  undefined1 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  float local_20 [4];
  
  local_40 = PTR_DAT_00103808 + 8;
  local_3c = *(undefined1 *)(param_3 + 4);
  local_38 = *(undefined4 *)(param_3 + 8);
  local_34 = *(undefined4 *)(param_3 + 0xc);
  OscAnalog3_c_vslot_32(param_1,param_2,&local_40,param_4);
  local_40 = PTR_DAT_00103808 + 8;
  if (param_1[0x49] != 0) {
    (**(code **)(*param_1 + 0x7c))(param_1,0xffffffff);
    local_30 = PTR_DAT_00103808 + 8;
    local_2c = *(undefined1 *)(param_3 + 4);
    local_28 = *(undefined4 *)(param_3 + 8);
    local_24 = *(undefined4 *)(param_3 + 0xc);
    FUN_0008d858(param_1[0xa1],param_2,&local_30,param_1 + 0x86,local_20);
    local_30 = PTR_DAT_00103808 + 8;
    if (param_1[0x86] != 0) {
      iVar2 = 5;
      piVar1 = param_1;
      do {
        piVar1[0x87] = 0;
        piVar1[0x88] = 0;
        piVar1[0x91] = 0;
        piVar1[0x92] = 0;
        piVar1 = piVar1 + 2;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      iVar2 = param_1[0x49];
      if (*(char *)(iVar2 + 0x24c) == '\0') {
        local_54 = 32.70319566257483;
      }
      else {
        lVar3 = (longdouble)FUN_000130fe(param_1,(float)*(int *)(param_3 + 8));
        local_54 = (double)(float)lVar3;
        iVar2 = param_1[0x49];
      }
      lVar3 = (longdouble)
              _pow(0,0x40000000,
                   (double)*(float *)(iVar2 + 0xec) +
                   (double)*(float *)(iVar2 + 0x15c) * 0.08333333333333333 +
                   (double)*(float *)(iVar2 + 0x1cc) * 0.0008333333333333334);
      lVar4 = (longdouble)
              FUN_00015302((double)lVar3 * local_54 * 128.0,(double)(float)param_1[0x50]);
      *(double *)(param_1 + 0x9b) = (double)lVar4;
      iVar2 = param_1[0x49];
      lVar3 = (longdouble)
              _pow((double)lVar3 * local_54 * 0.003802825042667697,(double)*(float *)(iVar2 + 0x31c)
                  );
      lVar4 = (longdouble)
              FUN_000152c0(*(undefined4 *)(iVar2 + 0x2ac),(float)param_1[0x50] * local_20[0] * 0.125
                          );
      *(double *)(param_1 + 0x9f) = (double)lVar3 * 64.0 * (double)(float)lVar4;
    }
  }
  return;
}

