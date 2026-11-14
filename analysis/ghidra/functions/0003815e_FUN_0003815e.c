/* 0003815e FUN_0003815e */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined1 FUN_0003815e(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  float fVar2;
  bool bVar3;
  bool bVar4;
  undefined *puVar5;
  char cVar6;
  char cVar7;
  int iVar8;
  longdouble lVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  float fVar15;
  undefined1 local_39;
  int local_38;
  int local_20 [4];
  
  if ((*(char *)(param_1 + 0x15c) == '\0') || (param_3 != 0)) {
    return 0;
  }
  local_39 = 0;
  local_38 = 0;
LAB_000381a4:
  do {
    iVar8 = *(int *)(param_1 + 0x23c + local_38 * 4);
    while( true ) {
      if (iVar8 == 0) {
        return local_39;
      }
      cVar6 = FUN_0002ddfc(iVar8 + 0x1d4);
      if (cVar6 == '\0') break;
      dVar12 = *(double *)(param_1 + 0x268 + local_38 * 8);
      *(double *)(param_1 + 0x328) = dVar12;
      iVar8 = *(int *)(param_1 + 0x23c + local_38 * 4);
      dVar14 = (double)(*(int *)(iVar8 + 0x22c) + -1);
      *(double *)(param_1 + 0x428) = dVar14;
      puVar5 = PTR_DAT_00103830;
      if (dVar14 <= dVar12) {
        FUN_0002de1a(iVar8 + 0x1d4);
        break;
      }
      cVar6 = *(char *)(local_38 + 0x260 + param_1);
      uVar1 = *(undefined4 *)(iVar8 + 0x25c);
      *(undefined **)(param_1 + 0x228) = PTR_DAT_00103830;
      *(undefined **)(param_1 + 0x22c) = puVar5;
      if (*(char *)(param_1 + 0x45d) == '\0') {
        if (*(char *)(param_1 + 0x45e) != '\0') {
          (**(code **)(**(int **)(param_1 + 0x10) + 0x34))
                    (*(int **)(param_1 + 0x10),param_1 + 0x228,0);
          iVar8 = *(int *)(param_1 + 0x23c + local_38 * 4);
        }
      }
      else {
        (**(code **)(**(int **)(param_1 + 0x10) + 0x34))
                  (*(int **)(param_1 + 0x10),param_1 + 0x22c,0);
        iVar8 = *(int *)(param_1 + 0x23c + local_38 * 4);
      }
      *(undefined4 *)(param_1 + 0x208) = *(undefined4 *)(param_1 + 0x1f8);
      *(undefined4 *)(param_1 + 0x20c) = *(undefined4 *)(param_1 + 0x1fc);
      *(undefined4 *)(param_1 + 0x210) = *(undefined4 *)(param_1 + 0x200);
      *(undefined4 *)(param_1 + 0x214) = *(undefined4 *)(param_1 + 0x204);
      *(undefined8 *)(param_1 + 0x330) = *(undefined8 *)(param_1 + 0x2a8 + local_38 * 8);
      *(double *)(param_1 + 0x434) = (double)*(int *)(iVar8 + 0x24c);
      *(double *)(param_1 + 0x43c) = (double)*(int *)(iVar8 + 0x250);
      *(double *)(param_1 + 0x444) = (double)*(int *)(iVar8 + 0x254);
      lVar9 = (longdouble)
              FUN_00015302((double)*(float *)(param_1 + 0x140),(double)*(float *)(iVar8 + 0x238));
      *(double *)(param_1 + 0x44c) = (double)lVar9;
      iVar8 = *(int *)(param_1 + 0x23c + local_38 * 4);
      dVar12 = (double)(*(int *)(iVar8 + 0x22c) / 2);
      if (dVar12 < (double)lVar9) {
        *(double *)(param_1 + 0x44c) = dVar12;
      }
      dVar12 = *(double *)(param_1 + 0x434);
      dVar14 = *(double *)(param_1 + 0x43c);
      *(bool *)(param_1 + 0x458) = dVar12 < dVar14;
      if (dVar14 <= dVar12) {
        *(undefined8 *)(param_1 + 0x418) = *(undefined8 *)(param_1 + 0x2e8 + local_38 * 8);
        if (*(char *)(iVar8 + 0x214) != '\0') goto LAB_000383c7;
LAB_00038732:
        (**(code **)(**(int **)(param_1 + 0x118) + 0x28))
                  (*(int **)(param_1 + 0x118),param_1 + 0x230,0);
      }
      else {
        dVar12 = dVar12 + *(double *)(param_1 + 0x44c);
        if (dVar12 <= dVar14) {
          dVar12 = dVar14;
        }
        *(double *)(param_1 + 0x43c) = dVar12;
        if (cVar6 == '\0') {
          if (*(char *)(param_1 + 0x459) == '\0') {
            fVar15 = *(float *)(*(int *)(param_1 + 0x124) + 0x2ac) * -0.01 + 1.0;
            dVar13 = *(double *)(param_1 + 0x444) * 0.0;
            dVar12 = dVar13 + *(double *)(param_1 + 0x434);
            *(double *)(param_1 + 0x3f8) = dVar12;
            dVar14 = (double)(~-(ulonglong)(1.0 <= dVar12) & (ulonglong)1.0 |
                             (ulonglong)dVar12 & -(ulonglong)(1.0 <= dVar12));
            dVar12 = *(double *)(param_1 + 0x428) - (*(double *)(param_1 + 0x44c) + 1.0);
            if (dVar14 <= dVar12) {
              dVar12 = dVar14;
            }
            *(double *)(param_1 + 0x3f8) = dVar12;
            dVar13 = dVar13 + *(double *)(param_1 + 0x43c);
            dVar12 = dVar12 + *(double *)(param_1 + 0x44c);
            if (dVar12 <= dVar13) {
              dVar12 = dVar13;
            }
            *(double *)(param_1 + 0x400) = dVar12;
            if ((*(char *)(param_1 + 0x15d) != '\0') || (*(char *)(param_1 + 0x45c) != '\0')) {
              dVar14 = *(double *)(param_1 + 0x328) + 1.0;
              if (dVar14 <= dVar12) {
                dVar14 = dVar12;
              }
              *(double *)(param_1 + 0x400) = dVar14;
            }
            dVar12 = *(double *)(param_1 + 0x428) - 1.0;
          }
          else {
            fVar2 = **(float **)(param_1 + 0x214);
            fVar15 = *(float *)(*(int *)(param_1 + 0x124) + 0x2ac) * -0.01 + 1.0;
            dVar12 = (double)**(float **)(param_1 + 0x210) * *(double *)(param_1 + 0x444) +
                     *(double *)(param_1 + 0x434);
            *(double *)(param_1 + 0x3f8) = dVar12;
            dVar13 = (double)(~-(ulonglong)(1.0 <= dVar12) & (ulonglong)1.0 |
                             (ulonglong)dVar12 & -(ulonglong)(1.0 <= dVar12));
            dVar12 = *(double *)(param_1 + 0x428);
            dVar14 = dVar12 - (*(double *)(param_1 + 0x44c) + 1.0);
            if (dVar13 <= dVar14) {
              dVar14 = dVar13;
            }
            *(double *)(param_1 + 0x3f8) = dVar14;
            dVar13 = (double)fVar2 * *(double *)(param_1 + 0x444) + *(double *)(param_1 + 0x43c);
            dVar14 = dVar14 + *(double *)(param_1 + 0x44c);
            if (dVar14 <= dVar13) {
              dVar14 = dVar13;
            }
            *(double *)(param_1 + 0x400) = dVar14;
            if ((*(char *)(param_1 + 0x15d) == '\0') && (*(char *)(param_1 + 0x45c) == '\0')) {
              dVar12 = dVar12 - 1.0;
            }
            else {
              dVar13 = *(double *)(param_1 + 0x328) + 1.0;
              if (dVar13 <= dVar14) {
                dVar13 = dVar14;
              }
              *(double *)(param_1 + 0x400) = dVar13;
              dVar12 = dVar12 - 1.0;
            }
          }
          dVar14 = *(double *)(param_1 + 0x400);
          if (dVar14 <= dVar12) {
            dVar12 = dVar14;
          }
          *(double *)(param_1 + 0x400) = dVar12;
          dVar12 = *(double *)(param_1 + 0x400) - *(double *)(param_1 + 0x3f8);
          *(double *)(param_1 + 0x410) = dVar12;
          dVar12 = (double)fVar15 * dVar12 + *(double *)(param_1 + 0x3f8);
          *(double *)(param_1 + 0x408) = dVar12;
          if ((*(char *)(param_1 + 0x15d) != '\0') || (*(char *)(param_1 + 0x45c) != '\0')) {
            dVar14 = *(double *)(param_1 + 0x328);
            if (*(double *)(param_1 + 0x328) <= dVar12) {
              dVar14 = dVar12;
            }
            *(double *)(param_1 + 0x408) = dVar14;
          }
          dVar12 = *(double *)(param_1 + 0x410);
          uVar10 = SUB84(dVar12,0);
          uVar11 = (undefined4)((ulonglong)dVar12 >> 0x20);
          dVar14 = *(double *)(param_1 + 0x408);
          if (dVar12 <= dVar14) {
            uVar10 = SUB84(dVar14,0);
            uVar11 = (undefined4)((ulonglong)dVar14 >> 0x20);
          }
          *(ulonglong *)(param_1 + 0x408) = CONCAT44(uVar11,uVar10);
          iVar8 = *(int *)(param_1 + 0x23c + local_38 * 4);
        }
        else {
          *(undefined8 *)(param_1 + 0x3f8) = *(undefined8 *)(param_1 + 0x338 + local_38 * 8);
          dVar12 = *(double *)(param_1 + 0x378 + local_38 * 8);
          *(double *)(param_1 + 0x400) = dVar12;
          *(undefined8 *)(param_1 + 0x408) = *(undefined8 *)(param_1 + 0x3b8 + local_38 * 8);
          *(double *)(param_1 + 0x410) = dVar12 - *(double *)(param_1 + 0x3f8);
          iVar8 = *(int *)(param_1 + 0x23c + local_38 * 4);
        }
        *(undefined8 *)(param_1 + 0x418) = *(undefined8 *)(param_1 + 0x2e8 + local_38 * 8);
        if (*(char *)(iVar8 + 0x214) == '\0') goto LAB_00038732;
LAB_000383c7:
        if (*(int *)(param_1 + 0x1e0) == 0) {
          (**(code **)(**(int **)(param_1 + 0x118) + 0x2c))
                    (*(int **)(param_1 + 0x118),param_1 + 0x230,param_1 + 0x234);
        }
        else {
          (**(code **)(**(int **)(param_1 + 0x118) + 0x28))
                    (*(int **)(param_1 + 0x118),param_1 + 0x230,0);
          *(undefined4 *)(param_1 + 0x234) = *(undefined4 *)(param_1 + 0x230);
        }
      }
      *(undefined4 *)(param_1 + 0x430) = 0;
      local_20[0] = param_2;
      if (param_2 < 1) {
        bVar3 = false;
        bVar4 = false;
      }
      else {
        bVar3 = false;
        bVar4 = false;
        do {
          while (cVar6 == '\0') {
            iVar8 = *(int *)(param_1 + 0x23c + local_38 * 4);
            if (*(char *)(iVar8 + 0x214) == '\0') {
              cVar7 = FUN_00036b3a(param_1,local_20,*(undefined4 *)(iVar8 + 0x21c),uVar1);
              bVar4 = true;
            }
            else {
              cVar7 = FUN_00036fbe();
              bVar3 = true;
            }
            if (cVar7 != '\0') {
              if (local_20[0] < 1) {
                cVar7 = '\0';
                local_39 = 1;
              }
              else {
                cVar7 = '\x01';
              }
            }
            if ((*(char *)(param_1 + 0x458) == '\0') ||
               ((*(char *)(param_1 + 0x15d) == '\0' && (*(char *)(param_1 + 0x45c) == '\0'))))
            goto LAB_000386b9;
            dVar12 = *(double *)(param_1 + 0x328);
            if (*(double *)(param_1 + 0x400) <= dVar12) {
              dVar12 = dVar12 - *(double *)(param_1 + 0x410);
              *(double *)(param_1 + 0x328) = dVar12;
              *(double *)(param_1 + 0x330) =
                   *(double *)(param_1 + 0x330) - *(double *)(param_1 + 0x410);
            }
            cVar6 = *(double *)(param_1 + 0x408) <= dVar12;
LAB_000384e3:
            if (cVar7 == '\0') goto LAB_00038583;
          }
          if (*(char *)(*(int *)(param_1 + 0x23c + local_38 * 4) + 0x214) == '\0') {
            FUN_000374bc();
            bVar4 = true;
            if (0 < local_20[0]) goto LAB_00038549;
LAB_0003869d:
            local_39 = 1;
            cVar7 = '\0';
            dVar12 = *(double *)(param_1 + 0x328);
            cVar6 = '\0';
            if (dVar12 < *(double *)(param_1 + 0x408)) goto LAB_000386b9;
          }
          else {
            FUN_00037a86();
            bVar3 = true;
            if (local_20[0] < 1) goto LAB_0003869d;
LAB_00038549:
            cVar7 = '\x01';
            dVar12 = *(double *)(param_1 + 0x328);
            cVar6 = '\x01';
            if (dVar12 < *(double *)(param_1 + 0x408)) goto LAB_000386b9;
          }
          cVar7 = cVar6;
          if (*(double *)(param_1 + 0x400) < dVar12) {
LAB_000386b9:
            cVar6 = false;
            goto LAB_000384e3;
          }
          cVar6 = '\x01';
        } while (cVar7 != '\0');
      }
LAB_00038583:
      *(char *)(local_38 + 0x260 + param_1) = cVar6;
      if (cVar6 != '\0') {
        *(undefined8 *)(param_1 + 0x338 + local_38 * 8) = *(undefined8 *)(param_1 + 0x3f8);
        *(undefined8 *)(param_1 + 0x378 + local_38 * 8) = *(undefined8 *)(param_1 + 0x400);
        *(undefined8 *)(param_1 + 0x3b8 + local_38 * 8) = *(undefined8 *)(param_1 + 0x408);
      }
      FUN_0002de1a(*(int *)(param_1 + 0x23c + local_38 * 4) + 0x1d4);
      *(undefined8 *)(param_1 + 0x268 + local_38 * 8) = *(undefined8 *)(param_1 + 0x328);
      *(undefined8 *)(param_1 + 0x2a8 + local_38 * 8) = *(undefined8 *)(param_1 + 0x330);
      local_38 = local_38 + 1;
      if (bVar3) {
        if (*(int *)(param_1 + 0x1e0) == 0) {
          (**(code **)(**(int **)(param_1 + 0x118) + 0x44))(*(int **)(param_1 + 0x118));
        }
        else {
          (**(code **)(**(int **)(param_1 + 0x118) + 0x40))(*(int **)(param_1 + 0x118));
        }
      }
      if (!bVar4) goto LAB_000381a4;
      (**(code **)(**(int **)(param_1 + 0x118) + 0x40))(*(int **)(param_1 + 0x118));
      iVar8 = *(int *)(param_1 + 0x23c + local_38 * 4);
    }
    local_38 = local_38 + 1;
  } while( true );
}

