#include "script_finder.h"
#include "string_helpers.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

const char *find_script(const char *filename, const char *scripts_dir) {
  const char *file_extension = get_filename_ext(filename);
  DIR *dir = opendir(scripts_dir);
  struct dirent *entry;
  if (dir == NULL) {
    closedir(dir);
    return "";
  } else {
    while ((entry = readdir(dir))) {
      if (!memcmp(file_extension, entry->d_name, strlen(file_extension))) {
        char *dest = malloc((257) * sizeof(char));
        sprintf(dest, "%s/%s", scripts_dir, entry->d_name);
        closedir(dir);
        return dest;
      }
    }
  }
  closedir(dir);
  return 0;
}
