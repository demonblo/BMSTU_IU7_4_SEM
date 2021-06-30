#include "set.h"

template <typename T>
Set<T>::Set(std::initializer_list<T> li) {
    if (!li.size()) return;

    for (const T& elem : li) {
        add(elem);
    }

    _amount = li.size();
}

template <typename T>
Set<T>::Set(const T* array, const int& size) {
    time_t t_time = time(nullptr);
    if (size < 0)
        throw rangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    if (array == nullptr)
        throw nullPtrError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    for (size_t i = 0; i < size; ++i)
        add(array[i]);
}

template <typename T>
Set<T>::Set(const Set<T> &arg) {
    for (const auto& elem : arg) {
        add(elem);
    }
}

template <typename T>
Set<T>::Set(Set<T>&& arg) noexcept {
    for (const auto& elem : arg) {
        add(elem);
    }
}


template <typename T>
template <typename Iter>
Set<T>::Set(const Iter& begin, const Iter& end) {

    Iter it(begin);
    while (it != end) {
        add(*it);
        ++it;
    }
}

template <typename T>
Set<T>::~Set() {
    _tree = nullptr;
    _amount = 0;
}



// assignment

template <typename T>
Set<T> & Set<T>::operator=(const Set<T> &copy) {
    if (this == &copy)
        return *this;

    _tree.reset();
    _tree = std::make_shared<RBtree<T>>();
    _amount = 0;

    for (const auto& elem : copy)
        add(elem);

    return *this;
}

template <typename T>
Set<T> & Set<T>::operator=(Set<T> &&copy) noexcept {
    if (this == &copy)
        return *this;

    _tree.reset();
    _amount = copy._amount;
    _tree = copy._tree;
    copy._tree.reset();

    return *this;
}

template <typename T>
Set<T> & Set<T>::operator=(const T& val) {
    _tree.reset();
    _amount = 0;
    _tree = std::make_shared<RBtree<T>>();
    add(val);

    return *this;
}

template <typename T>
Set<T> & Set<T>::operator=(T &&val) noexcept {
    _tree.reset();
    _amount = 0;
    _tree = std::make_shared<RBtree<T>>();
    add(val);

    return *this;
}


// other func

template <typename T>
bool Set<T>::add(const T& val) {
    time_t t_time = time(nullptr);

    if (_tree.get() == nullptr)
        throw nullPtrError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    bool ret = _tree->InsertNode(val);
    if (ret)
        _amount ++;

    return ret;
}

template <typename T>
bool Set<T>::remove(const T& val) {
    time_t t_time = time(nullptr);

    if (_tree.get() == nullptr)
        throw nullPtrError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    std::shared_ptr<Node<T>> node = _tree->SearchForNode(val);

    bool flag = true;
    if (!node or node->val != val)
        flag = false;
    else {
        _tree->deleteNode(node);
        _amount --;
    }

    return flag;
}

