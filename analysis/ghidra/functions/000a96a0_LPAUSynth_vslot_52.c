/* 000a96a0 LPAUSynth_vslot_52 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void LPAUSynth_vslot_52(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 local_d;
  
  if (param_2 < 5) {
    iVar3 = param_1 + 0x20 + param_2 * 0x14;
    piVar1 = *(int **)(iVar3 + 8);
    piVar2 = piVar1 + param_3;
    if (((piVar2 < *(int **)(iVar3 + 0xc)) && (piVar1 <= piVar2)) && (*piVar2 != 0)) {
      piVar2 = (int *)___dynamic_cast(*piVar2,PTR_PTR_vtable_001038c8,PTR_PTR_vtable_001038c4,0);
      if (piVar2 != (int *)0x0) {
        iVar3 = (**(code **)(*piVar2 + 0x18))(piVar2,0,&local_d);
        if (iVar3 != 0) {
          (**(code **)(*piVar2 + 0x20))(piVar2);
        }
        return;
      }
    }
    puVar4 = (undefined4 *)___cxa_allocate_exception(4);
    *puVar4 = 0xffffd583;
  }
  else {
    puVar4 = (undefined4 *)___cxa_allocate_exception(4);
    *puVar4 = 0xffffd58e;
  }
                    /* WARNING: Subroutine does not return */
  ___cxa_throw(puVar4,PTR_001037fc,0);
}

