/* 0001dde8 FUN_0001dde8 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0001dde8(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6,int param_7,int param_8,undefined4 param_9,undefined4 param_10,
                 undefined4 param_11,undefined4 param_12,undefined4 param_13,undefined4 param_14,
                 char *param_15)

{
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  float *pfVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  longdouble lVar9;
  float fVar10;
  
  iVar7 = param_6;
  if (1 < param_8) {
    iVar7 = (param_8 + 1) * param_7 + -1;
  }
  FUN_000959c8(param_1,param_2,param_4,iVar7);
  *param_1 = &PTR_Synth_vslot_0_000e7028;
  FUN_00029a14(param_1 + 0x2d,param_15);
  FUN_0001533c(param_1 + 0xf3,param_10);
  FUN_00015cce(param_1 + 0x169,param_4,param_10);
  FUN_0008c976(param_1 + 0x1e1,param_1,param_15);
  FUN_00014822(param_1 + 0xdb0);
  FUN_0002e178(param_1 + 0xe28);
  FUN_0002b954(param_1 + 0xe29,0x280);
  FUN_0002b954(param_1 + 0xe2e,0x280);
  FUN_0002fee2(param_1 + 0xe33,param_9);
  FUN_0002d838(param_1 + 0xe3f);
  FUN_000b557e(param_1 + 0x113d,param_1,param_1 + 0x349e,&DAT_000fd6a0);
  FUN_0001014a(param_1 + 0x24b2);
  FUN_0002bb40(param_1 + 0x24ce,param_1);
  FUN_0002de30(param_1 + 0x267c);
  FUN_000aea0a(param_1 + 0x2689);
  FUN_0000a5d4(param_1 + 0x30f6);
  FUN_0000bb8a(param_1 + 0x319b);
  FUN_00089e26(param_1 + 0x33aa);
  param_1[0x2289f] = 0;
  param_1[0x2289e] = 0;
  param_1[0xecb] = 0;
  param_1[0xecc] = 0;
  param_1[0xecd] = 1;
  param_1[0xece] = 0;
  *(undefined1 *)(param_1 + 0x33f1) = 0;
  *(undefined1 *)(param_1 + 0xec4) = 0;
  *(undefined1 *)((int)param_1 + 0xcfc7) = 0;
  *(undefined1 *)(param_1 + 0x33f2) = 1;
  *(undefined1 *)((int)param_1 + 0xcfc9) = 0;
  *(undefined1 *)((int)param_1 + 0xcfca) = 1;
  *(undefined1 *)(param_1 + 0x33f3) = 0;
  *(undefined1 *)((int)param_1 + 0xcfcd) = 0;
  *(undefined1 *)((int)param_1 + 0xcfce) = 0;
  *(undefined1 *)((int)param_1 + 0xcfcf) = 0;
  *(undefined1 *)((int)param_1 + 0xcfd1) = 0;
  *(undefined1 *)((int)param_1 + 0xcfd2) = 0;
  *(undefined1 *)(param_1 + 0x33f5) = 1;
  *(undefined1 *)((int)param_1 + 0xcfd5) = 0;
  *(undefined1 *)((int)param_1 + 0xcfd6) = 1;
  *(undefined1 *)((int)param_1 + 0xcfc5) = 0;
  *(undefined1 *)((int)param_1 + 0xcfc6) = 0;
  *(undefined1 *)((int)param_1 + 0xcfd7) = 0;
  *(undefined1 *)(param_1 + 0x33f6) = 0;
  *(undefined1 *)((int)param_1 + 0xcfcb) = 0;
  *(undefined1 *)((int)param_1 + 0xcfd3) = 0;
  *(undefined1 *)((int)param_1 + 0xcfda) = 1;
  *(undefined1 *)((int)param_1 + 0xcfd9) = 1;
  *(undefined1 *)(param_1 + 0x33f7) = 0;
  *(undefined1 *)((int)param_1 + 0xcfdb) = 0;
  *(undefined1 *)((int)param_1 + 0xcfdd) = 0;
  param_1[0xfed] = 0x73756e55;
  *(undefined2 *)(param_1 + 0xfee) = 0x6465;
  *(undefined1 *)((int)param_1 + 0x3fba) = 0;
  param_1[0xecf] = param_7;
  if ((param_6 <= param_5) && (param_8 < 0x20)) {
    param_1[0x33ec] = param_8;
    param_1[0x2691] = param_6;
    param_1[0x2692] = param_5;
    param_1[0xec9] = param_9;
    param_1[0x2693] = param_3;
    param_1[0x2694] = param_4;
    param_1[0x269d] = param_13;
    param_1[0xeeb] = param_11;
    param_1[0x269e] = param_12;
    param_1[0x269f] = param_14;
    _strcpy((char *)(param_1 + 0x13e4),param_15);
    param_1[0x2697] = param_10;
    param_1[0x33f0] = 0;
    param_1[0x22af] = 0;
    param_1[0x22b0] = 0;
    param_1[2] = 0;
    param_1[0x33a8] = 0;
    param_1[0x26a0] = 0;
    param_1[0xeec] = 0;
    param_1[0x33a9] = 0;
    param_1[0x26f1] = 0;
    param_1[0x26f2] = 0;
    param_1[0x26f3] = 0;
    param_1[0xeea] = 0;
    param_1[0xec3] = 0;
    param_1[0xdaf] = 0;
    param_1[0xeca] = 0;
    param_1[0x1e6b] = 0;
    param_1[0x1e6c] = 0;
    param_1[0x1e6d] = 0;
    param_1[0x1e6e] = 0;
    iVar7 = param_1[0x33ec];
    piVar1 = (int *)operator_new__(iVar7 * 0x574 + 4);
    *piVar1 = iVar7;
    if (iVar7 != 0) {
      iVar7 = iVar7 + -2;
      piVar8 = piVar1 + 1;
      do {
        FUN_0002c962(piVar8);
        piVar8 = piVar8 + 0x15d;
        iVar7 = iVar7 + -1;
      } while (iVar7 != -2);
    }
    param_1[0xe3d] = piVar1 + 1;
    iVar7 = param_1[0x33ec];
    piVar1 = (int *)operator_new__(iVar7 * 0x574 + 4);
    piVar8 = piVar1 + 1;
    *piVar1 = iVar7;
    if (iVar7 != 0) {
      iVar7 = iVar7 + -2;
      piVar1 = piVar8;
      do {
        FUN_0002c962(piVar1);
        piVar1 = piVar1 + 0x15d;
        iVar7 = iVar7 + -1;
      } while (iVar7 != -2);
    }
    param_1[0xe3e] = piVar8;
    if ((param_1[0xe3d] != 0) && (piVar8 != (int *)0x0)) {
      param_1[0xe3c] = 0;
      param_1[0xe3b] = 0;
      *(undefined1 *)(param_1 + 0x26a1) = 0;
      param_1[0x33f9] = 0;
      param_1[0xed0] = 0;
      param_1[0xed1] = 0;
      param_1[0xed2] = 0xffffffff;
      param_1[0xed3] = 0xffffffff;
      param_1[0x2696] = 0;
      param_1[0xed5] = 0xffffffff;
      param_1[0xed4] = 0xffffffff;
      param_1[0xed6] = 0xffffffff;
      param_1[0xed7] = 0xffffffff;
      param_1[0xed8] = 0xffffffff;
      param_1[0xed9] = 0xffffffff;
      param_1[0xeda] = 0xffffffff;
      param_1[0xedb] = 0;
      param_1[0xedc] = 4000;
      param_1[0xedd] = 3;
      param_1[0xede] = 0xffffffff;
      param_1[0xedf] = 0xffffffff;
      param_1[0xee0] = 0xffffffff;
      param_1[0xee1] = 0;
      param_1[0xee2] = 0;
      param_1[0xee3] = 0;
      param_1[0xee4] = 0;
      param_1[0xee5] = 0xbf800000;
      param_1[0xee7] = 0;
      param_1[0xee8] = 0x3f800000;
      param_1[0xee9] = 0;
      *(double *)(param_1 + 0xec7) = -1.0;
      *(double *)(param_1 + 0xec5) = -1.0;
      param_1[7] = 0;
      param_1[0x2c] = 0;
      param_1[0x349c] = 0;
      param_1[0x269c] = 0;
      param_1[0x349d] = 0;
      param_1[0x269b] = 0;
      param_1[0x33f8] = 0;
      param_1[0x2695] = 0xffffffff;
      param_1[0x2698] = 0xffffffff;
      param_1[0x33ed] = 1;
      param_1[0x33ee] = 0;
      param_1[0x33ef] = 2;
      param_1[0x24b1] = 0;
      param_1[0x26f4] = 0;
      *(undefined1 *)(param_1 + 0x26f5) = 0;
      uVar2 = _time((time_t *)0x0);
      _srand(uVar2);
      iVar7 = 0;
      puVar5 = param_1;
      do {
        puVar5[0x103d] = (float)iVar7 / 127.0;
        lVar9 = (longdouble)_expf((float)(iVar7 + -0x7f) / 20.0);
        puVar5[0x10bd] = (float)lVar9;
        iVar7 = iVar7 + 1;
        puVar5 = puVar5 + 1;
      } while (iVar7 != 0x80);
      iVar7 = 9;
      puVar5 = param_1;
      do {
        puVar5[0x1434] = 0xffffffff;
        puVar5[0x143d] = 0xffffffff;
        puVar5 = puVar5 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      iVar7 = 0xa0;
      puVar5 = param_1;
      do {
        puVar5[0x1449] = 0x20202020;
        puVar5[0x144a] = 0xffffffff;
        puVar5[0x1447] = 0;
        puVar5[0x1448] = 0xffffffff;
        puVar5[0x144c] = 0;
        puVar5 = puVar5 + 7;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      iVar7 = 0xe0;
      puVar5 = param_1;
      do {
        puVar5[0x18a6] = "";
        puVar5[0x18a7] = 0xffffffff;
        puVar5[0x18a9] = 0;
        puVar5[0x18a8] = 0;
        puVar5[0x18aa] = 0xffffffff;
        puVar5[0x18ab] = 0xffffffff;
        puVar5 = puVar5 + 6;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      iVar7 = 5;
      puVar5 = param_1;
      do {
        puVar5[0x1e66] = 0;
        puVar5 = puVar5 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      iVar7 = 0;
      puVar5 = param_1 + 0x1e6c;
      do {
        puVar3 = puVar5 + 3;
        iVar6 = 0x22;
        do {
          *puVar3 = 0;
          puVar3 = puVar3 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        iVar7 = iVar7 + 1;
        puVar5 = puVar5 + 0x22;
      } while (iVar7 != 0x20);
      param_1[0x33fa] = 0x12;
      if (param_2 != 0) {
        Synth_vslot_28(param_1,1);
        Synth_vslot_26(param_1,1);
        Synth_vslot_89(param_1,1);
        iVar7 = Synth_vslot_87(param_1,"acceptIOChanges");
        *(bool *)((int)param_1 + 0xcfc6) = 0 < iVar7;
        if (param_1[0x33fa] == 2) {
          *(undefined1 *)((int)param_1 + 0xcfc6) = 0;
        }
      }
      FUN_00010290(param_1 + 0x24b2,"Dummy",0);
      param_1[0x2699] = 0;
      param_1[0x269a] = 0;
      param_1[0x349c] = 0;
      param_1[0x269c] = 0;
      param_1[0x33a8] = 0;
      param_1[0x26f1] = 0;
      param_1[0x33a4] = 0;
      param_1[0x33a5] = 0;
      param_1[0x33a7] = 0;
      param_1[0x33a6] = 0;
      if (0 < (int)param_1[0x33ec]) {
        iVar6 = 0;
        iVar7 = param_1[0x33ec];
        puVar5 = param_1;
        do {
          *(undefined1 *)((int)puVar5 + 0x9bd5) = 0;
          iVar6 = iVar6 + 1;
          puVar5 = puVar5 + 0x50;
        } while (iVar6 < iVar7);
      }
      fVar10 = 1e-07;
      pfVar4 = (float *)&DAT_001016a0;
      puVar5 = &DAT_00101aa0;
      do {
        fVar10 = -fVar10;
        *pfVar4 = fVar10;
        *puVar5 = 0x3f800000;
        pfVar4 = pfVar4 + 1;
        puVar5 = puVar5 + 1;
      } while (pfVar4 != (float *)&DAT_00101aa0);
      Synth_vslot_160(param_1);
      param_1[0xecd] = 0;
      return;
    }
  }
  return;
}

