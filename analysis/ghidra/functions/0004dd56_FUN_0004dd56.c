/* 0004dd56 FUN_0004dd56 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0004dd56(int *param_1)

{
  char cVar1;
  char local_164 [320];
  char *local_24;
  undefined4 local_20;
  
  _strcpy(local_164,(char *)((int)param_1 + 0x9bd5));
  (**(code **)(*param_1 + 0x2dc))(param_1,0,local_164);
  (**(code **)(*param_1 + 0x2d8))(param_1,0,local_164);
  local_24 = "fxp";
  local_20 = 0;
  while( true ) {
    cVar1 = FUN_0000abd0(param_1 + 0xcaaf6,1,(char *)((int)param_1 + 0x9bd5),local_164,&local_24);
    if (cVar1 == '\0') break;
    (**(code **)(*param_1 + 0x2dc))(param_1,0,local_164);
    (**(code **)(*param_1 + 0x2d8))(param_1,0,local_164);
  }
  return;
}

