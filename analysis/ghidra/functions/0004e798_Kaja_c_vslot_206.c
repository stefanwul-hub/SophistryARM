/* 0004e798 Kaja_c_vslot_206 */

void Kaja_c_vslot_206(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_1[0x33ef];
  if (0 < iVar3) {
    iVar4 = 0;
    do {
      cVar1 = (**(code **)(*param_1 + 0x98))(param_1,iVar4);
      if (cVar1 == '\0') {
        param_1[0x33ef] = iVar4;
        iVar3 = iVar4;
      }
      else {
        iVar3 = param_1[0x33ef];
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar3);
  }
  if (iVar3 < 6) {
    param_1[0x33ef] = 2;
    iVar3 = 0x20;
    piVar2 = param_1;
    do {
      *(undefined1 *)((int)piVar2 + 0xc07c1) = 1;
      *(undefined1 *)((int)piVar2 + 0xc09d5) = 1;
      *(undefined1 *)((int)piVar2 + 0xc0be9) = 1;
      *(undefined1 *)((int)piVar2 + 0xc0dfd) = 1;
      piVar2 = piVar2 + 0x4e77;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    if (0 < param_1[0x33ec]) {
      iVar3 = 0;
      piVar2 = param_1;
      do {
        *(undefined1 *)((int)piVar2 + 0xb68c9) = 1;
        *(undefined1 *)((int)piVar2 + 0xb6add) = 1;
        *(undefined1 *)((int)piVar2 + 0xb6cf1) = 1;
        iVar3 = iVar3 + 1;
        piVar2 = piVar2 + 0x53fd;
      } while (iVar3 < param_1[0x33ec]);
    }
  }
  (**(code **)(*param_1 + 0x350))(param_1);
  (**(code **)(*param_1 + 700))(param_1);
  *(undefined1 *)((int)param_1 + 0xcfc5) = 1;
  return;
}

