#ifndef _ITERATOR_VECTOR_H
#define _ITERATOR_VECTOR_H

#include "vector/vector.h"
#include "exceptions/exceptions.h"
#include <iterator>
#include <ctime>

template <typename T>
class VectorIterator : public std::iterator<std::input_iterator_tag, T>
{
    friend class Vector<T>;

public:
    VectorIterator() {
        std::weak_ptr<T[]> arr;
        count = 0;
        index = 0;
    }
    VectorIterator(const shared_ptr<T[]>& a, const int& c, const int ind = 0) : arr(a), count(c), index(ind) {}
    VectorIterator(const VectorIterator<T>& it) = default;

    bool operator != (const VectorIterator<T>& it) const;
    bool operator == (const VectorIterator<T>& it) const;

    VectorIterator<T>& operator ++(); // ++obj
    VectorIterator<T> operator ++(int); // obj++

    T& operator *();
    const T& operator*() const;
    T* operator ->();
    const T* operator->() const;

    operator bool() const noexcept;

 private:
    weak_ptr<T[]> arr;
    int count;
    int index = 0;
};

template <typename T>
class ConstVectorIterator : public std::iterator<std::output_iterator_tag, T>
{
private:
    ConstVectorIterator(const shared_ptr<T[]>& a, const shared_ptr<size_t>& c, size_t ind = 0) : arr(a), count(c), index(ind) {}
public:
    ConstVectorIterator(const ConstVectorIterator<T>& it) = default;

    bool operator != (const ConstVectorIterator<T>& it) const;
    bool operator == (const ConstVectorIterator<T>& it) const;

    ConstVectorIterator<T>& operator ++(); // ++obj
    ConstVectorIterator<T> operator ++(int); // obj++

    const T& operator*() const;
    const T* operator->() const;

    operator bool() const noexcept;

 private:
    weak_ptr<T[]> arr;
    weak_ptr<size_t> count;
    size_t index = 0;
};


















template <typename T>
bool VectorIterator<T>::operator != (const VectorIterator<T>& it) const
{
    return index != it.index;
}

template <typename T>
bool VectorIterator<T>::operator == (const VectorIterator<T>& it) const
{
    return index = it.index;
}

template <typename T>
VectorIterator<T>& VectorIterator<T>::operator++()
{
    if (index < count)
        index++;

    return *this;
}

template <typename T>
VectorIterator<T> VectorIterator<T>::operator++(int)
{
    VectorIterator<T> it(*this);

    ++(*this);

    return it;
}


template <typename T>
T& VectorIterator<T>::operator*()
{
    shared_ptr<T[]> a(arr);

    return a[index];
}

template <typename T>
const T& VectorIterator<T>::operator*() const
{
    shared_ptr<T[]> a(arr);

    return a[index];
}

template <typename T>
T* VectorIterator<T>::operator->()
{
    shared_ptr<T[]> a(arr);

    return &a[index];
}

template <typename T>
const T* VectorIterator<T>::operator->() const
{
    shared_ptr<T[]> a(arr);

    return &a[index];
}

template <typename T>
VectorIterator<T>::operator bool() const noexcept
{
    return arr.expired();
}


#endif // _ITERATOR_VECTOR_H
