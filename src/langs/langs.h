#pragma once
#include "sds/sds.h"
#include <stdbool.h>


typedef enum { unknown_lang, lua_lang, yasl_lang } Lang;

bool load_script_lang(Lang lang, sds script_path, sds file_path);
bool load_script(sds script_path, sds file_path);
Lang get_lang(sds script_path);
