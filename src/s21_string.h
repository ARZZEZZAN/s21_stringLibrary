#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 512

typedef long unsigned s21_size_t;  // Целочисленный тип без знака, являющийся
                                   // результатом ключевого слова sizeof.
#define s21_NULL \
  ((void *)0)  // Макрос, являющийся значением константы нулевого указателя.

#define UNKNOWN "Unknown error: "
#define is_flag(ch)                                                   \
  ((ch) == '-') || ((ch) == '+') || ((ch) == ' ') || ((ch) == '#') || \
      ((ch) == '0')

#define is_digit(ch) ((ch) >= '0' && (ch) <= '9')

#define is_length(ch) ((ch) == 'h' || (ch) == 'l' || (ch) == 'L')

#define is_specifier(ch)                                                      \
  ((ch) == 'c' || (ch) == 'd' || (ch) == 'i' || (ch) == 'e' || (ch) == 'E' || \
   (ch) == 'f' || (ch) == 'g' || (ch) == 'G' || (ch) == 'o' || (ch) == 's' || \
   (ch) == 'u' || (ch) == 'x' || (ch) == 'X' || (ch) == 'p' || (ch) == 'n' || \
   (ch) == '%')

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int n);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

/*----------------------------SPRINTF------------------------------*/
typedef struct s21_FORMAT {
  int flag_minus;  // Выравнивание по левому краю
  int flag_plus;  // Заставляет предварять результат знаком + или -
  int flag_space;  // Если знак не записан, перед значением
                   // вставляется пробел.
  int flag_sharp;  //При o, x или X значению предшествуют 0, 0x или
                   // 0X соответственно, если не нуль. При с e, E и
                   // f заставляет записанный вывод содержать
                   //десятичную точку. По умолчанию, если цифры не
                   //следуют, десятичная точка не записывается.
  int flag_zero;  // Дополняет число слева нулями (0) вместо
                  // пробелов
  int width;  //Минимальное количество печатаемых цифр.
  int precision;  //Минимальное количество записываемых цифр.
  char length;     // Тип переменной
  char specifier;  // Спецификатор

  int sign;   // Знак + или -
  int point;  // ФЛАГ НА ТООООЧКУУ!
} s21_FORMAT;

int s21_sprintf(char *str, const char *format, ...);
void s21_default_precision(s21_FORMAT *parameters);
void s21_check_flag(s21_FORMAT *parameters, const char *format);
void s21_sharp_flag(s21_FORMAT *parameters, char *str);

char *s21_str_to_int(int *number, const char *format, va_list *input);
void s21_int_to_str(s21_FORMAT *parameters, char *str, long double number);
void s21_simple_str_to_int(int *number, char *str);
void s21_ul_to_str(char *str, unsigned long long number,
                   s21_FORMAT *parameters);
void s21_ol_to_str(char *str, unsigned long long number, int prefix);
void s21_hl_to_str(char *str, unsigned long long number,
                   s21_FORMAT *parameters);
void s21_float_to_str(char *str, long double number, s21_FORMAT *parameters);
void s21_wch_to_str(char *str, wchar_t *wstr, s21_size_t length);
void s21_eE_to_str(char *str, long double number, s21_FORMAT *parameters);

char *s21_check_specifier(char *str, s21_size_t *str_len, va_list *input,
                          s21_FORMAT *parameters);
int s21_compare_round(s21_FORMAT *parameters, long double number);
void s21_delete_zero(s21_FORMAT *parameters, char *str);

void s21_move_string(char *str);
void s21_make_string_flags(s21_FORMAT *parameters, char *str);
void s21_make_string_width(s21_FORMAT *parameters, char *str);
void s21_make_string_precision(s21_FORMAT *parameters, char *str);
void s21_make_mantissa(s21_FORMAT *parameters, char *mantice, int notation);
void s21_reverse_writing(char *str);

void s21_spec_c(char *str, va_list *input, s21_FORMAT *parameters);  //Символ
void s21_spec_di(char *str, va_list *input,
                 s21_FORMAT *parameters);  // Знаковое десятичное целое число
void s21_spec_eE(
    char *str, va_list *input,
    s21_FORMAT *parameters);  //Научная нотация (мантисса/экспонента) с
                              //использованием символа e/E (вывод чисел должен
                              //совпадать с точностью до
                              // e-6)
