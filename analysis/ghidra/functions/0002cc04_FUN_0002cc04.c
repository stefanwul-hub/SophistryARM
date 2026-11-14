/* 0002cc04 FUN_0002cc04 */

void FUN_0002cc04(undefined4 param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *local_164;
  int local_158;
  int local_154;
  int local_150;
  char local_14c [320];
  
  if (((param_2 == (undefined4 *)0x0) || ((char *)*param_2 == (char *)0x0)) || (param_3 < 2)) {
    return;
  }
  _strcpy(local_14c,(char *)*param_2);
  local_154 = param_3;
  local_158 = 0;
  local_150 = 4;
  local_164 = param_2;
  do {
    iVar1 = local_158 + 1;
    local_164 = local_164 + 1;
    iVar5 = (int)param_2 + local_150;
    iVar3 = _strcasecmp((char *)*local_164,local_14c);
    if ((-1 < iVar3) || (param_3 <= iVar1)) {
      puVar6 = param_2 + local_154;
      iVar3 = 0;
      do {
        iVar4 = _strcasecmp((char *)puVar6[-1],local_14c);
        iVar3 = iVar3 + -1;
        puVar6 = puVar6 + -1;
      } while (0 < iVar4);
      local_154 = local_154 + iVar3;
      if (local_154 <= iVar1) {
        uVar2 = *(undefined4 *)(iVar5 + -4);
        *(undefined4 *)(iVar5 + -4) = *param_2;
        *param_2 = uVar2;
        FUN_0002cc04(param_1,param_2,local_158);
        FUN_0002cc04(param_1,iVar5,param_3 - iVar1);
        return;
      }
      uVar2 = *local_164;
      *local_164 = *puVar6;
      *puVar6 = uVar2;
    }
    local_150 = local_150 + 4;
    local_158 = iVar1;
  } while( true );
}

