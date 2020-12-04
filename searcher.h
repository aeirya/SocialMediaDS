#pragma once

#include "linked_list.h"

template <typename T>
class MemoriedSearcher {
    private:
    LinkedList<T> list;
    NodeIterator<T> it;
    int index;

    public:
    MemoriedSearcher(LinkedList<T>& list) : list(list) {
        index = 0;
        it = list.begin();
    }

    T& get(int i) {
        while (i > index) {
            ++it;
            ++index;
        }
        while (i < index) {
            --it;
            --index;
        }
        return *it;
    }
};