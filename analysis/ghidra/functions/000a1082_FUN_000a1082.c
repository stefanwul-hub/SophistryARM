/* 000a1082 FUN_000a1082 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000a1082(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  int local_24;
  undefined1 local_20 [2];
  byte local_1e;
  
  param_1[1] = 1;
  *param_1 = &PTR_CDrawContext_vslot_0_000f4008;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = param_3;
  param_1[7] = param_4;
  param_1[8] = param_2;
  param_1[9] = 0xffffffff;
  param_1[10] = 0;
  param_1[0xb] = 8;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x12] = 1;
  param_1[0x13] = 3;
  piVar1 = param_1 + 0x14;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  piVar2 = (int *)param_1[8];
  if (piVar2 == (int *)0x0) {
    param_1[0x14] = 0;
    param_1[0x16] = 1000;
    param_1[0x15] = 0;
    param_1[0x17] = 1000;
  }
  else {
    (**(code **)(*piVar2 + 0x78))(piVar2,piVar1);
  }
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined1 *)((int)param_1 + 0x41) = 0;
  *(undefined1 *)((int)param_1 + 0x42) = 0;
  *(undefined1 *)((int)param_1 + 0x43) = 0;
  *(undefined1 *)(param_1 + 0x11) = 0;
  *(undefined1 *)((int)param_1 + 0x45) = 0;
  *(undefined1 *)((int)param_1 + 0x46) = 0;
  *(undefined1 *)((int)param_1 + 0x47) = 0;
  *(undefined1 *)(param_1 + 0xc) = 0;
  *(undefined1 *)((int)param_1 + 0x31) = 0;
  *(undefined1 *)((int)param_1 + 0x32) = 0;
  *(undefined1 *)((int)param_1 + 0x33) = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  if ((param_1[8] != 0) && ((param_1[6] != 0 || (param_1[7] != 0)))) {
    _HIViewGetFrame(*(undefined4 *)(param_1[8] + 0x7c),&local_34);
    if ((param_1[7] == 0) && (param_1[6] != 0)) {
      param_1[2] = (int)local_34;
      param_1[3] = (int)local_30;
      iVar8 = (int)local_28;
      iVar5 = (int)local_2c;
      if (0 < iVar5) goto LAB_000a1217;
LAB_000a144d:
      *piVar1 = iVar5;
      param_1[0x16] = 0;
      if (0 < iVar8) goto LAB_000a122b;
LAB_000a1461:
      param_1[0x15] = iVar8;
      param_1[0x17] = 0;
    }
    else {
      _GetWindowAttributes(param_1[7],local_20);
      if ((local_1e & 8) != 0) {
        uVar6 = *(undefined4 *)PTR_0010389c;
        uVar3 = *(undefined4 *)(PTR_0010389c + 4);
        uVar7 = _HIViewGetRoot(param_1[7]);
        _HIViewFindByID(uVar7,uVar6,uVar3,&local_24);
        iVar5 = _HIViewGetSuperview(*(undefined4 *)(param_1[8] + 0x7c));
        if (iVar5 != local_24) {
          _HIViewConvertRect(&local_34,*(undefined4 *)(param_1[8] + 0x7c),local_24);
        }
        local_34 = (float)*(int *)(param_1[8] + 0x8c) + local_34;
        local_30 = (float)*(int *)(param_1[8] + 0x90) + local_30;
      }
      param_1[2] = (int)local_34;
      param_1[3] = (int)local_30;
      iVar8 = (int)local_28;
      iVar5 = (int)local_2c;
      if (iVar5 < 1) goto LAB_000a144d;
LAB_000a1217:
      *piVar1 = 0;
      param_1[0x16] = iVar5;
      if (iVar8 < 1) goto LAB_000a1461;
LAB_000a122b:
      param_1[0x15] = 0;
      param_1[0x17] = iVar8;
    }
    iVar5 = *(int *)(param_1[8] + 0x90);
    iVar8 = *(int *)(param_1[8] + 0x8c);
    *piVar1 = *piVar1 + iVar8;
    param_1[0x16] = param_1[0x16] + iVar8;
    param_1[0x15] = param_1[0x15] + iVar5;
    param_1[0x17] = param_1[0x17] + iVar5;
  }
  param_1[0x18] = 0;
  iVar5 = param_1[6];
  if (iVar5 == 0) {
    if (param_1[7] == 0) goto LAB_000a12f1;
    uVar6 = _GetWindowPort(param_1[7]);
    iVar5 = _QDBeginCGContext(uVar6,param_1 + 0x18);
    if (iVar5 != 0) goto LAB_000a12f1;
    _CGContextSaveGState(param_1[0x18]);
    _SyncCGContextOriginWithPort(param_1[0x18],uVar6);
    _GetPortBounds(uVar6,&local_34);
    _CGContextTranslateCTM(param_1[0x18],0,(float)((int)local_30._0_2_ - (int)local_34._0_2_));
    _CGContextTranslateCTM(param_1[0x18],(float)(int)param_1[2],(float)(int)-param_1[3]);
    _CGContextTranslateCTM
              (param_1[0x18],(float)-*(int *)(param_1[8] + 0x8c),(float)*(int *)(param_1[8] + 0x90))
    ;
    _CGContextSetShouldAntialias(param_1[0x18],0);
    _CGContextSetFillColorSpace(param_1[0x18],DAT_000fd500);
    _CGContextSetStrokeColorSpace(param_1[0x18],DAT_000fd500);
    _CGContextScaleCTM(param_1[0x18],0x3f800000,0xbf800000);
    _CGContextClipToRect
              (param_1[0x18],(float)*piVar1,(float)(int)param_1[0x15],
               (float)(param_1[0x16] - *piVar1),(float)(int)(param_1[0x17] - param_1[0x15]));
    _CGContextScaleCTM(param_1[0x18],0x3f800000,0xbf800000);
    _CGContextSaveGState(param_1[0x18]);
  }
  else {
    param_1[0x18] = iVar5;
    _CGContextSaveGState(iVar5);
    _CGContextScaleCTM(param_1[0x18],0x3f800000,0xbf800000);
    _CGContextSetShouldAntialias(param_1[0x18],0);
    _CGContextSetFillColorSpace(param_1[0x18],DAT_000fd500);
    _CGContextSetStrokeColorSpace(param_1[0x18],DAT_000fd500);
    _CGContextSaveGState(param_1[0x18]);
  }
  FUN_000a08c2(param_1,piVar1);
  if (param_1[8] != 0) {
    *(undefined4 **)(param_1[8] + 0x94) = param_1;
  }
LAB_000a12f1:
  if (param_1[0x18] != 0) {
    _CGContextSetTextMatrix(param_1[0x18],0x3f800000,0,0,0xbf800000,0,0);
  }
  *(undefined1 *)(param_1 + 0x19) = 0;
  FUN_0009f51a(param_1,_DAT_000e20c4);
  if (param_1[0x12] != 0) {
    param_1[0x12] = 0;
  }
  if (param_1[0xf] != 1) {
    param_1[0xf] = 1;
    if (param_1[0x18] != 0) {
      _CGContextSetLineWidth(param_1[0x18],0x3f800000);
    }
  }
  FUN_0009e6ec(param_1,_DAT_000e20c8);
  uVar6 = _DAT_000e20c4;
  uVar4 = (uint)_DAT_000e20c4 >> 8;
  *(char *)(param_1 + 0xc) = (char)_DAT_000e20c4;
  *(char *)((int)param_1 + 0x31) = (char)uVar4;
  *(char *)((int)param_1 + 0x32) = (char)((uint)uVar6 >> 0x10);
  *(char *)((int)param_1 + 0x33) = (char)((uint)uVar6 >> 0x18);
  FUN_0009ca22(param_1,0,0,0);
  if (param_1[0x13] != 0) {
    param_1[0x13] = 0;
    if (param_1[0x18] != 0) {
      _CGContextSetShouldAntialias(param_1[0x18],0);
    }
  }
  return;
}

