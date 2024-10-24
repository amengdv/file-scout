#include "entry.h"
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

entries_t *new_entries(size_t capacity) {
    entries_t *entries = malloc(sizeof(entries_t));
    if (entries == NULL) {
        return NULL;
    }

    char **collections = calloc(capacity, sizeof(char *));
    if (collections == NULL) {
        free(entries);
        return NULL;
    }
    entries->collections = collections;
    entries->len = 0;
    entries->capacity = capacity;

    return entries;
}

void insert_entry(entries_t *entries, char *data) {
    if (entries == NULL) {
        return;
    }

    if (entries->len >= entries->capacity) {
        char **reall_coll = realloc(entries->collections, 2 * entries->capacity * sizeof(char*));
        if (reall_coll == NULL) {
            return;
        }

        entries->collections = reall_coll;
        entries->capacity = entries->capacity * 2;
    }

    int data_len = strlen(data);
    char *alloc_data = malloc(data_len * sizeof(char) + 1);
    if (alloc_data == NULL) {
        return;
    }
    strcpy(alloc_data, data);
    entries->collections[entries->len] = alloc_data;
    entries->len++;
}

void free_entries(entries_t *entries) {
    for (size_t i = 0; i < entries->len; i++) {
        if (entries->collections[i] != NULL)
            free(entries->collections[i]);
    }

    free(entries->collections);
    free(entries);
}

// Using simple sorting for now
// For testing purposes
void sort_entry(entries_t *entries) {
    for (size_t i = 0; i < entries->len; i++) {
        for (size_t j = 0; j < entries->len - i - 1; j++) {
            if (strcasecmp(entries->collections[j], entries->collections[j + 1]) > 0) {
                char *dup_j = strdup(entries->collections[j]);
                if (dup_j == NULL) {
                    return;
                }
                free(entries->collections[j]);
                entries->collections[j] = entries->collections[j + 1];
                entries->collections[j + 1] = dup_j;
            }
        }
    }
}

/*
 *
    ├: U+251C

    │: U+2502
    ─: U+2500
    └: U+2514
 *
*/
void pretty_entry_display(entries_t *entries) {
    (void) entries;
}

void slice_dir_from_entry(char *entry, char *curr_dir, char *res) {
    int dir_len = strlen(curr_dir);
    
    // Check if entry starts with curr_dir
    if (strncmp(entry, curr_dir, dir_len) == 0 && entry[dir_len] == '/') {
        // Copy the part after curr_dir and the following '/'
        strcpy(res, entry + dir_len + 1);
    } else {
        // Handle cases where curr_dir is not a prefix
        strcpy(res, entry);
    }
}

