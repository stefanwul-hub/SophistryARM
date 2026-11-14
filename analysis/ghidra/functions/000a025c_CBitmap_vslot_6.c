/* 000a025c CBitmap_vslot_6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CBitmap_vslot_6(int ****param_1,int ***param_2,int *param_3,int *param_4,byte param_5)

{
  int **ppiVar1;
  int iVar2;
  int ****ppppiVar3;
  int **local_180;
  int ***local_17c;
  int *local_178;
  float local_174;
  float local_170;
  float local_16c;
  int **local_168;
  float local_164;
  float local_160;
  float local_15c;
  int local_140;
  int *local_134;
  int *local_130;
  int *local_12c;
  int ***local_11c;
  int *local_104;
  int *local_100;
  int *local_fc;
  int *local_f8;
  int local_f4;
  int local_f0;
  int local_e8;
  int **local_e4;
  int *local_e0;
  int **local_dc;
  int **local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  int ***local_bc;
  int *local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  int **local_9c;
  float local_98;
  float local_94;
  float local_90;
  int ***local_8c;
  int *local_88;
  float local_84;
  float local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int **local_6c;
  float local_68;
  float local_64;
  float local_60;
  int *local_5c;
  float local_58;
  float local_54;
  float local_50;
  int ***local_4c;
  int *local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
  ppppiVar3 = &local_17c;
  if (DAT_000fd508 == (code *)0x0) {
    if ((param_1[7] != (int ***)0x0) || (param_1[9] != (int ***)0x0)) {
      local_178 = (int *)0x0;
      local_17c = param_2;
      local_180 = (int **)0xa0612;
      local_17c = (int ***)FUN_0009e3a2();
      if (local_17c != (int ***)0x0) {
        local_dc = (int **)local_17c;
        if (param_5 != 0xff) {
          local_178 = (int *)((float)param_5 / 255.0);
          local_180 = (int **)0xa064a;
          _CGContextSetAlpha();
        }
        local_178 = (int *)0x0;
        local_17c = (int ***)param_1;
        local_180 = (int **)0xa065a;
        local_d8 = (int **)(*(code *)(*param_1)[7])();
        if ((int ***)local_d8 != (int ***)0x0) {
          local_f8 = (int *)param_2[4];
          local_c0 = (float)((*param_3 - *param_4) + (int)local_f8);
          ppiVar1 = param_2[5];
          local_c4 = (float)(-((int)param_1[4] - param_4[1]) - ((int)ppiVar1 + param_3[1]));
          local_c8 = (float)(int)param_1[3];
          local_cc = (float)(int)param_1[4];
          local_134 = (int *)param_2[0x15];
          local_100 = (int *)param_2[0x16];
          local_104 = (int *)param_2[0x17];
          local_7c = -(int)local_f8 + (int)param_2[0x14];
          local_140 = -(int)local_f8 + (int)local_100;
          local_78 = -(int)ppiVar1 + (int)local_134;
          local_70 = -(int)ppiVar1 + (int)local_104;
          local_170 = (float)(local_140 - local_7c);
          local_16c = (float)(local_70 - local_78);
          local_174 = (float)(-(local_70 - local_78) - ((int)ppiVar1 + local_78));
          local_178 = (int *)(float)((int)local_f8 + local_7c);
          local_17c = (int ***)local_dc;
          local_180 = (int **)0xa0792;
          local_74 = local_140;
          local_3c = (float)local_178;
          local_38 = local_174;
          local_34 = local_170;
          local_30 = local_16c;
          _CGContextClipToRect();
          local_178 = (int *)(float)(*param_3 + (int)param_2[4]);
          iVar2 = param_3[3] - param_3[1];
          local_174 = (float)(-iVar2 - (param_3[1] + (int)param_2[5]));
          local_170 = (float)(param_3[2] - *param_3);
          local_16c = (float)iVar2;
          local_17c = (int ***)local_dc;
          local_180 = (int **)0xa0806;
          local_2c = (float)local_178;
          local_28 = local_174;
          local_24 = local_170;
          local_20 = local_16c;
          _CGContextClipToRect();
          local_a0 = local_cc;
          local_a4 = local_c8;
          local_a8 = local_c4;
          local_ac = local_c0;
          local_168 = local_d8;
          local_178 = (int *)local_c0;
          local_174 = local_c4;
          local_170 = local_c8;
          local_16c = local_cc;
          local_17c = (int ***)local_dc;
          local_180 = (int **)0xa0886;
          _CGContextDrawImage();
          local_17c = (int ***)local_d8;
          local_180 = (int **)0xa0894;
          _CGImageRelease();
        }
        local_17c = (int ***)local_dc;
        local_180 = (int **)0xa08a2;
        _CGContextRestoreGState();
        *(undefined1 *)(param_2 + 0x19) = 1;
        return;
      }
    }
  }
  else if ((param_1[7] != (int ***)0x0) || (param_1[9] != (int ***)0x0)) {
    local_178 = (int *)0x0;
    local_17c = param_2;
    local_180 = (int **)0xa02a0;
    local_17c = (int ***)FUN_0009e3a2();
    if (local_17c != (int ***)0x0) {
      local_e4 = (int **)local_17c;
      if (param_5 != 0xff) {
        local_178 = (int *)((float)param_5 / 255.0);
        local_180 = (int **)0xa02d8;
        _CGContextSetAlpha();
      }
      local_178 = (int *)0x0;
      local_17c = (int ***)param_1;
      local_180 = (int **)0xa02e8;
      local_e0 = (int *)(*(code *)(*param_1)[7])();
      if ((int **)local_e0 != (int **)0x0) {
        local_fc = (int *)param_2[0x15];
        local_130 = (int *)param_2[0x16];
        local_7c = -(int)param_2[4] + (int)param_2[0x14];
        local_74 = -(int)param_2[4] + (int)local_130;
        local_e8 = (int)local_fc + -(int)param_2[5];
        local_70 = -(int)param_2[5] + (int)param_2[0x17];
        local_170 = (float)(local_74 - local_7c);
        local_f4 = param_4[1];
        local_174 = (float)((local_e8 - param_3[1]) + local_f4);
        local_f0 = *param_4;
        local_178 = (int *)(float)((local_7c - *param_3) + local_f0);
        local_15c = (float)(param_3[3] - param_3[1]);
        local_160 = (float)(param_3[2] - *param_3);
        local_164 = (float)local_f4;
        local_168 = (int **)(float)local_f0;
        local_16c = (float)(local_70 - local_e8);
        local_17c = (int ***)&local_bc;
        local_180 = (int **)0xa0426;
        local_78 = local_e8;
        local_6c = local_168;
        local_68 = local_164;
        local_64 = local_160;
        local_60 = local_15c;
        local_5c = local_178;
        local_58 = local_174;
        local_54 = local_170;
        local_50 = local_16c;
        _CGRectIntersection();
        ppppiVar3 = (int ****)&local_180;
        local_8c = local_bc;
        local_88 = local_b8;
        local_84 = local_b4;
        local_80 = local_b0;
        local_d4 = local_b0;
        local_d0 = local_b4;
        if ((local_b4 != 0.0) && (local_b0 != 0.0)) {
          local_48 = local_b8;
          local_4c = local_bc;
          local_40 = local_b0;
          local_44 = local_b4;
          local_17c = local_bc;
          local_178 = local_b8;
          local_174 = local_b4;
          local_170 = local_b0;
          local_180 = (int **)local_e0;
          local_11c = local_bc;
          local_12c = local_b8;
          ppiVar1 = (int **)(*DAT_000fd508)();
          if (ppiVar1 != (int **)0x0) {
            local_9c = (int **)((((float)local_11c + (float)(int)param_2[4]) - (float)*param_4) +
                               (float)*param_3);
            local_98 = (((float)local_12c + (float)(int)param_2[5]) - (float)param_4[1]) +
                       (float)param_3[1];
            local_94 = local_d0;
            local_90 = local_d4;
            local_178 = (int *)0xbf800000;
            local_17c = (int ***)0x3f800000;
            local_180 = local_e4;
            _CGContextScaleCTM();
            local_17c = &local_9c;
            local_180 = local_e4;
            local_178 = (int *)ppiVar1;
            _HIViewDrawCGImage();
            local_180 = ppiVar1;
            _CGImageRelease();
          }
        }
        local_180 = (int **)local_e0;
        _CGImageRelease();
      }
      *ppppiVar3 = (int ***)local_e4;
      ((int *)ppppiVar3)[-1] = 0xa04b3;
      _CGContextRestoreGState();
      *(undefined1 *)(param_2 + 0x19) = 1;
    }
  }
  return;
}

