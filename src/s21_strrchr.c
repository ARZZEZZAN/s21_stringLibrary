#include "s21_string.h"

char *s21_strrchr(const char *str, int n) {
  const char *result = s21_NULL;
  int x = s21_strlen(str);
  for (int i = x; i >= 0; i--) {
    if (str[i] == n) {
      result = (str + i);
      break;
    }
  }
  return (char *)result;
}