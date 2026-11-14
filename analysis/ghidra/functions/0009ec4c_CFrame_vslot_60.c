/* 0009ec4c CFrame_vslot_60 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined1 CFrame_vslot_60(int *param_1,int *param_2,undefined1 param_3)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  int *piVar4;
  int *piVar5;
  
  if (param_1[0x1a] == 0) {
    if ((param_2 == (int *)0x0) && (param_2 = (int *)param_1[0x1b], param_2 == (int *)0x0)) {
      uVar3 = CModulFramePl_vslot_60(param_1,0,param_3);
      return uVar3;
    }
    cVar2 = (**(code **)(*param_1 + 0xbc))(param_1,param_2);
    if (cVar2 == '\0') {
      piVar5 = (int *)param_2[0xb];
      if ((piVar5 != (int *)0x0) &&
         (cVar2 = (**(code **)(*piVar5 + 0xa4))(piVar5,"CViewContainer"), piVar4 = param_2,
         cVar2 != '\0')) {
        do {
          cVar2 = (**(code **)(*piVar5 + 0xf0))(piVar5,piVar4,param_3);
          if (cVar2 != '\0') {
            return 1;
          }
        } while (((piVar5[0xb] != 0) &&
                 (cVar2 = (**(code **)(*(int *)piVar5[0xb] + 0xa4))
                                    ((int *)piVar5[0xb],"CViewContainer"), cVar2 != '\0')) &&
                (piVar1 = piVar5 + 0xb, piVar4 = piVar5, piVar5 = (int *)*piVar1,
                (int *)*piVar1 != (int *)0x0));
      }
      uVar3 = CModulFramePl_vslot_60(param_1,param_2,param_3);
      return uVar3;
    }
    cVar2 = CModulFramePl_vslot_60(param_1,param_2,param_3);
    if (cVar2 != '\0') {
      return 1;
    }
    (**(code **)(*param_1 + 0x13c))(param_1,0);
  }
  return 0;
}

