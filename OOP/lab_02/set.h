#ifndef UNTITLED72_SET_H
#define UNTITLED72_SET_H

#include "baseContainer.h"
#include "RBtree_impl.hpp"
#include "const_set_iterator_impl.hpp"
#include "errors.h"
#include <initializer_list>
#include <memory>
#include <ctime>


template <typename T>
class Set final : public baseContainer {
public:

    // constructors
    explicit Set() = default;
    Set(const T* array, const int& size);
    Set(std::initializer_list<T> lt);
    template <typename Iter> Set(const Iter& begin, const Iter& end);

    explicit Set(const Set& copy);
    Set(Set&& move) noexcept;

    ~Set() override;

    // assignment by copying and moving
    Set& operator = (const Set& copy);
    Set& operator = (Set&& move) noexcept;
    Set& operator = (const T& val);
    Set& operator = (T&& val) noexcept;

    // merge operations
    Set& operator += (const Set& copy);
    Set& operator += (Set&& move);
    Set& operator += (const T& val);
    Set& merge(const Set& copy);
    Set& merge(Set&& move);
    template<typename Y> friend Set<Y> operator + (const Set<Y>& f, const Set<Y>& s);

    // intersection operation
    Set& operator *= (const Set& copy);
    Set& operator *= (Set&& move);
    Set& intersection(const Set& copy);
    Set& intersection(Set&& move);
    template<typename Y> friend Set<Y> operator * (const Set<Y>& f, const Set<Y>& s);

    // subtraction operations
    Set& operator -= (const Set& copy);
    Set& operator -= (Set&& move);
    Set& operator -= (const T& val);
    Set& subtraction(const Set& copy);
    Set& subtraction(Set&& move);
    template<typename Y> friend Set<Y> operator - (const Set<Y>& f, const Set<Y>& s);


    // other methods
    bool add(const T& val);
    bool remove(const T& val);
    std::pair<bool, constSetIterator<T>> find(const T& val) const;
    T* toArray() const;
    [[nodiscard]] bool isEmpty() const override;
    void clear() override;
    [[nodiscard]] size_t size() const override;

    // iterators
    constSetIterator<T> begin() const;
    constSetIterator<T> end() const { return constSetIterator<T>(nullptr); };
    constSetIterator<T> rbegin() const;
    constSetIterator<T> rend() const { return constSetIterator<T>(nullptr); };


private:
    size_t _amount{};
    std::shared_ptr<RBtree<T>> _tree{ new RBtree<T>() };
};

#endif //UNTITLED72_SET_H
