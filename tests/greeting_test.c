#include "munit.h"
#include "hello.h"
#include "test_utils.h"

static MunitResult test_hello(const MunitParameter params[], void *user_data_or_fixture) {
    (void) params;
    (void) user_data_or_fixture;

    char *actual = get_hello();

    munit_assert_string_equal(actual, "Hello");

    return MUNIT_OK;
}

static MunitTest test_suite_tests[] = {
    {
        "/tests/hello",
        test_hello,
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/tests/insert_entries",
        test_insertentries,
        test_insertentries_setup,
        test_insertentries_teardown,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/tests/insert_entries_over_capacity",
        test_entries_over_capacity,
        test_insertentries_setup,
        test_insertentries_teardown,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        "/tests/sort_entries",
        test_entries_sort,
        test_insertentries_setup,
        test_insertentries_teardown,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite test_suite = {
    "",
    test_suite_tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  /* Finally, we'll actually run our test suite!  That second argument
   * is the user_data parameter which will be passed either to the
   * test or (if provided) the fixture setup function. */
  return munit_suite_main(&test_suite, (void*) "µnit", argc, argv);
}
