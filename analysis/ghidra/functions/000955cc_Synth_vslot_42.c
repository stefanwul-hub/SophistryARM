/* 000955cc Synth_vslot_42 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Synth_vslot_42(undefined4 param_1,float param_2,char *param_3,size_t param_4)

{
  bool bVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  longdouble lVar6;
  longdouble lVar7;
  double dVar8;
  double local_54;
  double local_4c;
  char local_20 [16];
  
  local_54 = (double)param_2;
  if ((0.0 <= local_54) || (NAN(local_54))) {
    if (99999999.0 < local_54) {
      return;
    }
    bVar1 = false;
    uVar5 = 2;
  }
  else {
    local_54 = -local_54;
    if (9999999.0 < local_54) {
      return;
    }
    bVar1 = true;
    uVar5 = 3;
  }
  local_20[3] = 0;
  local_20[2] = 0x2e;
  lVar6 = (longdouble)_floor(local_54);
  lVar7 = (longdouble)_fmod((double)lVar6,0);
  local_20[1] = (char)(int)lVar7 + '0';
  dVar8 = (double)lVar6 / 10.0;
  if ((dVar8 < 1.0) || (7 < uVar5)) {
    pcVar3 = local_20;
  }
  else {
    pcVar3 = local_20;
    do {
      lVar6 = (longdouble)_fmod(dVar8,0);
      *pcVar3 = (char)(int)lVar6 + '0';
      pcVar3 = pcVar3 + -1;
      dVar8 = dVar8 / 10.0;
      uVar5 = uVar5 + 1;
      if (dVar8 < 1.0) break;
    } while (uVar5 != 8);
  }
  if (bVar1) {
    *pcVar3 = '-';
    pcVar3 = pcVar3 + -1;
  }
  _strncpy(param_3,pcVar3 + 1,param_4);
  pcVar3 = param_3 + param_4;
  *pcVar3 = '\0';
  if ((int)uVar5 < 8) {
    local_20[3] = 0;
    lVar6 = (longdouble)_fmod(local_54,0,0x3ff00000);
    lVar7 = (longdouble)_pow(0,0x40240000,(double)(int)(8 - uVar5));
    local_4c = (double)lVar6 * (double)lVar7;
    pcVar2 = local_20 + 2;
    do {
      while (pcVar4 = pcVar2, local_4c <= 0.0) {
        *pcVar4 = '0';
        uVar5 = uVar5 + 1;
        pcVar2 = pcVar4 + -1;
        if (uVar5 == 8) {
          _strncat(param_3,pcVar4,param_4);
          *pcVar3 = '\0';
          return;
        }
      }
      lVar6 = (longdouble)_fmod(local_4c,0);
      *pcVar4 = (char)(int)lVar6 + '0';
      local_4c = local_4c / 10.0;
      uVar5 = uVar5 + 1;
      pcVar2 = pcVar4 + -1;
    } while (uVar5 != 8);
    _strncat(param_3,pcVar4,param_4);
    *pcVar3 = '\0';
    return;
  }
  return;
}

