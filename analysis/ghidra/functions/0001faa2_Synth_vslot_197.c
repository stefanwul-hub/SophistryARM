/* 0001faa2 Synth_vslot_197 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Synth_vslot_197(int *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  longdouble lVar7;
  int local_5c;
  int local_58;
  int *local_4c;
  int *local_48;
  undefined1 local_34 [4];
  undefined1 local_30;
  undefined1 local_2f;
  undefined2 local_2e;
  undefined4 local_28;
  undefined4 local_24;
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_1[0x33ec] + -1 < param_2) {
    param_2 = param_1[0x33ec] + -1;
  }
  (**(code **)(*param_1 + 0x364))(param_1,param_2,0,0xffffffff);
  *(undefined1 *)(param_1 + 0x33f6) = 1;
  if (0 < param_1[0x24b1]) {
    iVar3 = 0;
    piVar5 = param_1;
    do {
      lVar7 = (longdouble)(**(code **)(*param_1 + 0x2b4))(param_1,piVar5[0x22b1]);
      (**(code **)(*param_1 + 0x2b0))(param_1,piVar5[0x22b2],(float)lVar7);
      iVar3 = iVar3 + 1;
      piVar5 = piVar5 + 2;
    } while (iVar3 < param_1[0x24b1]);
  }
  *(undefined1 *)(param_1 + 0x33f6) = 0;
  if (param_1[0xed0] != 0) {
    FUN_0002b8e2(local_34);
    local_30 = 0x59;
    local_2f = 0xff;
    local_2e = 0xffff;
    local_28 = 0;
    local_24 = 0;
    FUN_0002ba10(param_1 + 0xe29,local_34);
    HoldData_c_vslot_0(local_34);
  }
  Envelope_c_vslot_30(param_1 + 0xf3,param_2,0xffffffff);
  Envelope_c_vslot_30(param_1 + 0x169,param_2,0xffffffff);
  piVar5 = (int *)param_1[0xeec];
  if (piVar5 == (int *)0x0) {
    return;
  }
  (**(code **)(*piVar5 + 0x78))(piVar5,param_2,0xffffffff);
  if (0 < param_1[0xee2]) {
    local_48 = param_1;
    local_5c = 0;
    do {
      if (((int *)local_48[0x1447] != (int *)0x0) &&
         (piVar5 = *(int **)local_48[0x1447], piVar5 != (int *)0x0)) {
        (**(code **)(*piVar5 + 0x74))(piVar5);
        (**(code **)(**(int **)local_48[0x1447] + 0x78))
                  (*(int **)local_48[0x1447],param_2,0xffffffff);
        bVar1 = true;
        while (*(int *)local_48[0x1447] != 0) {
          if (bVar1) {
            if (0 < param_1[0xee2]) {
              iVar3 = 0;
              piVar5 = param_1;
              do {
                if (((int *)piVar5[0x1447] != (int *)0x0) &&
                   (*(int *)local_48[0x1447] == *(int *)piVar5[0x1447])) goto LAB_0001fc7b;
                iVar3 = iVar3 + 1;
                piVar5 = piVar5 + 7;
              } while (param_1[0xee2] != iVar3);
            }
            iVar3 = -1;
LAB_0001fc7b:
            param_1[0x2699] = iVar3;
            param_1[0x269a] = 0;
          }
          iVar3 = param_1[0x2699];
          if (((iVar3 < 0) || (iVar4 = param_1[0x269a], param_1[iVar3 * 7 + 0x144b] <= iVar4)) ||
             (iVar2 = param_1[iVar3 * 7 + 0x1447], iVar2 == 0)) {
            if (param_1[0xee2] <= local_5c + 1) goto LAB_0001fe22;
            goto LAB_0001fd4a;
          }
          while( true ) {
            piVar5 = *(int **)(iVar2 + iVar4 * 4);
            if (piVar5 == (int *)0x0) goto LAB_0001fd30;
            iVar2 = piVar5[0x4a];
            iVar4 = iVar4 + 1;
            param_1[0x269a] = iVar4;
            if (param_2 == iVar2) break;
            if ((param_1[iVar3 * 7 + 0x144b] <= iVar4) ||
               (iVar2 = param_1[iVar3 * 7 + 0x1447], iVar2 == 0)) goto LAB_0001fd30;
          }
          if (param_2 != iVar2) break;
          lVar7 = (longdouble)(**(code **)(*piVar5 + 0x70))(piVar5);
          if ((float)lVar7 == 0.0) {
            bVar1 = false;
          }
          else {
            (**(code **)(*piVar5 + 0x7c))(piVar5,0xffffffff);
            bVar1 = false;
          }
        }
      }
LAB_0001fd30:
      if (param_1[0xee2] <= local_5c + 1) goto LAB_0001fe22;
LAB_0001fd4a:
      local_48 = local_48 + 7;
      local_5c = local_5c + 1;
    } while( true );
  }
  piVar5 = *(int **)param_1[0xec3];
joined_r0x0001fe2e:
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 0x18))(piVar5,param_2);
    piVar5 = *(int **)(param_1[0x33a9] + param_2 * 4);
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 0x18))(piVar5,param_2);
      (**(code **)(*param_1 + 0x368))(param_1,param_2,0,0xffffffff);
      (**(code **)(*param_1 + 0x308))(param_1,param_1[0xee0]);
      if ((param_1[0xeec] != 0) && (0 < param_1[0xee3])) {
        local_4c = param_1;
        local_58 = 0;
        iVar3 = param_1[0x18aa];
        if (iVar3 != -1) goto LAB_0001ff65;
        do {
          iVar3 = local_4c[0x18a7];
          iVar4 = local_4c[0x18a8];
          iVar2 = local_4c[0x18a9];
          if (0 < param_1[iVar3 * 7 + 0x144b]) {
            iVar6 = 0;
            do {
              if (param_1[iVar3 * 7 + 0x1447] == 0) {
LAB_0001ff0b:
                if (param_1[iVar3 * 7 + 0x144b] <= iVar6 + 1) break;
              }
              else {
                piVar5 = *(int **)(param_1[iVar3 * 7 + 0x1447] + iVar6 * 4);
                if (piVar5 != (int *)0x0) {
                  (**(code **)(*piVar5 + 0xbc))(piVar5,param_2,iVar4,iVar2);
                  goto LAB_0001ff0b;
                }
                if (param_1[iVar3 * 7 + 0x144b] <= iVar6 + 1) break;
              }
              iVar6 = iVar6 + 1;
            } while( true );
          }
          do {
            local_58 = local_58 + 1;
            piVar5 = local_4c + 6;
            if (param_1[0xee3] <= local_58) goto LAB_0001fdf6;
            iVar3 = local_4c[0x18b0];
            local_4c = piVar5;
            if (iVar3 == -1) break;
LAB_0001ff65:
            iVar3 = (**(code **)(*(int *)param_1[0xeec] + 0x30))
                              ((int *)param_1[0xeec],param_2,iVar3);
          } while (iVar3 != local_4c[0x18ab]);
        } while( true );
      }
LAB_0001fdf6:
      (**(code **)(*param_1 + 0x350))(param_1);
    }
  }
  return;
LAB_0001fe22:
  piVar5 = *(int **)param_1[0xec3];
  goto joined_r0x0001fe2e;
}

