// Created by Mahmoud Haney on 7/28/2022.
#ifndef DATASTRUCTURESTRAINING_SIMPLEQUEUE_H
#define DATASTRUCTURESTRAINING_SIMPLEQUEUE_H


class SimpleQueue {
private:
    int front;
    int rear;
    int* arr;
    int size;
public:
    SimpleQueue(int size){
        this->size = size;
        front = rear = -1;
        arr = new int [size];
    }
    bool isEmpty();
    bool isFull();
    void inqueue(int value);
    int dequeue();
    int peek();
    void display();
};


#endif //DATASTRUCTURESTRAINING_SIMPLEQUEUE_H
