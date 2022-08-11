// Created by Mahmoud Haney on 8/3/2022.
#include <iostream>
#include <cassert>
#include "BinaryHeap.h"
using namespace std;

int BinaryHeap::left(int node) {
    int lf = 2 * node + 1;
    return lf >= size ? -1 : lf;
}

int BinaryHeap::right(int node) {
    int rt = 2 * node + 2;
    return rt >= size ? -1 : rt;
}

int BinaryHeap::parent(int node) {
    return node == 0 ? -1 : (node - 1) / 2;
}

bool BinaryHeap::isEmpty() {
    return size == 0;
}

int BinaryHeap::top() {
    return array[0];
}

void BinaryHeap::heapifyUp(int childPosition) {
    int childParent = parent(childPosition);
    if(childPosition == 0 || array[childParent] < array[childPosition])
        return; //Will stop if it's the root or the parent less than the child "This is the required thing"

    swap(array[childPosition], array[childParent]); //Otherwise swap the child with its parent
    heapifyUp(childParent); // And do the same with new parent
}

void BinaryHeap::push(int value) {
    assert(size + 1 <= capacity); // 1. Make sure that there is enough space.
    array[size++] = value; // 2. Put the new value at the end of the array & increase size by 1.
    heapifyUp(size - 1); // 3. Fix the tree from down to up stating by the index of the value that I just insert it.
}

void BinaryHeap::heapifyDown(int parentPosition) {
    int childPosition = left(parentPosition);
    if(childPosition == -1) // If it has no left child then, for sure it has no right child because I fill thr tree from left to right
        return; // So I have to end the process

    //Getting here mean that I have a left child, and I have to check if there is a right child or not
    int rightChild = right(parentPosition);
    if(rightChild != -1 && array[rightChild] < array[childPosition]) // and I need to know who is greater, left or right
        childPosition = rightChild;

    if(array[parentPosition] > array[childPosition]){ // Parent must be less than the child.
        swap(array[parentPosition], array[childPosition]); //Replace parent with child.
        heapifyDown(childPosition); // Do the same with the new child.
    }
}

void BinaryHeap::pop() {
    assert(!isEmpty()); // 1. Make sure that is not empty.
    array[0] = array[--size]; // 2. Replace the root with the last value.
    heapifyDown(0); // 3. Fix the tree.
}

void BinaryHeap::print() {
    if(isEmpty())
        cout << "Heap is empty" << endl;
    else
        for (int i = 0; i < size; ++i)
            cout << array[i] << " ";
        cout << endl;
}












