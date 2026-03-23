#ifndef queue_h
#define queue_h

#include "Node.h"

class Queue {
    NodePtr headPtr, tailPtr;
    int size;

public:
    void enqueue(int price, int cash);
    NodePtr dequeue();

    Queue();
    ~Queue();
};

// Enqueue
void Queue::enqueue(int price, int cash){
    NodePtr new_node = new NODE(price, cash);

    if(tailPtr != NULL)
        tailPtr->set_next(new_node);

    tailPtr = new_node;

    if(size == 0)
        headPtr = new_node;

    size++;
}

// Dequeue
NodePtr Queue::dequeue(){
    if(size > 0){
        NodePtr temp = headPtr;
        headPtr = headPtr->get_next();

        size--;

        if(size == 0)
            tailPtr = NULL;

        return temp;
    }

    return NULL;
}

// Constructor
Queue::Queue(){
    headPtr = NULL;
    tailPtr = NULL;
    size = 0;
}

// Destructor
Queue::~Queue(){
    while(size > 0){
        NodePtr temp = dequeue();
        delete temp;
    }
}

#endif