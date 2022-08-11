// Created by Mahmoud Haney on 8/2/2022.
#include <iostream>
#include <cassert>
#include "BinaryTree.h"
using namespace std;

bool BinaryTree::isEmpty() {
    return this->root == NULL;
}

void BinaryTree::preOrder(BinaryTree::node *current) {
    if(!current)
        return;
    cout << current->data << " ";
    preOrder(current->left);
    preOrder(current->right);
}

void BinaryTree::inOrder(node* current) {
    if (!current)
        return;
    inOrder(current->left);
    cout << current->data << " ";
    inOrder(current->right);
}

void BinaryTree::postOrder(BinaryTree::node *current) {
    if(!current)
        return;
    postOrder(current->left);
    postOrder(current->right);
    cout << current->data << " ";
}

void BinaryTree::preOrder() {
    preOrder(root);
    cout << endl;
}

void BinaryTree::inOrder() {
    inOrder(root);
    cout << endl;
}

void BinaryTree::postOrder() {
    postOrder(root);
    cout << endl;
}

void BinaryTree::add(vector<int> values, vector<char> direction) {
    assert(values.size() == direction.size());
    node* current = this->root;
    // iterate on the path, create all necessary nodes
    for (int i = 0; i < (int) values.size(); ++i) {
        if (direction[i] == 'L') {
            if (!current->left)
                current->left = new node(values[i]);
            else
                assert(current->left->data == values[i]);
            current = current->left;
        } else {
            if (!current->right)
                current->right = new node(values[i]);
            else
                assert(current->right->data == values[i]);
            current = current->right;
        }
    }
}

int BinaryTree::treeMax(BinaryTree::node *current) {
    if(!current)
        return -1;
    int result = current->data;
    result = max(result, treeMax(current->left));
    result = max(result, treeMax(current->right));
    return result;
}

int BinaryTree::treeMax() {
    return treeMax(this->root);
}

int BinaryTree::treeHeight(BinaryTree::node *current) {
    if(!current)
        return -1;
    int result = 0;
    result = 1 + treeHeight(current->left);
    result = max(result, 1 + treeHeight(current->right));
    return result;
}

int BinaryTree::treeHeight() {
    return treeHeight(this->root);
}

