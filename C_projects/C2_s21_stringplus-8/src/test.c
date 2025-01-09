#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "check.h"
#include "s21_string.h"

START_TEST(s21_memchr_test) {
  char data[] = "This is a simple test.";
  int len = strlen(data);

  // Тест: символ найден в середине строки
  ck_assert_ptr_eq(s21_memchr(data, 's', len), memchr(data, 's', len));

  // Тест: символ найден в начале строки
  ck_assert_ptr_eq(s21_memchr(data, 'T', len), memchr(data, 'T', len));

  // Тест: символ найден в конце строки
  ck_assert_ptr_eq(s21_memchr(data, '.', len), memchr(data, '.', len));

  // Тест: символ не найден в строке
  ck_assert_ptr_eq(s21_memchr(data, 'x', len), memchr(data, 'x', len));

  // Тест: поиск нулевого символа в строке
  ck_assert_ptr_eq(s21_memchr(data, '\0', len + 1),
                   memchr(data, '\0', len + 1));

  // Тест: поиск с ограниченным размером n
  ck_assert_ptr_eq(s21_memchr(data, 's', 4), memchr(data, 's', 4));
  ck_assert_ptr_eq(s21_memchr(data, 't', 7), memchr(data, 't', 7));

  // Дополнительные тесты
  ck_assert_ptr_eq(s21_memchr("", 'a', 0), memchr("", 'a', 0));
  ck_assert_ptr_eq(s21_memchr(data, 'T', 1), memchr(data, 'T', 1));
  ck_assert_ptr_eq(s21_memchr(data, 'T', 0), memchr(data, 'T', 0));
}
END_TEST

START_TEST(s21_strerror_test) {
#ifdef __linux__
  char *expected_linux_valid = "No such file or directory";
  char *result_linux_valid = s21_strerror(2);
  ck_assert_str_eq(result_linux_valid, expected_linux_valid);

  char expected_linux_invalid[100];
  s21_sprintf(expected_linux_invalid, "Unknown error: %d", 200);
  char *result_linux_invalid = s21_strerror(200);
  ck_assert_str_eq(result_linux_invalid, expected_linux_invalid);

#elif __APPLE__
  char *expected_macos_valid = "No such file or directory";
  char *result_macos_valid = s21_strerror(2);
  ck_assert_str_eq(result_macos_valid, expected_macos_valid);

  char expected_macos_invalid[100];
  s21_sprintf(expected_macos_invalid, "Unknown error: %d", 200);
  char *result_macos_invalid = s21_strerror(200);
  ck_assert_str_eq(result_macos_invalid, expected_macos_invalid);

#endif
}
END_TEST

START_TEST(s21_memset_test) {
  char buffer1[50];
  char buffer2[50];

  // Тест: заполнение пустого массива нулями
  memset(buffer1, 0, sizeof(buffer1));
  s21_memset(buffer2, 0, sizeof(buffer2));
  ck_assert_mem_eq(buffer1, buffer2, sizeof(buffer1));

  // Тест: заполнение массива символами 'A'
  memset(buffer1, 'A', sizeof(buffer1));
  s21_memset(buffer2, 'A', sizeof(buffer2));
  ck_assert_mem_eq(buffer1, buffer2, sizeof(buffer1));

  // Тест: частичное заполнение массива символами 'B'
  memset(buffer1, 'B', 25);
  s21_memset(buffer2, 'B', 25);
  ck_assert_mem_eq(buffer1, buffer2, 25);

  // Тест: заполнение массива символом 255
  memset(buffer1, 255, sizeof(buffer1));
  s21_memset(buffer2, 255, sizeof(buffer2));
  ck_assert_mem_eq(buffer1, buffer2, sizeof(buffer1));

  // Тест: заполнение массива с начальным содержимым
  char test_data1[] = "Hello, world!";
  char test_data2[] = "Hello, world!";
  memset(test_data1, 'X', 5);
  s21_memset(test_data2, 'X', 5);
  ck_assert_str_eq(test_data1, test_data2);
}
END_TEST

START_TEST(s21_memcpy_test) {
  char buffer1[50];
  char buffer2[50];
  char source[50];

  // Тест: копирование пустого массива
  memset(source, 0, sizeof(source));
  memcpy(buffer1, source, sizeof(source));
  s21_memcpy(buffer2, source, sizeof(source));
  ck_assert_mem_eq(buffer1, buffer2, sizeof(source));

  // Тест: копирование массива с данными
  strcpy(source, "Hello, world!");
  memcpy(buffer1, source, strlen(source) + 1);
  s21_memcpy(buffer2, source, strlen(source) + 1);
  ck_assert_mem_eq(buffer1, buffer2, strlen(source) + 1);

  // Тест: частичное копирование массива
  strcpy(source, "1234567890");
  memcpy(buffer1, source, 5);
  s21_memcpy(buffer2, source, 5);
  ck_assert_mem_eq(buffer1, buffer2, 5);

  // Дополнительные тесты
  memcpy(buffer1, "abcdef", 6);
  s21_memcpy(buffer2, "abcdef", 6);
  ck_assert_mem_eq(buffer1, buffer2, 6);

  memcpy(buffer1, "12345", 5);
  s21_memcpy(buffer2, "12345", 5);
  ck_assert_mem_eq(buffer1, buffer2, 5);
}
END_TEST

