
#include "s21_string.h"

int left_side(const char *src, const char *trim_chars, int last) {
  int res = 0;
  int size = s21_strlen(trim_chars);
  for (int i = 0; i < size; i++) {
    if (src[last] == trim_chars[i]) res = 1;
  }
  return res;
}

int right_side(const char *src, const char *trim_chars, int last) {
  int res = 0;
  last--;
  int size = s21_strlen(trim_chars);
  for (int i = 0; i < size; i++) {
    if (src[last] == trim_chars[i]) res = 1;
  }
  return res;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *arr = s21_NULL;
  if (src) {
    if (trim_chars && trim_chars[0]) {
      arr = calloc(s21_strlen(src) + 1, sizeof(char));
      s21_size_t begin = 0, last = s21_strlen(src);
      while (left_side(src, trim_chars, begin)) {
        begin++;
      }
      if (begin != last) {
        while (right_side(src, trim_chars, last)) last--;
      } else {
        arr[0] = '\0';
      }
      for (int i = 0; begin < last; i++) {
        arr[i] = src[begin];
        begin++;
      }
    } else {
      arr = s21_trim(src, "\t\n ");
    }
  }
  return arr;
}