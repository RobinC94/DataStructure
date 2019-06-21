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
    };

    template<typename T>
    void displayArray(T array[], int size);
}

#include "../src/mySort.cpp"