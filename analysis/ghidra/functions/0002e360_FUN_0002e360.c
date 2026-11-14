/* 0002e360 FUN_0002e360 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

bool FUN_0002e360(undefined4 param_1,int param_2,int param_3,char param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar4;
  undefined4 *puVar5;
  bool bVar6;
  undefined4 local_40;
  undefined1 local_3c;
  undefined1 local_3b;
  cfstringStruct *local_3a;
  cfstringStruct *local_36;
  undefined4 local_32;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined2 local_2a;
  undefined4 local_24;
  short local_1e [7];
  
  if ((param_2 == 0) || (param_3 == 0)) {
    return false;
  }
  local_24 = 0;
  local_1e[0] = 0;
  puVar5 = &local_40;
  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  iVar3 = _CFStringCreateWithCString(0,param_2,0x8000100);
  iVar1 = _CFStringCreateWithCString(0,param_3,0x8000100);
  if (param_4 == '\0') {
    local_3a = &cf_OK;
    local_36 = (cfstringStruct *)0x0;
    uVar4 = 1;
  }
  else {
    local_3a = &cf_Yes;
    local_36 = &cf_No;
    uVar4 = 2;
  }
  local_32 = 0;
  local_40 = 1;
  local_3c = 1;
  local_3b = 0;
  local_2e = 1;
  local_2c = 2;
  local_2a = 0x700a;
  if ((iVar3 == 0) || (iVar1 == 0)) {
LAB_0002e45f:
    iVar2 = _RunStandardAlert(local_24,0,local_1e);
    if (iVar2 == 0) {
      bVar6 = local_1e[0] == 1;
      goto LAB_0002e488;
    }
  }
  else {
    iVar2 = _CreateStandardAlert(uVar4,iVar3,iVar1,&local_40,&local_24);
    if (iVar2 == 0) goto LAB_0002e45f;
  }
  _fwrite("[LinPlug] Could not create Alert Dialog!\n",1,0x29,(FILE *)(PTR_001037f8 + 0xb0));
  bVar6 = false;
LAB_0002e488:
  if (iVar3 != 0) {
    _CFRelease(iVar3);
  }
  if (iVar1 != 0) {
    _CFRelease(iVar1);
  }
  return bVar6;
}

