/* 000a8f7c LPAUSynth_vslot_51 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 LPAUSynth_vslot_51(int param_1,uint param_2,int param_3,int *param_4)

{
  bool bVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  
  if (param_2 < 5) {
    iVar5 = param_1 + 0x20 + param_2 * 0x14;
    piVar6 = *(int **)(iVar5 + 8);
    piVar2 = piVar6 + param_3;
    if (((piVar2 < *(int **)(iVar5 + 0xc)) && (piVar6 <= piVar2)) && (*piVar2 != 0)) {
      piVar2 = (int *)___dynamic_cast(*piVar2,PTR_PTR_vtable_001038c8,PTR_PTR_vtable_001038c4,0);
      if (piVar2 != (int *)0x0) {
        iVar5 = piVar2[0x14];
        iVar4 = FUN_000ae542(param_4);
        if (iVar5 == iVar4) {
          iVar5 = (**(code **)(*piVar2 + 0x14))(piVar2,0);
          piVar6 = (int *)_malloc(iVar5 << 2);
          (**(code **)(*piVar2 + 0x14))(piVar2,piVar6);
          if (iVar5 == 0) {
LAB_000a9094:
            bVar1 = false;
          }
          else {
            if (*piVar6 != *param_4) {
              iVar4 = 0;
              do {
                iVar4 = iVar4 + 1;
                if (iVar5 == iVar4) goto LAB_000a9094;
              } while (piVar6[iVar4] != *param_4);
            }
            bVar1 = true;
          }
          _free(piVar6);
          if (bVar1) {
                    /* WARNING: Could not recover jumptable at 0x000a90bb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar7 = (**(code **)(*piVar2 + 0x1c))();
            return uVar7;
          }
        }
        return 0xffffd59d;
      }
    }
    puVar3 = (undefined4 *)___cxa_allocate_exception(4);
    *puVar3 = 0xffffd583;
  }
  else {
    puVar3 = (undefined4 *)___cxa_allocate_exception(4);
    *puVar3 = 0xffffd58e;
  }
                    /* WARNING: Subroutine does not return */
  ___cxa_throw(puVar3,PTR_001037fc,0);
}

