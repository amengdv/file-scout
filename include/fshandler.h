#pragma once

#include "entry.h"

int is_dir(char *dir_name);
int is_file(char *is_file);

void traverse_directory_r(char *dir_name, entries_t *entries, int hidden_visible);

void remove_trailing_slash(char *str);
