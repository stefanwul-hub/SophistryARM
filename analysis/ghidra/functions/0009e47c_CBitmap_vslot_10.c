/* 0009e47c CBitmap_vslot_10 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

uint CBitmap_vslot_10(int *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  size_t sVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  (**(code **)(*param_1 + 0x20))(param_1);
  iVar1 = _CGDataProviderCreateWithURL(param_2);
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = _CGImageCreateWithPNGDataProvider(iVar1,0,0,0);
  if (uVar2 == 0) {
    uVar8 = 0;
    goto LAB_0009e686;
  }
  iVar3 = _CGImageGetWidth(uVar2);
  param_1[3] = iVar3;
  iVar3 = _CGImageGetHeight(uVar2);
  param_1[4] = iVar3;
  iVar3 = _CGColorSpaceCreateDeviceRGB();
  uVar8 = (uint)(param_1[3] << 5) >> 3;
  if (iVar3 == 0) {
    uVar8 = 0;
  }
  else {
    sVar4 = uVar8 * param_1[4];
    pvVar5 = _malloc(sVar4);
    _memset(pvVar5,0,sVar4);
    iVar6 = _CGBitmapContextCreate(pvVar5,param_1[3],param_1[4],8,uVar8,iVar3,2);
    if (iVar6 == 0) {
LAB_0009e6a8:
      uVar8 = 0;
    }
    else {
      _CGContextDrawImage(iVar6,0,0,(float)param_1[3],(float)param_1[4],uVar2);
      _CGContextRelease(iVar6);
      iVar6 = _CGDataProviderCreateWithData(0,pvVar5,sVar4,FUN_0009dbe6);
      if (iVar6 == 0) goto LAB_0009e6a8;
      uVar7 = _CGImageCreate(param_1[3],param_1[4],8,0x20,uVar8,iVar3,2,iVar6,0,1,0);
      uVar8 = uVar7;
      if (uVar7 != 0) {
        _CGImageRelease(uVar2);
        uVar8 = 1;
        uVar2 = uVar7;
      }
      _CGDataProviderRelease(iVar6);
    }
    _CGColorSpaceRelease(iVar3);
  }
  param_1[9] = uVar2;
LAB_0009e686:
  _CGDataProviderRelease(iVar1);
  return uVar8 & 0xff;
}

