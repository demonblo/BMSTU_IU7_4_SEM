#include "const_set_Iterator.h"

template <typename T>
bool constSetIterator<T>::operator!=(const constSetIterator<T> &another) const {
    return _cur.lock() != another._cur.lock();
}

template <typename T>
bool constSetIterator<T>::operator==(const constSetIterator<T> &another) const {
    return _cur.lock() == another._cur.lock();
}

template <typename T>
const T& constSetIterator<T>::operator*() const {
    time_t t_time = time(nullptr);

    if (_cur.lock() == nullptr)
        throw nullPtrError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    return _cur.lock()->val;
}

template <typename T>
std::shared_ptr<Node<T>> constSetIterator<T>::operator->() const {
    time_t t_time = time(nullptr);

    if (_cur.lock() == nullptr)
        throw nullPtrError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    return _cur.lock();
}

template <typename T>
constSetIterator<T>& constSetIterator<T>::operator++() {
    time_t t_time = time(nullptr);

    if (_cur.lock() == nullptr)
        throw nullPtrError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    _cur = _cur.lock()->nextElem(_cur.lock());

    return *this;
}

template <typename T>
constSetIterator<T>& constSetIterator<T>::operator--() {
    time_t t_time = time(nullptr);

    if (_cur.lock() == nullptr)
        throw nullPtrError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    _cur = _cur.lock()->prevElem(_cur.lock());

    return *this;
}

template <typename T>
const constSetIterator<T> constSetIterator<T>::operator++(int) {
    time_t t_time = time(nullptr);

    if (_cur.lock() == nullptr)
        throw nullPtrError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    std::shared_ptr<Node<T>> temp = _cur.lock();
    _cur = _cur.lock()->nextElem(_cur.lock());
    return constSetIterator<T>(temp);
}

template <typename T>
const constSetIterator<T> constSetIterator<T>::operator--(int) {
    time_t t_time = time(nullptr);

    if (_cur.lock() == nullptr)
        throw nullPtrError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    std::shared_ptr<Node<T>> temp = _cur.lock();
    _cur = _cur.lock()->prevElem(_cur.lock());
    return constSetIterator<T>(temp);
}

template <typename T>
bool constSetIterator<T>::isEnd() const {
    return this->_cur.lock() == nullptr;
}
