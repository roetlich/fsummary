#include "script_finder.h"
#include "string_helpers.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

char *find_script(char *filename, char *scripts_dir) {
  char *file_extension = get_filename_ext(filename);
  DIR *dir = opendir(scripts_dir);
  struct dirent *entry;
  if (dir == NULL) {
    return "";
  } else {
    while ((entry = readdir(dir))) {
      if (!memcmp(file_extension, entry->d_name, strlen(file_extension))) {
        char *dest = malloc((120) * sizeof(char));
        sprintf(dest, "%s/%s", scripts_dir, entry->d_name);
        return dest;
      }
    }
  }
  return 0;
}
