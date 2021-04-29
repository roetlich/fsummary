#include "yasl-binding.h"
#include "dependencies/yasl/yasl.h"
#include <string.h>

bool load_yasl(char* script_path, char* file_path) {
  // make a new YASL state, loaded the script from script_path
  struct YASL_State *S = YASL_newstate(script_path);

  // Enable use of the io lib
  YASL_decllib_io(S);

  // declare a variable `answer`
  YASL_declglobal(S, "file_path");

  // push the file path onto the stack
  YASL_pushlstr(S, file_path, strlen(file_path));

  // init `answer` with the top of the stack (in this case, the `42` we just
  // pushed)
  YASL_setglobal(S, "file_path");

  // execute `example.yasl`, now that we're done setting everything up
  YASL_execute(S);

  // clean up
  YASL_delstate(S);

  return true;
}
