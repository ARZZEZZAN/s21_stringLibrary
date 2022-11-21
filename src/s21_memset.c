#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  char *memsetStr = (char *)str;
  for (unsigned int i = 0; i < n; i++) {
    *(memsetStr + i) = (char)c;
  }
  return memsetStr;
}