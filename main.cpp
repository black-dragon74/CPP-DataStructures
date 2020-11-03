#include "SinglyLinkedList/linkedlist.hpp"

int main() {
    LinkedList<int> l1;

    for (int i = 0; i < 100; ++i) {
        l1.pushFront(i);
    }

    return 0;
}