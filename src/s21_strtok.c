#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *final;
  register int ch;

  if (str == 0) {
    str = final;
  }
  do {
    if ((ch = *str++) == '\0') {
      return 0;
    }
  } while (s21_strchr(delim, ch));
  --str;
  final = str + s21_strcspn(str, delim);
  if (*final != 0) {
    *final++ = 0;
  }
  return str;
}