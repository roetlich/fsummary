#include "cester.h"
#include "script_finder.h"

CESTER_TEST(get_filename_ext, inst,
            cester_assert_str_equal(get_filename_ext("pic.jpg"), "jpg");
            cester_assert_str_equal(get_filename_ext("video.cool.mp4"), "mp4");
            cester_assert_str_equal(get_filename_ext("Makefile"), "Makefile");)

CESTER_TEST(sub_str, inst,
            cester_assert_str_equal(sub_str("abcde", 1, 3), "bc");
            cester_assert_str_equal(sub_str("abcde", 0, 5), "abcde");
            cester_assert_str_equal(sub_str("abcde", 0, 0), "");)
