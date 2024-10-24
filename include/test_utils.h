#pragma once

#include "munit.h"

MunitResult test_insertentries(const MunitParameter params[], void *entries);
MunitResult test_entries_over_capacity(const MunitParameter params[], void *entries);
MunitResult test_entries_sort(const MunitParameter params[], void *entries);
MunitResult test_slice_dir_from_entry(const MunitParameter params[], void *entries);
void *test_insertentries_setup(const MunitParameter params[], void *data);
void test_insertentries_teardown(void *entries);

