#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list input = {0};
  va_start(input, format);
  s21_FORMAT parameters = {0};
  s21_size_t i = 0;
  str = s21_strcpy(str, "");
  while (*format) {
    parameters.precision = -1;
    parameters.flag_plus = parameters.flag_minus = parameters.flag_space =
        parameters.flag_zero = parameters.flag_sharp = parameters.width =
            parameters.point = parameters.specifier = parameters.length = 0;
    switch (*format) {
      case '%':
        format++;
        if (is_flag(*format)) {
          while (is_flag(*format)) {
            s21_check_flag(&parameters, format++);
          }
        }
        if (is_digit(*format) || *format == '*') {
          format = s21_str_to_int(&parameters.width, format++, &input);
          if (parameters.width < 0) {
            parameters.flag_minus = 1;
            parameters.width *= -1;
          }
        }
        if (*format == '.') {
          parameters.point = 1;
          parameters.precision = 0;
          format++;
          if (is_digit(*format) || *format == '*') {
            format = s21_str_to_int(&parameters.precision, format++, &input);
          } else {
            parameters.precision = -1;
          }
        }
        if (is_length(*format)) {
          while (is_length(*format)) {
            parameters.length = *(format++);
          }
        }
        if (is_specifier(*format)) {
          parameters.specifier = *(format++);
        }
        s21_default_precision(&parameters);
        str = s21_check_specifier(str, &i, &input, &parameters);
        break;
      default:
        str[i++] = *(format++);
        str[i] = '\0';
        break;
    }
  }
  va_end(input);
  return (int)s21_strlen(str);
}

void s21_default_precision(s21_FORMAT *parameters) {
  if (parameters->point && parameters->precision <= 0) {
    parameters->precision = 0;
  }
  if (!parameters->point && s21_strchr("eEfgG", parameters->specifier)) {
    parameters->precision = 6;
  }
}

void s21_check_flag(s21_FORMAT *parameters, const char *format) {
  switch (*format) {
    case '-':
      parameters->flag_minus = 1;
      break;
    case '+':
      parameters->flag_plus = 1;
      break;
    case ' ':
      parameters->flag_space = 1;
      break;
    case '#':
      parameters->flag_sharp = 1;
      break;
    case '0':
      parameters->flag_zero = 1;
      break;
  }
}

char *s21_check_specifier(char *str, s21_size_t *str_len, va_list *input,
                          s21_FORMAT *parameters) {
  char *tmp_str = s21_NULL;
  tmp_str = calloc(1024, sizeof(char));
  if (tmp_str != s21_NULL) {
    switch (parameters->specifier) {
      case 'c':
        s21_spec_c(tmp_str, input, parameters);
        break;
      case 'd':
      case 'i':
        s21_spec_di(tmp_str, input, parameters);
        break;
      case 'e':
      case 'E':
        s21_spec_eE(tmp_str, input, parameters);
        break;
      case 'f':
        s21_spec_f(tmp_str, input, parameters);
        break;
      case 'g':
      case 'G':
        s21_spec_gG(tmp_str, input, parameters);
        break;
      case 'n':
        s21_spec_n(str_len, input);
        break;
      case 'o':
        s21_spec_o(tmp_str, input, parameters);
        break;
      case 'p':
        s21_spec_p(tmp_str, input, parameters);
        break;
      case 's':
        s21_spec_s(tmp_str, input, parameters);
        break;
      case 'u':
        s21_spec_u(tmp_str, input, parameters);
        break;
      case 'x':
      case 'X':
        s21_spec_xX(tmp_str, input, parameters);
        break;
      case '%':
        s21_spec_percentage(tmp_str, parameters);
        break;
    }
    s21_strcat(str, tmp_str);
    free(tmp_str);
    *str_len = s21_strlen(str);
  }
  return str;
}

char *s21_str_to_int(int *number, const char *format, va_list *input) {
  char wth[128] = {0};
  char *num = NULL;
  int count = 0;
  while (is_digit(*format)) {
    wth[count++] = *(format)++;
  }
  num = wth;
  while (count > 0) {
    *number += ((*(num)++) - '0') * pow(10, --count);
  }
  if (*format == '*') {
    *number = va_arg(*input, int);
    format++;
  }
  return (char *)format;
}

