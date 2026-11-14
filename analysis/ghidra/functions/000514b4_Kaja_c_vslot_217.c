/* 000514b4 Kaja_c_vslot_217 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Kaja_c_vslot_217(int *param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  char cVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  int *piVar10;
  longdouble lVar11;
  longdouble lVar12;
  double dVar13;
  int *local_180;
  int *local_168;
  undefined1 local_15c [332];
  
  Synth_vslot_217(param_1,param_2,param_3,param_4);
  if (param_4 == -1) {
LAB_000524b9:
    iVar6 = Envelope_c_vslot_12(param_1 + 0xcaa81,param_2,4);
    if (iVar6 != -1 && SCARRY4(iVar6,1) == iVar6 + 1 < 0) {
      FUN_0004bc7a(param_1);
    }
joined_r0x000524ed:
    piVar10 = param_1 + 0xcaa81;
    if ((param_3 == param_1 + 0xcaa81) && (piVar10 = param_3, 0xd3 < param_4)) {
      if (param_4 < 0xd8) {
        Envelope_c_vslot_18(param_3,param_2,param_4,local_15c);
        FUN_0003ad36(param_1 + param_4 * 0x1bc + 0xb8f0,param_2,local_15c,0);
        (**(code **)(*param_1 + 0x350))(param_1);
      }
      else if (param_4 < 0xdc) {
        FUN_0004c9a2(param_1,param_2,param_4);
      }
    }
  }
  else {
    if (param_4 != 4) goto joined_r0x000524ed;
    piVar10 = param_1 + 0xcaa81;
    if (param_3 == piVar10) goto LAB_000524b9;
  }
  if ((param_3 == param_1 + 0x23678) &&
     (iVar6 = (param_4 + -0x18) / 0x14, param_4 + -0x18 == iVar6 * 0x14)) {
    iVar6 = FUN_000349ae(param_3,param_2,iVar6);
    iVar6 = *(int *)(iVar6 + 0x22c) / 0x13d;
    if (iVar6 < 2) {
      dVar13 = 1.0;
    }
    else {
      iVar7 = 1;
      do {
        iVar1 = iVar7 * 2;
        iVar2 = iVar7 * -2;
        iVar7 = iVar1;
      } while (iVar6 != iVar1 && SBORROW4(iVar6,iVar1) == iVar6 + iVar2 < 0);
      dVar13 = (double)iVar1;
    }
    lVar12 = (longdouble)_log(dVar13);
    lVar11 = (longdouble)_log(0,0x40000000);
    Envelope_c_vslot_9(piVar10,param_2,0xa1,(int)((double)lVar12 / (double)lVar11 + 0.5));
    (**(code **)(*param_1 + 0x350))(param_1);
    (**(code **)(*param_1 + 700))(param_1);
  }
  local_168 = param_1 + 0x23678;
  piVar5 = param_1 + 0x25ee6;
  if ((param_3 == piVar5) && (iVar6 = (param_4 + -0x18) / 0x14, param_4 + -0x18 == iVar6 * 0x14)) {
    iVar6 = FUN_000349ae(param_3,param_2,iVar6);
    iVar6 = *(int *)(iVar6 + 0x22c) / 0x13d;
    if (iVar6 < 2) {
      dVar13 = 1.0;
    }
    else {
      iVar7 = 1;
      do {
        iVar1 = iVar7 * 2;
        iVar2 = iVar7 * -2;
        iVar7 = iVar1;
      } while (iVar6 != iVar1 && SBORROW4(iVar6,iVar1) == iVar6 + iVar2 < 0);
      dVar13 = (double)iVar1;
    }
    lVar12 = (longdouble)_log(dVar13);
    lVar11 = (longdouble)_log(0,0x40000000);
    Envelope_c_vslot_9(piVar10,param_2,0xa2,(int)((double)lVar12 / (double)lVar11 + 0.5));
    (**(code **)(*param_1 + 0x350))(param_1);
    (**(code **)(*param_1 + 700))(param_1);
  }
  if (((param_3 == local_168) || (param_3 == piVar5)) &&
     (param_4 + -0x13 == ((param_4 + -0x13) / 0x14) * 0x14)) {
    (**(code **)(*param_1 + 0x350))(param_1);
    (**(code **)(*param_1 + 700))(param_1);
  }
  iVar6 = Envelope_c_vslot_12(param_1 + 0x2d,0,2);
  if (iVar6 != 1) {
    Envelope_c_vslot_9(param_1 + 0x2d,0,2,1);
  }
  if (param_4 == -1) {
LAB_00051798:
    uVar8 = Envelope_c_vslot_12(piVar10,param_2,5);
    Envelope_c_vslot_9(param_1 + 0x30480,param_2,2,uVar8);
    if (param_4 == -1) {
LAB_000517e3:
      uVar8 = Envelope_c_vslot_12(piVar10,param_2,0x78);
      Envelope_c_vslot_9(param_1 + 0x3154f,param_2,2,uVar8);
      if (param_4 != -1) goto LAB_00051827;
LAB_00052e9d:
      uVar8 = Envelope_c_vslot_12(param_1 + 0x30480,param_2,3);
      piVar9 = param_1 + 0x3261e;
      Envelope_c_vslot_9(piVar9,param_2,2,uVar8);
      iVar6 = 0;
      do {
        FilterFree_c_vslot_31(piVar9,2);
        iVar6 = iVar6 + 1;
        piVar9 = piVar9 + 0x4e77;
      } while (iVar6 != 0x20);
      if (param_4 == -1) {
LAB_000521cd:
        uVar8 = Envelope_c_vslot_12(param_1 + 0x3154f,param_2,3);
        piVar9 = param_1 + 0x326d5;
        Envelope_c_vslot_9(piVar9,param_2,2,uVar8);
        iVar6 = 0;
        do {
          FilterFree_c_vslot_31(piVar9,2);
          iVar6 = iVar6 + 1;
          piVar9 = piVar9 + 0x4e77;
        } while (iVar6 != 0x20);
        if (param_4 != -1) goto LAB_00052232;
LAB_00052255:
        local_180 = param_1 + 0x30480;
        uVar8 = Envelope_c_vslot_12(local_180,param_2,4);
        piVar9 = param_1 + 0x3261e;
        Envelope_c_vslot_9(piVar9,param_2,3,uVar8);
        iVar6 = 0;
        do {
          FilterFree_c_vslot_31(piVar9,3);
          iVar6 = iVar6 + 1;
          piVar9 = piVar9 + 0x4e77;
        } while (iVar6 != 0x20);
        if (param_4 != -1) goto LAB_00051859;
LAB_000522c3:
        uVar8 = Envelope_c_vslot_12(param_1 + 0x3154f,param_2,4);
        piVar9 = param_1 + 0x326d5;
        Envelope_c_vslot_9(piVar9,param_2,3,uVar8);
        iVar6 = 0;
        do {
          FilterFree_c_vslot_31(piVar9,3);
          iVar6 = iVar6 + 1;
          piVar9 = piVar9 + 0x4e77;
        } while (iVar6 != 0x20);
        if (param_4 != -1) goto LAB_00052328;
LAB_000527de:
        local_180 = param_1 + 0x30480;
        uVar8 = Envelope_c_vslot_12(local_180,param_2,6);
        piVar9 = param_1 + 0x3261e;
        Envelope_c_vslot_9(piVar9,param_2,6,uVar8);
        iVar6 = 0;
        do {
          FilterFree_c_vslot_31(piVar9,6);
          iVar6 = iVar6 + 1;
          piVar9 = piVar9 + 0x4e77;
        } while (iVar6 != 0x20);
        if (param_4 != -1) goto LAB_00051874;
LAB_0005284c:
        uVar8 = Envelope_c_vslot_12(param_1 + 0x3154f,param_2,6);
        piVar9 = param_1 + 0x326d5;
        Envelope_c_vslot_9(piVar9,param_2,6,uVar8);
        iVar6 = 0;
        do {
          FilterFree_c_vslot_31(piVar9,6);
          iVar6 = iVar6 + 1;
          piVar9 = piVar9 + 0x4e77;
        } while (iVar6 != 0x20);
        if (param_4 != -1) goto LAB_000528b1;
      }
      else {
        if (param_4 == 3) goto LAB_00051848;
LAB_00052232:
        if (param_4 == 4) {
          if (param_3 == param_1 + 0x30480) goto LAB_00052255;
          goto LAB_00051863;
        }
LAB_00052328:
        if (param_4 == 6) {
          if (param_3 == param_1 + 0x30480) goto LAB_000527de;
          goto LAB_0005187e;
        }
LAB_000528b1:
        if (param_4 != 0xba) goto LAB_0005188f;
        if (param_3 != piVar10) goto LAB_000515d1;
      }
      lVar12 = (longdouble)Envelope_c_vslot_8(piVar10,param_2,0xba);
      FUN_000627c0(param_1 + param_2 * 0x53fd + 0x28754,0,(float)lVar12);
      if (param_4 != -1) goto LAB_0005188f;
LAB_000518ad:
      lVar12 = (longdouble)Envelope_c_vslot_8(piVar10,param_2,0xbb);
      FUN_000627c0(param_1 + param_2 * 0x53fd + 0x28754,1,(float)lVar12);
      if (param_4 != -1) goto LAB_000525c0;
LAB_00051903:
      lVar12 = (longdouble)Envelope_c_vslot_8(piVar10,param_2,0xbc);
      FUN_000627c0(param_1 + param_2 * 0x53fd + 0x28754,2,(float)lVar12);
      if (param_4 != -1) goto LAB_00052651;
LAB_00051959:
      lVar12 = (longdouble)Envelope_c_vslot_8(piVar10,param_2,0xbd);
      FUN_000627c0(param_1 + param_2 * 0x53fd + 0x28754,3,(float)lVar12);
      if (param_4 != -1) goto LAB_00052daf;
LAB_000519af:
      lVar12 = (longdouble)Envelope_c_vslot_8(piVar10,param_2,0xbe);
      FUN_000627c0(param_1 + param_2 * 0x53fd + 0x28754,4,(float)lVar12);
      if (param_4 != -1) goto LAB_000519ff;
LAB_00051a19:
      lVar12 = (longdouble)Envelope_c_vslot_8(piVar10,param_2,0xbf);
      FUN_000627c0(param_1 + param_2 * 0x53fd + 0x28754,5,(float)lVar12);
      if (param_4 != -1) goto LAB_00051a69;
LAB_00053ca8:
      uVar8 = Envelope_c_vslot_12(param_1 + param_2 * 0x53fd + 0x2a67c,param_2,6);
      Envelope_c_vslot_9(param_1 + param_2 * 0x53fd + 0x2a67c,param_2,3,uVar8);
      if (param_4 == -1) {
LAB_00053c3c:
        uVar8 = Envelope_c_vslot_12(param_1 + param_2 * 0x53fd + 0x2bdca,param_2,6);
        Envelope_c_vslot_9(param_1 + param_2 * 0x53fd + 0x2bdca,param_2,3,uVar8);
        if (param_4 == -1) goto LAB_00053a03;
        if (param_4 == 6) goto LAB_00051ab5;
      }
      else if (param_4 == 6) goto LAB_00051a97;
LAB_00053a53:
      if (param_4 == 0x57) {
LAB_00053a5d:
        if (param_3 == piVar10) goto LAB_00053a6c;
      }
      else {
LAB_00051ad3:
        if (param_4 == 0x65) goto LAB_00053a5d;
      }
LAB_00051add:
      if (param_4 == 0x61) {
        if (param_3 != piVar10) goto LAB_000515d1;
        goto LAB_00053a88;
      }
LAB_00051ae7:
      if (param_4 != 99) goto LAB_000539c1;
      if (param_3 == piVar10) goto LAB_00051b00;
      goto LAB_000515e6;
    }
LAB_000515b8:
    if (param_4 == 0x78) {
      if (param_3 != piVar10) goto LAB_000515d1;
      goto LAB_000517e3;
    }
LAB_00051827:
    if (param_4 != 3) goto LAB_00052232;
    if (param_3 == param_1 + 0x30480) goto LAB_00052e9d;
LAB_00051848:
    if (param_3 == param_1 + 0x3154f) goto LAB_000521cd;
LAB_00051859:
    if (param_4 != 4) goto LAB_00052328;
LAB_00051863:
    if (param_3 == param_1 + 0x3154f) goto LAB_000522c3;
LAB_00051874:
    if (param_4 != 6) goto LAB_000528b1;
LAB_0005187e:
    if (param_3 == param_1 + 0x3154f) goto LAB_0005284c;
LAB_0005188f:
    if (param_4 == 0xbb) {
      if (param_3 != piVar10) goto LAB_000515d1;
      goto LAB_000518ad;
    }
LAB_000525c0:
    if (param_4 == 0xbc) {
      if (param_3 != piVar10) goto LAB_000515d1;
      goto LAB_00051903;
    }
LAB_00052651:
    if (param_4 == 0xbd) {
      if (param_3 != piVar10) goto LAB_000515d1;
      goto LAB_00051959;
    }
LAB_00052daf:
    if (param_4 == 0xbe) {
      if (param_3 != piVar10) goto LAB_000515d1;
      goto LAB_000519af;
    }
LAB_000519ff:
    if (param_4 == 0xbf) {
      if (param_3 != piVar10) goto LAB_000515d1;
      goto LAB_00051a19;
    }
LAB_00051a69:
    if (param_4 != 6) goto LAB_00053a53;
    if (param_3 == param_1 + param_2 * 0x53fd + 0x2a67c) goto LAB_00053ca8;
LAB_00051a97:
    if (param_3 == param_1 + param_2 * 0x53fd + 0x2bdca) goto LAB_00053c3c;
LAB_00051ab5:
    if (param_3 != param_1 + param_2 * 0x53fd + 0x2d518) goto LAB_00051ad3;
LAB_00053a03:
    uVar8 = Envelope_c_vslot_12(param_1 + param_2 * 0x53fd + 0x2d518,param_2,6);
    Envelope_c_vslot_9(param_1 + param_2 * 0x53fd + 0x2d518,param_2,3,uVar8);
    if (param_4 != -1) goto LAB_00053a53;
LAB_00053a6c:
    FUN_00017586(param_1,param_2);
    if (param_4 != -1) goto LAB_00051add;
LAB_00053a88:
    iVar6 = param_2 * 0x14ff4;
    Delay2R_c_vslot_39(param_1 + param_2 * 0x53fd + 0x293d0,param_2);
    DelayStereo_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2a5df,param_2);
    DelayPingPongR_c_vslot_39(FUN_000aaa38 + iVar6 + (int)param_1,param_2);
    Envelope_c_vslot_39(param_1 + param_2 * 0x53fd + 0x29676,param_2);
    Envelope_c_vslot_39(param_1 + param_2 * 0x53fd + 0x29eb9,param_2);
    Envelope_c_vslot_39(&UNK_000a850c + iVar6 + (int)param_1,param_2);
    Reverb2R_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2a3c4,param_2);
    Flanger2R_c_vslot_39(&UNK_000a99f0 + iVar6 + (int)param_1,param_2);
    StereoEnh1_c_vslot_39(&UNK_000a9c2c + iVar6 + (int)param_1,param_2);
    Envelope_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2a78e,param_2);
    Envelope_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2a858,param_2);
    Envelope_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2a8ec,param_2);
    uVar8 = Envelope_c_vslot_12(piVar10,param_2,0x61);
    switch(uVar8) {
    case 0:
      param_1[param_2 * 0x53fd + 0x2db49] = (int)(param_1 + param_2 * 0x53fd + 0x293d0);
      break;
    case 1:
      param_1[param_2 * 0x53fd + 0x2db49] = (int)(param_1 + param_2 * 0x53fd + 0x2a5df);
      break;
    case 2:
      param_1[param_2 * 0x53fd + 0x2db49] = (int)(FUN_000aaa38 + param_2 * 0x14ff4 + (int)param_1);
      break;
    case 3:
      param_1[param_2 * 0x53fd + 0x2db49] = (int)(param_1 + param_2 * 0x53fd + 0x29676);
      break;
    case 4:
      param_1[param_2 * 0x53fd + 0x2db49] = (int)(param_1 + param_2 * 0x53fd + 0x29eb9);
      break;
    case 5:
      param_1[param_2 * 0x53fd + 0x2db49] = (int)(&UNK_000a850c + param_2 * 0x14ff4 + (int)param_1);
      break;
    case 6:
      param_1[param_2 * 0x53fd + 0x2db49] = (int)(param_1 + param_2 * 0x53fd + 0x2a3c4);
      break;
    case 7:
      param_1[param_2 * 0x53fd + 0x2db49] = (int)(&UNK_000a99f0 + param_2 * 0x14ff4 + (int)param_1);
      break;
    case 8:
      param_1[param_2 * 0x53fd + 0x2db49] = (int)(param_1 + param_2 * 0x53fd + 0x2a858);
      break;
    case 9:
      param_1[param_2 * 0x53fd + 0x2db49] = (int)(&UNK_000a9c2c + param_2 * 0x14ff4 + (int)param_1);
      break;
    case 10:
      param_1[param_2 * 0x53fd + 0x2db49] = (int)(param_1 + param_2 * 0x53fd + 0x2a78e);
      break;
    case 0xb:
      param_1[param_2 * 0x53fd + 0x2db49] = (int)(param_1 + param_2 * 0x53fd + 0x2a8ec);
    }
    (**(code **)(*(int *)param_1[param_2 * 0x53fd + 0x2db49] + 0x98))
              ((int *)param_1[param_2 * 0x53fd + 0x2db49],param_2);
    if (param_4 != -1) goto LAB_00051ae7;
LAB_00051b00:
    Delay2R_c_vslot_39(&UNK_000aac78 + param_2 * 0x14ff4 + (int)param_1,param_2);
    DelayStereo_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2bd2d,param_2);
    DelayPingPongR_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2c1dc,param_2);
    Envelope_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2adc4,param_2);
    Envelope_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2b607,param_2);
    Envelope_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2b891,param_2);
    Reverb2R_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2bb12,param_2);
    Flanger2R_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2bdca,param_2);
    StereoEnh1_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2be59,param_2);
    Envelope_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2bedc,param_2);
    Envelope_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2bfa6,param_2);
    Envelope_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2c03a,param_2);
    uVar8 = Envelope_c_vslot_12(piVar10,param_2,99);
    switch(uVar8) {
    case 0:
      param_1[param_2 * 0x53fd + 0x2db4a] = (int)(&UNK_000aac78 + param_2 * 0x14ff4 + (int)param_1);
      break;
    case 1:
      param_1[param_2 * 0x53fd + 0x2db4a] = (int)(param_1 + param_2 * 0x53fd + 0x2bd2d);
      break;
    case 2:
      param_1[param_2 * 0x53fd + 0x2db4a] = (int)(param_1 + param_2 * 0x53fd + 0x2c1dc);
      break;
    case 3:
      param_1[param_2 * 0x53fd + 0x2db4a] = (int)(param_1 + param_2 * 0x53fd + 0x2adc4);
      break;
    case 4:
      param_1[param_2 * 0x53fd + 0x2db4a] = (int)(param_1 + param_2 * 0x53fd + 0x2b607);
      break;
    case 5:
      param_1[param_2 * 0x53fd + 0x2db4a] = (int)(param_1 + param_2 * 0x53fd + 0x2b891);
      break;
    case 6:
      param_1[param_2 * 0x53fd + 0x2db4a] = (int)(param_1 + param_2 * 0x53fd + 0x2bb12);
      break;
    case 7:
      param_1[param_2 * 0x53fd + 0x2db4a] = (int)(param_1 + param_2 * 0x53fd + 0x2bdca);
      break;
    case 8:
      param_1[param_2 * 0x53fd + 0x2db4a] = (int)(param_1 + param_2 * 0x53fd + 0x2bfa6);
      break;
    case 9:
      param_1[param_2 * 0x53fd + 0x2db4a] = (int)(param_1 + param_2 * 0x53fd + 0x2be59);
      break;
    case 10:
      param_1[param_2 * 0x53fd + 0x2db4a] = (int)(param_1 + param_2 * 0x53fd + 0x2bedc);
      break;
    case 0xb:
      param_1[param_2 * 0x53fd + 0x2db4a] = (int)(param_1 + param_2 * 0x53fd + 0x2c03a);
    }
    (**(code **)(*(int *)param_1[param_2 * 0x53fd + 0x2db49] + 0x98))
              ((int *)param_1[param_2 * 0x53fd + 0x2db49],param_2);
LAB_000539c1:
    if (param_4 == -1) goto LAB_000528e2;
    if (param_4 == 0x6c) {
      if (param_3 == piVar10) {
        uVar8 = 0;
        goto LAB_000528e7;
      }
      goto LAB_000515e6;
    }
    if (param_4 == 0x6e) {
      if (param_3 == piVar10) {
        uVar8 = 1;
        goto LAB_000528e7;
      }
      goto LAB_000515e6;
    }
    if (param_4 != 0x70) goto LAB_000515d1;
    if (param_3 == piVar10) {
      uVar8 = 2;
      goto LAB_000528e7;
    }
LAB_000527c9:
    if (param_4 == 5) {
LAB_00052362:
      if (param_3 == param_1 + 0x2e1b5) {
        iVar6 = param_2 << 2;
        bVar3 = false;
LAB_00052067:
        if (*(int *)(iVar6 + param_1[0x33a9]) != 0) {
          iVar7 = Envelope_c_vslot_12(piVar10,param_2,0x96);
          if (bVar3) {
            iVar1 = *(int *)(iVar6 + param_1[0x33a9]);
            *(undefined4 *)(iVar1 + 0x168) = 0;
            *(undefined4 *)(iVar1 + 0x16c) = 0;
          }
          iVar1 = *(int *)(iVar6 + param_1[0x33a9]);
          dVar13 = 0.0;
          if (iVar7 != 0) {
            lVar12 = (longdouble)LFOSimp_c_vslot_58(param_1 + 0x2e234,param_2);
            dVar13 = (double)lVar12 * 0.125;
          }
          *(double *)(iVar1 + 0x188) = dVar13;
        }
        if (param_4 != -1) goto LAB_000520e2;
LAB_00052104:
        bVar3 = true;
LAB_00052109:
        if (*(int *)(iVar6 + param_1[0x33a9]) != 0) {
          iVar7 = Envelope_c_vslot_12(piVar10,param_2,0x97);
          if (bVar3) {
            iVar1 = *(int *)(iVar6 + param_1[0x33a9]);
            *(undefined4 *)(iVar1 + 0x170) = 0;
            *(undefined4 *)(iVar1 + 0x174) = 0;
          }
          iVar1 = *(int *)(iVar6 + param_1[0x33a9]);
          dVar13 = 0.0;
          if (iVar7 != 0) {
            lVar12 = (longdouble)LFOSimp_c_vslot_58(param_1 + 0x2e584,param_2);
            dVar13 = (double)lVar12 * 0.125;
          }
          *(double *)(iVar1 + 400) = dVar13;
        }
        if (param_4 != -1) goto LAB_00052184;
LAB_000521a6:
        bVar3 = true;
      }
      else {
LAB_00052373:
        if (param_3 == param_1 + 0x2e505) {
          iVar6 = param_2 << 2;
          bVar3 = false;
          goto LAB_00052109;
        }
LAB_00052384:
        if (param_3 != param_1 + 0x2e855) goto LAB_0005162d;
        iVar6 = param_2 << 2;
        bVar3 = false;
      }
      if (*(int *)(iVar6 + param_1[0x33a9]) != 0) {
        iVar7 = Envelope_c_vslot_12(piVar10,param_2,0x98);
        if (bVar3) {
          iVar1 = *(int *)(iVar6 + param_1[0x33a9]);
          *(undefined4 *)(iVar1 + 0x178) = 0;
          *(undefined4 *)(iVar1 + 0x17c) = 0;
        }
        iVar6 = *(int *)(iVar6 + param_1[0x33a9]);
        dVar13 = 0.0;
        if (iVar7 != 0) {
          lVar12 = (longdouble)LFOSimp_c_vslot_58(param_1 + 0x2e8d4,param_2);
          dVar13 = (double)lVar12 * 0.125;
        }
        *(double *)(iVar6 + 0x198) = dVar13;
      }
      if (param_4 != -1) {
LAB_00052400:
        if ((param_4 != 0x60) || (param_3 != piVar10)) goto LAB_0005162d;
      }
      iVar6 = FUN_00012888(piVar10,param_2);
      if (iVar6 == 0) {
        return;
      }
      iVar7 = *(int *)(LPAUSynth_vslot_7 + iVar6 + 2);
      cVar4 = FUN_00010462(iVar6 + 0x2a00);
      if (cVar4 == '\0') {
        (**(code **)(param_1[param_2 * 0x53fd + 0x28754] + 0x7c))
                  (param_1 + param_2 * 0x53fd + 0x28754,iVar7);
      }
      else {
        (**(code **)(param_1[param_2 * 0x53fd + 0x28754] + 0x7c))
                  (param_1 + param_2 * 0x53fd + 0x28754,0x20);
      }
      *(bool *)(param_1 + param_2 * 0x53fd + 0x287aa) = iVar7 == 1;
    }
    else {
LAB_000520e2:
      if (param_4 == 0x97) {
        if (param_3 == piVar10) {
          iVar6 = param_2 << 2;
          goto LAB_00052104;
        }
        goto LAB_0005162d;
      }
      if ((param_4 == 3) || (param_4 == 5)) goto LAB_00052373;
LAB_00052184:
      if (param_4 != 0x98) {
        if ((param_4 == 3) || (param_4 == 5)) goto LAB_00052384;
        goto LAB_00052400;
      }
      if (param_3 == piVar10) {
        iVar6 = param_2 << 2;
        goto LAB_000521a6;
      }
    }
  }
  else {
    if (param_4 != 5) goto LAB_000515b8;
    if (param_3 == piVar10) goto LAB_00051798;
LAB_000515d1:
    if ((param_4 == 0x72) && (param_3 == piVar10)) {
LAB_000528e2:
      uVar8 = 3;
LAB_000528e7:
      FUN_0004b81e(param_1,param_2,uVar8);
      Delay2R_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2c26c,param_2);
      DelayStereo_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2d47b,param_2);
      DelayPingPongR_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2d92a,param_2);
      Envelope_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2c512,param_2);
      Envelope_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2cd55,param_2);
      Envelope_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2cfdf,param_2);
      Reverb2R_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2d260,param_2);
      Flanger2R_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2d518,param_2);
      StereoEnh1_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2d5a7,param_2);
      Envelope_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2d62a,param_2);
      Envelope_c_vslot_39(&UNK_000b5bd0 + param_2 * 0x14ff4 + (int)param_1,param_2);
      Envelope_c_vslot_39(param_1 + param_2 * 0x53fd + 0x2d788,param_2);
      uVar8 = Envelope_c_vslot_12(piVar10,param_2,0x6c);
      switch(uVar8) {
      case 0:
        param_1[param_2 * 0x53fd + 0x2db4b] = (int)(param_1 + param_2 * 0x53fd + 0x2c26c);
        break;
      case 1:
        param_1[param_2 * 0x53fd + 0x2db4b] = (int)(param_1 + param_2 * 0x53fd + 0x2d47b);
        break;
      case 2:
        param_1[param_2 * 0x53fd + 0x2db4b] = (int)(param_1 + param_2 * 0x53fd + 0x2d92a);
        break;
      case 3:
        param_1[param_2 * 0x53fd + 0x2db4b] = (int)(param_1 + param_2 * 0x53fd + 0x2c512);
        break;
      case 4:
        param_1[param_2 * 0x53fd + 0x2db4b] = (int)(param_1 + param_2 * 0x53fd + 0x2cd55);
        break;
      case 5:
        param_1[param_2 * 0x53fd + 0x2db4b] = (int)(param_1 + param_2 * 0x53fd + 0x2cfdf);
        break;
      case 6:
        param_1[param_2 * 0x53fd + 0x2db4b] = (int)(param_1 + param_2 * 0x53fd + 0x2d260);
        break;
      case 7:
        param_1[param_2 * 0x53fd + 0x2db4b] = (int)(param_1 + param_2 * 0x53fd + 0x2d518);
        break;
      case 8:
        param_1[param_2 * 0x53fd + 0x2db4b] =
             (int)(&UNK_000b5bd0 + param_2 * 0x14ff4 + (int)param_1);
        break;
      case 9:
        param_1[param_2 * 0x53fd + 0x2db4b] = (int)(param_1 + param_2 * 0x53fd + 0x2d5a7);
        break;
      case 10:
        param_1[param_2 * 0x53fd + 0x2db4b] = (int)(param_1 + param_2 * 0x53fd + 0x2d62a);
        break;
      case 0xb:
        param_1[param_2 * 0x53fd + 0x2db4b] = (int)(param_1 + param_2 * 0x53fd + 0x2d788);
      }
      uVar8 = Envelope_c_vslot_12(piVar10,param_2,0x6e);
      switch(uVar8) {
      case 0:
        param_1[param_2 * 0x53fd + 0x2db4c] = (int)(param_1 + param_2 * 0x53fd + 0x2c26c);
        break;
      case 1:
        param_1[param_2 * 0x53fd + 0x2db4c] = (int)(param_1 + param_2 * 0x53fd + 0x2d47b);
        break;
      case 2:
        param_1[param_2 * 0x53fd + 0x2db4c] = (int)(param_1 + param_2 * 0x53fd + 0x2d92a);
        break;
      case 3:
        param_1[param_2 * 0x53fd + 0x2db4c] = (int)(param_1 + param_2 * 0x53fd + 0x2c512);
        break;
      case 4:
        param_1[param_2 * 0x53fd + 0x2db4c] = (int)(param_1 + param_2 * 0x53fd + 0x2cd55);
        break;
      case 5:
        param_1[param_2 * 0x53fd + 0x2db4c] = (int)(param_1 + param_2 * 0x53fd + 0x2cfdf);
        break;
      case 6:
        param_1[param_2 * 0x53fd + 0x2db4c] = (int)(param_1 + param_2 * 0x53fd + 0x2d260);
        break;
      case 7:
        param_1[param_2 * 0x53fd + 0x2db4c] = (int)(param_1 + param_2 * 0x53fd + 0x2d518);
        break;
      case 8:
        param_1[param_2 * 0x53fd + 0x2db4c] =
             (int)(&UNK_000b5bd0 + param_2 * 0x14ff4 + (int)param_1);
        break;
      case 9:
        param_1[param_2 * 0x53fd + 0x2db4c] = (int)(param_1 + param_2 * 0x53fd + 0x2d5a7);
        break;
      case 10:
        param_1[param_2 * 0x53fd + 0x2db4c] = (int)(param_1 + param_2 * 0x53fd + 0x2d62a);
        break;
      case 0xb:
        param_1[param_2 * 0x53fd + 0x2db4c] = (int)(param_1 + param_2 * 0x53fd + 0x2d788);
      }
      uVar8 = Envelope_c_vslot_12(piVar10,param_2,0x70);
      switch(uVar8) {
      case 0:
        param_1[param_2 * 0x53fd + 0x2db4d] = (int)(param_1 + param_2 * 0x53fd + 0x2c26c);
        break;
      case 1:
        param_1[param_2 * 0x53fd + 0x2db4d] = (int)(param_1 + param_2 * 0x53fd + 0x2d47b);
        break;
      case 2:
        param_1[param_2 * 0x53fd + 0x2db4d] = (int)(param_1 + param_2 * 0x53fd + 0x2d92a);
        break;
      case 3:
        param_1[param_2 * 0x53fd + 0x2db4d] = (int)(param_1 + param_2 * 0x53fd + 0x2c512);
        break;
      case 4:
        param_1[param_2 * 0x53fd + 0x2db4d] = (int)(param_1 + param_2 * 0x53fd + 0x2cd55);
        break;
      case 5:
        param_1[param_2 * 0x53fd + 0x2db4d] = (int)(param_1 + param_2 * 0x53fd + 0x2cfdf);
        break;
      case 6:
        param_1[param_2 * 0x53fd + 0x2db4d] = (int)(param_1 + param_2 * 0x53fd + 0x2d260);
        break;
      case 7:
        param_1[param_2 * 0x53fd + 0x2db4d] = (int)(param_1 + param_2 * 0x53fd + 0x2d518);
        break;
      case 8:
        param_1[param_2 * 0x53fd + 0x2db4d] =
             (int)(&UNK_000b5bd0 + param_2 * 0x14ff4 + (int)param_1);
        break;
      case 9:
        param_1[param_2 * 0x53fd + 0x2db4d] = (int)(param_1 + param_2 * 0x53fd + 0x2d5a7);
        break;
      case 10:
        param_1[param_2 * 0x53fd + 0x2db4d] = (int)(param_1 + param_2 * 0x53fd + 0x2d62a);
        break;
      case 0xb:
        param_1[param_2 * 0x53fd + 0x2db4d] = (int)(param_1 + param_2 * 0x53fd + 0x2d788);
      }
      uVar8 = Envelope_c_vslot_12(piVar10,param_2,0x72);
      switch(uVar8) {
      case 0:
        param_1[param_2 * 0x53fd + 0x2db4e] = (int)(param_1 + param_2 * 0x53fd + 0x2c26c);
        break;
      case 1:
        param_1[param_2 * 0x53fd + 0x2db4e] = (int)(param_1 + param_2 * 0x53fd + 0x2d47b);
        break;
      case 2:
        param_1[param_2 * 0x53fd + 0x2db4e] = (int)(param_1 + param_2 * 0x53fd + 0x2d92a);
        break;
      case 3:
        param_1[param_2 * 0x53fd + 0x2db4e] = (int)(param_1 + param_2 * 0x53fd + 0x2c512);
        break;
      case 4:
        param_1[param_2 * 0x53fd + 0x2db4e] = (int)(param_1 + param_2 * 0x53fd + 0x2cd55);
        break;
      case 5:
        param_1[param_2 * 0x53fd + 0x2db4e] = (int)(param_1 + param_2 * 0x53fd + 0x2cfdf);
        break;
      case 6:
        param_1[param_2 * 0x53fd + 0x2db4e] = (int)(param_1 + param_2 * 0x53fd + 0x2d260);
        break;
      case 7:
        param_1[param_2 * 0x53fd + 0x2db4e] = (int)(param_1 + param_2 * 0x53fd + 0x2d518);
        break;
      case 8:
        param_1[param_2 * 0x53fd + 0x2db4e] =
             (int)(&UNK_000b5bd0 + param_2 * 0x14ff4 + (int)param_1);
        break;
      case 9:
        param_1[param_2 * 0x53fd + 0x2db4e] = (int)(param_1 + param_2 * 0x53fd + 0x2d5a7);
        break;
      case 10:
        param_1[param_2 * 0x53fd + 0x2db4e] = (int)(param_1 + param_2 * 0x53fd + 0x2d62a);
        break;
      case 0xb:
        param_1[param_2 * 0x53fd + 0x2db4e] = (int)(param_1 + param_2 * 0x53fd + 0x2d788);
      }
      (**(code **)(*(int *)param_1[param_2 * 0x53fd + 0x2db4b] + 0x98))
                ((int *)param_1[param_2 * 0x53fd + 0x2db4b],param_2);
      (**(code **)(*(int *)param_1[param_2 * 0x53fd + 0x2db4c] + 0x98))
                ((int *)param_1[param_2 * 0x53fd + 0x2db4c],param_2);
      (**(code **)(*(int *)param_1[param_2 * 0x53fd + 0x2db4d] + 0x98))
                ((int *)param_1[param_2 * 0x53fd + 0x2db4d],param_2);
      (**(code **)(*(int *)param_1[param_2 * 0x53fd + 0x2db4e] + 0x98))
                ((int *)param_1[param_2 * 0x53fd + 0x2db4e],param_2);
      lVar12 = (longdouble)Envelope_c_vslot_8(piVar10,param_2,0xbc);
      piVar9 = param_1 + param_2 * 0x53fd + 0x28754;
      FUN_000627c0(piVar9,2,(float)lVar12);
      lVar12 = (longdouble)Envelope_c_vslot_8(piVar10,param_2,0xbd);
      FUN_000627c0(piVar9,3,(float)lVar12);
      lVar12 = (longdouble)Envelope_c_vslot_8(piVar10,param_2,0xbe);
      FUN_000627c0(piVar9,4,(float)lVar12);
      lVar12 = (longdouble)Envelope_c_vslot_8(piVar10,param_2,0xbf);
      FUN_000627c0(piVar9,5,(float)lVar12);
    }
LAB_000515e6:
    if (param_4 != -1) {
      if (param_4 != 0x95) {
        if ((param_4 != 3) && (param_4 != 5)) goto LAB_00051611;
        if (param_3 == param_1 + 0x2de65) {
          bVar3 = false;
          goto LAB_00051ff9;
        }
        goto LAB_00052362;
      }
      if (param_3 == piVar10) goto LAB_00051ff4;
      goto LAB_000520e2;
    }
LAB_00051ff4:
    bVar3 = true;
LAB_00051ff9:
    iVar6 = param_2 * 4;
    if (*(int *)(param_1[0x33a9] + iVar6) != 0) {
      iVar7 = Envelope_c_vslot_12(piVar10,param_2,0x95);
      if (bVar3) {
        iVar1 = *(int *)(iVar6 + param_1[0x33a9]);
        *(undefined4 *)(iVar1 + 0x160) = 0;
        *(undefined4 *)(iVar1 + 0x164) = 0;
        iVar1 = *(int *)(iVar6 + param_1[0x33a9]);
      }
      else {
        iVar1 = *(int *)(iVar6 + param_1[0x33a9]);
      }
      dVar13 = 0.0;
      if (iVar7 != 0) {
        lVar12 = (longdouble)LFOSimp_c_vslot_58(param_1 + 0x2dee4,param_2);
        dVar13 = (double)lVar12 * 0.125;
      }
      *(double *)(iVar1 + 0x180) = dVar13;
    }
    if (param_4 == -1) {
LAB_00052062:
      bVar3 = true;
      goto LAB_00052067;
    }
LAB_00051611:
    if (param_4 != 0x96) {
      if (param_4 != 3) goto LAB_000527c9;
      goto LAB_00052362;
    }
    if (param_3 == piVar10) {
      iVar6 = param_2 << 2;
      goto LAB_00052062;
    }
  }
LAB_0005162d:
  iVar6 = 0;
  piVar9 = param_1 + 0x228a0;
  if (param_4 == -1) {
    do {
      (**(code **)(*param_1 + 0x348))(param_1,piVar9,3,param_2,0);
      (**(code **)(*param_1 + 0x348))(param_1,piVar9,0xc,param_2,0);
      (**(code **)(*param_1 + 0x348))(param_1,piVar9,6,param_2,0);
      iVar6 = iVar6 + 1;
      piVar9 = piVar9 + 0x1bc;
    } while (iVar6 != 4);
  }
  else if (param_4 == 0xe) {
    do {
      if (param_3 == piVar9) {
        (**(code **)(*param_1 + 0x348))(param_1,piVar9,3,param_2,0);
        (**(code **)(*param_1 + 0x348))(param_1,piVar9,0xc,param_2,0);
        (**(code **)(*param_1 + 0x348))(param_1,piVar9,6,param_2,0);
      }
      iVar6 = iVar6 + 1;
      piVar9 = piVar9 + 0x1bc;
    } while (iVar6 != 4);
  }
  else {
    do {
      iVar6 = iVar6 + 1;
    } while (iVar6 != 4);
  }
  if (param_4 == -1) {
    iVar6 = 0;
    piVar9 = param_1 + 0x23678;
    do {
      (**(code **)(*param_1 + 0x348))(param_1,piVar9,9,param_2,0);
      iVar6 = iVar6 + 1;
      piVar9 = piVar9 + 0x286e;
    } while (iVar6 != 2);
LAB_00051cfe:
    iVar7 = FUN_0001d28c(param_1,0x3a6);
    iVar6 = FUN_0001d28c(param_1,0x3a8);
    iVar6 = iVar6 + iVar7 * 8;
    if (iVar6 < 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = 0x3f;
      if (iVar6 < 0x40) {
        iVar7 = iVar6;
      }
    }
    param_1[0xcac1a] = iVar7;
    FUN_0004caa2(param_1,param_2,0);
    iVar7 = FUN_000349ae(local_168,param_2,param_1[0xcac1a]);
    param_1[0xcac1c] = iVar7;
    (**(code **)(*param_1 + 0x350))(param_1);
    FUN_0001d1ca(param_1,0x3aa,iVar6);
    (**(code **)(*param_1 + 0x350))(param_1);
    if (param_4 != -1) goto joined_r0x000516a6;
LAB_00051dc1:
    iVar7 = FUN_0001d28c(param_1,0x3a7);
    iVar6 = FUN_0001d28c(param_1,0x3a9);
    iVar6 = iVar6 + iVar7 * 8;
    if (iVar6 < 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = 0x3f;
      if (iVar6 < 0x40) {
        iVar7 = iVar6;
      }
    }
    param_1[0xcac1b] = iVar7;
    FUN_0004caa2(param_1,param_2,1);
    iVar7 = FUN_000349ae(piVar5,param_2,param_1[0xcac1b]);
    param_1[0xcac1d] = iVar7;
    (**(code **)(*param_1 + 0x350))(param_1);
    FUN_0001d1ca(param_1,0x3ab,iVar6);
    (**(code **)(*param_1 + 0x350))(param_1);
    if (param_4 != -1) goto LAB_000516ac;
LAB_00051e84:
    FUN_0004caa2(param_1,param_2,0);
    (**(code **)(*param_1 + 0x350))(param_1);
    if (param_4 != -1) goto LAB_000516b9;
LAB_00051eb6:
    FUN_0004caa2(param_1,param_2,1);
    (**(code **)(*param_1 + 0x350))(param_1);
    if (param_4 != -1) goto LAB_00051ee8;
LAB_000526a6:
    (**(code **)(*param_1 + 0x350))(param_1);
  }
  else {
    if (param_4 == 0x18) {
      iVar6 = 0;
      piVar9 = param_1 + 0x23678;
      do {
        if (param_3 == piVar9) {
          (**(code **)(*param_1 + 0x348))(param_1,param_3,9,param_2,0);
        }
        iVar6 = iVar6 + 1;
        piVar9 = piVar9 + 0x286e;
      } while (iVar6 != 2);
    }
    else {
      iVar6 = 0;
      do {
        iVar6 = iVar6 + 1;
      } while (iVar6 != 2);
    }
    if ((param_4 - 0x9bU < 2) && (param_3 == piVar10)) goto LAB_00051cfe;
joined_r0x000516a6:
    if ((param_4 - 0x9eU < 2) && (param_3 == piVar10)) goto LAB_00051dc1;
LAB_000516ac:
    if (param_4 == 0xa1) {
      if (param_3 != piVar10) goto LAB_000516d5;
      goto LAB_00051e84;
    }
LAB_000516b9:
    if (param_4 == 0xa2) {
      if (param_3 != piVar10) goto LAB_000516d5;
      goto LAB_00051eb6;
    }
LAB_00051ee8:
    if ((param_4 == 4) && (param_3 == param_1 + 0xdb0)) goto LAB_000526a6;
  }
  if (param_3 == piVar10) {
    if (param_4 == 0x7b) {
      Envelope_c_vslot_18(param_3,param_2,0x7b,local_15c);
      FUN_0004d9b4(param_1,param_2,0,local_15c);
    }
    else if (param_4 == 0x7c) {
      Envelope_c_vslot_18(param_3,param_2,0x7c,local_15c);
      FUN_0004d9b4(param_1,param_2,1,local_15c);
    }
  }
LAB_000516d5:
  FUN_0004c384(param_1,param_2,param_3,param_4);
  return;
}

