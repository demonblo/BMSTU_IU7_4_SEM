#ifndef UNTITLED72_CONST_SET_ITERATOR_H
#define UNTITLED72_CONST_SET_ITERATOR_H

#include "errors.h"
#include <iterator>
#include <memory>
#include <ctime>

template <typename T>
class constSetIterator : public std::iterator<std::output_iterator_tag, T>{
public:
    // constructors
    constSetIterator() = default;
    explicit constSetIterator(const std::shared_ptr<Node<T>>& in) : _cur(in) {}
    explicit constSetIterator(std::shared_ptr<Node<T>>&& in) noexcept : _cur(in) {}

    // comparison
    bool operator != (const constSetIterator& another) const;
    bool operator == (const constSetIterator& another) const;

    // retrieving an element
    const T& operator * () const;
    std::shared_ptr<Node<T>> operator -> () const;

    // iteration
    constSetIterator<T>& operator ++ ();
    constSetIterator<T>& operator -- ();
    const constSetIterator<T> operator ++ (int);
    const constSetIterator<T> operator -- (int);

    // isEnd?
    [[nodiscard]] bool isEnd() const;

private:
    std::weak_ptr<Node<T>> _cur{};
};

#endif //UNTITLED72_CONST_SET_ITERATOR_H