START_TEST(s21_strncat_test) {
  char dest1[20], dest2[20];
  // Тест 1: Простое конкатенирование
  strcpy(dest1, "Hello, ");
  strcpy(dest2, "Hello, ");
  ck_assert_str_eq(s21_strncat(dest1, "World!", 6),
                   strncat(dest2, "World!", 6));

  // Тест 2: n меньше длины src
  strcpy(dest1, "Hello, ");
  strcpy(dest2, "Hello, ");
  ck_assert_str_eq(s21_strncat(dest1, "World!", 3),
                   strncat(dest2, "World!", 3));

  // Тест 3: n больше длины src
  strcpy(dest1, "Hello, ");
  strcpy(dest2, "Hello, ");
  ck_assert_str_eq(s21_strncat(dest1, "World!", 10),
                   strncat(dest2, "World!", 10));

  // Тест 4: Конкатенирование пустой строки
  strcpy(dest1, "Hello, ");
  strcpy(dest2, "Hello, ");
  ck_assert_str_eq(s21_strncat(dest1, "", 3), strncat(dest2, "", 3));

  // Тест 5: Конкатенирование к пустой строке
  strcpy(dest1, "");
  strcpy(dest2, "");
  ck_assert_str_eq(s21_strncat(dest1, "World!", 6),
                   strncat(dest2, "World!", 6));

  // Тест 6: n равно 0
  strcpy(dest1, "Hello, ");
  strcpy(dest2, "Hello, ");
  ck_assert_str_eq(s21_strncat(dest1, "World!", 0),
                   strncat(dest2, "World!", 0));

  // Тест 7: Конкатенирование символов с пробелами
  strcpy(dest1, "Hello,");
  strcpy(dest2, "Hello,");
  ck_assert_str_eq(s21_strncat(dest1, " World! ", 7),
                   strncat(dest2, " World! ", 7));

  // Тест 8: Конкатенирование строки, содержащей только пробелы
  strcpy(dest1, "Hello,");
  strcpy(dest2, "Hello,");
  ck_assert_str_eq(s21_strncat(dest1, "     ", 5), strncat(dest2, "     ", 5));

  // Тест 9: n равно длине src
  strcpy(dest1, "Hello, ");
  strcpy(dest2, "Hello, ");
  ck_assert_str_eq(s21_strncat(dest1, "World!", 6),
                   strncat(dest2, "World!", 6));

  // Тест 10: Конкатенирование с начальной пустой строкой назначения
  dest1[0] = '\0';
  dest2[0] = '\0';
  ck_assert_str_eq(s21_strncat(dest1, "Hello, World!", 13),
                   strncat(dest2, "Hello, World!", 13));
}
END_TEST

START_TEST(s21_memcmp_test) {
  char buffer1[50];
  char buffer2[50];

  // Тест: сравнение пустых массивов
  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));
  ck_assert_int_eq(s21_memcmp(buffer1, buffer2, sizeof(buffer1)),
                   memcmp(buffer1, buffer2, sizeof(buffer1)));

  // Тест: сравнение идентичных массивов
  strcpy(buffer1, "Hello, world!");
  strcpy(buffer2, "Hello, world!");
  ck_assert_int_eq(s21_memcmp(buffer1, buffer2, strlen(buffer1)),
                   memcmp(buffer1, buffer2, strlen(buffer1)));

  // Тест: сравнение различных массивов
  strcpy(buffer1, "Hello, world!");
  strcpy(buffer2, "Hello, WORLD!");
  ck_assert_int_eq(s21_memcmp(buffer1, buffer2, strlen(buffer1)),
                   memcmp(buffer1, buffer2, strlen(buffer1)));

  // Тест: сравнение массивов с разными длинами
  strcpy(buffer1, "short");
  strcpy(buffer2, "longer string");
  ck_assert_int_eq(s21_memcmp(buffer1, buffer2, 5),
                   memcmp(buffer1, buffer2, 5));

  // Дополнительные тесты
  memset(buffer1, 'A', 50);
  memset(buffer2, 'A', 50);
  ck_assert_int_eq(s21_memcmp(buffer1, buffer2, 50),
                   memcmp(buffer1, buffer2, 50));

  memset(buffer1, 'A', 50);
  memset(buffer2, 'B', 50);
  ck_assert_int_eq(s21_memcmp(buffer1, buffer2, 50),
                   memcmp(buffer1, buffer2, 50));
}
END_TEST

START_TEST(s21_strtok_test) {
  char str_strtok1[] = "one/two/three(four)five";
  char delim1[] = "/()";

  char str_strtok2[] = "one/two/three(four)five";

  char *my_strtok = s21_strtok(str_strtok1, delim1);
  char *origin_strtok = strtok(str_strtok2, delim1);

  while (origin_strtok != s21_NULL) {
    ck_assert_str_eq(my_strtok, origin_strtok);

    my_strtok = s21_strtok(s21_NULL, delim1);
    origin_strtok = strtok(s21_NULL, delim1);
  }
}
END_TEST

START_TEST(s21_strstr_test) {
  // поиск первого вхождения строки А в строку В.
  // NULL – если строка strA не входит в строку strB. Указатель на первое
  // вхождение строки strA в строку strB.

  char test_1[] = "<<<5>>>";
  char test_2[] = "5";
  char test_3[] = "QwertyQwertyQwerty";
  char test_4[] = "Qwerty";
  char test_5[] = "abcd";
  char test_6[] = "";
  char test_7[] = "aaaaa123aaa1234aaa";
  char test_8[] = "1234";

  ck_assert_ptr_eq(s21_strstr(test_1, test_2), strstr(test_1, test_2));
  ck_assert_ptr_eq(s21_strstr(test_3, test_4), strstr(test_3, test_4));
  ck_assert_ptr_eq(s21_strstr(test_5, test_6), strstr(test_5, test_6));
  ck_assert_ptr_eq(s21_strstr(test_4, test_5), strstr(test_4, test_5));
  ck_assert_ptr_eq(s21_strstr(test_7, test_8), strstr(test_7, test_8));
}
END_TEST

START_TEST(s21_strlen_test) {
  // определение длины строки.
  // Количество символов в строке до первого вхождения символа конца строки.

  char test_1[] = "12345";
  char test_2[] = "Hello";
  char test_3[] = "1\0";
  char test_4[] = "   ";
  char test_5[] = "123\0456";
  char test_6[] = "hhh\0";
  ck_assert_int_eq(s21_strlen(test_1), strlen(test_1));
  ck_assert_int_eq(s21_strlen(test_2), strlen(test_2));
  ck_assert_int_eq(s21_strlen(test_3), strlen(test_3));
  ck_assert_int_eq(s21_strlen(test_4), strlen(test_4));
  ck_assert_int_eq(s21_strlen(test_5), strlen(test_5));
  ck_assert_int_eq(s21_strlen(test_6), strlen(test_6));
}
END_TEST

START_TEST(s21_strncpy_test) {
  // копирование строк c ограничением длины.
  // Функция возвращает указатель на строку, в которую скопированы данные.

  char src[] = "one/two/three(four)five";
  char sdc[] = "";
  char dest1[30] = {0};
  char dest2[30] = {0};
  s21_size_t n = 10;

  ck_assert_str_eq(s21_strncpy(dest1, src, n), strncpy(dest2, src, n));
  ck_assert_str_eq(s21_strncpy(dest1, sdc, n), strncpy(dest2, sdc, n));

  char test_1[] = "00000";
  char test_2[] = "     ";
  char test_3[] = "123\07";
  char test_4[] = "first_string\0second_string";
  char test_5[128] = "";
  char test_6[] = "Hello, world!!!";

  ck_assert_str_eq(s21_strncpy(test_1, test_2, 5), strncpy(test_1, test_2, 5));
  ck_assert_str_eq(s21_strncpy(test_2, test_3, 5), strncpy(test_2, test_3, 5));
  ck_assert_str_eq(s21_strncpy(test_4, test_5, 20),
                   strncpy(test_4, test_5, 20));
  ck_assert_str_eq(s21_strncpy(test_5, test_4, 20),
                   strncpy(test_5, test_4, 20));
  ck_assert_str_eq(s21_strncpy(test_6, test_5, 20),
                   strncpy(test_6, test_5, 10));
}
END_TEST

