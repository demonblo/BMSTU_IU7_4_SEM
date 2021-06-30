#ifndef UNTITLED72_NODE_H
#define UNTITLED72_NODE_H

#include <memory>

template <typename T>
class Node {
public:
    enum color_t { BLACK, RED };

    T val{};
    enum color_t color;
    std::shared_ptr<Node<T>> left{};
    std::shared_ptr<Node<T>> right{};
    std::shared_ptr<Node<T>> parent{};

    explicit Node();
    explicit Node(const T &val);

    std::shared_ptr<Node<T>> GetParent();
    std::shared_ptr<Node<T>> GetGrandParent();
    std::shared_ptr<Node<T>> GetSibling();
    std::shared_ptr<Node<T>> GetUncle();
    bool isOnLeft();
    bool hasRedChild();

    std::shared_ptr<Node<T>> nextElem(std::shared_ptr<Node<T>> cur);
    std::shared_ptr<Node<T>> prevElem(std::shared_ptr<Node<T>> cur);
    std::shared_ptr<Node<T>> getRightest(std::shared_ptr<Node<T>> cur);
    std::shared_ptr<Node<T>> getLeftest(std::shared_ptr<Node<T>> cur);

//
//    bool operator != (std::shared_ptr<Node<T>> node);
//    bool operator == (std::shared_ptr<Node<T>> node);

};
#endif //UNTITLED72_NODE_H
