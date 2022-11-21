#include "s21_string.h"

int s21_sscanf(const char *str, const char *format, ...) {
  va_list ap = {0};
  struct step Step = {0};
  struct arguments Arguments = {0, -1, '\0', 0, 0};
  va_start(ap, format);
  Step.strLength = s21_strlen(str);
  int end_Function = 1;
  if (s21_strlen(str) == 0 || s21_strlen(format) == 0) {
    Step.countReturn = -1;
  }
  while (format[Step.formatStep] && end_Function && Step.countReturn != -1 &&
         Step.strStep <= Step.strLength) {
    Arguments.modifier = '\0';
    Arguments.star = 0;
    Arguments.width = -1;
    if (format[Step.formatStep] == '%') {
      Step.formatStep++;
      while (s21_is_digit(format[Step.formatStep])) {
        if (Arguments.width == -1)
          Arguments.width = (format[Step.formatStep] - '0');
        else
          Arguments.width =
              Arguments.width * 10 + (format[Step.formatStep] - '0');
        Step.formatStep++;
      }
      if (format[Step.formatStep] == '*') {
        Arguments.star = 1;
        Step.formatStep++;
      }
      if (format[Step.formatStep] == 'h' || format[Step.formatStep] == 'l' ||
          format[Step.formatStep] == 'L') {
        Arguments.modifier = format[Step.formatStep];
        Step.formatStep++;
      }
      if (end_Function) {
        end_Function = s21_switchCase(ap, &Arguments, &Step, str, format);
      }
    } else if (format[Step.formatStep] == str[Step.strStep]) {
      Step.formatStep++;
      Step.strStep++;
    } else if (s21_is_space(format[Step.formatStep])) {
      Step.formatStep++;
    } else {
      end_Function = 0;
    }
  }
  int cuntSpace = 0;
  for (int i = 0; i < Step.strLength; i++) {
    if (s21_is_space(str[i])) {
      cuntSpace++;
    }
  }
  if (cuntSpace == Step.strLength) {
    Step.countReturn = -1;
  }
  va_end(ap);
  return Step.countReturn;
}

int s21_switchCase(va_list ap, struct arguments *Arguments, struct step *Step,
                   const char *str, const char *format) {
  int end_Function = 1;
  switch (format[Step->formatStep]) {
    case 'c': {
      end_Function = s21_specifier_c(ap, str, &(*Step), &(*Arguments));
      break;
    }
    case 'i': {
      end_Function = s21_specifier_i(ap, str, &(*Step), &(*Arguments));
      break;
    }
    case 's': {
      end_Function = s21_specifier_s(ap, str, &(*Step), &(*Arguments));
      break;
    }
    case 'f':
    case 'e':
    case 'E':
    case 'g':
    case 'G': {
      end_Function = s21_specifier_f_e_E_g_G(ap, str, &(*Step), &(*Arguments));
      break;
    }
    case '%': {
      end_Function = s21_specifier_percent(str, &(*Step), &(*Arguments));
      break;
    }
    case 'n': {
      end_Function = s21_specifier_n(ap, str, &(*Step), &(*Arguments), format);
      break;
    }
    case 'd': {
      end_Function = s21_specifier_d(ap, str, &(*Arguments), &(*Step));
      break;
    }
    case 'u': {
      end_Function = s21_specifier_u(ap, str, &(*Arguments), &(*Step));
      break;
    }
    case 'o': {
      Arguments->flag = 1;
      if (Arguments->flag_o == 1) {
      } else {
        end_Function = s21_specifier_o(ap, str, &(*Arguments), &(*Step));
      }

      Arguments->flag = 0;
      break;
    }
    case 'x':
    case 'X': {
      Step->strStep += s21_specifier_Xx(ap, &str[Step->strStep], &(*Arguments),
                                        &(*Step), &end_Function);
      Step->formatStep++;

      break;
    }
    case 'p': {
      Step->strStep += s21_specifier_p(ap, &str[Step->strStep], &(*Arguments),
                                       &(*Step), &end_Function);
      Step->formatStep++;
      break;
    }
    default: {
      end_Function = 0;
    }
  }
  return end_Function;
}