void s21_int_to_str(s21_FORMAT *parameters, char *str, long double number) {
  char *point = s21_NULL;
  int flag = 1;
  parameters->sign = number < 0 ? -1 : 1;
  number *= parameters->sign;
  point = str;
  if (parameters->specifier != 'n') {
    while (flag) {
      int digit = 0;
      if (number >= 10) {
        digit = (int)fmod(number, 10);
        number = (number - digit) / 10;
      } else {
        digit = (int)number;
        flag = 0;
      }
      *(point++) = (char)(digit + '0');
    }
    if (s21_strchr("dioxX", parameters->specifier) &&
        parameters->precision == 0 && number == 0 && parameters->point)
      str[0] = '\0';
    *point = '\0';
    s21_reverse_writing(str);
  }
}

void s21_ul_to_str(char *str, unsigned long long number,
                   s21_FORMAT *parameters) {
  char *point = s21_NULL;
  int flag = 1;

  point = str;

  while (flag) {
    int digit = 0;
    if (number >= 10) {
      digit = (int)fmod(number, 10);
      number = (number - digit) / 10;
    } else {
      digit = (int)number;
      flag = 0;
    }
    *(point++) = (char)(digit + '0');
  }
  if (parameters->precision == 0 && number == 0 && parameters->point)
    str[0] = '\0';
  *point = '\0';
  s21_reverse_writing(str);
}

void s21_ol_to_str(char *str, unsigned long long number, int prefix) {
  char *point = s21_NULL;
  int flag = 1;

  point = str;

  while (flag) {
    unsigned int digit;
    if (number > 7) {
      digit = number % 8;
      number = (number - digit) / 8;
    } else {
      digit = number;
      flag = 0;
    }
    *(point++) = (char)(digit + '0');
  }

  if (prefix == 1) *(point++) = '0';
  *point = '\0';
  s21_reverse_writing(str);
}

void s21_hl_to_str(char *str, unsigned long long number,
                   s21_FORMAT *parameters) {
  char *point = s21_NULL;
  int flag = 1, shift = 0;
  point = str;
  shift = parameters->specifier == 'x' ? 32 : 0;

  while (flag) {
    unsigned int digit;
    if (number > 15) {
      digit = number % 16;
      number = (number - digit) / 16;
    } else {
      digit = number;
      flag = 0;
    }
    if (digit < 10)
      *(point++) = (char)(digit + '0');
    else
      *(point++) = (char)(digit + 'A' + shift - 10);
  }
  *point = '\0';
  if (number == 0) parameters->flag_sharp = 0;
  s21_reverse_writing(str);
}

void s21_float_to_str(char *str, long double number, s21_FORMAT *parameters) {
  parameters->sign = number < 0 ? -1 : 1;
  number *= parameters->sign;
  int local_sign = parameters->sign;
  if (parameters->precision <= 0) {
    s21_int_to_str(parameters, str, roundl(number));
  } else {
    long double left = 0, right = 0;
    int pos = 0;
    char result[256] = {0};
    right = modfl(number, &left);
    if (s21_strchr("gG", parameters->specifier) && parameters->precision == 1 &&
        right >= 0.5) {
      left++;
    }
    s21_int_to_str(parameters, str, roundl(left));
    s21_strcat(str, ".");
    int local_precision = parameters->precision;
    if (s21_strchr("gG", parameters->specifier)) {
      if (left >= 1) {
        local_precision = parameters->precision - (int)s21_strlen(str) + 1 +
                          ((int)roundl(number) == 0);
      } else if (right * pow(10, local_precision) < 1) {
        local_precision = 4;
      }
    }
    for (int i = 0; i < local_precision; i++) right *= 10;
    s21_int_to_str(parameters, result, roundl(right));
    pos = (int)s21_strlen(result);
    for (int i = 0; pos < local_precision; i++, pos++) {
      s21_move_string(result);
      result[i] = '0';
    }
    if (s21_strchr("gG", parameters->specifier) && (int)roundl(number) != 0) {
      result[parameters->precision - (int)s21_strlen(str) + 1] = '\0';
    }
    s21_strcat(str, result);
  }
  parameters->sign = local_sign;
}

