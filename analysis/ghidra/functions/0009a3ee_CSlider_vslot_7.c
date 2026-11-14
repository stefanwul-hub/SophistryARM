/* 0009a3ee CSlider_vslot_7 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CSlider_vslot_7(int *param_1,undefined4 param_2,int *param_3,uint param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  float fVar8;
  uint local_54;
  float local_38;
  int local_30;
  
  if (*(char *)((int)param_1 + 0x31) != '\0') {
    if (param_4 == 0xffffffff) {
      param_4 = FUN_0009cba2(param_2);
    }
    piVar1 = (int *)param_1[0xf];
    if ((piVar1 == (int *)0x0) || ((param_4 & 0x78) == 0)) {
      cVar3 = (**(code **)(*param_1 + 0xfc))(param_1,param_2,param_4);
    }
    else {
      iVar7 = (**(code **)(*piVar1 + 4))(piVar1,param_2,param_1,param_4);
      if (iVar7 != 0) {
        return;
      }
      cVar3 = (**(code **)(*param_1 + 0xfc))(param_1,param_2,param_4);
    }
    if ((cVar3 == '\0') && ((param_4 & 1) != 0)) {
      uVar4 = param_1[0x21];
      if ((uVar4 & 1) == 0) {
        local_30 = param_1[3] + param_1[0x1e];
        cVar3 = *(char *)((int)param_1 + 0xad);
      }
      else {
        local_30 = param_1[2] + param_1[0x1d];
        cVar3 = *(char *)((int)param_1 + 0xad);
      }
      if (cVar3 != '\0') {
        if ((uVar4 & 1) == 0) {
          local_30 = local_30 + -1 + param_1[0x23] / 2;
        }
        else {
          local_30 = local_30 + -1 + param_1[0x22] / 2;
        }
LAB_0009a5e1:
        local_38 = (float)param_1[0x13];
        (**(code **)(*param_1 + 0xe0))(param_1);
        local_54 = param_4;
        do {
          uVar4 = FUN_0009cba2(param_2);
          if ((uVar4 & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0x0009a722. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (**(code **)(*param_1 + 0xe4))();
            return;
          }
          if (local_54 == uVar4) {
            uVar6 = uVar4 >> 3 & 1;
            if (uVar6 == 0) goto LAB_0009a6fc;
          }
          else {
            uVar6 = uVar4 >> 3 & 1;
            if (uVar6 == 0) {
LAB_0009a6fc:
              local_38 = (float)param_1[0x13];
              uVar6 = uVar4 >> 3 & 1;
            }
            else {
              local_38 = (float)param_1[0x13];
              local_54 = uVar4;
            }
          }
          uVar4 = param_1[0x21];
          if ((uVar4 & 1) == 0) {
            iVar7 = param_3[1];
          }
          else {
            iVar7 = *param_3;
          }
          param_1[0x13] = (int)((float)(iVar7 - local_30) / (float)param_1[0x24]);
          if (((uVar4 & 0x10) != 0) || ((uVar4 & 0x40) != 0)) {
            param_1[0x13] = (int)(1.0 - (float)param_1[0x13]);
          }
          if (uVar6 != 0) {
            param_1[0x13] =
                 (int)(((float)param_1[0x13] - local_38) / (float)param_1[0x2a] + local_38);
          }
          (**(code **)(*param_1 + 0xf8))(param_1);
          cVar3 = (**(code **)(*param_1 + 0x50))(param_1);
          if ((cVar3 != '\0') && (puVar2 = (undefined4 *)param_1[0xf], puVar2 != (undefined4 *)0x0))
          {
            (**(code **)*puVar2)(puVar2,param_2,param_1);
          }
          (**(code **)(*param_1 + 0x84))(param_1,param_2,param_3);
          (**(code **)(*param_1 + 0xac))(param_1);
        } while( true );
      }
      if (((uVar4 & 8) == 0) && ((uVar4 & 0x20) == 0)) {
        fVar8 = 1.0 - (float)param_1[0x13];
      }
      else {
        fVar8 = (float)param_1[0x13];
      }
      if ((uVar4 & 1) == 0) {
        iVar7 = (int)(fVar8 * (float)param_1[0x24]) + param_1[0x1e] + param_1[3];
        if ((((param_1[2] + param_1[0x1d] <= *param_3) &&
             (*param_3 <= param_1[2] + param_1[0x1d] + param_1[0x22])) &&
            (iVar5 = param_3[1], iVar7 <= iVar5)) && (iVar5 <= param_1[0x23] + iVar7)) {
          local_30 = (iVar5 - iVar7) + local_30;
          goto LAB_0009a5e1;
        }
      }
      else {
        iVar5 = (int)(fVar8 * (float)param_1[0x24]) + param_1[0x1d] + param_1[2];
        iVar7 = *param_3;
        if (((iVar5 <= iVar7) && (iVar7 <= iVar5 + param_1[0x22])) &&
           ((param_1[3] + param_1[0x1e] <= param_3[1] &&
            (param_3[1] <= param_1[3] + param_1[0x1e] + param_1[0x23])))) {
          local_30 = (iVar7 - iVar5) + local_30;
          goto LAB_0009a5e1;
        }
      }
    }
  }
  return;
}

