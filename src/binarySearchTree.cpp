#include "binarySearchTree.h"
#include <iostream>

template<typename T>
void crb_dataStructure::BinarySearchTree<T>::clear(crb_dataStructure::BinarySearchTree<T>::BinaryNode *t) {
    if (t->left != NULL)
        clear(t->left);
    if (t->right != NULL)
        clear(t->right);
    delete t;
}

template<typename T>
bool crb_dataStructure::BinarySearchTree<T>::find(const T &x,
                                                  crb_dataStructure::BinarySearchTree<T>::BinaryNode *t) const {
    if (t == NULL)
        return false;
    else if (x < t->data)
        return find(x, t->left);
    else if (x > t->data)
        return find(x, t->right);
    else
        return true;
}

template<typename T>
void crb_dataStructure::BinarySearchTree<T>::insert(const T &x,
                                                    crb_dataStructure::BinarySearchTree<T>::BinaryNode *&t) {
    if (t == NULL)
        t = new BinaryNode(x, NULL, NULL);
    else if (x < t->data)
        insert(x, t->left);
    else if (x > t->data)
        insert(x, t->right);
}

template<typename T>
void crb_dataStructure::BinarySearchTree<T>::remove(const T &x,
                                                    crb_dataStructure::BinarySearchTree<T>::BinaryNode *&t) {
    if (t == NULL)
        return;
    if (x < t->data)
        remove(x, t->left);
    else if (x > t->data)
        remove(x, t->right);
    else if (t->left != NULL && t->right != NULL) {
        BinaryNode *tmp = t->right;
        while (tmp->left != NULL) tmp = tmp->left;
        t->data = tmp->data;
        remove(t->data, t->right);
    } else {
        BinaryNode *tmp2 = t;
        t = (t->left != NULL) ? t->left : t->right;
        delete tmp2;
    }
}

template<typename T>
void crb_dataStructure::BinarySearchTree<T>::display(
        const crb_dataStructure::BinarySearchTree<T>::BinaryNode *t) const {
    if (t != NULL) {
        display(t->left);
        std::cout << t->data << ',';
        display(t->right);
    }
}

template<typename T>
void crb_dataStructure::displayTree(const crb_dataStructure::BinarySearchTree<T> &tree) {
    if (tree.root == NULL)
        std::cout << "tree is emply" << std::endl;
    if (tree.root != NULL) {
        std::cout << "tree: ";
        tree.display(tree.root);
        std::cout << std::endl;
    }
}
