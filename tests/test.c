#include "cester.h"
#include "script_finder.h"
#include "string_helpers.h"

CESTER_TEST(get_filename_ext, inst,
            cester_assert_str_equal(get_filename_ext("pic.jpg"), "jpg");
            cester_assert_str_equal(get_filename_ext("video.cool.mp4"), "mp4");
            cester_assert_str_equal(get_filename_ext("Makefile"), "Makefile");)


CESTER_TEST(check_match_macro, inst,
            cester_assert_true(MATCH("test", "test"));
            cester_assert_true(MATCH("", ""));
            cester_assert_true(MATCH("123456789", "123456789"));
            cester_assert_false(MATCH("test", "nope"));
            cester_assert_false(MATCH("test", "nope"));
            cester_assert_false(MATCH("test", "nope"));)

CESTER_TEST(find_scripts_correctly, inst,
            cester_assert_str_equal(find_script(("Makefile"), ("scripts")),
                                    "scripts/Makefile.lua");)
