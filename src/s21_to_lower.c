#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *array2 = s21_NULL;
  if (str) {
    array2 = (char *)calloc(s21_strlen(str) + 1, sizeof(char));
  }
  if (array2) {
    s21_strncpy(array2, str, s21_strlen(str) + 1);
    for (s21_size_t i = 0; i < s21_strlen(array2); i++) {
      if (array2[i] >= 65 && array2[i] <= 90) {
        array2[i] += 32;
      }
    }
  }
  return (void *)array2;
}
