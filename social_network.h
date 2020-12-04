#pragma once

#include "linked_list.h"
#include "searcher.h"
#include "sort.h"

template <typename T>
using list = LinkedList<T>;

class NamedTuple {
    string label;
    double value;

    public:
    NamedTuple() : label(""), value(0) { }
    NamedTuple(string label, Tuple tuple) : label(label), value(tuple.intensity) { }

    // comparison
    bool operator<(NamedTuple& other) {
        return label < other.label;
    }

    // sum operation 
    NamedTuple& operator+=(NamedTuple& other) {
        // didn't do name check
        value += other.value;
        return *this;
    }

    NamedTuple operator+(NamedTuple& other) {
        auto temp = NamedTuple(*this);
        temp += other;
        return temp;
    }

    bool operator==(NamedTuple& other) {
        return label == other.label;
    }
};

using relations = LinkedList<NamedTuple>;

class NetworkScrapper {
    MemoriedSearcher<Person> people;
    MemoriedSearcher<string> topics;

    public:
        NetworkScrapper(Network& network) : people(network.people), topics(network.subjects) {}

        string& getTopic(int i) {
            return topics.get(i);
        }

        Person& getPerson(int i) {
            return people.get(i);
        }
};

class SocialMember {
    string name;
    relations topics {};
    relations friends {};
    
    public:

    SocialMember() { }

    SocialMember(Person person, NetworkScrapper& finder) : name(person.name) {
        // convert topics to named tuple
        for (auto& topic : person.topics) {
            string label = finder.getTopic(topic.getIndex());
            topics.add(NamedTuple(label, topic));
        }
        bubbleSort(topics);
        // LinkedListSorter<NamedTuple>::sort(topics);

        // convert friends to named tuple
        for (auto& person : person.friendships) {
            string label = finder.getPerson(person.getIndex()).name;;
            friends.add(NamedTuple(label, person));
        }
        bubbleSort(friends);
        // LinkedListSorter<NamedTuple>::sort(friends);
    }

    bool operator==(SocialMember& other) {
        return name == other.name;
    }

    bool operator<(SocialMember& other) {
        return name < other.name;
    }

    SocialMember operator+(SocialMember& other) {
        SocialMember person {};
        person.name = name;
        person.topics =
        merge_sorted_linkedlists(topics, other.topics,
            []( NamedTuple& left,  NamedTuple& right) { return left + right; }
        );
        person.friends =
        merge_sorted_linkedlists(friends, other.friends);

        return person;
    }

    void sort() {
        topics.sort();
        friends.sort();
    }
};

class SocialNetwork {

    private:
        list<string> subjects {};
        list<SocialMember> people {};

    public:
        SocialNetwork() {}

        SocialNetwork(Network& network) : subjects(network.subjects), people(list<SocialMember> {}) {
            NetworkScrapper finder(network);

            for (Person& person : network.people) {
                auto member = SocialMember(person, finder);
                people.add(member);
            }
        }

        SocialNetwork operator+(SocialNetwork& other) {
            SocialNetwork net {};

            net.people = 
            merge_sorted_linkedlists(people, other.people,
                [](SocialMember& left, SocialMember& right) { return left + right; }
            );
            
            net.subjects =
            merge_sorted_linkedlists(subjects, other.subjects,
                [](const string& left, const string& right) { return left; }
            );
            
            return net;
        }

        void sort() {
            people.sort();

            for (SocialMember& person : people) {
                person.sort();
            }

            subjects.sort();
        }
};


// class SocialNetworkMerger {
//     SocialNetwork& merge(SocialNetwork& ) {

//     }
// }