#include "fshandler.h"
#include <stdio.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("FileScout require at least 1 argument\n");
        return 1;
    }

    char *dir_name = argv[1];

    if (!is_dir(dir_name)) {
        printf("%s is not a directory\n", dir_name);
        return 1;
    }
    return 0;
}
