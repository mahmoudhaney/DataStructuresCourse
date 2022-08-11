// Created by Mahmoud Haney on 7/28/2022.
#include "iostream"
#include "StackBasedLinkedlist.h"
using namespace std;

bool StackBasedLinkedlist::isEmpty() {
    return top == NULL;
}

void StackBasedLinkedlist::push(int value) {
    Node* new_node = new Node;
    new_node->data = value;
    new_node->next = top;
    top = new_node;
}

void StackBasedLinkedlist::pop() {
    if(isEmpty())
        cout << "Error: Stack Is Already Empty" << endl;
    else
        top = top->next;
}

void StackBasedLinkedlist::pop(int &poped) {
    if(isEmpty())
        cout << "Error: Stack Is Already Empty" << endl;
    else{
        poped = top->data;
        top = top->next;
    }
}

void StackBasedLinkedlist::display() {
    if(isEmpty())
        cout << "Error: Stack Is Already Empty" << endl;
    else{
        cout << "[ ";
        for(Node* current = top; current; current = current->next)
            cout << current->data << " ";
        cout << "]" << endl;
    }
}

int StackBasedLinkedlist::peek() {
    if(isEmpty())
        cout << "Error: Stack Is Already Empty" << endl;
    else
    {
        return top->data;
    }
}
