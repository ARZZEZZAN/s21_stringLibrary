#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *memcpyDest = (char *)dest;
  const char *memcpySrc = (const char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    memcpyDest[i] = memcpySrc[i];
  }
  return (char *)memcpyDest;
}