int s21_specifier_percent(const char *str, struct step *Step,
                          struct arguments *args) {
  int flag = 1;
  while (s21_is_space(str[Step->strStep])) {
    Step->strStep++;
  }
  if (str[Step->strStep] == '%') {
    Step->strStep++;
  } else {
    flag = 0;
  }
  if (args->width != -1 || args->star == 1 || args->modifier != '\0') {
    flag = 0;
  }
  Step->formatStep++;
  return flag;
}

int s21_specifier_c(va_list ap, const char *str, struct step *Step,
                    struct arguments *args) {
  int flag = 1;
  if (Step->strStep <= Step->strLength) {
    if (Step->strStep != 0) {
      while (str[Step->strStep] == ' ') {
        Step->strStep++;
      }
    }
    char c = (char)str[Step->strStep];
    if (args->star == 0) {
      if (args->modifier == '\0') {
        *(char *)va_arg(ap, char *) = (char)c;
      } else if (args->modifier == 'l') {
        *(wchar_t *)va_arg(ap, wchar_t *) = (wchar_t)c;
      } else {
        flag = 0;
      }
      if (flag) {
        Step->countReturn++;
      }
    }
    if (flag) {
      Step->strStep++;
    }
  } else {
    flag = 0;
  }
  for (int i = 0; i < (args->width - 1); i++) {
    Step->strStep++;
  }
  Step->formatStep++;
  return flag;
}

int s21_specifier_i(va_list ap, const char *str, struct step *Step,
                    struct arguments *args) {
  char *end = s21_NULL;
  long long int num = 0;
  int flag = 1;
  char *string = s21_NULL;
  int negative = 1;
  while (s21_is_space(str[Step->strStep]) == 1) {
    Step->strStep++;
  }
  if (str[Step->strStep] == '-') {
    negative = -1;
    Step->strStep++;
    args->width--;
  } else if (str[Step->strStep] == '+') {
    Step->strStep++;
    args->width--;
  }
  if (args->width > 0) {
    int i = 0;
    string = (char *)malloc((args->width + 1) * sizeof(char));
    for (; i < args->width; i++) {
      string[i] = (char)str[Step->strStep];
      Step->strStep++;
    }
    string[i] = '\0';
  } else {
    string = (char *)&str[Step->strStep];
  }
  if (string[0] == '0' && (string[1] == 'x' || string[1] == 'X')) {
    num = s21_strtol(string, &end, 16);  // 16
  } else if (str[Step->strStep] == '0') {
    num = s21_strtol(string, &end, 8);  // 8
  } else if (s21_is_digit((string[0]))) {
    num = s21_strtol(string, &end, 10);
  } else {
    flag = 0;
  }
  if (args->star == 0) {
    num *= negative;
    if (args->modifier == 'l') {
      *(long int *)va_arg(ap, long int *) = (long int)num;
    } else if (args->modifier == 'h') {
      *(short int *)va_arg(ap, short int *) = (short int)num;
    } else if (args->modifier == '\0') {
      *(int *)va_arg(ap, int *) = (int)num;
    } else {
      flag = 0;
    }
    if (flag) {
      Step->countReturn++;
    }
  }
  if (flag) {
    Step->strStep += end - &str[Step->strStep];
  }
  Step->formatStep++;
  if (args->width > 0) {
    free(string);
  }
  return flag;
}

