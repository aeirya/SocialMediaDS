#pragma once
#include "person.h"
#include "linked_list.h"

class Network {
    public:
        // network number
        int index;
        // network subjects
        int m;
        // number of people
        int n;

        Network() { }

        Network(int index) : index(index) { }

        Network& operator+=(Network& net) {
            return *this; 
        }

        void readNetwork();

        bool contains(Person& person) {
            // for (Person& p : people) {
            //     if (p.name.compare(person.name)) return true;
            // }
            // person.
            // to be implemented later
            return false;
        }

        Network& merge(Network& other) {
            Network dest(*this);

            // first merge subjects
            LinkedList<string> merged = merge_sorted_linkedlists(
                subjects, other.subjects, 
                [](const string left, const string right) { return left; }
                );

            // find new indices of each subject in others
            LinkedList<int> newIndices {};
            auto it = other.subjects.begin();
            while(it != other.subjects.end()) {
                int i = 0;
                for (string subject : subjects) {
                    if (*it == subject) {
                        newIndices.add(i);
                        ++i;
                        ++it;
                    }
                }
            }
            
            // for each person update topic indices
            LinkedList<Person> newPeople {};
            for (Person p : other.people) {
                auto indice = newIndices.begin();
                for (Tuple& topic : p.topics) {
                    topic.index = newIndices.at(topic.index);
                }
            }
            
            for (Person& p : other.people) {
                
            }
            return dest;
        }

        LinkedList<string> subjects {};
        LinkedList<Person> people {};

        void addSubject(string subject) {
            subjects.add(subject);
        }

        void addPerson(Person person) {
            // person.network = this;
            people.add(person);
        }
};