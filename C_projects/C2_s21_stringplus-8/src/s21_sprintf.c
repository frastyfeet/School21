#include "s21_string.h"

int s21_sprintf(char* str, const char* format, ...) {
  if (str == s21_NULL || format == s21_NULL) return -1;
  char flags[] = "cdiosuxXpf%";
  char* src = str;
  va_list arg;
  va_start(arg, format);

  while (*format) {
    if (*format == '%') {
      format++;
      specifier specifiers = {0};
      specifiers.num_sys = 10;
      format = set_specifiers(&specifiers, format, &arg);
      while (!s21_strchr(flags, *format)) format++;
      str = parser(str, src, format, &specifiers, &arg);
    } else {
      *str = *format;
      str++;
    }
    format++;
  }

  *str = '\0';
  va_end(arg);
  return (str - src);
}

const char* set_flags(const char* format, specifier* specifiers) {
  while (*format) {
    if (*format == '+')
      specifiers->sign = 1;
    else if (*format == '-')
      specifiers->left_align = 1;
    else if (*format == '#')
      specifiers->hash = 1;
    else if (*format == ' ')
      specifiers->space = 1;
    else if (*format == '0')
      specifiers->zero = 1;
    else
      break;
    format++;
  }
  specifiers->space = (specifiers->space && !specifiers->sign);
  specifiers->zero = (specifiers->zero && !specifiers->left_align);
  return format;
}

const char* set_width(const char* format, int* width, va_list arg) {
  *width = 0;
  if (*format == '*') {
    *width = va_arg(arg, int);
    format++;
  }
  while (*format >= '0' && *format <= '9') {
    *width *= 10;
    *width += *format - '0';
    format++;
  }
  return format;
}

const char* set_specifiers(specifier* specifiers, const char* format,
                           va_list* arg) {
  format = set_flags(format, specifiers);
  format = set_width(format, &specifiers->width, *arg);
  if (specifiers->width < 0) {
    specifiers->left_align = 1;
    specifiers->width *= -1;
  }
  if (*format == '.') {
    specifiers->dot = 1;
    specifiers->zero = 0;
    format++;
    format = set_width(format, &specifiers->accuracy, *arg);
  }
  if (*format == 'L')
    specifiers->length = 'L';
  else if (*format == 'l')
    specifiers->length = 'l';
  else if (*format == 'h')
    specifiers->length = 'h';
  return format;
}

char* parser(char* str, char* src, const char* format, specifier* specifiers,
             va_list* arg) {
  switch (*format) {
    case 'd':
    case 'i':
      str = func_d(str, *specifiers, arg);
      break;
    case 'u':
    case 'o':
    case 'x':
    case 'X':
    case 'p':
      *specifiers = set_system(*specifiers, *format);
      str = func_u(str, *specifiers, *(format - 1), arg);
      break;
    case 'c': {
      int s = va_arg(*arg, int);
      str = func_c(str, *specifiers, s);
      break;
    }
    case 's':
      str = func_s(str, *specifiers, arg);
      break;
    case 'f':
      str = func_f(str, *specifiers, arg);
      break;
    case '%':
      str = func_c(str, *specifiers, '%');
      break;
    default:
      str = s21_NULL;
      break;
  }

  if (!str) *src = '\0';
  return str;
}

char* func_d(char* str, specifier specifiers, va_list* arg) {
  long int number = 0;
  if (specifiers.length == 'l')
    number = (long int)va_arg(*arg, long int);
  else
    number = (int)va_arg(*arg, int);

  s21_size_t size_decimal = get_size(&specifiers, number);
  char* string_to_number = malloc(sizeof(char) * size_decimal + 1);
  if (string_to_number) {
    int i =
        number_to_string(specifiers, number, string_to_number, size_decimal);
    for (int j = i - 1; j >= 0; j--) {
      *str++ = string_to_number[j];
    }
    if (specifiers.width > 0) {
      while (i < specifiers.width) {
        *str = ' ';
        str++;
        i++;
      }
    }

    free(string_to_number);
  } else {
    return s21_NULL;
  }
  *str = '\0';
  return str;
}

