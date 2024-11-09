#include "Queue2Stacks.h"
#include "gtest.h"

TEST(Queue2Stacks, can_create_Queue2Stacks)
{
    ASSERT_NO_THROW(Queue2Stacks<int> qs);
}

TEST(Queue2Stacks, can_check_for_empty)
{
    Queue2Stacks<int> qs;
    EXPECT_EQ(1, qs.isEmpty());
}

TEST(Queue2Stacks, can_check_for_full)
{
    Queue2Stacks<int> qs;
    EXPECT_NE(1, qs.isFull());
}

TEST(Queue2Stacks, can_return_correct_size)
{
    Queue2Stacks<int> qs;
    qs.push(1); qs.push(1); qs.push(1); qs.push(1); qs.push(1);
    EXPECT_EQ(5, qs.size_());
}

TEST(Queue2Stacks, can_return_correct_capacity)
{
    Queue2Stacks<int> qs;
    qs.push(1); qs.push(1); qs.push(1); qs.push(1); qs.push(1);
    EXPECT_EQ(2 * 3 + 2, qs.capacity_());
}

TEST(Queue2Stacks, can_push_element)
{
    Queue2Stacks<int> qs;
    qs.push(1);
    EXPECT_EQ(1, qs.front());
}

TEST(Queue2Stacks, can_pop_element)
{
    Queue2Stacks<int> qs;
    qs.push(3);
    qs.push(3);
    qs.pop();
    EXPECT_EQ(1, qs.size_());
}