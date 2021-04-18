#include "cester.h"
#include "script_finder.h"
#include "string_helpers.h"

CESTER_TEST(get_filename_ext, inst,
            cester_assert_str_equal(get_filename_ext("pic.jpg"), "jpg");
            cester_assert_str_equal(get_filename_ext("video.cool.mp4"), "mp4");
            cester_assert_str_equal(get_filename_ext("Makefile"), "Makefile");)

CESTER_TEST(check_sdsmatch, inst,
            cester_assert_true(sdsmatch(sdsnew("test"), "test", 4));
            cester_assert_true(sdsmatch(sdsnew(""), "", 0));
            cester_assert_true(sdsmatch(sdsnew("123456789"), "123456789", 9));
            cester_assert_false(sdsmatch(sdsnew("test"), "nope", 4));
            cester_assert_false(sdsmatch(sdsnew("test"), "nope", 200));
            cester_assert_false(sdsmatch(sdsnew("test"), "nope", 0));)

CESTER_TEST(check_match_macro, inst,
            cester_assert_true(MATCH(sdsnew("test"), "test"));
            cester_assert_true(MATCH(sdsnew(""), ""));
            cester_assert_true(MATCH(sdsnew("123456789"), "123456789"));
            cester_assert_false(MATCH(sdsnew("test"), "nope"));
            cester_assert_false(MATCH(sdsnew("test"), "nope"));
            cester_assert_false(MATCH(sdsnew("test"), "nope"));)

CESTER_TEST(find_scripts_correctly, inst,
            cester_assert_str_equal(
                find_script(sdsnew("Makefile"), sdsnew("scripts")), "scripts/Makefile.lua");)
