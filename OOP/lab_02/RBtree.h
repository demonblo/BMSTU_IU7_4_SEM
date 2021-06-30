#ifndef UNTITLED72_RBTREE_H
#define UNTITLED72_RBTREE_H

#include "node_impl.hpp"
#include <memory>

template<typename T>
class RBtree {
public:
    explicit RBtree() = default;
    //RBtree(std::initializer_list<T> lt);
    virtual ~RBtree();

    bool InsertNode(const T& n);
    void deleteNode(std::shared_ptr<Node<T>> v);

    std::shared_ptr<Node<T>> SearchForNode(const T &val) const;
    std::shared_ptr<Node<T>> getMinElem();
    std::shared_ptr<Node<T>> getMaxElem();


private:
    std::shared_ptr<Node<T>> root_{};

    void InsertCase1(std::shared_ptr<Node<T>> n);
    void InsertCase2(std::shared_ptr<Node<T>> n);
    void InsertCase3(std::shared_ptr<Node<T>> n);
    void InsertCase4(std::shared_ptr<Node<T>> n);
    void InsertCase4Step2(std::shared_ptr<Node<T>> n);
    void InsertRepairTree(std::shared_ptr<Node<T>> n);

    void RotateLeft(std::shared_ptr<Node<T>> n);
    void RotateRight(std::shared_ptr<Node<T>> n);

    std::shared_ptr<Node<T>> initNode(const T &elem);
    std::shared_ptr<Node<T>> FindSuccessor(std::shared_ptr<Node<T>> x);
    std::shared_ptr<Node<T>> FindRepNode(std::shared_ptr<Node<T>> x);
    void fixDoubleBlack(std::shared_ptr<Node<T>> x);
    void swapValues(std::shared_ptr<Node<T>> u, std::shared_ptr<Node<T>> v);
    void getRoot();

    void delCase1();
    void delCase2(std::shared_ptr<Node<T>> n);
    void delCase3(std::shared_ptr<Node<T>> v) const;
    void setToChild(std::shared_ptr<Node<T>> v, std::shared_ptr<Node<T>> pointer) const;
    void delCase4(std::shared_ptr<Node<T>> v, std::shared_ptr<Node<T>> u) const;
    void delCase5(std::shared_ptr<Node<T>> v, std::shared_ptr<Node<T>> u) const;
    bool bothBlack(std::shared_ptr<Node<T>> v, std::shared_ptr<Node<T>> u) const;
    void delCase6(std::shared_ptr<Node<T>> u) const;
};

#endif //UNTITLED72_RBTREE_H
