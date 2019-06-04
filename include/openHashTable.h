#pragma once

namespace crb_dataStructure
{
    template <typename T>
    class openHashTable {
        template <typename Ty>
        friend void displayHashTable(const openHashTable<Ty>&);

    private:
        struct node {
            T data;
            node *next;

            node(const T &x): data(x), next(NULL) {}
            node(): data(0), next(NULL) {}
        };

        node **array;
        int size;

    public:
        int(*key)(const T &x);

        static int defaultKey(const T &k) { return int(k); }

        openHashTable(int length = 101, int (*f)(const T &x) = defaultKey);

        ~openHashTable();

        bool insert(const T &x);

        bool find(const T &x)const ;

        bool remove(const T &x);
    };

    template <typename T>
    void displayHashTable(const openHashTable<T> &table);
}

#include "../src/openHashTable.cpp"
