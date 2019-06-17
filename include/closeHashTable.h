#pragma once

namespace crb_dataStructure {
    template<typename T>
    class closeHashTable {
        template<typename Ty>
        friend void displayHashTable(const closeHashTable<Ty> &);

    private:
        struct node {
            T data;
            int state;

            node() { state = 0; }
        };

        node *array;
        int size;

    public:
        int (*key)(const T &x);

        static int defaultKey(const T &k) { return int(k); }

        closeHashTable(int length = 101, int(*f)(const T &x) = defaultKey);

        ~closeHashTable() { delete[] array; }

        bool insert(const T &x) const;

        bool find(const T &x) const;

        bool remove(const T &x);

        void rehash();
    };

    template<typename T>
    void displayHashTable(const closeHashTable<T> &);
}

#include "../src/closeHashTable.cpp"