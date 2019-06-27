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

template<typename T>
void crb_dataStructure::mySort<T>::simpleSelectSort(T *array, int size) {
    int k;
    T tmp;

    for (int i = 0; i < size; ++i) {
        k = i;
        for (int j = i + 1; j < size; ++j)
            if (array[j] < array[k])
                k = j;

        tmp = array[i];
        array[i] = array[k];
        array[k] = tmp;
    }
}

template<typename T>
void crb_dataStructure::mySort<T>::heapSort(T *array, int size) {
    int i;
    T tmp;

    for (i = size / 2 - 1; i >= 0; --i)
        percolateDown(array, i, size);
    for (i = size - 1; i > 0; --i) {
        tmp = array[0];
        array[0] = array[i];
        array[i] = tmp;
        percolateDown(array, 0, i);
    }
}

template<typename T>
void crb_dataStructure::mySort<T>::percolateDown(T *array, int hole, int size) {
    int child;
    T tmp = array[hole];

    for (; hole * 2 + 1 < size; hole = child) {
        child = hole * 2 + 1;
        if (child != size - 1 && array[child + 1] > array[child])
            child++;
        if (array[child] > tmp) array[hole] = array[child];
        else break;
    }
    array[hole] = tmp;
}

template<typename T>
void crb_dataStructure::mySort<T>::bubbleSort(T *array, int size) {
    T tmp;
    bool flag;

    for (int i = 1; i < size; ++i) {
        flag = false;
        for (int j = 0; j < size - i; ++j)
            if (array[j + 1] < array[j]) {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                flag = true;
            }
        if (!flag) break;
    }
}

template<typename T>
void crb_dataStructure::mySort<T>::mergeSort(T *array, int size) {
    mergeSort(array, 0, size);
}

template<typename T>
void crb_dataStructure::mySort<T>::mergeSort(T *array, int left, int right) {
    if (left == right - 1)
        return;

    int mid = (left + right - 1) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid + 1, right);
}

template<typename T>
void crb_dataStructure::mySort<T>::merge(T *array, int left, int mid, int right) {
    T *tmp = new T[right - left];

    int i = left, j = mid, k = 0;
    while (i < mid && j < right)
        if (array[i] < array[j])
            tmp[k++] = array[i++];
        else tmp[k++] = array[j++];

    while (i < mid)
        tmp[k++] = array[i++];
    while (j <= right)
        tmp[k++] = array[j++];

    for (i = 0, k = left; k < right;)
        array[k++] = tmp[i++];

    delete[]tmp;
}

template<typename T>
void crb_dataStructure::mySort<T>::quickSort(T *array, int size) {
    quickSort(array, 0, size);
}

template<typename T>
void crb_dataStructure::mySort<T>::quickSort(T *array, int low, int high) {

    if (low >= high) return;

    int initLow = low, initHigh = high;
    T k = array[low];
    do {
        while (low < high && array[high] >= k) --high;
        if (low < high) {
            array[low] = array[high];
            ++low;
        }
        while (low < high && array[low] <= k) ++low;
        if (low < high) {
            array[high] = array[low];
            --high;
        }
    } while (low != high);
    array[low] = k;
    int mid = low;
    quickSort(array, initLow, mid - 1);
    quickSort(array, mid + 1, initHigh);

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