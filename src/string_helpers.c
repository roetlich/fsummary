#include "string_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

bool sdsmatch(sds str1, const char *str2, size_t l) {
  return (sdslen(str1) == l) && (memcmp(str1, str2, l + 1) == 0);
}

sds get_filename_ext(sds filename) {
  const char *dot = strrchr(filename, '.');
  if (!dot)
    return filename;
  return sdsnew(dot + 1);
}

bool starts_with_dashdash(sds str) {
  return (sdslen(str) >= 2) && (memcmp(str, "--", 2) == 0);
}
