#include "string_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

const char *get_filename_ext(const char *filename) {
  const char *dot = strrchr(filename, '.');
  if (!dot)
    return filename;
  return dot + 1;
}

bool starts_with_dashdash(const char *str) { return !(memcmp(str, "--", 2)); }
