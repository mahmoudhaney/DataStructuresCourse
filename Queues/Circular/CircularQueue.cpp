// Created by Mahmoud Haney on 7/28/2022.
#include <iostream>
#include "CircularQueue.h"
using namespace std;

bool CircularQueue::isEmpty() {
    return (front == -1 && rear == -1);
}

bool CircularQueue::isFull() {
    return (front == 0 && rear == size -1) || (front == rear + 1);
}

void CircularQueue::inqueue(int value) {
    if(isFull())
        cout << "Error: Queue Overflow" << endl;
    else
    {
        if(isEmpty())
            front++, arr[++rear] = value;
        else if (rear == size - 1)
            rear = 0, arr[rear] = value;
        else
            arr[++rear] = value;
    }
}

void CircularQueue::dequeue() {
    if(isEmpty())
        cout << "Error: Queue Is Already Empty" << endl;
    else
    {
        if (front == rear)
            front = rear = -1;
        else if (front == size - 1)
            front = 0;
        else
            front++;
    }
}

int CircularQueue::peek() {
    if(isEmpty()){
        cout << "Error: Queue is Empty" << endl;
        return -1;
    }
    return arr[front];
}

void CircularQueue::display() {
    if(isEmpty())
        cout << "Error: Queue Is Empty" << endl;
    else
    {
        if(front <= rear){
            for (int i = front; i <= rear; ++i)
                cout << arr[i] << " ";
            cout << endl;
        }
        else{
            for (int i = front; i < size; ++i)
                cout << arr[i] << " ";
            for (int i = 0; i <= rear; ++i)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
}