s21_size_t get_size(specifier* specifiers, long int number) {
  s21_size_t result = 0;
  unsigned long int copy = number < 0 ? -number : number;

  while (copy > 0) {
    copy /= 10;
    result++;
  }

  if (number == 0 && (specifiers->accuracy || specifiers->width ||
                      specifiers->space || specifiers->sign))
    result++;

  if ((s21_size_t)specifiers->width > result)
    result = (s21_size_t)specifiers->width;

  if ((s21_size_t)specifiers->accuracy > result)
    result = (s21_size_t)specifiers->accuracy;

  if (specifiers->space || specifiers->sign || number < 0) {
    specifiers->size_flag = 1;
    result++;
  }

  if (result == 0 && copy == 0 && !specifiers->accuracy && !specifiers->width &&
      !specifiers->space && !specifiers->dot)
    result++;

  return result;
}

int number_to_string(specifier specifiers, long int number,
                     char* string_to_number, s21_size_t size_decimal) {
  int flag = 0;
  if (number < 0) {
    flag = 1;
    number *= -1;
  }
  int i = 0;
  unsigned long int copy = number;

  read_num(&copy, &size_decimal, &i, string_to_number, &specifiers);

  if (flag) number *= -1;

  if (specifiers.accuracy > i) {
    specifiers.accuracy -= i;
    specifiers.zero = 1;
  } else
    flag = 1;

  if (size_decimal == 1 && specifiers.zero == 1 && specifiers.size_flag == 1)
    specifiers.zero = 0;

  flag_zero(string_to_number, &specifiers, flag, &i, &size_decimal);
  flag_plus_minus_space(specifiers, string_to_number, &i, &size_decimal,
                        number);

  if (size_decimal > 0 && specifiers.left_align == 0) {
    while ((size_decimal - specifiers.size_flag > 0) && string_to_number) {
      string_to_number[i] = ' ';
      i++;
      size_decimal--;
    }
  }
  return i;
}

void flag_zero(char* string_to_number, specifier* specifiers, int flag, int* i,
               s21_size_t* size_decimal) {
  while (specifiers->zero && string_to_number &&
         (*size_decimal > 0 && (specifiers->accuracy > 0 || flag)) &&
         (specifiers->accuracy || flag)) {
    if ((*size_decimal == 1 && specifiers->size_flag == 1)) break;
    string_to_number[*i] = '0';
    (*i)++;
    (*size_decimal)--;
    specifiers->accuracy--;
  }
}

void flag_plus_minus_space(specifier specifiers, char* string_to_number, int* i,
                           s21_size_t* size_decimal, int number) {
  if (specifiers.space && number >= 0 && *size_decimal) {
    string_to_number[*i] = ' ';
    (*i)++;
    (*size_decimal)--;
  }

  if (number < 0 && *size_decimal) {
    string_to_number[*i] = '-';
    (*i)++;
    (*size_decimal)--;
  }
  if (number >= 0 && specifiers.sign && *size_decimal) {
    string_to_number[*i] = '+';
    (*i)++;
    (*size_decimal)--;
  }
}

void read_num(unsigned long int* copy, s21_size_t* size_decimal, int* i,
              char* string_to_number, specifier* specifiers) {
  if ((*copy == 0 &&
       (specifiers->accuracy || specifiers->width || specifiers->space)) ||
      (*copy == 0 && !specifiers->accuracy && !specifiers->width &&
       !specifiers->space && !specifiers->dot)) {
    char symbol = *copy % specifiers->num_sys + '0';
    string_to_number[*i] = symbol;
    (*i)++;
    (*size_decimal)--;
    *copy /= specifiers->num_sys;
  }
  while (*copy && string_to_number && *size_decimal) {
    char symbol = get_char(*copy % specifiers->num_sys, specifiers->upper_case);
    string_to_number[*i] = symbol;
    (*i)++;
    (*size_decimal)--;
    *copy /= specifiers->num_sys;
  }
}

