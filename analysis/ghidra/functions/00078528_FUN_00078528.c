/* 00078528 FUN_00078528 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00078528(int *param_1,int param_2,float *param_3,float *param_4)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float in_XMM4_Da;
  float *local_24;
  int local_20;
  
  if (((char)param_1[0x57] != '\0') && (param_1[0x79] = 0, 0 < param_2)) {
    local_24 = param_3;
    local_20 = 0;
    do {
      uVar1 = param_1[0x79];
      param_1[0x79] = uVar1 + 1;
      if ((uVar1 & 7) == 0) {
        fVar3 = *(float *)param_1[0x10bf];
        param_1[0x10bf] = (int)((float *)param_1[0x10bf] + 1);
        if ((1e-06 <= fVar3) || (NAN(fVar3))) {
          if (fVar3 <= 1.0) {
            fVar3 = fVar3 * 8.0;
          }
          else {
            fVar3 = 8.0;
          }
        }
        else {
          fVar3 = 8e-06;
        }
        fVar3 = fVar3 - 4.0;
        fVar3 = fVar3 * fVar3 * fVar3 * 0.00083790737 + fVar3 * fVar3 * 0.01550458 +
                fVar3 * 0.17380469 + 1.0;
        in_XMM4_Da = fVar3 * fVar3 * fVar3 * fVar3 * 0.0625;
        fVar3 = in_XMM4_Da * -0.9 + 1.0;
        fVar3 = fVar3 * fVar3 * 16.0;
        param_1[0x10ce] = (int)fVar3;
        fVar3 = fVar3 * *(float *)param_1[0x10c1];
        param_1[0x10cc] = (int)fVar3;
        param_1[0x10c1] = (int)((float *)param_1[0x10c1] + 1);
        param_1[0x10cd] = (int)((fVar3 - (float)param_1[0x10c6]) * 0.125);
        fVar3 = (float)param_1[0x10c7] * 0.75 + (*(float *)param_1[0x10c2] + 1.0) * 0.25;
        param_1[0x10c7] = (int)fVar3;
        param_1[0x10c2] = (int)((float *)param_1[0x10c2] + 1);
        if ((1e-05 <= fVar3) || (NAN(fVar3))) {
          fVar3 = (float)(~-(uint)(fVar3 <= 1.99999) & (uint)1.99999 |
                         (uint)fVar3 & -(uint)(fVar3 <= 1.99999));
        }
        else {
          fVar3 = 1e-05;
        }
        param_1[0x10c7] = (int)fVar3;
      }
      param_1[0x10c6] = (int)((float)param_1[0x10c6] + (float)param_1[0x10cd]);
      fVar2 = (*local_24 - (float)param_1[0x82]) * in_XMM4_Da + (float)param_1[0x82];
      param_1[0x82] = (int)fVar2;
      local_24 = local_24 + 1;
      fVar3 = (*param_4 - (float)param_1[0x8a]) * in_XMM4_Da + (float)param_1[0x8a];
      param_1[0x8a] = (int)fVar3;
      param_4 = param_4 + 1;
      fVar2 = (fVar2 - (float)param_1[0x83]) * in_XMM4_Da + (float)param_1[0x83];
      param_1[0x83] = (int)fVar2;
      fVar3 = (fVar3 - (float)param_1[0x8b]) * in_XMM4_Da + (float)param_1[0x8b];
      param_1[0x8b] = (int)fVar3;
      fVar2 = (fVar2 - (float)param_1[0x84]) * in_XMM4_Da + (float)param_1[0x84];
      param_1[0x84] = (int)fVar2;
      fVar3 = (fVar3 - (float)param_1[0x8c]) * in_XMM4_Da + (float)param_1[0x8c];
      param_1[0x8c] = (int)fVar3;
      fVar2 = (fVar2 - (float)param_1[0x85]) * in_XMM4_Da + (float)param_1[0x85];
      param_1[0x85] = (int)fVar2;
      fVar3 = (fVar3 - (float)param_1[0x8d]) * in_XMM4_Da + (float)param_1[0x8d];
      param_1[0x8d] = (int)fVar3;
      fVar2 = fVar2 - (float)param_1[0x86];
      param_1[0x86] = (int)((float)param_1[0x86] + in_XMM4_Da * fVar2);
      fVar3 = fVar3 - (float)param_1[0x8e];
      param_1[0x8e] = (int)((float)param_1[0x8e] + in_XMM4_Da * fVar3);
      fVar2 = fVar2 - (float)param_1[0x87];
      param_1[0x87] = (int)((float)param_1[0x87] + in_XMM4_Da * fVar2);
      fVar3 = fVar3 - (float)param_1[0x8f];
      param_1[0x8f] = (int)((float)param_1[0x8f] + in_XMM4_Da * fVar3);
      fVar2 = fVar2 - (float)param_1[0x88];
      param_1[0x88] = (int)((float)param_1[0x88] + in_XMM4_Da * fVar2);
      fVar3 = fVar3 - (float)param_1[0x90];
      param_1[0x90] = (int)((float)param_1[0x90] + in_XMM4_Da * fVar3);
      fVar2 = (fVar2 - (float)param_1[0x89]) * in_XMM4_Da + (float)param_1[0x89];
      param_1[0x89] = (int)fVar2;
      param_1[0x91] = (int)((float)param_1[0x91] + (fVar3 - (float)param_1[0x91]) * in_XMM4_Da);
      (**(code **)(*param_1 + 0xcc))
                (param_1,param_1 + 0x80,
                 fVar2 * (float)param_1[0x10c6] * (2.0 - (float)param_1[0x10c7]));
      (**(code **)(*param_1 + 0xcc))
                (param_1,param_1 + 0x81,
                 (float)param_1[0x91] * (float)param_1[0x10c6] * (float)param_1[0x10c7]);
      local_20 = local_20 + 1;
    } while (param_2 != local_20);
  }
  return;
}

