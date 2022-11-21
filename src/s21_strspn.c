#include "s21_string.h"

s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t size = 0;
  int flag = 1;
  for (s21_size_t i = 0; i < s21_strlen(str1) && flag == 1; i++) {
    flag = 0;
    for (s21_size_t j = 0; j < s21_strlen(str2); j++) {
      if (str1[i] == str2[j]) {
        flag = 1;
      }
    }
    if (flag == 1) {
      size++;
    }
  }
  return size;
}