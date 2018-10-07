#include <gtest/gtest.h>

#include <cpp_utils/primitives/idisable_move.hpp>
#include <test_utils/test_utils.hpp>
#include <test_utils/static_class_assertions.hpp>

// TODO: move this 2 tests into the template

namespace
{
namespace primitives = burda::cpp_utils::primitives;
namespace test_utils = burda::test_utils;

struct child_of_move : private primitives::idisable_move
{
};

TEST(idisable_copy, static_assertions)
{
    test_utils::assert_default_constructibility<primitives::idisable_move, true>();
    test_utils::assert_copy_constructibility<primitives::idisable_move, false>();
    test_utils::assert_move_constructibility<primitives::idisable_move, true>();

    test_utils::assert_default_constructibility<child_of_move, true>();
    test_utils::assert_copy_constructibility<child_of_move, false>();
    test_utils::assert_move_constructibility<child_of_move, true>();
}

TEST(idisable_copy, construction_destruction)
{
    test_utils::assert_construction_and_destruction<child_of_move>();
}
}