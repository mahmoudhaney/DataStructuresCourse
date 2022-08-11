// Created by Mahmoud Haney on 7/28/2022.
#include <iostream>
#include <cassert>
#include "Stack.h"
using namespace std;

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == size - 1;
}

void Stack::push(char value) {
    if(isFull())
        cout << "Error: Stack Overflow" << endl;
    else
        arr[++top] = value;
}

char Stack::pop() {
    if(isEmpty())
        cout << "Error: Stack Is Already Empty" << endl;
    else
        return arr[top--];
}

void Stack::display() {
    assert(isEmpty());
    cout << "[ ";
    for (int i = top; i >= 0; --i)
        cout<< arr[i] << " ";
    cout << "]" << endl;
}

char Stack::peek() {
    assert(isEmpty());
    return arr[top];
}
