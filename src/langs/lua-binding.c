#include "lua-binding.h"
#include "dependencies/lua/src/lua.h"
#include "dependencies/lua/src/lualib.h"
#include "dependencies/lua/src/lauxlib.h"

bool load_lua(sds script_path, sds file_path) {
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    luaopen_math(L);
    luaopen_string(L);
    printf("test");
    lua_pushlstring(L, file_path, sdslen(file_path));
    lua_setglobal(L, "file_path");

    int h = luaL_dofile(L, script_path);
    if (h!=0) {
        fprintf(stderr,"\nluaL_dofile failed(%i): %s\n", h, lua_tostring(L,-1));
    }

    lua_close(L);
    return true;
}
