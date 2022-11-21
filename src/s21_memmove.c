#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *memmoveDest = (char *)dest;
  const char *memmoveSrc = (const char *)src;
  char *tmp = (char *)malloc(sizeof(char) * n);
  if (s21_NULL == tmp) {
    return s21_NULL;
  } else {
    unsigned int i = 0;
    for (i = 0; i < n; ++i) {
      *(tmp + i) = *(memmoveSrc + i);
    }
    for (i = 0; i < n; ++i) {
      *(memmoveDest + i) = *(tmp + i);
    }
    free(tmp);
  }
  return dest;
}