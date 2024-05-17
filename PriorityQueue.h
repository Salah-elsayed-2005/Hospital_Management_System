#include <iostream>
#include "MaxHeap.h"
using namespace std;

class PriorityQueue : public MaxHeap{
public:
    void enqueue(Patient&);
    Patient dequeue();
    Patient peek();
    bool isEmpty();
};


