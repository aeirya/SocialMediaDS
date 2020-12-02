#pragma once

#include "searcher.h"

template <typename T>
using list = LinkedList<T> 

class NamedTuple {
    string label;
    double value;

    public:
    NamedTuple(string label, Tuple tuple) : label(label), value(tuple.intensity) { }
};

using relations = LinkedList<NamedTuple>;

class NetworkScrapper {
    string& getTopic(int i);
    Person& getPerson(int i);
};

class SocialMember {
    string name;
    relations topics;
    relations friends;
    
    public:

    SocialMember(Person person, NetworkScrapper finder) : name(person.name) {
        // convert topics to named tuple
        for (auto topic : person.topics) {
            string label = finder.getTopic(topic.getIndex());
            topics.add(NamedTuple(label, topic));
        }
        // convert friends to named tuple
        for (auto person : person.friendships) {
            string label = finder.getPerson(person.getIndex()).name;;
            friends.add(NamedTuple(label, person));
        }
    }
};

class NetworkScrapper {
    MemoriedSearcher<Person> people;
    MemoriedSearcher<string> topics;

    public:
        NetworkScrapper(Network network) : people(network.people), topics(network.subjects) {}

        string& getTopic(int i) {
            return topics.get(i);
        }

        Person& getPerson(int i) {
            return people.get(i);
        }
};

class SocialNetwork {

    private:
        list<string> subjects;
        list<SocialMember> people;

    public:
        SocialNetwork(Network network) : subjects(network.subjects), people(list<SocialMember> {}) {
            NetworkScrapper finder(network);

            for (Person& person : network.people) {
                auto member = SocialMember(person, finder);
                people.add(member);
            }
        }
};



// class SocialNetworkMerger {
//     SocialNetwork& merge(SocialNetwork& ) {

//     }
// }