//
// Created by Nick on 11/3/20.
//

#include "linkedlist.h"

template<typename T>
LinkedList<T>::LinkedList() {
    start = nullptr;
    numElements = 0;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    Node<T> *temp;
    temp = start;
    while (temp != nullptr) {
        delete temp;
        temp = temp->next;
    }
}

template<typename T>
Node<T> *LinkedList<T>::createNode(T elem) {
    Node<T> *temp;
    temp = new Node<T>;
    temp->data = elem;
    temp->next = nullptr;

    return temp;
}

template<typename T>
T LinkedList<T>::getDataAtIndex(unsigned index) {
    Node<T> *temp = start;

    if (index < numElements) {
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
    }

    return temp->data;
}

template<typename T>
Node<T> *LinkedList<T>::begin() {
    return start;
}

template<typename T>
Node<T> *LinkedList<T>::end() {
    return nullptr;
}

template<typename T>
bool LinkedList<T>::isEmpty() {
    return numElements == 0;
}

template<typename T>
unsigned LinkedList<T>::size() {
    return numElements;
}

template<typename T>
DSReturn LinkedList<T>::pushFront(T elem) {
    Node<T> *temp;
    temp = createNode(elem);

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

template<typename T>
DSReturn LinkedList<T>::pushBack(T elem) {
    Node<T> *temp;
    Node<T> *ptr = start;

    temp = createNode(elem);

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

template<typename T>
DSReturn LinkedList<T>::insertAt(unsigned index, T elem) {
    Node<T> *ptr;
    ptr = start;

    if (index == 0) {
        pushFront(elem);
    } else if (index == (numElements - 1)) {
        pushBack(elem);
    } else {
        Node<T>* temp = createNode(elem);
        for (int i = 0; i < index; ++i) {
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = temp;
        numElements++;
    }

    return kDSReturnSuccess;
}