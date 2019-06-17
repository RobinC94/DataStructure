#pragma once

namespace crb_dataStructure {
    template<typename T>
    class linkStack {
        template<typename Ty>
        friend void displayStack(const linkStack<Ty> &);

    private:
        struct node {
            T data;
            node *next;

            node() : next(NULL) {}

            node(const T &x, node *n = NULL) : data(x), next(n) {};
        };

        node *top;

    public:
        linkStack() { top = NULL; }

        ~linkStack() {
            node *tmp;
            while (top != NULL) {
                tmp = top;
                top = top->next;
                delete tmp;
            }
        }

        bool isEmpty() const { return top == NULL; }

        void push(const T &x) {
            node *tmp = new node(x, top);
            top = tmp;
        }

        T pop() {
            if (isEmpty()) {
                std::cout << "Stack empty!" << std::endl;
                return -1;
            }
            node *tmp = top;
            T x = tmp->data;
            top = top->next;
            delete tmp;
            return x;
        }

        T _top() const {
            if (isEmpty()) {
                std::cout << "Stack empty!" << std::endl;
                return -1;
            }
            return top->data;
        }

    };

    template<typename T>
    void displayStack(const linkStack<T> &stack) {
        if (stack.isEmpty()) {
            std::cout << "empty stack." << std::endl;
            return;
        }
        auto *p = stack.top;
        std::cout << "t: ";
        for (int i = 0;; ++i) {
            if (p == NULL) break;
            std::cout << p->data << ',';
            if (i % 10 == 9)
                std::cout << "\n   ";
            p = p->next;
        }
        std::cout << std::endl;
    }
}