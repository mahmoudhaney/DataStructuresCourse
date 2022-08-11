// Created by Mahmoud Haney on 7/28/2022.
#ifndef DATASTRUCTURESTRAINING_SINGLYLINKEDLIST_H
#define DATASTRUCTURESTRAINING_SINGLYLINKEDLIST_H

struct node {
    int data;
    node* next;
};

class SinglyLinkedlist {
private:
    node* head {};
public:
    void insert(int value);
    void print();
    bool isEmpty();
    void deleteValue(int value);
    void insertAtBeginning(int value);
    void deleteFirst();
    void deleteLast();
    void size();
    int search (int value);
    void swap_pairs();
    void reverse();
    void embedAfter(node* nod, int value);
    void insertSorted(int value);
};

#endif //DATASTRUCTURESTRAINING_SINGLYLINKEDLIST_H
