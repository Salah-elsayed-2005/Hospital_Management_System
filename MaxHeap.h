#ifndef MAXHEAP_H
#define MAXHEAP_H


#include <iostream>
#include <vector>
#include "Patient.h"
using namespace std;


class MaxHeap {
    vector<Patient> heap;

    void swap(Patient&, Patient&);

    int inline parent(int);
    int inline left_child(int);
    int inline right_child(int);

    void shiftUp(int);
    void shiftDown(int);

protected:
    MaxHeap(){}
    MaxHeap(vector<Patient> vec){
        heap = vec;
    }
    void build();
    void insert(Patient&);
    Patient  getMax();
    Patient extractMax();
    bool empty();

};

#endif