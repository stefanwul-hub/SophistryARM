/* 0001beb0 Synth_vslot_177 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 Synth_vslot_177(int *param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int local_178;
  int local_170;
  char local_16c [320];
  undefined4 local_2c;
  uint local_28;
  int local_24;
  int local_20 [4];
  
  piVar3 = (int *)operator_new(0x10);
  FUN_0002df20(piVar3,param_3,param_2);
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  bVar1 = true;
  local_178 = 0;
  do {
    cVar2 = FUN_0002e0fc(piVar3,local_178,&local_24);
    if ((((cVar2 == '\0') || (cVar2 = FUN_0002e13a(piVar3,local_178 + 1,&local_28), cVar2 == '\0'))
        || (cVar2 = FUN_0002e13a(piVar3,local_178 + 2,&local_2c), cVar2 == '\0')) ||
       ((cVar2 = FUN_0002e0b2(piVar3,local_178,local_20), cVar2 == '\0' || (!bVar1)))) {
      cVar2 = *(char *)((int)param_1 + 0xcfd2);
      if (cVar2 == '\0') {
        *(undefined1 *)((int)param_1 + 0xcfd2) = 1;
        *(undefined1 *)(param_1 + 0x33f3) = 0;
        if (*(char *)((int)param_1 + 0xcfd1) != '\0') {
          do {
            FUN_0002e340(param_1 + 0xe28,0x1e);
          } while (*(char *)((int)param_1 + 0xcfd1) != '\0');
        }
      }
      piVar6 = param_1 + 0xf3;
      iVar4 = Envelope_c_vslot_12(piVar6,0,1);
      param_1[0x33f8] = iVar4;
      (**(code **)(*param_1 + 0x318))(param_1,iVar4);
      if (param_1[0xe3c] == 0) {
        iVar4 = Envelope_c_vslot_12(param_1 + 0x169,param_1[0x33f8],1);
        param_1[7] = iVar4;
      }
      else {
        iVar4 = Envelope_c_vslot_12(piVar6,0,0x1a);
        param_1[7] = iVar4;
        iVar4 = Envelope_c_vslot_12(piVar6,0,0x1b);
        param_1[0x2c] = iVar4;
        Envelope_c_vslot_18(piVar6,0,0x1e,&DAT_000fbf80);
        FUN_0001a3ce(param_1,&DAT_000fbf80);
      }
      param_1[0xed1] = 0;
      if (0 < param_1[0x33ec]) {
        local_170 = 0;
        do {
          iVar4 = param_1[0xed1];
          iVar5 = Envelope_c_vslot_12(param_1 + 0x169,local_170,5);
          param_1[0xed1] = iVar4 + iVar5;
          local_170 = local_170 + 1;
        } while (local_170 < param_1[0x33ec]);
      }
      if (cVar2 == '\0') {
        *(undefined1 *)((int)param_1 + 0xcfd2) = 0;
      }
      (**(code **)(*param_1 + 0x270))(param_1);
      (**(code **)(*piVar3 + 4))(piVar3);
      (**(code **)(*param_1 + 0x354))(param_1,0);
      return param_3;
    }
    if (local_24 == 0x50524f47) {
      (**(code **)(*param_1 + 0x2c8))(param_1,local_2c,local_20[0] + 0xc,local_28 - 0xc);
      bVar1 = true;
    }
    else if (local_24 < 0x50524f48) {
      if (local_24 == 0x45435331) {
        piVar6 = (int *)param_1[0x33a5];
        if (piVar6 == (int *)0x0) {
          return 0;
        }
LAB_0001c10a:
        if (param_4 == '\0') goto LAB_0001c0d6;
        bVar1 = true;
      }
      else if (local_24 == 0x4d494431) {
        if (((param_1[0xdaf] == 0) || (piVar6 = (int *)param_1[0x33a7], piVar6 == (int *)0x0)) ||
           (param_4 != '\0')) {
LAB_0001c088:
          bVar1 = true;
        }
        else {
          if ((char)param_1[0x33f4] == '\0') goto LAB_0001c0d6;
          bVar1 = true;
        }
      }
      else {
LAB_0001bf2e:
        _sprintf(local_16c,"format mismatch %c%c%c%c Order %ld Size %ld",local_24 >> 0x18,
                 (local_24 << 8) >> 0x18,(int)(char)((uint)local_24 >> 8),(int)(char)local_24,
                 local_2c,local_28);
        FUN_0002e53a(param_1 + 0xe28,"Bank Load Error",local_16c);
        bVar1 = false;
      }
    }
    else if (local_24 == 0x53594731) {
      piVar6 = (int *)param_1[0x1453];
      if (piVar6 == (int *)0x0) {
        return 0;
      }
LAB_0001c0d6:
      (**(code **)(*piVar6 + 0x10))(piVar6,local_20[0],local_28,local_2c);
      bVar1 = true;
    }
    else {
      if (local_24 == 0x54554e30) {
        piVar6 = (int *)param_1[0x33a6];
        if (piVar6 == (int *)0x0) {
          return 0;
        }
        goto LAB_0001c10a;
      }
      if (local_24 != 0x53594730) goto LAB_0001bf2e;
      piVar6 = (int *)param_1[0x144c];
      if (piVar6 == (int *)0x0) {
        return 0;
      }
      if (param_4 != '\0') goto LAB_0001c088;
      (**(code **)(*piVar6 + 0x10))(piVar6,local_20[0],local_28,0);
      bVar1 = true;
    }
    local_178 = local_178 + (local_28 >> 2);
  } while( true );
}

