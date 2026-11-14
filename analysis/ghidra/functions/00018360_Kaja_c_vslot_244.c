/* 00018360 Kaja_c_vslot_244 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Kaja_c_vslot_244(int *param_1,int param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  
  switch(*(undefined1 *)(param_2 + 4)) {
  case 0:
    break;
  default:
    (**(code **)(*param_1 + 0x32c))
              (param_1,*(undefined1 *)(param_2 + 4),*(undefined1 *)(param_2 + 5),
               (int)*(short *)(param_2 + 6),*(undefined4 *)(param_2 + 0xc));
    return;
  case 0x46:
    goto code_r0x0001856e;
  case 0x49:
    UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x29c);
    goto code_r0x0001855b;
  case 0x4a:
code_r0x00018582:
    (**(code **)(*param_1 + 0x2a4))
              (param_1,*(undefined1 *)(param_2 + 5),(int)*(short *)(param_2 + 6));
    break;
  case 0x4b:
code_r0x000185a2:
    (**(code **)(*param_1 + 0x2a0))
              (param_1,*(undefined1 *)(param_2 + 5),(int)*(short *)(param_2 + 6));
    break;
  case 0x4c:
    (**(code **)(*param_1 + 0x364))
              (param_1,*(undefined1 *)(param_2 + 5),*(undefined4 *)(param_2 + 0xc),
               (int)*(short *)(param_2 + 6));
    break;
  case 0x4d:
    if (param_1[0xe3c] == 0) goto code_r0x00018582;
  case 0x45:
    UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x2a8);
code_r0x0001855b:
                    /* WARNING: Could not recover jumptable at 0x00018562. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  case 0x4e:
    if (param_1[0xe3b] == 0) goto code_r0x000185a2;
    goto code_r0x0001856e;
  case 0x4f:
    UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x318);
    goto code_r0x0001855b;
  case 0x50:
    FUN_0002e53a(param_1 + 0xe28,*(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0xc));
    if (*(void **)(param_2 + 0xc) != (void *)0x0) {
      _free(*(void **)(param_2 + 0xc));
    }
    *(undefined4 *)(param_2 + 0xc) = 0;
  }
  return;
code_r0x0001856e:
  UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x2ac);
  goto code_r0x0001855b;
}

