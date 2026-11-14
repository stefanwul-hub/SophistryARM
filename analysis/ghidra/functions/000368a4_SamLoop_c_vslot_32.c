/* 000368a4 SamLoop_c_vslot_32 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void SamLoop_c_vslot_32(int param_1,undefined4 param_2,int param_3,undefined1 param_4)

{
  int *piVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  longdouble lVar8;
  double dVar9;
  int local_4c;
  int local_48;
  int local_44;
  undefined *local_3c;
  undefined1 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined *local_2c;
  undefined1 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_3c = PTR_DAT_00103808 + 8;
  local_38 = *(undefined1 *)(param_3 + 4);
  local_34 = *(undefined4 *)(param_3 + 8);
  local_30 = *(undefined4 *)(param_3 + 0xc);
  OscAnalog3_c_vslot_32(param_1,param_2,&local_3c,param_4);
  puVar2 = PTR_DAT_00103808;
  local_3c = PTR_DAT_00103808 + 8;
  if ((*(int *)(param_1 + 0x124) != 0) && (*(int *)(param_1 + 0x238) != 0)) {
    *(undefined4 *)(param_1 + 0x454) = 0;
    iVar5 = 9;
    iVar3 = param_1;
    do {
      *(undefined4 *)(iVar3 + 0x23c) = 0;
      iVar3 = iVar3 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    local_28 = *(undefined1 *)(param_3 + 4);
    local_24 = *(undefined4 *)(param_3 + 8);
    local_20 = *(undefined4 *)(param_3 + 0xc);
    local_2c = puVar2 + 8;
    FUN_00035e9c(*(undefined4 *)(param_1 + 0x238),param_2,&local_2c,param_1 + 0x23c,8);
    if (*(int *)(param_1 + 0x23c) != 0) {
      local_48 = param_1;
      local_44 = param_1;
      local_4c = param_1 + 0x2e0;
      iVar3 = param_1;
      local_2c = puVar2 + 8;
      do {
        lVar8 = (longdouble)FUN_0000c38c(param_1,*(undefined4 *)(param_1 + 0x134),5,2,3,4);
        *(double *)(iVar3 + 0x2e8) =
             (double)(((float)lVar8 * (float)*(int *)(*(int *)(local_48 + 0x23c) + 0x210) *
                      *(float *)(param_1 + 0x144)) / *(float *)(*(int *)(local_48 + 0x23c) + 0x238))
        ;
        dVar9 = 0.0001;
        if (0.0001 <= *(double *)(local_4c + 8)) {
          dVar9 = *(double *)(local_4c + 8);
        }
        *(double *)(local_4c + 8) = dVar9;
        iVar5 = *(int *)(param_1 + 0x23c);
        if (iVar5 != 0) {
          iVar6 = param_1 + 0x260;
          iVar4 = param_1;
          iVar7 = param_1;
          do {
            *(double *)(iVar4 + 0x268) = (double)*(int *)(iVar5 + 0x26c) + 0.0;
            dVar9 = 0.0;
            if (0.0 <= *(double *)(iVar6 + 8)) {
              dVar9 = *(double *)(iVar6 + 8);
            }
            *(double *)(iVar6 + 8) = dVar9;
            *(double *)(iVar4 + 0x2a8) = *(double *)(iVar4 + 0x268) - *(double *)(iVar4 + 0x2e8);
            iVar6 = iVar6 + 8;
            iVar5 = *(int *)(iVar7 + 0x240);
            iVar4 = iVar4 + 8;
            iVar7 = iVar7 + 4;
          } while (iVar5 != 0);
        }
        *(undefined4 *)(iVar3 + 0x338) = 0;
        *(undefined4 *)(iVar3 + 0x33c) = 0xbff00000;
        *(undefined4 *)(iVar3 + 0x378) = 0;
        *(undefined4 *)(iVar3 + 0x37c) = 0xbff00000;
        *(undefined4 *)(iVar3 + 0x3b8) = 0;
        *(undefined4 *)(iVar3 + 0x3bc) = 0xbff00000;
        *(undefined1 *)(local_44 + 0x260) = 0;
        local_4c = local_4c + 8;
        iVar3 = iVar3 + 8;
        local_44 = local_44 + 1;
        piVar1 = (int *)(local_48 + 0x240);
        local_48 = local_48 + 4;
      } while (*piVar1 != 0);
    }
    *(undefined1 *)(param_1 + 0x45c) = *(undefined1 *)(*(int *)(param_1 + 0x124) + 0x32c);
  }
  return;
}

