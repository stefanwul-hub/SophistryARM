/* 0009689a Synth_vslot_114 */

undefined4 Synth_vslot_114(int *param_1,int *param_2,undefined4 *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  if (((param_3 != (undefined4 *)0x0) &&
      (cVar1 = (**(code **)(*param_1 + 0x1c0))(param_1,param_2), cVar1 != '\0')) &&
     (cVar1 = (**(code **)(*param_1 + 0x1bc))(param_1,param_2,param_3[1]), cVar1 != '\0')) {
    *(undefined4 *)*param_2 = *param_3;
    iVar3 = *param_2;
    if (0 < *(int *)(iVar3 + 4)) {
      iVar2 = 0;
      do {
        cVar1 = (**(code **)(*param_1 + 0x1c4))
                          (param_1,iVar3 + 8 + iVar2 * 0x70,param_3 + iVar2 * 0x1c + 2);
        if (cVar1 == '\0') {
          return 0;
        }
        iVar2 = iVar2 + 1;
        iVar3 = *param_2;
      } while (iVar2 < *(int *)(iVar3 + 4));
    }
    return 1;
  }
  return 0;
}

