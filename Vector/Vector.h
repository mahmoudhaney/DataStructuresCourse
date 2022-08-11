// Created by Mahmoud Haney on 7/28/2022.
#ifndef DATASTRUCTURESTRAINING_VECTOR_H
#define DATASTRUCTURESTRAINING_VECTOR_H



class Vector
{
private:
    int *arr {nullptr};
    int size {0}; // User size
    int capacity {}; // Actual size
public:
    Vector(int size) : size(size){
        if(size < 0)
            size = 1;
        capacity = size + 10;
        // The actual array size will be bigger than needed
        arr = new int[capacity] {};
    }
    ~Vector() {
        delete[] arr;
        arr = nullptr;
    }
    // ================Functionalities=====================
    int get(int idx);
    void set(int idx, int value);
    void print();
    int find(int value);
    int get_front();
    int get_back();
    void expand_capacity();
    void push_back(int value);
    void insert(int idx, int value);
    void right_rotate();
    void right_rotate(int times);
    int find_transposition(int value);
};


#endif //DATASTRUCTURESTRAINING_VECTOR_H
