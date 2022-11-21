#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  int flag = 1;
  s21_size_t i = 0;
  for (i = 0; i < s21_strlen(str1) && flag == 1; i++) {
    for (s21_size_t j = 0; j < s21_strlen(str2); j++) {
      if (str1[i] == str2[j]) {
        flag = 0;
      }
    }
  }
  i--;
  return flag ? s21_NULL : (char *)&str1[i];
}