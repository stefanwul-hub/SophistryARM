/* 00026146 SynthEditor_c_vslot_26 */

void SynthEditor_c_vslot_26
               (int param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
               undefined1 param_5)

{
  int iVar1;
  int *piVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  
  *(undefined1 *)(param_1 + 0x34) = param_2;
  *(undefined1 *)(param_1 + 0x35) = param_3;
  *(undefined1 *)(param_1 + 0x36) = param_4;
  *(undefined1 *)(param_1 + 0x37) = param_5;
  iVar4 = param_1;
  iVar5 = param_1;
  do {
    piVar2 = *(int **)(iVar4 + 0x20854);
    if (piVar2 == (int *)0x0) {
      iVar1 = *(int *)(iVar4 + 0x2085c);
      if (iVar1 == 9) {
LAB_000261dc:
        piVar2 = *(int **)(iVar4 + 0x20858);
        if (piVar2 != (int *)0x0) {
          pcVar3 = *(code **)(*piVar2 + 0x104);
          goto LAB_0002618a;
        }
      }
      else if (iVar1 < 10) {
        if (iVar1 == 3) {
          piVar2 = *(int **)(iVar5 + 0x90);
joined_r0x00026202:
          if (piVar2 != (int *)0x0) goto LAB_00026182;
        }
      }
      else {
        if (iVar1 == 10) goto LAB_000261dc;
        if (iVar1 == 0xd) {
          piVar2 = *(int **)(iVar5 + 0x88);
          goto joined_r0x00026202;
        }
      }
    }
    else {
LAB_00026182:
      pcVar3 = *(code **)(*piVar2 + 0x138);
LAB_0002618a:
      (*pcVar3)(piVar2,*(undefined4 *)(param_1 + 0x34));
    }
    iVar5 = iVar5 + 0x68;
    iVar4 = iVar4 + 0xc;
    if (iVar4 == param_1 + 0x3c00) {
      return;
    }
  } while( true );
}

