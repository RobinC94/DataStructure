#include <iostream>
#include "mySort.h"

template<typename T>
void crb_dataStructure::mySort<T>::simpleInsertSort(T *array, int size) {
    int k;
    T tmp;

    for (int i = 1; i < size; ++i) {
        tmp = array[i];
        for (k = i - 1; tmp < array[k] && k >= 0; --k)
            array[k + 1] = array[k];
        array[k + 1] = tmp;
    }
}

template <typename T>
void crb_dataStructure::mySort<T>::simpleSelectSort(T *array, int size) {
    int k;
    T tmp;

    for (int i = 0; i < size ; ++i) {
        k = i;
        for(int j = i + 1; j < size; ++j)
            if(array[j] < array[k])
                k = j;

        tmp = array[i];
        array[i] = array[k];
        array[k] = tmp;
    }
}

template <typename T>
void crb_dataStructure::mySort<T>::heapSort(T *array, int size) {

}

template<typename T>
void crb_dataStructure::displayArray(T *array, int size) {
    std::cout << '[';
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << ',';
        if (i % 10 == 9) {
            std::cout << "\n ";
        }
    }
    std::cout << ']' << std::endl;
}