#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H


#include <iostream>
#include "MaxHeap.h"
using namespace std;

class PriorityQueue : public MaxHeap{
public:
    void enqueue(Patient&);
    Patient dequeue();
    Patient peek();
    bool isEmpty();
    void print();
};

#endif
