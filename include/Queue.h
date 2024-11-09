
#ifndef Queue_h
#define Queue_h
#include "Vector.h"

using namespace std;

template<typename T> class Queue : private Vector<T>
{
    using Vector<T>::size;
    using Vector<T>::capacity;
    using Vector<T>::data;
    using Vector<T>::resize;
    size_t front, back;
public:
    
    Queue() : Vector<T>(0), front(0), back(0) {}
   
    using Vector<T>::isFull;
    using Vector<T>::isEmpty;
    using Vector<T>::size_;
    using Vector<T>::capacity_;

    void push(T elem)
    {
        if (!this->isFull()) 
        {
            data[back] = elem;
            size++;
            if (back == capacity - 1) back = 0;
            else back++;
        }
        else 
        {
            this->resize(size_t(size_t((int)size + 1)));
            data[back++] = elem;
        }
    }

    void pop()
    {
        if (!this->isEmpty())
        {
            if (front == capacity - 1) front = 0;
            else front++;
            size--;
        }
    }

    T get_front()
    {
        return data[front];
    }

    T get_back()
    {
        if (back == 0) 
            return data[capacity-1];
        else 
            return data[back - 1];
    }

    T get_back_ind()
    {
        return back;
    }
};

#endif