#include <gtest/gtest.h>

#include <cpp_utils/primitives/idisable_copy.hpp>
#include <test_utils/lifetime_assertions.hpp>
#include <test_utils/static_class_assertions.hpp>

namespace
{
namespace primitives = burda::cpp_utils::primitives;
namespace test_utils = burda::test_utils;

struct child_of_copy : private primitives::idisable_copy
{
};

TEST(idisable_copy, static_assertions)
{
    test_utils::assert_default_constructibility<primitives::idisable_copy, true>();
    test_utils::assert_copy_constructibility<primitives::idisable_copy, false>();
    test_utils::assert_move_constructibility<primitives::idisable_copy, true>();

    test_utils::assert_default_constructibility<child_of_copy, true>();
    test_utils::assert_copy_constructibility<child_of_copy, false>();
    test_utils::assert_move_constructibility<child_of_copy, true>();
}

TEST(idisable_copy, construction_destruction)
{
    test_utils::assert_construction_and_destruction<child_of_copy>();
}
}
