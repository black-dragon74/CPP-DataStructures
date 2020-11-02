//
// Created by Nick on 11/3/20.
//

#ifndef CPP_DATASTRUCTURES_LINKEDLIST_H
#define CPP_DATASTRUCTURES_LINKEDLIST_H

#include <iostream>
#include <iterator>

#include "../liberr.h"

using namespace std;

template<class T>
struct Node {
    T data;
    Node *next;
};

template<class T>
class LinkedList {
private:
    Node<T> *start;
    unsigned numElements;

    Node<T> *createNode(T elem);

public:
    LinkedList();

    ~LinkedList();

    T getDataAtIndex(unsigned index);

    Node<T> *begin();

    Node<T> *end();

    bool isEmpty();

    unsigned size();

    DSReturn pushFront(T elem);

    DSReturn pushBack(T elem);

    DSReturn popFront();

    DSReturn popBack();

    DSReturn insertAt(unsigned index, T elem);

    DSReturn removeAt(unsigned index);

    unsigned searchFor(T elem);

    void merge(Node<T> *nodePtr, unsigned numElems);

    void printList();

    class iterator : public std::iterator<std::forward_iterator_tag, Node<T> *> {
        Node<T> *currElem;
    public:
        explicit iterator(Node<T> *temp) : currElem(temp) {}

        iterator(const iterator &myitr) : currElem(myitr) {}

        iterator &operator++() {
            currElem = currElem->next;
            return *this;
        }

        iterator operator++(int) {
            iterator result(*this);
            ++*this;
            return result;
        }

        bool operator==(const iterator &rhs) {
            return currElem == rhs.currElem;
        }

        bool operator!=(const iterator &rhs) {
            return currElem != rhs.currElem;
        }

        T &operator*() {
            return currElem->data;
        }

        T *operator->() {
            return &currElem->data;
        }
    };
};

#endif //CPP_DATASTRUCTURES_LINKEDLIST_H
