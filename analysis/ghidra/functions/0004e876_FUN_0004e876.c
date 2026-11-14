/* 0004e876 FUN_0004e876 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0004e876(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  char *local_28;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  FUN_0001dde8(param_1,param_2,1,0x80,0x3c2,0x25a,0x400,1,0x20,6,"Sophistry","2232",
               "LINE,LINM,LINC,Crx3,Sop3,C2x3,S2p3","3.0.8","Sophistry");
  *param_1 = &PTR_Kaja_c_vslot_0_000e8da8;
  puVar1 = param_1 + 0x228a0;
  iVar2 = 2;
  do {
    FUN_0003a25a(puVar1);
    puVar1 = puVar1 + 0x1bc;
    iVar2 = iVar2 + -1;
  } while (iVar2 != -2);
  puVar1 = param_1 + 0x22f90;
  iVar2 = 2;
  do {
    FUN_0008eb1e(puVar1);
    puVar1 = puVar1 + 0x1ba;
    iVar2 = iVar2 + -1;
  } while (iVar2 != -2);
  puVar1 = param_1 + 0x23678;
  iVar2 = 0;
  do {
    FUN_00034d36(puVar1);
    puVar1 = puVar1 + 0x286e;
    iVar2 = iVar2 + -1;
  } while (iVar2 != -2);
  FUN_00062f20(param_1 + 0x28754);
  puVar1 = param_1 + 0x2db51;
  iVar2 = 0x1e;
  do {
    FUN_0006582a(puVar1);
    puVar1 = puVar1 + 0x4e77;
    iVar2 = iVar2 + -1;
  } while (iVar2 != -2);
  FUN_00060448(param_1 + 0xcaa81);
  FUN_0000a5d4(param_1 + 0xcaaf6);
  FUN_000854ac(param_1 + 0xcab9b);
  FUN_000854ac(param_1 + 0xcabb0);
  FUN_000854ac(param_1 + 0xcabc5);
  FUN_000854ac(param_1 + 0xcabda);
  FUN_000854ac(param_1 + 0xcabef);
  FUN_000854ac(param_1 + 0xcac04);
  FUN_000854ac(param_1 + 0xcac1e);
  FUN_000854ac(param_1 + 0xcac33);
  FUN_000854ac(param_1 + 0xcac48);
  FUN_000854ac(param_1 + 0xcac5d);
  FUN_000854ac(param_1 + 0xcac72);
  FUN_000854ac(param_1 + 0xcac87);
  _OSAtomicAdd32Barrier(1,param_1 + 0xecd);
  param_1[0x1a] = 0x536f7033;
  *(undefined1 *)(param_1 + 0xcac19) = 0;
  local_28 = "fxp";
  local_24 = 0;
  local_20[0] = 0;
  FUN_0002cd7c(param_1[0xe3e],0x140,"empty",&local_28,0);
  FUN_0002cd7c(param_1[0xe3d],0x140,"empty",local_20,0);
  if (param_2 != 0) {
    param_1[0x10] = 6;
    param_1[0x33f0] = 0;
    param_1[0xf] = 0;
  }
  param_1[0xecd] = 0;
  return;
}

