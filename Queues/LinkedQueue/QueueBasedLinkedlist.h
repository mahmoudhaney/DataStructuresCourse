// Created by Mahmoud Haney on 7/28/2022.
#ifndef DATASTRUCTURESTRAINING_QUEUEBASEDLINKEDLIST_H
#define DATASTRUCTURESTRAINING_QUEUEBASEDLINKEDLIST_H

struct node{
    int data;
    node* next;
};

class QueueBasedLinkedlist {
private:
    node* front;
    node* rear;
public:
    QueueBasedLinkedlist() : front(NULL), rear(NULL) {}
    bool isEmpty();
    void inqueue(int value);
    void dequeue();
    int peek();
    void display();
};


#endif //DATASTRUCTURESTRAINING_QUEUEBASEDLINKEDLIST_H
