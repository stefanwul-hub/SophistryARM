/* 00093174 FUN_00093174 */

void FUN_00093174(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int local_58;
  int *local_48;
  int *local_44;
  int *local_40;
  int *local_3c;
  int *local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  iVar4 = *(int *)(param_1 + 0x4c0);
  iVar3 = *(int *)(iVar4 + 0xc) / 6;
  iVar7 = *(int *)(*(int *)(param_1 + 0x4c4) + 0xc) / 6;
  uVar2 = *(undefined4 *)(param_1 + 0xc);
  iVar6 = *(int *)(param_1 + 0x4b4);
  if (0 < iVar6) {
    local_58 = 0;
    do {
      iVar6 = local_58 * *(int *)(param_1 + 0x4c8) * 7 + *(int *)(param_1 + 8);
      piVar1 = (int *)((local_58 + *(int *)(param_1 + 0x4b8)) * 0x30 + 0xb0 + param_1);
      if (*piVar1 == 0) {
        FUN_0009310a(param_1,param_2,iVar6,uVar2,iVar4,0);
        if (*piVar1 == 0) goto LAB_00093217;
LAB_000936ca:
        local_34 = iVar6 + iVar3;
        if (piVar1[1] == 0) {
          FUN_0009310a(param_1,param_2,local_34,uVar2,*(undefined4 *)(param_1 + 0x4c4),4);
          if (*piVar1 == 0) goto LAB_00093217;
          if (piVar1[1] != 0) goto LAB_000936d8;
          goto LAB_00093231;
        }
LAB_000936d8:
        FUN_0009310a(param_1,param_2,local_34,uVar2,*(undefined4 *)(param_1 + 0x4c4),5);
        if (*piVar1 == 0) goto LAB_00093217;
        local_30 = iVar7 + local_34;
        if (piVar1[1] == 0) goto LAB_0009372a;
LAB_00093244:
        if (piVar1[2] != 0) goto LAB_00093752;
LAB_00093256:
        if (piVar1[1] == 0) goto LAB_00093260;
LAB_00093791:
        local_38 = piVar1 + 2;
        if (*local_38 == 0) {
          FUN_0009310a(param_1,param_2,local_30,uVar2,*(undefined4 *)(param_1 + 0x4c0),3);
          goto LAB_0009327a;
        }
        local_2c = iVar3 + local_30;
        if (*local_38 == 0) goto LAB_000937b3;
LAB_0009328d:
        local_38 = piVar1 + 2;
        if (piVar1[3] == 0) {
          FUN_0009310a(param_1,param_2,local_2c,uVar2,*(undefined4 *)(param_1 + 0x4c4),4);
          if (*local_38 == 0) goto LAB_000932d9;
          if (piVar1[3] != 0) goto LAB_0009329b;
        }
        else {
LAB_0009329b:
          FUN_0009310a(param_1,param_2,local_2c,uVar2,*(undefined4 *)(param_1 + 0x4c4),5);
          if (*local_38 == 0) {
LAB_000932d9:
            iVar6 = piVar1[3];
            goto joined_r0x000932dd;
          }
        }
      }
      else {
        FUN_0009310a(param_1,param_2,iVar6,uVar2,iVar4,1);
        if (*piVar1 != 0) goto LAB_000936ca;
LAB_00093217:
        local_34 = iVar6 + iVar3;
        if (piVar1[1] != 0) {
          FUN_0009310a(param_1,param_2,local_34,uVar2,*(undefined4 *)(param_1 + 0x4c4),3);
        }
        if ((*piVar1 == 0) && (piVar1[1] == 0)) {
          FUN_0009310a(param_1,param_2,local_34,uVar2,*(undefined4 *)(param_1 + 0x4c4),2);
        }
LAB_00093231:
        local_34 = iVar6 + iVar3;
        local_30 = iVar7 + local_34;
        if (piVar1[1] != 0) goto LAB_00093244;
LAB_0009372a:
        if (piVar1[2] == 0) {
          FUN_0009310a(param_1,param_2,local_30,uVar2,*(undefined4 *)(param_1 + 0x4c0),2);
        }
        local_38 = piVar1 + 2;
        if (piVar1[1] == 0) goto LAB_00093260;
        if (*local_38 == 0) goto LAB_00093256;
LAB_00093752:
        FUN_0009310a(param_1,param_2,local_30,uVar2,*(undefined4 *)(param_1 + 0x4c0),5);
        if (piVar1[1] != 0) goto LAB_00093791;
LAB_00093260:
        local_38 = piVar1 + 2;
        if (*local_38 != 0) {
          FUN_0009310a(param_1,param_2,local_30,uVar2,*(undefined4 *)(param_1 + 0x4c0),4);
        }
        if (piVar1[1] != 0) goto LAB_00093791;
LAB_0009327a:
        local_38 = piVar1 + 2;
        local_2c = iVar3 + local_30;
        if (*local_38 != 0) goto LAB_0009328d;
LAB_000937b3:
        iVar6 = piVar1[3];
joined_r0x000932dd:
        if (iVar6 != 0) {
          FUN_0009310a(param_1,param_2,local_2c,uVar2,*(undefined4 *)(param_1 + 0x4c4),3);
        }
        local_38 = piVar1 + 2;
        if ((*local_38 == 0) && (piVar1[3] == 0)) {
          FUN_0009310a(param_1,param_2,local_2c,uVar2,*(undefined4 *)(param_1 + 0x4c4),2);
        }
      }
      piVar5 = piVar1 + 3;
      local_2c = iVar7 + local_2c;
      if (*piVar5 == 0) {
        if (piVar1[4] == 0) {
          FUN_0009310a(param_1,param_2,local_2c,uVar2,*(undefined4 *)(param_1 + 0x4c0),2);
        }
        local_3c = piVar1 + 4;
        if (*piVar5 != 0) {
          iVar6 = *local_3c;
          goto joined_r0x00093ac0;
        }
LAB_00093325:
        local_3c = piVar1 + 4;
        if (*local_3c != 0) {
          FUN_0009310a(param_1,param_2,local_2c,uVar2,*(undefined4 *)(param_1 + 0x4c0),4);
        }
        if (*piVar5 != 0) goto LAB_00093b05;
LAB_0009333f:
        local_3c = piVar1 + 4;
        if (*local_3c != 0) goto LAB_0009334f;
LAB_00093b24:
        uVar8 = 0;
      }
      else {
        iVar6 = piVar1[4];
joined_r0x00093ac0:
        if (iVar6 == 0) {
          iVar6 = *piVar5;
        }
        else {
          FUN_0009310a(param_1,param_2,local_2c,uVar2,*(undefined4 *)(param_1 + 0x4c0),5);
          iVar6 = *piVar5;
        }
        if (iVar6 == 0) goto LAB_00093325;
LAB_00093b05:
        local_3c = piVar1 + 4;
        if (*local_3c == 0) {
          FUN_0009310a(param_1,param_2,local_2c,uVar2,*(undefined4 *)(param_1 + 0x4c0),3);
          goto LAB_0009333f;
        }
        if (*local_3c == 0) goto LAB_00093b24;
LAB_0009334f:
        uVar8 = 1;
      }
      FUN_0009310a(param_1,param_2,iVar3 + local_2c,uVar2,*(undefined4 *)(param_1 + 0x4c4),uVar8);
      iVar6 = iVar3 + local_2c + iVar7;
      piVar5 = piVar1 + 5;
      FUN_0009310a(param_1,param_2,iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c0),piVar1[5] != 0);
      iVar6 = iVar6 + iVar3;
      if (*piVar5 == 0) {
LAB_00093baf:
        if (piVar1[6] != 0) {
          FUN_0009310a(param_1,param_2,iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c4),3);
        }
        if ((*piVar5 == 0) && (piVar1[6] == 0)) {
          FUN_0009310a(param_1,param_2,iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c4),2);
        }
      }
      else if (piVar1[6] == 0) {
        FUN_0009310a(param_1,param_2,iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c4),4);
        if (*piVar5 == 0) goto LAB_00093baf;
        if (piVar1[6] != 0) goto LAB_000933e2;
      }
      else {
LAB_000933e2:
        FUN_0009310a(param_1,param_2,iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c4),5);
        if (*piVar5 == 0) goto LAB_00093baf;
      }
      piVar5 = piVar1 + 6;
      iVar6 = iVar7 + iVar6;
      if (*piVar5 == 0) {
        if (piVar1[7] == 0) {
          FUN_0009310a(param_1,param_2,iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c0),2);
        }
        local_40 = piVar1 + 7;
        if (*piVar5 != 0) {
          iVar4 = *local_40;
          goto joined_r0x00093b53;
        }
