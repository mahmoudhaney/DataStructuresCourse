// Created by Mahmoud Haney on 8/3/2022.
#ifndef DATASTRUCTURESTRAINING_BINARYHEAP_H
#define DATASTRUCTURESTRAINING_BINARYHEAP_H
class BinaryHeap {
private:
    int *array { };
    int size { };
    int capacity { 1000 };
    int left(int node);
    int right(int node);
    int parent(int node);
    void heapifyUp(int childPosition);
    void heapifyDown(int parentPosition);
public:
    BinaryHeap(){
        array = new int [capacity];
        size = 0;
    }
    ~BinaryHeap(){
        delete[] array;
        array = nullptr;
    }
    bool isEmpty();
    int top();
    void push (int value);
    void pop ();
    void print();
};
#endif //DATASTRUCTURESTRAINING_BINARYHEAP_H
