// Created by Mahmoud Haney on 7/28/2022.
#include <iostream>
#include "SimpleQueue.h"
using namespace std;

bool SimpleQueue::isEmpty() {
    return (front == -1 && rear == -1) || (front > rear);
}

bool SimpleQueue::isFull() {
    return rear == size - 1;
}

void SimpleQueue::inqueue(int value) {
    if(isFull())
        cout << "Error: Queue Overflow" << endl;
    else
    {
        if(front == -1 && rear == -1)
            front++, arr[++rear] = value;
        else
            arr[++rear] = value;
    }
}

int SimpleQueue::dequeue() {
    if(isEmpty())
        cout << "Error: Stack Is Already Empty" << endl;
    else
        return arr[front++];
}

int SimpleQueue::peek() {
    if(isEmpty()){
        cout << "Error: Stack Is Empty" << endl;
        return -1;
    }
    return arr[front];
}

void SimpleQueue::display() {
    if(isEmpty())
        cout << "Error: Stack Is Empty" << endl;
    else
    {
        for (int i = front; i <= rear ; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
}
