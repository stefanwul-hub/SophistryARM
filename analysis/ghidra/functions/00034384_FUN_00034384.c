/* 00034384 FUN_00034384 */

char FUN_00034384(int *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 int param_6)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  
  if (((param_3 < 0x40) && (param_1[0x48] != 0)) &&
     (iVar2 = FUN_00011b72(param_1[0x48],param_2), iVar2 != 0)) {
    piVar3 = param_1 + param_2 * 0x2740 + param_3 * 0x9d + 0x78;
    cVar1 = FUN_0002ddaa(piVar3 + 0x75);
    if (cVar1 != '\0') {
      if (piVar3[0x87] != 0) {
        FUN_000aecdc(piVar3);
      }
      cVar1 = FUN_000b2666(piVar3,param_4,param_5);
      if (cVar1 != '\0') {
        piVar3[0x84] = param_6;
        if (*(char *)((int)param_1 + 0x1d5) != '\0') {
          FUN_000af2b2(piVar3);
        }
        if ((char)piVar3[0x85] == '\0') {
          if ((char)param_1[0x75] != '\0') {
            FUN_0003225a(param_1,piVar3[0x87],piVar3[0x8b]);
          }
          FUN_00032430(param_1,piVar3[0x87],piVar3[0x8b]);
        }
        else {
          if ((char)param_1[0x75] != '\0') {
            FUN_0003225a(param_1,piVar3[0x87],piVar3[0x8b]);
            FUN_0003225a(param_1,piVar3[0x88],piVar3[0x8b]);
          }
          FUN_00032344(param_1,piVar3[0x87],piVar3[0x88],piVar3[0x8b]);
        }
        if (((char)param_1[0x75] != '\0') &&
           (FUN_000322d4(param_1,piVar3[0x87],piVar3[0x8b]), (char)piVar3[0x85] != '\0')) {
          FUN_000322d4(param_1,piVar3[0x88],piVar3[0x8b]);
        }
        iVar2 = param_3 * 0x8c0 + iVar2;
        FUN_000109ee(iVar2 + 0x690,piVar3[0x8b] + -1);
        FUN_000109ee(iVar2 + 0x8c0,piVar3[0x8b] + -1);
        FUN_000109ee(iVar2 + 0x930,piVar3[0x8b] + -1);
        FUN_000109ee(iVar2 + 0xaf0,piVar3[0x8b] + -1);
        if ((char)piVar3[0x98] != '\0') {
          FUN_000109c8(iVar2 + 0x8c0,piVar3[0x93]);
          FUN_000109c8(iVar2 + 0x930,piVar3[0x94]);
        }
        param_3 = param_3 * 0x14;
        (**(code **)(*param_1 + 0x78))(param_1,param_2,param_3 + 0xf);
        (**(code **)(*param_1 + 0x78))(param_1,param_2,param_3 + 0x14);
        (**(code **)(*param_1 + 0x78))(param_1,param_2,param_3 + 0x15);
        (**(code **)(*param_1 + 0x78))(param_1,param_2,param_3 + 0x19);
      }
      FUN_0002ddc8(piVar3 + 0x75);
      return cVar1;
    }
  }
  return '\0';
}

