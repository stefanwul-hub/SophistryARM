/* 000866e0 InBuffer2_c_vslot_7 */

void InBuffer2_c_vslot_7(int *param_1,int *param_2,int param_3,char param_4,int param_5)

{
  char cVar1;
  size_t sVar2;
  void *local_3c;
  void *local_38;
  void *local_34;
  void *local_30;
  void *local_2c;
  void *local_28;
  void *local_24;
  void *local_20;
  void *local_1c;
  void *local_18;
  void *local_14;
  void *local_10;
  
  if ((param_4 == '\0') && (*(char *)((int)param_2 + 0x26) != '\0')) {
    cVar1 = (**(code **)(*param_1 + 0x28))(param_1,&local_3c,0);
    if (cVar1 != '\0') {
      cVar1 = (**(code **)(*param_2 + 0x34))(param_2,&local_24,0);
      if (cVar1 != '\0') {
        if (param_5 == 0) {
          _memcpy(local_3c,local_24,param_3 << 2);
        }
        else {
          (**(code **)(*param_1 + 0x50))(param_1,local_3c,local_24,param_3,param_5);
        }
      }
      (**(code **)(*param_1 + 0x40))(param_1);
    }
  }
  else if ((*(char *)((int)param_2 + 0x27) == '\0') && (param_4 == '\0')) {
    if ((char)param_2[10] != '\0') {
      cVar1 = (**(code **)(*param_1 + 0x30))(param_1,&local_3c);
      if (cVar1 != '\0') {
        cVar1 = (**(code **)(*param_2 + 0x3c))(param_2,&local_24);
        if (cVar1 != '\0') {
          if (param_5 == 0) {
            sVar2 = param_3 << 2;
            _memcpy(local_3c,local_24,sVar2);
            _memcpy(local_38,local_20,sVar2);
            _memcpy(local_34,local_1c,sVar2);
            _memcpy(local_30,local_18,sVar2);
            _memcpy(local_2c,local_14,sVar2);
            _memcpy(local_28,local_10,sVar2);
          }
          else {
            (**(code **)(*param_1 + 0x50))(param_1,local_3c,local_24,param_3,param_5);
            (**(code **)(*param_1 + 0x50))(param_1,local_38,local_20,param_3,param_5);
            (**(code **)(*param_1 + 0x50))(param_1,local_34,local_1c,param_3,param_5);
            (**(code **)(*param_1 + 0x50))(param_1,local_30,local_18,param_3,param_5);
            (**(code **)(*param_1 + 0x50))(param_1,local_2c,local_14,param_3,param_5);
            (**(code **)(*param_1 + 0x50))(param_1,local_28,local_10,param_3,param_5);
          }
        }
        (**(code **)(*param_1 + 0x48))(param_1);
      }
    }
  }
  else {
    cVar1 = (**(code **)(*param_1 + 0x2c))(param_1,&local_3c,&local_38);
    if (cVar1 != '\0') {
      cVar1 = (**(code **)(*param_2 + 0x38))(param_2,&local_24,&local_20);
      if (cVar1 != '\0') {
        if (param_5 == 0) {
          _memcpy(local_3c,local_24,param_3 << 2);
          _memcpy(local_38,local_20,param_3 << 2);
        }
        else {
          (**(code **)(*param_1 + 0x50))(param_1,local_3c,local_24,param_3,param_5);
          (**(code **)(*param_1 + 0x50))(param_1,local_38,local_20,param_3,param_5);
        }
      }
      (**(code **)(*param_1 + 0x44))(param_1);
      return;
    }
  }
  return;
}

