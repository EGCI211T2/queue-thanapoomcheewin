#ifndef node_h
#define node_h
#include <iostream>
using namespace std;

class NODE{
    int data;
    NODE *nextPtr;

public:
    NODE(int x);
    ~NODE();

    void set_next(NODE*);
    NODE* get_next();
    int get_value();
};

typedef NODE* NodePtr;

NODE::NODE(int x){
    data = x;
    nextPtr = NULL;
}

NODE* NODE::get_next(){
    return nextPtr;
}

void NODE::set_next(NODE *t){
    nextPtr = t;
}

int NODE::get_value(){
    return data;
}

NODE::~NODE(){}

#endif