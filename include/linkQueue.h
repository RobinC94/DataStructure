#pragma once

namespace crb_dataStructure {
    template<typename T>
    class linkQueue {
        template<typename Ty>
        friend void displayQueue(const linkQueue<Ty> &);

    private:
        struct node {
            T data;
            node *next;

            node() : next(NULL) {}

            node(const T &x, node *p) : data(x), next(p) {}

            ~node() {}
        };

        node *front, *rear;

    public:
        linkQueue() { front = rear = NULL; }

        ~linkQueue() {
            node *tmp;
            while (front != NULL) {
                tmp = front;
                front = front->next;
                delete tmp;
            }
        }

        bool isEmpty() const { return front == NULL; }

        void enQueue(const T &x) {
            if (rear == NULL)
                front = rear = new node(x, NULL);
            else {
                rear->next = new node(x, NULL);
                rear = rear->next;
            }
        }

        T deQueue() {
            if (isEmpty()) {
                std::cout << "Queue empty!" << std::endl;
                return -1;
            }
            node *tmp = front;
            T value = front->data;

            front = front->next;

            if (front == NULL) rear = NULL;
            delete tmp;

            return value;
        }

        T getHead()const {
            if (isEmpty()) {
                std::cout << "Queue empty!" << std::endl;
                return -1;
            }
            return front->data;
        }
    };

    template <typename T>
    void displayQueue(const linkQueue<T> &queue)
    {
        if (queue.isEmpty()) {
            std::cout << "empty queue." << std::endl;
            return;
        }
        auto *p = queue.front;
        std::cout << "h: ";
        for (int i = 0; ; ++i) {
            if (p == NULL) break;
            std::cout << p -> data << ',';
            if (i % 10 == 9)
                std::cout << "\n   ";
            p = p -> next;
        }
        std::cout << " :e" << std::endl;
    }

}