#include "linkList.h"
#include <iostream>

template <typename T>
crb_dataStructure::linkList<T>::linkList()
{
    head = new node;
    currentLength = 0;
}

template <typename T>
crb_dataStructure::linkList<T>::~linkList()
{
    clear();
    delete(head);
}

template <typename T>
void crb_dataStructure::linkList<T>::clear()
{
    node *p = head -> next, *q;
    head -> next = NULL;
    while (p != NULL){
        q = p;
        p = p -> next;
        delete q;
    }
    currentLength = 0;
}

template <typename T>
void crb_dataStructure::linkList<T>::insert(int i, const T &x)
{
    if (i < 0 || i > currentLength){
        std::cout << "invalid position!" << std::endl;
        return;
    }
    node *p = head, *tmp;
    for (int j = 0; j < i; ++j)
        p = p -> next;
    tmp = p;
    p = new node(x, tmp ->next);
    tmp -> next = p;

    ++currentLength;
}

template <typename T>
void crb_dataStructure::linkList<T>::remove(int i)
{
    if (i < 0 || i > currentLength){
        std::cout << "invalid position!" << std::endl;
        return;
    }
    node *p = head, *tmp;
    for(int j = 0; j < i; ++j)
        p = p -> next;
    tmp = p -> next;
    p -> next = tmp -> next;
    delete tmp;
    currentLength--;
}

template <typename T>
int crb_dataStructure::linkList<T>::search(const T &x) const
{
    node *p = head -> next;
    int i = 0;
    while (p != NULL && p -> data != x)
    {
        p = p -> next;
        ++i;
    }
    if(p == NULL) return -1;
    else return i;
}

template <typename T>
T crb_dataStructure::linkList<T>::visit(int i)const
{
    if (i < 0 || i > currentLength){
        std::cout << "invalid position!" << std::endl;
        return;
    }
    node *p = head -> next;
    for (int j = 0; j < i; ++j)
        p = p -> next;
    return p -> data;
}

template <typename T>
void crb_dataStructure::displayLinkList(const crb_dataStructure::linkList<T> &list)
{
    if (list.length() == 0){
        std::cout << "empty list." << std::endl;
        return;
    }
    std::cout << "h->";
    auto *p = list.head;
    for (int i = 0; i < list.currentLength; ++i) {
        p = p -> next;
        if (p == NULL) break;
        std::cout << p -> data << "->";
        if (i % 10 == 9)
            std::cout << "\n   ";
    }
    std::cout << std::endl;
}

