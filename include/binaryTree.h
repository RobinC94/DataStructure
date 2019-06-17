#pragma once

#include <iostream>

namespace crb_dataStructure {
    template<typename T>
    class BinaryTree {
        template<typename Ty>
        friend void displayTree(const BinaryTree<Ty> &);

    private:
        struct Node {
            Node *left, *right;
            T data;

            Node() : left(NULL), right(NULL) {}

            Node(T x, Node *L = NULL, Node *R = NULL) :
                    data(x), left(L), right(R) {}

            ~Node() {}
        };

        Node *root;

    public:
        BinaryTree() : root(NULL) {}

        BinaryTree(const T &x) { root = new Node(x); }

        ~BinaryTree() { clear(); }

        T getRoot() const { return root->data; }

        bool isEmpty() const { return root == NULL; }

        int size() const { return size(root); }

        int height() const { return height(root); }

        void clear() {
            if (root != NULL)
                clear(root);
            root = NULL;
        }

        void makeTree(const T &x, BinaryTree &lt, BinaryTree &rt) {
            root = new Node(x, lt.root, rt.root);
            lt.root = NULL;
            rt.root = NULL;
        }

        void delLeft() {
            Node *tmp = root->left;
            root->left = NULL;
            clear(tmp);
        }

        void delRight() {
            Node *tmp = root->right;
            root->right = NULL;
            clear(tmp);
        }

        void preOrder() const {
            std::cout << "pre order: ";
            if (root != NULL)
                preOrder(root);
            std::cout << std::endl;
        }

        void postOrder() const {
            std::cout << "post order: ";
            if (root != NULL)
                postOrder(root);
            std::cout << std::endl;
        }

        void midOrder() const {
            std::cout << "mid order: ";
            if (root != NULL)
                midOrder(root);
            std::cout << std::endl;
        }

        void creatTree(const T &flag);

    private:
        void clear(Node *t);

        int size(Node *t) const;

        int height(Node *t) const;

        void preOrder(Node *t) const;

        void postOrder(Node *t) const;

        void midOrder(Node *t) const;
    };

    template<typename T>
    void displayTree(const BinaryTree<T> &);
}

#include "../src/binaryTree.cpp"