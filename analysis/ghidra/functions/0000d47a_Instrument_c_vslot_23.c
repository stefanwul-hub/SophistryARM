/* 0000d47a Instrument_c_vslot_23 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Instrument_c_vslot_23(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  
  fVar3 = (float)param_4 / 127.0;
  fVar4 = (fVar3 + fVar3) - 1.0;
  switch(param_3) {
  case 1:
    if ((char)param_1[0x3b0] != '\0') {
      param_1[0x6b7] = (int)fVar3;
    }
    break;
  case 2:
    param_1[0x6b8] = (int)fVar3;
    break;
  case 4:
    param_1[0x6b9] = (int)fVar3;
    break;
  case 6:
    if (((char)param_1[0x6d5] != '\0') && (param_1[0x6d6] == 0)) {
      Envelope_c_vslot_9(param_1[1] + 0x5a4,0,0xc,param_4);
      iVar1 = param_1[1];
      iVar2 = *(int *)(iVar1 + 0x6c4);
      if (iVar2 == 0) {
        return;
      }
      FUN_00012222(iVar2,0,0x19,0xffffffff);
                    /* WARNING: Could not recover jumptable at 0x00012bb3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*(int *)(iVar1 + 0x5a4) + 0x78))();
      return;
    }
    break;
  case 7:
    param_1[0x4c] = (int)(fVar3 - 1.0);
    break;
  case 10:
    if (param_4 == 0x40) {
      param_1[0x4d] = 0;
    }
    else {
      param_1[0x4d] = (int)fVar4;
    }
    break;
  case 0xb:
    param_1[0x6ba] = (int)fVar3;
    break;
  case 0x10:
    param_1[0x4e] = (int)fVar4;
    break;
  case 0x11:
    param_1[0x4f] = (int)fVar4;
    break;
  case 0x12:
    param_1[0x50] = (int)fVar4;
    break;
  case 0x13:
    param_1[0x51] = (int)fVar4;
    break;
  case 0x40:
    if (*(char *)((int)param_1 + 0xec3) != '\0') {
                    /* WARNING: Could not recover jumptable at 0x0000d778. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_1 + 0x58))();
      return;
    }
    break;
  case 100:
    if ((char)param_1[0x6d5] != '\0') {
code_r0x0000d670:
      param_1[0x6d6] = param_4;
      *(undefined1 *)(param_1 + 0x6d5) = 0;
      return;
    }
    goto code_r0x0000d787;
  case 0x65:
    if ((char)param_1[0x6d5] != '\0') {
      param_4 = param_4 << 7;
      goto code_r0x0000d670;
    }
    param_4 = param_4 << 7;
code_r0x0000d787:
    param_1[0x6d6] = param_1[0x6d6] + param_4;
    *(undefined1 *)(param_1 + 0x6d5) = 1;
  }
  return;
}

