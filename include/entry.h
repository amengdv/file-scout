#pragma once

#include <stddef.h>

typedef struct Entries {
    size_t len;
    size_t capacity;
    char *root_entry;
    char **collections;
} entries_t;

entries_t *new_entries(size_t len);
void insert_entry(entries_t *entries, char *data);
void free_entries(entries_t *entries);

void sort_entry(entries_t *entries);
void pretty_entry_display(entries_t *entries); 
void slice_dir_from_entry(char *entry, char *curr_dir, char *res);
