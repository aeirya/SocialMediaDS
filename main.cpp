#include <iostream>
#include "linked_list.h"
// #include "graph.h"
#include "network.h"
// #include "person.h"
#include "social_network.h"


using namespace std;

void rc() {
    cout << "reached checkpoint!" << endl;
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