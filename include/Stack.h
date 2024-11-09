
#ifndef Stack_h
#define Stack_h
#include "Vector.h"

using namespace std;

template<typename T> class Stack : private Vector<T>
{
    using Vector<T>::size;
    using Vector<T>::capacity;
    using Vector<T>::data;
    using Vector<T>::pop_back;
    using Vector<T>::resize;
    using Vector<T>::push_back;
    using Vector<T>::back;

public:

    // конструктор
    Stack() : Vector<T>(0) {}

    // Наследуем
    using Vector<T>::isFull;
    using Vector<T>::isEmpty;
    using Vector<T>::size_;
    using Vector<T>::capacity_;
   

    void push(T elem)
    {
        this->push_back(elem);
    }
    void pop()
    {
        this->pop_back();
    }
    T top()
    {
        return this->back();
    }
};

#endif 