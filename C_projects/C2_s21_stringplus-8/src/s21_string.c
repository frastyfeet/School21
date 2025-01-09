#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *res = s21_NULL;
  int flag = 0;

  for (; !flag && *str != '\0'; str++) {
    if (*str == c) {
      res = (char *)str;
      flag = 1;
    }
  }

  if (c == '\0') res = (char *)str;
  return res;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  if (str1 != s21_NULL && str2 != s21_NULL && n > 0) {
    for (s21_size_t i = 0; i < n; i++) {
      if (str1[i] == '\0' || str1[i] != str2[i]) {
        result = str1[i] - str2[i];
        break;
      }
    }
  }
  return result;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i;

  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }

  for (; i < n; i++) {
    dest[i] = '\0';
  }

  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t i, j;
  for (i = 0; i < s21_strlen(str1); i++) {
    for (j = 0; j < s21_strlen(str2); j++) {
      if (str2[j] == str1[i]) {
        return i;
      }
    }
  }
  return i;
}

char *s21_strerror(int errnum) {
  static char res[100] = {0};
#ifdef __linux__
  LINUX;
  if (errnum < 0 || errnum >= 134)
    s21_sprintf(res, "Unknown error: %d", errnum);
  else
    s21_strncpy(res, &Linux_errorlist[errnum][0], 30);
  return res;
#elif __APPLE__
  MACOS;
  if (errnum < 0 || errnum >= 107)
    s21_sprintf(res, "Unknown error: %d", errnum);
  else
    s21_strncpy(res, &MACOS_errorlist[errnum][0], 30);
  return res;
#endif
}

// Danil
s21_size_t s21_strlen(const char *str) {
  s21_size_t i = 0;
  while (str[i] != '\0') {
    i++;
  }
  return i;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  for (const char *p1 = str1; *p1 != '\0'; ++p1) {
    for (const char *p2 = str2; *p2 != '\0'; ++p2) {
      if (*p1 == *p2) {
        return (char *)p1;
      }
    }
  }
  return s21_NULL;
}

char *s21_strrchr(const char *str, int c) {
  void *result = s21_NULL;

  while (*str != '\0') {
    if (*str == c) {
      result = (char *)str;
    }
    str++;
  }

  if (c == '\0' && *str == c) {
    result = (char *)str;
  }

  return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
  if (haystack == s21_NULL || needle == s21_NULL) return s21_NULL;

  char *result = s21_NULL;

  for (s21_size_t i = 0; result == s21_NULL && haystack[i] != '\0'; i++) {
    s21_size_t j = 0;
    while (haystack[i + j] == needle[j] && needle[j] != '\0') j++;

    if (needle[j] == '\0') result = (char *)&haystack[i];
  }

  return result;
}

char *s21_strtok(char *str, const char *delim) {
  if (delim == s21_NULL) return s21_NULL;

  static char *next_token = s21_NULL;
  char *token = s21_NULL;

  if (str) next_token = str;

  if (next_token) {
    while (*next_token && s21_strchr(delim, *next_token)) next_token++;

    if (*next_token != '\0') {
      token = next_token;

      while (*next_token && !s21_strchr(delim, *next_token)) next_token++;

      if (*next_token)
        *next_token++ = '\0';
      else
        next_token = s21_NULL;
    }
  }

  return token;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *p1 = (const unsigned char *)str1;
  const unsigned char *p2 = (const unsigned char *)str2;

  while (n--) {
    if (*p1 != *p2) {
      return *p1 - *p2;
    }
    p1++;
    p2++;
  }

  return 0;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *p1 = str;
  unsigned char ch = (unsigned char)c;

  void *result = s21_NULL;

  while (n--) {
    if (*p1 == ch) {
      result = (void *)p1;
      break;
    }
    p1++;
  }

  return result;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *p1 = (unsigned char *)str;

  for (s21_size_t i = 0; i < n; i++) {
    p1[i] = (unsigned char)c;
  }
  return str;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *d = (unsigned char *)dest;
  const unsigned char *s = (const unsigned char *)src;
  while (n--) {
    *d++ = *s++;
  }
  return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *original_dest = dest;

  while (*dest) ++dest;

  while (n-- && *src) {
    *dest++ = *src++;
  }

  *dest = '\0';

  return original_dest;
}
