#include "seqList.h"
#include <cstdio>

template<class T>
void crb_dataStructure::seqList<T>::doubleSpace() {
    T *tmp = data;
    maxSize *= 2;
    data = new T[maxSize];
    for (int i = 0; i < currentLength; ++i) data[i] = tmp[i];
    delete[] tmp;
}

template<class T>
crb_dataStructure::seqList<T>::seqList(int size) {
    if (size <= 0) {
        std::cout << "size must be positive!" << std::endl;
        return;
    }
    data = new T[size];
    maxSize = size;
    currentLength = 0;
}

template<class T>
void crb_dataStructure::seqList<T>::insert(int i, const T &x) {
    if (i < 0 || i > currentLength) {
        std::cout << "invalid position!" << std::endl;
        return;
    }
    if (currentLength == maxSize) doubleSpace();
    for (int j = currentLength; j > i; --j) data[j] = data[j - 1];
    data[i] = x;
    ++currentLength;
}

template<class T>
void crb_dataStructure::seqList<T>::remove(int i) {
    if (i < 0 || i > currentLength) {
        std::cout << "invalid position!" << std::endl;
        return;
    }
    for (int j = i; j < currentLength - 1; ++j)
        data[j] = data[j + 1];
    currentLength--;
}

template<class T>
int crb_dataStructure::seqList<T>::search(const T &x) const {
    int i;
    for (i = 0; i < currentLength && data[i] != x; ++i);
    if (i == currentLength)
        return -1;
    else
        return i;
}

template<class T>
T crb_dataStructure::seqList<T>::visit(int i) const {
    if (i < 0 || i > currentLength - 1) {
        std::cout << "invalid position!" << std::endl;
        return -1;
    }
    return data[i];
}

//template <class T>
//std::ostream& crb_dataStructure::print(std::ostream &os, const crb_dataStructure::seqList<T> &list){
//    if (list.isEmply){
//        os << "emply list\n";
//        return os;
//    }
//    os << '[';
//    for (int i = 0; i < list.currentLength; ++i) {
//        os << list.data[i] << ',';
//    }
//    os << ']';
//    return os;
//}

template<class T>
void crb_dataStructure::displayList(const crb_dataStructure::seqList<T> &list) {
    if (list.length() == 0) {
        std::cout << "empty list." << std::endl;
        return;
    }

    std::cout << '[';
    for (int i = 0; i < list.currentLength; ++i) {
        std::cout << list.data[i] << ',';
        if (i % 10 == 9)
            std::cout << "\n ";
    }
    std::cout << ']' << std::endl;
}
