#include "entry.h"
#include "munit.h"
#include "test_utils.h"

MunitResult test_insertentries(const MunitParameter *params, void *entries) {
    (void) params;
    entries_t *setup_entries = (entries_t*)entries;
    insert_entry(setup_entries, "foo");
    insert_entry(setup_entries, "bar");
    insert_entry(setup_entries, "baz");

    munit_assert_size(setup_entries->len, ==, 3);
    munit_assert_size(setup_entries->capacity, ==, 5);
    munit_assert_string_equal(setup_entries->collections[0], "foo");
    munit_assert_string_equal(setup_entries->collections[1], "bar");
    munit_assert_string_equal(setup_entries->collections[2], "baz");
    return MUNIT_OK;
}

MunitResult test_entries_over_capacity(const MunitParameter params[], void *entries) {
    (void) params;
    entries_t *setup_entries = (entries_t*)entries;
    insert_entry(setup_entries, "foo");
    insert_entry(setup_entries, "bar");
    insert_entry(setup_entries, "baz");
    insert_entry(setup_entries, "test");
    insert_entry(setup_entries, "boo");
    insert_entry(setup_entries, "baa");
    munit_assert_size(setup_entries->len, ==, 6);
    munit_assert_size(setup_entries->capacity, ==, 10);
    munit_assert_string_equal(setup_entries->collections[0], "foo");
    munit_assert_string_equal(setup_entries->collections[1], "bar");
    munit_assert_string_equal(setup_entries->collections[2], "baz");
    munit_assert_string_equal(setup_entries->collections[4], "boo");
    munit_assert_string_equal(setup_entries->collections[5], "baa");
    return MUNIT_OK;
}

MunitResult test_entries_sort(const MunitParameter params[], void *entries) {
    (void) params;
    entries_t *setup_entries = (entries_t*)entries;
    insert_entry(setup_entries, "src/hello.c");
    insert_entry(setup_entries, "src/fshandler.c");
    insert_entry(setup_entries, "src/entry.c");
    insert_entry(setup_entries, "src/main.c");
    munit_assert_size(setup_entries->len, ==, 4);
    munit_assert_size(setup_entries->capacity, ==, 5);
    sort_entry(setup_entries);
    munit_assert_string_equal(setup_entries->collections[0], "src/entry.c");
    munit_assert_string_equal(setup_entries->collections[1], "src/fshandler.c");
    munit_assert_string_equal(setup_entries->collections[2], "src/hello.c");
    munit_assert_string_equal(setup_entries->collections[3], "src/main.c");
    return MUNIT_OK;
}

void *test_insertentries_setup(const MunitParameter *params, void *data) {
    (void) data;
    (void) params;
    return new_entries(5);
}

void test_insertentries_teardown(void *entries) {
    free_entries(entries);
}
