#pragma once

#include <stdbool.h>

typedef enum { unknown_lang, lua_lang, yasl_lang } Lang;

bool load_script_lang(Lang lang, const char *script_path,
                      const char *file_path);
bool load_script(const char *script_path, const char *file_path);
Lang get_lang(const char *script_path);
