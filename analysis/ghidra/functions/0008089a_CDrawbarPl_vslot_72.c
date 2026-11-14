/* 0008089a CDrawbarPl_vslot_72 */

longdouble CDrawbarPl_vslot_72(int param_1,int param_2)

{
  return (longdouble)
         ((float)(*(int *)(param_2 + 4) - *(int *)(param_1 + 0xc4)) /
         (float)(*(int *)(param_1 + 0xcc) - *(int *)(param_1 + 0xc4)));
}

