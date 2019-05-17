#include "seqList.h"

void crb_dataStructure::seqList::doubleSpace()
{
    T *tmp = data;
    maxSize *= 2;
    data = new T[maxSize];
    for (int i = 0; i < currentLength; ++i) data[i] = tmp[i];
    delete [] tmp;
}

crb_dataStructure::seqList::seqList(int size)
{
    if (size <= 0) {
        printf("size must be positive!");
        return -1;
    }
    data = new T[size];
    maxSize = size;
    currentLength = 0;
}

void crb_dataStructure::seqList::insert(int i, const T &x)
{

}