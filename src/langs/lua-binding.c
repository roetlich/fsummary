#include "lua-binding.h"
#include "lua/src/lauxlib.h"
#include "lua/src/lua.h"
#include "lua/src/lualib.h"
#include <stdio.h>
#include <string.h>

bool load_lua(const char *script_path, const char *file_path) {
  lua_State *L = luaL_newstate();
  luaL_openlibs(L);
  luaopen_math(L);
  luaopen_string(L);
  lua_pushlstring(L, file_path, strlen(file_path));
  lua_setglobal(L, "file_path");
  printf("Doing the lua! \n");
  int h = luaL_dofile(L, script_path);
  if (h != 0) {
    fprintf(stderr, "\nluaL_dofile failed(%i): %s\n", h, lua_tostring(L, -1));
  }

  lua_close(L);
  return true;
}
