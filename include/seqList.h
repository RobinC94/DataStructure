#pragma once

namespace crb_dataStructure {
    template<class T>
    class seqList {
        template<class Ty>
        friend void displayList(const seqList<Ty> &);

    public:
        seqList(int size = 10);

        ~seqList() { delete[] data; }

        void clear() { currentLength = 0; }

        int length() const { return currentLength; }

        void insert(int i, const T &x);

        void remove(int i);

        int search(const T &x) const;

        T visit(int i) const;

    private:
        T *data;
        int currentLength;
        int maxSize;

        void doubleSpace();

    };

    template<class T>
    void displayList(const seqList<T> &);

}

#include "../src/seqList.cpp"


