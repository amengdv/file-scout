#include "entry.h"
#include "fshandler.h"
#include <stdio.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("FileScout require at least 1 argument\n");
        return 1;
    }

    char *dir_name = argv[1];
    remove_trailing_slash(dir_name);

    if (!is_dir(dir_name)) {
        printf("%s is not a directory\n", dir_name);
        return 1;
    }

    entries_t *entries = new_entries(5);
    entries->root_entry = dir_name;
    traverse_directory_r(dir_name, entries, 0);

    sort_entry(entries);
    for (size_t i = 0; i < entries->len; i++) {
        printf("%s\n", entries->collections[i]);
    }

    free_entries(entries);

    return 0;
}
