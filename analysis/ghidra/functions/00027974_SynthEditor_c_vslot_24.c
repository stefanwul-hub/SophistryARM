/* 00027974 SynthEditor_c_vslot_24 */

void SynthEditor_c_vslot_24(int *param_1,int *param_2,int *param_3,int param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 local_d;
  
  if (((param_2 != (int *)0x0) && (param_3 != (int *)0x0)) && (*param_3 != 0)) {
    iVar3 = 0;
    do {
      iVar2 = iVar3;
      iVar3 = iVar2 + 1;
    } while (param_3[iVar3] != 0);
    if (param_4 < 0) {
      param_4 = 0;
    }
    if (param_4 <= iVar2) {
      iVar2 = param_4;
    }
    iVar2 = param_3[iVar2];
    cVar1 = (**(code **)(*param_2 + 0xbc))(param_2,iVar2);
    if (cVar1 == '\0') {
      if (0 < iVar3) {
        iVar4 = 0;
        do {
          local_d = 0;
          (**(code **)(*param_2 + 0xb4))(param_2,param_3[iVar4],&local_d);
          iVar4 = iVar4 + 1;
        } while (iVar3 != iVar4);
      }
      (**(code **)(*param_2 + 0xac))(param_2,iVar2);
      (**(code **)(*param_1 + 0x7c))(param_1);
      *(undefined1 *)(iVar2 + 0x30) = 1;
      *(undefined1 *)(iVar2 + 100) = 1;
    }
  }
  return;
}

