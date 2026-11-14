/* 0007818a FUN_0007818a */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0007818a(int *param_1,int param_2,float *param_3)

{
  uint uVar1;
  float fVar2;
  float in_XMM4_Da;
  int local_20;
  
  if (((char)param_1[0x57] != '\0') && (param_1[0x79] = 0, 0 < param_2)) {
    local_20 = 0;
    do {
      uVar1 = param_1[0x79];
      param_1[0x79] = uVar1 + 1;
      if ((uVar1 & 7) == 0) {
        fVar2 = *(float *)param_1[0x10bf];
        param_1[0x10bf] = (int)((float *)param_1[0x10bf] + 1);
        if ((1e-06 <= fVar2) || (NAN(fVar2))) {
          if (fVar2 <= 1.0) {
            fVar2 = fVar2 * 8.0;
          }
          else {
            fVar2 = 8.0;
          }
        }
        else {
          fVar2 = 8e-06;
        }
        fVar2 = fVar2 - 4.0;
        fVar2 = fVar2 * fVar2 * fVar2 * 0.00083790737 + fVar2 * fVar2 * 0.01550458 +
                fVar2 * 0.17380469 + 1.0;
        in_XMM4_Da = fVar2 * fVar2 * fVar2 * fVar2 * 0.0625;
        fVar2 = in_XMM4_Da * -0.9 + 1.0;
        fVar2 = fVar2 * fVar2 * 16.0;
        param_1[0x10ce] = (int)fVar2;
        fVar2 = fVar2 * *(float *)param_1[0x10c1];
        param_1[0x10cc] = (int)fVar2;
        param_1[0x10c1] = (int)((float *)param_1[0x10c1] + 1);
        param_1[0x10cd] = (int)((fVar2 - (float)param_1[0x10c6]) * 0.125);
        fVar2 = (float)param_1[0x10c7] * 0.75 + (*(float *)param_1[0x10c2] + 1.0) * 0.25;
        param_1[0x10c7] = (int)fVar2;
        param_1[0x10c2] = (int)((float *)param_1[0x10c2] + 1);
        if ((1e-05 <= fVar2) || (NAN(fVar2))) {
          fVar2 = (float)(~-(uint)(fVar2 <= 1.99999) & (uint)1.99999 |
                         (uint)fVar2 & -(uint)(fVar2 <= 1.99999));
        }
        else {
          fVar2 = 1e-05;
        }
        param_1[0x10c7] = (int)fVar2;
      }
      param_1[0x10c6] = (int)((float)param_1[0x10c6] + (float)param_1[0x10cd]);
      fVar2 = (*param_3 - (float)param_1[0x82]) * in_XMM4_Da + (float)param_1[0x82];
      param_1[0x82] = (int)fVar2;
      param_3 = param_3 + 1;
      fVar2 = (fVar2 - (float)param_1[0x83]) * in_XMM4_Da + (float)param_1[0x83];
      param_1[0x83] = (int)fVar2;
      fVar2 = (fVar2 - (float)param_1[0x84]) * in_XMM4_Da + (float)param_1[0x84];
      param_1[0x84] = (int)fVar2;
      fVar2 = (fVar2 - (float)param_1[0x85]) * in_XMM4_Da + (float)param_1[0x85];
      param_1[0x85] = (int)fVar2;
      fVar2 = fVar2 - (float)param_1[0x86];
      param_1[0x86] = (int)((float)param_1[0x86] + in_XMM4_Da * fVar2);
      fVar2 = fVar2 - (float)param_1[0x87];
      param_1[0x87] = (int)((float)param_1[0x87] + in_XMM4_Da * fVar2);
      fVar2 = fVar2 - (float)param_1[0x88];
      param_1[0x88] = (int)((float)param_1[0x88] + in_XMM4_Da * fVar2);
      fVar2 = (fVar2 - (float)param_1[0x89]) * in_XMM4_Da + (float)param_1[0x89];
      param_1[0x89] = (int)fVar2;
      (**(code **)(*param_1 + 0xcc))
                (param_1,param_1 + 0x80,
                 fVar2 * (float)param_1[0x10c6] * (2.0 - (float)param_1[0x10c7]));
      (**(code **)(*param_1 + 0xcc))
                (param_1,param_1 + 0x81,
                 (float)param_1[0x89] * (float)param_1[0x10c6] * (float)param_1[0x10c7]);
      local_20 = local_20 + 1;
    } while (param_2 != local_20);
  }
  return;
}