void s21_spec_f(char *str, va_list *input,
                s21_FORMAT *parameters);  // Десятичное число с плавающей точкой
void s21_spec_gG(char *str, va_list *input,
                 s21_FORMAT *parameters);  // Использует кратчайший из
                                           // представлений десятичного числа
void s21_spec_o(char *str, va_list *input,
                s21_FORMAT *parameters);  // Беззнаковое восьмеричное число
void s21_spec_s(char *str, va_list *input,
                s21_FORMAT *parameters);  // Строка символов
void s21_spec_u(char *str, va_list *input,
                s21_FORMAT *parameters);  // Беззнаковое десятичное целое число
void s21_spec_xX(char *str, va_list *input,
                 s21_FORMAT *parameters);  // Беззнаковое шестнадцатеричное
                                           // целое число(X - заглавные буквы)
void s21_spec_p(char *str, va_list *input,
                s21_FORMAT *parameters);  // Адрес указателя
void s21_spec_n(
    s21_size_t const *str_len,
    va_list *input);  // Количество символов, напечатанных до появления %n
void s21_spec_percentage(char *str, s21_FORMAT *parameters);  // Символ %
/*----------------------------SSCANF------------------------------*/
#ifndef ULONG_MAX
#define ULONG_MAX ((unsigned long)(~0L)) /* 0xFFFFFFFF */
#endif

#ifndef LONG_MAX
#define LONG_MAX ((long)(ULONG_MAX >> 1)) /* 0x7FFFFFFF */
#endif

#ifndef LONG_MIN
#define LONG_MIN ((long)(~LONG_MAX)) /* 0x80000000 */
#endif

#define is_digit(ch) ((ch) >= '0' && (ch) <= '9')
#define is_digit_o2(ch) ((ch) >= '8' && (ch) <= '9')
#define is_digit_o(ch) ((ch) >= '0' && (ch) <= '7')

struct step {
  int strStep;
  int strLength;
  int formatStep;
  int countReturn;
};

struct arguments {
  short star;
  int width;
  char modifier;
  int flag;
  int flag_o;
};

int s21_sscanf(const char *str, const char *format, ...);
int s21_switchCase(va_list ap, struct arguments *Arguments, struct step *Step,
                   const char *str, const char *format);
int s21_specifier_c(va_list ap, const char *str, struct step *Step,
                    struct arguments *args);
int s21_specifier_s(va_list ap, const char *str, struct step *Step,
                    struct arguments *args);
int s21_specifier_i(va_list ap, const char *str, struct step *Step,
                    struct arguments *args);
int s21_specifier_f_e_E_g_G(va_list ap, const char *str, struct step *Step,
                            struct arguments *args);
int s21_specifier_percent(const char *str, struct step *Step,
                          struct arguments *args);
int s21_specifier_n(va_list ap, const char *str, struct step *Step,
                    struct arguments *args, const char *format);
int s21_Euler_search(const char *str, char **end, long double *num);
int s21_string_to_Ld(const char *str, char **end, long double *numbur,
                     struct arguments *args);
int s21_inf_nan(const char *str, int i, long double *num);
long long s21_strtol(const char *nptr, char **endptr, register int base);
int s21_is_space(char c);
int s21_is_digit(char c);

int s21_sscanf_atoi_d(const char *str, struct arguments *args, long *res,
                      struct step *Step);
int s21_specifier_d(va_list valist, const char *str, struct arguments *args,
                    struct step *Step);

double s21_pow(double x, int power);
int s21_specifier_u(va_list valist, const char *str, struct arguments *args,
                    struct step *Step);
int s21_specifier_o(va_list valist, const char *str, struct arguments *args,
                    struct step *Step);
void s21_specifier_result(va_list valist, struct arguments *args,
                          long int *result);
int s21_specifier_Xx(va_list valist, const char *str, struct arguments *args,
                     struct step *Step, int *end_func);
int s21_specifier_p(va_list valist, const char *str, struct arguments *args,
                    struct step *Step, int *end_func);
int s21_checkSymbols_XxP(const char *str, int *symbols_counter, long *decimal,
                         struct arguments *args, int *end_func, int *flagx);

#endif  // SRC_S21_STRING_H_
