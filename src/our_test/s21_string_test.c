#include "../s21_string.h"
#define BUFF_SIZE 512

#include <check.h>
#include <string.h>

START_TEST(s21_strlen_test) {
  char test_1[] = "BrewMaster";
  char test_2[] = "Hello";
  char test_3[] = "1\0";
  char test_4[] = " ";
  char test_5[] = "123\0456";
  char test_6[] = "qqq\\\0";
  char test_8[] = "";
  char test_10[] = "1";

  ck_assert_int_eq(s21_strlen(test_1), strlen(test_1));
  ck_assert_int_eq(s21_strlen(test_2), strlen(test_2));
  ck_assert_int_eq(s21_strlen(test_3), strlen(test_3));
  ck_assert_int_eq(s21_strlen(test_4), strlen(test_4));
  ck_assert_int_eq(s21_strlen(test_5), strlen(test_5));
  ck_assert_int_eq(s21_strlen(test_6), strlen(test_6));
  ck_assert_int_eq(s21_strlen(test_8), strlen(test_8));
  ck_assert_int_eq(s21_strlen(test_10), strlen(test_10));
}
END_TEST

START_TEST(s21_memchr_test) {
  char test1[] = "BrewMaster";
  char test2 = 'M';
  char test3 = 'r';
  char test4[] = "8919/\0";
  char test5[] = "?";
  char test6 = 'h';
  char test7 = ' ';
  char test8 = '/';
  char test9 = '\0';
  char test_8[] = "";
  char test_10[] = "1";
  char test_11 = '1';
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test2, 10),
                    (unsigned long)memchr(test1, test2, 10));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, test3, 10),
                    (unsigned long)memchr(test1, test3, 10));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test6, 7),
                    (unsigned long)memchr(test4, test6, 7));
  ck_assert_uint_eq((unsigned long)s21_memchr(test5, test7, 1),
                    (unsigned long)memchr(test5, test7, 1));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test8, 7),
                    (unsigned long)memchr(test4, test8, 7));
  ck_assert_uint_eq((unsigned long)s21_memchr(test4, test9, 7),
                    (unsigned long)memchr(test4, test9, 7));
  ck_assert_uint_eq((unsigned long)s21_memchr(test_8, test7, 1),
                    (unsigned long)memchr(test_8, test7, 1));
  ck_assert_uint_eq((unsigned long)s21_memchr(test_10, test_11, 1),
                    (unsigned long)memchr(test_10, test_11, 1));
}
END_TEST

START_TEST(s21_memcmp_test) {
  char test1[] = "It's hard to be god";
  char test2[] = "Code like god";
  char test3[] = "\0";
  char test4[] = "Wanna\0 sleep";
  char test5[] = "Wanna\0 sleep";
  char test_8[] = "";
  char test_9[] = "";
  char test_10[] = "1";
  char test_11[] = "1";
  ck_assert_uint_eq(s21_memcmp(test1, test2, 14) == 0,
                    memcmp(test1, test2, 14) == 0);
  ck_assert_uint_eq(s21_memcmp(test1, test3, 2) > 0,
                    memcmp(test1, test3, 2) > 0);
  ck_assert_uint_eq(s21_memcmp(test2, test3, 2) > 0,
                    memcmp(test2, test3, 2) > 0);
  ck_assert_uint_eq(s21_memcmp(test4, test1, 9) > 0,
                    memcmp(test4, test1, 9) > 0);
  ck_assert_uint_eq(s21_memcmp(test4, test5, 7) == 0,
                    memcmp(test4, test5, 7) == 0);
  ck_assert_uint_eq(s21_memcmp(test_8, test_9, 1) == 0,
                    memcmp(test_8, test_9, 1) == 0);
  ck_assert_uint_eq(s21_memcmp(test_10, test_11, 1) == 0,
                    memcmp(test_10, test_11, 1) == 0);
}
END_TEST

START_TEST(s21_memcpy_test) {
  char test_1[BUFF_SIZE] = "Vengeful_Spirit";
  char test_2[BUFF_SIZE] = "  ";
  char test_3[BUFF_SIZE] = "///  ";
  char test_4[BUFF_SIZE] = "   & ///";
  char test_5[BUFF_SIZE] = "";
  char test_6[BUFF_SIZE] = "8922486";
  char test_7[BUFF_SIZE] = "5526\0123";
  char test_8[BUFF_SIZE] = "";
  char test_9[BUFF_SIZE] = "";
  char test_10[BUFF_SIZE] = "1";
  char test_11[BUFF_SIZE] = "1";

  ck_assert_str_eq(s21_memcpy(test_1, test_2, 2), memcpy(test_1, test_2, 2));
  ck_assert_str_eq(s21_memcpy(test_3, test_4, 6), memcpy(test_3, test_4, 6));
  ck_assert_str_eq(s21_memcpy(test_5, test_6, 4), memcpy(test_5, test_6, 4));
  ck_assert_str_eq(s21_memcpy(test_6, test_7, 4), memcpy(test_6, test_7, 4));
  ck_assert_str_eq(s21_memcpy(test_8, test_9, 1), memcpy(test_8, test_9, 1));
  ck_assert_str_eq(s21_memcpy(test_10, test_11, 1),
                   memcpy(test_10, test_11, 1));
}
END_TEST

START_TEST(s21_memmove_test) {
  char src[] = "Team";
  char dest[] = "1111 Spirit";
  size_t n = 4;

  char csrc[] = "Team";
  char cdest[] = "1111 Spirit";
  ck_assert_str_eq(s21_memmove(dest, src, n), memmove(cdest, csrc, n));
  ck_assert_str_eq(dest, cdest);
  ck_assert_str_eq(dest, "Team Spirit");

  char dest_cover[] = "9554358919";
  char *src_cover = dest_cover + 6;
  s21_memmove(dest_cover, src_cover, n);
  ck_assert_str_eq(dest_cover, "8919358919");

  char dest_cover2[] = "1";
  char cdest2[] = "";
  ck_assert_str_eq(s21_memmove(dest_cover2, cdest2, 1),
                   memmove(dest_cover2, cdest2, 1));
  char dest_cover3[] = "";
  char cdest3[] = "";
  ck_assert_str_eq(s21_memmove(dest_cover3, cdest3, 1),
                   memmove(dest_cover3, cdest3, 1));
}
END_TEST

START_TEST(s21_memset_test) {
  unsigned char test1[10] = "Jonny WTF";
  unsigned char test2[10] = "Lochanta";
  ck_assert_uint_eq((unsigned long)s21_memset(test1, '-', 10),
                    (unsigned long)memset(test1, '-', 10));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, '6', 10),
                    (unsigned long)memchr(test1, '6', 10));
  ck_assert_uint_eq((unsigned long)s21_memchr(test2, '!', 6),
                    (unsigned long)memchr(test2, '!', 6));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, '9', 0),
                    (unsigned long)memchr(test1, '9', 0));
  ck_assert_uint_eq((unsigned long)s21_memchr(test1, 'a', 5),
                    (unsigned long)memchr(test1, 'a', 5));
  ck_assert_uint_eq((unsigned long)s21_memchr(test2, '>', 3),
                    (unsigned long)memchr(test2, '>', 3));
  ck_assert_uint_eq((unsigned long)s21_memchr(test2, ' ', 1),
                    (unsigned long)memchr(test2, ' ', 1));
}
END_TEST

START_TEST(s21_strcat_test) {
  char test1[] = "EA Sport I love this game";
  char test3[] = "\0";
  ck_assert_uint_eq((unsigned long)s21_strcat(test1, test3),
                    (unsigned long)strcat(test1, test3));

  char test5[] = "1\0";
  char test4[] = "\0";
  ck_assert_uint_eq((unsigned long)s21_strcat(test5, test4),
                    (unsigned long)strcat(test5, test4));
  char test6[] = "";
  char test7[] = "";
  ck_assert_uint_eq((unsigned long)s21_strcat(test6, test7),
                    (unsigned long)strcat(test6, test7));
  char test8[5] = "1\0";
  char test9[5] = "1";
  ck_assert_uint_eq((unsigned long)s21_strcat(test8, test9),
                    (unsigned long)strcat(test8, test9));
  char test2[5] = "1";
  char test10[5] = "1";
  ck_assert_uint_eq((unsigned long)s21_strcat(test2, test10),
                    (unsigned long)strcat(test2, test10));
}
END_TEST

START_TEST(s21_strncat_test) {
  char test_1[16] = "Happy";
  char test_2[16] = " New Year";
  char test_3[2] = "5";
  char test_4[] = "";
  char str1[99] = "Regular";
  char str2[99] = "Regular";
  char str3[] = " normal mother fucker";
  char str4[99] = "";
  char str5[99] = "";
  char str6[99] = "1";
  char str7[99] = "1";

  ck_assert_str_eq(strcat(str1, str3), s21_strcat(str2, str3));
  ck_assert_str_eq(strcat(str4, str5), s21_strcat(str4, str5));
  ck_assert_str_eq(strcat(str6, str7), s21_strcat(str6, str7));
  ck_assert_str_eq(s21_strncat(test_1, test_2, 9), "Happy New Year");
  ck_assert_str_eq(s21_strncat(test_3, test_4, 0), strncat(test_3, test_4, 0));
}
END_TEST

START_TEST(s21_strchr_test) {
  char str1[] = "Dota2";
  int symbol1 = 'o';
  char *ach1 = s21_strchr(str1, symbol1);
  ck_assert_str_eq(ach1, "ota2");

  char str2[] = "Dota2";
  int symbol2 = 'o';
  char *ach2 = strchr(str2, symbol2);
  ck_assert_str_eq(ach1, ach2);
  ck_assert_str_eq(str1, str2);

  char str3[] = "Abcdefg";
  int symbol3 = '\0';
  char *ach3 = s21_strchr(str3, symbol3);

  char str4[] = "Abcdefg";
  int symbol4 = '\0';
  char *ach4 = strchr(str4, symbol4);
  ck_assert_str_eq(ach3, ach4);
  ck_assert_str_eq(str3, str4);

  char str5[] = "abcd";
  int symbol5 = 'a';
  char *ach5 = s21_strchr(str5, symbol5);
  char str6[] = "abcd";
  int symbol6 = 'a';
  char *ach6 = strchr(str6, symbol6);
  ck_assert_str_eq(ach5, ach6);
  ck_assert_str_eq(str5, str6);

  char str7[] = "abcd";
  int symbol7 = 'd';
  char *ach7 = s21_strchr(str7, symbol7);
  char str8[] = "abcd";
  int symbol8 = 'd';
  char *ach8 = strchr(str8, symbol8);
  ck_assert_str_eq(ach7, ach8);
  ck_assert_str_eq(str7, str8);
}
END_TEST

START_TEST(s21_strcmp_test) {
  char test1[] = "Shadow fiend";
  char test2[] = "Shadow fiend";
  char test3[] = "Lina";
  char test4[] = "Pudge";
  char test5[] = "   ";
  char test6[] = "\0HH";
  char test7[] = "";
  char test8[] = "";
  char test9[] = "1";
  char test10[] = "1";
  ck_assert_uint_eq((unsigned long)s21_strcmp(test1, test2) == 0,
                    (unsigned long)strcmp(test1, test2) == 0);
  ck_assert_uint_eq((unsigned long)s21_strcmp(test3, test4) > 0,
                    (unsigned long)strcmp(test3, test4) > 0);
  ck_assert_uint_eq((unsigned long)s21_strcmp(test5, test6) < 0,
                    (unsigned long)strcmp(test5, test6) < 0);
  ck_assert_uint_eq((unsigned long)s21_strcmp(test7, test8) == 0,
                    (unsigned long)strcmp(test7, test8) == 0);
  ck_assert_uint_eq((unsigned long)s21_strcmp(test9, test10) == 0,
                    (unsigned long)strcmp(test9, test10) == 0);
}
END_TEST

START_TEST(s21_strncmp_test) {
  char str1[] = "Earth Spirit";
  char str2[] = "EarthShaker";
  char str3[] = "EarthShaker\0";
  char str4[] = "";
  char str5[] = "";

  ck_assert_int_eq(s21_strncmp(str1, str2, 5) == 0,
                   strncmp(str1, str2, 5) == 0);
  ck_assert_int_eq(s21_strncmp(str1, str2, 6) > 0, strncmp(str1, str2, 6) > 0);
  ck_assert_int_eq(s21_strncmp(str1, str3, 10) > 0,
                   strncmp(str1, str3, 10) > 0);
  ck_assert_int_eq(s21_strncmp(str4, str5, 1) == 0,
                   strncmp(str4, str5, 1) == 0);
}
END_TEST

START_TEST(s21_strcpy_test) {
  char test_1[] = "Axe and Primal Beast";
  char test_2[] = "     ";
  char test_3[] = "Axe\0";
  char test_4[] = "Dire\0Radiant";
  char test_5[128] = "";
  char test_6[] = "School 21 and School 42";
  char test_7[] = "";
  char test_8[] = "1";
  ck_assert_str_eq(s21_strcpy(test_1, test_2), strcpy(test_1, test_2));
  ck_assert_str_eq(s21_strcpy(test_2, test_3), strcpy(test_2, test_3));
  ck_assert_str_eq(s21_strcpy(test_4, test_5), strcpy(test_4, test_5));
  ck_assert_str_eq(s21_strcpy(test_5, test_4), strcpy(test_5, test_4));
  ck_assert_str_eq(s21_strcpy(test_6, test_5), strcpy(test_6, test_5));
  ck_assert_str_eq(s21_strcpy(test_7, test_5), strcpy(test_7, test_5));
  ck_assert_str_eq(s21_strcpy(test_8, test_5), strcpy(test_8, test_5));
}
END_TEST

START_TEST(s21_strncpy_test) {
  char str1[] = "Dota2 public society";
  char dest1[15] = "";

  char str2[] = "Dota \0";
  char dest2[10] = "";

  char str3[] = "Dota ";
  char dest3[] = "pulllRequest";

  char str6[] = "Dota ";
  char dest6[] = "pulllRequest";

  char str4[] = "D";
  char dest4[2] = "";

  char str5[] = " ";
  char dest5[2] = "";

  ck_assert_str_eq("Dota2", s21_strncpy(dest1, str1, 5));
  ck_assert_str_eq("Dota ", s21_strncpy(dest2, str2, 5));
  s21_strncpy(dest3, str3, 10);
  strncpy(dest6, str6, 10);
  ck_assert_str_eq(dest3, dest6);

  ck_assert_str_eq("D", s21_strncpy(dest4, str4, 1));
  ck_assert_str_eq(" ", s21_strncpy(dest5, str5, 1));
}
END_TEST

START_TEST(s21_strcspn_test) {
  char test1[] = "DawnBreaker";
  char test2[] = "Dawn";
  char test3[] = "Primal Beast";
  char test4[] = "beast";
  char test5[] = "0/";
  char test6[] = "//#";
  char test7[] = " ";
  char test8[] = "0987654321";
  char test9[] = "0";
  char test10[] = "1";
  ck_assert_uint_eq(s21_strcspn(test1, test2), strcspn(test1, test2));
  ck_assert_uint_eq(s21_strcspn(test3, test4), strcspn(test3, test4));
  ck_assert_uint_eq(s21_strcspn(test3, test5), strcspn(test3, test5));
  ck_assert_uint_eq(s21_strcspn(test3, test6), strcspn(test3, test6));
  ck_assert_uint_eq(s21_strcspn(test3, test7), strcspn(test3, test7));
  ck_assert_uint_eq(s21_strcspn(test4, test8), strcspn(test4, test8));
  ck_assert_uint_eq(s21_strcspn(test2, test7), strcspn(test2, test7));
  ck_assert_uint_eq(s21_strcspn(test8, test9), strcspn(test8, test9));
  ck_assert_uint_eq(s21_strcspn(test8, test10), strcspn(test8, test10));
}
END_TEST

START_TEST(s21_strpbrk_test) {
  char str_for_strpbrk[] = "Templar Assasin";
  char str_oneof[] = "Ass";
  ck_assert_str_eq(s21_strpbrk(str_for_strpbrk, str_oneof), "Assasin");
  ck_assert_str_eq(s21_strpbrk(str_for_strpbrk, str_oneof),
                   strpbrk(str_for_strpbrk, str_oneof));
  char str_for_strpbrk2[] = "State Of New York";
  char str_oneof2[] = "Of";

  ck_assert_str_eq(s21_strpbrk(str_for_strpbrk2, str_oneof2),
                   strpbrk(str_for_strpbrk2, str_oneof2));

  char *str = "This is the road to hell";
  char *empty = "";
  char *empty2 = "T";
  char *empty3 = "l";

  ck_assert(s21_strpbrk(str, empty) == s21_NULL);
  ck_assert_uint_eq((unsigned long)s21_strpbrk(str, empty),
                    (unsigned long)strpbrk(str, empty));
  ck_assert_uint_eq((unsigned long)s21_strpbrk(str, empty2),
                    (unsigned long)strpbrk(str, empty2));
  ck_assert_uint_eq((unsigned long)s21_strpbrk(str, empty3),
                    (unsigned long)strpbrk(str, empty3));
}
END_TEST

