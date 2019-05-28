#pragma once

namespace crb_dataStructure {
    template <typename T>
    class linkList {
        template <typename Ty>
        friend void displayList(const linkList<Ty>&);

    public:
        linkList();
        ~linkList();

        void clear();
        int length()const { return currentLength; }
        void insert(int i, const T &x);
        void remove(int i);
        int search(const T &x)const;
        T visit(int i)const;

    private:
        struct node{
            T data;
            node *next;

            node(const T &x, node *p = NULL): data(x), next(p) {};
            node(): next(NULL) {};
            ~node() {};
        };

        node *head;
        int currentLength;

    };

    template <typename T>
    void displayList(const linkList<T>&);
}

#include <../src/linkList.cpp>
