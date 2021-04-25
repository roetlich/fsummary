#include "script_finder.h"
#include "string_helpers.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

sds find_script(char* filename, char* scripts_dir) {
  char* file_extension = get_filename_ext(filename);
  printf("filename: %s\n", filename);
  printf("scripts dir: %s\n", scripts_dir);
  DIR *dir = opendir(scripts_dir);
  if (dir != NULL) {
    struct dirent *entry;
    while ((entry = readdir(dir))) {
      if (memcmp(file_extension, entry->d_name, sdslen(file_extension)) == 0) {
        closedir(dir);
        return sdscat(s(scripts_dir, "/"), entry->d_name);
      }
    }
  }

  closedir(dir);
  return sdsempty();
}
