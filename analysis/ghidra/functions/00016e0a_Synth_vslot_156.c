/* 00016e0a Synth_vslot_156 */

void Synth_vslot_156(int param_1)

{
  int iVar1;
  
  *(byte *)(param_1 + 0xcfcc) =
       ((*(byte *)(param_1 + 0xcfd2) ^ 1) & *(byte *)(param_1 + 0xcfc7)) != 0 &
       *(byte *)(param_1 + 0xcfc5);
  if (0 < *(int *)(param_1 + 0xcfb0)) {
    iVar1 = 0;
    if (*(int *)(param_1 + 0xcea4) == 0) {
      do {
        *(undefined1 *)(param_1 + 0xcfcc) = 0;
        if (*(int *)(param_1 + 0xcfb0) <= iVar1 + 1) {
          return;
        }
        *(undefined1 *)(param_1 + 0xcfcc) = 0;
        iVar1 = iVar1 + 2;
      } while (iVar1 < *(int *)(param_1 + 0xcfb0));
    }
    else {
      do {
        *(byte *)(param_1 + 0xcfcc) =
             *(byte *)(param_1 + 0xcfcc) & *(int *)(*(int *)(param_1 + 0xcea4) + iVar1 * 4) != 0;
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 0xcfb0));
    }
  }
  return;
}

