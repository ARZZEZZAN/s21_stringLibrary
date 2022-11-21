#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int size = 0;
  unsigned int i = 0;
  int flag = 0;
  while (flag == 0 && i < n) {
    if (str1[i] != str2[i]) {
      size = str1[i] - str2[i];
      flag = 1;
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
      flag = 1;
    }
    i++;
  }
  return size;
}