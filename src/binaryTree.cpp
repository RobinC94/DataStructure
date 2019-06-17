#include <iostream>
#include "binaryTree.h"
#include "seqQueue.h"

template<typename T>
void crb_dataStructure::BinaryTree<T>::clear(Node *t) {
    if (t->left != NULL) clear(t->left);
    if (t->right != NULL) clear(t->right);
    delete t;
}

template<typename T>
void crb_dataStructure::BinaryTree<T>::creatTree(const T &flag) {
    seqQueue<Node *> que;
    Node *tmp;
    T x, ldata, rdata;

    std::cout << "input root node: ";
    std::cin >> x;
    root = new Node(x);
    que.enQueue(root);

    while (!que.isEmpty()) {
        tmp = que.deQueue();
        std::cout << std::endl << "input sons of node " << tmp->data << "(" << flag << " represents null node):";
        std::cin >> ldata >> rdata;
        if (ldata != flag) que.enQueue(tmp->left = new Node(ldata));
        if (rdata != flag) que.enQueue(tmp->right = new Node(rdata));
    }

    std::cout << std::endl << "create completed!" << std::endl;
}

template<typename T>
int crb_dataStructure::BinaryTree<T>::size(crb_dataStructure::BinaryTree<T>::Node *t) const {
    if (t == NULL)
        return 0;
    else
        return 1 + size(t->left) + size(t->right);
}

template<typename T>
int crb_dataStructure::BinaryTree<T>::height(crb_dataStructure::BinaryTree<T>::Node *t) const {
    if (t == NULL)
        return 0;
    else {
        int lt = height(t->left), rt = height(t->right);
        return 1 + ((lt > rt) ? lt : rt);
    }
}

template<typename T>
void crb_dataStructure::BinaryTree<T>::preOrder(crb_dataStructure::BinaryTree<T>::Node *t) const {
    if (t != NULL) {
        std::cout << t->data << ' ';
        preOrder(t->left);
        preOrder(t->right);
    }
}

template<typename T>
void crb_dataStructure::BinaryTree<T>::postOrder(crb_dataStructure::BinaryTree<T>::Node *t) const {
    if (t != NULL) {
        postOrder(t->left);
        postOrder(t->right);
        std::cout << t->data << ' ';
    }
}

template<typename T>
void crb_dataStructure::BinaryTree<T>::midOrder(crb_dataStructure::BinaryTree<T>::Node *t) const {
    if (t != NULL) {
        midOrder(t->left);
        std::cout << t->data << ' ';
        midOrder(t->right);
    }
}