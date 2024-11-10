#include "Vector.h"
#include "gtest.h"
using namespace std;

TEST(Vector, can_create_Vector_with_positive_length)
{
    ASSERT_NO_THROW(Vector<int> v(5));
}

TEST(Vector, cant_create_Vector_with_negative_positive_length)
{
    ASSERT_ANY_THROW(Vector<int> v(-5));
}

TEST(Vector, can_create_Vector_from_arr)
{
    int* a = new int[5] {1, 2, 3, 4, 5};
    Vector<int> v(a, 5);
    int f = 0;
    if (v.size_() == 5)
        for (size_t i = 0; i < 5; i++)
            if (a[i] != v[i]) f = 1;
    delete[] a;
    EXPECT_EQ(0, f);
}

TEST(Vector, can_create_Vector_copy)
{
    int* a = new int[5] {1, 2, 3, 4, 5};
    Vector<int> v(a, 5);
    delete[] a;
    Vector<int> v1(v);
    EXPECT_EQ(v, v1);
}

TEST(Vector, can_assign_Vector)
{
    int* a = new int[5] {1, 2, 3, 4, 5};
    Vector<int> v(a, 5);
    delete[] a;
    Vector<int> v1;
    v1 = v;
    EXPECT_EQ(v, v1);
}

TEST(Vector, can_assign_Vectors_with_non_equal_size)
{
    int* a = new int[5] {1, 2, 3, 4, 5};
    int* b = new int[7] {1, 2, 3, 4, 5, 6, 7};
    Vector<int> v(a, 5);
    Vector<int> v1(b, 7);
    delete[] a; delete[] b;
    v1 = v;
    EXPECT_EQ(v, v1);
}

TEST(Vector, can_return_correct_size)
{
    int* a = new int[5] {1, 2, 3, 4, 5};
    Vector<int> v(a, 5);
    delete[] a;
    EXPECT_EQ(5, v.size_());
}

TEST(Vector, can_return_correct_capacity)
{
    int* a = new int[5] {1, 2, 3, 4, 5};
    Vector<int> v(a, 5);
    delete[] a;
    EXPECT_EQ(5 * 2 + 2, v.capacity_());
}

TEST(Vector, can_check_for_empty)
{
    Vector<int> v;
    EXPECT_EQ(1, v.isEmpty());
}

TEST(Vector, can_check_for_full1)
{
    int* a = new int[5] {1, 2, 3, 4, 5};
    Vector<int> v(a, 5);
    delete[] a;
    EXPECT_NE(1, v.isFull());
}

TEST(Vector, can_check_for_full2)
{
    int* a = new int[5] {1, 2, 3, 4, 5};
    Vector<int> v(a, 5);
    delete[] a;
    v.push_back(1);  v.push_back(1);  v.push_back(1);  v.push_back(1);  v.push_back(1);  v.push_back(1); v.push_back(1);
    EXPECT_EQ(1, v.isFull());
}

TEST(Vector, can_compare_equal_Vectors_with_equal_size)
{
    int* a = new int[5] {1, 2, 3, 4, 5};
    int* b = new int[5] {1, 2, 3, 4, 5};
    Vector<int> v(a, 5);
    Vector<int> v1(b, 5);
    delete[] a; delete[] b;
    EXPECT_EQ(v, v1);
}

TEST(Vector, can_compare_non_equal_Vectors_with_equal_size)
{
    int* a = new int[5] {1, 2, 3, 4, 5};
    int* b = new int[5] {1, 2, 23, 4, 5};
    Vector<int> v(a, 5);
    Vector<int> v1(b, 5);
    delete[] a; delete[] b;
    EXPECT_NE(v, v1);
}

TEST(Vector, can_compare_non_equal_Vectors_with_non_equal_size)
{
    int* a = new int[5] {1, 2, 3, 4, 5};
    int* b = new int[7] {1, 2, 3, 4, 5, 6, 7};
    Vector<int> v(a, 5);
    Vector<int> v1(b, 7);
    delete[] a; delete[] b;
    EXPECT_NE(v, v1);
}

TEST(Vector, can_get_element_with_positive_index)
{
    int* a = new int[5] {1, 2, 3, 4, 5};
    Vector<int> v(a, 5);
    delete[] a;
    EXPECT_EQ(2, v[1]);
}