void s21_gG_to_str(char *str, long double number, s21_FORMAT *parameters) {
  parameters->sign = number < 0 ? -1 : 1;
  number *= parameters->sign;
  int local_sign = parameters->sign;
  if ((number / pow(10, parameters->precision)) > 1 ||
      ((number * (pow(10, 4))) < 1 && (number * (pow(10, 21))) >= 1)) {
    if (number < 1 && parameters->precision <= 0) {
      parameters->precision = 4;
    } else {
      --parameters->precision;
    }
    s21_eE_to_str(str, number, parameters);
  } else {
    parameters->precision > 0 ? 1 : ++parameters->precision;
    s21_float_to_str(str, number, parameters);
    s21_delete_zero(parameters, str);
  }
  parameters->sign = local_sign;
}

void s21_delete_zero(s21_FORMAT *parameters, char *str) {
  int pos = (int)s21_strlen(str) - 1;
  if (pos > 0) {
    while (str[pos] == '0') {
      if (!parameters->flag_sharp ||
          (parameters->flag_sharp && pos > parameters->precision)) {
        str[pos] = '\0';
        pos -= 1;
      }
    }
    if (!parameters->flag_sharp && str[pos] == '.') {
      str[pos] = '\0';
    }
  }
}

void s21_eE_to_str(char *str, long double number, s21_FORMAT *parameters) {
  parameters->sign = number < 0 ? -1 : 1;
  int notation = 0, local_sign = parameters->sign;
  number *= parameters->sign;
  if (number < 1) {
    while (number < 1 && notation-- > -42) {
      number *= 10;
    }
    number < 1 ? (notation = number = 0) : 1;
    if (s21_compare_round(parameters, number)) {
      if (parameters->precision >= 0) {
        --parameters->precision;
      }
      notation++;
    }
    if (s21_strchr("gG", parameters->specifier))
      s21_delete_zero(parameters, str);
    s21_make_mantissa(parameters, &str[s21_strlen(str)], notation);
  } else {
    while (number >= 10) {
      notation++;
      number /= 10;
    }
    if (s21_compare_round(parameters, number)) {
      if (parameters->precision >= 0) {
        --parameters->precision;
      }
      notation++;
    }
  }
  number = roundl(number * pow(10, parameters->precision));
  s21_int_to_str(parameters, str, number);
  if (parameters->precision > 0) {
    s21_move_string(&str[1]);
    str[1] = '.';
    for (int i = (int)s21_strlen(str); i < 2 + parameters->precision; i++) {
      str[i] = '0';
    }
  }
  if (s21_strchr("gG", parameters->specifier)) s21_delete_zero(parameters, str);
  s21_make_mantissa(parameters, &str[s21_strlen(str)], notation);
  parameters->sign = local_sign;
}

// Если округляется до следующего разряда, необходимо увеличить степень
// и поделить число на 10
// В этом случае возвращаем True
int s21_compare_round(s21_FORMAT *parameters, long double number) {
  char compare_str[128] = {'\0'};
  int length = 0, result = 0;
  number *= pow(10, parameters->precision);
  s21_int_to_str(parameters, compare_str, number);
  length = s21_strlen(compare_str);
  number = roundl(number);
  s21_int_to_str(parameters, compare_str, number);
  if (length < (int)s21_strlen(compare_str)) {
    result = 1;
  }
  return result;
}

void s21_make_mantissa(s21_FORMAT *parameters, char *mantice, int notation) {
  int start_pos = 0;
  if (parameters->flag_sharp && parameters->precision <= 0) {
    mantice[start_pos++] = '.';
  }
  mantice[start_pos++] = s21_strchr("eg", parameters->specifier) ? 'e' : 'E';
  mantice[start_pos++] = (notation >= 0) ? '+' : '-';
  if (abs(notation) < 10) {
    mantice[start_pos++] = '0';
    s21_int_to_str(parameters, &mantice[start_pos], abs(notation));
  } else {
    s21_int_to_str(parameters, &mantice[start_pos], abs(notation));
  }
}

