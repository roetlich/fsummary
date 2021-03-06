#include "langs.h"
#include "lua-binding.h"
#include "string_helpers.h"
#include "yasl-binding.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool load_script_lang(Lang lang, const char *script_path,
                      const char *file_path) {
  switch (lang) {
  case lua_lang:
    return load_lua(script_path, file_path);
  case yasl_lang:
    return load_yasl(script_path, file_path);
  default:
    return false;
  }
}
bool load_script(const char *script_path, const char *file_path) {
  Lang lang = get_lang(script_path);
  if (lang == unknown_lang)
    return false;
  else
    return load_script_lang(lang, script_path, file_path);
}

Lang get_lang(const char *script_path) {
  const char *ext = get_filename_ext(script_path);
  if (MATCH(ext, "lua")) {
    return lua_lang;
  }
  if (MATCH(ext, "yasl")) {
    return yasl_lang;
  }
  return unknown_lang;
}
