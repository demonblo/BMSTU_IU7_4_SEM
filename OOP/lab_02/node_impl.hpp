#include "node.h"

template <typename T>
Node<T>::Node(const T &val) : Node() {
    this->val = val;
}

template <typename T>
Node<T>::Node() {
    color = RED;
    left = right = parent = nullptr;
}

template <typename T>
std::shared_ptr<Node<T>> Node<T>::GetParent() {
    return this->parent;
}

template <typename T>
std::shared_ptr<Node<T>> Node<T>::GetGrandParent() {
    return this->GetParent()->GetParent();
}

template <typename T>
std::shared_ptr<Node<T>> Node<T>::GetSibling() {
    std::shared_ptr<Node> p { this->GetParent() };
    std::shared_ptr<Node> ret { nullptr };

    if (p == nullptr);
    else if (this == p->left.get())
        ret = p->right;
    else
        ret = p->left;

    return ret;
}

template <typename T>
std::shared_ptr<Node<T>> Node<T>::GetUncle() {
    std::shared_ptr<Node> p = this->GetParent();
    return p->GetSibling();
}

template <typename T>
bool Node<T>::isOnLeft() {
    return this == parent->left.get();
}

template <typename T>
bool Node<T>::Node::hasRedChild() {
    return (left != nullptr and left->color == RED) or
           (right != nullptr and right->color == RED);
}

//template <typename T>
//bool Node<T>::operator != (std::shared_ptr<Node<T> > node) {
//    return this != node.get();
//}
//
//template <typename T>
//bool Node<T>::operator == (std::shared_ptr<Node<T> > node) {
//    return this != node.get();
//}

template <typename T>
std::shared_ptr<Node<T>> Node<T>::getLeftest(std::shared_ptr<Node<T>> cur) {
    while (cur->left)
        cur = cur->left;

    return cur;
}

template <typename T>
std::shared_ptr<Node<T>> Node<T>::getRightest(std::shared_ptr<Node<T>> cur) {
    while (cur->right)
        cur = cur->right;

    return cur;
}

template <typename T>
std::shared_ptr<Node<T>> Node<T>::nextElem(std::shared_ptr<Node<T>> cur) {
    if (cur->right) {
        cur = cur->right;
        cur = cur->getLeftest(cur);
    }
    else if (cur and (!cur->parent or cur->parent->left == cur)) {
        cur = cur->parent;
    }
    else {
        while (cur and (!cur->parent or cur->parent->right == cur))
            cur = cur->parent;
        if (cur and (!cur->parent or cur->parent->left == cur)) {
            cur = cur->parent;
        }
    }
    return cur;
}

template <typename T>
std::shared_ptr<Node<T>> Node<T>::prevElem(std::shared_ptr<Node<T>> cur) {
    if (cur->left) {
        cur = cur->left;
        cur = cur->getRightest(cur);
    }
    else if (cur and (!cur->parent or cur->parent->right == cur)) {
        cur = cur->parent;
    }
    else {
        while (cur and (!cur->parent or cur->parent->left == cur))
            cur = cur->parent;
        if (cur and (!cur->parent or cur->parent->right == cur)) {
            cur = cur->parent;
        }
    }
    return cur;
}