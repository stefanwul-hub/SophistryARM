/* 0002037e Synth_vslot_3 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Synth_vslot_3(int *param_1)

{
  undefined1 uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int local_28;
  
  if ((char)param_1[0x33f1] == '\0') {
    param_1[0xecd] = 1;
    pvVar2 = _malloc(param_1[0x2692] * 0x20 + 0x20);
    param_1[0x22af] = (int)pvVar2;
    pvVar2 = _malloc(param_1[0x2692] * 0x10 + 0x10);
    param_1[0x22b0] = (int)pvVar2;
    if (((void *)param_1[0x22af] != (void *)0x0) && (pvVar2 != (void *)0x0)) {
      _memset((void *)param_1[0x22af],0,param_1[0x2692] << 5);
      if (0 < param_1[0x2692]) {
        iVar5 = 0;
        do {
          iVar3 = 0;
          iVar4 = iVar5 << 4;
          do {
            *(undefined4 *)(iVar4 + param_1[0x22b0]) = 0xffffffff;
            iVar3 = iVar3 + 1;
            iVar4 = iVar4 + 4;
          } while (iVar3 != 4);
          iVar5 = iVar5 + 1;
        } while (iVar5 < param_1[0x2692]);
      }
      _memset(param_1 + 0x22b1,0,0x800);
      pvVar2 = _malloc(param_1[0x2693] * 4 + 4);
      param_1[0x33a8] = (int)pvVar2;
      if (pvVar2 != (void *)0x0) {
        if (0 < param_1[0x2693]) {
          iVar5 = 0;
          do {
            *(undefined4 *)(param_1[0x33a8] + iVar5 * 4) = 0;
            iVar5 = iVar5 + 1;
          } while (iVar5 < param_1[0x2693]);
        }
        pvVar2 = _malloc(param_1[0x2697] * 8 + 4);
        param_1[0x26f1] = (int)pvVar2;
        if (pvVar2 != (void *)0x0) {
          local_28 = 0;
          piVar6 = param_1;
          do {
            pvVar2 = _malloc(0x24);
            piVar6[0x1e66] = (int)pvVar2;
            if (pvVar2 == (void *)0x0) {
              return;
            }
            local_28 = local_28 + 1;
            piVar6 = piVar6 + 1;
          } while (local_28 != 5);
          pvVar2 = _malloc(param_1[0xec9] * 4 + 4);
          param_1[0xec3] = (int)pvVar2;
          if (pvVar2 != (void *)0x0) {
            if (0 < param_1[0xec9]) {
              iVar5 = 0;
              do {
                *(undefined4 *)(param_1[0xec3] + iVar5 * 4) = 0;
                iVar5 = iVar5 + 1;
              } while (iVar5 < param_1[0xec9]);
            }
            pvVar2 = _malloc(param_1[0x33ec] * 4 + 4);
            param_1[0x33a9] = (int)pvVar2;
            if (pvVar2 != (void *)0x0) {
              if (0 < param_1[0x33ec]) {
                iVar5 = 0;
                do {
                  *(undefined4 *)(param_1[0x33a9] + iVar5 * 4) = 0;
                  iVar5 = iVar5 + 1;
                } while (iVar5 < param_1[0x33ec]);
              }
              iVar5 = FUN_0002e1c0(param_1 + 0xe28);
              param_1[0x269c] = iVar5;
              param_1[0x349c] = iVar5;
              piVar6 = param_1 + 0xf3;
              if (((piVar6 != (int *)0x0) && (iVar5 = param_1[0xee2], -1 < iVar5)) && (iVar5 < 0xa0)
                 ) {
                pvVar2 = _malloc(8);
                param_1[iVar5 * 7 + 0x1447] = (int)pvVar2;
                if ((undefined4 *)param_1[param_1[0xee2] * 7 + 0x1447] != (undefined4 *)0x0) {
                  *(undefined4 *)param_1[param_1[0xee2] * 7 + 0x1447] = piVar6;
                  param_1[param_1[0xee2] * 7 + 0x1448] = 0;
                  iVar5 = param_1[0xee2];
                  iVar3 = (**(code **)(param_1[0xf3] + 100))(piVar6);
                  param_1[iVar5 * 7 + 0x1449] = iVar3;
                  param_1[param_1[0xee2] * 7 + 0x144a] = 0;
                  param_1[param_1[0xee2] * 7 + 0x144b] = 1;
                  iVar5 = param_1[0xee2];
                  param_1[0xee2] = iVar5 + 1;
                  FUN_0001a686(param_1,iVar5);
                }
              }
              piVar6 = param_1 + 0x169;
              if (((piVar6 != (int *)0x0) && (iVar5 = param_1[0xee2], -1 < iVar5)) && (iVar5 < 0xa0)
                 ) {
                pvVar2 = _malloc(8);
                param_1[iVar5 * 7 + 0x1447] = (int)pvVar2;
                if ((undefined4 *)param_1[param_1[0xee2] * 7 + 0x1447] != (undefined4 *)0x0) {
                  *(undefined4 *)param_1[param_1[0xee2] * 7 + 0x1447] = piVar6;
                  param_1[param_1[0xee2] * 7 + 0x1448] = 0;
                  iVar5 = param_1[0xee2];
                  iVar3 = (**(code **)(param_1[0x169] + 100))(piVar6);
                  param_1[iVar5 * 7 + 0x1449] = iVar3;
                  param_1[param_1[0xee2] * 7 + 0x144a] = 0;
                  param_1[param_1[0xee2] * 7 + 0x144b] = 1;
                  iVar5 = param_1[0xee2];
                  param_1[0xee2] = iVar5 + 1;
                  FUN_0001a686(param_1,iVar5);
                }
              }
              param_1[0x33a6] = 0;
              NoteFreqTable_c_vslot_5(param_1 + 0xdb0,param_1 + 0x33a6);
              param_1[0x33a4] = 0;
              SysGlo_c_vslot_5(param_1 + 0x2d,param_1 + 0x33a4);
              param_1[0x33a5] = 0;
              ECS2_c_vslot_5(param_1 + 0x1e1,param_1 + 0x33a5);
              if (param_1[0xdaf] != 0) {
                param_1[0x33a7] = 0;
                (**(code **)(*(int *)param_1[0xdaf] + 0x14))((int *)param_1[0xdaf],param_1 + 0x33a7)
                ;
              }
              (**(code **)(*param_1 + 0x280))(param_1);
              iVar5 = (**(code **)(*param_1 + 0x15c))(param_1,"supplyIdle");
              *(bool *)((int)param_1 + 0xcfd6) = 0 < iVar5;
              if (0 >= iVar5) {
                uVar1 = FUN_000ae908(param_1 + 0x2689,FUN_0001af32,0x32,param_1);
                *(undefined1 *)((int)param_1 + 0xcfd6) = uVar1;
              }
              (**(code **)(*param_1 + 0x284))(param_1);
              param_1[0xecd] = 0;
              return;
            }
          }
        }
      }
    }
  }
  return;
}

