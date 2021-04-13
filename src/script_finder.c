#include "script_finder.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

sds sub_str(sds str, int start, int end) {
  int l = end - start;
  char *sub = (char *)malloc((l + 1) * sizeof(char));
  strncpy(sub, str + start, end - start);
  return sdsnew(sub);
}

sds get_filename_ext(sds filename) {
  const char *dot = strrchr(filename, '.');
  if (!dot)
    return filename;
  return sdsnew(dot + 1);
}

sds find_script(sds filename, sds scripts_dir) {
  sds file_extension = get_filename_ext(filename);
  int len = sdslen(file_extension);
  // printf("File ext: %s [%i]\n", file_extension, len);
  DIR *dir = opendir(scripts_dir);
  struct dirent *entry;
  if (dir == NULL) {
    // printf("Unable to read scripts directory: %s", scripts_dir);
    return sdsempty();
  } else {
    while ((entry = readdir(dir))) {
      int cmp = memcmp(file_extension, entry->d_name, sdslen(file_extension));
      if (memcmp(file_extension, entry->d_name, sdslen(file_extension)) == 0) {
        // printf("match: %s, cmp = %i", entry->d_name, cmp);
        return sdsnew(entry->d_name);
      }
      // printf("File name: %s\n", entry->d_name);
    }
  }
  printf("done");
  return sdsempty();
}

// sds get_filename_without_ext(sds filename) {
//   //   char *end = filename + strlen(filename);

//   //   while (end > filename && *end != '.' && *end != '\\' && *end != '/') {
//   //     --end;
//   //   }
//   //   if ((end > filename && *end == '.') &&
//   //       (*(end - 1) != '\\' && *(end - 1) != '/')) {
//   //     *end = '\0';
//   //   }
// }
