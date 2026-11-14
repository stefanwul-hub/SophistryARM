/* 00091ec2 FUN_00091ec2 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00091ec2(int *param_1,int param_2,float *param_3,float *param_4)

{
  float fVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double local_2c;
  int local_20;
  
  if (0 < param_2) {
    local_2c = 1e-07;
    local_20 = 0;
    do {
      dVar2 = (double)*param_3 - local_2c;
      param_3 = param_3 + 1;
      local_2c = -local_2c;
      fVar1 = *param_4;
      param_4 = param_4 + 1;
      dVar6 = (((dVar2 * *(double *)(param_1 + 0x7f) +
                 *(double *)(param_1 + 0x91) * *(double *)(param_1 + 0x81) +
                *(double *)(param_1 + 0x83) * *(double *)(param_1 + 0x93)) -
               *(double *)(param_1 + 0x7b) * *(double *)(param_1 + 0x99)) -
              *(double *)(param_1 + 0x7d) * *(double *)(param_1 + 0x9b)) *
              *(double *)(param_1 + 0x85);
      dVar5 = (((*(double *)(param_1 + 0x7f) * ((double)fVar1 + local_2c) +
                 *(double *)(param_1 + 0x81) * *(double *)(param_1 + 0x95) +
                *(double *)(param_1 + 0x83) * *(double *)(param_1 + 0x97)) -
               *(double *)(param_1 + 0x7b) * *(double *)(param_1 + 0x9d)) -
              *(double *)(param_1 + 0x7d) * *(double *)(param_1 + 0x9f)) *
              *(double *)(param_1 + 0x85);
      dVar4 = (((dVar6 * *(double *)(param_1 + 0xa7) +
                 *(double *)(param_1 + 0xa9) * *(double *)(param_1 + 0xb9) +
                *(double *)(param_1 + 0xab) * *(double *)(param_1 + 0xbb)) -
               *(double *)(param_1 + 0xa3) * *(double *)(param_1 + 0xc1)) -
              *(double *)(param_1 + 0xa5) * *(double *)(param_1 + 0xc3)) *
              *(double *)(param_1 + 0xad);
      dVar3 = (((*(double *)(param_1 + 0xa7) * dVar5 +
                 *(double *)(param_1 + 0xa9) * *(double *)(param_1 + 0xbd) +
                *(double *)(param_1 + 0xab) * *(double *)(param_1 + 0xbf)) -
               *(double *)(param_1 + 0xa3) * *(double *)(param_1 + 0xc5)) -
              *(double *)(param_1 + 0xa5) * *(double *)(param_1 + 199)) *
              *(double *)(param_1 + 0xad);
      *(undefined8 *)(param_1 + 0x93) = *(undefined8 *)(param_1 + 0x91);
      *(double *)(param_1 + 0x91) = dVar2;
      *(undefined8 *)(param_1 + 0x9b) = *(undefined8 *)(param_1 + 0x99);
      *(double *)(param_1 + 0x99) = dVar6;
      *(undefined8 *)(param_1 + 0x97) = *(undefined8 *)(param_1 + 0x95);
      *(double *)(param_1 + 0x95) = (double)fVar1 + local_2c;
      *(undefined8 *)(param_1 + 0x9f) = *(undefined8 *)(param_1 + 0x9d);
      *(double *)(param_1 + 0x9d) = dVar5;
      *(undefined8 *)(param_1 + 0xbb) = *(undefined8 *)(param_1 + 0xb9);
      *(double *)(param_1 + 0xb9) = dVar6;
      *(undefined8 *)(param_1 + 0xc3) = *(undefined8 *)(param_1 + 0xc1);
      *(double *)(param_1 + 0xc1) = dVar4;
      *(undefined8 *)(param_1 + 0xbf) = *(undefined8 *)(param_1 + 0xbd);
      *(double *)(param_1 + 0xbd) = dVar5;
      *(undefined8 *)(param_1 + 199) = *(undefined8 *)(param_1 + 0xc5);
      *(double *)(param_1 + 0xc5) = dVar3;
      (**(code **)(*param_1 + 0xcc))(param_1,&stack0x00000014,(float)dVar4);
      (**(code **)(*param_1 + 0xcc))(param_1,&stack0x00000018,(float)dVar3);
      local_20 = local_20 + 1;
    } while (param_2 != local_20);
  }
  return;
}

