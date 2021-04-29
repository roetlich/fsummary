#pragma once
#include <stdbool.h>
#include <stdio.h>

#define MATCH(str1, str2) !strncmp(str1, str2, sizeof(str2) - 1)

char* get_filename_ext(char* filename);

bool starts_with_dashdash(char* str);
