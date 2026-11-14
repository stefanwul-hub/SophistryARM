/* 000219f2 Synth_vslot_172 */

void Synth_vslot_172(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  longdouble lVar13;
  undefined1 local_60;
  undefined1 local_30 [4];
  undefined1 local_2c;
  undefined1 local_2b;
  undefined2 local_2a;
  undefined4 local_24;
  undefined4 local_20;
  int local_18;
  int *local_14;
  int local_10;
  
  if ((char)param_1[0x33f1] != '\0') {
    iVar6 = param_1[0xecf];
    iVar9 = param_2 % iVar6;
    if ((((iVar9 < param_1[0x2692]) && (iVar9 != param_1[0xed4])) && (param_1[0x22af] != 0)) &&
       (iVar10 = iVar9 * 0x20, *(char *)(param_1[0x22af] + 0x1c + iVar10) == '\0')) {
      local_18 = -1;
      FUN_0001cb52(param_1,iVar9,&local_14,&local_18,&local_10);
      if ((local_18 != -1) && (local_14 != (int *)0x0)) {
        _OSAtomicAdd32Barrier(1,param_1 + 0xecc);
        iVar3 = local_18;
        iVar5 = local_10;
        if (*(int *)(iVar10 + 0xc + param_1[0x22af]) == -1) {
          iVar5 = param_2 / iVar6;
        }
        iVar6 = iVar5 * 4;
        local_10 = iVar5;
        if ((*(int *)(param_1[0x33a9] + iVar6) != 0) && ((char)param_1[0x33f1] != '\0')) {
          iVar7 = param_1[0xed7];
          if ((iVar7 < 0) || (param_1[0x33ec] < 1)) {
LAB_00021ca1:
            iVar7 = _OSAtomicAdd32Barrier(1,param_1 + 0x26f4);
            if (iVar7 == 1) {
              uVar4 = FUN_0002ddaa(*(int *)(iVar6 + param_1[0x33a9]) + 0xe84);
              *(undefined1 *)(param_1 + 0x26f5) = uVar4;
            }
            (**(code **)(*local_14 + 0x1c))(local_14,iVar5,iVar3,param_3);
            bVar2 = true;
            while ((((param_1[0x22af] != 0 && (-1 < iVar9)) && (iVar9 < param_1[0x2692])) &&
                   (piVar8 = (int *)(param_1[0x22af] + iVar10), iVar9 == *piVar8))) {
              if (bVar2) {
                if (0 < param_1[0xee2]) {
                  iVar7 = 0;
                  piVar12 = param_1;
                  do {
                    if (((int *)piVar12[0x1447] != (int *)0x0) &&
                       (piVar8[5] == *(int *)piVar12[0x1447])) goto LAB_00021de0;
                    iVar7 = iVar7 + 1;
                    piVar12 = piVar12 + 7;
                  } while (iVar7 != param_1[0xee2]);
                }
                iVar7 = -1;
LAB_00021de0:
                param_1[0x2699] = iVar7;
                param_1[0x269a] = 0;
              }
              iVar7 = param_1[0x2699];
              if ((iVar7 < 0) || (iVar11 = param_1[0x269a], param_1[iVar7 * 7 + 0x144b] <= iVar11))
              break;
              iVar1 = param_1[iVar7 * 7 + 0x1447];
              while( true ) {
                if ((iVar1 == 0) || (piVar8 = *(int **)(iVar1 + iVar11 * 4), piVar8 == (int *)0x0))
                goto LAB_00021d1a;
                iVar1 = piVar8[0x4a];
                iVar11 = iVar11 + 1;
                param_1[0x269a] = iVar11;
                if (iVar5 == iVar1) break;
                if (param_1[iVar7 * 7 + 0x144b] <= iVar11) goto LAB_00021d1a;
                iVar1 = param_1[iVar7 * 7 + 0x1447];
              }
              if (iVar5 != iVar1) break;
              (**(code **)(*piVar8 + 0x7c))(piVar8,iVar3);
              bVar2 = false;
            }
LAB_00021d1a:
            (**(code **)(*param_1 + 0x364))(param_1,iVar5,local_14,iVar3);
            iVar10 = _OSAtomicAdd32Barrier(0xffffffff,param_1 + 0x26f4);
            if ((iVar10 == 0) && ((char)param_1[0x26f5] != '\0')) {
              FUN_0002ddc8(*(int *)(iVar6 + param_1[0x33a9]) + 0xe84);
            }
            (**(code **)(*param_1 + 0x34c))(param_1,iVar9,1);
            (**(code **)(*param_1 + 0x354))(param_1,1);
          }
          else if (iVar9 != iVar7) {
            iVar11 = 0;
            do {
              iVar11 = iVar11 + 1;
              if (param_1[0x33ec] == iVar11) goto LAB_00021ca1;
            } while (iVar9 != iVar7 + param_1[0xed9] * iVar11);
          }
        }
        iVar6 = local_10;
        if (param_1[0xed0] != 0) {
          FUN_0002b8e2(local_30);
          local_2c = 0x59;
          local_60 = (undefined1)iVar6;
          local_2b = local_60;
          local_2a = (undefined2)iVar9;
          local_24 = 0;
          local_20 = 0;
          FUN_0002ba10(param_1 + 0xe29,local_30);
          HoldData_c_vslot_0(local_30);
        }
        if ((char)param_1[0x33f6] == '\0') {
          *(undefined1 *)(param_1 + 0x33f6) = 1;
          if (param_2 < 0) {
            if (0 < param_1[0x24b1]) {
              iVar6 = 0;
              piVar8 = param_1;
              do {
                lVar13 = (longdouble)(**(code **)(*param_1 + 0x2b4))(param_1,piVar8[0x22b1]);
                (**(code **)(*param_1 + 0x2b0))(param_1,piVar8[0x22b2],(float)lVar13);
                iVar6 = iVar6 + 1;
                piVar8 = piVar8 + 2;
              } while (iVar6 < param_1[0x24b1]);
            }
          }
          else if (0 < param_1[0x24b1]) {
            iVar6 = 0;
            piVar8 = param_1;
            do {
              if (param_2 == piVar8[0x22b1]) {
                (**(code **)(*param_1 + 0x2b0))(param_1,piVar8[0x22b2],param_3);
              }
              iVar6 = iVar6 + 1;
              piVar8 = piVar8 + 2;
            } while (iVar6 < param_1[0x24b1]);
          }
          *(undefined1 *)(param_1 + 0x33f6) = 0;
        }
        _OSAtomicAdd32Barrier(0xffffffff,param_1 + 0xecc);
        return;
      }
    }
  }
  return;
}

