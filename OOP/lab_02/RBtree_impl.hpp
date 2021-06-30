#include "RBtree.h"

template <typename T>
void RBtree<T>::RotateLeft(std::shared_ptr<Node<T>> n) {
    std::shared_ptr<Node<T>> nnew = n->right;
    std::shared_ptr<Node<T>> p = n->GetParent();
    if (nnew == nullptr)
        return;// Since the leaves of a red-black _tree are empty,
    // they cannot become internal nodes.
    n->right = nnew->left;
    nnew->left = n;
    n->parent = nnew;
    // Handle other child/parent pointers.
    if (n->right != nullptr) {
        n->right->parent = n;
    }

    // Initially n could be the root.
    if (p != nullptr) {
        if (n == p->left) {
            p->left = nnew;
        } else if (n == p->right) {
            p->right = nnew;
        }
    }
    nnew->parent = p;
}

template <typename T>
void RBtree<T>::RotateRight(std::shared_ptr<Node<T>> n) {
    std::shared_ptr<Node<T>> nnew = n->left;
    std::shared_ptr<Node<T>> p = n->GetParent();
    if (nnew == nullptr)
        return;

    n->left = nnew->right;
    nnew->right = n;
    n->parent = nnew;


    if (n->left != nullptr) {
        n->left->parent = n;
    }

    if (p != nullptr) {
        if (n == p->left) {
            p->left = nnew;
        } else if (n == p->right) {
            p->right = nnew;
        }
    }
    nnew->parent = p;
}


template <typename T>
std::shared_ptr<Node<T>> RBtree<T>::SearchForNode(const T &val) const {
    std::shared_ptr<Node<T>> inWork = this->root_;
    bool stop_flag{};

    while (inWork != nullptr and !stop_flag) {
        if (val < inWork->val) {
            if (inWork->left == nullptr)
                stop_flag = true;
            else
                inWork = inWork->left;
        } else if (val == inWork->val) {
            stop_flag = true;
        } else {
            if (inWork->right == nullptr)
                stop_flag = true;
            else
                inWork = inWork->right;
        }
    }

    return inWork;
}

template <typename T>
std::shared_ptr<Node<T>> RBtree<T>::initNode(const T& elem) {
    return std::shared_ptr<Node<T>>(new Node(elem));
}

template <typename T>
void RBtree<T>::InsertRepairTree(std::shared_ptr<Node<T>> n) {
    if (n->GetParent() == nullptr) {
        InsertCase1(n);
    } else if (n->GetParent()->color == Node<T>::BLACK) {
        InsertCase2(n);
    } else if (n->GetUncle() != nullptr && n->GetUncle()->color == Node<T>::RED) {
        InsertCase3(n);
    } else {
        InsertCase4(n);
    }
}


template <typename T>
void RBtree<T>::InsertCase1(std::shared_ptr<Node<T>> n) {
    n->color = Node<T>::BLACK;
}

template <typename T>
void RBtree<T>::InsertCase2(std::shared_ptr<Node<T>> n) {
    return;
}

template <typename T>
void RBtree<T>::InsertCase3(std::shared_ptr<Node<T>> n) {
    n->GetParent()->color = Node<T>::BLACK;
    n->GetUncle()->color = Node<T>::BLACK;
    n->GetGrandParent()->color = Node<T>::RED;
    InsertRepairTree(n->GetGrandParent());
}

template <typename T>
void RBtree<T>::InsertCase4(std::shared_ptr<Node<T>> n) {
    std::shared_ptr<Node<T>>  p = n->GetParent();
    std::shared_ptr<Node<T>>  g = n->GetGrandParent();

    if (n == p->right && p == g->left) {
        RotateLeft(p);
        n = n->left;
    } else if (n == p->left && p == g->right) {
        RotateRight(p);
        n = n->right;
    }

    InsertCase4Step2(n);
}
template <typename T>
void RBtree<T>::InsertCase4Step2(std::shared_ptr<Node<T>> n) {
    std::shared_ptr<Node<T>> p = n->GetParent();
    std::shared_ptr<Node<T>> g = n->GetGrandParent();

    if (n == p->left) {
        RotateRight(g);
    } else {
        RotateLeft(g);
    }
    p->color = Node<T>::BLACK;
    g->color = Node<T>::RED;
}


template <typename T>
RBtree<T>::~RBtree() = default;
    //DestroyRecursive(root_);



template <typename T>
bool RBtree<T>::InsertNode(const T& n) {
    std::shared_ptr<Node<T>> node = SearchForNode(n);
    bool flag = true;
    std::shared_ptr<Node<T>> inWork = nullptr;

    if (!node) {
        root_ = initNode(n);
        root_->color = Node<T>::BLACK;
        inWork = root_;
    }
    else if (node->val == n) {
        flag = false;
        inWork = node;
    }
    else {
        inWork = initNode(n);
        inWork->parent = node;

        if (n < node->val)
            node->left = inWork;
        else
            node->right = inWork;

        InsertRepairTree(inWork);

        while (root_->parent)
            root_ = root_->parent;
    }

    return flag;
}



template <typename T>
std::shared_ptr<Node<T>> RBtree<T>::FindSuccessor(std::shared_ptr<Node<T>> x) {
    std::shared_ptr<Node<T>> temp = x;

    while (temp->right != nullptr)
        temp = temp->right;

    return temp;
}



