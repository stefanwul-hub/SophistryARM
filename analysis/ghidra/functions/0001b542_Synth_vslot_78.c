/* 0001b542 Synth_vslot_78 */

undefined4 Synth_vslot_78(int *param_1,int *param_2)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  int *piVar5;
  int local_24;
  int *local_20;
  undefined1 auStack_11 [5];
  
  if (((*param_2 != 0) && (*(char *)((int)param_1 + 0xcfd2) == '\0')) &&
     ((char)param_1[0x33f5] != '\0')) {
    *(undefined1 *)((int)param_1 + 0xcfd1) = 1;
    _OSAtomicAdd32Barrier(1,param_1 + 0xecb);
    if ((((char)param_1[0x33f2] == '\0') &&
        (cVar2 = (**(code **)(*param_1 + 0x380))(param_1), cVar2 == '\0')) &&
       ((cVar2 = (**(code **)(*param_1 + 900))(param_1), cVar2 == '\0' &&
        (cVar2 = (**(code **)(*param_1 + 0x37c))(param_1), cVar2 == '\0')))) {
      uVar3 = FUN_0002d8c4(param_1 + 0xe3f,param_1 + 0x26a1,param_1[0x269e],param_1 + 0xfed);
      *(undefined1 *)(param_1 + 0x33f2) = uVar3;
    }
    if ((((char)param_1[0x33f2] != '\0') && (*(char *)((int)param_1 + 0xcfca) != '\0')) &&
       (0 < *param_2)) {
      local_20 = param_2;
      local_24 = 0;
      do {
        piVar1 = (int *)local_20[2];
        if (*piVar1 == 1) {
          iVar4 = 1;
          piVar5 = piVar1;
          do {
            (auStack_11 + 1)[iVar4 + -1] = (char)piVar5[6];
            iVar4 = iVar4 + 1;
            piVar5 = (int *)((int)piVar5 + 1);
          } while (iVar4 != 5);
          FUN_00017f44(param_1,piVar1[2],auStack_11 + 1);
        }
        local_24 = local_24 + 1;
        local_20 = local_20 + 1;
      } while (local_24 < *param_2);
    }
    _OSAtomicAdd32Barrier(0xffffffff,param_1 + 0xecb);
    *(undefined1 *)((int)param_1 + 0xcfd1) = 0;
  }
  return 1;
}

