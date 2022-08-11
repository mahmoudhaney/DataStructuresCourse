// Created by Mahmoud Haney on 7/29/2022.
#ifndef DATASTRUCTURESTRAINING_DOUBLYLINKEDLIST_H
#define DATASTRUCTURESTRAINING_DOUBLYLINKEDLIST_H

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedlist {
private:
    Node* head;
    Node* tail;
    int count;
public:
    DoublyLinkedlist(){
        head = NULL;
        tail = NULL;
        count = 0;
    }
    bool isEmpty();
    void insertFirst(int value);
    void insertBack(int value);
    void display();
    void deleteBack();
    void deleteFirst();
    void displayReverse();
};


#endif //DATASTRUCTURESTRAINING_DOUBLYLINKEDLIST_H
