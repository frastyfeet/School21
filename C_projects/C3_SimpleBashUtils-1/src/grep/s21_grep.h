#ifndef S21_GREP_H
#define S21_GREP_H

#define _GNU_SOURCE

#include <ctype.h>
#include <getopt.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int e, i, v, c, l, n, h, s, o, f;
  char pattern[1024];

  int len_pattern;
  int mem_pattern;

} Flags;

Flags ReadFlags(int argc, char **argv);
void print_line(char *line, int n);
void process_File(Flags flag, char *filename, regex_t *reg, FILE *file);
void output(Flags flags, int argc, char **argv);
void pattern_add(Flags *flags, char *pattern);
void output_reg(regex_t *reg, char *line);
void add_pattern_from_file(Flags *flag, char *filename);
void output_l(Flags *flag, char *filename, int flag_l);
#endif