LAB_00093453:
        local_40 = piVar1 + 7;
        if (*local_40 != 0) {
          FUN_0009310a(param_1,param_2,iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c0),4);
        }
        if (*piVar5 != 0) goto LAB_00093b98;
      }
      else {
        iVar4 = piVar1[7];
joined_r0x00093b53:
        if (iVar4 == 0) {
          iVar4 = *piVar5;
        }
        else {
          FUN_0009310a(param_1,param_2,iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c0),5);
          iVar4 = *piVar5;
        }
        if (iVar4 == 0) goto LAB_00093453;
LAB_00093b98:
        local_40 = piVar1 + 7;
        if (*local_40 == 0) {
          FUN_0009310a(param_1,param_2,iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c0),3);
        }
      }
      local_40 = piVar1 + 7;
      iVar6 = iVar3 + iVar6;
      if (*local_40 == 0) {
        iVar4 = piVar1[8];
joined_r0x00093a5e:
        if (iVar4 != 0) {
          FUN_0009310a(param_1,param_2,iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c4),3);
        }
        if ((*local_40 == 0) && (piVar1[8] == 0)) {
          FUN_0009310a(param_1,param_2,iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c4),2);
        }
      }
      else if (piVar1[8] == 0) {
        FUN_0009310a(param_1,param_2,iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c4),4);
        if (*local_40 == 0) goto LAB_000934cc;
        if (piVar1[8] != 0) goto LAB_0009348e;
      }
      else {
LAB_0009348e:
        FUN_0009310a(param_1,param_2,iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c4),5);
        if (*local_40 == 0) {
LAB_000934cc:
          iVar4 = piVar1[8];
          goto joined_r0x00093a5e;
        }
      }
      piVar5 = piVar1 + 8;
      iVar6 = iVar7 + iVar6;
      if (*piVar5 == 0) {
        if (piVar1[9] == 0) {
          FUN_0009310a(param_1,param_2,iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c0),2);
        }
        local_44 = piVar1 + 9;
        if (*piVar5 != 0) {
          iVar4 = *local_44;
          goto joined_r0x000939fe;
        }