int s21_specifier_s(va_list ap, const char *str, struct step *Step,
                    struct arguments *args) {
  int flag = 1;
  if (args->modifier == '\0') {
    char *array = s21_NULL;
    if (args->star == 0) {
      array = (char *)va_arg(ap, char *);
    }
    while (s21_is_space(str[Step->strStep])) {
      Step->strStep++;
    }
    int i = 0;
    while (s21_is_space(str[Step->strStep]) == 0 &&
           str[Step->strStep] != '\0') {
      if (args->width > 0) {
        if (i >= args->width) {
          break;
        }
      }
      if (args->star == 0) {
        array[i] = str[Step->strStep];
      }
      i++;
      Step->strStep++;
    }
    if (args->star == 0) {
      Step->countReturn++;
    }
  } else if (args->modifier == 'l') {
    wchar_t *array = s21_NULL;
    if (args->star == 0) {
      array = (wchar_t *)va_arg(ap, wchar_t *);
    }
    while (s21_is_space(str[Step->strStep])) {
      Step->strStep++;
    }
    int i = 0;
    while (s21_is_space(str[Step->strStep]) == 0) {
      if (args->width > 0) {
        if (i >= args->width) {
          break;
        }
      }
      if (args->star == 0) {
        array[i] = (wchar_t)str[Step->strStep];
      }
      i++;
      Step->strStep++;
    }
    if (args->star == 0) {
      Step->countReturn++;
    }
  } else {
    flag = 0;
  }
  Step->formatStep++;
  return flag;
}

int s21_specifier_f_e_E_g_G(va_list ap, const char *str, struct step *Step,
                            struct arguments *args) {
  char *end = s21_NULL;
  long double num = 0;
  int flag = 1;
  if (s21_string_to_Ld(&str[Step->strStep], &end, &num, args)) {
    Step->strStep += end - &str[Step->strStep];
    if (s21_Euler_search(&str[Step->strStep], &end, &num)) {
      Step->strStep += end - &str[Step->strStep];
    }
    if (args->star == 0) {
      if (args->modifier == 'L') {
        *(long double *)va_arg(ap, long double *) = (long double)num;
      } else if (args->modifier == '\0') {
        *(float *)va_arg(ap, float *) = (float)num;
      } else {
        flag = 0;
      }
      if (flag) {
        Step->countReturn++;
      }
    }
  } else {
    flag = 0;
  }
  Step->formatStep++;
  return flag;
}

int s21_Euler_search(const char *str, char **end, long double *num) {
  int e = 0;
  int negative = 1;
  int flag = 1;
  int i = 0;
  if (str[i] == 'e' || str[i] == 'E') {
    i++;
    if (str[i] && str[i] == '-') {
      negative = -1;
      i++;
    } else if (str[i] && str[i] == '+') {
      negative = 1;
      i++;
    }
    if (str[i] && s21_is_digit(str[i]) == 1) {
      e = (e * 10) + (int)(str[i] - '0');
      i++;
    } else {
      flag = 0;
    }
    if (str[i] && s21_is_digit(str[i]) == 1) {
      e = (e * 10) + (int)(str[i] - '0');
    }
  } else {
    flag = 0;
  }
  double ten = 10;
  if (flag == 1) {
    if (negative == -1) {
      ten = 0.1;
    }
    for (int i = 0; i < e; i++) {
      *num *= ten;
    }
  }
  if (end != 0 && flag == 1) {
    *end = (char *)&str[i];
  }
  return flag;
}

int s21_string_to_Ld(const char *str, char **end, long double *numbur,
                     struct arguments *args) {
  long double num = 0;
  int dot = 0;
  size_t i = 0;
  int negative = 1;
  int flag = 1;
  int length = 0;
  int infNan = 1;
  while (s21_is_space(str[i]) == 1) {
    i++;
  }
  if (str[i] == '-') {
    negative = -1;
    i++;
    length++;
  } else if (str[i] == '+') {
    i++;
    length++;
  }
  if (s21_is_digit(str[i]) == 0) {
    if (str[i] == '.') {
      if (s21_is_digit(str[i + 1]) == 0) {
        flag = 0;
      }
      length++;
    } else {
      if (s21_inf_nan(str, i, &num)) {
        i += 3;
        infNan = 0;
      } else {
        flag = 0;
      }
    }
  }
  if (flag == 1 && infNan == 1) {
    for (;; i++) {
      if (s21_is_digit(str[i]) == 0) {
        if (str[i] != '.') {
          break;
        }
      }
      if (args->width > 0) {
        if ((length) == args->width) {
          break;
        }
      }
      if (str[i] == '.') {
        dot = 10;
      }
      if (dot == 0) {
        num = (num * 10) + (long double)(str[i] - '0');
      } else if (str[i] != '.') {
        num += (long double)(str[i] - '0') / dot;
        dot *= 10;
      }
      length++;
    }
  }
  if (end != 0) {
    *end = (char *)&str[i];
  }
  *numbur = (num * negative);
  return flag;
}

