#ifndef Queue2Stacks_h
#define Queue2Stacks_h

#include "Vector.h"
#include "Stack.h"

using namespace std;

template<typename T> class Queue2Stacks : private Vector<Stack<T>>
{
private:

    using::Vector<Stack<T>>::data;
    size_t size, capacity;

public:

    Queue2Stacks() : size(data[0].size_() + data[1].size_()), capacity(data[0].capacity_() + data[1].capacity_()) {}

    size_t size_() const noexcept { return data[0].size_() + data[1].size_(); };
    size_t capacity_() const noexcept { return data[0].capacity_() + data[1].capacity_(); };
    bool isEmpty() const noexcept { return (data[0].isEmpty() && data[1].isEmpty()); };
    bool isFull() const noexcept { return (data[0].isFull() && data[1].isFull()); };

    void push(T elem)
    {
        data[0].push(elem);
        size++;
    }

    void pop()
    {
        if (data[1].isEmpty())
        {
            while (!data[0].isEmpty()) 
            {
                T mem = data[0].top();
                data[1].push(mem);
                data[0].pop();
            }
        }
        else 
        {
            data[1].pop();
        }
        size--;
    }

    T back()
    {
        if (!data[1].isEmpty()) 
        {
            T mem = {};
            while (!data[1].isEmpty()) 
            {
                mem = data[1].top();
                data[1].pop();
            }
            return mem;
        }
        if (!data[0].isEmpty())
            return data[0].top();
        else 
            return 0;
    }

    T front()
    {
        if (!data[0].isEmpty()) 
        {
            T mem = {};
            while (!data[0].isEmpty()) 
            {
                mem = data[0].top();
                data[0].pop();
            }
            return mem;
        }
        if (!data[1].isEmpty())
            return data[1].top();
        else 
            return 0;
    }
};

#endif