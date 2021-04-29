#pragma once
#include <stdbool.h>
#include <stdio.h>

#define MATCH(str1, str2) !strncmp(str1, str2, sizeof(str2) - 1)

const char *get_filename_ext(const char *filename);

bool starts_with_dashdash(const char *str);