int s21_inf_nan(const char *str, int i, long double *num) {
  int flag = 0;
  if ((str[i] == 'i' || str[i] == 'I') &&
      (str[i + 1] == 'n' || str[i + 1] == 'N') &&
      (str[i + 2] == 'f' || str[i + 2] == 'F')) {
    flag = 1;
    *num = INFINITY;
  } else if ((str[i] == 'n' || str[i] == 'N') &&
             (str[i + 1] == 'a' || str[i + 1] == 'A') &&
             (str[i + 2] == 'n' || str[i + 2] == 'N')) {
    *num = NAN;
    flag = 1;
  }
  return flag;
}

long long s21_strtol(const char *nptr, char **endptr, register int base) {
  register const char *s = nptr;
  register unsigned long acc = 0;
  register int c = 0;
  register unsigned long cutoff = 0;
  register int neg = 0, any = 0, cutlim = 0;
  do {
    c = *s++;
  } while (s21_is_space(c) == 1);
  if ((base == 0 || base == 16) && c == '0' && (*s == 'x' || *s == 'X')) {
    c = s[1];
    s += 2;
    base = 16;
  }
  cutoff = neg ? -(unsigned long)LONG_MIN : LONG_MAX;
  cutlim = cutoff % (unsigned long)base;
  cutoff /= (unsigned long)base;
  for (acc = 0, any = 0;; c = *s++) {
    if (c >= '0' && c <= '9')
      c -= '0';
    else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
      c -= (c >= 'A' && c <= 'Z') ? 'A' - 10 : 'a' - 10;
    else
      break;
    if (c >= base) break;
    if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
      any = -1;
    else {
      any = 1;
      acc *= base;
      acc += c;
    }
  }
  if (any < 0) {
    acc = neg ? LONG_MIN : LONG_MAX;
  }
  if (endptr != 0) *endptr = (char *)(any ? s - 1 : nptr);
  return (acc);
}

int s21_is_digit(char c) {
  int flag = 0;
  if (c >= '0' && c <= '9') {
    flag = 1;
  }
  return flag;
}

int s21_is_space(char c) {
  int flag = 0;
  if ((c == ' ') || (c == '\t') || (c == '\n') || (c == '\v') || (c == '\f') ||
      (c == '\r')) {
    flag = 1;
  }
  return flag;
}

int s21_specifier_p(va_list valist, const char *str, struct arguments *args,
                    struct step *Step, int *end_func) {
  int chars_in_arg = 0;
  int sign = 1;
  long decimal = 0;
  int flagp = 0;
  while (*str == ' ' || *str == '-' || *str == '+' || *str == '0' ||
         *str == 'x') {
    if (*str == '-') sign = -1;
    str++;
    chars_in_arg++;
  }
  int result = s21_checkSymbols_XxP(str, &chars_in_arg, &decimal, args,
                                    &(*end_func), &flagp);
  if (result > 0) {
    flagp = 0;
  }
  decimal = decimal * sign;
  if (args->star == 0) {
    void **destination = va_arg(valist, void **);
    *destination = (void *)(0x0 + decimal);
    if (*end_func == 1 && flagp == 0 && *destination != 0x0) {
      Step->countReturn++;
    }
  }
  return chars_in_arg;
}

int s21_specifier_o(va_list valist, const char *str, struct arguments *args,
                    struct step *Step) {
  int counter = 0;
  int octal_number = 8;
  int flag = 0;
  long octal_argument = 0;
  if (s21_sscanf_atoi_d(str, args, &octal_argument, &(*Step))) {
    long decimal = 0;
    while ((*str == ' ' || *str == '-' || *str == '+' || *str == '0')) str++;
    while (octal_argument != 0 && args->width--) {
      decimal += (octal_argument % 10) * s21_pow(octal_number, counter++);
      octal_argument = octal_argument / 10;
    }
    if (args->star == 0) {
      s21_specifier_result(valist, args, &decimal);
      Step->countReturn++;
    }
    flag = 1;
  }
  Step->formatStep++;
  return flag;
}