void s21_wch_to_str(char *str, wchar_t *wstr, s21_size_t length) {
  s21_size_t str_len = s21_strlen(str);
  int cnt = length;
  char *p = str + str_len;

  while (*wstr != '\0' && (cnt-- > 0 || length == 0)) {
    *(p++) = (char)*(wstr++);
  }
  *p = '\0';
}

/* Функция сдвига строки на 1 позицию вправо */
void s21_move_string(char *str) {
  int pos = (int)s21_strlen(str);
  str[pos + 1] = '\0';
  while (pos > 0) {
    str[pos] = str[pos - 1];
    pos--;
  }
}

void s21_make_string_flags(s21_FORMAT *parameters, char *str) {
  int pos = 0;
  if (!s21_strchr("cuo\%", parameters->specifier)) {
    if (parameters->specifier != 'x' && parameters->specifier != 'X') {
      if (parameters->sign < 0) {
        s21_move_string(str);
        str[pos++] = '-';
        parameters->sign = 0;
      }
      if (parameters->flag_plus && parameters->sign != 0) {
        s21_move_string(str);
        str[pos] = (parameters->sign > 0) ? '+' : '-';
        parameters->sign = 0;
      }
      if (parameters->flag_space && parameters->sign != 0) {
        s21_move_string(str);
        str[pos] = (parameters->sign > 0) ? ' ' : '-';
        parameters->sign = 0;
      }
    }
    if (parameters->flag_sharp) {
      s21_sharp_flag(parameters, str);
    }
  }
  if (parameters->flag_minus) {
    pos = (int)s21_strlen(str);
    while (pos < parameters->width) {
      str[pos++] = ' ';
    }
  }
}

/* Функция обработки флага '#' */
void s21_sharp_flag(s21_FORMAT *parameters, char *str) {
  int pos = 0;
  if (s21_strchr("oxX", parameters->specifier)) {
    if (parameters->specifier == 'x' || parameters->specifier == 'X') {
      s21_move_string(str);
    }
    parameters->specifier == 'o' ? 1 : s21_move_string(str);
    str[pos++] = '0';
    if (parameters->specifier != 'o')
      str[pos] = parameters->specifier == 'x' ? 'x' : 'X';
  }
  if (s21_strchr("eEf", parameters->specifier)) {
    if (!s21_strchr(str, '.')) {
      str[s21_strlen(str)] = '.';
    }
  }
}

/* Функция обработки ширины форматной строки */
void s21_make_string_width(s21_FORMAT *parameters, char *str) {
  int pos_str = (int)s21_strlen(str);
  if (parameters->width > pos_str) {
    str[parameters->width + 1] = '\0';
    while (pos_str >= 0) {
      str[parameters->width--] = str[pos_str--];
    }
    for (pos_str = 0; pos_str <= parameters->width; pos_str++) {
      if (s21_strchr("diopuxX", parameters->specifier)) {
        str[pos_str] =
            (parameters->flag_zero && !parameters->point) ? '0' : ' ';
      }
      if (s21_strchr("feEgGcs", parameters->specifier)) {
        str[pos_str] = (parameters->flag_zero) ? '0' : ' ';
      }
    }
  }
}

/* Функция обработки точности форматной строки */
void s21_make_string_precision(s21_FORMAT *parameters, char *str) {
  char *string_with_precision = s21_NULL;
  string_with_precision = calloc(1024, sizeof(char));
  int pos = 0;
  if (string_with_precision != s21_NULL) {
    if (s21_strchr("diouxX", parameters->specifier)) {
      while (pos < parameters->precision - (int)s21_strlen(str)) {
        string_with_precision[pos++] = '0';
      }
      for (int i = 0; str[i] != '\0'; i++) {
        string_with_precision[pos++] = str[i];
      }
      s21_strcpy(str, string_with_precision);
    }
    free(string_with_precision);
  }
}

