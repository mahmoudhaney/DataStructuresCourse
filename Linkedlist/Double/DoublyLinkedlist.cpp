// Created by Mahmoud Haney on 7/29/2022.
#include <iostream>
#include "DoublyLinkedlist.h"
using namespace std;

bool DoublyLinkedlist::isEmpty() {
    return head == NULL;
}

void DoublyLinkedlist::insertFirst(int value) {
    Node* new_node = new Node;
    new_node->data = value;
    if(count == 0){
        head = tail = new_node;
        new_node->next = new_node->prev = NULL;
    }
    else{
        new_node->prev = NULL;
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    count++;
}

void DoublyLinkedlist::insertBack(int value) {
    Node* new_node = new Node;
    new_node->data = value;
    if(count == 0){
        head = tail = new_node;
        new_node->next = new_node->prev = NULL;
    }
    else
    {
        new_node->next = NULL;
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
    count++;
}

void DoublyLinkedlist::deleteFirst() {
    if(isEmpty()){
        cout << "Error: Linked List Is Empty" << endl;
        return;
    }
    else if (count == 1)
        delete(head), head = tail = NULL;
    else{
        Node* cur = head;
        head->next->prev = NULL, head = head->next;
        delete(cur);
    }
    count--;
}

void DoublyLinkedlist::deleteBack() {
    if(isEmpty()){
        cout << "Error: Linked List Is Empty" << endl;
        return;
    }
    else if (count == 1)
        delete(head), head = tail = NULL;
    else{
        Node* cur = tail;
        tail->prev->next = NULL, tail = tail->prev;
        delete(cur);
    }
    count--;

}

void DoublyLinkedlist::display() {
    if(isEmpty())
        cout << "Error: Linked List Is Empty" << endl;
    else
    {

        for (Node* current = head; current; current = current->next)
            cout << current->data << " ";
        cout << endl;
    }

}

void DoublyLinkedlist::displayReverse() {
    if(isEmpty())
        cout << "Error: Linked List Is Empty" << endl;
    else
    {

        for (Node* current = tail; current; current = current->prev)
            cout << current->data << " ";
        cout << endl;
    }
}
