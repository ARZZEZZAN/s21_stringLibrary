#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  unsigned int i = 0;
  int flag = 1;
  for (i = 0; haystack[i] != '\0' && flag == 1; i++) {
    flag = 0;
    for (unsigned int j = 0; needle[j] != '\0' && flag == 0; j++) {
      if ((haystack[i + j] == '\0') || (haystack[i + j] != needle[j])) {
        flag = 1;
      }
    }
  }
  i--;
  return flag ? s21_NULL : (char *)&haystack[i];
}