char get_char(int num, int upper_case) {
  char str = '0';
  switch (num) {
    case 10:
      str = (char)('a' - upper_case * 32);
      break;
    case 11:
      str = (char)('b' - upper_case * 32);
      break;
    case 12:
      str = (char)('c' - upper_case * 32);
      break;
    case 13:
      str = (char)('d' - upper_case * 32);
      break;
    case 14:
      str = (char)('e' - upper_case * 32);
      break;
    case 15:
      str = (char)('f' - upper_case * 32);
      break;
  }
  if (num >= 0 && num <= 9) str = (char)(num + '0');

  return str;
}
specifier set_system(specifier specifiers, char format) {
  if (format == 'o')
    specifiers.num_sys = 8;
  else if (format == 'x' || format == 'X')
    specifiers.num_sys = 16;
  if (format == 'X') specifiers.upper_case = 1;
  if (format == 'p') {
    specifiers.hash = 1;
    specifiers.num_sys = 16;
    specifiers.upper_case = 0;
    specifiers.p = 1;
  }
  return specifiers;
}
char* func_u(char* str, specifier specifiers, char format, va_list* arg) {
  unsigned long int number = 0;
  if (format == 'l')
    number = (unsigned long int)va_arg(*arg, unsigned long int);
  else if (format == 'h')
    number = (unsigned short)va_arg(*arg, int);
  else if (specifiers.hash == 1 && specifiers.num_sys == 16 &&
           specifiers.upper_case == 0)
    number = (unsigned long int)va_arg(*arg, unsigned long int);
  else
    number = (unsigned int)va_arg(*arg, unsigned int);
  s21_size_t size_number = get_size_unsigned(&specifiers, number);
  char* buf = malloc(sizeof(char) * size_number);
  if (buf) {
    int i = unsigned_to_string(buf, specifiers, number, size_number);
    if (specifiers.width > i) {
      while (size_number > (s21_size_t)i) {
        *str = ' ';
        str++;
        size_number--;
      }
    }
    for (int j = i - 1; j >= 0; j--) {
      *str = buf[j];
      str++;
    }
    free(buf);
  } else {
    return s21_NULL;
  }
  if (number == 0 && specifiers.hash == 1 && specifiers.num_sys == 16 &&
      specifiers.upper_case == 0 && specifiers.p) {
    str -= 3;
    s21_strncpy(str, "(nil)", 6);
    str += s21_strlen("(nil)");
  }
  return str;
}

s21_size_t get_size_unsigned(specifier* specifiers, unsigned long int number) {
  s21_size_t result = 0;
  unsigned long int copy = number;

  if (specifiers->num_sys == 16 && specifiers->hash) {
    result += 2;
  }

  while (copy > 0) {
    copy /= specifiers->num_sys;
    result++;
  }
  if ((s21_size_t)specifiers->width > result) {
    result = specifiers->width;
  }
  if ((s21_size_t)specifiers->accuracy > result) {
    result = specifiers->accuracy;
  }
  if (specifiers->space) {
    result++;
  }
  if (result == 0 && copy == 0 && !specifiers->accuracy && !specifiers->width &&
      !specifiers->space && !specifiers->dot) {
    result++;
  }

  return result;
}

int unsigned_to_string(char* buf, specifier specifiers,
                       unsigned long int number, s21_size_t size_number) {
  int flag = 0;
  int i = 0;
  unsigned long int copy = number;

  if (specifiers.hash && specifiers.num_sys == 8)
    specifiers.size_flag = 1;
  else if (specifiers.hash && specifiers.num_sys == 16)
    specifiers.size_flag = 2;

  read_num(&copy, &size_number, &i, buf, &specifiers);

  if (specifiers.accuracy > i) {
    specifiers.accuracy -= i;
    specifiers.zero = 1;
  } else
    flag = 1;

  if (size_number == 1 && specifiers.zero == 1 && specifiers.size_flag == 1)
    specifiers.zero = 0;

  flag_zero(buf, &specifiers, flag, &i, &size_number);
  int size = (int)size_number;
  if (!(number == 0 && specifiers.hash == 1 && specifiers.num_sys == 16))
    check_sys(specifiers, buf, &i, &size);

  if (size > 0 && specifiers.left_align == 0) {
    while ((size - specifiers.size_flag > 0) && buf) {
      buf[i] = ' ';
      i++;
      size--;
    }
  }
  return i;
}

void check_sys(specifier specifiers, char* buffer, int* i, int* size_number) {
  if (specifiers.hash && specifiers.num_sys == 8) {
    buffer[*i] = '0';
    (*i)++;
    (*size_number)--;
  } else if (specifiers.hash && specifiers.num_sys == 16 &&
             specifiers.upper_case) {
    buffer[*i] = 'X';
    (*i)++;
    (*size_number)--;
    buffer[*i] = '0';
    (*i)++;
    (*size_number)--;
  } else if (specifiers.hash && specifiers.num_sys == 16 &&
             !specifiers.upper_case) {
    buffer[*i] = 'x';
    (*i)++;
    (*size_number)--;
    buffer[*i] = '0';
    (*i)++;
    (*size_number)--;
  }
}

