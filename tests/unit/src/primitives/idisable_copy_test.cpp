#include <gtest/gtest.h>

#include <cpp_utils/primitives/idisable_copy.hpp>
#include <test_utils/lifetime.hpp>
#include <test_utils/statics.hpp>

namespace
{
namespace primitives = burda::cpp_utils::primitives;
namespace test_utils = burda::test_utils;

struct child_of_copy : private primitives::idisable_copy
{
};

TEST(idisable_copy, static_assertions)
{
    test_utils::statics::assert_default_constructibility<primitives::idisable_copy, true>();
    test_utils::statics::assert_copy_constructibility<primitives::idisable_copy, false>();
    test_utils::statics::assert_move_constructibility<primitives::idisable_copy, true>();

    test_utils::statics::assert_default_constructibility<child_of_copy, true>();
    test_utils::statics::assert_copy_constructibility<child_of_copy, false>();
    test_utils::statics::assert_move_constructibility<child_of_copy, true>();
}

TEST(idisable_copy, construction_destruction)
{
    test_utils::lifetime::assert_construction_and_destruction<child_of_copy>();
}
}