template <typename T>
void RBtree<T>::fixDoubleBlack(std::shared_ptr<Node<T>> x) {
    if (x == root_)
        // Reached root_
        return;

    std::shared_ptr<Node<T>> sibling = x->GetSibling(), parent = x->parent;
    if (sibling == nullptr) {
        // No sibiling, double black pushed up
        fixDoubleBlack(parent);
    } else {
        if (sibling->color == Node<T>::RED) {
            // Sibling red
            parent->color = Node<T>::RED;
            sibling->color = Node<T>::BLACK;
            if (sibling->isOnLeft()) {
                // left case
                RotateRight(parent);
            } else {
                // right case
                RotateLeft(parent);
            }
            fixDoubleBlack(x);
        } else {
            // Sibling black
            if (sibling->hasRedChild()) {
                // at least 1 red children
                if (sibling->left != nullptr and sibling->left->color == Node<T>::RED) {
                    if (sibling->isOnLeft()) {
                        // left left
                        sibling->left->color = sibling->color;
                        sibling->color = parent->color;
                        RotateRight(parent);
                    } else {
                        // right left
                        sibling->left->color = parent->color;
                        RotateRight(sibling);
                        RotateLeft(parent);
                    }
                } else {
                    if (sibling->isOnLeft()) {
                        // left right
                        sibling->right->color = parent->color;
                        RotateLeft(sibling);
                        RotateRight(parent);
                    } else {
                        // right right
                        sibling->right->color = sibling->color;
                        sibling->color = parent->color;
                        RotateLeft(parent);
                    }
                }
                parent->color = Node<T>::BLACK;
            } else {
                // 2 black children
                sibling->color = Node<T>::RED;
                if (parent->color == Node<T>::BLACK)
                    fixDoubleBlack(parent);
                else
                    parent->color = Node<T>::BLACK;
            }
        }
    }
}


template <typename T>
void RBtree<T>::getRoot() {
    while (root_ and root_->parent)
        root_ = root_->parent;
}

template <typename T>
void RBtree<T>::deleteNode(std::shared_ptr<Node<T>> v) {
    std::shared_ptr<Node<T>> u = FindRepNode(v);
    std::shared_ptr<Node<T>> parent = v->parent;

    bool bb = bothBlack(v, u);

    if (u == nullptr) {
        // v is leaf
        if (v == root_) {
            delCase1();
        }
        else {
            if (bb)
                delCase2(v);
            else
                delCase3(v);

            setToChild(v, nullptr);
        }

        v->parent = v->right = v->left = nullptr;
        v->val = 0;

        getRoot();
        return;
    }

    if (v->left == nullptr or v->right == nullptr) {
        // v has 1 child
        if (v == root_) {
            delCase4(v, u);
        }
        else {
            delCase5(v, u);
            u->parent = parent;

            if (bb) {
                delCase2(u);
            } else {
                delCase6(u);
            }
        }

        getRoot();
        return;
    }

    // v has 2 children
    swapValues(u, v);
    deleteNode(u);
}

template <typename T>
std::shared_ptr<Node<T>> RBtree<T>::FindRepNode(std::shared_ptr<Node<T>> x) {
    // when node have 2 children
    if (x->left != nullptr and x->right != nullptr)
        return FindSuccessor(x->left);

    // when leaf
    if (x->left == nullptr and x->right == nullptr)
        return nullptr;

    // when single child
    if (x->left != nullptr)
        return x->left;
    else
        return x->right;
}

template <typename T>
bool RBtree<T>::bothBlack(std::shared_ptr<Node<T>> v, std::shared_ptr<Node<T>> u) const {
    return ((u == nullptr or u->color == Node<T>::BLACK) and (v->color == Node<T>::BLACK));
}

template <typename T>
void RBtree<T>::setToChild(std::shared_ptr<Node<T>> n, std::shared_ptr<Node<T>> pointer) const {
    if (n->isOnLeft())
        n->parent->left = pointer;
    else
        n->parent->right = pointer;
}

template <typename T>
void RBtree<T>::swapValues(std::shared_ptr<Node<T>> u, std::shared_ptr<Node<T>> v) {
    T temp;
    temp = u->val;
    u->val = v->val;
    v->val = temp;
}


template <typename T>
void RBtree<T>::delCase1() {
    // v is root_, making root_ null
    root_ = nullptr;
}

template <typename T>
void RBtree<T>::delCase2(std::shared_ptr<Node<T>> n) {
    // u and v both black
    // v is leaf, fix double black at v
    fixDoubleBlack(n);
}

template <typename T>
void RBtree<T>::delCase3(std::shared_ptr<Node<T>> n) const {
    // u or v is red
    if (n->GetSibling() != nullptr)
        // Sibling is not null, make it red"
        n->GetSibling()->color = Node<T>::RED;
}

template <typename T>
void RBtree<T>::delCase4(std::shared_ptr<Node<T>> v, std::shared_ptr<Node<T>> u) const {
    // v is root_, assign the value of u to v, and delete u
    v->val = u->val;
    v->left = v->right = nullptr;
    u->parent = u->right = u->left = nullptr;
    u->val = 0;
}

template <typename T>
void RBtree<T>::delCase5(std::shared_ptr<Node<T>> v, std::shared_ptr<Node<T>> u) const {
    setToChild(v, u);
    v->parent = v->right = v->left = nullptr;
    v->val = 0;
}

template <typename T>
void RBtree<T>::delCase6(std::shared_ptr<Node<T>> u) const { u->color = Node<T>::BLACK; }


template <typename T>
std::shared_ptr<Node<T>> RBtree<T>::getMinElem() {
    auto temp = root_;
    while (temp and temp->left)
        temp = temp->left;

    return temp;
}


template <typename T>
std::shared_ptr<Node<T>> RBtree<T>::getMaxElem() {
    auto temp = root_;
    while (temp and temp->right)
        temp = temp->right;

    return temp;
}
