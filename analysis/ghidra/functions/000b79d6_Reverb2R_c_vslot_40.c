/* 000b79d6 Reverb2R_c_vslot_40 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Reverb2R_c_vslot_40(int param_1,float param_2)

{
  float fVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  
  fVar1 = param_2 / 44100.0;
  iVar5 = 0;
  iVar4 = param_1 + 0x404;
  do {
    *(float *)(iVar4 + -0x20c) = param_2;
    if (*(void **)(iVar4 + -0x21c) != (void *)0x0) {
      _free(*(void **)(iVar4 + -0x21c));
    }
    *(undefined4 *)(iVar4 + -0x21c) = 0;
    iVar2 = (int)((float)*(int *)(iVar4 + -0x214) * fVar1 + 0.5);
    *(int *)(iVar4 + -0x218) = iVar2;
    if (iVar2 < *(int *)(iVar4 + -0x210)) {
      *(undefined4 *)(iVar4 + -0x210) = 0;
      iVar2 = *(int *)(iVar4 + -0x218);
    }
    pvVar3 = _malloc(iVar2 * 4 + 0x28);
    *(void **)(iVar4 + -0x21c) = pvVar3;
    if ((pvVar3 != (void *)0x0) && (0 < *(int *)(iVar4 + -0x218))) {
      iVar2 = 0;
      do {
        *(undefined4 *)(*(int *)(iVar4 + -0x21c) + iVar2 * 4) = 0;
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(iVar4 + -0x218));
    }
    fVar6 = (float)*(int *)(iVar4 + -0x1e0) * *(float *)(iVar4 + -0x1e8);
    *(float *)(iVar4 + -0x1e4) = (fVar6 + fVar6) / param_2;
    *(float *)(iVar4 + 0x14) = param_2;
    if (*(void **)(iVar4 + 4) != (void *)0x0) {
      _free(*(void **)(iVar4 + 4));
    }
    *(undefined4 *)(iVar4 + 4) = 0;
    iVar2 = (int)((float)*(int *)(iVar4 + 0xc) * fVar1 + 0.5);
    *(int *)(iVar4 + 8) = iVar2;
    if (iVar2 < *(int *)(iVar4 + 0x10)) {
      *(undefined4 *)(iVar4 + 0x10) = 0;
      iVar2 = *(int *)(iVar4 + 8);
    }
    pvVar3 = _malloc(iVar2 * 4 + 0x28);
    *(void **)(iVar4 + 4) = pvVar3;
    if ((pvVar3 != (void *)0x0) && (0 < *(int *)(iVar4 + 8))) {
      iVar2 = 0;
      do {
        *(undefined4 *)(*(int *)(iVar4 + 4) + iVar2 * 4) = 0;
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(iVar4 + 8));
    }
    fVar6 = (float)*(int *)(iVar4 + 0x40) * *(float *)(iVar4 + 0x38);
    *(float *)(iVar4 + 0x3c) = (fVar6 + fVar6) / param_2;
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + 0x44;
  } while (iVar5 != 8);
  iVar5 = 0;
  iVar4 = param_1 + 0x6b4;
  do {
    *(float *)(iVar4 + -0x7c) = param_2;
    if (*(void **)(iVar4 + -0x8c) != (void *)0x0) {
      _free(*(void **)(iVar4 + -0x8c));
    }
    *(undefined4 *)(iVar4 + -0x8c) = 0;
    iVar2 = (int)((float)*(int *)(iVar4 + -0x84) * fVar1 + 0.5);
    *(int *)(iVar4 + -0x88) = iVar2;
    if (iVar2 < *(int *)(iVar4 + -0x80)) {
      *(undefined4 *)(iVar4 + -0x80) = 0;
      iVar2 = *(int *)(iVar4 + -0x88);
    }
    pvVar3 = _malloc(iVar2 * 4 + 0x28);
    *(void **)(iVar4 + -0x8c) = pvVar3;
    if ((pvVar3 != (void *)0x0) && (0 < *(int *)(iVar4 + -0x88))) {
      iVar2 = 0;
      do {
        *(undefined4 *)(*(int *)(iVar4 + -0x8c) + iVar2 * 4) = 0;
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(iVar4 + -0x88));
    }
    *(float *)(iVar4 + 0x14) = param_2;
    if (*(void **)(iVar4 + 4) != (void *)0x0) {
      _free(*(void **)(iVar4 + 4));
    }
    *(undefined4 *)(iVar4 + 4) = 0;
    iVar2 = (int)((float)*(int *)(iVar4 + 0xc) * fVar1 + 0.5);
    *(int *)(iVar4 + 8) = iVar2;
    if (iVar2 < *(int *)(iVar4 + 0x10)) {
      *(undefined4 *)(iVar4 + 0x10) = 0;
      iVar2 = *(int *)(iVar4 + 8);
    }
    pvVar3 = _malloc(iVar2 * 4 + 0x28);
    *(void **)(iVar4 + 4) = pvVar3;
    if ((pvVar3 != (void *)0x0) && (0 < *(int *)(iVar4 + 8))) {
      iVar2 = 0;
      do {
        *(undefined4 *)(*(int *)(iVar4 + 4) + iVar2 * 4) = 0;
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(iVar4 + 8));
    }
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + 0x18;
  } while (iVar5 != 6);
  *(float *)(param_1 + 0x758) = param_2;
  if (*(void **)(param_1 + 0x748) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x748));
  }
  *(undefined4 *)(param_1 + 0x748) = 0;
  iVar4 = (int)((float)*(int *)(param_1 + 0x750) * fVar1 + 0.5);
  *(int *)(param_1 + 0x74c) = iVar4;
  if (iVar4 < *(int *)(param_1 + 0x754)) {
    *(undefined4 *)(param_1 + 0x754) = 0;
    iVar4 = *(int *)(param_1 + 0x74c);
  }
  pvVar3 = _malloc(iVar4 * 4 + 0x28);
  *(void **)(param_1 + 0x748) = pvVar3;
  if ((pvVar3 != (void *)0x0) && (0 < *(int *)(param_1 + 0x74c))) {
    iVar4 = 0;
    do {
      *(undefined4 *)(*(int *)(param_1 + 0x748) + iVar4 * 4) = 0;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x74c));
  }
  Part_c_vslot_40();
  return;
}

