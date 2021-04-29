#include "string_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>


char *get_filename_ext(char *filename) {
  const char *dot = strrchr(filename, '.');
  if (!dot)
    return filename;
  return dot + 1;
}

bool starts_with_dashdash(char *str) { return !(memcmp(str, "--", 2)); }
