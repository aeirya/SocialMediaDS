#include <iostream>
#include "linked_list.h"
// #include "graph.h"
#include "network.h"
// #include "person.h"

using namespace std;

void rc() {
    cout << "reached checkpoint!" << endl;
}

class Tuple {
    public:
        int index;
        double intensity;
        
        Tuple() : index(0), intensity(0) { }
        Tuple(int x, double y) : index(x), intensity(y) { }

        int getIndex() {
            return index;
        }

        int getIntensity() {
            return intensity;
        }
};

Tuple halfenString(string text) {
    char splitter = ':';
    int l = text.length();
    string first;
    string second;
    char current;
    for (int i = 0; i < l; ++i) {
        current = text.at(i);
        if (current == splitter) {
            first = text.substr(0, i);
            second = text.substr(i + 1, l - i);
            break;
        }
    }
    return Tuple(stoi(first), stod(second));   
}

Tuple readTuple() {
    string word;
    cin >> word;
    cout << word << endl;
    return halfenString(word);
}

class Person {
    public:
        string name;
        LinkedList<Tuple> friendships;
        LinkedList<Tuple> topics;
        Network* network;

        Person() : name("") { }
        Person(string name) : name(name) { }

        bool operator==(const Person& other) {
            return name == other.name;
        }

        Person& operator+=(Person& person) {
            if (person == *this) {
                // merge topics
                
                for (auto& topic : person.topics) {
                    person.network;
                }
            }
            return *this;
        }

        Person& operator+(Person& person) {
            
        }    
};

Person readPerson() {
    string name;
    int topic_number;
    cin >> name;
    cin >> topic_number;

    Tuple value;
    LinkedList<Tuple> topics {};

    for (int i = 0; i < topic_number; ++i) {
        value = readTuple();
        topics.add(value);
    }
    Person* p = new Person(name);
    p->topics = topics;
    return *p;
}

void inputNetworks(LinkedList<Network>& networks) {
    // number of networks
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        Network network(i);
        network.readNetwork();
        networks.add(network);
    }
}

void inputQueries() {
    // query num
    int q;
    int qi;
    int k;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        // number of subjects
        cin >> qi;;
        string subject;
        for (int j = 0; j < qi; ++j)
        {   
            cin >> subject;
        }
        cin >> k;
    }
}

void makeSuperNetwork(LinkedList<Network>& networks) {
    Network super {};
    for (Network& net : networks) {
        super += net;
    }
}

int main() {
    LinkedList<Network> networks {};
    inputNetworks(networks);

    inputQueries();

    // // testing the application
    // for (Network& node : networks) {
    //     node.printHI();
    // }

    return 0;
}