LAB_00093518:
        local_44 = piVar1 + 9;
        if (*local_44 != 0) {
          FUN_0009310a(param_1,param_2,iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c0),4);
        }
        if (*piVar5 != 0) goto LAB_00093a43;
      }
      else {
        iVar4 = piVar1[9];
joined_r0x000939fe:
        if (iVar4 == 0) {
          iVar4 = *piVar5;
        }
        else {
          FUN_0009310a(param_1,param_2,iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c0),5);
          iVar4 = *piVar5;
        }
        if (iVar4 == 0) goto LAB_00093518;
LAB_00093a43:
        local_44 = piVar1 + 9;
        if (*local_44 == 0) {
          FUN_0009310a(param_1,param_2,iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c0),3);
        }
      }
      local_44 = piVar1 + 9;
      iVar6 = iVar3 + iVar6;
      if (*local_44 == 0) {
        iVar4 = piVar1[10];
joined_r0x0009399c:
        if (iVar4 != 0) {
          FUN_0009310a(param_1,param_2,iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c4),3);
        }
        if ((*local_44 == 0) && (piVar1[10] == 0)) {
          FUN_0009310a(param_1,param_2,iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c4),2);
        }
      }
      else if (piVar1[10] == 0) {
        FUN_0009310a(param_1,param_2,iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c4),4);
        if (*local_44 == 0) goto LAB_00093591;
        if (piVar1[10] != 0) goto LAB_00093553;
      }
      else {
LAB_00093553:
        FUN_0009310a(param_1,param_2,iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c4),5);
        if (*local_44 == 0) {
LAB_00093591:
          iVar4 = piVar1[10];
          goto joined_r0x0009399c;
        }
      }
      piVar5 = piVar1 + 10;
      iVar6 = iVar7 + iVar6;
      if (*piVar5 == 0) {
        if (piVar1[0xb] == 0) {
          FUN_0009310a(param_1,param_2,iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c0),2);
        }
        local_48 = piVar1 + 0xb;
        if (*piVar5 != 0) {
          iVar4 = *local_48;
          goto joined_r0x0009393c;
        }
