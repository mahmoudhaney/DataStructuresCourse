// Created by Mahmoud Haney on 7/28/2022.
#include <iostream>
#include <cassert>
#include "Vector.h"
using namespace std;

int Vector::get(int idx){
    assert(idx >= 0 && idx < size);
    return arr[idx];
}
void Vector::set(int idx, int value){
    assert(idx >= 0 && idx < size);
    arr[idx] = value;
}
void Vector::print(){
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
int Vector::find(int value){
    for (int i = 0; i < size; ++i)
        if(arr[i] == value)
            return i;
    return -1;
}
int Vector::get_front(){
    return arr[0];
}
int Vector::get_back(){
    return arr[size-1];
}
void Vector::expand_capacity(){
    // We double the actual array size
    capacity *= 2;
    cout << "Capacity expanded to " << capacity << endl;
    int *arr2 = new int[capacity] {}; //Creating a new array with new capacity
    for (int i = 0; i < size; ++i)
        arr2[i] = arr[i]; // Copy old array with the new one
    swap(arr, arr2); // Swap the pointers
    delete[] arr2; // Delete the new array
}
void Vector::push_back(int value){
    if(size == capacity)
        expand_capacity();
    arr[size++] = value;

}
void Vector::insert(int idx, int value){
    assert(0 <= idx && idx < size);
    // we can't add anymore
    if (size == capacity)
        expand_capacity();
    for (int i = size - 1; i >= idx ; --i) //Shift element to right till wanted index
        arr[i+1] = arr[i];
    arr[idx] = value;
    size++;
}
void Vector::right_rotate(){
    int last = get_back();
    for (int i = size - 2; i >= 0 ; --i) // Make i = size - 2 to git rid of the last element
        arr[i+1] = arr[i]; //Shift element to right till wanted index
    arr[0] = last;
}
void Vector::right_rotate(int times){
    while (--times)
        right_rotate();
}
int Vector::find_transposition(int value){
    for (int i = 0; i < size; ++i) {
        if (arr[i] == value){
            if(i == 0)
                return 0; // if it was the first element I can't shift it
            swap(arr[i], arr[i-1]);
            return i-1; //Found
        }
    }
    return -1; //Not found
}