START_TEST(s21_strchr_test) {
  char str_src1[] = "Hello, world!";
  int ch = 'h';
  ck_assert_pstr_eq(strchr(str_src1, ch), s21_strchr(str_src1, ch));

  char str_src2[] = "Hello, world!";
  ch = '\0';
  ck_assert_pstr_eq(strchr(str_src2, ch), s21_strchr(str_src2, ch));

  char str_src3[] = "Hello, world!";
  ch = ',';
  ck_assert_pstr_eq(strchr(str_src3, ch), s21_strchr(str_src3, ch));

  char str_src4[] = "Hello, world!";
  ch = 33;
  ck_assert_pstr_eq(strchr(str_src4, ch), s21_strchr(str_src4, ch));

  char str_src5[] = "Hello, Polina!";
  ch = 'P';
  ck_assert_pstr_eq(strchr(str_src5, ch), s21_strchr(str_src5, ch));

  char str_src6[] = "Hello, world!";
  ch = 'w';
  ck_assert_pstr_eq(strchr(str_src6, ch), s21_strchr(str_src6, ch));

  char str_src7[] = "Hello, world!";
  ch = '0';
  ck_assert_pstr_eq(strchr(str_src7, ch), s21_strchr(str_src7, ch));
}
END_TEST

START_TEST(s21_strncmp_test) {
  // Тест на равные строки
  ck_assert_int_eq(s21_strncmp("abc", "abc", 3), strncmp("abc", "abc", 3));
  ck_assert_int_eq(s21_strncmp("abcd", "abcd", 4), strncmp("abcd", "abcd", 4));
  ck_assert_int_eq(s21_strncmp("abc", "abc", 0),
                   strncmp("abc", "abc", 0));  // n == 0

  // Тест на строки с нулевым символом в середине
  ck_assert_int_eq(s21_strncmp("ab\0c", "ab\0d", 4),
                   strncmp("ab\0c", "ab\0d", 4));
  ck_assert_int_eq(s21_strncmp("ab\0c", "ab\0c", 4),
                   strncmp("ab\0c", "ab\0c", 4));

  // Тест на частичное сравнение строк
  ck_assert_int_eq(
      s21_strncmp("abc", "abd", 2),
      strncmp("abc", "abd", 2));  // только первые 2 символа сравниваются
  ck_assert_int_eq(s21_strncmp("abcd", "abcf", 3),
                   strncmp("abcd", "abcf", 3));  // первые 3 символа

  ck_assert_int_eq(s21_strncmp("", "", 1), 0);
  ck_assert_int_eq(s21_strncmp("a", "b", 1), strncmp("a", "b", 1));
  ck_assert_int_eq(s21_strncmp("abc", "abc", 5), strncmp("abc", "abc", 5));
}
END_TEST

START_TEST(s21_strcspn_test) {
  char str[10] = "0123456789";
  char sym[10] = "9876";
  char tst1[10] = "";
  char tst2[10] = "";
  char tst3[10] = "sdf";

  ck_assert_int_eq(s21_strcspn(str, sym), strcspn(str, sym));
  ck_assert_int_eq(s21_strcspn(str, tst3), strcspn(str, tst3));
  ck_assert_int_eq(s21_strcspn(str, tst2), strcspn(str, tst2));
  ck_assert_int_eq(s21_strcspn(tst2, tst1), strcspn(tst2, tst1));
}
END_TEST

START_TEST(s21_strpbrk_test) {
  char str[] = "Megalomania";

  char str_oneof[] = "yal";

  char *result_custom = s21_strpbrk(str, str_oneof);
  char *result_standard = strpbrk(str, str_oneof);

  ck_assert_str_eq(result_custom, "alomania");
  ck_assert_str_eq(result_custom, result_standard);

  char *empty = "";

  ck_assert_ptr_eq(s21_strpbrk(str, empty), NULL);
  ck_assert_ptr_eq(s21_strpbrk(str, empty), strpbrk(str, empty));
}
END_TEST

START_TEST(s21_strrchr_test) {
  char test1[] = "0163456769";
  char test2[] = ";;;;;;H%%//#HH";
  char test3[] = "     /";
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, '6'),
                    (unsigned long)strrchr(test1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, ' '),
                    (unsigned long)strrchr(test1, ' '));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, '6'),
                    (unsigned long)strrchr(test1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, 'H'),
                    (unsigned long)strrchr(test2, 'H'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, '$'),
                    (unsigned long)strrchr(test2, '$'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, ';'),
                    (unsigned long)strrchr(test2, ';'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test3, ' '),
                    (unsigned long)strrchr(test3, ' '));
  ck_assert_str_eq(s21_strrchr(test2, '\0'), strrchr(test2, '\0'));
}
END_TEST

START_TEST(s21_to_upper_test) {
  // Тест: NULL строка
  char *result = s21_to_upper(NULL);
  ck_assert_ptr_eq(result, NULL);

  // Тест: пустая строка
  result = s21_to_upper("");
  ck_assert_str_eq(result, "");
  free(result);

  // Тест: строка с маленькими буквами
  result = s21_to_upper("hello");
  ck_assert_str_eq(result, "HELLO");
  free(result);

  // Тест: строка с смешанными буквами
  result = s21_to_upper("Hello World");
  ck_assert_str_eq(result, "HELLO WORLD");
  free(result);

  // Тест: строка с числами
  result = s21_to_upper("12345");
  ck_assert_str_eq(result, "12345");
  free(result);

  // Тест: строка с специальными символами
  result = s21_to_upper("hello@123");
  ck_assert_str_eq(result, "HELLO@123");
  free(result);

  // Тест: строка с уже верхними буквами
  result = s21_to_upper("HELLO");
  ck_assert_str_eq(result, "HELLO");
  free(result);
}
END_TEST

