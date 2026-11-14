/* 00019986 Synth_vslot_176 */

uint Synth_vslot_176(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  void *pvVar5;
  uint local_24;
  undefined4 *local_20;
  int local_18;
  int local_14;
  int local_10;
  
  if (1 < *(int *)(param_1 + 0x3b88)) {
    if (0 < *(int *)(param_1 + 0xcfb0)) {
      iVar2 = 0;
      do {
        Envelope_c_vslot_17(param_1 + 0x5a4,iVar2,0xe,iVar2 * 0x140 + 0x9bd5 + param_1);
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(param_1 + 0xcfb0));
      if (0 < *(int *)(param_1 + 0xcfb0)) {
        iVar2 = 0;
        do {
          FUN_00019748(param_1,iVar2,iVar2);
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(param_1 + 0xcfb0));
      }
    }
    piVar1 = *(int **)(param_1 + 0x5130);
    if ((piVar1 != (int *)0x0) &&
       (local_18 = (**(code **)(*piVar1 + 8))(piVar1,0), *(int *)(param_1 + 0x514c) != 0)) {
      if (*(int *)(param_1 + 0xcfb0) < 1) {
        piVar1 = *(int **)(Instrument_c_vslot_17 + param_1 + 4);
      }
      else {
        iVar2 = 0;
        do {
          iVar3 = (**(code **)(**(int **)(param_1 + 0x514c) + 8))(*(int **)(param_1 + 0x514c),iVar2)
          ;
          local_18 = local_18 + iVar3;
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(param_1 + 0xcfb0));
        piVar1 = *(int **)(Instrument_c_vslot_17 + param_1 + 4);
      }
      if (piVar1 != (int *)0x0) {
        iVar2 = (**(code **)(*piVar1 + 8))(piVar1,0);
        local_24 = iVar2 + local_18;
        if ((*(int *)(param_1 + 0x36bc) != 0) &&
           (piVar1 = *(int **)(param_1 + 0xce9c), piVar1 != (int *)0x0)) {
          iVar2 = (**(code **)(*piVar1 + 8))(piVar1,0);
          local_24 = local_24 + iVar2;
        }
        if (0 < *(int *)(param_1 + 0x9a4c)) {
          iVar2 = 0;
          do {
            iVar3 = FUN_0002e026(*(undefined4 *)(*(int *)(param_1 + 0xcea0) + iVar2 * 4));
            local_24 = iVar3 + 0xc + local_24;
            iVar2 = iVar2 + 1;
          } while (iVar2 < *(int *)(param_1 + 0x9a4c));
        }
        if (local_24 < 0x7d000) {
          iVar2 = param_1 + 0xd278;
          *param_2 = iVar2;
          iVar3 = (**(code **)(**(int **)(param_1 + 0x5130) + 0xc))
                            (*(int **)(param_1 + 0x5130),iVar2,0);
          iVar2 = iVar2 + iVar3;
          if (0 < *(int *)(param_1 + 0xcfb0)) {
            local_10 = 0;
            do {
              iVar3 = (**(code **)(**(int **)(param_1 + 0x514c) + 0xc))
                                (*(int **)(param_1 + 0x514c),iVar2,local_10);
              *(int *)(iVar2 + 8) = local_10;
              iVar2 = iVar2 + iVar3;
              local_10 = local_10 + 1;
            } while (local_10 < *(int *)(param_1 + 0xcfb0));
          }
          iVar3 = (**(code **)(**(int **)(Instrument_c_vslot_17 + param_1 + 4) + 0xc))
                            (*(int **)(Instrument_c_vslot_17 + param_1 + 4),iVar2,0);
          *(undefined4 *)(iVar2 + 8) = 0;
          local_20 = (undefined4 *)(iVar3 + iVar2);
          if ((*(int *)(param_1 + 0x36bc) != 0) &&
             (piVar1 = *(int **)(param_1 + 0xce9c), piVar1 != (int *)0x0)) {
            iVar2 = (**(code **)(*piVar1 + 0xc))(piVar1,local_20,0);
            local_20[2] = 0;
            local_20 = (undefined4 *)((int)local_20 + iVar2);
          }
          if (*(int *)(param_1 + 0x9a4c) < 1) {
            return local_24;
          }
          local_14 = 0;
          while( true ) {
            *local_20 = 0x50524f47;
            local_20[1] = 0;
            local_20[2] = local_14;
            pvVar5 = (void *)FUN_0002e032(*(undefined4 *)(*(int *)(param_1 + 0xcea0) + local_14 * 4)
                                         );
            if ((pvVar5 == (void *)0x0) ||
               (sVar4 = FUN_0002e026(*(undefined4 *)(*(int *)(param_1 + 0xcea0) + local_14 * 4)),
               (int)sVar4 < 1)) break;
            _memcpy(local_20 + 3,pvVar5,sVar4);
            local_20[1] = sVar4 + 0xc;
            local_20 = (undefined4 *)((int)local_20 + sVar4 + 0xc);
            local_14 = local_14 + 1;
            if (*(int *)(param_1 + 0x9a4c) <= local_14) {
              return local_24;
            }
          }
        }
      }
    }
  }
  return 0;
}

