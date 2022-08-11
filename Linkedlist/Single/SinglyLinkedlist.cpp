// Created by Mahmoud Haney on 7/28/2022.
#include <iostream>
#include "SinglyLinkedlist.h"
using namespace std;

void SinglyLinkedlist::insert(int value){
    node* new_node = new node;
    new_node->data = value;

    // If this node is the first one in the linked list
    if(head == NULL){
        head = new_node;
        new_node->next = NULL;
    }
    else{
        node* last = head;
        while (last->next != NULL)//I started form the second node (ptr->next) because I'm sure it is not the first one.
            last = last->next;
        last->next = new_node;
        new_node->next = NULL;
    }
};
void SinglyLinkedlist::print(){
    if (head == NULL)
        cout << "Linked List is Empty" << endl;
    else{
        for (node* current = head; current ; current = current->next)
            cout << current->data << " ";
        cout << endl;
    }
}
bool SinglyLinkedlist::isEmpty(){
    return (head == NULL);
}
void SinglyLinkedlist::deleteValue(int value){
    if(head == NULL)
        cout << "Linked list is empty, No items to delete" << endl;
    else
    {
        node* current_node = head, *previous = current_node;
        // Check if it's the first node or not
        if(current_node->data == value)
        {
            head = current_node->next;
            free(current_node);
            return;
        }
        else
        {
            int flag = false;
            while (current_node != NULL){
                if(current_node->data == value){
                    flag = true; // Means that value exist in the linked list
                    break;
                }
                else{
                    previous = current_node;
                    current_node = current_node->next;
                }

            }
            if(flag){
                previous->next = current_node->next;
                free(current_node);
            }
            else
                cout << "Linked list doesn't have this value: " << value << endl;

        }
    }
}
void SinglyLinkedlist::insertAtBeginning(int value){
    node* new_node = new node;
    new_node->data = value;
    new_node->next = head;
    head = new_node;
}
void SinglyLinkedlist::deleteFirst(){
    if (head == NULL)
        cout << "linked list is Empty"<< endl;
    else
        head = head->next;
}
void SinglyLinkedlist::deleteLast(){
    if(head == NULL)
        cout << "Linked list is Empty" << endl;
    else{
        if(head->next == NULL){ //There is one node in linked list
            delete(head);
            head = NULL;
        }
        else{
            node* current_node = head;
            while (current_node->next->next != NULL) // معناها اني لسه موصلتش للنود اللي قبل الأخيرة
                current_node = current_node->next;
            delete(current_node->next);
            current_node->next = NULL; // نخلي النود اللي قبل الاخيرة بتساوي null ودا معناه ان النود الاخيرة اتمسحت
        }
    }
}
void SinglyLinkedlist::size(){
    if(head == NULL)
        cout << "0, Empty linked list" << endl;
    else{
        int count = 0;
        node* current_node = head;
        while (current_node != NULL){
            count++;
            current_node = current_node->next;
        }
        cout << "Size = " << count << endl;
    }
}
int SinglyLinkedlist::search (int value){
    int idx = 0;
    for(node* current = head; current; current = current->next, ++idx)
        if(current->data == value)
            return idx;
    return -1;
}
void SinglyLinkedlist::swap_pairs(){
    if(head == NULL || head->next == NULL)
        cout << "NO Pairs To Swap"<< endl;
    else
        for (node* current = head; current; current = current->next)
            if(current->next){
                swap(current->data, current->next->data);
                current = current->next;
            }
}
void SinglyLinkedlist::reverse(){
    if(!(isEmpty() && head->next == NULL)){
        node* previous = NULL, *next = NULL, *current = head;
        while(current){
            // Store the next node
            next = current->next;
            // make current node point at previous node
            current->next = previous;
            // Move pointers one position ahead.
            previous = current;
            current = next;
        }
        //make head point at previous "last node"
        head = previous;
    }
}
void SinglyLinkedlist::embedAfter(node* nod, int value){
    node* new_node = new node();
    new_node->data = value;
    new_node->next = nod->next;
    nod->next = new_node;
}
void SinglyLinkedlist::insertSorted(int value){
    // If this node is the first one in the linked list
    if( (value <= head->data) || (head == NULL) ){
        insertAtBeginning(value);
        return;
    }
    for (node* current = head, *previous = head; current; previous = current, current = current->next)
    {
        if(value <= current->data)
        {
            if(current->next == NULL)
            {
                node* new_node = new node;
                new_node->data = value;
                new_node->next = NULL;
                current->next = new_node;
                break;
            }
            else
            {
                embedAfter(previous, value);
                break;
            }
        }
    }
}