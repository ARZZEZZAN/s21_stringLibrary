#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  while (i < n && src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  if (src[i] == '\0' && n > 0 && n > s21_strlen(src)) {
    dest[i] = '\0';
  }
  return dest;
}