char* func_c(char* str, specifier specifiers, int sym) {
  char* p = s21_NULL;
  while (specifiers.width - 1 > 0 && !specifiers.left_align) {
    *str = ' ';
    str++;
    specifiers.width--;
  }
  *str = sym;
  str++;

  while (specifiers.width - 1 > 0 && specifiers.left_align) {
    *str = ' ';
    str++;
    specifiers.width--;
  }
  p = str;
  return p;
}

char* func_s(char* str, specifier specifiers, va_list* arg) {
  char* p = str;
  char* string = va_arg(*arg, char*);
  if (string) {
    int temp = specifiers.width;

    if ((s21_size_t)specifiers.width < s21_strlen(string))
      specifiers.width = s21_strlen(string);

    int blank = specifiers.width - s21_strlen(string);

    if (specifiers.accuracy == 0) specifiers.accuracy = specifiers.width;

    if (specifiers.accuracy != 0 && specifiers.accuracy < temp)
      blank = temp - specifiers.accuracy;

    while (blank && !specifiers.left_align) {
      *str = ' ';
      str++;
      blank--;
    }
    while (*string != '\0') {
      if (!specifiers.accuracy) break;
      *str = *string;
      str++;
      string++;
      specifiers.accuracy--;
    }
    while (blank && specifiers.left_align) {
      *str = ' ';
      str++;
      blank--;
    }
  } else {
    str = s21_memcpy(str, "(null)", 6);
    str += 6;
  }
  if (p) p = str;

  return p;
}

s21_size_t get_size_float(specifier* specifiers, long double number) {
  s21_size_t result = 0;
  long double copy = number < 0 ? -number : number;

  long long integerPart = (long long)copy;
  do {
    integerPart /= 10;
    result++;
  } while (integerPart > 0);

  if (!specifiers->dot) {
    specifiers->accuracy = 6;
  }

  result += 1 + specifiers->accuracy;

  if (number < 0 || specifiers->sign) {
    result++;
  }
  if ((s21_size_t)specifiers->width > result) {
    result = specifiers->width;
  }
  return result;
}
char* func_f(char* str, specifier specifiers, va_list* arg) {
  long double number = 0;
  if (specifiers.length == 'L')
    number = (long double)va_arg(*arg, long double);
  else
    number = (double)va_arg(*arg, double);
  if (number < 0) {
    *str = '-';
    str++;
    number = -number;
  }
  s21_size_t size_number = get_size_float(&specifiers, number);
  char* float_to_number = malloc(sizeof(char) * (size_number + 1));
  if (float_to_number) {
    int len = float_to_string(float_to_number, specifiers, number);
    if (specifiers.width > len) {
      while (size_number > (s21_size_t)len) {
        *str = ' ';
        str++;
        size_number--;
      }
    }
    for (int j = 0; j < len; j++) {
      *str = float_to_number[j];
      str++;
    }
    free(float_to_number);
  }
  *str = '\0';
  return str;
}

int float_to_string(char* buffer, specifier specifiers, long double number) {
  long double integerPart = 0, fractionalPart = modfl(number, &integerPart);
  int length = 0;
  if (integerPart == 0) {
    *buffer = '0';
    buffer++;
    length++;
  } else {
    char int_buffer[20];
    int temp_len = 0;
    while (integerPart >= 1) {
      int_buffer[temp_len++] = ((long long)integerPart % 10) + '0';
      integerPart = (long long)integerPart / 10;
    }
    for (int i = temp_len - 1; i >= 0; i--) {
      *buffer = int_buffer[i];
      buffer++;
      length++;
    }
  }
  if (specifiers.accuracy > 0 || specifiers.dot) {
    if (specifiers.accuracy > 0) {
      *buffer = '.';
      buffer++;
      length++;
    }
    fractionalPart = roundl(fractionalPart * powl(10, specifiers.accuracy));
    for (int i = specifiers.accuracy - 1; i >= 0; i--) {
      long long digit = (long long)fractionalPart % 10;
      buffer[i] = digit + '0';
      fractionalPart /= 10;
    }
    buffer += specifiers.accuracy;
    length += specifiers.accuracy;
  }
  *buffer = '\0';
  return length;
}