START_TEST(s21_strrchr_test) {
  char test1[] = "9876 54326 10";
  char test2[] = "a;b;c;d;e;f;g;h;i;j;h";
  char test3[] = " $ ! @ # $ ^ & * ( $ ) $ ";
  char test4[] = "$";

  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, '6'),
                    (unsigned long)strrchr(test1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, ' '),
                    (unsigned long)strrchr(test1, ' '));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, '6'),
                    (unsigned long)strrchr(test1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, 'h'),
                    (unsigned long)strrchr(test2, 'h'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test3, '$'),
                    (unsigned long)strrchr(test3, '$'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, ';'),
                    (unsigned long)strrchr(test2, ';'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test3, ' '),
                    (unsigned long)strrchr(test3, ' '));
  ck_assert_str_eq(s21_strrchr(test2, '\0'), strrchr(test2, '\0'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test4, '$'),
                    (unsigned long)strrchr(test4, '$'));
}
END_TEST

START_TEST(s21_strspn_test) {
  char str1[] = "0987654321";
  char str2[] = "012";
  char str3[] = "abcdefg";
  char str4[] = "gda";
  char str5[] = "!@#$^&*()";
  char str6[] = ")(*";
  char str7[] = ")";
  char str8[] = "";

  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));
  ck_assert_int_eq(s21_strspn(str3, str4), strspn(str3, str4));
  ck_assert_int_eq(s21_strspn(str5, str6), strspn(str5, str6));
  ck_assert_int_eq(s21_strspn(str5, str7), strspn(str5, str7));
  ck_assert_int_eq(s21_strspn(str5, str8), strspn(str5, str8));
}

START_TEST(s21_strstr_test) {
  char test_1[] = "Monkey King";
  char test_2[] = "king";
  char test_3[] = "AssassinAsssasssinAsasin";
  char test_4[] = "Assassin";
  char test_5[] = "1234";
  char test_6[] = "";
  char test_7[] = "5123451234512345";
  char test_8[] = "1234";
  char test_9[] = "1";
  char test_10[] = "4";

  ck_assert_ptr_eq(s21_strstr(test_1, test_2), strstr(test_1, test_2));
  ck_assert_ptr_eq(s21_strstr(test_3, test_4), strstr(test_3, test_4));
  ck_assert_ptr_eq(s21_strstr(test_5, test_6), strstr(test_5, test_6));
  ck_assert_ptr_eq(s21_strstr(test_4, test_5), strstr(test_4, test_5));
  ck_assert_ptr_eq(s21_strstr(test_7, test_8), strstr(test_7, test_8));
  ck_assert_ptr_eq(s21_strstr(test_8, test_9), strstr(test_8, test_9));
  ck_assert_ptr_eq(s21_strstr(test_8, test_10), strstr(test_8, test_10));
}
END_TEST

START_TEST(s21_strtok_test) {
  char str_strtok1[] = "Anti-mage/Medusa/Clinkz(Weaver)Witch Doctor";
  char delim1[] = "/";

  char str_strtok2[] = "Anti-mage/Medusa/Clinkz(Weaver)Witch Doctor";
  char delim2[] = "/";
  char *my_strtok = s21_strtok(str_strtok1, delim1);
  char *origin_strtok = strtok(str_strtok2, delim2);
  while (my_strtok != s21_NULL) {
    ck_assert_str_eq(my_strtok, origin_strtok);
    my_strtok = s21_strtok(s21_NULL, delim1);
    origin_strtok = strtok(s21_NULL, delim2);
  }
}

END_TEST

START_TEST(s21_to_upper_test) {
  char str1[] = "everything seems imposible until it's done";
  char str2[] = "dota2forever";
  char str3[] = "";
  char str4[] = "a";

  char *str = s21_to_upper(str1);

  if (str) {
    ck_assert_str_eq(str, "EVERYTHING SEEMS IMPOSIBLE UNTIL IT'S DONE");
    free(str);
  }

  str = s21_to_upper(str2);

  if (str) {
    ck_assert_str_eq(str, "DOTA2FOREVER");
    free(str);
  }
  str = s21_to_upper(str3);

  if (str) {
    ck_assert_str_eq(str, "");
    free(str);
  }

  str = s21_to_upper(str4);

  if (str) {
    ck_assert_str_eq(str, "A");
    free(str);
  }
}
END_TEST

START_TEST(s21_to_lower_test) {
  char str1[] = "I'M JUST a REGULAR EVERY DAy";
  char str2[] = "DOTA2FOREVER";
  char str3[] = "";
  char str4[] = "A";
  char *str = s21_to_lower(str1);

  if (str) {
    ck_assert_str_eq(str, "i'm just a regular every day");
    free(str);
  }

  str = s21_to_lower(str2);

  if (str) {
    ck_assert_str_eq(str, "dota2forever");
    free(str);
  }

  str = s21_to_lower(str3);

  if (str) {
    ck_assert_str_eq(str, "");
    free(str);
  }

  str = s21_to_lower(str4);

  if (str) {
    ck_assert_str_eq(str, "a");
    free(str);
  }
}
END_TEST

START_TEST(s21_insert_test) {
  char *src = "Regular!";
  char *str = ", brainfucker";
  char *new_str = {0};
  new_str = s21_insert(src, str, 7);
  if (new_str) {
    ck_assert_str_eq(new_str, "Regular, brainfucker!");
    free(new_str);
  }

  new_str = s21_insert(src, "", 9);
  ck_assert(new_str == s21_NULL);
  free(new_str);

  new_str = s21_insert("Regular!", ", brainfucker!!", 7);
  if (new_str) {
    ck_assert_str_eq(new_str, "Regular, brainfucker!!!");
    free(new_str);
  }

  new_str = s21_insert("Regular!", ", brainfucker!!", 35);
  ck_assert(new_str == s21_NULL);
  free(new_str);

  new_str = s21_insert("", "", 0);
  if (new_str) {
    ck_assert_str_eq(new_str, "");
    free(new_str);
  }

  char *src1 = "1";
  char *str1 = "1";
  char *new_str2 = s21_insert(src1, str1, 1);
  if (new_str2) {
    ck_assert_str_eq(new_str2, "11");
    free(new_str2);
  }
}

END_TEST

START_TEST(s21_trim_test) {
  char *result;
  char *banner = " \n   !* * *'\' Much Ado About Nothing * * '\'*  !\n";
  result = s21_trim(banner, " *!\n '\'");
  if (result) {
    ck_assert_str_eq(result, "Much Ado About Nothing");
    free(result);
  }

  char *banner2 = "xxx Hello, world! xxx ---";
  char *format_str = "x -";
  result = s21_trim(banner2, format_str);
  if (result) {
    ck_assert_str_eq(result, "Hello, world!");
    free(result);
  }

  char *empty_str = "";
  result = s21_trim(empty_str, s21_NULL);
  if (result) {
    ck_assert_str_eq(result, "");
    free(result);
  }

  char *empty_format = "";
  result = s21_trim(s21_NULL, empty_format);
  ck_assert(result == s21_NULL);

  result = s21_trim(banner, empty_format);
  if (result) {
    ck_assert_str_eq(result, "!* * *'' Much Ado About Nothing * * ''*  !");
    free(result);
  }

  result = s21_trim("banner \n", "\n");
  if (result) {
    ck_assert_str_eq(result, "banner ");
    free(result);
  }

  result = s21_trim(empty_str, " \n\0");
  if (result) {
    ck_assert_str_eq(result, "");
    free(result);
  }
}
END_TEST

START_TEST(s21_strerror_test) {
  char *case1 = s21_strerror(0);
  char *case2 = strerror(0);
  ck_assert_uint_eq((unsigned long)*case1, (unsigned long)*case2);

  char *case9 = s21_strerror(1);
  char *case10 = strerror(1);
  ck_assert_uint_eq((unsigned long)*case9, (unsigned long)*case10);

  char *case0 = s21_strerror(106);
  char *case3 = strerror(106);
  ck_assert_uint_eq((unsigned long)*case0, (unsigned long)*case3);

  char *case7 = s21_strerror(200);
  char *case8 = strerror(200);
  ck_assert_uint_eq((unsigned long)*case7, (unsigned long)*case8);

  char *case5 = s21_strerror(INT_MAX);
  char *case6 = strerror(INT_MAX);
  ck_assert_uint_eq((unsigned long)*case5, (unsigned long)*case6);

  char *case11 = s21_strerror(-1);
  char *case12 = strerror(-1);
  ck_assert_uint_eq((unsigned long)*case11, (unsigned long)*case12);
}
END_TEST

/*-----------------SPRINTF-----------------*/

