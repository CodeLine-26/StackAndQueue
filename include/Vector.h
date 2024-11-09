
#ifndef Vector_h
#define Vector_h
#include <iostream>

using namespace std;

template<typename T> class Vector
{
protected:

    size_t size;
    size_t capacity;
    T* data;

public:

    // Конструкторы
    Vector(size_t sz = 0) : size(sz), capacity(sz * 2 + 2)
    {
        data = new T[capacity];
        if (data == nullptr) 
            throw ("Error");
    }

    Vector(T* arr, size_t sz) : size(sz), capacity(sz * 2 + 2)
    {
        data = new T[capacity];
        if (data == nullptr) 
            throw ("Error");
        else copy(arr, arr + sz, data);
    }

    Vector(const Vector& t) : size(t.size), capacity(t.capacity)
    {
        data = new T[capacity];
        if (data == nullptr) 
            throw ("Error"); 
        else copy(t.data, t.data + t.size + 1, data);
    }

    Vector(const Vector&& t) noexcept
    {
        data = nullptr;
        swap(*this, t);
    }

    // Деструктор
    ~Vector()
    {
        delete[] data;
        data = nullptr;
    }

    // operator =
    Vector& operator=(const Vector& v)
    {
        if (&v == this) 
            return *this;

        if (size != v.size)
        {
            T* p = new T[v.capacity];
            if (p == nullptr)
                throw ("Error");
            else {
                delete[] data; data = nullptr;
                data = p;
                size = v.size;
                capacity = v.capacity;
                p = nullptr;
            }
        }
        copy(v.data, v.data + v.size + 1, data);
        return *this;
    }

    Vector& operator=(const Vector&& v) noexcept
    {
        delete[] data;
        data = nullptr;
        swap(*this, v);
        return *this;
    }

    friend void swap(Vector& lhs, Vector& rhs)
    {
        swap(lhs.size, rhs.size);
        swap(lhs.capacity, rhs.capacity);
        swap(lhs.data, rhs.data);
    }

    size_t size_() const noexcept { return size; };
    size_t capacity_() const noexcept { return capacity; };
    bool isEmpty() const noexcept { return (size == 0); };
    bool isFull() const noexcept { return (size == capacity); };

    // сравнение
    bool operator==(const Vector& t) const noexcept
    {
        if (size != t.size) 
            return 0;
        else 
            for (size_t i = 1; i < size + 1; i++)
            if (data[i] != t.data[i]) 
                return 0;
        return 1;
    }

    bool operator!=(const Vector& t) const noexcept
    {
        return (!(*this == t));
    }

    // индексация
    T operator[](size_t ind)
    {
        return data[ind + 1];
    }

    const T operator[](size_t ind) const
    {
        return data[ind + 1];
    }


    T back() 
    {
        if (!(this->isEmpty())) 
            return data[size]; 
        else 
            throw ("Vector is empty");
    };

    //void resize(int new_size)
    //{
    //    T* mem = new T[new_size * 2 + 2];
    //    if (mem != nullptr) 
    //    {
    //        copy(data, data + capacity, mem);
    //        delete[] data;
    //        size = new_size;
    //        capacity = new_size * 2 + 2;
    //        data = mem;
    //        mem = nullptr;
    //    }
    //}

    void push_back(T elem)
    {
        if (!(this->isFull())) 
            data[++size] = elem;
        else 
        {
            this->resize(size_t(size_t((int)size + 1)));
            data[size] = elem;
        }
    }

    void push_front(T elem)
    {
        insert(elem, 0);
    }

    void pop_back()
    {
        if (!(this->isEmpty())) 
            size--;
        else 
            throw ("Vector is empty");
    }

    void pop_front()
    {
        erase(0);
    }

    void insert(T elem, size_t ind)
    {
        ind += 1;
        if (!(this->isFull()))
        {
            for (size_t i = size + 1; i > ind; i--)
                data[i] = data[i - 1];
            data[ind] = elem; size++;
        }
        else 
        {
            this->resize(size_t(size_t((int)size + 1)));
            for (size_t i = size + 1; i > ind; i--)
                data[i] = data[i - 1];
            data[ind] = elem;
        }
    }

    void erase(size_t ind)
    {
        ind += 1;
        if (!(this->isEmpty()))
        {
            for (size_t i = ind; i < size + 1; i++)
                data[i] = data[i + 1];
            size--;
        }
        else 
            throw ("Vector is empty");
    }
};

#endif