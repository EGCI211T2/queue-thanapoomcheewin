#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#include "Queue.h"

int main(int argc , char **argv) {
    Queue q;

    // Read input
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "x") == 0){
            
            NodePtr n = q.dequeue();

            cout << "================\n";

            if(n == NULL){
                cout << "Empty Queue\n";
                continue;
            }

            int price = n->get_price();
            int cash  = n->get_cash();

            cout << "Removing order\n";

            // Case: no food
            if(price == -1){
                cout << "We don't have that food. You don't have to pay.\n";
            }
            // Not enough money
            else if(cash < price){
                cout << "Not enough money.\n";
            }
            // Exact payment
            else if(cash == price){
                cout << "You have to pay " << price << endl;
                cout << "Cash:" << cash << endl;
                cout << "Thank you\n";
            }
            // Need change
            else{
                cout << "You have to pay " << price << endl;
                cout << "Cash:" << cash << endl;
                cout << "Thank you\n";
                cout << "Here is your " << (cash - price) << " change.\n";
            }

            delete n;
        }
        else {
            // Expect 2 numbers: price and cash
            if(i + 1 < argc){
                int price = atoi(argv[i]);
                int cash  = atoi(argv[i+1]);

                q.enqueue(price, cash);
                i++; // skip next since it's used
            }
        }
    }

    return 0;
}