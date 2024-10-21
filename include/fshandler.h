#pragma once

int is_dir(char *dir_name);
int is_file(char *is_file);

void traverse_directory_r(char *dir_name);

void remove_trailing_slash(char *str);
