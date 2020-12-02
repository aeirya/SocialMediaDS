#pragma once
#include "linked_list.h"
#include<iostream>

class item {
    public:
        int row, col;
        float val;

        item(int row, int col, float val) : row(row), col(col), val(val) { }

        bool operator> (item other) {
            if (row > other.row) return true;
            return (col > other.col);
        }

        bool operator==(const item other) {
            return other.col == col && other.row == row;
        }

        std::string to_string() {
            return std::to_string(row) + ":" + std::to_string(col) + "->" + std::to_string(val);
        }

        item& operator*=(item& other) {
            if (col == other.row) {
                // std::cout << "multiplying " << to_string() << " by " << other.to_string() << std::endl;
                col = other.col;
                val *= other.val;
                // std::cout << to_string() << std::endl; 
            } else {
                val = 0;
            }
            return *this;
        }

        item operator*(item& other) {
            item temp_f(*this);
            // item temp_s(other);
            temp_f *= other;
            return temp_f;
        }

        item& operator+=(const item& other) {
            if (*this == other) {
                val += other.val;
            }
            else {
                // std::cout << "mmm";
            }
            return *this;
        }

};

using ilist = LinkedList<item>;
using iterator = NodeIterator<item>;

class matrix {
    ilist items {};

    public:
        matrix() {
            items = ilist();
            // add(0,0,0.0f);
        }

        explicit matrix(ilist lst) : items(lst) { }

        matrix& operator+=(matrix& other) {
            for (item& j : other) {
                bool flag = false;
                for (item& i : items) {
                    if (i == j) {
                        i.val += j.val;
                        flag = true;
                        break;
                    }
                }
                if (!flag && j.val != 0) {
                    // std::cout << "adding in plus: " << j.row << j.row << std::endl;
                    add(j);
                }
            }
            return *this;
        }

        // matrix& operator+=(matrix& other) {
        //     auto it = items.begin();
        //     for (item& j : other) {
        //         bool flag = false;
        //         while (true) {
        //             item& i = *it;
        //             if (i == j) {
        //                 i.val += j.val;
        //                 flag = true;
        //                 break;
        //             }
        //             ++it;
        //         }
        //         if (! flag) {
        //             add(j);
        //         }
        //     }
        //     return *this;
        // }
        // matrix& operator+=(matrix& other) {
        //     for (item& i : other) {
        //         add(i);
        //     }
        //     merge_items();
        //     return *this;
        // }

        // matrix operator +(const matrix& left, const matrix& right) {
        //     matrix temp(left);
        //     temp += right;
        //     return temp;
        // }

        matrix operator+(matrix& other) {
            matrix temp(other);
            temp += *this;
            return temp;
        }

        matrix& operator*=(matrix& other) {
            items = (*this * other).items;
            return *this;
        }

        matrix operator*(matrix& other) {
            ilist toAdd {};

            // multiply
            for (item& i : items) {
                for (item& j : other) {
                    item t = i * j;
                    if (t.val != 0) {
                        // adding t
                        bool flag = false;
                        for (item& k : toAdd) {
                            if (k == t) {
                                k += t;
                                flag = true;
                                break;
                            }
                        }
                        // if does not exist yet
                        if (! flag) {
                            toAdd.add(t);
                        }
                    }
                }
            }

            // add

            for (item i : toAdd) {
                // std::cout << "added: " << i.row << i.col << i.val << std::endl;
            }
            // change this
            // matrix z{};
            // matrix* M = new matrix(toAdd);
            // return (z + *M);
            return matrix(toAdd);
        }
        // matrix operator*(matrix& other) {
        //     matrix temp(other);
        //     temp *= *this;
        //     return temp;
        // }

        matrix* operator()(matrix x) const {
            return new matrix();
        }

        void print() {
            for (item& i : items) {
                std::cout << "r: " <<i.row << " c: " << i.col << " val: " << i.val << std::endl;
            }
        }

        void add(int row, int col, float val) {
            items.add(item(row, col, val));
        }

        void add(item& i) {
            items.add(i);
        }

        void merge_items() {
            iterator it = items.begin();
            
            LinkedListSorter<item>().sort(items);
            // while(true) {
            //     //
            // }
        }

        NodeIterator<item> begin() {
            return items.begin();
        }

        NodeIterator<item> end() {
            return items.end();
        }
};

// int main(int argc, char const *argv[])
// {
//     matrix m {};
//     matrix n {};
//     // m(n);
//     // m+n;
//     m.add(1,1,1.0f);
//     m.add(1,0,1.0f);
//     m.add(0,0,4.0f);
//     m.add(0,1, 2.0f);

//     n.add(1,1,1.0f);
//     n.add(0,0,1.0f);
//     n.add(1,0,1.0f);
//     n.add(0,1,1.0f);
//     // n.add(3,3,7.0f);
//     matrix t = n * m;
//     // n *= m;
//     // matrix t = n;
//     // auto i = * iterator().next().next();
//     t.print();
//     return 0;
// }
