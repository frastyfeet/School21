#include "s21_grep.h"

int main(int argc, char **argv) {
  Flags flags = ReadFlags(argc, argv);
  output(flags, argc, argv);
}
Flags ReadFlags(int argc, char **argv) {
  int current_flag = getopt(argc, argv, "e:ivclnhsf:o");
  Flags flags = {0};
  for (; current_flag != -1;
       current_flag = getopt(argc, argv, "e:ivclnhsf:o")) {
    switch (current_flag) {
      case 'e':
        flags.e = 1;
        pattern_add(&flags, optarg);
        break;
      case 'i':
        flags.i = REG_ICASE;
        break;
      case 'v':
        flags.v = 1;
        break;
      case 'c':
        flags.c = 1;
        break;
      case 'l':
        flags.l = 1;
        break;
      case 'n':
        flags.n = 1;
        break;
      case 'h':
        flags.h = 1;
        break;
      case 's':
        flags.s = 1;
        break;
      case 'f':
        flags.f = 1;
        add_pattern_from_file(&flags, optarg);
        break;
      case 'o':
        flags.o = 1;
        break;
    }
  }
  if (flags.len_pattern == 0) {
    pattern_add(&flags, argv[optind]);
    optind++;
  }
  if (argc - optind == 1) {
    flags.h = 1;
  }
  return flags;
}

void print_line(char *line, int n) {
  for (int i = 0; i < n; i++) {
    putchar(line[i]);
  }
  if (line[n - 1] != '\n') {
    putchar('\n');
  }
}
void process_File(Flags flag, char *filename, regex_t *reg, FILE *file) {
  char *line = NULL;
  size_t memlen = 0;
  int read = 0, counter = 0, line_counter = 1, flag_l = 0;
  read = getline(&line, &memlen, file);
  while (read != -1) {
    int result = regexec(reg, line, 0, NULL, 0);
    if (!result && (flag.c || flag.n || flag.o || flag.l || flag.f) &&
        !flag.v) {
      if (flag.c) {
        if (flag.l) flag_l = 1;
        counter++;
      } else {
        if (!flag.h && !flag.l) printf("%s:", filename);
        if (flag.n && !flag.l && !flag.v) printf("%d:", line_counter);
        if (flag.l)
          flag_l = 1;
        else if (flag.o && !flag.c) {
          if (!flag.v) output_reg(reg, line);
        } else
          print_line(line, read);
      }
    } else if (flag.v && result) {
      if (!flag.h && !flag.l && !flag.c) printf("%s:", filename);
      if (flag.n && !flag.l && !flag.c) printf("%d:", line_counter);
      if (flag.c || flag.l) {
        if (flag.l) flag_l = 1;
        counter++;
      } else
        print_line(line, read);
    } else if (!result && !flag.v && !flag.l) {
      if (!flag.h) printf("%s:", filename);
      if (flag.n && !flag.l) printf("%d:", line_counter);
      print_line(line, read);
    }
    read = getline(&line, &memlen, file);
    line_counter++;
  }
  if (flag.c && !flag.l) {
    if (!flag.h) printf("%s:", filename);
    printf("%d\n", counter);
  }
  if (flag.l && flag_l) output_l(&flag, filename, flag_l);
  flag_l = 0;
  free(line);
  fclose(file);
}
void output(Flags flags, int argc, char **argv) {
  regex_t re;
  int error = regcomp(&re, flags.pattern, REG_EXTENDED | flags.i);
  if (error) perror("Error");
  for (int i = optind; i < argc; i++) {
    FILE *file = fopen(argv[i], "r");
    if (file == NULL) {
      if (!flags.s) perror("Error opening file");
      exit(1);
    }
    process_File(flags, argv[i], &re, file);
  }
  regfree(&re);
}

void pattern_add(Flags *flags, char *pattern) {
  if (flags->len_pattern != 0) {
    strcat(flags->pattern + flags->len_pattern, "|");
    flags->len_pattern++;
  }
  flags->len_pattern +=
      sprintf(flags->pattern + flags->len_pattern, "(%s)", pattern);
}
void output_reg(regex_t *reg, char *line) {
  regmatch_t pmatch;
  int offset = 0;
  while (1) {
    int result = regexec(reg, line + offset, 1, &pmatch, 0);
    if (result != 0) {
      break;
    }
    for (int i = pmatch.rm_so; i < pmatch.rm_eo; i++) {
      putchar(line[i]);
    }
    putchar('\n');
    offset += pmatch.rm_eo;
  }
}
void add_pattern_from_file(Flags *flag, char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    if (!flag->s) perror("Error opening file");
    exit(1);
  }
  size_t memlen = 0;
  char *line = NULL;
  int read = 0;
  read = getline(&line, &memlen, file);
  while (read != -1) {
    if (line[read - 1] == '\n') line[read - 1] = '\0';
    pattern_add(flag, line);
    read = getline(&line, &memlen, file);
  }
  free(line);
  fclose(file);
}
void output_l(Flags *flag, char *filename, int flag_l) {
  if (!flag->c)
    printf("%s\n", filename);
  else if (flag->h)
    printf("%d\n%s\n", flag_l, filename);
  else
    printf("%s:%d\n%s\n", filename, flag_l, filename);
}