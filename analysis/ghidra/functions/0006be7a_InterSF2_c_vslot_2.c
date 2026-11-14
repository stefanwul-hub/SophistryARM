/* 0006be7a InterSF2_c_vslot_2 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void InterSF2_c_vslot_2(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  undefined4 local_3c;
  int local_38;
  void *local_34;
  uint local_30;
  uint local_2c;
  int local_28;
  int local_24;
  int local_20 [4];
  
  local_3c = 0;
  local_38 = 0;
  local_34 = (void *)0x0;
  local_30 = 0;
  iVar3 = param_1 + 4;
  _fseek(*(FILE **)(param_1 + 0xc),8,1);
  FUN_00009b22(iVar3,&local_2c);
  FUN_00009b22(iVar3,&local_2c);
  FUN_00009b22(iVar3,local_20);
  do {
    iVar1 = FUN_00009b22(iVar3,&local_24);
    if (iVar1 != 4) {
      FUN_0006b0a0(param_1,&local_3c);
      if (*(int *)(param_1 + 0x298) != 0) {
        local_4c = (int)*(float *)(local_38 + 0x68);
        local_48 = (int)*(float *)(local_38 + 0x70);
        local_44 = (int)(*(float *)(local_38 + 0x74) * 1000.0);
        local_40 = (int)*(float *)(local_38 + 0x78);
        (**(code **)(**(int **)(param_1 + 0x298) + 0x2d4))
                  (*(int **)(param_1 + 0x298),*(undefined4 *)(param_1 + 0x2a0),&local_4c);
      }
      if (local_38 != 0) {
        for (iVar3 = local_38 + *(int *)(local_38 + -4) * 0x7c; local_38 != iVar3;
            iVar3 = iVar3 + -0x7c) {
        }
        operator_delete__((void *)(local_38 + -4));
      }
      if (local_34 != (void *)0x0) {
        _free(local_34);
      }
      return;
    }
    if (local_24 == 0x61746470) {
LAB_0006c01e:
      FUN_0006b9e0(param_1,local_20[0] + -4,&local_3c);
    }
    else if (local_24 < 0x61746471) {
      if ((local_24 == 0x494e464f) || (local_24 == 0x4f464e49)) {
        FUN_0006b964(param_1,local_20[0] + -4);
      }
      else {
LAB_0006bf1e:
        _fseek(*(FILE **)(param_1 + 0xc),local_20[0] + -4,1);
      }
    }
    else {
      if (local_24 == 0x70647461) goto LAB_0006c01e;
      if ((local_24 != 0x73647461) && (local_24 != 0x61746473)) goto LAB_0006bf1e;
      for (iVar1 = local_20[0] + -4; 0 < iVar1; iVar1 = (iVar1 - iVar2) - (local_30 + 4)) {
        while( true ) {
          iVar2 = FUN_00009b22(iVar3,&local_28);
          if ((local_28 == 0x6c706d73) || (local_28 == 0x736d706c)) break;
          FUN_00009b22(iVar3,&local_2c);
          if ((local_2c & 1) != 0) {
            local_2c = local_2c + 1;
          }
          _fseek(*(FILE **)(param_1 + 0xc),local_2c,1);
          iVar1 = (iVar1 - iVar2) - (local_2c + 4);
          if (iVar1 < 1) goto LAB_0006bf3b;
        }
        FUN_00009b22(iVar3,&local_30);
        if ((local_30 & 1) != 0) {
          local_30 = local_30 + 1;
        }
        local_34 = _malloc(local_30 + 0x41);
        FUN_00009b6e(iVar3,local_34,local_30);
      }
    }
LAB_0006bf3b:
    _fseek(*(FILE **)(param_1 + 0xc),4,1);
    FUN_00009b22(iVar3,local_20);
  } while( true );
}

