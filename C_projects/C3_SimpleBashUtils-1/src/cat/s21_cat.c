#include "cat.h"

int main(int argc, char **argv) {
  Flags flags = ReadFlags(argc, argv);
  if (optind == argc) {
    print_file(NULL, flags);
  } else {
    for (int i = optind; i < argc; i++) {
      print_file(argv[i], flags);
    }
  }
}
Flags ReadFlags(int argc, char **argv) {
  struct option longOptoins[] = {{"number-nonblank", 0, NULL, 'b'},
                                 {"number", 0, NULL, 'n'},
                                 {"squeeze-blank", 0, NULL, 's'},
                                 {NULL, 0, NULL, 0}};

  int current_flag = getopt_long(argc, argv, "bevEnstT", longOptoins, NULL);
  Flags flags = {false, false, false, false, false, false};
  for (; current_flag != -1;
       current_flag = getopt_long(argc, argv, "bevEnstT", longOptoins, NULL)) {
    switch (current_flag) {
      case 'b':
        flags.numberNonBlank = true;
        break;
      case 'e':
        flags.markEndl = true;
        flags.printNonPrinttable = true;
        break;
      case 'v':
        flags.printNonPrinttable = true;
        break;
      case 'E':
        flags.markEndl = true;
        break;
      case 'n':
        flags.numberAll = true;
        break;
      case 's':
        flags.squeeze = true;
        break;
      case 't':
        flags.printNonPrinttable = true;
        flags.tab = true;
        break;
      case 'T':
        flags.tab = true;
        break;
    }
  }
  return flags;
}
void print_file(char *filename, Flags flag) {
  FILE *file;
  if (filename == NULL) {
    file = stdin;
  } else {
    file = fopen(filename, "rt");
    if (file == NULL) {
      perror("Error opening file");
      return;
    }
  }
  char c;
  char prev_sym;
  int counter_line = 1;
  bool print;
  int skip;
  skip = 0;
  if (flag.numberAll && flag.numberNonBlank) flag.numberAll = false;
  for (prev_sym = '\n'; (c = getc(file)) != EOF; prev_sym = c) {
    print = true;
    if (prev_sym == '\n') {
      if (flag.squeeze) {
        if (c == '\n') {
          if (skip) continue;
          skip = 1;
        } else {
          skip = 0;
        }
      }
      if (flag.numberAll && ((c == '\n') || (c != '\n')))
        printf("%6d\t", counter_line++);
      if (flag.numberNonBlank && c != '\n') printf("%6d\t", counter_line++);
    }
    if (c == '\n') {
      if (flag.markEndl) {
        print_flag_e(&prev_sym, flag);
      }
    } else if (c == '\t') {
      if (flag.tab) {
        print_flag_t();
        print = false;
      }
    } else if (flag.printNonPrinttable) {
      print_flag_v(&c, &print);
    }
    if (print) {
      putchar(c);
    }
  }
  fclose(file);
}
void print_flag_e(char *symbol, Flags flag) {
  if (*symbol == '\n' && flag.numberNonBlank) {
    printf("      \t$");
  } else {
    putchar('$');
  }
}
void print_flag_t() {
  putchar('^');
  putchar('I');
}
void print_flag_v(char *ch, bool *print) {
  if (!isascii(*ch) && !isprint(*ch)) {
    putchar('M');
    putchar('-');
    *ch = toascii(*ch);
  }
  if (iscntrl(*ch)) {
    putchar('^');
    putchar(*ch == 127 ? '?' : *ch + 64);
    *print = false;
  }
}
