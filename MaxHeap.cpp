#include "MaxHeap.h"

/****** Heap Methods implementation ******/

void MaxHeap::swap(Patient &a, Patient &b) {
    Patient temp = a;
    a = b;
    b = temp;
}


int inline MaxHeap::parent(int index) {
    return (index - 1) / 2;
}


int inline MaxHeap::left_child(int index) {
    return 2 * index + 1;
}


int inline MaxHeap::right_child(int index) {
    return 2 * index + 2;
}


void MaxHeap::shiftUp(int index){
    for(int i = index; i > 0; i = parent(i)){

        if(heap.at(i) > heap.at(parent(i))){
            swap(heap.at(i), heap.at(parent(i)));
        }
    }
}


void MaxHeap::shiftDown(int index) {

    while(left_child(index) < heap.size() && heap.at(left_child(index)) > heap.at(index)
          || right_child(index) < heap.size() && heap.at(right_child(index)) > heap.at(index)){

        int max = index;
        if(heap.at(left_child(index)) > heap.at(index))
            max = left_child(index);
        if(right_child(index) < heap.size() && heap.at(right_child(index)) > heap.at(max))
            max = right_child(index);
        if(max == index)
            break;

        swap(heap.at(index), heap.at(max));
        index = max;
    }
}


void MaxHeap::build() {
    for(int i = parent(heap.size() - 1); i >= 0; i--){
        shiftDown(i);
    }
}


void MaxHeap::insert(Patient &obj) {
    heap.push_back(obj);
    shiftUp(heap.size() - 1);
}


Patient MaxHeap::getMax() {
    return heap.at(0);
}


Patient MaxHeap::extractMax() {
    Patient max = heap.at(0);
    heap.at(0) = heap.at(heap.size() - 1);
    heap.pop_back();
    shiftDown(0);

    return max;
}

bool MaxHeap::empty() {
    return heap.empty();
}

