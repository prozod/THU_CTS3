#ifndef DLIST_H
#define DLIST_H

#include <iostream>

template<typename T>
struct DListElem {
    T data;
    DListElem<T> *next;
    DListElem<T> *prev;
};

template<typename T>
struct DList {
    DListElem<T> *head;
    DListElem<T> *next;
    DListElem<T> *prev;
};

template<typename T>
void initializeDList(DList<T> &dl) {
    dl.head = nullptr;
    dl.next = nullptr;
    dl.prev = nullptr;
}

template<typename T>
void put(DList<T> &dl, const T &val) {
    auto *new_node = new DListElem<T>{val, dl.head, nullptr};
    if (dl.head) {
        dl.head->prev = new_node;
    }
    dl.head = new_node;
    if (dl.prev == nullptr) {
        dl.prev = new_node;
    }
}

template<typename T>
bool get(DList<T> &dl, T &val) {
    if (dl.head == nullptr) {
        return false; // Empty list
    }

    DListElem<T> *last = dl.head;
    while (last->next) {
        last = last->next;
    }

    val = last->data;

    if (dl.head == last) {
        delete dl.head;
        dl.head = dl.next = dl.prev = nullptr;
    } else {
        last->prev->next = nullptr;
        delete last;
    }

    return true;
}

template<typename T>
bool isEmpty(const DList<T> &dl) {
    return dl.head == nullptr;
}

template<typename T>
void print(const DList<T> &dl) {
    DListElem<T> *current = dl.head;

    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

template<typename T>
int length(const DList<T> &dl) {
    int count = 0;
    DListElem<T> *current = dl.head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}
#endif //DLIST_H