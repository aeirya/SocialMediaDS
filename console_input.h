#pragma once

#include "tuple.h"
#include "person.h"
#include "network.h"
#include "linked_list.h"
#include <iostream>

using namespace std;

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

void Network:: readNetwork() {
    // read subjects
    cin >> m;
    string subject;
    for (int i = 0; i < m; ++i) {
        cin >> subject;
        addSubject(subject);
    }
    // read people
    cin >> n;
    for (int i = 0; i < n; ++i) {
        addPerson(readPerson());
    }
    // friendship chain
    int r;
    cin >> r;
    int index; //person
    int d; //# of friends

    auto it = people.begin();
    int counter = 0;
    LinkedList<Tuple>* friendships;
    for (int i = 0; i < r; ++i) {
        friendships = new LinkedList<Tuple>();
        cin >> index >> d;
        while (counter != index) {
            ++it;
            ++counter;
        }
        for (int j = 0; j < d; ++j)
        {
            Tuple friendship = readTuple();
            (*friendships).add(friendship);
        }
        Person* p = &*it;
        p->friendships = *friendships;
    }
}

// used by main

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