template <typename T>
T* Set<T>::toArray() const {
    time_t t_time = time(nullptr);

    if (_amount == 0) {
        throw rangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    T* array = new(std::nothrow) T[_amount];

    if (array == nullptr)
        throw memError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    int i = 0;
    for (const auto& elem : *this)
        array[i++] = elem;

    return array;
}

template <typename T>
std::pair<bool, constSetIterator<T>> Set<T>::find(const T& val) const {
    std::shared_ptr<Node<T>> node = _tree->SearchForNode(val);
    std::pair<bool, constSetIterator<T>> ret{};

    if (node->val != val) {
        ret.first = false;
        ret.second = constSetIterator<T>(nullptr);
    }
    else {
        ret.first = true;
        ret.second = constSetIterator<T>(node);
    }

    return ret;
}

template <typename T>
size_t Set<T>::size() const {
    return _amount;
}

template <typename T>
bool Set<T>::isEmpty() const {
    return !_amount;
}

template <typename T>
void Set<T>::clear() {
    _amount = 0;
}




// iterators

template <typename T>
constSetIterator<T> Set<T>::begin() const {
    std::shared_ptr<Node<T>> temp = _tree->getMinElem();

    return constSetIterator<T>(temp);
}

template <typename T>
constSetIterator<T> Set<T>::rbegin() const {
    std::shared_ptr<Node<T>> temp = _tree->getMaxElem();

    return constSetIterator<T>(temp);
}



// union

template <typename T>
Set<T> & Set<T>::merge(const Set<T> &inWork) {
    time_t t_time = time(nullptr);

    if (inWork._tree == nullptr)
        throw nullPtrError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    for (const auto& elem : inWork) {
        add(elem);
    }
    return *this;
}

template <typename T>
Set<T> & Set<T>::merge(Set<T> &&inWork) {
    time_t t_time = time(nullptr);

    if (inWork._tree == nullptr)
        throw nullPtrError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    for (const auto& elem : inWork) {
        add(elem);
    }
    return *this;
}

template <typename T>
Set<T> & Set<T>::operator+=(const Set<T> &copy) {
    merge(copy);
    return *this;
}

template <typename T>
Set<T> & Set<T>::operator+=(Set<T> &&move) {
    merge(std::move(move));
    return *this;
}

template <typename T>
Set<T> & Set<T>::operator+=(const T& val) {
    add(val);
    return *this;
}


template <typename T>
Set<T> operator +(const Set<T>& f, const Set<T>& s) {
    Set<T> newSet{};

    for (const auto& el : f)
        newSet.add(el);
    for (const auto& el : s)
        newSet.add(el);

    return newSet;
}


// Intersection

template <typename T>
Set<T>& Set<T>::intersection(const Set<T> &copy) {
    time_t t_time = time(nullptr);

    if (copy._tree == nullptr)
        throw nullPtrError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    Set<T> temp{};
    auto i = begin();
    auto j = copy.begin();

    while (i != end() and j != copy.end()) {
        if (*i == *j) {
            temp.add(*i);
            ++i;
            ++j;
        }
        else {
            if (*i < *j) {
                ++i;
            }
            else
                ++j;
        }
    }

    *this = temp;

    return *this;
}

template <typename T>
Set<T>& Set<T>::intersection(Set<T>&& copy) {
    time_t t_time = time(nullptr);

    if (copy == nullptr)
        throw nullPtrError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    Set<T> temp{};
    auto i = begin();
    auto j = copy.begin();

    while (i != end() and j != copy.end()) {
        if (*i == *j) {
            temp.add(*i);
            ++i;
            ++j;
        }
        else {
            if (*i < *j) {
                ++i;
            }
            else
                ++j;
        }
    }

    *this = temp;

    return *this;
}

template <typename T>
Set<T> & Set<T>::operator*=(const Set<T> &copy) {
    intersection(copy);
    return *this;
}

template <typename T>
Set<T> & Set<T>::operator*=(Set<T>&& copy) {
    intersection(std::move(copy));
    return *this;
}

template <typename T>
Set<T> operator *(const Set<T>& f, const Set<T>& s) {
    Set<T> newSet{};

    for (const auto& el : f)
        newSet.add(el);

    newSet.intersection(s);

    return newSet;
}


// subtraction

template <typename T>
Set<T> & Set<T>::subtraction(const Set<T> &copy) {
    time_t t_time = time(nullptr);

    if (copy._tree == nullptr)
        throw nullPtrError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    for (const auto& elem : copy)
        remove(elem);

    return *this;
}

template <typename T>
Set<T> & Set<T>::subtraction(Set<T>&& copy) {
    time_t t_time = time(nullptr);

    if (copy._tree == nullptr)
        throw nullPtrError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    for (const auto& elem : copy)
        remove(elem);

    return *this;
}

template <typename T>
Set<T> & Set<T>::operator-=(const Set<T> &copy) {
    subtraction(copy);
    return *this;
}

template <typename T>
Set<T> & Set<T>::operator-=(Set<T>&& copy) {
    subtraction(std::move(copy));
    return *this;
}

template <typename T>
Set<T> & Set<T>::operator-=(const T& val) {
    remove(val);
    return *this;
}

template <typename T>
Set<T> operator -(const Set<T>& f, const Set<T>& s) {
    Set<T> newSet{};

    for (const auto& el : f)
        newSet.add(el);

    newSet.subtraction(s);

    return newSet;
}
