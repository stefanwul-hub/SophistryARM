/* 00025bd6 SynthEditor_c_vslot_23 */

void SynthEditor_c_vslot_23(int *param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int local_20;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  
  if (param_1[7] != 0) {
    if ((char)param_1[0x9756] != '\0') {
      iVar4 = 1;
      FUN_0002e340(param_1 + 0x9775,0x32);
      cVar1 = (char)param_1[0x9756];
      while ((cVar1 != '\0' && (iVar4 = iVar4 + 1, iVar4 != 6))) {
        FUN_0002e340(param_1 + 0x9775,0x32);
        cVar1 = (char)param_1[0x9756];
      }
    }
    local_20 = 0;
    piVar3 = param_1 + 0x9616;
    piVar2 = param_1;
    do {
      if ((piVar2[0x9616] != param_1[9]) && (piVar2[0x9616] != param_1[10])) {
        (**(code **)(*param_1 + 0xa8))(param_1,piVar3);
      }
      local_20 = local_20 + 1;
      piVar3 = piVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (local_20 != 0xc0);
    piVar2 = (int *)param_1[9];
    if (piVar2 != (int *)0x0) {
      local_10 = 1;
      (**(code **)(*piVar2 + 0xb8))(piVar2,&local_10);
    }
    piVar2 = (int *)param_1[10];
    if (piVar2 == (int *)0x0) {
      cVar1 = (**(code **)(*(int *)param_1[7] + 0xbc))((int *)param_1[7],param_1[9]);
    }
    else {
      local_f = 1;
      (**(code **)(*piVar2 + 0xb8))(piVar2,&local_f);
      cVar1 = (**(code **)(*(int *)param_1[7] + 0xbc))((int *)param_1[7],param_1[9]);
    }
    if (cVar1 != '\0') {
      local_e = 0;
      (**(code **)(*(int *)param_1[7] + 0xb4))((int *)param_1[7],param_1[9],&local_e);
    }
    if ((param_1[10] != 0) &&
       (cVar1 = (**(code **)(*(int *)param_1[7] + 0xbc))((int *)param_1[7],param_1[10]),
       cVar1 != '\0')) {
      local_d = 0;
      (**(code **)(*(int *)param_1[7] + 0xb4))((int *)param_1[7],param_1[10],&local_d);
    }
    piVar2 = (int *)param_1[9];
    if (piVar2 == (int *)0x0) {
      param_1[9] = 0;
      piVar2 = (int *)param_1[10];
    }
    else {
      (**(code **)(*piVar2 + 8))(piVar2);
      param_1[9] = 0;
      piVar2 = (int *)param_1[10];
    }
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    param_1[10] = 0;
    piVar2 = (int *)param_1[7];
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    param_1[7] = 0;
    iVar4 = 0;
    piVar2 = param_1 + 0x977a;
    do {
      FUN_00080724(piVar2);
      iVar4 = iVar4 + 1;
      piVar2 = piVar2 + 0x1a;
    } while (iVar4 != 0x40);
    (**(code **)(*param_1 + 0x54))(param_1);
  }
  return;
}

