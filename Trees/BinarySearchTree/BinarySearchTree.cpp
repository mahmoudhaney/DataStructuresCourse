// Created by Mahmoud Haney on 8/3/2022.
#include <iostream>
#include <cassert>
#include "BinarySearchTree.h"
using namespace std;

bool BinarySearchTree::isEmpty() {
    return this->root == NULL;
}

void BinarySearchTree::inorder(node* r) {
    if(!r)
        return;
    inorder(r->left);
    cout << r->data << " ";
    inorder(r->right);
}

void BinarySearchTree::preorder(node* r) {
    if(!r)
        return;
    cout << r->data << " ";
    inorder(r->left);
    inorder(r->right);
}

void BinarySearchTree::postorder(node* r) {
    if(!r)
        return;
    postorder(r->left);
    postorder(r->right);
    cout << r->data << " ";
}

void BinarySearchTree::inorder() {
    inorder(this->root);
    cout << endl;
}

void BinarySearchTree::preorder() {
    preorder(this->root);
    cout << endl;
}

void BinarySearchTree::postorder() {
    postorder(this->root);
    cout << endl;
}

void BinarySearchTree::clearTree(node* &r) {
    if(!r)
        return;
    clearTree(r->left);
    clearTree(r->right);
    delete(r);
    r = NULL;
}

void BinarySearchTree::clearTree() {
    clearTree(this->root);
}

void BinarySearchTree::insert(int value) {
    node* newNode = new node(value);
    assert(newNode != NULL);
    newNode->left = NULL;
    newNode->right = NULL;

    if(root == NULL) // First node "It will be the root"
        root = newNode;
    else {
        node* current = root, *prev;
        while (current){
            prev = current;

            if(current->data == value){
                cout << "This value is already in the tree, Duplicates are not allowed." << endl;
                return;
            }
            else{
                if(current->data > value)
                    current = current->left;
                else
                    current = current->right;
            }
        }
        if(prev->data > value)
            prev->left = newNode;
        else
            prev->right = newNode;
    }
}

void BinarySearchTree::deleteNode(node* &r) {
    // 1. The node is a leaf -> Just Delete it.
    if(r->left == NULL && r->right == NULL){
        delete(r);
        r = NULL;
    }
    //2. The node has one child -> Reconnect its child with its parent and delete it.
    else if(r->left == NULL){
        node* temp = r;
        r = r->right;
        delete(temp);
    }
    else if(r->right == NULL){
        node* temp = r;
        r = r->left;
        delete(temp);
    }
    //3. Otherwise -> Replace it with the maximum of its left tree
    else{
        node* current = r->left, *prev = NULL;
        while (current->right)
            prev = current, current = current->right; // When while loop is done
                                                      // -> current will be point at the maximum of the left subtree
        r->data = current->data; // Replace the deleted value with max of left subtree
        if(prev)
            prev->right = current->left;
        else
            r->left = current->left;
        delete(current);
    }
}

void BinarySearchTree::remove(int value) {
    // If the tree is empty
    if(isEmpty()){
        cout << "Cannot delete from the empty tree." << endl;
        return;
    }
    // If the deleted value is the root
    if(root->data == value){
        deleteNode(root);
        return;
    }
    // The value to be deleted is not the root
    node* current, *prev = root;
    if(root->data > value)
        current = root->left; //if the value is less than the root then go left
    else
        current = root->right; //if the value is greater than the root then go right

    // Searching for the node to be deleted
    while (current){
        if(current->data == value)
            break;
        else
        {
            prev = current;
            if(current->data > value)
                current = current->left;
            else
                current = current->right;
        }
    }//end while loop

    if(current == NULL) //Value Not Exist
        cout << "This value doesn't exist in the tree." << endl;
    else
        deleteNode(current);
}

int BinarySearchTree::height(node *r) {
    if(r == NULL)
        return 0;
    else
        return 1 + max(height(r->left), height(r->right));
}

int BinarySearchTree::height() {
    return height(this->root) - 1;
}

int BinarySearchTree::nodesCount(node *r) {
    if(r == NULL)
        return 0;
    else
        return 1 + nodesCount(r->left) + nodesCount(r->right);
}

int BinarySearchTree::nodesCount() {
    return nodesCount(this->root);
}

int BinarySearchTree::leavesCount(node *r) {
    if(r == NULL)
        return 0;
    else if ((r->left == NULL) && (r->right == NULL))
        return 1;
    else
        return leavesCount(r->left) + leavesCount(r->right);
}

int BinarySearchTree::treeLeavesCount() {
    return leavesCount(this->root);
}

bool BinarySearchTree::isExist(int value) {
    node* current = root;

    while(current != NULL)
    {
        if(current->data == value)
            return true;
        else if(current->data > value)
            current = current->left;
        else
            current = current->right;
    }
    return false;
}