/* Функция обратной записи в строку */
void s21_reverse_writing(char *str) {
  char c = 0;
  s21_size_t length = s21_strlen(str);
  for (s21_size_t i = 0; i < length / 2; i++) {
    c = str[i];
    str[i] = str[length - 1 - i];
    str[length - 1 - i] = c;
  }
}

/* Символ */
void s21_spec_c(char *str, va_list *input, s21_FORMAT *parameters) {
  wchar_t wchar = 0;
  wchar_t wchar_s[10] = {0};
  switch (parameters->length) {
    case 'l':
      wchar = va_arg(*input, wchar_t);
      wchar_s[0] = wchar;
      s21_wch_to_str(str, wchar_s, 0);
      break;
    default:
      str[0] = va_arg(*input, int);
      str[1] = '\0';
      break;
  }
  s21_make_string_flags(parameters, str);
  s21_make_string_width(parameters, str);
}

/* Знаковое десятичное целое число */
void s21_spec_di(char *str, va_list *input, s21_FORMAT *parameters) {
  long int ld_number = 0;
  short int sd_number = 0;
  int number = 0;

  switch (parameters->length) {
    case 'h':
      sd_number = (short int)va_arg(*input, int);
      s21_int_to_str(parameters, str, sd_number);
      break;
    case 'l':
      ld_number = (long int)va_arg(*input, long int);
      s21_int_to_str(parameters, str, ld_number);
      break;
    default:
      number = va_arg(*input, int);
      s21_int_to_str(parameters, str, number);
      break;
  }
  s21_make_string_precision(parameters, str);
  s21_make_string_flags(parameters, str);
  s21_make_string_width(parameters, str);
}

/* Научная нотация (мантисса/экспонента) с использованием символа e/E (вывод
 * чисел должен совпадать с точностью до e-6) */
void s21_spec_eE(char *str, va_list *input, s21_FORMAT *parameters) {
  long double l_number = 0;
  double number = 0;
  switch (parameters->length) {
    case 'L':
      l_number = va_arg(*input, long double);
      s21_eE_to_str(str, l_number, parameters);
      break;
    default:
      number = va_arg(*input, double);
      s21_eE_to_str(str, number, parameters);
      break;
  }
  s21_make_string_precision(parameters, str);
  s21_make_string_flags(parameters, str);
  s21_make_string_width(parameters, str);
}

void s21_spec_f(char *str, va_list *input, s21_FORMAT *parameters) {
  long double l_number = 0;
  double d_number = 0;

  switch (parameters->length) {
    case 'L':
      l_number = va_arg(*input, long double);
      s21_float_to_str(str, l_number, parameters);
      break;
    case 'l':
    default:
      d_number = va_arg(*input, double);
      s21_float_to_str(str, d_number, parameters);
      break;
  }
  s21_make_string_flags(parameters, str);
  s21_make_string_width(parameters, str);
}

/* Использует кратчайший из представлений десятичного числа */
void s21_spec_gG(char *str, va_list *input, s21_FORMAT *parameters) {
  long double l_number = 0;
  double number = 0;

  switch (parameters->length) {
    case 'L':
      l_number = va_arg(*input, long double);
      s21_gG_to_str(str, l_number, parameters);
      break;
    case 'l':
    default:
      number = va_arg(*input, double);
      s21_gG_to_str(str, number, parameters);
      break;
  }
  s21_make_string_precision(parameters, str);
  s21_make_string_flags(parameters, str);
  s21_make_string_width(parameters, str);
}

/* Беззнаковое восьмеричное число */
void s21_spec_o(char *str, va_list *input, s21_FORMAT *parameters) {
  unsigned long int ld_number = 0;
  unsigned short int sd_number = 0;
  unsigned int number = 0;

  switch (parameters->length) {
    case 'h':
      sd_number = (unsigned short int)va_arg(*input, unsigned int);
      s21_ol_to_str(str, sd_number, parameters->flag_sharp);
      break;
    case 'l':
      ld_number = (unsigned long int)va_arg(*input, unsigned long int);
      s21_ol_to_str(str, ld_number, parameters->flag_sharp);
      break;
    default:
      number = va_arg(*input, unsigned int);
      s21_ol_to_str(str, number, parameters->flag_sharp);
      break;
  }
  s21_make_string_precision(parameters, str);
  s21_make_string_flags(parameters, str);
  s21_make_string_width(parameters, str);
}

