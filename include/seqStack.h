#pragma once

namespace crb_dataStructure 
{
    template <class T>
    class seqStack {
    private:
        T *data;
        int top;
        int maxSize;

        void doubleSpace()
        {
            T *tmp = data;
            data = new T[2 * maxSize];
            for (int i = 0; i < maxSize; ++i)
                data[i] = tmp[i];
            maxSize *= 2;
            delete [] tmp;
        }

    public:
        seqStack(int size = 10)
        {
            data = new T[size];
            maxSize = size;
            top = -1;
        }

        ~seqStack() {delete [] data;}

        bool isEmpty()const {return top == -1;}

        void push(const T &x)
        {
            if(top == maxSize - 1)
                doubleSpace();
            data[++top] = x;
        }

        T pop()
        {
            if(isEmpty()){
                printf("Stack empty!!");
                return -1;
            }
            top--;
            return data[top + 1];
        }

        T _top()const {return data[top];}

    };

};
