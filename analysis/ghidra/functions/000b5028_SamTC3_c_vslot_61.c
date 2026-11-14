/* 000b5028 SamTC3_c_vslot_61 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 SamTC3_c_vslot_61(int param_1,int param_2,int param_3)

{
  float fVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  undefined4 uVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int local_24;
  int local_20 [4];
  
  if (1.0 < *(float *)(param_1 + 0x140)) {
    if (*(int *)(param_1 + 0x3c4) == 0) {
      return 1;
    }
    dVar2 = *(double *)(param_1 + 0x340);
    *(double *)(param_1 + 0x340) = (double)*(float *)(param_1 + 0x1e8) * dVar2;
    *(undefined4 *)(param_1 + 0x204) = *(undefined4 *)(param_1 + 0x1f8);
    *(undefined4 *)(param_1 + 0x208) = *(undefined4 *)(param_1 + 0x1fc);
    *(undefined4 *)(param_1 + 0x20c) = *(undefined4 *)(param_1 + 0x200);
    *(undefined8 *)(param_1 + 0x310) = *(undefined8 *)(param_1 + 0x220 + param_3 * 8);
    *(undefined8 *)(param_1 + 0x318) = *(undefined8 *)(param_1 + 0x248 + param_3 * 8);
    *(undefined8 *)(param_1 + 0x328) = *(undefined8 *)(param_1 + 0x2e8 + param_3 * 8);
    *(undefined8 *)(param_1 + 0x330) = *(undefined8 *)(param_1 + 0x270 + param_3 * 8);
    *(undefined8 *)(param_1 + 0x338) = *(undefined8 *)(param_1 + 0x298 + param_3 * 8);
    iVar3 = *(int *)(param_1 + 0x3c4);
    if ((1.0 < (double)*(int *)(iVar3 + 0x210)) && (1.0 < *(float *)(iVar3 + 0x224))) {
      cVar5 = FUN_0002ddfc(iVar3 + 0x1d4);
      if (cVar5 == '\0') {
        return 1;
      }
      fVar1 = *(float *)(*(int *)(param_1 + 0x3c4) + 0x224);
      dVar7 = *(double *)(param_1 + 0x388 + param_3 * 8) - 1.0;
      if (dVar7 <= *(double *)(param_1 + 0x310)) {
        FUN_0002de1a(*(int *)(param_1 + 0x3c4) + 0x1d4);
        return 1;
      }
      if (*(int *)(param_1 + 0x1dc) != 0) {
        (**(code **)(**(int **)(param_1 + 0x10) + 0x34))
                  (*(int **)(param_1 + 0x10),param_1 + 0x210,0);
      }
      (**(code **)(**(int **)(param_1 + 0x118) + 0x28))(*(int **)(param_1 + 0x118),local_20,0);
      *(undefined4 *)(param_1 + 0x3b4) = 0;
      uVar6 = *(undefined4 *)(*(int *)(param_1 + 0x3c4) + 0x21c);
      local_24 = param_2;
      do {
        if (*(char *)(param_3 + 0x358 + param_1) != '\0') {
          dVar8 = (double)fVar1 + *(double *)(param_1 + 0x360 + param_3 * 8);
          dVar9 = dVar7;
          if (dVar8 <= dVar7) {
            dVar9 = dVar8;
          }
          iVar3 = *(int *)(param_1 + 0x1dc);
          uVar10 = SUB84(dVar9,0);
          uVar11 = (undefined4)((ulonglong)dVar9 >> 0x20);
          if (iVar3 == 1) {
            cVar5 = FUN_000b4642(param_1,uVar6,uVar10,uVar11,local_20,&local_24);
          }
          else if (iVar3 == 2) {
            cVar5 = FUN_000b401c(param_1,uVar6,uVar10,uVar11,local_20,&local_24);
          }
          else if (iVar3 == 0) {
            cVar5 = FUN_000b3a1e(param_1,uVar6,uVar10,uVar11,local_20,&local_24);
          }
          else {
            cVar5 = '\0';
          }
          if (dVar7 <= *(double *)(param_1 + 0x310)) {
            FUN_0002de1a(*(int *)(param_1 + 0x3c4) + 0x1d4);
            (**(code **)(**(int **)(param_1 + 0x118) + 0x40))(*(int **)(param_1 + 0x118));
            *(double *)(param_1 + 0x340) = dVar2;
            return 1;
          }
          if (cVar5 != '\0') {
            dVar9 = *(double *)(param_1 + 0x360 + param_3 * 8);
            *(double *)(param_1 + 0x310) = dVar9;
            *(double *)(param_1 + 0x330) = dVar9 - 1.0;
            *(undefined1 *)(param_3 + 0x358 + param_1) = 0;
          }
        }
        do {
          iVar3 = local_24;
          cVar5 = FUN_000b48c4(param_1,uVar6,fVar1,dVar7,local_20[0],&local_24);
          if (cVar5 != '\0') {
            if (*(char *)(param_1 + 0x3b0) == '\0') {
              cVar5 = '\x01';
            }
            else {
              iVar4 = *(int *)(param_1 + 0x3c4);
              if (iVar4 == 0) {
                *(undefined4 *)(param_1 + 0x360 + param_3 * 8) = 0;
                *(undefined4 *)(param_1 + 0x364 + param_3 * 8) = 0;
                *(undefined4 *)(param_1 + 0x388 + param_3 * 8) = 0;
                *(undefined4 *)(param_1 + 0x38c + param_3 * 8) = 0;
              }
              else {
                *(double *)(param_1 + 0x360 + param_3 * 8) = (double)*(int *)(iVar4 + 0x26c);
                *(double *)(param_1 + 0x388 + param_3 * 8) = (double)*(int *)(iVar4 + 0x270);
              }
              dVar9 = *(double *)(param_1 + 0x360 + param_3 * 8);
              dVar8 = (double)*(float *)(iVar4 + 0x224) + dVar9;
              *(double *)(param_1 + 0x220 + param_3 * 8) = dVar9;
              *(double *)(param_1 + 0x310) = dVar9;
              *(double *)(param_1 + 0x248 + param_3 * 8) = dVar8;
              *(double *)(param_1 + 0x318) = dVar8;
              *(double *)(param_1 + 0x2e8 + param_3 * 8) = 1e-06;
              *(double *)(param_1 + 0x328) = 1e-06;
              *(double *)(param_1 + 0x270 + param_3 * 8) = dVar9 - 1.0;
              *(double *)(param_1 + 0x330) = dVar9 - 1.0;
              *(double *)(param_1 + 0x298 + param_3 * 8) = dVar8 - 1.0;
              *(double *)(param_1 + 0x338) = dVar8 - 1.0;
              *(undefined1 *)(param_3 + 0x358 + param_1) = 1;
              cVar5 = '\0';
            }
          }
          local_20[0] = local_20[0] + (iVar3 - local_24) * 4;
          if (cVar5 != '\0') {
            uVar6 = 1;
LAB_000b5426:
            *(undefined8 *)(param_1 + 0x220 + param_3 * 8) = *(undefined8 *)(param_1 + 0x310);
            *(undefined8 *)(param_1 + 0x248 + param_3 * 8) = *(undefined8 *)(param_1 + 0x318);
            *(undefined8 *)(param_1 + 0x2e8 + param_3 * 8) = *(undefined8 *)(param_1 + 0x328);
            *(undefined8 *)(param_1 + 0x270 + param_3 * 8) = *(undefined8 *)(param_1 + 0x330);
            *(undefined8 *)(param_1 + 0x298 + param_3 * 8) = *(undefined8 *)(param_1 + 0x338);
            FUN_0002de1a(*(int *)(param_1 + 0x3c4) + 0x1d4);
            (**(code **)(**(int **)(param_1 + 0x118) + 0x40))(*(int **)(param_1 + 0x118));
            *(double *)(param_1 + 0x340) = dVar2;
            return uVar6;
          }
          if (local_24 < 1) {
            uVar6 = 0;
            goto LAB_000b5426;
          }
        } while (*(char *)(param_3 + 0x358 + param_1) == '\0');
      } while( true );
    }
  }
  return 0;
}

