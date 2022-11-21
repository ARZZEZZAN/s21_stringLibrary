#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *memcmpStr1 = (const unsigned char *)str1;
  const unsigned char *memcmpStr2 = (const unsigned char *)str2;
  int flag = 0;
  s21_size_t i = 0;
  while (i < n && flag == 0) {
    if (memcmpStr1[i] != memcmpStr2[i]) {
      flag = memcmpStr1[i] - memcmpStr2[i];
    }
    i++;
  }
  return flag;
}
