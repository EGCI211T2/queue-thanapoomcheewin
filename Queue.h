#ifndef queue_h
#define queue_h

#include "Node.h"

class Queue {
    NodePtr headPtr, tailPtr;
    int size;

public:
    void enqueue(int);
    int dequeue();

    Queue();
    ~Queue();
};

void Queue::enqueue(int x){
    NodePtr new_node = new NODE(x);

    if(tailPtr != NULL)
        tailPtr->set_next(new_node);

    tailPtr = new_node;

    if(size == 0)
        headPtr = new_node;

    size++;
}

int Queue::dequeue(){
    if(size > 0){
        NodePtr temp = headPtr;
        int value = temp->get_value();

        headPtr = headPtr->get_next();

        delete temp;
        size--;

        if(size == 0)
            tailPtr = NULL;

        return value;
    }

    return -1;
}

Queue::Queue(){
    headPtr = NULL;
    tailPtr = NULL;
    size = 0;
}

Queue::~Queue(){
    while(size > 0){
        dequeue();
    }
}

#endif