START_TEST(s21_to_lower_test) {
  // Тест: NULL строка
  char *result = s21_to_lower(NULL);
  ck_assert_ptr_eq(result, NULL);

  // Тест: пустая строка
  result = s21_to_lower("");
  ck_assert_str_eq(result, "");
  free(result);

  // Тест: строка с заглавными буквами
  result = s21_to_lower("HELLO");
  ck_assert_str_eq(result, "hello");
  free(result);

  // Тест: строка с смешанными регистрами
  result = s21_to_lower("HeLLo WoRlD");
  ck_assert_str_eq(result, "hello world");
  free(result);

  // Тест: строка с цифрами
  result = s21_to_lower("12345");
  ck_assert_str_eq(result, "12345");
  free(result);

  // Тест: строка с специальными символами
  result = s21_to_lower("Hello@123");
  ck_assert_str_eq(result, "hello@123");
  free(result);

  // Тест: строка с уже нижними буквами
  result = s21_to_lower("hello");
  ck_assert_str_eq(result, "hello");
  free(result);
}
END_TEST

START_TEST(s21_insert_test) {
  char str1[] = "Hello World";
  char str2[] = "Beautiful ";

  char *new_str = s21_insert(str1, str2, 6);

  if (new_str) {
    ck_assert_str_eq(new_str, "Hello Beautiful World");
    free(new_str);
  }

  new_str = s21_insert(str1, "", 5);
  ck_assert_str_eq(new_str, "Hello World");
  free(new_str);

  new_str = s21_insert(str1, s21_NULL, 5);
  ck_assert(new_str == s21_NULL);
  free(new_str);

  new_str = s21_insert("Hello!", ", world!!", 5);
  if (new_str) {
    ck_assert_str_eq(new_str, "Hello, world!!!");
    free(new_str);
  }
}

// s21_sprintf

