// Created by Mahmoud Haney on 7/28/2022.
#include <iostream>
#include "QueueBasedLinkedlist.h"
using namespace std;


bool QueueBasedLinkedlist::isEmpty() {
    return (front == NULL && rear == NULL);
}

void QueueBasedLinkedlist::inqueue(int value) {
    node* new_node = new node;
    new_node->data = value;
    new_node->next = NULL;
    if(isEmpty())
        front = rear = new_node;
    else
        rear->next = new_node, rear = new_node; // Last node points at new one and then rear points at new node "new last node"
}

void QueueBasedLinkedlist::dequeue() {
    if(isEmpty())
        cout << "Error: Queue Is Empty" << endl;
    else
    {
        if(front == rear)
            front = rear = NULL;
        else
            front = front->next;
    }
}

int QueueBasedLinkedlist::peek() {
    if(isEmpty()){
        cout << "Error: Queue Is Empty" << endl;
        return -1;
    }
    return front->data;
}

void QueueBasedLinkedlist::display() {
    if(isEmpty())
        cout << "Error: Queue Is Empty" << endl;
    else
        for (node* current = front; current; current = current->next)
            cout << current->data << " ";
        cout << endl;
}
