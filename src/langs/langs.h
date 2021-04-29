#pragma once

#include <stdbool.h>

typedef enum { unknown_lang, lua_lang, yasl_lang } Lang;

bool load_script_lang(Lang lang, char *script_path, char *file_path);
bool load_script(char *script_path, char *file_path);
Lang get_lang(char *script_path);
