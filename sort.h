#pragma once
#include "linked_list.h"

// template <typename T>
// void swap(Node<T>& first, Node<T>& second) {
//     Node<T>* pre = first.previous;
//     Node<T>* nex = first.next;

//     first.previous = second.previous;
//     first.next = second.next;

//     second.previous = pre;
//     second.next = nex;
// }

template <typename T>
void swapNodeValues(Node<T>& first, Node<T>& second) {
    auto temp = first.value;
    first.value = second.value;
    second.value = temp;
}

template <typename T>
void bubbleSort(LinkedList<T>& list) {
    bool swapped;
    do {
        swapped = false;
        auto it = list.begin();
        while (it != list.end()) {
            auto in_it = it;
            ++in_it;
            while (in_it != list.end()) {
                auto a = *it;   
                auto b = *in_it;
                if (b < a) {
                    swapNodeValues<T>(it.getCurrent(), in_it.getCurrent());
                    swapped = true;
                    break;
                }
                ++in_it;
            }
            ++it;
        }
    } while (swapped);
}

template <typename T>
LinkedList<T> bubbleSorted(LinkedList<T> list) {
    bubbleSort(list);
    return list;
}

// for testing 
// int main(int argc, char const *argv[])
// {
//     LinkedList<int> l {};
//     l.add(1);
//     l.add(3);
//     l.add(2);
//     l.add(2);
//     l.add(0);

//     auto l2 = bubbleSort(l);

//     for(auto& i : l2) {
//         std::cout << i << std::endl;
//     }
//     return 0;
// }