TEST(Vector, can_get_back_element)
{
    int* a = new int[5] {1, 2, 3, 4, 5};
    Vector<int> v(a, 5);
    delete[] a;
    EXPECT_EQ(5, v.back());
}

TEST(Vector, can_pop_back_element)
{
    int* a = new int[5] {1, 2, 3, 4, 5};
    Vector<int> v(a, 5);
    delete[] a;
    int* b = new int[4] {1, 2, 3, 4};
    Vector<int> v1(b, 4);
    delete[] b;
    v.pop_back();
    EXPECT_EQ(v, v1);
}

TEST(Vector, cant_pop_back_element_empty_Vector)
{
    Vector<int> v;
    ASSERT_ANY_THROW(v.pop_back());
}

TEST(Vector, can_pop_front_element)
{
    int* a = new int[5] {1, 2, 3, 4, 5};
    Vector<int> v(a, 5);
    delete[] a;
    int* b = new int[4] {2, 3, 4, 5};
    Vector<int> v1(b, 4);
    delete[] b;
    v.pop_front();
    EXPECT_EQ(v, v1);
}

TEST(Vector, can_push_back_element)
{
    int* a = new int[5] {1, 2, 3, 4, 5};
    Vector<int> v(a, 5);
    delete[] a;
    int* b = new int[6] {1, 2, 3, 4, 5, 6};
    Vector<int> v1(b, 6);
    delete[] b;
    v.push_back(6);
    EXPECT_EQ(v, v1);
}

TEST(Vector, can_push_back_element_with_resize)
{
    int* a = new int[5] {1, 2, 3, 4, 5};
    Vector<int> v(a, 5);
    delete[] a;
    int* b = new int[13] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    Vector<int> v1(b, 13);
    delete[] b;
    for (size_t i = 6; i < 14; i++)
        v.push_back(i);
    EXPECT_EQ(v, v1);
}

TEST(Vector, can_push_front_element)
{
    int* a = new int[5] {1, 2, 3, 4, 5};
    Vector<int> v(a, 5);
    delete[] a;
    int* b = new int[6] {6, 1, 2, 3, 4, 5};
    Vector<int> v1(b, 6);
    delete[] b;
    v.push_front(6);
    EXPECT_EQ(v, v1);
}

TEST(Vector, can_push_front_element_with_resize)
{
    int* a = new int[5] {1, 2, 3, 4, 5};
    Vector<int> v(a, 5);
    delete[] a;
    int* b = new int[13] {6, 7, 8, 9, 10, 11, 12, 13, 1, 2, 3, 4, 5};
    Vector<int> v1(b, 13);
    delete[] b;
    v.push_front(13); v.push_front(12); v.push_front(11); v.push_front(10); v.push_front(9); v.push_front(8); v.push_front(7); v.push_front(6);
    EXPECT_EQ(v, v1);
}

TEST(Vector, cant_pop_front_element_empty_Vector)
{
    Vector<int> v;
    ASSERT_ANY_THROW(v.pop_front());
}

TEST(Vector, can_erase_element)
{
    int* a = new int[5] {1, 2, 3, 4, 5};
    Vector<int> v(a, 5);
    delete[] a;
    int* b = new int[4] {1, 2, 4, 5};
    Vector<int> v1(b, 4);
    delete[] b;
    v.erase(2);
    EXPECT_EQ(v, v1);
}

TEST(Vector, cant_erase_element_empty_Vector)
{
    Vector<int> v;
    ASSERT_ANY_THROW(v.erase(1));
}

TEST(Vector, can_insert_element)
{
    int* a = new int[5] {1, 2, 3, 4, 5};
    Vector<int> v(a, 5);
    delete[] a;
    int* b = new int[6] {1, 2, 3, 7, 4, 5};
    Vector<int> v1(b, 6);
    delete[] b;
    v.insert(7, 3);
    EXPECT_EQ(v, v1);
}
TEST(Vector, can_insert_element_with_resize)
{
    int* a = new int[5] {1, 2, 3, 4, 5};
    Vector<int> v(a, 5);
    delete[] a;
    int* b = new int[13] {1, 2, 3, 7, 8, 9, 10, 11, 12, 13, 14, 4, 5};
    Vector<int> v1(b, 13);
    delete[] b;
    for (size_t i = 14; i >= 7; i--) 
        v.insert(i, 3);
    EXPECT_EQ(v, v1);
}