#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  unsigned int destLength = 0;
  unsigned int srcLength = 0;
  while (dest[destLength] != '\0') {
    destLength++;
  }
  while (src[srcLength] != '\0' && srcLength < n) {
    dest[destLength + srcLength] = src[srcLength];
    srcLength++;
  }
  dest[destLength + srcLength] = '\0';
  return dest;
}