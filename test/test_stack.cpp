#include "Stack.h"
#include "gtest.h"

TEST(Stack, can_create_Stack)
{
    ASSERT_NO_THROW(Stack<int> s);
}

TEST(Stack, can_check_for_empty)
{
    Stack<int> s;
    EXPECT_EQ(1, s.isEmpty());
}

TEST(Stack, can_check_for_full1)
{
    Stack<int> s;
    EXPECT_NE(1, s.isFull());
}

TEST(Stack, can_check_for_full2)
{
    Stack<int> s;
    s.push(1);
    EXPECT_EQ(1, s.isFull());
}

TEST(Stack, can_return_correct_size)
{
    Stack<int> s;
    s.push(1); s.push(1); s.push(1); s.push(1); s.push(1);
    EXPECT_EQ(5, s.size_());
}

TEST(Stack, can_return_correct_capacity)
{
    Stack<int> s;
    s.push(1); s.push(1); s.push(1); s.push(1); s.push(1);
    EXPECT_EQ(2 * 2 + 2, s.capacity_());
}

TEST(Stack, can_push_element)
{
    Stack<int> s;
    s.push(1);
    EXPECT_EQ(1, s.top());
}

TEST(Stack, can_pop_element)
{
    Stack<int> s;
    s.push(6);
    s.push(21);
    s.pop();
    EXPECT_EQ(1, s.size_());
}

TEST(Stack, can_resize_stack)
{
    Stack<int> s;
    s.resize(8);
    EXPECT_EQ(8*2+2, s.size_());
}

TEST(Stack, can_get_top_element)
{
    Stack<int> s;
    s.push(6);
    s.push(7);
    EXPECT_EQ(7, s.top());
}

TEST(Stack, can_resize_stack_while_pushing_elemets)
{
    Stack<int> s;
    s.push(6);
    s.push(7);
    EXPECT_EQ(6, s.capacity_());
}