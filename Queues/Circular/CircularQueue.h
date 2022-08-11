// Created by Mahmoud Haney on 7/28/2022.
#ifndef DATASTRUCTURESTRAINING_CIRCULARQUEUE_H
#define DATASTRUCTURESTRAINING_CIRCULARQUEUE_H


class CircularQueue {
private:
    int front;
    int rear;
    int* arr;
    int size;
public:
    CircularQueue(int size){
        this->size = size;
        front = rear = -1;
        arr = new int [size];
    }
    bool isEmpty();
    bool isFull();
    void inqueue(int value);
    void dequeue();
    int peek();
    void display();
};


#endif //DATASTRUCTURESTRAINING_CIRCULARQUEUE_H
