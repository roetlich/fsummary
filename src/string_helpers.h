#pragma once
#include "sds/sds.h"
#include <stdbool.h>

bool sdsmatch(sds str1, const char *str2, size_t l);
#define MATCH(str1, str2) sdsmatch(str1, str2, sizeof(str2) - 1)

sds get_filename_ext(sds filename);

bool starts_with_dashdash(sds str);
