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

SocialNetwork makeSuperNetwork(LinkedList<SocialNetwork>& networks) {
    SocialNetwork super {};
    for (SocialNetwork& net : networks) {
        super = super + net;
    }
    super.sort();
    return super;
}

int main() {
    LinkedList<Network> networks {};
    inputNetworks(networks);
    
    LinkedList<SocialNetwork> socials {};
    for (Network& net : networks) {
        socials.add(SocialNetwork(net));
        // delete &net;
    }

    SocialNetwork super = makeSuperNetwork(socials);
    
    return 0;
    inputQueries();

    // // testing the application
    // for (Network& node : networks) {
    //     node.printHI();
    // }

    return 0;
}