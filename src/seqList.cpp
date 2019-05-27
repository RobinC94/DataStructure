#include "seqList.h"
#include <cstdio>

template <class T>
void crb_dataStructure::seqList<T>::doubleSpace()
{
    T *tmp = data;
    maxSize *= 2;
    data = new T[maxSize];
    for (int i = 0; i < currentLength; ++i) data[i] = tmp[i];
    delete [] tmp;
}

template <class T>
crb_dataStructure::seqList<T>::seqList(int size)
{
    if (size <= 0) {
        printf("size must be positive!");
        return;
    }
    data = new T[size];
    maxSize = size;
    currentLength = 0;
}

template <class T>
void crb_dataStructure::seqList<T>::insert(int i, const T &x)
{
    if (i < 0 || i > currentLength) {
        printf("invalid position!");
        return;
    }
    if (currentLength == maxSize) doubleSpace();
    for(int j = currentLength; j > i; --j) data[j] = data[j - 1];
    data[i] = x;
    ++currentLength;
}

template <class T>
void crb_dataStructure::seqList<T>::remove(int i)
{
    if (i < 0 || i > currentLength) {
        printf("invalid position!");
        return;
    }
    for (int j = i; j < currentLength - 1; ++j)
        data[j] = data[j + 1];
    currentLength--;
}

template <class T>
int crb_dataStructure::seqList<T>::search(const T &x) const
{
    int i;
    for(i = 0; i < currentLength && data[i] != x; ++i);
    if(i == currentLength)
        return -1;
    else
        return i;
}

template <class T>
T crb_dataStructure::seqList<T>::visit(int i) const
{
    if (i < 0 || i > currentLength - 1) {
        printf("invalid position!");
        return 0;
    }
    return data[i];
}
