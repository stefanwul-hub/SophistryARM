/* 0001d93a Synth_vslot_196 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Synth_vslot_196(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  char unaff_DI;
  char local_528 [320];
  undefined1 local_3e8 [320];
  undefined1 local_2a8 [320];
  char local_168 [320];
  int local_28;
  int local_24;
  int *local_20 [4];
  
  if (0 < param_1[0xedb]) {
    local_2a8[0] = 0;
    local_528[0] = '\0';
    local_3e8[0] = 0;
    (**(code **)(*param_1 + 0x50))(param_1,param_2,local_3e8);
    FUN_0001cb52(param_1,param_2,local_20,&local_28,&local_24);
    if (param_1[0x22af] != 0) {
      iVar2 = 0;
      if (-1 < param_2) {
        iVar2 = param_2;
      }
      iVar1 = param_1[0x2692] + -1;
      if (iVar2 <= param_1[0x2692] + -1) {
        iVar1 = iVar2;
      }
      unaff_DI = *(char *)(iVar1 * 0x20 + 8 + param_1[0x22af]);
    }
    if (((local_20[0] != (int *)0x0) && (-1 < local_28)) && (unaff_DI != '\0')) {
      iVar2 = FUN_0002e1c0(param_1 + 0xe28);
      param_1[0xedf] = iVar2;
      param_1[0xede] = param_2;
      local_24 = 0;
      if (0 < param_1[0x33ec]) {
        do {
          (**(code **)(*local_20[0] + 0x50))(local_20[0],local_24,local_28,local_528,0x17);
          if (param_2 == param_1[0xee0]) {
            _strcpy(local_168,local_528);
          }
          else {
            (**(code **)(*local_20[0] + 0x4c))(local_20[0],local_24,local_28,local_2a8);
            if (param_1[0xedd] == 2) {
              _sprintf(local_168,"%s %s",local_528,local_2a8);
            }
            else if (param_1[0xedd] == 3) {
              _sprintf(local_168,"%s %s %s",local_3e8,local_528,local_2a8);
            }
            else {
              _strcpy(local_168,local_528);
            }
          }
          Envelope_c_vslot_17(param_1 + 0x169,local_24,0x10,local_168);
          (**(code **)(*param_1 + 0x34c))
                    (param_1,param_1[0xedb] * local_24 + param_1[0xeda],0 < param_1[0xecc]);
          local_24 = local_24 + 1;
        } while (local_24 < param_1[0x33ec]);
      }
    }
  }
  return;
}

