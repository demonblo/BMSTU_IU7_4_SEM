#include "vector/vector_iterator.hpp"

/*template <typename T>
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


//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------

template <typename T>
bool ConstVectorIterator<T>::operator != (const ConstVectorIterator<T>& it) const
{
    return index != it.index;
}

template <typename T>
bool ConstVectorIterator<T>::operator == (const ConstVectorIterator<T>& it) const
{
    return index = it.index;
}

template <typename T>
ConstVectorIterator<T>& ConstVectorIterator<T>::operator++()
{
    shared_ptr<size_t> n(count);
    if (index < *n)
        index++;

    return *this;
}

template <typename T>
ConstVectorIterator<T> ConstVectorIterator<T>::operator++(int)
{
    VectorIterator<T> it(*this);

    ++(*this);

    return it;
}

template <typename T>
const T& ConstVectorIterator<T>::operator*() const
{
    shared_ptr<T[]> a(arr);

    return a[index];
}

template <typename T>
const T* ConstVectorIterator<T>::operator->() const
{
    shared_ptr<T[]> a(arr);

    return &a[index];
}

template <typename T>
ConstVectorIterator<T>::operator bool() const noexcept
{
    return arr.expired();
}*/
