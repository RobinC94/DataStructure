#pragma once

#include <iostream>

namespace crb_dataStructure {
    template<typename T>
    class BinarySearchTree {
        template<typename Ty>
        friend void displayTree(const BinarySearchTree<Ty> &);

    private:
        struct BinaryNode {
            T data;
            BinaryNode *left;
            BinaryNode *right;

            BinaryNode(const T &x, BinaryNode *lt, BinaryNode *rt)
                    : data(x), left(lt), right(rt) {}
        };

        BinaryNode *root;

    public:
        BinarySearchTree(BinaryNode *t = NULL) { root = t; }

        ~BinarySearchTree() {
            if (root != NULL)
                clear(root);
            root = NULL;
        }

        bool isEmpty() const { return root == NULL; }

        bool find(const T &x) const { return find(x, root); }

        void insert(const T &x) { insert(x, root); }

        void remove(const T &x) {
            if (find(x))
                remove(x, root);
            else
                std::cout << "no value!" << std::endl;
        }

    private:
        void clear(BinaryNode *t);

        bool find(const T &x, BinaryNode *t) const;

        void insert(const T &x, BinaryNode *&t);

        void remove(const T &x, BinaryNode *&t);

        void display(const BinaryNode *t) const;
    };

    template<typename T>
    void displayTree(const BinarySearchTree<T> &);
}

#include "../src/binarySearchTree.cpp"