#include "Queue.h"
#include "gtest.h"

TEST(Queue, can_create_Queue)
{
    ASSERT_NO_THROW(Queue<int> q);
}

TEST(Queue, can_check_for_empty)
{
    Queue<int> q;
    EXPECT_EQ(1, q.isEmpty());
}

TEST(Queue, can_check_for_full)
{
    Queue<int> q;
    EXPECT_NE(1, q.isFull());
}

TEST(Queue, can_return_correct_size)
{
    Queue<int> q;
    q.push(1); q.push(1); q.push(1); q.push(1); q.push(1);
    EXPECT_EQ(5, q.size_());
}

TEST(Queue, can_return_correct_capacity)
{
    Queue<int> q;
    q.push(1); q.push(1); q.push(1); q.push(1); q.push(1);
    EXPECT_EQ(2 * 2 + 2, q.capacity_());
}

TEST(Queue, can_push_element)
{
    Queue<int> s;
    s.push(1);
    EXPECT_EQ(1, s.get_back());
}

TEST(Queue, can_pop_element)
{
    Queue<int> s;
    s.push(2);
    s.push(3);
    s.pop();
    EXPECT_EQ(1, s.size_());
}

TEST(Queue, can_get_front_element)
{
    Queue<int> s;
    s.push(2);
    s.push(3);
    EXPECT_EQ(2, s.get_front());
}

TEST(Queue, can_get_back_element)
{
    Queue<int> s;
    s.push(2);
    s.push(3);
    EXPECT_EQ(3, s.get_back());
}

TEST(Queue, can_move_back_element_before_front)
{
    Queue<int> s;
    s.push(6);
    s.push(9);
    s.pop();
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);
    EXPECT_EQ(0, s.get_back_ind());
}