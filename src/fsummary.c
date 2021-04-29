#include "langs/langs.h"
#include "script_finder.h"
#include "string_helpers.h"

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

void print_help(void) {
  puts("Usage: fsummary [OPTION...] FILE");
  puts("Print information about a file, extendable with scripts");
  puts("");
}

#ifndef TESTS
int main(int argc, char *argv[]) {
  sds file_name = sdsempty();
  sds script_dir = sdsempty();
  sds arg = 0;

  for (int i = 1; i < argc; i++) {
    sdsfree(arg);
    arg = sdsnew(argv[i]);
    if (MATCH(arg, "-h") || MATCH(arg, "--help")) {
      print_help();
      return EXIT_SUCCESS;
    } else if (MATCH(arg, "--script-dir")) {
      if (i == argc) {
        fprintf(stderr, "Error: Missing script directory\n");
        return EXIT_FAILURE;
      }
      if (sdslen(script_dir) != 0) {
        fprintf(stderr, "Error: Setting script directory twice\n");
        return EXIT_FAILURE;
      }
      script_dir = sdsnew(argv[++i]);
    } else if (starts_with_dashdash(arg)) {
      fprintf(stderr, "Unkonwn option: \t%s\n", arg);
      return EXIT_FAILURE;
    } else if (sdslen(file_name) != 0) {
      fprintf(stderr, "Error: Can only summarize one file at a time\n");
      return EXIT_FAILURE;
    } else {
      file_name = arg;
    }
  }

  if (sdslen(file_name) == 0) {
    fprintf(stderr, "Error: You need to specify a file\n");
    return EXIT_FAILURE;
  }

  if (sdslen(script_dir) == 0) {
    const char *script_env = getenv("FSUMMARY_SCRIPTS");
    if (script_env != 0) {
      script_dir = sdsnew(script_env);
    } else {
      fprintf(stderr, "Error: You need to specify a directory with scripts. "
                      "You can to that with the --script-dir option or with "
                      "the FSUMMARY_SCRIPTS env variable.\n");
      return EXIT_FAILURE;
    }
  }
  sdsfree(arg);

  char* script = find_script(file_name, script_dir);
  
  if (sdslen(script) == 0) {
    puts("No matching script found");
    return EXIT_FAILURE;
  } else {

    bool status = load_script(script, file_name);
    if (status) {
      return EXIT_SUCCESS;
    } else {
      return EXIT_FAILURE;
    }
  }
}
#endif
