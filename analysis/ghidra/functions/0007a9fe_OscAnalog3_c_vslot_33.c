/* 0007a9fe OscAnalog3_c_vslot_33 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void OscAnalog3_c_vslot_33(int *param_1,undefined4 param_2,int param_3,char param_4,char param_5)

{
  double dVar1;
  char cVar2;
  int *piVar3;
  longdouble lVar4;
  float local_38;
  int *local_34;
  int *local_30;
  undefined *local_2c;
  undefined1 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_2c = PTR_DAT_00103808 + 8;
  local_28 = *(undefined1 *)(param_3 + 4);
  local_24 = *(undefined4 *)(param_3 + 8);
  local_20 = *(undefined4 *)(param_3 + 0xc);
  OscAnalog3_c_vslot_32(param_1,param_2,&local_2c,param_4);
  local_2c = PTR_DAT_00103808 + 8;
  if (param_1[0x49] != 0) {
    (**(code **)(*param_1 + 0x7c))(param_1,0xffffffff);
    cVar2 = *(char *)(param_1[0x49] + 0x5cc);
    lVar4 = (longdouble)FUN_0000c38c(param_1,*(undefined4 *)(param_3 + 8),7,5,6,8);
    *(double *)(param_1 + 0x81) = (double)(float)lVar4;
    if ((param_4 == '\0') || (param_5 == '\0')) {
      param_1[0x8b] = 0x44b830;
      param_1[0x8c] = 0x3ff00000;
      *(double *)(param_1 + 0x8d) = 1e-09;
      *(double *)(param_1 + 0x8f) = 1e-09;
      *(undefined1 *)(param_1 + 0x96) = 1;
      param_1[0x91] = 0;
      param_1[0x92] = 0;
      param_1[0x94] = 0;
      param_1[0x95] = -0x40100000;
      param_1[0x97] = (int)(float)*(double *)(param_1 + 0x89);
      if (cVar2 == '\0') {
        local_38 = 0.0;
      }
      else {
        local_38 = 0.99;
      }
      local_34 = param_1;
      local_30 = param_1;
      piVar3 = param_1;
      do {
        dVar1 = *(double *)(param_1 + 0x8b);
        lVar4 = (longdouble)FUN_0002e314();
        *(double *)(piVar3 + 0x9d) =
             (double)((float)lVar4 * local_38) + (double)((float)lVar4 * local_38) + dVar1;
        *(undefined8 *)(piVar3 + 0xa7) = *(undefined8 *)(param_1 + 0x8d);
        *(undefined8 *)(piVar3 + 0xb1) = *(undefined8 *)(param_1 + 0x8f);
        *(char *)(local_34 + 0xcf) = (char)param_1[0x96];
        *(undefined8 *)(piVar3 + 0xbb) = *(undefined8 *)(param_1 + 0x91);
        *(undefined8 *)(piVar3 + 0xc5) = *(undefined8 *)(param_1 + 0x94);
        *(double *)(piVar3 + 0xd1) = (double)(float)param_1[0x97];
        *(undefined1 *)(param_1 + 0x98) = 1;
        *(undefined1 *)(local_34 + 0xdb) = 1;
        param_1[0xf1] = 0;
        param_1[0xf2] = 0;
        piVar3[0xf3] = 0;
        piVar3[0xf4] = 0;
        param_1[0xfd] = 0;
        param_1[0xfe] = 0;
        piVar3[0xff] = 0;
        piVar3[0x100] = 0;
        param_1[0x109] = 0;
        param_1[0x10a] = 0;
        piVar3[0x10b] = 0;
        piVar3[0x10c] = 0;
        param_1[0x115] = 0;
        local_30[0x116] = 0;
        piVar3 = piVar3 + 2;
        local_34 = (int *)((int)local_34 + 1);
        local_30 = local_30 + 1;
      } while (piVar3 != param_1 + 10);
      *(undefined8 *)(param_1 + 0x8b) = *(undefined8 *)(param_1 + 0x9d);
    }
    else if (cVar2 == '\0') {
      piVar3 = param_1;
      do {
        *(undefined8 *)(piVar3 + 0x9f) = *(undefined8 *)(param_1 + 0x9d);
        piVar3 = piVar3 + 2;
      } while (piVar3 != param_1 + 8);
      return;
    }
  }
  return;
}

