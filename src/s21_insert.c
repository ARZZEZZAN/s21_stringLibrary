#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  int err = 0;
  char *array = s21_NULL;
  if (src && str && start_index <= (s21_strlen(src))) {
    array = (char *)calloc(s21_strlen(src) + s21_strlen(str) + 1, sizeof(char));
    if (array == s21_NULL) {
      err = 1;
    }
    s21_size_t i = 0;
    for (; i < start_index; i++) {
      array[i] = src[i];
    }
    s21_size_t end = i;
    for (s21_size_t j = 0; j < s21_strlen(str); j++, i++) {
      array[i] = str[j];
    }
    for (; end < s21_strlen(src); end++, i++) {
      array[i] = src[end];
    }
    array[s21_strlen(array)] = '\0';
  } else {
    err = 1;
  }
  return err ? s21_NULL : (void *)array;
}
