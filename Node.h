#ifndef node_h
#define node_h
#include <iostream>
using namespace std;

class NODE {
    int price;
    int cash;
    NODE *nextPtr;

public:
    NODE(int p, int c);
    ~NODE();

    void set_next(NODE*);
    NODE* get_next();

    int get_price();
    int get_cash();
};

typedef NODE* NodePtr;

// Constructor
NODE::NODE(int p, int c){
    price = p;
    cash = c;
    nextPtr = NULL;
}

// Get next node
NODE* NODE::get_next(){
    return nextPtr;
}

// Set next node
void NODE::set_next(NODE *t){
    nextPtr = t;
}

// Get values
int NODE::get_price(){
    return price;
}

int NODE::get_cash(){
    return cash;
}

// Destructor (optional debug)
NODE::~NODE(){
    // cout << "Deleting node\n";
}

#endif