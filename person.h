#pragma once

#include "linked_list.h"
#include "tuple.h"

using namespace std;

class Person {
    public:
        string name;
        LinkedList<Tuple> friendships;
        LinkedList<Tuple> topics;
        // Network* network;

        Person() : name("") { }
        Person(string name) : name(name) { }

        bool operator==(const Person& other) {
            return name == other.name;
        }

        Person& operator+=(Person& person) {
            if (person == *this) {
                // merge topics
                
                for (auto& topic : person.topics) {
                    // person.network;
                }
            }
            return *this;
        }

        // Person& operator+(Person& person) {
            
        // }    
};