#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#include "Queue.h"

int main(int argc , char **argv) {
    Queue q;

    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "x") == 0){

            int val = q.dequeue();

            if(val == -1){
                cout << "Empty Queue\n";
            }
            else{
                cout << "dequeing " << val << endl;
            }
        }
        else{
            q.enqueue(atoi(argv[i]));
        }
    }

    return 0;
}