/* Строка символов */
void s21_spec_s(char *str, va_list *input, s21_FORMAT *parameters) {
  char *string = s21_NULL;
  string = va_arg(*input, char *);
  if (parameters->precision > -1)
    s21_strncat(str, string, parameters->precision);
  else
    s21_strcat(str, string);
  s21_make_string_precision(parameters, str);
  s21_make_string_flags(parameters, str);
  s21_make_string_width(parameters, str);
}

/* Беззнаковое десятичное целое число */
void s21_spec_u(char *str, va_list *input, s21_FORMAT *parameters) {
  unsigned short us_number = 0;
  unsigned long ul_number = 0;
  unsigned int u_number = 0;

  switch (parameters->length) {
    case 'h':
      us_number = (unsigned short)va_arg(*input, unsigned int);
      s21_ul_to_str(str, us_number, parameters);
      break;
    case 'l':
      ul_number = (unsigned long)va_arg(*input, unsigned long);
      s21_ul_to_str(str, ul_number, parameters);
      break;
    default:
      u_number = (unsigned int)va_arg(*input, unsigned int);
      s21_ul_to_str(str, u_number, parameters);
      break;
  }

  s21_make_string_precision(parameters, str);
  s21_make_string_flags(parameters, str);
  s21_make_string_width(parameters, str);
}

/* Беззнаковое шестнадцатеричное целое число(X - заглавные буквы) */
void s21_spec_xX(char *str, va_list *input, s21_FORMAT *parameters) {
  unsigned long int ld_number = 0;
  unsigned short int sd_number = 0;
  unsigned int number = 0;

  switch (parameters->length) {
    case 'h':
      sd_number = (unsigned short int)va_arg(*input, unsigned int);
      s21_hl_to_str(str, sd_number, parameters);
      break;
    case 'l':
      ld_number = (unsigned long int)va_arg(*input, unsigned long int);
      s21_hl_to_str(str, ld_number, parameters);
      break;
    default:
      number = (unsigned int)va_arg(*input, unsigned int);
      s21_hl_to_str(str, number, parameters);
      break;
  }
  s21_make_string_precision(parameters, str);
  s21_make_string_flags(parameters, str);
  s21_make_string_width(parameters, str);
}

/* Адрес указателя */
void s21_spec_p(char *str, va_list *input, s21_FORMAT *parameters) {
  int width = parameters->width < 15 ? 15 : parameters->width;
  char *str_start = s21_NULL;
  str_start = str;
  int *p = va_arg(*input, int *);
  char buf[4] = "x0";
  if (p == s21_NULL) {
    s21_strcpy(buf, "0x0");
  }
  for (int *j = p, k = 0; j && k < width;
       j = (void *)(((s21_size_t)j) >> 4), k++) {
    unsigned int dig = ((s21_size_t)j) % 0x10;
    if (dig < 10)
      *(str_start++) = (char)('0' + dig);
    else
      *(str_start++) = (char)('a' + (dig - 10));
  }
  *str_start = '\0';
  s21_strcat(str, buf);
  s21_reverse_writing(str);
  s21_make_string_precision(parameters, str);
  s21_make_string_flags(parameters, str);
  s21_make_string_width(parameters, str);
}

/* Количество символов, напечатанных до появления %n */
void s21_spec_n(s21_size_t const *str_len, va_list *input) {
  int *p = va_arg(*input, int *);
  *p = (int)*str_len;
}

/* Символ % */
void s21_spec_percentage(char *str, s21_FORMAT *parameters) {
  s21_strcat(str, "%");
  s21_make_string_precision(parameters, str);
  s21_make_string_flags(parameters, str);
  s21_make_string_width(parameters, str);
}
