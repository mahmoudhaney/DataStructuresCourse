// Created by Mahmoud Haney on 7/28/2022.
#ifndef DATASTRUCTURESTRAINING_STACK_H
#define DATASTRUCTURESTRAINING_STACK_H
using namespace std;
class Stack {
private:
    int top;
    int size;
    char* arr;
public:
    Stack(int size){
        this->size = size;
        top = -1;
        arr = new char [size];
    }
    bool isEmpty();
    bool isFull();
    void push(char value);
    char pop();
    void display();
    char peek();
};


#endif //DATASTRUCTURESTRAINING_STACK_H
