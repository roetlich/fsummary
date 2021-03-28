#include "langs.h"
#include "lua-binding.h"
#include "yasl-binding.h"
#include <stdio.h>
#include <string.h>

bool load_script_lang(Lang lang, sds script_path, sds file_path) {
  switch (lang) {
  case lua_lang:
    return load_lua(script_path, file_path);
  case yasl_lang:
    return load_yasl(script_path, file_path);
  default:
    return false;
  }
}
bool load_script(sds script_path, sds file_path) {
  Lang lang = get_lang(script_path);
  if (lang == unknown_lang)
    return false;
  else
    return load_script_lang(lang, script_path, file_path);
}

sds get_filename_ext_2(sds filename) {
  const char *dot = strrchr(filename, '.');
  if (!dot)
    return filename;
  return sdsnew(dot + 1);
}

Lang get_lang(sds script_path) {
  sds ext = get_filename_ext_2(script_path);
  if (sdscmp(ext, sdsnew("lua")) == 0) {
    return lua_lang;
  }
  if (sdscmp(ext, sdsnew("yasl")) == 0) {
    return yasl_lang;
  }
  return unknown_lang;
}