START_TEST(simplE_int11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple value %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(precisE_int11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_int1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(minus_width_int1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(plus_width_int1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(padding_int1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%012i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(star_width_int1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0*d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(star_precision_int1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(many_flags_many_ints1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char format[] = "%0.*i %d %4.*i %013d %d";
  int val = 69;
  ck_assert_int_eq(
      s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
      sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_long_int1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_short_int1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_another_long_int1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*ld";
  long val = 8581385185;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(zero_precision_zero_int1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(space_flag_int1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val1_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val1_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val1_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val1_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val1_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val1_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val1_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal1_width1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal1_flags1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal1_precision1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal1_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal1_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal1_hash) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#o";
  int val = 57175;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal1_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal1_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal1_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo, %o, %ho, %.5o, %5.o";
  long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_zero1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_width1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_flags1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_precision1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_many1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-10x%x%X%#x%#X%5.5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
                   sprintf(str2, format, val, val, val, val, val, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_many1_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-5.10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_zero1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_huge1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 18571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_short1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#hx";
  unsigned short val = 12352;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_long1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#lx";
  unsigned long val = 18571757371571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_one_longer_width1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#2x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_two_longer_width1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#30x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_char1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(one_precision11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_flags11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_width11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many11_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val = "I LOVE string1S AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string1_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15s";
  char *val = "I LOVE string1S AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string1_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string1_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-15.9s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string1_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG string1";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string1_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s%s%s%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG string1";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(ptr1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(ptr1_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(ptr1_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(null_ptr1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%p";
  char *ptr1 = NULL;
  ck_assert_int_eq(s21_sprintf(str1, format, ptr1),
                   sprintf(str2, format, ptr1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string1_width_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(n_specifier1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int ret = 0;
  char *format = "Hello, my sexy little aboba abobushka abobina %n";
  ck_assert_int_eq(s21_sprintf(str1, format, &ret),
                   sprintf(str2, format, &ret));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 513515.131513515151351;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_width1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%10Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision1_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_precision1_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision1_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_precision1_huge_negative) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_huge1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_flags1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_many1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0f %.lf %Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_precision1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.16Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_precision1_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_precision1_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Le";
  long double val = 15.000009121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_precision1_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = 0.000000000000000123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_precision1_huge_negative) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_huge1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Le";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_flags1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%015E";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_width1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%15e";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_many1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0e %.le %Le %e %le %Le";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 0.094913941;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(E_int1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.17LE";
  long double val = 4134121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(all_empty1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(empty_format_and_parameters1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_char1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_string1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_string1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_dec1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_dec1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111onE_int1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                   sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_float1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_float1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%f %f %f %f", -999.666, 0.0001, 666.999, -100.001),
      sprintf(str2, "%f %f %f %f", -999.666, 0.0001, 666.999, -100.001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                   sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                           (unsigned)666, (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_char1_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_char1_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                   sprintf(str2, "%-8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_char_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
      sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START HEX TEST
START_TEST(test_111one_hex_lower) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%x", (unsigned)INT32_MIN),
                   sprintf(str2, "%x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", INT32_MAX),
                   sprintf(str2, "%x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_hex_upper) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%X", (unsigned)INT32_MIN),
                   sprintf(str2, "%X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", INT32_MAX),
                   sprintf(str2, "%X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_lower) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_upper) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST

// START HEX WITH ALIGNMENT
START_TEST(test_111one_hex_lower_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-3x", (unsigned)INT32_MIN),
                   sprintf(str2, "%-3x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", 0), sprintf(str2, "%-3x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", INT32_MAX),
                   sprintf(str2, "%-3x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_hex_lower_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%13x", (unsigned)INT32_MIN),
                   sprintf(str2, "%13x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", 0), sprintf(str2, "%13x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", INT32_MAX),
                   sprintf(str2, "%13x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_hex_upper_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MIN),
                   sprintf(str2, "%-60X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", 0), sprintf(str2, "%-60X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MAX),
                   sprintf(str2, "%-60X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_hex_upper_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%7X", (unsigned)INT32_MIN),
                   sprintf(str2, "%7X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", 0), sprintf(str2, "%7X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", INT32_MAX),
                   sprintf(str2, "%7X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_lower_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_upper_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(
      s21_sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// START HEX WITH ALIGNMENT

// START HEX TEST WITH #
START_TEST(test_111one_hex_with_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MIN),
                   sprintf(str2, "%#x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", 0), sprintf(str2, "%#x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MAX),
                   sprintf(str2, "%#x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_hex_upper_with_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MIN),
                   sprintf(str2, "%#X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", 0), sprintf(str2, "%#X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MAX),
                   sprintf(str2, "%#X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_lower_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_upper_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH #

// START HEX TEST with width *
START_TEST(test_111one_hex_lower_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MIN),
                   sprintf(str2, "%*x", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, 0),
                   sprintf(str2, "%*x", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MAX),
                   sprintf(str2, "%*x", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_hex_upper_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MIN),
                   sprintf(str2, "%*X", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, 0),
                   sprintf(str2, "%*X", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MAX),
                   sprintf(str2, "%*X", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_lower_with_width_star_and_align_and_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#*x%*x%-12x%3x%*x", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*x%*x%-12x%3x%*x", 9, 127312897, -0, -1,
                           199, -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_upper_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1, 199,
                           -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH Width *

// START HEX TEST WITH precision
START_TEST(test_111one_hex_lower_with_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int a = s21_sprintf(str1, "%*.6x", 11, 0);
  int b = sprintf(str2, "%*.6x", 11, 0);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_hex_upper_with_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int a = s21_sprintf(str1, "%*.6X", 11, INT32_MIN);
  int b = sprintf(str2, "%*.6X", 11, (unsigned)INT32_MIN);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_lower_with_precision_and_other) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int a = s21_sprintf(
      str1, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
      4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
  int b = sprintf(str2, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x",
                  3, 126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9,
                  41, -41, 33);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111many_hex_upper_with_precision_and_other) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X",
                  3, -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9,
                  41, -41, 33),
      sprintf(str2, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
              -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41,
              -41, 33));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH precision

// START HEX TEST WITH Length
START_TEST(test_111one_hex_lower_with_length) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111one_hex_upper_with_length) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%10ld";

  ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%1.1f";

  ck_assert_int_eq(s21_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%8.3c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+5.5d aboba";

  int val = 10000;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);
  ck_assert_int_eq(a, b);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7.7f";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
                   sprintf(str2, format, 11.123456));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf7) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7.4s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
                   sprintf(str2, format, "aboba floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%6.6u";

  ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                   sprintf(str2, format, 12341151));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf9) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%li%ld%lu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
                   sprintf(str2, format, 666666666666, 777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf10) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%hi%hd%hu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
                   sprintf(str2, format, 666, -777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+li%+lu%+d%+lf";

  ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
                   sprintf(str2, format, -123, 321, -5555, -1213.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf12) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-11.11li%-35.5lu%-3.5ld%33.16Lf";
  long double k = 333.33213;

  ck_assert_int_eq(
      s21_sprintf(str1, format, 66666666666, 5555555555, 44444444444, k),
      sprintf(str2, format, 66666666666, 5555555555, 44444444444, k));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf14) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% 0.0li% 0.0lu% 0.0ld % 0.0lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf15) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% 0.0hi% 0.0hu% 0.0hd % 0.0hf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf16) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf17) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
                   sprintf(str2, format, "aboba likes floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf18) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% s% c";

  ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
                   sprintf(str2, format, "", 'f'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf19) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%210s";

  ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                   sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf20) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-115s";

  ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
                   sprintf(str2, format, "Nick her"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf24) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

  ck_assert_int_eq(
      s21_sprintf(str1, format, 'f', 21, 42, 666.666,
                  "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
      sprintf(str2, format, 'f', 21, 42, 666.666,
              "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf25) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 121.123),
                   sprintf(str2, format, 121.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf28) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int n1;
  int n2;
  int a = s21_sprintf(str1, "%d%n", 123, &n1);
  int b = sprintf(str2, "%d%n", 123, &n2);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf29) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.111),
                   sprintf(str2, format, 111.111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf30) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-.1d";

  ck_assert_int_eq(s21_sprintf(str1, format, 111), sprintf(str2, format, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf31) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%e";
  double x = 111;
  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf32) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%e%e%e%e";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.111, 222.2222, 666., -555.125),
                   sprintf(str2, format, 11.111, 222.2222, 666., -555.125));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf33) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%Le";
  long double x = 122.1231;

  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf35) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.10e";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.184314818),
                   sprintf(str2, format, 111.184314818));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf36) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%5.3e%3.2e%lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.000111, 111.555, 1.999),
                   sprintf(str2, format, 0.000111, 111.555, 1.999));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf37) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.666666),
                   sprintf(str2, format, 0.666666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf38) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%E%E%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.0000999, 111.9999, 6.666),
                   sprintf(str2, format, 0.0000999, 111.9999, 6.666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf39) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%e ABOBA %Lf %Lf %Le";
  long double c = 848181;
  long double a = 0.00000001;
  long double b = 1111111.11;
  ck_assert_int_eq(s21_sprintf(str1, format, 123.123, a, b, c),
                   sprintf(str2, format, 123.123, a, b, c));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf40) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%#e Floppa %#E%#f";

  ck_assert_int_eq(s21_sprintf(str1, format, 123.111, 0.0000999, 0.555),
                   sprintf(str2, format, 123.111, 0.0000999, 0.555));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf41) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.Lf";
  long double a = 7.9418438184;

  ck_assert_int_eq(s21_sprintf(str1, format, a), sprintf(str2, format, a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf42) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%#5p";
  int a = 5;
  ck_assert_int_eq(s21_sprintf(str1, format, &a), sprintf(str2, format, &a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf43) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5o";

  ck_assert_int_eq(s21_sprintf(str1, format, 12345),
                   sprintf(str2, format, 12345));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_111sprintf44) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%#5lX";
  long hex = 314818438141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_trailing_zero11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.50300;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_large1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 5131.43141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_small1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_precision1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_precision1_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.0g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_precision1_missing) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_many1_zeroes_in_front1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 0.0004;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_one_zero1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_zero1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_mantiss1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_mantiss1_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%5.8g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_short_no_mantiss1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(LG1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%LG";
  long double hex = 0.000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_many1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%LG %g %G %Lg %.5g";
  long double hex = 0.000005;
  double hex1 = 41.1341;
  double hex2 = 848.9000;
  long double hex3 = 0.0843;
  double hex4 = 0.0005;
  double hex5 = 0.8481481;
  ck_assert_int_eq(s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5),
                   sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_char1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %5c";
  char w = 'c';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}

/*-----------------SSCANF------------------*/
START_TEST(s21_sscanf_test_16_o_option) {
  int a = 0;
  int b = 0;

  int c = 0;
  int d = 0;

  int result1 = s21_sscanf("12345 36", "%o %o", &a, &b);
  int result_origin1 = sscanf("12345 36", "%o %o", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  a = 0;
  b = 0;

  result1 = s21_sscanf("12345", "%o", &a);
  result_origin1 = sscanf("12345", "%o", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;

  result1 = s21_sscanf("-12345", "%o", &a);
  result_origin1 = sscanf("-12345", "%o", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 10;
  b = 10;

  result1 = s21_sscanf("0", "%o", &a);
  result_origin1 = sscanf("0", "%o", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;
  const char *format_str = "-2345";

  result1 = s21_sscanf(format_str, "%o", &a);
  result_origin1 = sscanf(format_str, "%o", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;
  const char *format_str1 = "-2345 6789";

  result1 = s21_sscanf(format_str1, "%o %o", &a, &c);
  result_origin1 = sscanf(format_str1, "%o %o", &b, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(c, d);

  short int g, h, j, k;
  result1 = s21_sscanf(format_str1, "%ho %ho", &g, &h);
  result_origin1 = sscanf(format_str1, "%ho %ho", &j, &k);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(g, j);
  ck_assert_int_eq(h, k);

  long int u, i, o, p;
  result1 = s21_sscanf(format_str1, "%3lo %lo", &u, &i);
  result_origin1 = sscanf(format_str1, "%3lo %lo", &o, &p);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(u, o);
  ck_assert_int_eq(i, p);

  int x = 0;
  int y = 0;
  const char *format_str2 = "-2345 6789 5555";

  result1 = s21_sscanf(format_str2, "%o %o %o", &a, &c, &x);
  result_origin1 = sscanf(format_str2, "%o %o %o", &b, &d, &y);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(c, d);
  ck_assert_int_eq(x, y);

  result1 = s21_sscanf(format_str1, "%o %*o", &a);
  result_origin1 = sscanf(format_str1, "%o %*o", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  result1 = s21_sscanf(format_str1, "%*o %o", &a);
  result_origin1 = sscanf(format_str1, "%*o %o", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  result1 = s21_sscanf(format_str2, "%*o %o %o", &a, &c);
  result_origin1 = sscanf(format_str2, "%*o %o %o", &b, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(c, d);

  result1 = s21_sscanf(format_str2, "%o %*o %o", &a, &c);
  result_origin1 = sscanf(format_str2, "%o %*o %o", &b, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(c, d);

  result1 = s21_sscanf(format_str2, "%o %o %*o", &a, &c);
  result_origin1 = sscanf(format_str2, "%o %o %*o", &b, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(c, d);

  result1 = s21_sscanf(format_str2, "%o %*o %*o", &a);
  result_origin1 = sscanf(format_str2, "%o %*o %*o", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  result1 = s21_sscanf(format_str2, "%*o %o %*o", &a);
  result_origin1 = sscanf(format_str2, "%*o %o %*o", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  result1 = s21_sscanf(format_str2, "%*o %*o %o", &a);
  result_origin1 = sscanf(format_str2, "%*o %*o %o", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);
}
END_TEST
START_TEST(s21_sscanf_test_17_o_option) {
  uint32_t a1, a2;
  const char str[] = "          \n             \n     5";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}

END_TEST
START_TEST(s21_sscanf_test_18_o_option) {
  uint16_t a1, a2;
  const char str[] = "12";
  const char fstr[] = "%ho";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(s21_sscanf_test_17_d_option) {
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;

  int result1 = s21_sscanf("12345 36", "%d %d", &a, &b);
  int result_origin1 = sscanf("12345 36", "%d %d", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  short int g = 0;
  short int h = 0;
  short int j = 0;
  short int k = 0;

  result1 = s21_sscanf("12345 36", "%hd %hd", &g, &h);
  result_origin1 = sscanf("12345 36", "%hd %hd", &j, &k);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(g, j);
  ck_assert_int_eq(h, k);

  result1 = s21_sscanf("0 0", "%d %d", &a, &b);
  result_origin1 = sscanf("0 0", "%d %d", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  result1 = s21_sscanf("-123445 -123", "%d %d", &a, &b);
  result_origin1 = sscanf("-123445 -123", "%d %d", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str1 = "123 456";

  result1 = s21_sscanf(format_str1, "%d %d", &a, &b);
  result_origin1 = sscanf(format_str1, "%d %d", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str2 = "-123 -456";

  result1 = s21_sscanf(format_str2, "%d %d", &a, &b);
  result_origin1 = sscanf(format_str2, "%d %d", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str3 = "0 0";

  result1 = s21_sscanf(format_str3, "%d %d", &a, &b);
  result_origin1 = sscanf(format_str3, "%d %d", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str4 = "123 456";

  result1 = s21_sscanf(format_str4, "%10d %10d", &a, &b);
  result_origin1 = sscanf(format_str4, "%10d %10d", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str5 = "-123 -456";

  result1 = s21_sscanf(format_str5, "%2d %4d", &a, &b);
  result_origin1 = sscanf(format_str5, "%2d %4d", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str6 = "0 0";

  result1 = s21_sscanf(format_str6, "%5d %5d", &a, &b);
  result_origin1 = sscanf(format_str6, "%5d %5d", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str7 = "2147483647 -2147483648";

  result1 = s21_sscanf(format_str7, "%5d %5d", &a, &b);
  result_origin1 = sscanf(format_str7, "%5d %5d", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  long z1 = 0, z2 = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0, d1 = 0, d2 = 0;
  const char fstr[] = "%ld %ld %ld %ld";
  const char str[] = "123 456 789 111";

  int res1 = s21_sscanf(str, fstr, &z1, &x1, &y1, &d1);
  int res2 = sscanf(str, fstr, &z2, &x2, &y2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(z1, z2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
  ck_assert_int_eq(d1, d2);

  z1 = 0, z2 = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0, d1 = 0, d2 = 0;
  const char fstr2[] = "%1ld %1ld %1ld %1ld";

  res1 = s21_sscanf(str, fstr2, &z1, &x1, &y1, &d1);
  res2 = sscanf(str, fstr2, &z2, &x2, &y2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(z1, z2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
  ck_assert_int_eq(d1, d2);

  z1 = 0, z2 = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0, d1 = 0, d2 = 0;
  const char fstr3[BUFF_SIZE] = "%3ld %3ld %3ld %3ld";

  res1 = s21_sscanf(str, fstr3, &z1, &x1, &y1, &d1);
  res2 = sscanf(str, fstr3, &z2, &x2, &y2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(z1, z2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
  ck_assert_int_eq(d1, d2);

  z1 = 0, z2 = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0, d1 = 0, d2 = 0;
  const char fstr4[BUFF_SIZE] = "%5ld %5ld %5ld %5ld";

  res1 = s21_sscanf(str, fstr4, &z1, &x1, &y1, &d1);
  res2 = sscanf(str, fstr4, &z2, &x2, &y2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(z1, z2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
  ck_assert_int_eq(d1, d2);

  const char *fstr5 = "123 456";

  result1 = s21_sscanf(fstr5, "%d %*d", &a);
  result_origin1 = sscanf(fstr5, "%d %*d", &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, d);

  result1 = s21_sscanf(fstr5, "%*d %d", &a);
  result_origin1 = sscanf(fstr5, "%*d %d", &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, d);

  const char *fstr6 = "-123 -456";

  result1 = s21_sscanf(fstr6, "%d %*d", &a);
  result_origin1 = sscanf(fstr6, "%d %*d", &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, d);

  result1 = s21_sscanf(fstr6, "%*d %d", &a);
  result_origin1 = sscanf(fstr6, "%*d %d", &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, d);

  const char *fstr7 = "0 0";

  result1 = s21_sscanf(fstr7, "%d %*d", &a);
  result_origin1 = sscanf(fstr7, "%d %*d", &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, d);

  result1 = s21_sscanf(fstr7, "%*d %d", &a);
  result_origin1 = sscanf(fstr7, "%*d %d", &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, d);
}

END_TEST

START_TEST(s21_sscanf_test_19_u_option) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 --5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(s21_sscanf_test_18_u_option) {
  unsigned short a = 0;
  unsigned short b = 0;
  unsigned short c = 0;
  unsigned short d = 0;

  int result1 = s21_sscanf("65535 36", "%hu %hu", &a, &b);
  int result_origin1 = sscanf("65535 36", "%hu %hu", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  result1 = s21_sscanf("0 0", "%hu %hu", &a, &b);
  result_origin1 = sscanf("0 0", "%hu %hu", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  result1 = s21_sscanf("123 123", "%hu %hu", &a, &b);
  result_origin1 = sscanf("123 123", "%hu %hu", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str1 = "123 456";

  result1 = s21_sscanf(format_str1, "%hu %hu", &a, &b);
  result_origin1 = sscanf(format_str1, "%hu %hu", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str2 = "1233 1456";

  result1 = s21_sscanf(format_str2, "%hu %hu", &a, &b);
  result_origin1 = sscanf(format_str2, "%hu %hu", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str3 = "0 0";

  result1 = s21_sscanf(format_str3, "%hu %hu", &a, &b);
  result_origin1 = sscanf(format_str3, "%hu %hu", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str4 = "123 456";

  result1 = s21_sscanf(format_str4, "%10hu %10hu", &a, &b);
  result_origin1 = sscanf(format_str4, "%10hu %10hu", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str5 = "123 456";

  result1 = s21_sscanf(format_str5, "%2hu %4hu", &a, &b);
  result_origin1 = sscanf(format_str5, "%2hu %4hu", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str6 = "0 0";

  result1 = s21_sscanf(format_str6, "%5hu %5hu", &a, &b);
  result_origin1 = sscanf(format_str6, "%5hu %5hu", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str7 = "65535 65535";

  result1 = s21_sscanf(format_str7, "%5hu %5hu", &a, &b);
  result_origin1 = sscanf(format_str7, "%5hu %5hu", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  long int z1 = 0, z2 = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0, d1 = 0, d2 = 0;
  const char fstr4[] = "%lu %lu %lu %lu";
  const char str[] = "123 456 789 111";

  int res1 = s21_sscanf(str, fstr4, &z1, &x1, &y1, &d1);
  int res2 = sscanf(str, fstr4, &z2, &x2, &y2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(z1, z2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
  ck_assert_int_eq(d1, d2);

  z1 = 0, z2 = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0, d1 = 0, d2 = 0;
  const char fstr3[] = "%1lu %1lu %1lu %1lu";

  res1 = s21_sscanf(str, fstr3, &z1, &x1, &y1, &d1);
  res2 = sscanf(str, fstr3, &z2, &x2, &y2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(z1, z2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
  ck_assert_int_eq(d1, d2);

  z1 = 0, z2 = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0, d1 = 0, d2 = 0;
  const char fstr1[] = "%2lu %2lu %2lu %2lu";

  res1 = s21_sscanf(str, fstr1, &z1, &x1, &y1, &d1);
  res2 = sscanf(str, fstr1, &z2, &x2, &y2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(z1, z2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
  ck_assert_int_eq(d1, d2);

  z1 = 0, z2 = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0, d1 = 0, d2 = 0;
  const char fstr2[] = "%5lu %5lu %5lu %5lu";

  res1 = s21_sscanf(str, fstr2, &z1, &x1, &y1, &d1);
  res2 = sscanf(str, fstr2, &z2, &x2, &y2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(z1, z2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(y1, y2);
  ck_assert_int_eq(d1, d2);

  unsigned int aa = 0;
  unsigned int bb = 0;
  unsigned int cc = 0;
  unsigned int dd = 0;

  result1 = s21_sscanf("65535 36", "%u %u", &aa, &bb);
  result_origin1 = sscanf("65535 36", "%u %u", &cc, &dd);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(aa, cc);
  ck_assert_int_eq(bb, dd);

  result1 = s21_sscanf("0 0", "%u %u", &aa, &bb);
  result_origin1 = sscanf("0 0", "%u %u", &cc, &dd);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(aa, cc);
  ck_assert_int_eq(bb, dd);

  result1 = s21_sscanf("123 123", "%u %u", &aa, &bb);
  result_origin1 = sscanf("123 123", "%u %u", &cc, &dd);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(aa, cc);
  ck_assert_int_eq(bb, dd);

  const char *format_str10 = "123 456";

  result1 = s21_sscanf(format_str10, "%u %u", &aa, &bb);
  result_origin1 = sscanf(format_str10, "%u %u", &cc, &dd);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(aa, cc);
  ck_assert_int_eq(bb, dd);

  const char *format_str11 = "1233 1456";

  result1 = s21_sscanf(format_str11, "%u %u", &aa, &bb);
  result_origin1 = sscanf(format_str11, "%u %u", &cc, &dd);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(aa, cc);
  ck_assert_int_eq(bb, dd);

  const char *format_str12 = "0 0";

  result1 = s21_sscanf(format_str12, "%u %u", &aa, &bb);
  result_origin1 = sscanf(format_str12, "%u %u", &cc, &dd);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(aa, cc);
  ck_assert_int_eq(bb, dd);

  const char *format_str13 = "123 456";

  result1 = s21_sscanf(format_str13, "%10u %10u", &aa, &bb);
  result_origin1 = sscanf(format_str13, "%10u %10u", &cc, &dd);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(aa, cc);
  ck_assert_int_eq(bb, dd);

  const char *format_str14 = "123 456";

  result1 = s21_sscanf(format_str14, "%2u %4u", &aa, &bb);
  result_origin1 = sscanf(format_str14, "%2u %4u", &cc, &dd);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(aa, cc);
  ck_assert_int_eq(bb, dd);

  const char *format_str15 = "0 0";

  result1 = s21_sscanf(format_str15, "%5u %5u", &aa, &bb);
  result_origin1 = sscanf(format_str15, "%5u %5u", &cc, &dd);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(aa, cc);
  ck_assert_int_eq(bb, dd);

  const char *format_str16 = "65535 65535";

  result1 = s21_sscanf(format_str16, "%5u %5u", &aa, &bb);
  result_origin1 = sscanf(format_str16, "%5u %5u", &cc, &dd);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(aa, cc);
  ck_assert_int_eq(bb, dd);

  const char *format_str17 = "0 0";

  result1 = s21_sscanf(format_str17, "%u %*u", &aa);
  result_origin1 = sscanf(format_str17, "%u %*u", &cc);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(aa, cc);

  const char *format_str18 = "0 0";

  result1 = s21_sscanf(format_str18, "%*u %u", &aa);
  result_origin1 = sscanf(format_str18, "%*u %u", &cc);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(aa, cc);

  const char *format_str19 = "1233 1456";

  result1 = s21_sscanf(format_str19, "%hu %*u", &a);
  result_origin1 = sscanf(format_str19, "%hu %*u", &c);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);

  const char *format_str20 = "1233 1456";

  result1 = s21_sscanf(format_str20, "%*u %hu", &a);
  result_origin1 = sscanf(format_str20, "%*u %hu", &c);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
}

END_TEST

START_TEST(s21_sscanf_test_19_c_option) {
  char a = 0;
  char b = 0;
  char c = 0;
  char d = 0;

  int result1 = s21_sscanf("a  b", "%c %c", &a, &b);
  int result_origin1 = sscanf("a b", "%c %c", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  result1 = s21_sscanf(" A B", "%c %c", &a, &b);
  result_origin1 = sscanf(" A B", "%c %c", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  result1 = s21_sscanf("- -", "%c %c", &a, &b);
  result_origin1 = sscanf("- -", "%c %c", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str1 = "123  150";

  result1 = s21_sscanf(format_str1, "%c %c", &a, &b);
  result_origin1 = sscanf(format_str1, "%c %c", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str2 = "1 10";

  result1 = s21_sscanf(format_str2, "%c %c", &a, &b);
  result_origin1 = sscanf(format_str2, "%c %c", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str3 = "0 0";

  result1 = s21_sscanf(format_str3, "%c %c", &a, &b);
  result_origin1 = sscanf(format_str3, "%c %c", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str4 = "";

  result1 = s21_sscanf(format_str4, "%*c %c %c", &a, &b);
  result_origin1 = sscanf(format_str4, "%*c %c %c", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char *format_str5 = "qwe 1";
  result1 = s21_sscanf(format_str5, "%Lc %c", &a, &b);

  const char *format_str6 = "qwerty";

  result1 = s21_sscanf(format_str6, "%1c %c", &a, &b);
  result_origin1 = sscanf(format_str6, "%1c %c", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  wchar_t a_w = 0;
  wchar_t b_w = 0;
  wchar_t c_w = 0;
  wchar_t d_w = 0;
  result1 = s21_sscanf("A B", "%lc %lc", &a_w, &b_w);
  result_origin1 = sscanf("A B", "%lc %lc", &c_w, &d_w);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a_w, c_w);
  ck_assert_int_eq(b_w, d_w);
}

END_TEST

START_TEST(s21_sscanf_test_20_s_option) {
  char array[BUFF_SIZE] = {0};
  char array_origin[BUFF_SIZE] = {0};

  int result = s21_sscanf("12345 36", "%s", array);
  int result_origin = sscanf("12345 36", "%s", array_origin);
  ck_assert_int_eq(result, result_origin);
  ck_assert_str_eq(array, array_origin);

  char array1[BUFF_SIZE] = {0};
  char array_origin1[BUFF_SIZE] = {0};

  result = s21_sscanf("Hello Dotan", "%s", array1);
  result_origin = sscanf("Hello Dotan", "%s", array_origin1);
  ck_assert_int_eq(result, result_origin);
  ck_assert_str_eq(array1, array_origin1);

  char array2[BUFF_SIZE] = {0};
  char array_origin2[BUFF_SIZE] = {0};

  result = s21_sscanf("", "%s", array2);
  result_origin = sscanf("", "%s", array_origin2);
  ck_assert_int_eq(result, result_origin);
  ck_assert_str_eq(array2, array_origin2);

  char array3[BUFF_SIZE] = {0};
  char array_origin3[BUFF_SIZE] = {0};

  result = s21_sscanf("", "%s", array3);
  result_origin = sscanf("", "%s", array_origin3);
  ck_assert_int_eq(result, result_origin);
  ck_assert_str_eq(array3, array_origin3);

  wchar_t array_t_1[999] = {0};
  wchar_t array_t_2[999] = {0};
  wchar_t array_t_3[999] = {0};
  wchar_t array_t_4[999] = {0};

  result = s21_sscanf("qwerty", "%4ls%ls", array_t_1, array_t_3);
  result_origin = sscanf("qwerty", "%4ls%ls", array_t_2, array_t_4);
  ck_assert_str_eq((char *)array_t_1, (char *)array_t_2);
  ck_assert_str_eq((char *)array_t_3, (char *)array_t_4);
  ck_assert_int_eq(result, result_origin);
}

END_TEST

START_TEST(s21_sscanf_test_21_i_option) {
  int a = 0;
  int b = 0;
  int result = s21_sscanf("0x1E240", "%i", &a);
  int result_origin = sscanf("0x1E240", "%i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;
  result = s21_sscanf("0xABCZ", "%i", &a);
  result_origin = sscanf("0xABCZ", "%i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;
  result = s21_sscanf("0361100", "%i", &a);
  result_origin = sscanf("0361100", "%i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;
  result = s21_sscanf("4147483648", "%i", &a);
  result_origin = sscanf("4147483648", "%i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;
  result = s21_sscanf("04147483648", "%i", &a);
  result_origin = sscanf("04147483648", "%i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;
  result = s21_sscanf("0x4147483648", "%i", &a);
  result_origin = sscanf("0x4147483648", "%i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;
  result = s21_sscanf("0X4147483648", "%i", &a);
  result_origin = sscanf("0X4147483648", "%i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;
  result = s21_sscanf("-123456", "%i", &a);
  result_origin = sscanf("-123456", "%i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;
  result = s21_sscanf("+123456", "%i", &a);
  result_origin = sscanf("+123456", "%i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  a = 10;
  b = 10;
  result = s21_sscanf("0", "%i", &a);
  result_origin = sscanf("0", "%i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  a = 10;
  b = 10;
  result = s21_sscanf("0", "%i", &a);
  result_origin = sscanf("0", "%i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  a = 10;
  b = 10;
  result = s21_sscanf("123456", "%4i", &a);
  result_origin = sscanf("123456", "%4i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  a = 10;
  b = 10;
  result = s21_sscanf("-123456", "%4i", &a);
  result_origin = sscanf("-123456", "%4i", &b);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a, b);

  short int ah = 10;
  short int bh = 10;
  result = s21_sscanf("32767", "%hi", &ah);
  result_origin = sscanf("32767", "%hi", &bh);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(ah, bh);

  ah = 10;
  bh = 10;
  result = s21_sscanf("52767", "%hi", &ah);
  result_origin = sscanf("52767", "%hi", &bh);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(ah, bh);

  ah = 10;
  bh = 10;
  result = s21_sscanf("-32767", "%hi", &ah);
  result_origin = sscanf("-32767", "%hi", &bh);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(ah, bh);

  ah = 10;
  bh = 10;
  result = s21_sscanf("-52767", "%hi", &ah);
  result_origin = sscanf("-52767", "%hi", &bh);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(ah, bh);

  ah = 10;
  bh = 10;
  result = s21_sscanf("-52767", "%hi", &ah);
  result_origin = sscanf("-52767", "%hi", &bh);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(ah, bh);

  ah = 10;
  bh = 10;
  result = s21_sscanf("-52767", "%hi", &ah);
  result_origin = sscanf("-52767", "%hi", &bh);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(ah, bh);

  long int al = 0;
  long int bl = 0;
  result = s21_sscanf("9223372036854775807", "%li", &al);
  result_origin = sscanf("9223372036854775807", "%li", &bl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(al, bl);

  al = 0;
  bl = 0;
  result = s21_sscanf("99223372036854775807", "%li", &al);
  result_origin = sscanf("99223372036854775807", "%li", &bl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(al, bl);

  al = 0;
  bl = 0;
  result = s21_sscanf("-9223372036854775807", "%li", &al);
  result_origin = sscanf("-9223372036854775807", "%li", &bl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(al, bl);
}

END_TEST

START_TEST(s21_sscanf_test_21_f_option) {
  float a = 0;
  float b = 0;
  float c = 0;
  float d = 0;

  int result = s21_sscanf("0.1234 123", "%f %f", &a, &b);
  int result_origin = sscanf("0.1234 123", "%f %f", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 123.123456789", "%f %f", &a, &b);
  result_origin = sscanf(".1234 123.123456789", "%f %f", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 -123.123456789", "%f %f", &a, &b);
  result_origin = sscanf(".1234 -123.123456789", "%f %f", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 -123.123456789", "%f %6f", &a, &b);
  result_origin = sscanf(".1234 -123.123456789", "%f %6f", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("3.402823466E+38", "%f", &a);
  result_origin = sscanf("3.402823466E+38", "%f", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("10.402823466E+38", "%f", &a);
  result_origin = sscanf("10.402823466E+38", "%f", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("1.175494351E–38", "%f", &a);
  result_origin = sscanf("1.175494351E–38", "%f", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("10.175494351E–38", "%f", &a);
  result_origin = sscanf("10.175494351E–38", "%f", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  long double al = 0;
  long double cl = 0;

  result = s21_sscanf("3.4E-4932", "%Lf", &al);
  result_origin = sscanf("3.4E-4932", "%Lf", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("30.4E-4932", "%Lf", &al);
  result_origin = sscanf("30.4E-4932", "%Lf", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("3.4E+4932", "%Lf", &al);
  result_origin = sscanf("3.4E+4932", "%Lf", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("30.4E+4932", "%Lf", &al);
  result_origin = sscanf("30.4E+4932", "%Lf", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);
}

END_TEST

START_TEST(s21_sscanf_test_21_g_option) {
  float a = 0;
  float b = 0;
  float c = 0;
  float d = 0;

  int result = s21_sscanf("0.12 123", "%g %g", &a, &b);
  int result_origin = sscanf("0.12 123", "%g %g", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 123.123456789", "%g %g", &a, &b);
  result_origin = sscanf(".1234 123.123456789", "%g %g", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 -123.123456789", "%g %6g", &a, &b);
  result_origin = sscanf(".1234 -123.123456789", "%g %6g", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 -123.12E+2", "%g %g", &a, &b);
  result_origin = sscanf(".1234 -123.12E+2", "%g %g", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("1.175494351E–38", "%g", &a);
  result_origin = sscanf("1.175494351E–38", "%g", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("10.175494351E–38", "%g", &a);
  result_origin = sscanf("10.175494351E–38", "%g", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("3.402823466E+38", "%g", &a);
  result_origin = sscanf("3.402823466E+38", "%g", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("30.402823466E+38", "%g", &a);
  result_origin = sscanf("30.402823466E+38", "%g", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  long double al = 0;
  long double cl = 0;

  result = s21_sscanf("3.4E-4932", "%Lg", &al);
  result_origin = sscanf("3.4E-4932", "%Lg", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("30.4E-4932", "%Lg", &al);
  result_origin = sscanf("30.4E-4932", "%Lg", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("3.4E+4932", "%Lg", &al);
  result_origin = sscanf("3.4E+4932", "%Lg", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("30.4E+4932", "%Lg", &al);
  result_origin = sscanf("30.4E+4932", "%Lg", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);
}

END_TEST

START_TEST(s21_sscanf_test_21_G_option) {
  float a = 0;
  float b = 0;
  float c = 0;
  float d = 0;

  int result = s21_sscanf("0.12 123", "%G %G", &a, &b);
  int result_origin = sscanf("0.12 123", "%G %G", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 123.123456789", "%G %G", &a, &b);
  result_origin = sscanf(".1234 123.123456789", "%G %G", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 -123.123456789", "%G %6G", &a, &b);
  result_origin = sscanf(".1234 -123.123456789", "%G %6G", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 -123.12E+2", "%G %G", &a, &b);
  result_origin = sscanf(".1234 -123.12E+2", "%G %G", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("1.175494351E–38", "%G", &a);
  result_origin = sscanf("1.175494351E–38", "%G", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("10.175494351E–38", "%G", &a);
  result_origin = sscanf("10.175494351E–38", "%G", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("3.402823466E+38", "%G", &a);
  result_origin = sscanf("3.402823466E+38", "%G", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("30.402823466E+38", "%G", &a);
  result_origin = sscanf("30.402823466E+38", "%G", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  long double al = 0;
  long double cl = 0;

  result = s21_sscanf("3.4E-4932", "%LG", &al);
  result_origin = sscanf("3.4E-4932", "%LG", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("30.4E-4932", "%LG", &al);
  result_origin = sscanf("30.4E-4932", "%LG", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("3.4E+4932", "%LG", &al);
  result_origin = sscanf("3.4E+4932", "%LG", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("30.4E+4932", "%LG", &al);
  result_origin = sscanf("30.4E+4932", "%LG", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);
}

END_TEST

START_TEST(s21_sscanf_test_21_e_option) {
  float a = 0;
  float b = 0;
  float c = 0;
  float d = 0;

  int result = s21_sscanf("0.12 123", "%e %e", &a, &b);
  int result_origin = sscanf("0.12 123", "%e %e", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 -123.123456789", "%e %6e", &a, &b);
  result_origin = sscanf(".1234 -123.123456789", "%e %6e", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 123.123456789e+5", "%e %e", &a, &b);
  result_origin = sscanf(".1234 123.123456789e+5", "%e %e", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 -123.12E+2", "%e %e", &a, &b);
  result_origin = sscanf(".1234 -123.12E+2", "%e %e", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("1.175494351E–38", "%e", &a);
  result_origin = sscanf("1.175494351E–38", "%e", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("10.175494351E–38", "%e", &a);
  result_origin = sscanf("10.175494351E–38", "%e", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("3.402823466E+38", "%e", &a);
  result_origin = sscanf("3.402823466E+38", "%e", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("30.402823466E+38", "%e", &a);
  result_origin = sscanf("30.402823466E+38", "%e", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  long double al = 0;
  long double cl = 0;

  result = s21_sscanf("3.4E-4932", "%Le", &al);
  result_origin = sscanf("3.4E-4932", "%Le", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("30.4E-4932", "%Le", &al);
  result_origin = sscanf("30.4E-4932", "%Le", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("3.4E+4932", "%Le", &al);
  result_origin = sscanf("3.4E+4932", "%Le", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("30.4E+4932", "%Le", &al);
  result_origin = sscanf("30.4E+4932", "%Le", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);
}

END_TEST

START_TEST(s21_sscanf_test_21_E_option) {
  float a = 0;
  float b = 0;
  float c = 0;
  float d = 0;

  int result = s21_sscanf("0.12 123", "%E %E", &a, &b);
  int result_origin = sscanf("0.12 123", "%E %E", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 -123.123456789", "%E %6E", &a, &b);
  result_origin = sscanf(".1234 -123.123456789", "%E %6E", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 123.123456789E+5", "%E %E", &a, &b);
  result_origin = sscanf(".1234 123.123456789E+5", "%E %E", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf(".1234 -123.12E+2", "%E %E", &a, &b);
  result_origin = sscanf(".1234 -123.12E+2", "%E %E", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("1.175494351E–38", "%E", &a);
  result_origin = sscanf("1.175494351E–38", "%E", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("10.175494351E–38", "%E", &a);
  result_origin = sscanf("10.175494351E–38", "%E", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("3.402823466E+38", "%E", &a);
  result_origin = sscanf("3.402823466E+38", "%E", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("30.402823466E+38", "%E", &a);
  result_origin = sscanf("30.402823466E+38", "%E", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  long double al = 0;
  long double cl = 0;

  result = s21_sscanf("3.4E-4932", "%LE", &al);
  result_origin = sscanf("3.4E-4932", "%LE", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("30.4E-4932", "%LE", &al);
  result_origin = sscanf("30.4E-4932", "%LE", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("3.4E+4932", "%LE", &al);
  result_origin = sscanf("3.4E+4932", "%LE", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = s21_sscanf("30.4E+4932", "%LE", &al);
  result_origin = sscanf("30.4E+4932", "%LE", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);
}

END_TEST

START_TEST(s21_sscanf_test_21_percent_option) {
  float a = 0;
  float b = 0;
  float c = 0;
  float d = 0;

  int result = s21_sscanf("1.55 % 2", "%f %% %f", &a, &b);
  int result_origin = sscanf("1.55 % 2", "%f %% %f", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("1.55 2", "%f %% %f", &a, &b);
  result_origin = sscanf("1.55 2", "%f %% %f", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("% 1.55 2", "%f %% %f", &a, &b);
  result_origin = sscanf("% 1.55 2", "%f %% %f", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = s21_sscanf("% 1.55 2", "%%%f %f", &a, &b);
  result_origin = sscanf("% 1.55 2", "%%%f %f", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);
}

END_TEST

START_TEST(s21_sscanf_test_21_star_option) {
  float a = 0;
  float c = 0;

  int result = s21_sscanf(".1234 123.123456789e-5", "%*E %E", &a);
  int result_origin = sscanf(".1234 123.123456789e-5", "%*E %E", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  c = 0;

  result = s21_sscanf(".1234 123.123456789E-5", "%*e %e", &a);
  result_origin = sscanf(".1234 123.123456789E-5", "%*e %e", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  c = 0;

  result = s21_sscanf(".1234 123.123456789", "%*G %G", &a);
  result_origin = sscanf(".1234 123.123456789", "%*G %G", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  c = 0;

  result = s21_sscanf(".1234 123.123456789", "%*g %g", &a);
  result_origin = sscanf(".1234 123.123456789", "%*g %g", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  c = 0;

  result = s21_sscanf(".1234 123.123456789", "%*f %f", &a);
  result_origin = sscanf(".1234 123.123456789", "%*f %f", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  int ai = 0;
  int bi = 0;
  result = s21_sscanf("0x1234 442", "%*i %i", &ai);
  result_origin = sscanf("0x1234 442", "%*i %i", &bi);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(ai, bi);

  char array3[BUFF_SIZE] = {0};
  char array_origin3[BUFF_SIZE] = {0};

  result = s21_sscanf("1234.5 442", "%*s %s", array3);
  result_origin = sscanf("1234.5 442", "%*s %s", array_origin3);
  ck_assert_int_eq(result, result_origin);
  ck_assert_str_eq(array3, array_origin3);

  char a_char = 0;
  char b_char = 0;
  char c_char = 0;
  char d_char = 0;
  const char *format_str4 = "";

  result = s21_sscanf(format_str4, "%*c %c %c", &a_char, &b_char);
  result_origin = sscanf(format_str4, "%*c %c %c", &c_char, &d_char);
  ck_assert_int_eq(result, result_origin);
  ck_assert_int_eq(a_char, c_char);
  ck_assert_int_eq(b_char, d_char);
}

END_TEST
START_TEST(s21_sscanf_test_16_xX_option) {
  int a = 0;
  int b = 0;

  int c = 0;
  int d = 0;

  int result1 = s21_sscanf("1E240 12D687", "%x %X", &a, &b);
  int result_origin1 = sscanf("1E240 12D687", "%x %X", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  a = 0;
  b = 0;

  result1 = s21_sscanf("1E240", "%x", &a);
  result_origin1 = sscanf("1E240", "%x", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;

  result1 = s21_sscanf("1E240", "%X", &a);
  result_origin1 = sscanf("1E240", "%X", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;

  result1 = s21_sscanf("-12D687", "%X", &a);
  result_origin1 = sscanf("-12D687", "%X", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 10;
  b = 10;

  result1 = s21_sscanf("-12D687", "%x", &a);
  result_origin1 = sscanf("-12D687", "%x", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 10;
  b = 10;

  result1 = s21_sscanf("3039", "%x", &a);
  result_origin1 = sscanf("3039", "%x", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 10;
  b = 10;

  result1 = s21_sscanf("3039", "%X", &a);
  result_origin1 = sscanf("3039", "%X", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);
  a = 0;
  b = 0;
  const char *for_str = "-929";

  result1 = s21_sscanf(for_str, "%X", &a);
  result_origin1 = sscanf(for_str, "%X", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  const char *for_str3 = "-929";

  result1 = s21_sscanf(for_str3, "%x", &a);
  result_origin1 = sscanf(for_str3, "%x", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;
  const char *for_str1 = "-929 1A85";

  result1 = s21_sscanf(for_str1, "%x %X", &a, &c);
  result_origin1 = sscanf(for_str1, "%x %X", &b, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(c, d);

  int x = 0;
  int y = 0;
  const char *format_str2 = "7FFFFFFF -80000000 -1";

  result1 = s21_sscanf(format_str2, "%X %X %X", &a, &c, &x);
  result_origin1 = sscanf(format_str2, "%X %X %X", &b, &d, &y);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(c, d);
  ck_assert_int_eq(x, y);

  a = 0;
  b = 0;
  const char *format_str3 = "-929 1A85";

  result1 = s21_sscanf(format_str3, "%*x %X", &a);
  result_origin1 = sscanf(format_str3, "%*x %X", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  a = 0;
  b = 0;
  result1 = s21_sscanf("1E240 12D687", "%x %*X", &a);
  result_origin1 = sscanf("1E240 12D687", "%x %*X", &b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);

  const char *format_str4 = "7FFFFFFF -80000000 -1";

  result1 = s21_sscanf(format_str4, "%X %X %*X", &a, &c);
  result_origin1 = sscanf(format_str4, "%X %X %*X", &b, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(c, d);

  const char *format_str5 = "-1 7FFFFFFF -80000000";

  result1 = s21_sscanf(format_str5, "%x %x %*x", &a, &c);
  result_origin1 = sscanf(format_str5, "%x %x %*x", &b, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, b);
  ck_assert_int_eq(c, d);
}
END_TEST
START_TEST(s21_sscanf_test_24_p_option) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST
START_TEST(s21_sscanf_test_24_p2_option) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST
START_TEST(s21_sscanf_test_24_p3_option) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST
END_TEST
START_TEST(s21_sscanf_test_24_p4_option) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST
START_TEST(s21_sscanf_test_23_together_option) {
  int a = 0, b = 0, c = 0, d = 0, g = 0, f = 0;
  unsigned short aa = 0, bb = 0, cc = 0, dd = 0;
  char z = 0, q = 0;
  char array1[BUFF_SIZE] = {0};
  char array_origin1[BUFF_SIZE] = {0};
  int result1 =
      s21_sscanf("1E240 12D687 65535 0 ! Mask and Trump are friends 0x1E240",
                 "%x %X %hu %hu %c %s %i", &a, &b, &aa, &cc, &z, array1, &f);
  int result_origin1 =
      sscanf("1E240 12D687 65535 0 ! Mask and Trump are friends 0x1E240",
             "%x %X %hu %hu %c %s %i", &c, &d, &bb, &dd, &q, array_origin1, &g);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(aa, bb);
  ck_assert_int_eq(cc, dd);
  ck_assert_int_eq(z, q);
  ck_assert_str_eq(array1, array_origin1);
  ck_assert_int_eq(f, g);

  a = 0, b = 0, c = 0, d = 0, g = 0, f = 0;
  aa = 0, bb = 0, cc = 0, dd = 0;
  z = 0, q = 0;
  char array2[BUFF_SIZE] = {0};
  char array_origin2[BUFF_SIZE] = {0};
  int result2 = s21_sscanf(
      "Mask and Trump are friends 1E240 12D687 65535 0 ! 0361100",
      "%s %x %*i %X %hu %hu %c %i", array2, &a, &b, &aa, &cc, &z, &f);
  int result_origin2 = sscanf(
      "Mask and Trump are friends 1E240 12D687 65535 0 ! 0361100",
      "%s %x %*i %X %hu %hu %c %i", array_origin2, &c, &d, &bb, &dd, &q, &g);
  ck_assert_int_eq(result2, result_origin2);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(aa, bb);
  ck_assert_int_eq(cc, dd);
  ck_assert_int_eq(z, q);
  ck_assert_str_eq(array2, array_origin2);
  ck_assert_int_eq(f, g);
  a = 0, b = 0, c = 0, d = 0, g = 0, f = 0;
  aa = 0, bb = 0, cc = 0, dd = 0;
  z = 0, q = 0;
  char array3[BUFF_SIZE] = {0};
  char array_origin3[BUFF_SIZE] = {0};
  int result3 = s21_sscanf(
      "Mask and Trump\0 are friends 1E240 12D687 65535 0 ! 0361100",
      "%s %x %*i %X %hu %hu %c %i", array3, &a, &b, &aa, &cc, &z, &f);
  int result_origin3 = sscanf(
      "Mask and Trump\0 are friends 1E240 12D687 65535 0 ! 0361100",
      "%s %x %*i %X %hu %hu %c %i", array_origin3, &c, &d, &bb, &dd, &q, &g);
  ck_assert_int_eq(result3, result_origin3);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(aa, bb);
  ck_assert_int_eq(cc, dd);
  ck_assert_int_eq(z, q);
  ck_assert_str_eq(array3, array_origin3);
  ck_assert_int_eq(f, g);
  a = 0, b = 0, c = 0, d = 0, g = 0, f = 0;
  aa = 0, bb = 0, cc = 0, dd = 0;
  z = 0, q = 0;
  char array4[BUFF_SIZE] = {0};
  char array_origin4[BUFF_SIZE] = {0};
  int result4 = s21_sscanf(
      "Mask and\0 Trump\0 are friends 1E240 12D687 65535\0 0 ! 0361100",
      "%s %x %*i %X %hu %hu %c %i", array4, &a, &b, &aa, &cc, &z, &f);
  int result_origin4 = sscanf(
      "Mask and\0 Trump\0 are friends 1E240 12D687 65535\0 0 ! 0361100",
      "%s %x %*i %X %hu %hu %c %i", array_origin4, &c, &d, &bb, &dd, &q, &g);
  ck_assert_int_eq(result4, result_origin4);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(aa, bb);
  ck_assert_int_eq(cc, dd);
  ck_assert_int_eq(z, q);
  ck_assert_str_eq(array4, array_origin4);
  ck_assert_int_eq(f, g);

  a = 0, b = 0, c = 0, d = 0, g = 0, f = 0;
  aa = 0, bb = 0, cc = 0, dd = 0;
  z = 0, q = 0;
  char array5[BUFF_SIZE] = {0};
  char array_origin5[BUFF_SIZE] = {0};
  int result5 = s21_sscanf(
      "Mask and Trump are friends 1E240 12D687 65535 0 ! 0361100",
      "%s %*x %x %X %*x %hu %*u %hu %c %i", array5, &a, &b, &aa, &cc, &z, &f);
  int result_origin5 =
      sscanf("Mask and Trump are friends 1E240 12D687 65535 0 ! 0361100",
             "%s %*x %x %X %*x %hu %*u %hu %c %i", array_origin5, &c, &d, &bb,
             &dd, &q, &g);
  ck_assert_int_eq(result5, result_origin5);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(aa, bb);
  ck_assert_int_eq(cc, dd);
  ck_assert_int_eq(z, q);
  ck_assert_str_eq(array5, array_origin5);
  ck_assert_int_eq(f, g);
}
END_TEST
START_TEST(s21_sscanf_test_26_hard_option) {
  int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
  int32_t n1 = 0, n2 = 0;

  const char str[] = "123123SkipMePlease!!!!123";
  const char fstr[] = "%d %d %n";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &a3, &n1);
  int16_t res2 = sscanf(str, fstr, &a2, &a4, &n2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a3, a4);
  ck_assert_int_eq(n1, n2);
}
END_TEST
START_TEST(s21_sscanf_test_27_hard_option) {
  int32_t a1, a2;
  int32_t b1 = 0, b2 = 0;
  const char str[] = "12keppa12";
  const char fstr[] = "%d %d";
  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(s21_sscanf_test_23_n_option) {
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  int n1 = 0;
  int n2 = 0;
  int result1 = s21_sscanf("10     20", "%d %n%d", &a, &n1, &b);
  int result2 = sscanf("10     20", "%d %n%d", &c, &n2, &d);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(result1, result2);

  a = 0;
  b = 0;
  c = 0;
  d = 0;
  n1 = 0;
  n2 = 0;
  result1 = s21_sscanf("10     20", "%d%n%d", &a, &n1, &b);
  result2 = sscanf("10     20", "%d%n%d", &c, &n2, &d);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(result1, result2);

  a = 0;
  b = 0;
  c = 0;
  d = 0;
  n1 = 0;
  n2 = 0;
  result1 = s21_sscanf("10     20", "%n%d%d", &a, &n1, &b);
  result2 = sscanf("10     20", "%n%d%d", &c, &n2, &d);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(result1, result2);

  a = 0;
  b = 0;
  c = 0;
  d = 0;
  n1 = 0;
  n2 = 0;
  result1 = s21_sscanf("  10     20", "%n%d%d", &a, &n1, &b);
  result2 = sscanf("  10     20", "%n%d%d", &c, &n2, &d);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(result1, result2);

  a = 0;
  b = 0;
  c = 0;
  d = 0;
  n1 = 0;
  n2 = 0;
  result1 = s21_sscanf("10     20  ", "%d%d%n", &a, &n1, &b);
  result2 = sscanf("10     20  ", "%d%d%n", &c, &n2, &d);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(result1, result2);

  a = 0;
  b = 0;
  c = 0;
  d = 0;
  n1 = 0;
  n2 = 0;
  result1 = s21_sscanf("10     20  ", "%d%d %n", &a, &n1, &b);
  result2 = sscanf("10     20  ", "%d%d %n", &c, &n2, &d);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(result1, result2);

  a = 0;
  b = 0;
  c = 0;
  d = 0;
  n1 = 0;
  n2 = 0;
  result1 = s21_sscanf("10     20  ", "%hn%d%d", &a, &n1, &b);
  result2 = 0;
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(result1, result2);
}

END_TEST
START_TEST(s21_sscanf_test_28_hard_option) {
  int32_t a1 = 0, a2 = 0;
  int32_t b1 = 0, b2 = 0;
  const char str[] = "12keppa12";
  const char fstr[] = "I will break your function%d %d";
  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST
START_TEST(s21_sscanf_test_29_hard_option) {
  int32_t a1 = 0, a2 = 0;
  int32_t b1 = 0, b2 = 0;
  const char str[] = "12keppa12";
  const char fstr[] = "%d I will break your function%d";
  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST
START_TEST(s21_sscanf_test_30_hard_option) {
  int32_t a1 = 0, a2 = 0;
  int32_t b1 = 0, b2 = 0;
  const char str[] = "+12keppa12";
  const char fstr[] = "%d uti puti daniil%d";
  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST
START_TEST(s21_sscanf_test_23_error_option) {
  float error1 = 0;
  float error2 = 0;

  int result1 = s21_sscanf("10     20", "%z", &error1);
  int result2 = 0;
  ck_assert_float_eq(error1, error2);
  ck_assert_int_eq(result1, result2);

  error1 = 0;
  error2 = 0;

  result1 = s21_sscanf("10     20", "%100f", &error1);
  result2 = sscanf("10     20", "%100f", &error2);
  ck_assert_float_eq(error1, error2);
  ck_assert_int_eq(result1, result2);
}

END_TEST

START_TEST(EOF1) {
  char fstr[] = "%d";
  char str[] = "        ";

  int16_t res1 = s21_sscanf(str, fstr, 0);
  int16_t res2 = sscanf(str, fstr, 100);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(EOF2) {
  char fstr[] = "%d ";
  char str[] = "               ";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(EOF3) {
  char fstr[] = "%d ";
  char str[] = "  ";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(only_chars1) {
  char fstr[] = "%c %c %c %c";
  char str[] = "   a     b c d";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(only_chars2) {
  char fstr[] = "%c%c%c%c";
  char str[] = "abcd";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(only_chars3) {
  char fstr[] = "%c %c %c      %c";
  char str[] = "1 a 3   c           ";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(only_chars4) {
  char fstr[] = "%c %c %c %c";
  char str[] = "   000 0    ";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(only_chars5) {
  char fstr[] = "%c %c %c %c";
  char str[] = "tttt";
  int16_t a1 = 0, a2 = 5, b1 = 0, b2 = 5, c1 = 0, c2 = 5, d1 = 0, d2 = 5;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(special_symbols_as_chars1) {
  char fstr[] = "%c%c%c%c";
  char str[] = "\\\n\t\t\t";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(special_symbols_as_chars2) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z ' ' /";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(special_symbols_as_chars3) {
  char fstr[] = "%c%*c%c%c";
  char str[] = "ABCD";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);

  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(chars_flags1) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(chars_flags2) {
  char fstr[] = "%1c %c %c %0c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(chars_flags3) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(chars_flags4) {
  char fstr[] = "%c %c %c %c";
  char str[] = "z *'@";
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(chars_flags5) {
  char fstr[] = "%*c%*c%*c%c";
  char str[] = "abcde";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(chars_aster1) {
  char fstr[] = "%*c%*c%*c%*c";
  char str[] = "   c ";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(chars_aster2) {
  char fstr[] = "%*c%*c%*c%c";
  char str[] = "abcd ";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = s21_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(only_ints1) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char fstr[] = "%ld %ld %ld %ld";
  const char str[] = "555 666 777 888";

  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(only_ints2) {
  int16_t a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337 21 5008 3000";
  const char fstr[] = "%hd %hd %hd %hd";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(only_ints3) {
  int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337 21 5008 300004";
  const char fstr[] = "%d %d %d %d";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(ints_nwidth1) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337 21 5008 300004";
  const char fstr[] = "%1ld %3ld %1ld %4ld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(ints_nwidth2) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337";
  const char fstr[] = "%1ld %1ld %1ld %1ld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(ints_nwidth3) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "100000000000000005";
  const char fstr[] = "%3ld%ld%1ld%5ld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(ints_nwidth4) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337";
  const char fstr[] = "%15ld %1ld %1ld %1ld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(ints_astwidth1) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  const char str[] = "1337123123 1 123412341234 1 999999 0";
  const char fstr[] = "%*d %ld %*d %ld %*d %ld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(ints_astwidth2) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337";
  const char fstr[] = "%15ld %1ld %1ld %1ld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(ints_astwidth3) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337";
  const char fstr[] = "%15ld %1ld %1ld %1ld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(ints_astwidth4) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1337";
  const char fstr[] = "%15ld %1ld %1ld %1ld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(signed_ints1) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "11337 ++3 -5 ------4";
  const char fstr[] = "%ld %ld %ld %ld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(signed_ints2) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +1 -1 -1";
  const char fstr[] = "%15ld %1ld %1ld %5ld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(signed_ints3) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-0 +0 +0 -0";
  const char fstr[] = "%2ld %1ld %1ld %1ld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(signed_ints4) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "1 01 10 0";
  const char fstr[] = "%ld %ld %ld %ld";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_int1) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "300 500 -600 +700";
  const char fstr[] = "%li %li %li %li";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_int2) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "300500-600+700 111";
  const char fstr[] = "%li %ld %ld %li";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_int3) {
  long a1 = 0, a2 = 0, c1 = 0, c2 = 0;
  char b1 = 0, b2 = 0, d1 = 0, d2 = 0;
  const char str[] = "300500-600+700+400";
  const char fstr[] = "%li%c%li%c";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_int4) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "  55555 f f f5555555 ddd   4    3    1 ";
  const char fstr[] = "%li %ld %ld %li";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_hex1) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "0xFFF 0xA123123 0x123123 0x0";
  const char fstr[] = "%li %ld %ld %li";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_hex2) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = " 0xFFFF 0xf 0xf 0xf5555555 ddd   4    3    1 ";
  const char fstr[] = "%li %ld %ld %li";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_oct1) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";
  const char fstr[] = "%li %ld %ld %li";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(spec_i_oct2) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";
  const char fstr[] = "%li %ld %ld %li";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

/* [%s] */

START_TEST(strings1) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "Aboba Floppa Keppa Shleppa Anuroba";
  const char fstr[] = "%s %s %s %s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings_mixed3) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  long long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "Aboba 123 Floppa -3 Keppa 4444Shleppa 333Anuroba 3";
  const char fstr[] = "%s%ld%s%d%s%d%s";

  int16_t res1 = s21_sscanf(str, fstr, s1, &a1, s2, &b1, s3, &c1, s4, &d1);
  int16_t res2 = s21_sscanf(str, fstr, s5, &a2, s6, &b2, s7, &c2, s8, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings2) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%s%s%s%s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings3) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tkepaboba floppa shleppa koooppa ap p p p p";
  const char fstr[] = "%*s%*s%*s%*s";

  int16_t res1 = s21_sscanf(str, fstr);
  int16_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings4) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%1s%1s%1s%1s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings5) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%3s%3s%3s%3s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(strings6) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "aboba\tshlepa\tasdfasdf\tasdfasdf";
  const char fstr[] = "%150s%1s%1s\t%3s";

  int16_t res1 = s21_sscanf(str, fstr, s1, s2, s3, s4);
  int16_t res2 = sscanf(str, fstr, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

// strings_mixed1

START_TEST(strings_mixed1) {
  unsigned long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  long d1 = 0, d2 = 0;
  long double e1 = 0, e2 = 0;

  const char str[] =
      "4444444"
      "eeeeeee\teeeeeee";
  const char fstr[] = "%5s %1s %*s %*s %lu %s %lu %lu %ld %Lf %33s";

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};
  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};
  char s9[BUFF_SIZE] = {'\0'};
  char s10[BUFF_SIZE] = {'\0'};

  int16_t res1 = s21_sscanf(str, fstr, s7, s9, &a1, s5, &b1, &c1, &d1, &e1, s1);
  int16_t res2 = sscanf(str, fstr, s8, s10, &a2, s6, &b2, &c2, &d2, &e2, s2);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(s1, s2);
  ck_assert_str_eq(s3, s4);
  ck_assert_str_eq(s5, s6);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(strings_mixed2) {
  int d1 = 0, d2 = 0, b1 = 0, b2 = 0, a1 = 0, a2 = 0;
  long v1, v2;

  const char str[] = "1 1 1 1 1 -1";
  const char fstr[] = "%1s %5d %1s %1s %d %ld %d";

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};
  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};

  int16_t res1 = s21_sscanf(str, fstr, s1, &a1, s2, s3, &b1, &v1, &d1);
  int16_t res2 = sscanf(str, fstr, s4, &a2, s5, s6, &b2, &v2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(s1, s2);
  ck_assert_str_eq(s3, s4);
  ck_assert_str_eq(s5, s6);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

/* [%n] */

START_TEST(n1) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int32_t n1 = 0, n2 = 5;

  const char str[BUFF_SIZE] = "50 160 70 80";
  const char fstr[BUFF_SIZE] = "%li %li %n %li %li";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(n2) {
  int n1 = 1, n2 = 5;

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};

  const char str[] = "cbobErobM fl? asdfasdflkasdf asdfasdf asdfasdf 88888";
  const char fstr[] = "%s %s %n %s";

  int32_t res1 = s21_sscanf(str, fstr, s1, s2, &n1, s3);
  int32_t res2 = sscanf(str, fstr, s5, s6, &n2, s7);

  ck_assert_int_eq(res1, res2);

  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
}
END_TEST

START_TEST(n3) {
  int n1 = 0, n2 = 5;

  const char str[BUFF_SIZE] = "50 60 70 80";
  const char fstr[BUFF_SIZE] = "%n";

  int16_t res1 = s21_sscanf(str, fstr, &n1);
  int16_t res2 = sscanf(str, fstr, &n2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(n4) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int32_t n1 = 0, n2 = 5;

  const char str[] = "50 60 70 80";
  const char fstr[] = "%li %li %n %li %li";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(n5) {
  long a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  int n1 = 0, n2 = 5;

  const char str[] = "50 60 70 80";
  const char fstr[] = "%li %li %n %li %li";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &n1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &n2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

/* [%f] / [%g] / %[%G] */

START_TEST(floats1) {
  long double a1 = 1, a2 = 0, b1 = 1, b2 = 0, c1 = 1, c2 = 0, d1 = 1, d2 = 0;

  const char str[] = "53.1 -4.1135 41.3333 +2.0001";
  const char fstr[] = "%Lf %Lf %Lf %Lf";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(floats2) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "0.00001 -4123123 4. .";
  const char fstr[] = "%f %f %f %f";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
  ck_assert_float_eq(d1, d2);
}
END_TEST

START_TEST(floats3) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = ". . . .";
  const char fstr[] = "%f %f %f %f";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(floats4) {
  long double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "513.41 -4.14135 414.3333 +112.0001";
  const char fstr[] = "%Lf %Lf %Lf %Lf";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(floats5) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  const char str[] = "53.1 -4.1135 411231.333 +2.0001";
  const char fstr[] = "%*f %f %f %f";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
}
END_TEST

START_TEST(floats_sci1) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "1.4441 1.31e+4 -3.31e-4 0.444e-5";
  const char fstr[] = "%G %G %G %G";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(floats_sci2) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "inf 1.31e+4 NaN 0.444e-5";
  const char fstr[] = "%G %G %G %G";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ldouble_eq(a1, a2);
  // Unfortunately, assertions for inf do not work correctly in libcheck
  // ck_assert_ldouble_infinite(a1);
  // ck_assert_ldouble_infinite(a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_float_nan(c1);
  ck_assert_float_nan(c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(floats_sci3) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "inF InF inF INF";
  const char fstr[] = "%G %G %G %G";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ldouble_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(floats_sci4) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "Nan NAN 0.0000 0";
  const char fstr[] = "%G %G %G %G";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_nan(a1);
  ck_assert_float_nan(a2);
  ck_assert_float_nan(b1);
  ck_assert_float_nan(b2);
  ck_assert_ldouble_eq(c1, c2);
  ck_assert_ldouble_eq(d1, d2);
}
END_TEST

START_TEST(floats_sci5) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] =
      "nAN           INF                   -0.1111         1e-10";
  const char fstr[] = "%G %G %G %G";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_nan(a1);
  ck_assert_float_nan(a2);
  ck_assert_ldouble_eq(b1, b2);
  ck_assert_ldouble_eq(c1, c2);
  ck_assert_ldouble_eq(d1, d2);
}
END_TEST

/* [%u] */

START_TEST(uint1) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 --5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_uint_eq(res1, res2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
}
END_TEST

START_TEST(uint2) {
  unsigned long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0,
                    d2 = 0;
  const char str[] = "-1337 233333331 5008 3000";
  const char fstr[] = "%1lu %2lu %5lu %4lu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(uint3) {
  unsigned long int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
  long d1 = 0, d2 = 0;
  long double v1, v2;

  const char str[] =
      "\t\t\t\t\t\n 3      adsfdfa%$$$$`adfasdfasdfaszcvzcxvcv -1337 "
      "anurobich+ 21 -5008 -33000 0.3333";
  const char fstr[] = "%*s %*s %lu %s %lu %lu %ld %Lf";

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};

  int16_t res1 = s21_sscanf(str, fstr, &a1, s1, &b1, &c1, &d1, &v1);
  int16_t res2 = sscanf(str, fstr, &a2, s2, &b2, &c2, &d2, &v2);

  ck_assert_uint_eq(res1, res2);
  ck_assert_str_eq(s1, s2);
  ck_assert_uint_eq(a1, a2);
  ck_assert_uint_eq(b1, b2);
  ck_assert_uint_eq(c1, c2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_ldouble_eq_tol(v1, v2, 0.0001);
}
END_TEST

START_TEST(uint4) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 --5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(uint5) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 --5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(uint6) {
  unsigned short a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;
  const char str[] = "-1337 +21 --5008 3000";
  const char fstr[] = "%hu %hu %hu %hu";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(upeer_hex_base_version) {
  uint32_t a1, a2;
  const char str[] = "F";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_overflow) {
  uint32_t a1, a2;
  const char str[] = "0xFFFFFFFF";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_0x) {
  uint32_t a1, a2;
  const char str[] = "0x";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_0X) {
  uint32_t a1, a2;
  const char str[] = "0X";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_empty) {
  uint32_t a1, a2;
  const char str[] = "";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_fail) {
  uint32_t a1, a2;
  const char str[] = "qF";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_spaces_tabs_sns) {
  uint32_t a1, a2;
  const char str[] = "          \n             \n     F";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_short) {
  uint16_t a1, a2;
  const char str[] = "F";
  const char fstr[] = "%hX";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_long) {
  unsigned long int a1, a2;
  const char str[] = "F";
  const char fstr[] = "%lX";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_2x) {
  uint32_t a1, a2;
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_star) {
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[] = "%*X";
  uint32_t res1 = s21_sscanf(str, fstr);
  uint32_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_nohex) {
  uint32_t a1, a2;
  const char str[] = "tqwqpl";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(upeer_hex_lower) {
  uint32_t a1, a2;
  const char str[] = "abcdef";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upeer_hex_sign) {
  uint32_t a1, a2;
  const char str[] = "-f";
  const char fstr[] = "%X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(lower_hex_base_version) {
  uint32_t a1, a2;
  const char str[] = "f";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(lower_hex_overflow) {
  uint32_t a1, a2;
  const char str[] = "0xfffffffffffffffffff";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(lower_hex_0x) {
  uint32_t a1, a2;
  const char str[] = "0x";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(lower_hex_0X) {
  uint32_t a1, a2;
  const char str[] = "0X";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(lower_hex_empty) {
  uint32_t a1, a2;
  const char str[] = "";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_hex_fail) {
  uint32_t a1, a2;
  const char str[] = "qF";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_hex_spaces_tabs_sns) {
  uint32_t a1, a2;
  const char str[] = "          \n             \n     F";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(lower_hex_short) {
  uint16_t a1, a2;
  const char str[] = "ff";
  const char fstr[] = "%hx";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(lower_hex_long) {
  unsigned long int a1, a2;
  const char str[] = "ff";
  const char fstr[] = "%lx";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(lower_hex_2x) {
  uint32_t a1, a2;
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(lower_hex_star) {
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char fstr[] = "%*x";
  uint32_t res1 = s21_sscanf(str, fstr);
  uint32_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_hex_nohex) {
  uint32_t a1, a2;
  const char str[] = "tqwqpl";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(lower_hex_lower) {
  uint32_t a1, a2;
  const char str[] = "abcdef";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(lower_hex_sign) {
  uint32_t a1, a2;
  const char str[] = "-f";
  const char fstr[] = "%x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(upper_hex_len) {
  uint32_t a1, a2;
  const char str[] = "123531FFF";
  const char fstr[] = "%2X";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(lower_hex_len) {
  uint32_t a1, a2;
  const char str[] = "123531FFF";
  const char fstr[] = "%2x";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_base_version) {
  uint32_t a1, a2;
  const char str[] = "777";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_overflow) {
  uint32_t a1, a2;
  const char str[] = "0x7777777777777777777777";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_0x) {
  uint32_t a1, a2;
  const char str[] = "0x";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_0X) {
  uint32_t a1, a2;
  const char str[] = "0X";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_empty) {
  uint32_t a1, a2;
  const char str[] = "";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(octal_fail) {
  uint32_t a1, a2;
  const char str[] = "q1";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(octal_spaces_tabs_sns) {
  uint32_t a1, a2;
  const char str[] = "          \n             \n     5";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_short) {
  uint16_t a1, a2;
  const char str[] = "12";
  const char fstr[] = "%ho";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_long) {
  unsigned long int a1, a2;
  const char str[] = "57234";
  const char fstr[] = "%lo";
  uint16_t res1 = s21_sscanf(str, fstr, &a1);
  uint16_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_2x) {
  uint32_t a1, a2;
  const char str[] = "0x12320x213x123213";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_star) {
  const char str[] = "521561612";
  const char fstr[] = "%*o";
  uint32_t res1 = s21_sscanf(str, fstr);
  uint32_t res2 = sscanf(str, fstr);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(octal_nohex) {
  uint32_t a1, a2;
  const char str[] = "tqwqpl";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(octal_lower) {
  uint32_t a1, a2;
  const char str[] = "01234567";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_sign) {
  uint32_t a1, a2;
  const char str[] = "-66";
  const char fstr[] = "%o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(octal_len) {
  uint32_t a1, a2;
  const char str[] = "123531";
  const char fstr[] = "%2o";
  uint32_t res1 = s21_sscanf(str, fstr, &a1);
  uint32_t res2 = sscanf(str, fstr, &a2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(buff1) {
  int32_t a1, a2;
  int32_t b1, b2;
  const char str[] = "12 keppa 12";
  const char fstr[] = "%d keppa %d";
  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(buff2) {
  int32_t a1, a2;
  int32_t b1, b2;
  const char str[] = "12keppa12";
  const char fstr[] = "%dkeppa%d";
  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(pointer1) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(pointer2) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(pointer3) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(pointer4) {
  int *a1 = 0, *a2 = 0, *b1 = 0, *b2 = 0, *c1 = 0, *c2 = 0, *d1 = 0, *d2 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char fstr[] = "%p %p %p %p";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(a1, a2);
  ck_assert_ptr_eq(b1, b2);
  ck_assert_ptr_eq(c1, c2);
  ck_assert_ptr_eq(d1, d2);
}
END_TEST

START_TEST(hard1) {
  int a1 = 0, a2 = 5, a3 = 3, a4 = 9;
  int32_t n1 = 500, n2 = 10000;

  const char str[] = "123123SkipMePlease!!!!123";
  const char fstr[] = "%dSkipMePlease!!!!%d %n";

  int16_t res1 = s21_sscanf(str, fstr, &a1, &a3, &n1);
  int16_t res2 = sscanf(str, fstr, &a2, &a4, &n2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a3, a4);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(buff3) {
  int32_t a1, a2;
  int32_t b1 = 0, b2 = 0;
  const char str[] = "12keppa12";
  const char fstr[] = "%dkeppapos%d";
  int32_t res1 = s21_sscanf(str, fstr, &a1, &b1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(s21_sprintf_test_2_percent_option) {
  char a1[BUFF_SIZE] = {0};
  char aa1[BUFF_SIZE] = {0};
  int a = 10;
  char *format_str1 = "Positive %%, %d";
  int result1 = s21_sprintf(a1, format_str1, a);
  int result_origin1 = sprintf(aa1, format_str1, a);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(a1, aa1);

  char a2[BUFF_SIZE] = {0};
  char aa2[BUFF_SIZE] = {0};
  int b = -10;
  char *format_str2 = "Negative %%, %d";
  result1 = s21_sprintf(a2, format_str2, b);
  result_origin1 = sprintf(aa2, format_str2, b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(a2, aa2);

  char a3[BUFF_SIZE] = {0};
  char aa3[BUFF_SIZE] = {0};
  b = -100000, a = -1234556;
  char *format_str3 = "Negative %%, %d%d";
  result1 = s21_sprintf(a3, format_str3, b, a);
  result_origin1 = sprintf(aa3, format_str3, b, a);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(a3, aa3);

  char a4[BUFF_SIZE] = {0};
  char aa4[BUFF_SIZE] = {0};
  const char *format_str4 = "%%, %d";
  result1 = s21_sprintf(a4, format_str4, a);
  result_origin1 = sprintf(aa4, format_str4, a);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(a4, aa4);

  char a5[BUFF_SIZE] = {0};
  char aa5[BUFF_SIZE] = {0};
  a = 123456;
  b = -123456;
  const char *format_str5 = " *one, %% %+-010.0d % +-010.0d";
  result1 = s21_sprintf(a5, format_str5, a, b);
  result_origin1 = sprintf(aa5, format_str5, a, b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(a5, aa5);

  char a6[BUFF_SIZE] = {0};
  char aa6[BUFF_SIZE] = {0};

  const char *format_str6 = " *one %%%%%%%%%%%%%%, %%  %*.*d %*.*d";
  result1 = s21_sprintf(a6, format_str6, 5, 10, a, 7, 10, b);
  result_origin1 = sprintf(aa6, format_str6, 5, 10, a, 7, 10, b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(a6, aa6);

  char a7[BUFF_SIZE] = {0};
  char aa7[BUFF_SIZE] = {0};

  const char *format_str7 = " *one %%%%%%%%%%%%%%, %%  [%*.*d] [%*.*d]";
  result1 = s21_sprintf(a7, format_str7, 5, 10, a, 7, 10, b);
  result_origin1 = sprintf(aa7, format_str7, 5, 10, a, 7, 10, b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(a7, aa7);

  char a8[BUFF_SIZE] = {0};
  char aa8[BUFF_SIZE] = {0};

  const char *format_str8 = " *one %%%%%%%%%%%%%%, %%  [% *.*d] [% *.*d]";
  result1 = s21_sprintf(a8, format_str8, 5, 10, a, 7, 10, b);
  result_origin1 = sprintf(aa8, format_str8, 5, 10, a, 7, 10, b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(a8, aa8);

  char a9[BUFF_SIZE] = {0};
  char aa9[BUFF_SIZE] = {0};

  const char *format_str9 = " *one %%%%%%%%%%%%%%, %%  [%   *.*d ] [%   *.*d]";
  result1 = s21_sprintf(a9, format_str9, 5, 10, a, 7, 10, b);
  result_origin1 = sprintf(aa9, format_str9, 5, 10, a, 7, 10, b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(a9, aa9);

  char a10[BUFF_SIZE] = {0};
  char aa10[BUFF_SIZE] = {0};
  a = 0;
  b = 0;
  const char *format_str10 =
      " *one %%%%%%%%%%%%%%, % %  [%   *.*d ] [%   *.*d] %%";
  result1 = s21_sprintf(a10, format_str10, 5, 10, a, 7, 10, b);
  result_origin1 = sprintf(aa10, format_str10, 5, 10, a, 7, 10, b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(a10, aa10);

  char a11[BUFF_SIZE] = {0};
  char aa11[BUFF_SIZE] = {0};
  a = 11;
  b = -11;
  const char *format_str11 =
      " *one %%%%%%%%%%%%%%, % %  [%   *.*d ] [%   *.*d] asd";
  result1 = s21_sprintf(a11, format_str11, 5, 10, a, 7, 10, b);
  result_origin1 = sprintf(aa11, format_str11, 5, 10, a, 7, 10, b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(a11, aa11);

  char a12[BUFF_SIZE] = {0};
  char aa12[BUFF_SIZE] = {0};
  a = 11123;
  b = -114456;
  const char *format_str12 = " *one %%%%%%%%%%%%%%,[%*.*d ][%*.*d]Dota2";
  result1 = s21_sprintf(a12, format_str12, 10, 0, a, 10, 0, b);
  result_origin1 = sprintf(aa12, format_str12, 10, 0, a, 10, 0, b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(a12, aa12);
  char a13[BUFF_SIZE] = {0};
  char aa13[BUFF_SIZE] = {0};
  a = 11123;
  b = -114456;
  const char *format_str13 = " *one %%%%%%%%%%%%%%,[%*.*d ][%*.*d]Dota2";
  result1 = s21_sprintf(a13, format_str13, 0, 0, a, 0, 0, b);
  result_origin1 = sprintf(aa13, format_str13, 0, 0, a, 0, 0, b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(a13, aa13);

  char a14[BUFF_SIZE] = {0};
  char aa14[BUFF_SIZE] = {0};
  a = 123456;
  b = -123456;
  const char *format_str14 = " *one, %% %+-00.0d % +-00.0d";
  result1 = s21_sprintf(a14, format_str14, a, b);
  result_origin1 = sprintf(aa14, format_str14, a, b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(a14, aa14);

  char a15[BUFF_SIZE] = {0};
  char aa15[BUFF_SIZE] = {0};
  a = 123456;
  b = -123456;
  const char *format_str15 = " *one, %% %+-00.0d %% % +-00.0d";
  result1 = s21_sprintf(a15, format_str15, a, b);
  result_origin1 = sprintf(aa15, format_str15, a, b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(a15, aa15);

  char a16[BUFF_SIZE] = {0};
  char aa16[BUFF_SIZE] = {0};
  a = 12345;
  b = 1234;
  const char *format_str16 = " *one, %% %+d %% %+d";
  result1 = s21_sprintf(a16, format_str16, a, b);
  result_origin1 = sprintf(aa16, format_str16, a, b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(a16, aa16);

  char a17[BUFF_SIZE] = {0};
  char aa17[BUFF_SIZE] = {0};
  a = 12345;
  b = 1234;
  const char *format_str17 = " *one, %% %- d %% % -d";
  result1 = s21_sprintf(a17, format_str17, a, b);
  result_origin1 = sprintf(aa17, format_str17, a, b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(a17, aa17);

  char a18[BUFF_SIZE] = {0};
  char aa18[BUFF_SIZE] = {0};
  a = -12345;
  b = -1234;
  const char *format_str18 = " *one, %% %- d %% % -d, 12345";
  result1 = s21_sprintf(a18, format_str18, a, b);
  result_origin1 = sprintf(aa18, format_str18, a, b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(a18, aa18);

  char a19[BUFF_SIZE] = {0};
  char aa19[BUFF_SIZE] = {0};
  a = 11123;
  b = -114456;
  const char *format_str19 = " *one %%%%%%%%%%%%%%,[%*.*d ][%*.*d]";
  result1 = s21_sprintf(a19, format_str19, -11, 12, a, 12, -11, b);
  result_origin1 = sprintf(aa19, format_str19, -11, 12, a, 12, -11, b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(a19, aa19);

  char a20[BUFF_SIZE] = {0};
  char aa20[BUFF_SIZE] = {0};
  a = -11123;
  b = 114456;
  const char *format_str20 = " *one %%%%%%%%%%%%%%,[%*.*d ][%*.*d]";
  result1 = s21_sprintf(a20, format_str20, -11, 0, a, 0, -11, b);
  result_origin1 = sprintf(aa20, format_str20, -11, 0, a, 0, -11, b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(a20, aa20);

  char a21[BUFF_SIZE] = {0};
  char aa21[BUFF_SIZE] = {0};
  a = -11123;
  b = 114456;
  const char *format_str21 = " *one %%%%%%%%%%%%%%,[%*.*d ][%*.*d]";
  result1 = s21_sprintf(a21, format_str21, 0, -11, a, -11, 0, b);
  result_origin1 = sprintf(aa21, format_str21, 0, -11, a, -11, 0, b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(a21, aa21);

  char a22[BUFF_SIZE] = {0};
  char aa22[BUFF_SIZE] = {0};
  a = -1113;
  b = -4456;
  const char *format_str22 = " *one %%%%%%%%%%%%%%,[%*.*d ][%*.*d]";
  result1 = s21_sprintf(a22, format_str22, -11, -11, a, -11, -11, b);
  result_origin1 = sprintf(aa22, format_str22, -11, -11, a, -11, -11, b);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_str_eq(a22, aa22);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("s21_string");
  TCase *test_case_1 = tcase_create("s21_string");
  SRunner *sr = srunner_create(s1);
  int wtf;
  suite_add_tcase(s1, test_case_1);
  tcase_add_test(test_case_1, s21_memchr_test);
  tcase_add_test(test_case_1, s21_memcmp_test);
  tcase_add_test(test_case_1, s21_memcpy_test);
  tcase_add_test(test_case_1, s21_memmove_test);
  tcase_add_test(test_case_1, s21_memset_test);
  tcase_add_test(test_case_1, s21_strcat_test);
  tcase_add_test(test_case_1, s21_strncat_test);
  tcase_add_test(test_case_1, s21_strchr_test);
  tcase_add_test(test_case_1, s21_strcmp_test);
  tcase_add_test(test_case_1, s21_strncmp_test);
  tcase_add_test(test_case_1, s21_strcpy_test);
  tcase_add_test(test_case_1, s21_strncpy_test);
  tcase_add_test(test_case_1, s21_strncpy_test);
  tcase_add_test(test_case_1, s21_strcspn_test);
  tcase_add_test(test_case_1, s21_strerror_test);
  tcase_add_test(test_case_1, s21_strlen_test);
  tcase_add_test(test_case_1, s21_strpbrk_test);
  tcase_add_test(test_case_1, s21_strrchr_test);
  tcase_add_test(test_case_1, s21_strspn_test);
  tcase_add_test(test_case_1, s21_strstr_test);
  tcase_add_test(test_case_1, s21_strtok_test);
  tcase_add_test(test_case_1, s21_to_upper_test);
  tcase_add_test(test_case_1, s21_to_lower_test);
  tcase_add_test(test_case_1, s21_insert_test);
  tcase_add_test(test_case_1, s21_trim_test);

  /*----------------------SPRINTF----------------------*/

  tcase_add_test(test_case_1, simplE_int11);
  tcase_add_test(test_case_1, precisE_int11);
  tcase_add_test(test_case_1, width_int1);
  tcase_add_test(test_case_1, minus_width_int1);
  tcase_add_test(test_case_1, plus_width_int1);
  tcase_add_test(test_case_1, padding_int1);
  tcase_add_test(test_case_1, star_width_int1);
  tcase_add_test(test_case_1, star_precision_int1);
  tcase_add_test(test_case_1, many_flags_many_ints1);
  tcase_add_test(test_case_1, flags_long_int1);
  tcase_add_test(test_case_1, flags_short_int1);
  tcase_add_test(test_case_1, flags_another_long_int1);
  tcase_add_test(test_case_1, zero_precision_zero_int1);
  tcase_add_test(test_case_1, space_flag_int1);
  tcase_add_test(test_case_1, unsigned_val1);
  tcase_add_test(test_case_1, unsigned_val1_width);
  tcase_add_test(test_case_1, unsigned_val1_flags);
  tcase_add_test(test_case_1, unsigned_val1_precision);
  tcase_add_test(test_case_1, unsigned_val1_many_flags);
  tcase_add_test(test_case_1, unsigned_val1_short);
  tcase_add_test(test_case_1, unsigned_val1_long);
  tcase_add_test(test_case_1, unsigned_val1_many);
  tcase_add_test(test_case_1, octal1);
  tcase_add_test(test_case_1, octal1_width1);
  tcase_add_test(test_case_1, octal1_flags1);
  tcase_add_test(test_case_1, octal1_precision1);
  tcase_add_test(test_case_1, octal1_many_flags);
  tcase_add_test(test_case_1, octal1_short);
  tcase_add_test(test_case_1, octal1_long);
  tcase_add_test(test_case_1, octal1_many);
  tcase_add_test(test_case_1, octal1_zero);
  tcase_add_test(test_case_1, octal1_hash);
  tcase_add_test(test_case_1, unsigned_zero1);
  tcase_add_test(test_case_1, hex_width1);
  tcase_add_test(test_case_1, hex_flags1);
  tcase_add_test(test_case_1, hex_precision1);
  tcase_add_test(test_case_1, hex_many1);
  tcase_add_test(test_case_1, hex_many1_flags);
  tcase_add_test(test_case_1, hex_zero1);
  tcase_add_test(test_case_1, hex_huge1);
  tcase_add_test(test_case_1, hex_short1);
  tcase_add_test(test_case_1, hex_long1);
  tcase_add_test(test_case_1, hex_one_longer_width1);
  tcase_add_test(test_case_1, hex_two_longer_width1);
  tcase_add_test(test_case_1, one_char1);
  tcase_add_test(test_case_1, one_precision11);
  tcase_add_test(test_case_1, one_flags11);
  tcase_add_test(test_case_1, one_width11);
  tcase_add_test(test_case_1, one_many11);
  tcase_add_test(test_case_1, one_many11_flags);
  tcase_add_test(test_case_1, string1);
  tcase_add_test(test_case_1, string1_precision);
  tcase_add_test(test_case_1, string1_width);
  tcase_add_test(test_case_1, string1_flags);
  tcase_add_test(test_case_1, string1_long);
  tcase_add_test(test_case_1, string1_many);
  tcase_add_test(test_case_1, ptr1);
  tcase_add_test(test_case_1, ptr1_width);
  tcase_add_test(test_case_1, ptr1_precision);
  tcase_add_test(test_case_1, null_ptr1);
  tcase_add_test(test_case_1, n_specifier1);
  tcase_add_test(test_case_1, string1_width_huge);
  tcase_add_test(test_case_1, float_precision1);
  tcase_add_test(test_case_1, float_width1);
  tcase_add_test(test_case_1, float_precision1_zero);
  tcase_add_test(test_case_1, float_precision1_empty);
  tcase_add_test(test_case_1, float_precision1_huge);
  tcase_add_test(test_case_1, float_precision1_huge_negative);
  tcase_add_test(test_case_1, float_huge1);
  tcase_add_test(test_case_1, float_flags1);
  tcase_add_test(test_case_1, float_many1);
  tcase_add_test(test_case_1, e_precision1);
  tcase_add_test(test_case_1, e_precision1_zero);
  tcase_add_test(test_case_1, e_precision1_empty);
  tcase_add_test(test_case_1, e_precision1_huge);
  tcase_add_test(test_case_1, e_precision1_huge_negative);
  tcase_add_test(test_case_1, e_huge1);
  tcase_add_test(test_case_1, e_many1);
  tcase_add_test(test_case_1, e_width1);
  tcase_add_test(test_case_1, e_flags1);
  tcase_add_test(test_case_1, E_int1);
  tcase_add_test(test_case_1, all_empty1);
  tcase_add_test(test_case_1, empty_format_and_parameters1);
  tcase_add_test(test_case_1, test_111one_char1);
  tcase_add_test(test_case_1, test_111many_char);
  tcase_add_test(test_case_1, test_111one_string1);
  tcase_add_test(test_case_1, test_111many_string1);
  tcase_add_test(test_case_1, test_111one_dec1);
  tcase_add_test(test_case_1, test_111many_dec1);
  tcase_add_test(test_case_1, test_111onE_int1);
  tcase_add_test(test_case_1, test_111many_int);
  tcase_add_test(test_case_1, test_111one_float1);
  tcase_add_test(test_case_1, test_111many_float1);
  tcase_add_test(test_case_1, test_111one_unsigned_dec);
  tcase_add_test(test_case_1, test_111many_unsigned_dec);
  tcase_add_test(test_case_1, test_111one_char1_with_alignment_left);
  tcase_add_test(test_case_1, test_111one_char1_with_alignment_right);
  tcase_add_test(test_case_1, test_111many_char_with_alignment);
  tcase_add_test(test_case_1, test_111one_hex_lower);
  tcase_add_test(test_case_1, test_111one_hex_upper);
  tcase_add_test(test_case_1, test_111many_hex_lower);
  tcase_add_test(test_case_1, test_111many_hex_upper);
  tcase_add_test(test_case_1, test_111one_hex_lower_with_alignment_left);
  tcase_add_test(test_case_1, test_111one_hex_lower_with_alignment_right);
  tcase_add_test(test_case_1, test_111one_hex_upper_with_alignment_left);
  tcase_add_test(test_case_1, test_111one_hex_upper_with_alignment_right);
  tcase_add_test(test_case_1, test_111many_hex_lower_with_alignment);
  tcase_add_test(test_case_1, test_111many_hex_upper_with_alignment);
  tcase_add_test(test_case_1, test_111one_hex_with_hashtag);
  tcase_add_test(test_case_1, test_111one_hex_upper_with_hashtag);
  tcase_add_test(test_case_1, test_111many_hex_lower_with_hashtag_and_alignm);
  tcase_add_test(test_case_1, test_111many_hex_upper_with_hashtag_and_alignm);
  tcase_add_test(test_case_1, test_111one_hex_lower_with_width_star);
  tcase_add_test(test_case_1, test_111one_hex_upper_with_width_star);
  tcase_add_test(test_case_1,
                 test_111many_hex_lower_with_width_star_and_align_and_hashtag);
  tcase_add_test(test_case_1, test_111many_hex_upper_with_width_star);
  tcase_add_test(test_case_1, test_111one_hex_lower_with_precision);
  tcase_add_test(test_case_1, test_111one_hex_upper_with_precision);
  tcase_add_test(test_case_1, test_111many_hex_lower_with_precision_and_other);
  tcase_add_test(test_case_1, test_111many_hex_upper_with_precision_and_other);
  tcase_add_test(test_case_1, test_111one_hex_lower_with_length);
  tcase_add_test(test_case_1, test_111one_hex_upper_with_length);
  tcase_add_test(test_case_1, test_111sprintf1);
  tcase_add_test(test_case_1, test_111sprintf2);
  tcase_add_test(test_case_1, test_111sprintf3);
  tcase_add_test(test_case_1, test_111sprintf4);
  tcase_add_test(test_case_1, test_111sprintf6);
  tcase_add_test(test_case_1, test_111sprintf7);
  tcase_add_test(test_case_1, test_111sprintf8);
  tcase_add_test(test_case_1, test_111sprintf9);
  tcase_add_test(test_case_1, test_111sprintf10);
  tcase_add_test(test_case_1, test_111sprintf11);
  tcase_add_test(test_case_1, test_111sprintf12);
  tcase_add_test(test_case_1, test_111sprintf14);
  tcase_add_test(test_case_1, test_111sprintf15);
  tcase_add_test(test_case_1, test_111sprintf16);
  tcase_add_test(test_case_1, test_111sprintf17);
  tcase_add_test(test_case_1, test_111sprintf18);
  tcase_add_test(test_case_1, test_111sprintf19);
  tcase_add_test(test_case_1, test_111sprintf20);
  tcase_add_test(test_case_1, test_111sprintf24);
  tcase_add_test(test_case_1, test_111sprintf25);
  tcase_add_test(test_case_1, test_111sprintf28);
  tcase_add_test(test_case_1, test_111sprintf29);
  tcase_add_test(test_case_1, test_111sprintf30);
  tcase_add_test(test_case_1, test_111sprintf31);
  tcase_add_test(test_case_1, test_111sprintf32);
  tcase_add_test(test_case_1, test_111sprintf33);
  tcase_add_test(test_case_1, test_111sprintf35);
  tcase_add_test(test_case_1, test_111sprintf36);
  tcase_add_test(test_case_1, test_111sprintf37);
  tcase_add_test(test_case_1, test_111sprintf38);
  tcase_add_test(test_case_1, test_111sprintf39);
  tcase_add_test(test_case_1, test_111sprintf40);
  tcase_add_test(test_case_1, test_111sprintf41);
  tcase_add_test(test_case_1, test_111sprintf42);
  tcase_add_test(test_case_1, test_111sprintf43);
  tcase_add_test(test_case_1, test_111sprintf44);
  tcase_add_test(test_case_1, g_trailing_zero11);
  tcase_add_test(test_case_1, g_large1);
  tcase_add_test(test_case_1, g_small1);
  tcase_add_test(test_case_1, g_precision1);
  tcase_add_test(test_case_1, g_precision1_zero);
  tcase_add_test(test_case_1, g_precision1_missing);
  tcase_add_test(test_case_1, g_many1_zeroes_in_front1);
  tcase_add_test(test_case_1, g_one_zero1);
  tcase_add_test(test_case_1, g_mantiss1);
  tcase_add_test(test_case_1, g_mantiss1_flags);
  tcase_add_test(test_case_1, g_short_no_mantiss1);
  tcase_add_test(test_case_1, LG1);
  tcase_add_test(test_case_1, g_many1);
  tcase_add_test(test_case_1, g_zero1);
  tcase_add_test(test_case_1, width_char1);
  tcase_add_test(test_case_1, s21_sprintf_test_2_percent_option);

  /*--------------------------SSCANF----------------------*/

  tcase_add_test(test_case_1, s21_sscanf_test_19_c_option);
  tcase_add_test(test_case_1, s21_sscanf_test_20_s_option);
  tcase_add_test(test_case_1, s21_sscanf_test_21_i_option);
  tcase_add_test(test_case_1, s21_sscanf_test_21_e_option);
  tcase_add_test(test_case_1, s21_sscanf_test_21_E_option);
  tcase_add_test(test_case_1, s21_sscanf_test_21_percent_option);
  tcase_add_test(test_case_1, s21_sscanf_test_21_star_option);
  tcase_add_test(test_case_1, s21_sscanf_test_21_f_option);
  tcase_add_test(test_case_1, s21_sscanf_test_21_g_option);
  tcase_add_test(test_case_1, s21_sscanf_test_21_G_option);
  tcase_add_test(test_case_1, s21_sscanf_test_23_n_option);
  tcase_add_test(test_case_1, s21_sscanf_test_23_error_option);

  tcase_add_test(test_case_1, s21_sscanf_test_16_o_option);
  tcase_add_test(test_case_1, s21_sscanf_test_17_o_option);
  tcase_add_test(test_case_1, s21_sscanf_test_18_o_option);
  tcase_add_test(test_case_1, s21_sscanf_test_17_d_option);
  tcase_add_test(test_case_1, s21_sscanf_test_18_u_option);
  tcase_add_test(test_case_1, s21_sscanf_test_19_u_option);
  tcase_add_test(test_case_1, s21_sscanf_test_16_xX_option);
  tcase_add_test(test_case_1, s21_sscanf_test_24_p_option);
  tcase_add_test(test_case_1, s21_sscanf_test_24_p2_option);
  tcase_add_test(test_case_1, s21_sscanf_test_24_p3_option);
  tcase_add_test(test_case_1, s21_sscanf_test_24_p4_option);

  tcase_add_test(test_case_1, s21_sscanf_test_23_together_option);
  tcase_add_test(test_case_1, s21_sscanf_test_26_hard_option);
  tcase_add_test(test_case_1, s21_sscanf_test_27_hard_option);
  tcase_add_test(test_case_1, s21_sscanf_test_28_hard_option);
  tcase_add_test(test_case_1, s21_sscanf_test_29_hard_option);
  tcase_add_test(test_case_1, s21_sscanf_test_30_hard_option);

  tcase_add_test(test_case_1, EOF1);
  tcase_add_test(test_case_1, EOF2);
  tcase_add_test(test_case_1, EOF3);
  //

  // [%c]
  // Flags:
  // [Width] - N: 0, 1 - Do nothing; N > 1 - Undefined beh.
  //          * - skips chars
  // [Precision] - Any precision flag immediately stops sscanf (error)
  // [Length] - Does nothing

  tcase_add_test(test_case_1, only_chars1);
  tcase_add_test(test_case_1, only_chars2);
  tcase_add_test(test_case_1, only_chars3);
  tcase_add_test(test_case_1, only_chars4);
  tcase_add_test(test_case_1, only_chars5);
  tcase_add_test(test_case_1, special_symbols_as_chars1);
  tcase_add_test(test_case_1, special_symbols_as_chars2);
  tcase_add_test(test_case_1, special_symbols_as_chars3);

  tcase_add_test(test_case_1, chars_flags1);  // Precision flags lead to fail
  tcase_add_test(test_case_1,
                 chars_flags2);  // Width flags do nothing (if <= 1)
  tcase_add_test(test_case_1, chars_flags3);
  tcase_add_test(test_case_1, chars_flags4);  // Length flags do nothing
  tcase_add_test(test_case_1, chars_flags5);  // * flags - ignores char
  tcase_add_test(test_case_1, chars_aster1);
  tcase_add_test(test_case_1, chars_aster2);

  // [%d]/[%i]
  // [Width]: * - skip token, (N) - read N chars as a number
  // [Precision]: Not applicable to int, considered as UB

  // Length (h, l, ll)
  tcase_add_test(test_case_1, only_ints1);
  tcase_add_test(test_case_1, only_ints2);
  tcase_add_test(test_case_1, only_ints3);
  // // Width (N)
  tcase_add_test(test_case_1, ints_nwidth1);
  tcase_add_test(test_case_1, ints_nwidth2);
  tcase_add_test(test_case_1, ints_nwidth3);
  tcase_add_test(test_case_1, ints_nwidth4);
  // // Width (*)
  tcase_add_test(test_case_1, ints_astwidth1);
  tcase_add_test(test_case_1, ints_astwidth2);
  tcase_add_test(test_case_1, ints_astwidth3);
  tcase_add_test(test_case_1, ints_astwidth4);
  // // Negative & positive ints
  tcase_add_test(test_case_1, signed_ints1);
  tcase_add_test(test_case_1, signed_ints2);
  tcase_add_test(test_case_1, signed_ints3);
  tcase_add_test(test_case_1, signed_ints4);

  // // [%i] Specifier. It may be INT, OCT, HEX

  tcase_add_test(test_case_1, spec_i_int1);
  tcase_add_test(test_case_1, spec_i_int2);
  // // Mixed with chars & ints
  tcase_add_test(test_case_1, spec_i_int3);
  tcase_add_test(test_case_1, spec_i_int4);

  tcase_add_test(test_case_1, spec_i_oct1);
  tcase_add_test(test_case_1, spec_i_oct2);
  tcase_add_test(test_case_1, spec_i_hex1);
  tcase_add_test(test_case_1, spec_i_hex2);

  // [%s]
  // Width: (N) - parses N chars, (*) - пропустить строку
  // OUT: res = 4 (корректно парсит все в разные строки)
  // int res = sscanf("abobashlepafloppakoppa", "%5s %6s %6s %4s", s1, s2, s3,
  // s4); Precision, length - not applicable

  tcase_add_test(test_case_1, strings1);
  tcase_add_test(test_case_1, strings2);
  tcase_add_test(test_case_1, strings3);
  tcase_add_test(test_case_1, strings4);
  tcase_add_test(test_case_1, strings5);
  tcase_add_test(test_case_1, strings6);
  tcase_add_test(test_case_1, uint1);
  tcase_add_test(test_case_1, uint2);
  tcase_add_test(test_case_1, uint3);
  tcase_add_test(test_case_1, uint4);
  tcase_add_test(test_case_1, uint5);
  tcase_add_test(test_case_1, uint6);
  tcase_add_test(test_case_1, strings_mixed1);
  tcase_add_test(test_case_1, strings_mixed2);
  tcase_add_test(test_case_1, strings_mixed3);

  // [%f] [%g] [%G]
  // Width: (N) - parses N chars, (*) - пропустить строку
  // Precision: take it into account while parsing AFTER (.)
  // Length - l - long

  tcase_add_test(test_case_1, floats1);
  tcase_add_test(test_case_1, floats2);
  tcase_add_test(test_case_1, floats3);
  tcase_add_test(test_case_1, floats4);
  tcase_add_test(test_case_1, floats5);

  tcase_add_test(test_case_1, floats_sci1);
  tcase_add_test(test_case_1, floats_sci2);
  tcase_add_test(test_case_1, floats_sci3);
  tcase_add_test(test_case_1, floats_sci4);
  tcase_add_test(test_case_1, floats_sci5);

  // [%n] specifier

  tcase_add_test(test_case_1, n1);

  tcase_add_test(test_case_1, n2);
  tcase_add_test(test_case_1, n3);
  tcase_add_test(test_case_1, n4);
  tcase_add_test(test_case_1, n5);

  tcase_add_test(test_case_1, n2);
  tcase_add_test(test_case_1, n3);
  tcase_add_test(test_case_1, n4);
  tcase_add_test(test_case_1, n5);

  tcase_add_test(test_case_1, upeer_hex_base_version);
  tcase_add_test(test_case_1, upeer_hex_overflow);
  tcase_add_test(test_case_1, upeer_hex_0x);
  tcase_add_test(test_case_1, upeer_hex_0X);
  tcase_add_test(test_case_1, upeer_hex_empty);
  tcase_add_test(test_case_1, upeer_hex_fail);
  //
  tcase_add_test(test_case_1, upeer_hex_spaces_tabs_sns);
  //
  tcase_add_test(test_case_1, upeer_hex_short);
  tcase_add_test(test_case_1, upeer_hex_long);
  tcase_add_test(test_case_1, upeer_hex_2x);
  tcase_add_test(test_case_1, upeer_hex_star);
  tcase_add_test(test_case_1, upeer_hex_nohex);
  tcase_add_test(test_case_1, upeer_hex_lower);
  tcase_add_test(test_case_1, upeer_hex_sign);
  tcase_add_test(test_case_1, upper_hex_len);

  tcase_add_test(test_case_1, lower_hex_base_version);
  //
  tcase_add_test(test_case_1, lower_hex_overflow);
  //
  tcase_add_test(test_case_1, lower_hex_0x);
  tcase_add_test(test_case_1, lower_hex_0X);
  tcase_add_test(test_case_1, lower_hex_empty);
  tcase_add_test(test_case_1, lower_hex_fail);
  //
  tcase_add_test(test_case_1, lower_hex_spaces_tabs_sns);
  //
  tcase_add_test(test_case_1, lower_hex_short);
  tcase_add_test(test_case_1, lower_hex_long);
  tcase_add_test(test_case_1, lower_hex_2x);
  tcase_add_test(test_case_1, lower_hex_star);
  tcase_add_test(test_case_1, lower_hex_nohex);
  tcase_add_test(test_case_1, lower_hex_lower);
  tcase_add_test(test_case_1, lower_hex_sign);
  tcase_add_test(test_case_1, lower_hex_len);

  tcase_add_test(test_case_1, octal_base_version);
  tcase_add_test(test_case_1, octal_overflow);
  tcase_add_test(test_case_1, octal_0x);
  tcase_add_test(test_case_1, octal_0X);
  tcase_add_test(test_case_1, octal_empty);
  //
  tcase_add_test(test_case_1, octal_fail);
  //
  tcase_add_test(test_case_1, octal_spaces_tabs_sns);
  tcase_add_test(test_case_1, octal_short);
  tcase_add_test(test_case_1, octal_long);
  tcase_add_test(test_case_1, octal_2x);
  tcase_add_test(test_case_1, octal_star);
  //
  tcase_add_test(test_case_1, octal_nohex);
  //
  tcase_add_test(test_case_1, octal_lower);
  tcase_add_test(test_case_1, octal_sign);
  tcase_add_test(test_case_1, octal_len);

  tcase_add_test(test_case_1, pointer1);
  tcase_add_test(test_case_1, pointer2);
  tcase_add_test(test_case_1, pointer3);
  tcase_add_test(test_case_1, pointer4);
  //
  tcase_add_test(test_case_1, buff1);
  tcase_add_test(test_case_1, buff2);
  tcase_add_test(test_case_1, buff3);
  //
  // исправить, чтобы u не принимал минус.

  tcase_add_test(test_case_1, hard1);

  srunner_run_all(sr, CK_ENV);
  wtf = srunner_ntests_failed(sr);

  srunner_free(sr);
  return wtf == 0 ? 0 : 1;
}