//%d
START_TEST(test_s21_sprintf_int) {
  char buffer[100];
  char expected[100];

  // Тест для нуля
  s21_sprintf(buffer, "%d", 0);
  sprintf(expected, "%d", 0);
  ck_assert_str_eq(buffer, expected);

  // Тест для небольшого положительного числа
  s21_sprintf(buffer, "%d", 7);
  sprintf(expected, "%d", 7);
  ck_assert_str_eq(buffer, expected);

  // Тест для среднего положительного числа
  s21_sprintf(buffer, "%d", 123);
  sprintf(expected, "%d", 123);
  ck_assert_str_eq(buffer, expected);

  // Тест для большого положительного числа
  s21_sprintf(buffer, "%d", 123456789);
  sprintf(expected, "%d", 123456789);
  ck_assert_str_eq(buffer, expected);

  // Тест для небольшого отрицательного числа
  s21_sprintf(buffer, "%d", -7);
  sprintf(expected, "%d", -7);
  ck_assert_str_eq(buffer, expected);

  // Тест для среднего отрицательного числа
  s21_sprintf(buffer, "%d", -123);
  sprintf(expected, "%d", -123);
  ck_assert_str_eq(buffer, expected);

  // Тест для большого отрицательного числа
  s21_sprintf(buffer, "%d", -123456789);
  sprintf(expected, "%d", -123456789);
  ck_assert_str_eq(buffer, expected);

  // Тест для числа с ведущими нулями
  s21_sprintf(buffer, "%010d", 123);
  sprintf(expected, "%010d", 123);
  ck_assert_str_eq(buffer, expected);

  // Тест для короткого числа (short int)
  short int short_value = 12345;
  s21_sprintf(buffer, "%hd", short_value);
  sprintf(expected, "%hd", short_value);
  ck_assert_str_eq(buffer, expected);

  // Тест для длинного числа (long int)
  long int long_value = 1234567890L;
  s21_sprintf(buffer, "%ld", long_value);
  sprintf(expected, "%ld", long_value);
  ck_assert_str_eq(buffer, expected);

  // Тест для длинного длинного числа (long long int)
  long long int longlong_value = 1234567890123456789LL;
  s21_sprintf(buffer, "%lld", longlong_value);
  sprintf(expected, "%lld", longlong_value);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

//%f
START_TEST(test_s21_sprintf_float) {
  char buffer[100];  // Буфер для хранения результата форматирования
  char buffer1[100];

  // Тест для проверки форматирования целого числа с плавающей точкой
  s21_sprintf(buffer, "%f", 123.456);
  sprintf(buffer1, "%f", 123.456);
  ck_assert_str_eq(buffer, buffer1);

  // Тест для проверки форматирования отрицательного числа с плавающей точкой
  s21_sprintf(buffer, "%f", -123.456);
  sprintf(buffer1, "%f", -123.456);
  ck_assert_str_eq(buffer, buffer1);

  // Тест для проверки форматирования числа с плавающей точкой с нулевой дробной
  // частью
  s21_sprintf(buffer, "%f", 123.0);
  sprintf(buffer1, "%f", 123.0);
  ck_assert_str_eq(buffer, buffer1);

  // Тест для проверки форматирования числа с плавающей точкой с максимальной
  // точностью
  s21_sprintf(buffer, "%.15f", 3.141592653589793);
  sprintf(buffer1, "%.15f", 3.141592653589793);
  ck_assert_str_eq(buffer, buffer1);
  // Тест для проверки форматирования числа с плавающей точкой с нулевой
  // точностью
  s21_sprintf(buffer, "%.0f", 3.14159);
  sprintf(buffer1, "%.0f", 3.14159);
  ck_assert_str_eq(buffer, buffer1);

  // Тест для проверки форматирования нуля с плавающей точкой
  s21_sprintf(buffer, "%f", 0.0);
  sprintf(buffer1, "%f", 0.0);
  ck_assert_str_eq(buffer, buffer1);

  // Тест для проверки форматирования числа с плавающей точкой, которое приводит
  // к округлению
  s21_sprintf(buffer, "%.5f", 3.1465659);
  sprintf(buffer1, "%.5f", 3.1465659);
  ck_assert_str_eq(buffer, buffer1);
  // Тест для проверки форматирования очень большого числа с плавающей точкой
  s21_sprintf(buffer, "%f", 1.0e100);
  s21_sprintf(buffer1, "%f", 1.0e100);
  ck_assert_str_eq(buffer, buffer1);

  // Тест для проверки форматирования очень маленького числа с плавающей точкой
  s21_sprintf(buffer, "%f", 1.0e-100);
  sprintf(buffer1, "%f", 1.0e-100);
  ck_assert_str_eq(buffer, buffer1);

  // Тест для проверки форматирования числа с плавающей точкой с использованием
  // выравнивания
  s21_sprintf(buffer, "%10.2f", 123.456);
  sprintf(buffer1, "%10.2f", 123.456);
  ck_assert_str_eq(buffer, buffer1);

  // Тест для проверки форматирования числа с плавающей точкой с отрицательной
  // точностью
  s21_sprintf(buffer, "%.2f", 123.456);
  sprintf(buffer1, "%.2f", 123.456);
  ck_assert_str_eq(buffer, buffer1);
}
END_TEST

//%u
START_TEST(test_s21_sprintf_unsigned) {
  char buffer[100];
  char expected[100];

  // Тест для нуля
  s21_sprintf(buffer, "%u", 0U);
  sprintf(expected, "%u", 0U);
  ck_assert_str_eq(buffer, expected);

  // Тест для небольшого положительного числа
  s21_sprintf(buffer, "%u", 7U);
  sprintf(expected, "%u", 7U);
  ck_assert_str_eq(buffer, expected);

  // Тест для среднего положительного числа
  s21_sprintf(buffer, "%u", 123U);
  sprintf(expected, "%u", 123U);
  ck_assert_str_eq(buffer, expected);

  // Тест для большого положительного числа
  s21_sprintf(buffer, "%u", 123456789U);
  sprintf(expected, "%u", 123456789U);
  ck_assert_str_eq(buffer, expected);

  // Тест для максимального значения unsigned int
  unsigned int uint_value = 4294967295U;
  s21_sprintf(buffer, "%u", uint_value);
  sprintf(expected, "%u", uint_value);
  ck_assert_str_eq(buffer, expected);

  // Тест для короткого числа (unsigned short int)
  unsigned short int ushort_value = 65535;
  s21_sprintf(buffer, "%hu", ushort_value);
  sprintf(expected, "%hu", ushort_value);
  ck_assert_str_eq(buffer, expected);

  // Тест для длинного числа (unsigned long int)
  unsigned long int ulong_value = 1234567890UL;
  s21_sprintf(buffer, "%lu", ulong_value);
  sprintf(expected, "%lu", ulong_value);
  ck_assert_str_eq(buffer, expected);

  // Тест для длинного длинного числа (unsigned long long int)
  unsigned long long int ulonglong_value = 12345678901234567890ULL;
  s21_sprintf(buffer, "%llu", ulonglong_value);
  sprintf(expected, "%llu", ulonglong_value);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

//%c
START_TEST(test_s21_sprintf_char) {
  char buffer[100];
  char expected[100];

  s21_sprintf(buffer, "%c", 'H');
  sprintf(expected, "%c", 'H');
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%c", ' ');
  sprintf(expected, "%c", ' ');
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%c", '\n');
  sprintf(expected, "%c", '\n');
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%c", '\0');
  sprintf(expected, "%c", '\0');
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%c", '\t');
  sprintf(expected, "%c", '\t');
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%c", '\r');
  sprintf(expected, "%c", '\r');
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%c", '\b');
  sprintf(expected, "%c", '\b');
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%c", 'A');
  sprintf(expected, "%c", 'A');
  ck_assert_str_eq(buffer, expected);

  // Тест для обычного символа
  s21_sprintf(buffer, "%c", 'A');
  sprintf(expected, "%c", 'A');
  ck_assert_str_eq(buffer, expected);

  // Тест для пробела
  s21_sprintf(buffer, "%c", ' ');
  sprintf(expected, "%c", ' ');
  ck_assert_str_eq(buffer, expected);

  // Тест для цифры
  s21_sprintf(buffer, "%c", '5');
  sprintf(expected, "%c", '5');
  ck_assert_str_eq(buffer, expected);

  // Тест для специального символа
  s21_sprintf(buffer, "%c", '@');
  sprintf(expected, "%c", '@');
  ck_assert_str_eq(buffer, expected);

  // Тест для нулевого символа
  s21_sprintf(buffer, "%c", '\0');
  sprintf(expected, "%c", '\0');
  ck_assert_str_eq(buffer, expected);

  // Тест для табуляции
  s21_sprintf(buffer, "%c", '\t');
  sprintf(expected, "%c", '\t');
  ck_assert_str_eq(buffer, expected);

  // Тест для символа с ASCII кодом
  s21_sprintf(buffer, "%c", 65);
  sprintf(expected, "%c", 65);
  ck_assert_str_eq(buffer, expected);

  // Тест для символа с указанием ширины поля
  s21_sprintf(buffer, "%5c", 'A');
  sprintf(expected, "%5c", 'A');
  ck_assert_str_eq(buffer, expected);

  // Тест для символа с минусом (выравнивание по левому краю)
  s21_sprintf(buffer, "%-5c", 'A');
  sprintf(expected, "%-5c", 'A');
  ck_assert_str_eq(buffer, expected);
}
END_TEST

//%s
START_TEST(test_s21_sprintf_string) {
  char buffer[100];
  char expected[100];

  s21_sprintf(buffer, "%s", "s21_NULL");
  sprintf(expected, "%s", "s21_NULL");
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%s", "Hello, world!!!");
  sprintf(expected, "%s", "Hello, world!!!");
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%s", "lerem ipsum dolor sit amet");
  sprintf(expected, "%s", "lerem ipsum dolor sit amet");
  ck_assert_str_eq(buffer, expected);

  s21_sprintf(buffer, "%s", "Hello, world!");
  sprintf(expected, "%s", "Hello, world!");
  ck_assert_str_eq(buffer, expected);

  // Тест для пустой строки
  s21_sprintf(buffer, "%s", "");
  sprintf(expected, "%s", "");
  ck_assert_str_eq(buffer, expected);

  // Тест для обычной строки
  s21_sprintf(buffer, "%s", "Hello");
  sprintf(expected, "%s", "Hello");
  ck_assert_str_eq(buffer, expected);

  // Тест для строки с цифрами
  s21_sprintf(buffer, "%s", "12345");
  sprintf(expected, "%s", "12345");
  ck_assert_str_eq(buffer, expected);

  // Тест для строки с специальными символами
  s21_sprintf(buffer, "%s", "@#$%");
  sprintf(expected, "%s", "@#$%");
  ck_assert_str_eq(buffer, expected);

  // Тест для длинной строки
  s21_sprintf(buffer, "%s", "This is a very long string");
  sprintf(expected, "%s", "This is a very long string");
  ck_assert_str_eq(buffer, expected);

  // Тест для строки с нулевым символом
  s21_sprintf(buffer, "%s", "Hello\0World");
  sprintf(expected, "%s", "Hello");
  ck_assert_str_eq(buffer, expected);

  // Тест для строки с указанием ширины поля
  s21_sprintf(buffer, "%10s", "Hello");
  sprintf(expected, "%10s", "Hello");
  ck_assert_str_eq(buffer, expected);

  // Тест для строки с минусом (выравнивание по левому краю)
  s21_sprintf(buffer, "%-10s", "Hello");
  sprintf(expected, "%-10s", "Hello");
  ck_assert_str_eq(buffer, expected);

  // Тест для строки с указанием точности
  s21_sprintf(buffer, "%.5s", "Hello World");
  sprintf(expected, "%.5s", "Hello");
  ck_assert_str_eq(buffer, expected);
}
END_TEST

//%o
START_TEST(test_s21_sprintf_octal) {
  char buffer[100];
  char expected[100];

  // Тест для нуля
  s21_sprintf(buffer, "%o", 0);
  sprintf(expected, "%o", 0);
  ck_assert_str_eq(buffer, expected);

  // Тест для небольшого положительного числа
  s21_sprintf(buffer, "%o", 7);
  sprintf(expected, "%o", 7);
  ck_assert_str_eq(buffer, expected);

  // Тест для среднего положительного числа
  s21_sprintf(buffer, "%o", 123);
  sprintf(expected, "%o", 123);
  ck_assert_str_eq(buffer, expected);

  // Тест для большого положительного числа
  s21_sprintf(buffer, "%o", 123456789);
  sprintf(expected, "%o", 123456789);
  ck_assert_str_eq(buffer, expected);

  // Тест для unsigned int
  unsigned int uint_value = 4294967295U;
  s21_sprintf(buffer, "%o", uint_value);
  sprintf(expected, "%o", uint_value);
  ck_assert_str_eq(buffer, expected);

  // Тест для короткого числа (short int)
  short int short_value = 255;
  s21_sprintf(buffer, "%ho", short_value);
  sprintf(expected, "%ho", short_value);
  ck_assert_str_eq(buffer, expected);

  // Тест для длинного числа (long int)
  long int long_value = 1234567890L;
  s21_sprintf(buffer, "%lo", long_value);
  sprintf(expected, "%lo", long_value);
  ck_assert_str_eq(buffer, expected);

  // Тест для длинного длинного числа (long long int)
  long long int longlong_value = 1234567890123456789LL;
  s21_sprintf(buffer, "%llo", longlong_value);
  sprintf(expected, "%llo", longlong_value);
  ck_assert_str_eq(buffer, expected);

  // Тест для отрицательного числа
  int negative_value = -123;
  s21_sprintf(buffer, "%o", negative_value);
  sprintf(expected, "%o", negative_value);
  ck_assert_str_eq(buffer, expected);

  // Тест для числа с ведущими нулями
  s21_sprintf(buffer, "%010o", 123);
  sprintf(expected, "%010o", 123);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

//%x
START_TEST(test_s21_sprintf_hex) {
  char buffer[100];
  char expected[100];

  // Тест для нуля
  s21_sprintf(buffer, "%x", 0);
  sprintf(expected, "%x", 0);
  ck_assert_str_eq(buffer, expected);

  // Тест для небольшого числа
  s21_sprintf(buffer, "%x", 15);
  sprintf(expected, "%x", 15);
  ck_assert_str_eq(buffer, expected);

  // Тест для среднего числа
  s21_sprintf(buffer, "%x", 123456);
  sprintf(expected, "%x", 123456);
  ck_assert_str_eq(buffer, expected);

  // Тест для большого числа
  s21_sprintf(buffer, "%x", 4294967295U);
  sprintf(expected, "%x", 4294967295U);
  ck_assert_str_eq(buffer, expected);

  // Тест для числа с указанием ширины поля
  s21_sprintf(buffer, "%10x", 255);
  sprintf(expected, "%10x", 255);
  ck_assert_str_eq(buffer, expected);

  // Тест для числа с нулевым заполнением
  s21_sprintf(buffer, "%010x", 255);
  sprintf(expected, "%010x", 255);
  ck_assert_str_eq(buffer, expected);

  // Тест для числа с указанием точности
  s21_sprintf(buffer, "%.5x", 255);
  sprintf(expected, "%.5x", 255);
  ck_assert_str_eq(buffer, expected);

  // Тест для длинного числа (unsigned long int)
  unsigned long int a = 1234567890UL;
  s21_sprintf(buffer, "%lx", a);
  sprintf(expected, "%lx", a);
  ck_assert_str_eq(buffer, expected);

  // Тест для нуля
  s21_sprintf(buffer, "%X", 0);
  sprintf(expected, "%X", 0);
  ck_assert_str_eq(buffer, expected);

  // Тест для небольшого числа
  s21_sprintf(buffer, "%X", 15);
  sprintf(expected, "%X", 15);
  ck_assert_str_eq(buffer, expected);

  // Тест для среднего числа
  s21_sprintf(buffer, "%X", 123456);
  sprintf(expected, "%X", 123456);
  ck_assert_str_eq(buffer, expected);

  // Тест для большого числа
  s21_sprintf(buffer, "%X", 4294967295U);
  sprintf(expected, "%X", 4294967295U);
  ck_assert_str_eq(buffer, expected);

  // Тест для числа с нулевым заполнением
  s21_sprintf(buffer, "%010x", 255);
  sprintf(expected, "%010x", 255);
  ck_assert_str_eq(buffer, expected);

  // Тест для числа с указанием точности
  s21_sprintf(buffer, "%.5x", 255);
  sprintf(expected, "%.5x", 255);
  ck_assert_str_eq(buffer, expected);

  // Тест для длинного числа (unsigned long int)
  unsigned long int ulong_value = 1234567890UL;
  s21_sprintf(buffer, "%lx", ulong_value);
  sprintf(expected, "%lx", ulong_value);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

//%p
START_TEST(test_s21_sprintf_pointer) {
  char buffer[100];
  char expected[100];

  // Тест для указателя на char
  char char_value = 'A';
  char *char_ptr = &char_value;
  s21_sprintf(buffer, "%p", (void *)char_ptr);
  sprintf(expected, "%p", (void *)char_ptr);
  ck_assert_str_eq(buffer, expected);

  // Тест для указателя на double
  double double_value = 3.14;
  double *double_ptr = &double_value;
  s21_sprintf(buffer, "%p", (void *)double_ptr);
  sprintf(expected, "%p", (void *)double_ptr);
  ck_assert_str_eq(buffer, expected);

  // Тест для указателя на массив
  int arr[10];
  int *arr_ptr = arr;
  s21_sprintf(buffer, "%p", (void *)arr_ptr);
  sprintf(expected, "%p", (void *)arr_ptr);
  ck_assert_str_eq(buffer, expected);

  // Тест для указателя на структуру
  struct TestStruct {
    int a;
    double b;
  };
  struct TestStruct ts;
  struct TestStruct *struct_ptr = &ts;
  s21_sprintf(buffer, "%p", (void *)struct_ptr);
  sprintf(expected, "%p", (void *)struct_ptr);
  ck_assert_str_eq(buffer, expected);

  // Тест для указателя на указатель
  int **pptr = &arr_ptr;
  s21_sprintf(buffer, "%p", (void *)pptr);
  sprintf(expected, "%p", (void *)pptr);
  ck_assert_str_eq(buffer, expected);

  // Тест для указателя на heap-объект
  int *heap_ptr = (int *)malloc(sizeof(int));
  *heap_ptr = 42;
  s21_sprintf(buffer, "%p", (void *)heap_ptr);
  sprintf(expected, "%p", (void *)heap_ptr);
  ck_assert_str_eq(buffer, expected);
  free(heap_ptr);

  // Тест для указателя на const объект
  const int const_value = 42;
  const int *const_ptr = &const_value;
  s21_sprintf(buffer, "%p", (void *)const_ptr);
  sprintf(expected, "%p", (void *)const_ptr);
  ck_assert_str_eq(buffer, expected);
}
END_TEST

//%i
START_TEST(test_s21_sprintf_integer) {
  char buffer[100];
  char expected[100];

  // Тест для положительного десятичного числа
  s21_sprintf(buffer, "%i", 123);
  sprintf(expected, "%i", 123);
  ck_assert_str_eq(buffer, expected);

  // Тест для отрицательного десятичного числа
  s21_sprintf(buffer, "%i", -123);
  sprintf(expected, "%i", -123);
  ck_assert_str_eq(buffer, expected);

  // Тест для положительного восьмеричного числа
  s21_sprintf(buffer, "%i", 0123);
  sprintf(expected, "%i", 0123);
  ck_assert_str_eq(buffer, expected);

  // Тест для отрицательного восьмеричного числа
  s21_sprintf(buffer, "%i", -0123);
  sprintf(expected, "%i", -0123);
  ck_assert_str_eq(buffer, expected);

  // Тест для положительного шестнадцатеричного числа
  s21_sprintf(buffer, "%i", 0x123);
  sprintf(expected, "%i", 0x123);
  ck_assert_str_eq(buffer, expected);

  // Тест для отрицательного шестнадцатеричного числа
  s21_sprintf(buffer, "%i", -0x123);
  sprintf(expected, "%i", -0x123);
  ck_assert_str_eq(buffer, expected);

  // Тест для числа с указанием ширины поля
  s21_sprintf(buffer, "%10i", 123);
  sprintf(expected, "%10i", 123);
  ck_assert_str_eq(buffer, expected);

  // Тест для числа с нулевым заполнением
  s21_sprintf(buffer, "%010i", 123);
  sprintf(expected, "%010i", 123);
  ck_assert_str_eq(buffer, expected);

  // Тест для числа с указанием точности
  s21_sprintf(buffer, "%.5i", 123);
  sprintf(expected, "%.5i", 123);
  ck_assert_str_eq(buffer, expected);
}

void assert_trim(const char *src, const char *trim_chars,
                 const char *expected) {
  char *result = s21_trim(src, trim_chars);
  ck_assert_str_eq(result, expected);
  free(result);
}

START_TEST(s21_trim_test) {
  char *str_to_trim = " \n   Hello, world!  !\n";
  char *trimmed_str = s21_trim(str_to_trim, " !\nd");

  ck_assert_str_eq(trimmed_str, "Hello, worl");
  free(trimmed_str);

  char *empty_format = "";
  trimmed_str = s21_trim(str_to_trim, empty_format);
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, " \n   Hello, world!  !\n");
    free(trimmed_str);
  }

  trimmed_str = s21_trim(s21_NULL, empty_format);
  ck_assert(trimmed_str == s21_NULL);

  char *str_to_trim2 = "xxx Hello, world! xxx ---";
  char *format_str = "x -";
  trimmed_str = s21_trim(str_to_trim2, format_str);
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "Hello, world!");
    free(trimmed_str);
  }

  // Basic trim tests
  assert_trim("  hello  ", " ", "hello");
  assert_trim("xxhelloxx", "x", "hello");
  assert_trim("  xxhello worldxx  ", " x", "hello world");

  // Empty source string
  assert_trim("", " ", "");

  // No trim characters
  assert_trim("hello", "", "hello");

  // All trim characters
  assert_trim("xxxx", "x", "");

  // No matching trim characters
  assert_trim("hello", "x", "hello");

  // Null source string
  ck_assert_ptr_eq(s21_trim(NULL, " "), NULL);

  // Null trim characters string
  ck_assert_ptr_eq(s21_trim("hello", NULL), NULL);
}
END_TEST

