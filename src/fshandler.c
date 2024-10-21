#include <sys/types.h>
#include <sys/stat.h>

#include "fshandler.h"

int is_dir(char *dir_name) {
    struct stat statbuf;

    if (stat(dir_name, &statbuf) != 0) {
        return 1;
    }

    return S_ISDIR(statbuf.st_mode);
}

int is_file(char *file_name) {
    struct stat statbuf;

    if (stat(file_name, &statbuf) != 0) {
        return 1;
    }

    return S_ISREG(statbuf.st_mode);
}

int traverse_directory_r(char *dir_name) {
    if (!is_dir(dir_name)) {
        return 1;
    }

    return 0;
}
