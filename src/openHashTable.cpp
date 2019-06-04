#include "openHashTable.h"
#include <iostream>

template <typename T>
crb_dataStructure::openHashTable<T>::openHashTable(int length, int (*f)(const T &))
{
    size = length;
    array = new node*[size];
    key = f;
    for(int i = 0; i < size; ++i)
        array[i] = new node;
}

template <typename T>
crb_dataStructure::openHashTable<T>::~openHashTable()
{
    node *p, *q;

    for(int i = 0; i < size; ++i)
    {
        p = array[i];
        do
        {
            q = p -> next;
            delete p;
            p = q;
        }while (p != NULL);
    }

    delete [] array;
}

template <typename T>
bool crb_dataStructure::openHashTable<T>::insert(const T &x)
{
    int pos;
    node *p;

    pos = key(x) % size;
    p = array[pos] -> next;

    while(p != NULL && !(p -> data == x))
        p = p -> next;
    if(p == NULL)
    {
        p = new node(x);
        p -> next = array[pos] -> next;
        array[pos] -> next = p;
        return true;
    }

    return false;
}

template <typename T>
bool crb_dataStructure::openHashTable<T>::find(const T &x) const
{
    int pos;
    node *p;

    pos = key(x) % size;
    p = array[pos] -> next;
    while(p != NULL && !(p -> data == x)) p = p -> next;

    if(p != NULL)
        return true;
    else
        return false;

}

template <typename T>
bool crb_dataStructure::openHashTable<T>::remove(const T &x)
{
    int pos;
    node *p, *q;

    pos = key(x) % size;
    p = array[pos];

    while(p -> next != NULL && !(p -> next -> data == x))
        p = p -> next;
    if(p -> next == NULL)
        return false;
    else
    {
        q = p -> next;
        p -> next = q -> next;
        delete q;
        return true;
    }
}

template <typename T>
void crb_dataStructure::displayHashTable(const crb_dataStructure::openHashTable<T> &table)
{
    std::cout << "table:" << std::endl;

    for(int i = 0; i < table.size; ++i)
    {
        auto *p = table.array[i] -> next;
        if (p == NULL)
            continue;

        std::cout << "  " << i << ":";
        int count = 0;
        while (p != NULL)
        {
            count++;
            std::cout << p -> data << ',';
            p = p -> next;
            if (count % 10 == 9){
                std::cout << std::endl << '\t';
            }
        }
        std::cout << ';' << std::endl;
    }
}