int s21_specifier_Xx(va_list valist, const char *str, struct arguments *args,
                     struct step *Step, int *end_func) {
  int chars_in_arg = 0;
  int sign = 1;
  long decimal = 0;
  int flagx = 0;
  while (s21_is_space(*str)) {
    str++;
    chars_in_arg++;
  }
  if (*str == '-') {
    sign = -1;
    str++;
    chars_in_arg++;
  } else if (*str == '+') {
    str++;
    chars_in_arg++;
  }
  int result = s21_checkSymbols_XxP(str, &chars_in_arg, &decimal, args,
                                    &(*end_func), &flagx);
  if (result > 0) {
    flagx = 0;
  }
  decimal = decimal * sign;
  if (result > 13 && result <= 16) {
    decimal -= 1;
  } else if (result > 16) {
    decimal = -1;
  }
  if (args->star == 0) {
    s21_specifier_result(valist, args, &decimal);

    if (*end_func == 1 && flagx == 0) {
      Step->countReturn++;
    }
  };
  return chars_in_arg;
}
int s21_checkSymbols_XxP(const char *str, int *chars_in_arg, long *decimal,
                         struct arguments *args, int *end_func, int *flagx) {
  char hexadecimal_number[50] = {'\0'};
  int i = 0;
  if (args->width == -1) {
    args->width = 50;
  }
  if (*str == '0') {
    str++;
    args->width--;
    if (*str == 'x' || *str == 'X') {
      str++;
      args->width--;
    }
  }
  while ((*str && *str != ' ' && *str != '\n' && args->width--) ||
         ((is_digit(hexadecimal_number[i])) ||
          (hexadecimal_number[i] >= 'a' && hexadecimal_number[i] <= 'f') ||
          (hexadecimal_number[i] >= 'A' && hexadecimal_number[i] <= 'F'))) {
    if (*str <= 'f' || *str <= 'F') {
      (*chars_in_arg)++;
      hexadecimal_number[i++] = *str++;
    } else {
      *flagx = 1;
      break;
    }
  }
  int len = s21_strlen(hexadecimal_number);
  int temp = 0;
  for (i = 0; hexadecimal_number[i] != '\0' && *end_func; i++) {
    if (hexadecimal_number[i] >= '0' && hexadecimal_number[i] <= '9') {
      temp = hexadecimal_number[i] - 48;
    } else if (hexadecimal_number[i] >= 'a' && hexadecimal_number[i] <= 'f') {
      temp = hexadecimal_number[i] - 87;
    } else if (hexadecimal_number[i] >= 'A' && hexadecimal_number[i] <= 'F') {
      temp = hexadecimal_number[i] - 55;
    }
    *decimal += temp * s21_pow(16, --len);
  }
  return s21_strlen(hexadecimal_number);
}

void s21_specifier_result(va_list valist, struct arguments *args,
                          long int *result) {
  if (args->modifier == '\0') {
    int *destination = va_arg(valist, int *);
    *destination = (int)*result;
  } else if (args->modifier == 'h') {
    short *destination = va_arg(valist, short *);
    *destination = (short)*result;
  } else if (args->modifier == 'l') {
    long *destination = va_arg(valist, long *);
    *destination = (long)*result;
  }
}

