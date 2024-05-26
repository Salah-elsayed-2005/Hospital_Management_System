#include "PriorityQueue.h"




void PriorityQueue::enqueue(Patient &p) {
    insert(p);
}

Patient PriorityQueue::dequeue() {
    return extractMax();
}

Patient PriorityQueue::peek() {
    return getMax();
}

bool PriorityQueue::isEmpty() {
    return empty();
}
void PriorityQueue::print() {
    PriorityQueue temp= *this;
    while (!temp.isEmpty()){
        cout<<temp.dequeue().getName()<<"  ";
    }
}

string PriorityQueue::printStr(){
    PriorityQueue temp= *this;
    stringstream ss2;
    while (!temp.isEmpty()){
        ss2 <<temp.dequeue().getName()<<"  ";
    }
     return ss2.str();
}
