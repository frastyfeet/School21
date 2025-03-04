/*
 * Check: a unit test framework for C
 * Copyright (C) 2001, 2002 Arien Malec
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#include <stdio.h>

#include "libcompat.h"

#define INITIAL_SIZE 16
#define DELIMITER '\n'

ssize_t getline(char **lineptr, size_t *n, FILE *stream) {
  ssize_t written = 0;
  int character;

  if (*lineptr == NULL || *n < INITIAL_SIZE) {
    free(*lineptr);
    *lineptr = (char *)malloc(INITIAL_SIZE);
    *n = INITIAL_SIZE;
  }

  while ((character = fgetc(stream)) != EOF) {
    written += 1;
    if (written >= *n) {
      *n = *n * 2;
      *lineptr = realloc(*lineptr, *n);
    }

    (*lineptr)[written - 1] = character;

    if (character == DELIMITER) {
      break;
    }
  }

  (*lineptr)[written] = '\0';

  return written;
}
