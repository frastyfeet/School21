#ifndef CAT_H
#define CAT_H

#define _GNU_SOURCE

#include <ctype.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
  bool numberNonBlank;
  bool markEndl;
  bool numberAll;
  bool squeeze;
  bool tab;
  bool printNonPrinttable;
} Flags;

Flags ReadFlags(int argc, char **argv);

void print_file(char *filename, Flags flag);
void print_flag_e(char *symbol, Flags flag);
void print_flag_t();
void print_flag_v(char *ch, bool *print);

#endif
