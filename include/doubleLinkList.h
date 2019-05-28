#pragma once

namespace crb_dataStructure
{
    template <typename T>
    class doubleLinkList
    {
        template <typename Ty>
        friend void displayDoubleLinkList(const doubleLinkList<Ty>&);
    private:
        struct node{
            T data;
            node* prev;
            node* next;
            node(const T &x, node *p, node *q): data(x), prev(p), next(q) {};
            node(): prev(NULL), next(NULL) {};
            ~node() {};
        };
        node *head, *tail;
        int currentLength;

        node *move(int i)const;

    public:
        doubleLinkList();
        ~doubleLinkList();

        void clear();
        int length()const { return currentLength; }
        bool isEmpty()const { return(head -> next == tail); }
        void insert(int i, const T &x);
        void remove(int i);
        int search(const T &x);
        T visit(int i) const;
    };

    template <typename T>
    void displayDoubleLinkList(const doubleLinkList<T>&);
}

#include "../src/doubleLinkList.cpp"