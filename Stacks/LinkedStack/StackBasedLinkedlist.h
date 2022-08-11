// Created by Mahmoud Haney on 7/28/2022.
#ifndef DATASTRUCTURESTRAINING_STACKBASEDLINKEDLIST_H
#define DATASTRUCTURESTRAINING_STACKBASEDLINKEDLIST_H

struct Node{
    int data;
    Node* next;
};

class StackBasedLinkedlist {
private:
    Node* top = NULL;
public:
    bool isEmpty();
    void push(int value);
    void pop();
    void pop(int &poped);
    void display();
    int peek();
};


#endif //DATASTRUCTURESTRAINING_STACKBASEDLINKEDLIST_H
