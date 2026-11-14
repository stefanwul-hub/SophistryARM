/* 000958a2 Synth_vslot_43 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Synth_vslot_43(undefined4 param_1,int param_2,char *param_3,size_t param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int local_30;
  ushort local_1e [7];
  
  if (param_2 < 100000000) {
    if (param_2 < 0) {
      _strncpy(param_3,"-",param_4);
      param_3[param_4] = '\0';
      param_2 = -param_2;
    }
    else {
      _strncpy(param_3,"",param_4);
      param_3[param_4] = '\0';
    }
    bVar1 = false;
    iVar3 = 100000000;
    local_30 = 9;
    do {
      iVar2 = param_2 / iVar3;
      param_2 = param_2 - iVar2 * iVar3;
      if ((bVar1) || (0 < iVar2)) {
        local_1e[0] = (ushort)(byte)((char)iVar2 + 0x30);
        _strncat(param_3,(char *)local_1e,param_4);
        param_3[param_4] = '\0';
        bVar1 = true;
      }
      iVar3 = iVar3 / 10;
      local_30 = local_30 + -1;
    } while (local_30 != 0);
    return;
  }
  _strncpy(param_3,"Huge!",param_4);
  param_3[param_4] = '\0';
  return;
}

