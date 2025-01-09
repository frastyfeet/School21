#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *upper = s21_NULL;
  if (str != s21_NULL)
    upper = malloc(s21_strlen(str) * sizeof(char) + 1);
  else
    return s21_NULL;
  for (s21_size_t i = 0; str[i] != '\0'; i++) {
    upper[i] = str[i];
    if (upper[i] >= 97 && upper[i] <= 122) upper[i] -= 32;
  }
  upper[s21_strlen(str)] = '\0';
  return (void *)upper;
}
void *s21_to_lower(const char *str) {
  char *lower = s21_NULL;
  if (str != s21_NULL)
    lower = malloc(s21_strlen(str) * sizeof(char) + 1);
  else
    return s21_NULL;
  for (s21_size_t i = 0; str[i] != '\0'; i++) {
    lower[i] = str[i];
    if (lower[i] >= 65 && lower[i] <= 90) lower[i] += 32;
  }
  lower[s21_strlen(str)] = '\0';
  return (void *)lower;
}
void *s21_insert(const char *src, const char *str, size_t start_index) {
  char *insert = s21_NULL;
  if (str != s21_NULL && src != s21_NULL)
    insert = malloc((s21_strlen(str) + s21_strlen(src)) * sizeof(char) + 1);
  else
    return s21_NULL;
  for (s21_size_t i = 0; i < start_index; i++) {
    insert[i] = src[i];
  }
  for (s21_size_t i = 0; str[i] != '\0'; i++) {
    insert[i + start_index] = str[i];
  }
  for (; src[start_index] != '\0'; start_index++) {
    insert[start_index + s21_strlen(str)] = src[start_index];
  }
  insert[s21_strlen(src) + s21_strlen(str)] = '\0';
  return (void *)insert;
}

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == s21_NULL || trim_chars == s21_NULL) return s21_NULL;

  s21_size_t start_index = 0;
  s21_size_t end_index = s21_strlen(src);

  while (start_index < end_index && s21_strchr(trim_chars, src[start_index])) {
    start_index++;
  }

  while (end_index > start_index &&
         s21_strchr(trim_chars, src[end_index - 1])) {
    end_index--;
  }
  s21_size_t new_length = end_index - start_index;
  char *trim = (char *)malloc(new_length + 1);
  if (trim == s21_NULL) return s21_NULL;
  for (s21_size_t i = 0; i < new_length; i++) {
    trim[i] = src[start_index + i];
  }
  trim[new_length] = '\0';

  return (void *)trim;
}