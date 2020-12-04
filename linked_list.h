#pragma once

template <typename T>
class LinkedListSorter;

template<typename T>
class NodeIterator;

template <typename T>
class LinkedList {    

    public:
        class Node
        {
            public:

            T value;
            Node* next;
            Node* previous;

            void addNext(Node& node) {
                next = &node;
                node.previous = *this;
            }
        };

        LinkedList() : m_head(0), m_tail(0) {}
        
        ~LinkedList() {
            // Node& node = m_head;
            // while (node.next) {

            // }

        }


        void add(const T& value) {
            
            Node* node = new Node { value, 0, m_tail };
            // node->value = value;
            // node->next = 0;

            if (!m_head) {
                m_head = node;
                m_tail = node;
            } else {
                m_tail->next = node;
                m_tail = node;
            }
        }

        bool contains(const T& value) {
            for (T item : *this) {
                if (item == value) {
                    return true;
                }
            }
            return false;
        }

        T& at(int i) {
            auto it = begin();
            while (i>0) {
                ++it;
                --i;
            }
            return *it;
        }

        // sort
        void sort() {
            LinkedListSorter<T>::sort(*this);
        }

        // enumeration

        Node* head() {
            return this->m_head;
        }

        NodeIterator<T> begin() {
            return NodeIterator<T>(*m_head);
        }

        NodeIterator<T> end() const {
            return NodeIterator<T>();
        }

    private:
        Node *m_head, *m_tail;
};

template<typename T>
using Node = typename LinkedList<T>::Node;

template<typename T>
class NodeIterator {
    private:
        Node<T>* node;

    public:
        NodeIterator(const LinkedList<T> &list) : node(list.head()) { }
        NodeIterator(Node<T> &node) : node(&node) { }
        NodeIterator() : node(0) { }

    // NodeIterator* next() {
    //     return *this++;
    // }

    NodeIterator &operator++() {
        this->node = this->node->next;
        return *this;
    }

    NodeIterator &operator--() {
        this->node = this->node->previous;
        return *this;
    }

    NodeIterator operator++(int) {
        NodeIterator t(*this);
        this->node = this->node->next;
        return t;
    }

    T& operator*() {
        return this->node->value;
    }

    bool operator!=(const NodeIterator& other) const {
        return other.node != this->node;
    } 

    bool operator==(const NodeIterator<T>& other) {
        return this->node == other.node;
    }

    Node<T>& getCurrent() {
        return *node;
    }
};

template<typename T>
class LinkedListSorter {
    
    static void swap_with_previous(Node<T>& node) {
        Node<T>* p = node.previous;
        Node<T>* pp = p->previous;
        Node<T>* n = node.next;
        p->next = n;
        p->previous = &node;
        node.next = p;
        node.previous = pp;
    }

    public:

    static void sort(LinkedList<T>& list) {
        auto it = list.begin();
        while (it != list.end()) {
            auto& previous = *it;
            auto& pre_node = it.getCurrent();
            ++it;
            if (it == list.end()) break;
            auto& current = *it;
            auto& curr_node = it.getCurrent();

            if (current < previous) {
                swap_with_previous(curr_node);
            }
        }
    }
};

template<typename T, typename Merger>
LinkedList<T> merge_sorted_linkedlists(LinkedList<T>& to, LinkedList<T>& from, Merger merger) {
    auto toIt = to.begin();
    auto fromIt = from.begin();
    LinkedList<T> merged {};

    while(toIt != to.end() || fromIt != from.end()) {
        if (toIt == to.end()) {
            while (fromIt != from.end()) {
                merged.add(*fromIt);
                ++fromIt;
            }
            break;
        }
        else if (fromIt == from.end()){
            while (toIt != to.end()) {
                merged.add(*toIt);
                ++toIt;
            }
            break;
        } else {
            auto toVal = *toIt;
            auto fromVal = *fromIt;

            if (fromVal == toVal) {
                merged.add(merger(fromVal, toVal));
                ++toIt;
                ++fromIt;
            } else {
                auto& ptr = (fromVal < toVal) ? fromIt : toIt;
                merged.add(*ptr);
                ++(ptr);
            }
            to.end();
        }
    }
    return merged;
}

template<typename T>
LinkedList<T> merge_sorted_linkedlists(LinkedList<T>& to, LinkedList<T>& from) {
    return merge_sorted_linkedlists(to, from, [](T& left, T& right) { return left + right; });
}

// int main() {
    
//     LinkedList<int> list {};
//     list.add(1);
//     list.add(3);
//     list.add(4);


//     for (int i : list) {
//         std::cout << i;
//     }

//     auto& x = *list.begin();
//     x = 10;

//     for (int i : list) {
//         std::cout << i;
//     }

//     return 0;
// }