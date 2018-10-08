#include <thread>

#include <gtest/gtest.h>

#include <cpp_utils/time/measure_duration.hpp>

namespace
{
namespace time = burda::cpp_utils::time;

TEST(measure_duration, measure_duration)
{
    using namespace std::chrono_literals;

    EXPECT_THROW(time::measure_duration(nullptr), std::runtime_error);

    {
        const auto duration = time::measure_duration([]() {});
        EXPECT_TRUE(duration <= 1s);
    }

    {
        const auto duration = time::measure_duration([]() { std::this_thread::sleep_for(4s); });
        EXPECT_TRUE(duration >= 4s && duration <= 8s);
    }
}
}
