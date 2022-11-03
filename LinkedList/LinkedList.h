
# ifndef LINKEDLIST_H
# define LINKEDLIST_H

# include "List.h"
# include <cstddef>

template <typename T>
struct Node
{
    T data;
    Node* next;
};

template <typename T>
class LinkedList: public List<T>
{
    private:
        Node<T> *last;
    public:
        LinkedList() : last { NULL } {};
        void append(T);
        T head();
        T tail();
        int size();
        bool isEmpty();
        void printList();
};

# endif
