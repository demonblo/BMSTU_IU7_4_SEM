#ifndef VECTOR_H
#define VECTOR_H

#include "vector_base.h"
#include <iostream>
#include <memory>

#include <exceptions/exceptions.h>
#include <ctime>

template <typename T> class VectorIterator;
template <typename T> class ConstVectorIterator;

template<typename T>
class Vector : public VectorBase
{
public:
    Vector();
    Vector(Vector<T>&& vec);
    Vector(const Vector<T>& vec);
    Vector(size_t size);
    Vector(size_t size, const T& value);
    Vector(const std::initializer_list<T>& lst);

    ~Vector();

    size_t get_size() const override;
    bool is_empty() const override;
    void clear() override;
    void push_back(const T& elem);
    void erase(VectorIterator<T> &it);

    T& operator[] (size_t index);
    const T& operator[] (size_t index) const;
    Vector<T>& operator=(const Vector<T>& vec);
    Vector<T>& operator=(Vector<T>&& vec);

    operator bool() { return get_size(); }

    VectorIterator<T> begin();
    VectorIterator<T> end();

    VectorIterator<T> begin() const;
    VectorIterator<T> end() const;

    ConstVectorIterator<T> cbegin() const{return ConstVectorIterator<T>(arr, size);}
    ConstVectorIterator<T> cend() const{return ConstVectorIterator<T>(arr, size, size);}

private:
    int size;
    std::shared_ptr<T[]> arr;
};








template<typename T>
Vector<T>::Vector()
{
    arr = nullptr;
    size = 0;
}

template<typename T>
Vector<T>::Vector(Vector<T> &&vec)
{
    arr = vec.arr;
    size = vec.size;
    vec.~Vector();
}

template<typename T>
Vector<T>::Vector(size_t size)
{
   arr = nullptr;
   this->size = 0;
   time_t t_time = time(NULL);
   if (size <= 0)
       throw ErrorRange(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
   for (size_t i = 0; i < size; ++i)
   {
       push_back(0);
   }
}

template<typename T>
Vector<T>::Vector(size_t size, const T& value)
{
   arr = nullptr;
   time_t t_time = time(NULL);
   if (size <= 0)
       throw ErrorRange(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
   for (int i = 0; i < size; ++i)
   {
       push_back(value);
   }
}

template<typename T>
Vector<T>::Vector(const Vector<T>& vec)
{
    arr = vec.arr;
    size = vec.size;
}


template <typename T>
Vector<T>::Vector(const std::initializer_list<T> &lst)
{
    size = 0;
    arr = nullptr;
    for (auto &element : lst)
    {
        this->push_back(element);
    }
}

template<typename T>
Vector<T>::~Vector()
{
    clear();
}

template<typename T>
size_t Vector<T>::get_size() const
{
    return size;
}

template<typename T>
bool Vector<T>::is_empty() const
{
    return size == 0;
}

template<typename T>
void Vector<T>::clear()
{
    arr = nullptr;
    size = 0;
}

template<typename T>
void Vector<T>::push_back(const T& data)
{
    T *_result = new T[++this->size];

    for(int index = 0; index < this->size; index++)
    {
        if(index != this->size-1)
        {
            _result[index] = this->arr[index];
        }
        else
        {
            _result[index] = data;
            break;
        }
    }
    this->arr.reset(_result);
}

template<typename T>
void Vector<T>::erase(VectorIterator<T> &it)
{
    T *_result = new T[--this->size];
    int resIndex = 0;
    for(int index2 = 0; index2 < this->size+1; index2++)
    {
        T item = this->arr[index2];
        if (it.index == index2)
            continue;
        _result[resIndex++] = this->arr[index2];
    }
    this->arr.reset(_result);
}

template<typename T>
T& Vector<T>::operator[] (size_t index)
{
    time_t t_time = time(NULL);
    if (index >= size)
        throw ErrorRange(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    return arr[index];
}

template<typename T>
const T& Vector<T>::operator[] (size_t index) const
{
    time_t t_time = time(NULL);
    if (index < 0 || index >= size)
        throw ErrorRange(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    return arr[index];
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& vec)
{
    this->arr = vec.arr;
    this->size = vec.size;

    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& vec)
{
    this->arr = vec.arr;
    this->size = vec.size;
    vec.~Vector();

    return *this;
}

template <typename T>
VectorIterator<T> Vector<T>::begin()
{
    VectorIterator<T> it(arr, size, 0);
    return it;
};

template <typename T>
VectorIterator<T> Vector<T>::end()
{
    return VectorIterator<T>(arr, size, size);
};

template <typename T>
VectorIterator<T> Vector<T>::begin() const
{
    VectorIterator<T> it(arr, size, 0);
    return it;
};

template <typename T>
VectorIterator<T> Vector<T>::end() const
{
    return VectorIterator<T>(arr, size, size);
};
#endif // VECTOR_H
