// ------------------------- Tests File - test.cpp -------------------------- //
// This file is for writing your own user tests. Be sure to include your *.h
// files to be able to access the functions that you wrote for unit testing.
// An example has been provided, but more documentation is available here:
// https://github.com/google/googletest/blob/main/docs/primer.md
// -------------------------------------------------------------------------- //

// Include all of your *.h files you want to unit test:

#include <gtest/gtest.h>
#include "../src/unordered_list.h"

namespace
{

    TEST(UnorderedArrayList, IsEmpty)
    {
        UnorderedArrayList x;
        EXPECT_TRUE(x.is_empty());
    }

    TEST(UnorderedArrayList, IsFull)
    {
        UnorderedArrayList x;
        EXPECT_FALSE(x.is_full());
    }

} // anonymous namespace

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}