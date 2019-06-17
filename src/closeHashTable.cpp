#include "closeHashTable.h"
#include <iostream>

template<typename T>
crb_dataStructure::closeHashTable<T>::closeHashTable(int length, int (*f)(const T &)) {
    size = length;
    array = new node[size];
    key = f;
}

template<typename T>
bool crb_dataStructure::closeHashTable<T>::insert(const T &x) const {
    int initPos, pos;
    int offset = 0;

    initPos = pos = key(x) % size;
    do {
        if (array[pos].state != 1) {
            array[pos].data = x;
            array[pos].state = 1;
            return true;
        }
        if (array[pos].state == 1 && array[pos].data == x)
            return false;
        offset++;
        pos = (pos + offset * offset) % size;
    } while (pos != initPos);

    return false;
}

template<typename T>
bool crb_dataStructure::closeHashTable<T>::find(const T &x) const {
    int initPos, pos;
    int offset = 0;
    initPos = pos = key(x) % size;
    do {
        if (array[pos].state == 0) return false;
        if (array[pos].state == 1 && array[pos].data == x)
            return true;
        offset++;
        pos = (pos + offset * offset) % key(x);
    } while (pos != initPos);

    return false;
}

template<typename T>
bool crb_dataStructure::closeHashTable<T>::remove(const T &x) {
    int initPos, pos;
    int offset = 0;
    initPos = pos = key(x) % size;
    do {
        if (array[pos].state == 0) return false;
        if (array[pos].state == 1 && array[pos].data == x) {
            array[pos].state = 2;
            return true;
        }
        offset++;
        pos = (pos + offset) % key(x);
    } while (pos != initPos);

    return false;
}

template<typename T>
void crb_dataStructure::closeHashTable<T>::rehash() {
    node *tmp = array;
    array = new node[size];

    for (int i = 0; i < size; ++i) {
        if (tmp[i].state == 1)
            insert(tmp[i].data);
    }

    delete[] tmp;
}

template<typename T>
void crb_dataStructure::displayHashTable(const crb_dataStructure::closeHashTable<T> &table) {
    std::cout << "table:" << std::endl;

    for (int i = 0; i < table.size; ++i) {
        if (table.array[i].state == 1) {
            std::cout << "  " << i << ':' << table.array[i].data << ';' << std::endl;
        }
    }

}