int s21_specifier_d(va_list valist, const char *str, struct arguments *args,
                    struct step *Step) {
  int flag = 0;
  long temp = 0;
  if (args->star == 0) {
    if (args->modifier == '\0') {
      int *specifier_arg_u = va_arg(valist, int *);
      if (s21_sscanf_atoi_d(str, args, &temp, &(*Step))) {
        *specifier_arg_u = (int)temp;
        Step->countReturn++;
        flag = 1;
      }
    } else if (args->modifier == 'h') {
      short *specifier_arg_u = va_arg(valist, short int *);
      if (s21_sscanf_atoi_d(str, args, &temp, &(*Step))) {
        *specifier_arg_u = (short)temp;
        Step->countReturn++;
        flag = 1;
      }
    } else if (args->modifier == 'l') {
      long *specifier_arg_u = va_arg(valist, long int *);
      if (s21_sscanf_atoi_d(str, args, &temp, &(*Step))) {
        *specifier_arg_u = (long)temp;
        Step->countReturn++;
        flag = 1;
      }
    }
  } else {
    if (s21_sscanf_atoi_d(str, args, &temp, &(*Step))) {
      flag = 1;
    }
  }
  Step->formatStep++;
  return flag;
}

int s21_specifier_u(va_list valist, const char *str, struct arguments *args,
                    struct step *Step) {
  int flag = 0;
  long temp = 0;
  if (args->star == 0) {
    if (args->modifier == '\0') {
      unsigned int *specifier_arg_u = va_arg(valist, unsigned int *);
      if (s21_sscanf_atoi_d(str, args, &temp, &(*Step))) {
        *specifier_arg_u = (unsigned int)temp;
        Step->countReturn++;
        flag = 1;
      }
    } else if (args->modifier == 'h') {
      unsigned short *specifier_arg_u = va_arg(valist, unsigned short *);
      if (s21_sscanf_atoi_d(str, args, &temp, &(*Step))) {
        *specifier_arg_u = (unsigned short)temp;
        Step->countReturn++;
        flag = 1;
      }
    } else if (args->modifier == 'l') {
      unsigned long *specifier_arg_u = va_arg(valist, unsigned long *);
      if (s21_sscanf_atoi_d(str, args, &temp, &(*Step))) {
        *specifier_arg_u = (unsigned long)temp;
        Step->countReturn++;
        flag = 1;
      }
    }
  } else {
    if (s21_sscanf_atoi_d(str, args, &temp, &(*Step))) {
      flag = 1;
    }
  }
  Step->formatStep++;
  return flag;
}

double s21_pow(double x, int power) {
  double result = 1.0;
  int i = 1;
  for (i = 1; i <= power; i++) {
    result = result * x;
  }
  return (result);
}

int s21_sscanf_atoi_d(const char *str, struct arguments *args, long *res,
                      struct step *Step) {
  int sign = 1;
  int flag = 0;
  while (s21_is_space(str[Step->strStep])) {
    Step->strStep++;
  }
  if (str[Step->strStep] == '-') {
    sign = -1;
    Step->strStep++;
    args->width--;
  } else if (str[Step->strStep] == '+') {
    Step->strStep++;
    args->width--;
  }
  if (args->flag == 1) {
    if (is_digit_o(str[Step->strStep])) {
      while (is_digit_o(str[Step->strStep]) && args->width--) {
        *res = *res * 10 + (str[Step->strStep] - '0');
        Step->strStep++;
        flag = 1;
      }
    }
  } else {
    if (is_digit(str[Step->strStep])) {
      while (is_digit(str[Step->strStep]) && args->width--) {
        *res = *res * 10 + (str[Step->strStep] - '0');
        Step->strStep++;
        flag = 1;
      }
    }
  }
  if (is_digit_o2(str[Step->strStep])) {
    args->flag_o = 1;
  }
  *res *= sign;
  return flag;
}

int s21_specifier_n(va_list ap, const char *str, struct step *Step,
                    struct arguments *args, const char *format) {
  int flag = 1;
  if (s21_is_space(format[Step->formatStep - 2])) {
    while (s21_is_space(str[Step->strStep])) {
      Step->strStep++;
    }
  }
  if (args->star == 0) {
    if (args->modifier == '\0') {
      *(int *)va_arg(ap, int *) = (int)Step->strStep;
    } else {
      flag = 0;
    }
  }
  if (args->width != -1 || args->star == 1) {
    flag = 0;
  }
  Step->formatStep++;
  return flag;
}