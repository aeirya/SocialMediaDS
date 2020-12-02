#include <iostream>
#include "linked_list.h"
#include "network.h"
#include "social_network.h"
#include "console_input.h"
// #include "graph.h"
// #include "person.h"

using namespace std;

void rc() {
    cout << "reached checkpoint!" << endl;
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