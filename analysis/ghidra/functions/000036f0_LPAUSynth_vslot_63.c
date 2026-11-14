/* 000036f0 LPAUSynth_vslot_63 */

undefined4
LPAUSynth_vslot_63(int param_1,byte param_2,byte param_3,undefined1 param_4,undefined1 param_5,
                  undefined4 param_6)

{
  undefined4 *puVar1;
  undefined4 local_14;
  
  local_14 = (uint)CONCAT12(param_5,CONCAT11(param_4,param_2 | param_3));
  if (((*(int *)(param_1 + 0x32b40c) + 1U & *(uint *)(param_1 + 0x32b410)) !=
       *(uint *)(param_1 + 0x32b408)) &&
     (puVar1 = (undefined4 *)(*(int *)(param_1 + 0x32b40c) * 0x20 + *(int *)(param_1 + 0x32b414)),
     puVar1 != (undefined4 *)0x0)) {
    *puVar1 = 1;
    puVar1[1] = 0x18;
    puVar1[2] = param_6;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = local_14;
    puVar1[7] = 0;
    _CompareAndSwap(*(undefined4 *)(param_1 + 0x32b40c),
                    *(int *)(param_1 + 0x32b40c) + 1U & *(uint *)(param_1 + 0x32b410),
                    param_1 + 0x32b40c);
  }
  return 0;
}

