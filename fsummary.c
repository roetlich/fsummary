#include "langs/langs.h"
#include "script_finder.h"

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

void print_help() {
  puts("Usage: fsummary [OPTION...] FILE");
  puts("Print information about a file, extendable with scripts");
  puts("");
}

bool starts_with_dashdash(sds str) {
  return (sdslen(str) >= 2) && (memcmp(str, "--", 2) == 0);
}

int main(int argc, char *argv[]) {
  sds file_name = sdsempty();
  sds script_dir = sdsempty();

  for (int i = 1; i < argc; i++) {
    sds arg = sdsnew(argv[i]);
    if (sdscmp(arg, sdsnew("-h")) == 0 || sdscmp(arg, sdsnew("--help")) == 0) {
      print_help();
      return EXIT_SUCCESS;
    } else if (sdscmp(arg, sdsnew("--script-dir")) == 0) {
      if (i == argc) {
        fprintf(stderr, "Error: Missing script directory\n");
        return EXIT_FAILURE;
      }
      if (sdslen(script_dir) != 0) {
        fprintf(stderr, "Error: Setting script directory twice\n");
        return EXIT_FAILURE;
      }
      script_dir = sdsnew(argv[i]);
      i++;
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

  sds file_path = sdsnew(argv[1]);
  sds script = find_script(file_path, script_dir);
  if (sdslen(script) == 0) {
    puts("No matching script found");
    return EXIT_FAILURE;
  } else {
    puts(script);

    bool status = load_script(script, file_path);
    if (status) {
      return EXIT_SUCCESS;
    } else {
      return EXIT_FAILURE;
    }
  }
}
