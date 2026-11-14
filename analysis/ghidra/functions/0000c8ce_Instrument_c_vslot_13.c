/* 0000c8ce Instrument_c_vslot_13 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Instrument_c_vslot_13(int *param_1)

{
  char cVar1;
  int *piVar2;
  longdouble lVar3;
  longdouble lVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double local_44;
  int local_3c;
  int local_38;
  int local_24;
  int local_20 [4];
  
  cVar1 = (**(code **)(*param_1 + 0x30))(param_1,local_20,&local_24);
  if (cVar1 != '\0') {
    local_38 = 4;
    piVar2 = param_1;
    do {
      if (((char)piVar2[0x68] != '\0') && (dVar7 = *(double *)(param_1 + 0x60), 0.0 < dVar7)) {
        dVar8 = (double)local_20[0] * dVar7;
        for (dVar7 = (double)local_24 * dVar7; 1.0 < dVar7; dVar7 = dVar7 - 1.0) {
        }
        lVar3 = (longdouble)_fmod(dVar8,0);
        dVar6 = (double)lVar3;
        dVar5 = dVar6;
        if (0.5 < dVar6) {
          dVar5 = 1.0 - dVar6;
        }
        if (0.01 < dVar5) {
          lVar3 = (longdouble)FUN_00015302(0,0x3ff00000,dVar5);
          dVar8 = *(double *)(param_1 + 0x58);
          local_44 = ABS(dVar8 - dVar7);
          if (0 < (int)lVar3 + 1) {
            local_3c = 1;
            do {
              lVar4 = (longdouble)_fmod(dVar7 + (double)local_3c * dVar6,0);
              dVar5 = ABS((double)lVar4 - dVar8);
              if (dVar5 < local_44) {
                dVar7 = (double)lVar4;
                local_44 = dVar5;
              }
              lVar4 = (longdouble)_fmod(dVar7 - (double)local_3c * dVar6,0);
              dVar5 = ABS((double)lVar4 - dVar8);
              if (dVar5 < local_44) {
                dVar7 = (double)lVar4;
                local_44 = dVar5;
              }
              local_3c = local_3c + 1;
            } while (local_3c <= (int)lVar3 + 1);
          }
        }
        else {
          dVar6 = *(double *)(param_1 + 0x58);
          if (dVar8 * 0.5 < ABS(dVar7 - dVar6)) {
            for (; dVar7 < dVar8 * -0.5 + dVar6; dVar7 = dVar7 + dVar8) {
            }
            dVar6 = dVar8 * 0.5 + dVar6;
            for (; (dVar6 < dVar7 && (dVar7 = dVar7 - dVar8, dVar6 < dVar7)); dVar7 = dVar7 - dVar8)
            {
            }
          }
        }
        for (; (dVar7 < 0.0 && (dVar7 = dVar7 + 1.0, dVar7 < 0.0)); dVar7 = dVar7 + 1.0) {
        }
        for (; 1.0 < dVar7; dVar7 = dVar7 - 1.0) {
        }
        *(double *)(param_1 + 0x58) = dVar7;
      }
      piVar2 = (int *)((int)piVar2 + 1);
      param_1 = param_1 + 2;
      local_38 = local_38 + -1;
    } while (local_38 != 0);
  }
  return;
}

