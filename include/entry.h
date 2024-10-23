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
void pretty_entry(entries_t *entries); 
