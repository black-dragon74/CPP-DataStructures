//
// Created by Nick on 11/3/20.
//

#ifndef CPP_DATASTRUCTURES_LINKEDLIST_HPP
#define CPP_DATASTRUCTURES_LINKEDLIST_HPP

#include <iostream>
#include <iterator>

#include "../includes/libdsutils.hpp"

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

    Node<T> *createNode(T elem) {
        auto *temp = new Node<T>;
        temp->data = elem;
        temp->next = nullptr;

        return temp;
    }

public:
    LinkedList() : numElements(0), start(nullptr) {}

    ~LinkedList() {
        auto *temp = start;

        while (temp != nullptr) {
            delete temp;
            temp = temp->next;
        }
    }

    T getDataAtIndex(unsigned index) {
        auto *temp = start;

        if (index < numElements) {
            for (int i = 0; i < numElements; ++i) {
                temp = temp->next;
            }
        }

        return temp->data;
    }

    Node<T> *begin() { return start; }

    Node<T> *end() { return nullptr; }

    bool isEmpty() { return numElements == 0; }

    unsigned size() { return numElements; }

    DSReturn pushFront(T elem) {
        auto *temp = createNode(elem);

        if (temp == nullptr)
            return kDSReturnNoMem;

        if (start != nullptr) {
            temp->next = start;
            start = temp;
            numElements++;
        } else {
            start = temp;
            numElements++;
        }

        return kDSReturnSuccess;
    }

    DSReturn pushBack(T elem) {
        auto *temp = createNode(elem);
        auto *ptr = start;

        if (temp == nullptr)
            return kDSReturnNoMem;

        if (start == nullptr) {
            start = temp;
            numElements++;
        } else {
            while (ptr->next != nullptr) {
                ptr = ptr->next;
            }
            ptr->next = temp;
            numElements++;
        }

        return kDSReturnSuccess;
    }

    DSReturn popFront() {
        if (start != nullptr) {
            auto *temp = start;
            start = start->next;
            delete temp;
            numElements--;

            return kDSReturnSuccess;
        } else {
            return kDSReturnError;
        }
    }


    DSReturn popBack() {
        auto* temp = start;

        if (temp == nullptr)
            return kDSReturnError;

        if (temp->next == nullptr) {
            delete temp;
            numElements--;

            return kDSReturnSuccess;
        }

        while (temp->next->next != nullptr)
            temp = temp->next;

        delete temp->next;
        temp->next = nullptr;
        numElements--;

        return kDSReturnSuccess;
    }

//    DSReturn insertAt(unsigned index, T elem);
//
//    DSReturn removeAt(unsigned index);
//
//    unsigned searchFor(T elem);
//
//    void merge(Node<T> *nodePtr, unsigned numElems);
//
//    void printList();
//
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

#endif //CPP_DATASTRUCTURES_LINKEDLIST_HPP
