#include "doubleLinkList.h"
#include <iostream>

template <typename T>
crb_dataStructure::doubleLinkList<T>::doubleLinkList()
{
    head = new node;
    head -> next = tail = new node;
    tail -> prev = head;
    currentLength = 0;
}

template <typename T>
crb_dataStructure::doubleLinkList<T>::~doubleLinkList()
{
    clear();
    delete head;
    delete tail;
}

template <typename T>
typename crb_dataStructure::doubleLinkList<T>::node* crb_dataStructure::doubleLinkList<T>::move(int i)const
{
    if (i < 0 || i > currentLength){
        std::cout << "invalid position!" << std::endl;
        return NULL;
    }
    node* p = head->next;
    while(i--) p = p -> next;

    return p;
}

template <typename T>
void crb_dataStructure::doubleLinkList<T>::clear()
{
    node *p = head -> next, *q;
    head -> next = tail;
    tail -> prev = head;
    while (p != tail)
    {
        q = p;
        p = p-> next;
        delete q;
    }
    currentLength = 0;
}

template <typename T>
void crb_dataStructure::doubleLinkList<T>::insert(int i, const T &x)
{
    node *pos, *tmp;
    pos = move(i);
    if (pos == NULL) return;

    tmp = new node(x, pos -> prev, pos);
    pos -> prev -> next = tmp;
    pos -> prev = tmp;
    ++currentLength;
}

template <typename T>
void crb_dataStructure::doubleLinkList<T>::remove(int i)
{
    node *pos = move(i);
    if (pos == NULL || pos == tail) return;

    pos -> prev -> next = pos -> next;
    pos -> next -> prev = pos -> prev;
    delete pos;
    --currentLength;
}

template <typename T>
int crb_dataStructure::doubleLinkList<T>::search(const T &x)
{
    node *p = head -> next;
    int i = 0;

    while(p != tail && p -> data != x)
    {
        p = p -> next;
        ++i;
    }
    if(p == tail) return -1;
    else return i;
}

template <typename T>
T crb_dataStructure::doubleLinkList<T>::visit(int i) const
{
    node *p = move(i);
    if (p == NULL || p == tail)
        return -1;
    return p -> data;
}

template <typename T>
void crb_dataStructure::displayList(const crb_dataStructure::doubleLinkList<T> &list)
{
    if (list.length() == 0){
        std::cout << "empty list." << std::endl;
        return;
    }
    std::cout << '[';
    auto *p = list.head;
    for (int i = 0; i < list.currentLength; ++i) {
        p = p -> next;
        if (p == list.tail) break;
        std::cout << p -> data << ',';
        if (i % 10 == 9)
            std::cout << "\n ";
    }
    std::cout << ']' << std::endl;
}
