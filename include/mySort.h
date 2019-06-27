#pragma once

namespace crb_dataStructure {
    template<typename T>
    class mySort {
    public:
        static void simpleInsertSort(T array[], int size);

        static void simpleSelectSort(T array[], int size);

        static void heapSort(T array[], int size);

        static void bubbleSort(T array[], int size);

        static void quickSort(T array[], int size);

        static void mergeSort(T array[], int size);

    private:
        static void percolateDown(T array[], int hole, int size);

        static void mergeSort(T array[], int left, int right);

        static void merge(T array[], int left, int mid, int right);

        static void quickSort(T array[], int low, int high);
    };

    template<typename T>
    void displayArray(T array[], int size);
}

#include "../src/mySort.cpp"