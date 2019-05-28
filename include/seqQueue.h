#pragma once

#include <iostream>

namespace  crb_dataStructure
{
    template <class T>
    class seqQueue
    {
        template <class Ty>
        friend void displayQueue(const seqQueue<Ty>&);
    private:
        T *data;
        int maxSize;
        int front, rear;

        void doubleSpace()
        {
            T *tmp = data;
            data = new T[maxSize * 2];
            for(int i = 1; i < maxSize; ++i)
                data[i] = tmp[(front + i) % maxSize];

            front = 0; rear = maxSize - 1;
            maxSize *= 2;
            delete tmp;
        }

    public:
        seqQueue(int size = 10)
        {
            data = new T[size];
            maxSize = size;
            front = rear = 0;
        }

        ~seqQueue() { delete [] data; }

        bool isEmpty() const { return front == rear; }

        void enQueue(const T &x)
        {
            if ((rear + 1) % maxSize == front) doubleSpace();
            rear = (rear + 1) % maxSize;
            data[rear] = x;
        }

        T deQueue()
        {
            front = (front + 1) % maxSize;
            return data[front];
        }

        T getHead() { return data[(front + 1) % maxSize]; }
    };

    template <class T>
    void displayQueue(const seqQueue<T> &queue){
        if (queue.isEmpty()) {
            std::cout << "empty queue.\n";
            return;
        }

        std::cout << "h: ";
        for (int i = queue.front+1 ; i != queue.rear ; ++i) {
            i = i % queue.maxSize;
            std::cout << queue.data[i] << ',';
            if((i-queue.front-1) % 10 == 9)
                std::cout << "\n   ";
        }
        std::cout << " :e" << std::endl;
    }
}