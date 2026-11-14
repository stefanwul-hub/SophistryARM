/* 000a2030 FUN_000a2030 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000a2030(undefined4 *param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5)

{
  void *pvVar1;
  size_t sVar2;
  float fVar3;
  int local_68;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  float local_24;
  float local_20;
  
  FUN_000a1082(param_1,param_2,0,0);
  *param_1 = &PTR_COffscreenContext_vslot_0_000f4048;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = param_4;
  param_1[0x1d] = param_3;
  *(undefined4 *)((int)param_1 + 0x79) = param_5;
  if (param_3 < 1) {
    param_1[0x14] = param_3;
    param_1[0x16] = 0;
  }
  else {
    param_1[0x14] = 0;
    param_1[0x16] = param_3;
  }
  if (param_4 < 1) {
    param_1[0x15] = param_4;
    param_1[0x17] = 0;
  }
  else {
    param_1[0x15] = 0;
    param_1[0x17] = param_4;
  }
  *(undefined1 *)(param_1 + 0x1e) = 1;
  sVar2 = param_4 * param_3 * 4;
  pvVar1 = _malloc(sVar2);
  param_1[0x20] = pvVar1;
  if (pvVar1 == (void *)0x0) {
    local_68 = 0;
  }
  else {
    _memset(pvVar1,0,sVar2);
    local_68 = _CGBitmapContextCreate(param_1[0x20],param_3,param_4,8,param_3 * 4,DAT_000fd500,2);
    if (local_68 == 0) {
      _free((void *)param_1[0x20]);
      param_1[0x20] = 0;
    }
    else {
      fVar3 = (float)param_4;
      _CGContextTranslateCTM(local_68,0,fVar3);
      _CGContextSetFillColorSpace(local_68,DAT_000fd500);
      _CGContextSetStrokeColorSpace(local_68,DAT_000fd500);
      _CGContextSetTextMatrix(local_68,0x3f800000,0,0,0xbf800000,0,0);
      _CGContextSaveGState(local_68);
      local_24 = (float)param_3;
      local_28 = 0;
      local_2c = 0;
      local_20 = fVar3;
      _CGContextClearRect(local_68,0,0,local_24,fVar3);
    }
  }
  param_1[0x18] = local_68;
  local_3c = 0;
  local_38 = 0;
  local_34 = param_3;
  local_30 = param_4;
  FUN_0009e6ec(param_1,param_5);
  FUN_0009f51a(param_1,param_5);
  FUN_0009fcae(param_1,&local_3c);
  FUN_000a0ebc(param_1,&local_3c,0);
  return;
}

