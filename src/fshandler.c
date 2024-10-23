#include <linux/limits.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <limits.h>

#include "fshandler.h"
#include "entry.h"

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

void traverse_directory_r(char *dir_name, entries_t *entries, int hidden_visible) {
    if (!is_dir(dir_name)) {
        return;
    }

    printf("Current Dir: %s\n", dir_name);

    DIR *curr_dir = opendir(dir_name);
    if (curr_dir == NULL) {
        perror("opendir failed");
        return;
    }

    struct dirent *dir_read;

    while ((dir_read = readdir(curr_dir)) != NULL) {
        if (strcmp(dir_read->d_name, ".") == 0 || strcmp(dir_read->d_name, "..") == 0) {
            continue;
        }

        if (dir_read->d_name[0] == '.' && hidden_visible == 0) {
            continue;
        }

        char name[PATH_MAX];
        snprintf(name, sizeof(name), "%s/%s", dir_name, dir_read->d_name);

        insert_entry(entries, name);

        if (is_dir(name)) {
            traverse_directory_r(name, entries, hidden_visible);
        }     
    }
    closedir(curr_dir);
}

void remove_trailing_slash(char *str) {
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '/') {
        str[len - 1] = '\0';
    }
}