START_TEST(test_s21_sprintf_plus_flag) {
  char s21_buffer[100];
  char std_buffer[100];

  // Тест 1: положительное число
  s21_sprintf(s21_buffer, "%+d", 42);
  sprintf(std_buffer, "%+d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест 2: отрицательное число
  s21_sprintf(s21_buffer, "%+d", -42);
  sprintf(std_buffer, "%+d", -42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест 3: ноль
  s21_sprintf(s21_buffer, "%+d", 0);
  sprintf(std_buffer, "%+d", 0);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест 4: положительное число с шириной
  s21_sprintf(s21_buffer, "%+5d", 42);
  sprintf(std_buffer, "%+5d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест 5: отрицательное число с шириной
  s21_sprintf(s21_buffer, "%+5d", -42);
  sprintf(std_buffer, "%+5d", -42);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_hash_flag) {
  char s21_buffer[100];
  char std_buffer[100];

  // Тест 1: шестнадцатеричное число
  s21_sprintf(s21_buffer, "%#x", 255);
  sprintf(std_buffer, "%#x", 255);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест 2: восьмеричное число
  s21_sprintf(s21_buffer, "%#o", 255);
  sprintf(std_buffer, "%#o", 255);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест 3: ноль
  s21_sprintf(s21_buffer, "%#x", 0);
  sprintf(std_buffer, "%#x", 0);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест 4: восьмеричное число с шириной
  s21_sprintf(s21_buffer, "%#5o", 255);
  sprintf(std_buffer, "%#5o", 255);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест 5: шестнадцатеричное число с шириной
  s21_sprintf(s21_buffer, "%#8x", 255);
  sprintf(std_buffer, "%#8x", 255);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_space_flag) {
  char s21_buffer[100];
  char std_buffer[100];

  // Тест 1: положительное число
  s21_sprintf(s21_buffer, "% d", 42);
  sprintf(std_buffer, "% d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест 2: отрицательное число
  s21_sprintf(s21_buffer, "% d", -42);
  sprintf(std_buffer, "% d", -42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест 3: ноль
  s21_sprintf(s21_buffer, "% d", 0);
  sprintf(std_buffer, "% d", 0);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест 4: положительное число с шириной
  s21_sprintf(s21_buffer, "% 5d", 42);
  sprintf(std_buffer, "% 5d", 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест 5: отрицательное число с шириной
  s21_sprintf(s21_buffer, "% 5d", -42);
  sprintf(std_buffer, "% 5d", -42);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_width_asterisk) {
  char s21_buffer[100];
  char std_buffer[100];

  // Тест 1: положительное число с шириной 5
  s21_sprintf(s21_buffer, "%*d", 5, 42);
  sprintf(std_buffer, "%*d", 5, 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест 2: отрицательное число с шириной 5
  s21_sprintf(s21_buffer, "%*d", 5, -42);
  sprintf(std_buffer, "%*d", 5, -42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест 3: положительное число с шириной 0
  s21_sprintf(s21_buffer, "%*d", 0, 42);
  sprintf(std_buffer, "%*d", 0, 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест 4: положительное число с отрицательной шириной
  s21_sprintf(s21_buffer, "%*d", -5, 42);
  sprintf(std_buffer, "%*d", -5, 42);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест 5: ноль с шириной 5
  s21_sprintf(s21_buffer, "%*d", 5, 0);
  sprintf(std_buffer, "%*d", 5, 0);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_specifier_L) {
  char s21_buffer[100];
  char std_buffer[100];

  // Тест 1: длинное вещественное число
  s21_sprintf(s21_buffer, "%Lf", 3.141592653589793238L);
  sprintf(std_buffer, "%Lf", 3.141592653589793238L);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест 2: длинное вещественное число с шириной
  s21_sprintf(s21_buffer, "%20Lf", 3.141592653589793238L);
  sprintf(std_buffer, "%20Lf", 3.141592653589793238L);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест 3: длинное вещественное число с точностью
  s21_sprintf(s21_buffer, "%.10Lf", 3.141592653589793238L);
  sprintf(std_buffer, "%.10Lf", 3.141592653589793238L);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест 4: длинное вещественное число с точностью и шириной
  s21_sprintf(s21_buffer, "%20.10Lf", 3.141592653589793238L);
  sprintf(std_buffer, "%20.10Lf", 3.141592653589793238L);
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест 5: длинное вещественное число с нулем
  s21_sprintf(s21_buffer, "%Lf", 0.0L);
  sprintf(std_buffer, "%Lf", 0.0L);
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

START_TEST(test_s21_sprintf_percent) {
  char s21_buffer[100];
  char std_buffer[100];

  // Тест 1: один символ '%'
  s21_sprintf(s21_buffer, "%%");
  sprintf(std_buffer, "%%");
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест 2: символ '%' с текстом
  s21_sprintf(s21_buffer, "100%% sure");
  sprintf(std_buffer, "100%% sure");
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест 3: символ '%' с текстом и числом
  s21_sprintf(s21_buffer, "Value: 50%%");
  sprintf(std_buffer, "Value: 50%%");
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест 4: два символа '%'
  s21_sprintf(s21_buffer, "%% %%");
  sprintf(std_buffer, "%% %%");
  ck_assert_str_eq(s21_buffer, std_buffer);

  // Тест 5: символ '%' с пустой строкой
  s21_sprintf(s21_buffer, "%%%s%%", "");
  sprintf(std_buffer, "%%%s%%", "");
  ck_assert_str_eq(s21_buffer, std_buffer);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("s21_string");
  TCase *tc1 = tcase_create("s21_string");
  SRunner *sr = srunner_create(s1);
  int nf;

  tcase_add_test(tc1, s21_memchr_test);
  tcase_add_test(tc1, s21_memset_test);
  tcase_add_test(tc1, s21_memcpy_test);
  tcase_add_test(tc1, s21_strncat_test);
  tcase_add_test(tc1, s21_memcmp_test);
  tcase_add_test(tc1, s21_strstr_test);
  tcase_add_test(tc1, s21_strlen_test);
  tcase_add_test(tc1, s21_strncpy_test);
  tcase_add_test(tc1, s21_strchr_test);
  tcase_add_test(tc1, s21_strncmp_test);
  tcase_add_test(tc1, s21_strcspn_test);
  tcase_add_test(tc1, s21_strpbrk_test);
  tcase_add_test(tc1, s21_strrchr_test);
  tcase_add_test(tc1, s21_strtok_test);
  tcase_add_test(tc1, s21_to_upper_test);
  tcase_add_test(tc1, s21_to_lower_test);
  tcase_add_test(tc1, s21_insert_test);
  tcase_add_test(tc1, s21_trim_test);
  tcase_add_test(tc1, s21_strerror_test);

  // sprintf
  tcase_add_test(tc1, test_s21_sprintf_int);
  tcase_add_test(tc1, test_s21_sprintf_unsigned);
  tcase_add_test(tc1, test_s21_sprintf_char);
  tcase_add_test(tc1, test_s21_sprintf_string);
  tcase_add_test(tc1, test_s21_sprintf_hex);
  tcase_add_test(tc1, test_s21_sprintf_octal);
  tcase_add_test(tc1, test_s21_sprintf_pointer);
  tcase_add_test(tc1, test_s21_sprintf_integer);
  tcase_add_test(tc1, test_s21_sprintf_float);
  tcase_add_test(tc1, test_s21_sprintf_plus_flag);
  tcase_add_test(tc1, test_s21_sprintf_hash_flag);
  tcase_add_test(tc1, test_s21_sprintf_space_flag);
  tcase_add_test(tc1, test_s21_sprintf_width_asterisk);
  tcase_add_test(tc1, test_s21_sprintf_specifier_L);
  tcase_add_test(tc1, test_s21_sprintf_percent);

  suite_add_tcase(s1, tc1);

  srunner_run_all(sr, CK_NORMAL);

  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (nf == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}