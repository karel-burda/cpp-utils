#pragma once

/// Origin: https://github.com/karel-burda/cpp-utils
/// Version : 0.9.0

namespace burda
{
namespace cpp_utils
{
/// Helper class that enables default construction and disables move operations
struct idisable_move
{
    idisable_move() = default;

    idisable_move & operator=(const idisable_move &) = delete;
    idisable_move & operator=(idisable_move &&) = delete;
};
}
}
