#include "script_finder.h"
#include "string_helpers.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

sds find_script(sds filename, sds scripts_dir) {
  sds file_extension = get_filename_ext(filename);
  printf("filename: %s\n", filename);
  printf("scripts dir: %s\n", scripts_dir);
  DIR *dir = opendir(scripts_dir);
  struct dirent *entry;
  if (dir == NULL) {
    return sdsempty();
  } else {
    while ((entry = readdir(dir))) {
      if (memcmp(file_extension, entry->d_name, sdslen(file_extension)) == 0) {
        return sdscat(sdscat(scripts_dir, "/"), entry->d_name);
      }
    }
  }
  return sdsempty();
}
