/* 00028492 SynthEditor_c_vslot_7 */

void SynthEditor_c_vslot_7(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if ((param_1[0x13] != 0) && (*(char *)((int)param_1 + 0x51) != '\0')) {
    _OSAtomicAdd32Barrier(1,param_1[0x13] + 0x3b30);
    (**(code **)(*(int *)param_1[0x13] + 0x27c))((int *)param_1[0x13]);
    if ((*(char *)((int)param_1 + 0x52) != '\0') &&
       (((char)param_1[0x9770] != '\0' || (0 < param_1[0x976f])))) {
      *(undefined1 *)(param_1 + 0x9756) = 1;
      if ((char)param_1[0x9770] == '\0') {
        while( true ) {
          iVar1 = param_1[0x976f];
          iVar2 = iVar1 + -1;
          param_1[0x976f] = iVar2;
          if (iVar2 == -1) break;
          (**(code **)(*param_1 + 0x94))(param_1,param_1[iVar1 + 0x9756]);
        }
      }
      else {
        (**(code **)(*param_1 + 0x90))(param_1);
      }
      param_1[0x976f] = 0;
      *(undefined1 *)(param_1 + 0x9770) = 0;
      *(undefined1 *)(param_1 + 0x9756) = 0;
    }
    AEffGUIEditor_vslot_7(param_1);
    _OSAtomicAdd32Barrier(0xffffffff,param_1[0x13] + 0x3b30);
    return;
  }
  return;
}

