/* 000250d4 Synth_vslot_6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Synth_vslot_6(int *param_1)

{
  int *piVar1;
  code *pcVar2;
  char cVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  int iVar6;
  int local_180;
  int *local_174;
  int local_160;
  char local_15c [332];
  
  if ((char)param_1[0x33f1] == '\0') {
    (**(code **)(*param_1 + 0xc))(param_1);
  }
  if ((char)param_1[0x33f1] == '\0') {
    return;
  }
  _OSAtomicAdd32Barrier(1,param_1 + 0xecc);
  if (param_1[0x26a0] == 0) {
    iVar6 = FUN_00009ba6(param_1 + 0x30f6,param_1);
    param_1[0x26a0] = iVar6;
  }
  if (*(char *)((int)param_1 + 0xcfc7) == '\0') {
    (**(code **)(*param_1 + 0x1c))(param_1,0x472c4400);
    *(undefined1 *)((int)param_1 + 0xcfce) = 1;
    cVar3 = FUN_00029b82(param_1 + 0x2d);
  }
  else {
    *(undefined1 *)((int)param_1 + 0xcfce) = 1;
    cVar3 = FUN_00029b82(param_1 + 0x2d);
  }
  if (cVar3 == '\0') {
    local_174 = param_1 + 0x2d;
    FUN_00029ada(local_174);
    if ((int *)param_1[2] != (int *)0x0) {
      pcVar2 = *(code **)(*(int *)param_1[2] + 0x6c);
      uVar5 = Envelope_c_vslot_12(local_174,0,7);
      (*pcVar2)(param_1[2],uVar5);
    }
    if (0 < param_1[0x33ec]) {
      local_160 = 0;
      local_180 = (int)param_1 + 0x9bd5;
      do {
        _sprintf(local_15c,"%sLoadPresetPath%ld",param_1 + 0x13e4,local_160);
        FUN_0002e564(param_1 + 0xe28,local_15c,local_180,0x140);
        local_160 = local_160 + 1;
        local_180 = local_180 + 0x140;
      } while (local_160 < param_1[0x33ec]);
    }
    (**(code **)(*param_1 + 0x364))(param_1,0,local_174,2);
    (**(code **)(*param_1 + 0x364))(param_1,0,local_174,3);
    (**(code **)(*param_1 + 0x364))(param_1,0,local_174,4);
    (**(code **)(*param_1 + 0x364))(param_1,0,local_174,5);
  }
  local_174 = param_1 + 0x2d;
  (**(code **)(*param_1 + 0x374))(param_1);
  FUN_0008b5e4(param_1 + 0x1e1);
  cVar3 = (**(code **)(*param_1 + 0x380))(param_1);
  if (((cVar3 == '\0') && (cVar3 = (**(code **)(*param_1 + 900))(param_1), cVar3 == '\0')) &&
     (cVar3 = (**(code **)(*param_1 + 0x37c))(param_1), cVar3 == '\0')) {
    Envelope_c_vslot_18(local_174,0,1,local_15c);
    _strcpy((char *)(param_1 + 0x26a1),local_15c);
    uVar4 = FUN_0002d8c4(param_1 + 0xe3f,param_1 + 0x26a1,param_1[0x269e],param_1 + 0xfed);
    *(undefined1 *)(param_1 + 0x33f2) = uVar4;
  }
  *(undefined1 *)((int)param_1 + 0xcfd2) = 1;
  *(undefined1 *)(param_1 + 0x33f3) = 0;
  if (*(char *)((int)param_1 + 0xcfd1) != '\0') {
    do {
      FUN_0002e340(param_1 + 0xe28,0x1e);
    } while (*(char *)((int)param_1 + 0xcfd1) != '\0');
  }
  if (0 < param_1[0x33ec]) {
    iVar6 = 0;
    do {
      piVar1 = *(int **)(param_1[0x33a9] + iVar6 * 4);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x50))(piVar1);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_1[0x33ec]);
  }
  FUN_00024e9e(param_1);
  FUN_0002eb20(param_1 + 0xe33);
  FUN_0002bb04(param_1 + 0xe29);
  param_1[0xee9] = 0;
  if (0 < param_1[0xec9]) {
    iVar6 = 0;
    do {
      piVar1 = *(int **)(param_1[0xec3] + iVar6 * 4);
      (**(code **)(*piVar1 + 0x10))(piVar1);
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_1[0xec9]);
  }
  if (0 < param_1[0x33ec]) {
    iVar6 = 0;
    do {
      Envelope_c_vslot_9(param_1 + 0x169,iVar6,6,0);
      piVar1 = *(int **)(param_1[0x33a9] + iVar6 * 4);
      (**(code **)(*piVar1 + 0x10))(piVar1);
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_1[0x33ec]);
  }
  *(undefined1 *)((int)param_1 + 0xcfd2) = 0;
  (**(code **)(*param_1 + 0x270))(param_1);
  if (*(char *)((int)param_1 + 0xcfc9) == '\0') {
    (**(code **)(*param_1 + 0x2e8))(param_1);
  }
  (**(code **)(*param_1 + 500))(param_1,1);
  _OSAtomicAdd32Barrier(0xffffffff,param_1 + 0xecc);
  AudioEffectX_vslot_6(param_1);
  return;
}

