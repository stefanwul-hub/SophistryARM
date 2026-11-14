/* 0009c994 FUN_0009c994 */

void FUN_0009c994(int *param_1,int *param_2)

{
  if (*param_1 < *param_2) {
    *param_1 = *param_2;
  }
  if (param_1[1] < param_2[1]) {
    param_1[1] = param_2[1];
  }
  if (param_2[2] < param_1[2]) {
    param_1[2] = param_2[2];
  }
  if (param_2[3] < param_1[3]) {
    param_1[3] = param_2[3];
  }
  if (param_1[3] < param_1[1]) {
    param_1[3] = param_1[1];
  }
  if (param_1[2] < *param_1) {
    param_1[2] = *param_1;
  }
  return;
}