LAB_000935dd:
        local_48 = piVar1 + 0xb;
        if (*local_48 != 0) {
          FUN_0009310a(param_1,param_2,iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c0),4);
        }
        if (*piVar5 != 0) goto LAB_00093981;
      }
      else {
        iVar4 = piVar1[0xb];
joined_r0x0009393c:
        if (iVar4 == 0) {
          iVar4 = *piVar5;
        }
        else {
          FUN_0009310a(param_1,param_2,iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c0),5);
          iVar4 = *piVar5;
        }
        if (iVar4 == 0) goto LAB_000935dd;
LAB_00093981:
        local_48 = piVar1 + 0xb;
        if (*local_48 == 0) {
          FUN_0009310a(param_1,param_2,iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c0),3);
        }
      }
      local_48 = piVar1 + 0xb;
      if (*local_48 == 0) {
        FUN_0009310a(param_1,param_2,iVar3 + iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c4),0);
        iVar6 = *(int *)(param_1 + 0x4b4);
        if (iVar6 <= local_58 + 1) goto LAB_0009383f;
      }
      else {
        FUN_0009310a(param_1,param_2,iVar3 + iVar6,uVar2,*(undefined4 *)(param_1 + 0x4c4),1);
        iVar6 = *(int *)(param_1 + 0x4b4);
        if (iVar6 <= local_58 + 1) goto LAB_0009383f;
      }
      local_58 = local_58 + 1;
      iVar4 = *(int *)(param_1 + 0x4c0);
    } while( true );
  }
LAB_00093848:
  iVar7 = iVar6 * *(int *)(param_1 + 0x4c8) * 7 + *(int *)(param_1 + 8);
  piVar1 = (int *)((iVar6 + *(int *)(param_1 + 0x4b8)) * 0x30 + 0xb0 + param_1);
  if (*piVar1 == 0) {
    FUN_0009310a(param_1,param_2,iVar7,uVar2,iVar4,0);
  }
  else {
    FUN_0009310a(param_1,param_2,iVar7,uVar2,iVar4,1);
  }
  if ((*piVar1 == 0) ||
     (FUN_0009310a(param_1,param_2,iVar7 + iVar3,uVar2,*(undefined4 *)(param_1 + 0x4c4),1),
     *piVar1 == 0)) {
    FUN_0009310a(param_1,param_2,iVar7 + iVar3,uVar2,*(undefined4 *)(param_1 + 0x4c4),0);
  }
  return;
LAB_0009383f:
  iVar4 = *(int *)(param_1 + 0x4c0);
  goto LAB_00093848;
}

